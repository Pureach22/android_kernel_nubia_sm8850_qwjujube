# 🔴 Diagnóstico de Boot Hang — RedMagic 11 Pro (NX809J) Custom GKI Kernel

> **Status:** Em investigação ativa — Ajuda da comunidade é bem-vinda!
>
> **Device:** Nubia RedMagic 11 Pro (NX809J) — Snapdragon 8 Elite (SM8750/Canoe)
>
> **Kernel Base:** GKI 6.12.23-android16 com KernelSU-Next
>
> **Firmware Alvo:** Userdebug oficial ZTE

---

## Resumo do Problema

O kernel custom compila com sucesso (Build #8), boota além do early-init, mas **trava na tela do logo RedMagic indefinidamente**. O usuário precisa long-press no power para reiniciar.

### O que funciona:
- ✅ Kernel boota (sem NULL pointer dereference)
- ✅ UFS Storage detecta todas as LUNs (`sda`, `sde`)
- ✅ `/metadata` (sda10) monta com sucesso via F2FS
- ✅ `/system`, `/vendor`, `/product` montam via dm-verity/erofs
- ✅ SHM Bridge habilitado e registrado (4MB, paddr: 0xaa400000)
- ✅ Display inicializa (tela do logo RedMagic aparece)
- ✅ KernelSU-Next v33129 carrega

### O que NÃO funciona:
- ❌ `/data` (sda12) **não monta** — FBE (File-Based Encryption) requer descriptografia
- ❌ `vold` não aparece nos logs
- ❌ `keymint` não aparece nos logs
- ❌ `adsp-loader` falha em loop: "fail to get rproc" (~20 vezes)
- ❌ SCMI `arm-scmi.1.auto` sofre **timeout**
- ❌ BRD daemon loop infinito tentando ler `/sys/class/power_supply/battery/status`

---

## Causa Raiz Identificada

### Cadeia de Falhas (Root Cause Chain)

```
SCMI arm-scmi.1.auto TIMEOUT (do_xfer)
    ↓
cpuss_telemetry_probe FALHA ("Not able to find shared memory")
    ↓
qcom_q6v5_pas NÃO INICIA (remoteproc indisponível)
    ↓
adsp-loader: "fail to get rproc" (loop 20+ vezes)
    ↓
ADSP/CDSP remoteproc OFFLINE
    ↓
smcinvoke/qseecom NÃO DISPONÍVEL
    ↓
keymint NÃO INICIA
    ↓
vold NÃO CONSEGUE descriptografar /data
    ↓
/data NÃO MONTA (FBE requer keymint)
    ↓
HANG no logo RedMagic (init trava esperando /data)
```

### Evidência Crítica: Comparação Stock vs Custom

O `scm_mem_protection_init_do: SCM call failed 0, resp 7` e o `qcom_scm_cfg_pddr_protected_region: resp 4 ret -22` acontecem **identicamente** no kernel stock e são **não-fatais**. Estes NÃO são a causa do hang.

| Evento | Stock Kernel ✅ | Custom Kernel ❌ |
|--------|:-:|:-:|
| SCM mem_protection resp 7 | Acontece (não-fatal) | Acontece (não-fatal) |
| SHM Bridge habilitado | Sim | Sim |
| SCMI FC Failed ret:-22 | Acontece (fallback) | Acontece |
| TBU failed probe (4x) | Acontece (não-fatal) | Acontece |
| `/metadata` montado | ✅ | ✅ |
| `/system`, `/vendor` montados | ✅ | ✅ |
| `vendor/vm-system` invalid magic | Acontece (normal) | Acontece (normal) |
| `/data` "invalid magic" | Acontece (normal, é FBE) | Acontece |
| **SCMI arm-scmi.1.auto** | **Conecta OK** | **TIMEOUT** ⚠️ |
| **`keymint` inicia** | ✅ PID 1023, @1.27s | ❌ NÃO APARECE |
| **`vold` inicia** | ✅ PID 1027, @1.28s | ❌ NÃO APARECE |
| **`vdc cryptfs mountFstab`** | ✅ Chamado | ❌ NUNCA CHAMADO |
| **`adsp-loader`** | ✅ Funciona | ❌ "fail to get rproc" |
| **Boot completa** | ✅ | ❌ Hang |

---

## Dados de Diagnóstico Extraídos

### Stock Kernel (funcionando)

```
[0.245881] arm-scmi arm-scmi.1.auto: SCMI Protocol v2.0 'Qualcomm:PDP0' Firmware version 0x0
[0.261743] qcom-scm: __get_convention: qcom_scm: convention: smc arm 64
[0.262910] shmbridge: [130]: shmbridge is enabled
[0.262992] shmbridge: [565]: qtee shmbridge registered default bridge with size: 4194304 bytes
[0.265188] qcom-scm: scm_mem_protection_init_do: SCM call failed 0, resp 7
[0.265191] shmbridge: [570]: MEM protection Not enabled, 7
[0.275645] qcom-scm: qcom_scm_cfg_pddr_protected_region: resp 4 ret -22
[1.277863] init: starting service 'vendor.keymint'...
[1.282921] init: starting service 'vold'...
[1.550030] init: [libfs_mgr] mount_with_alternatives(): skipping mount due to invalid magic, mountpoint=/data
[1.550078] init: Calling: /system/bin/vdc cryptfs mountFstab /dev/block/bootdevice/by-name/userdata /data false
[1.745983] F2FS-fs (dm-57): recover_data: ...   ← /data montado com sucesso via dm-crypt!
```

### Custom Kernel (falhando) — Extraído do console-ramoops-0

```
[0.181496] arm-scmi arm-scmi.1.auto: Failed to get FC for protocol 13 [MSG_ID:6 / RES_ID:0] - ret:-22
[0.203758] qcom-scm: scm_mem_protection_init_do: SCM call failed, resp 7
[0.214551] qcom-scm: qcom_scm_cfg_pddr_protected_region: resp 4 ret -22
[1.112xx] arm-scmi arm-scmi.1.auto: timed out in resp (caller: do_xfer+0x140/0x4ec)  ← TIMEOUT!
[1.116211] scmi_cpuss_telemetry_probe: Not able to find shared memory location
[1.774-1.875] adsp-loader soc:qcom,msm-adsp-loader: fail to get rproc  ← (loop 20x)
[1.200813] init: [libfs_mgr] Failed to mount an un-encryptable, interrupted, or wiped partition
[1.379476] init: [libfs_mgr] mount_with_alternatives(): skipping mount due to invalid magic, mountpoint=/data
  ← vdc cryptfs mountFstab NUNCA É CHAMADO!
  ← keymint NUNCA INICIA!
  ← vold NUNCA INICIA!
[22.995404] init: process with updatable components 'vendor.per_mgr' exited 4 times before boot completed
[229.530209] reboot: Restarting system with command 'LONGPRESS'  ← Usuário long-press power
```

### Flags Taint dos Módulos (do crash dump)

No crash dump do custom kernel, os módulos mostram flags suspeitas:
- `clk_scmi(ME)` — Flag **M** = module init falhou? Flag **E** = unsigned
- `qcom_scmi_vendor(NE)` — Flag **N** = significado incerto
- `qcom_scm(OA)` — Flags **O** = out-of-tree, **A** = significado incerto

No stock, todos os módulos mostram flag `(O)` limpa, sem flags extras de erro.

---

## Módulos Carregados (Stock vs Custom)

### Módulos críticos de boot (ramdisk do vendor_boot):

No stock, estes são carregados pelo `init` do ramdisk na ordem exata:
1. `qcom_scmi_vendor.ko`
2. `qcom_scmi_client.ko`
3. `clk-scmi.ko`
4. `qcom-scm.ko`
5. `arm_smmu.ko`
6. `spmi_pmic_arb.ko`
7. `sched_walt.ko`
8. `mem_prot.ko`
9. `secure_buffer.ko`
10. `qcom_ice.ko`
...e mais ~50 módulos de early boot

### No custom kernel:

Os módulos acima são **compilados do source** e inseridos no boot.img via ramdisk. O problema pode estar em:
1. **Ordem de carregamento** diferente
2. **Módulos com erros de init** (flags M/N nos taint flags)
3. **CFI warnings** que estão causando falhas silenciosas de probe
4. **SCMI transport/mailbox** não inicializando corretamente

---

## Como Investigar (Para Contribuidores)

### 1. Análise dos CFI Warnings

O ramoops mostra vários "CFI failure ... - WARNING ONLY" para módulos como `spmi_pmic_arb`, `qcom_cpucp`, `qcom_llcc_pmu`. No stock, esses módulos **não** têm CFI warnings.

**Ação:** Verificar se os CFI type hashes dos módulos compilados correspondem aos esperados pelo kernel GKI. Os módulos podem estar sendo carregados mas com callbacks de probe **não executados** devido a KCFI mismatch.

```bash
# Verificar CFI hashes:
objdump -d modulo.ko | grep "kcfi"
```

### 2. Verificar o SCMI Timeout

O timeout do `arm-scmi.1.auto` é a divergência mais crítica. No stock, ele conecta em ~0.245s. No custom, timeout em ~1.1s.

**Ação:** Comparar a DTB do custom vs stock para os nós `arm-scmi`:
```bash
# Extrair e comparar DTBs
dtc -I dtb -O dts custom_dtb.img > custom.dts
dtc -I dtb -O dts stock_dtb.img > stock.dts
diff custom.dts stock.dts | grep -A5 -B5 "scmi"
```

### 3. Verificar módulos.load e ordem de carregamento

**Ação:** Extrair o ramdisk do custom boot.img e verificar `modules.load`:
```bash
# Descompactar boot.img
unbootimg dev_reverse_perfect.img
# Verificar ramdisk
ls -la ramdisk/lib/modules/
cat ramdisk/lib/modules/modules.load
```

### 4. Comparar lsmod entre stock e custom

**Ação:** No próximo boot custom, antes que trave, tentar capturar via adb:
```bash
adb shell "lsmod" > lsmod_custom.txt
adb shell "dmesg" > dmesg_custom.txt
```

### 5. Testar com CONFIG_CFI_PERMISSIVE=y

Se os CFI warnings estiverem bloqueando probes, testar com CFI permissivo:
```
CONFIG_CFI_PERMISSIVE=y
```

---

## Arquivos Relevantes

| Arquivo | Descrição |
|---------|-----------|
| `console-ramoops-0.log` | RAM dump do último boot custom (binário, 274KB) |
| `console-ramoops-0-clean.txt` | Versão text extraída via `strings` |
| `dmesg_stock.txt` | dmesg completo do kernel stock |
| `zte_parity.c` | Bridge de símbolos proprietários |
| `super_build.sh` | Script de compilação |
| `REVERSE_ENGINEERING_MASTER_PLAN.md` | Plano global do projeto |

---

## Contexto do Projeto

Este kernel é parte de um esforço de engenharia reversa para o RedMagic 11 Pro (NX809J) com o objetivo de:
- Alcançar paridade binária com firmware ZTE oficial
- Suporte nativo a KernelSU-Next
- Overclock de GPU 1200MHz+
- Remoção de travas proprietárias ZTE

O código-fonte original da ZTE foi liberado sob GPL mas está **incompleto** — faltam ~443 módulos proprietários, headers, e o fragment de configuração da plataforma (`canoe.fragment`). Todo o código faltante foi reconstruído via engenharia reversa (Ghidra) dos módulos .ko originais extraídos do smartphone.

---

## Como Contribuir

Se você tem experiência com:
- Qualcomm SCMI/SCM subsystem
- GKI module loading e KCFI
- ARM SMMU v500 TBU probing
- File-Based Encryption (FBE) boot flow no Android 16
- Remoteproc/ADSP/CDSP boot sequence

Por favor abra uma issue ou PR com suas descobertas. Toda ajuda é bem-vinda!

---

*Última atualização: 2026-05-27*
*Build: #8 (6.12.23-android16-OP-WILD)*

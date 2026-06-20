# Análise de Engenharia Reversa - Driver Synx (ZTE RedMagic 11 Pro - NX809J)

## 1. Visão Geral do Módulo original `synx_driver.ko`
O driver Synx (`msm_synx`) gerencia a sincronização de fences e buffers de hardware/software entre diferentes controladores e a HLOS (High-Level OS). Ele age como ponte para sincronizar operações de câmera (cam_sync), vídeo (msm_vidc), display (sde/dpu) e GPU (kgsl) com suporte a importação de sync fences do Android.

---

## 2. Estruturas e IOCTLs Mapeados
O driver expõe a interface de controle via `/dev/synx_device` utilizando o IOCTL `0xC0185382` (`_IOWR('S', 0x82, struct synx_ioctl_ops)`).

### Assinatura do Cabeçalho IOCTL
```c
struct synx_ioctl_ops {
	u32 op_id;
	u32 size;
	u32 reserved;
	u32 padding;
	u64 user_payload;
};
```

### Mapeamento de Opcodes (`op_id`)
* **`0`**: `synx_handle_create`
* **`1`**: `synx_handle_release`
* **`2`**: `synx_handle_signal`
* **`3`**: `synx_handle_merge`
* **`6`**: `synx_handle_wait`
* **`10`**: `synx_handle_import`
* **`13`**: `synx_handle_get_fence`
* **`14`**: `synx_handle_initialize`
* **`17`**: `synx_handle_initialize_v3`

---

## 3. Reconstrução Segura (Clean Kernel Stub & Interop)
Para manter paridade binária com o firmware oficial e permitir que módulos dependentes (como `msm_hw_fence`, display, câmera e vídeo) carreguem sem falhas de símbolos não resolvidos (unresolved symbols), implementamos todos os stubs e a API real de controle de fences usando `dma_fence` padrão do Linux.

### Registro de Interops do `hw_fence`
O driver integra com o módulo `msm_hw_fence` registrando a tabela de callbacks usando a seguinte função exportada por ele:
```c
int synx_hwfence_init_interops(struct synx_hwfence_interops *synx_ops, struct synx_hwfence_interops *hwfence_ops);
```

As funções registradas permitem a troca bidirecional de status de fences de hardware e software diretamente entre os frameworks.

---

## 4. Resolução de Compilação e Verificação da Estrutura

Durante a compilação do driver `synx_driver.ko` e do driver interop `msm_hw_fence.ko`, resolvemos com sucesso as seguintes inconsistências:
1. **Unificação da Estrutura `synx_session`**: Identificamos que o driver interop `msm_hw_fence` acessava os membros `type` e `client` do struct `synx_session`, enquanto o driver core `msm_synx` acessava o membro `client_id`. Criamos uma definição única em `synx_api.h` utilizando uma `union` contendo `type` e `client_id` no offset correto de 8 bytes (conforme descoberto a partir da descompilação de `synx_initialize`), o que permitiu compilar ambos os drivers sem erros e com alinhamento de memória idêntico ao driver oficial.
2. **Definições de Constantes de Hardware Fences**: Adicionamos os mapeamentos de hardware fences (`SYNX_CLIENT_HW_FENCE_*`) no intervalo de 1024 a 4096 (como `SYNX_CLIENT_HW_FENCE_VID_CTX0 = 1216`), o que corresponde perfeitamente ao offset e ao comportamento dinâmico detectado nos logs de dmesg do smartphone oficial.
3. **Compilação sem Erros**: Os módulos `msm_hw_fence.ko` e `synx_driver.ko` foram compilados com sucesso usando a toolchain oficial Clang.


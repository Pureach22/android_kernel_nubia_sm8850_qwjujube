# Análise de Engenharia Reversa e Dependências - Graphics Kernel (ZTE RedMagic 11 Pro - NX809J)

## 1. Visão Geral das Dependências do KGSL (Adreno GPU)
O driver de gráficos proprietário da Qualcomm (KGSL) gerencia o mapeamento de memória da GPU e as páginas seguras (Content Protection). Ele faz uso intensivo do framework `mem_buf` (`mem_buf_dev.ko`) para validar permissões de VM (Virtual Machine) ao importar buffers compartilhados (dma-bufs).

---

## 2. Estruturas Reconstruídas de `linux/mem-buf.h`
Durante a engenharia reversa das chamadas contidas no módulo `kgsl.ko` original e cruzamento com o módulo `mem_buf_dev.ko` carregado no dispositivo físico, mapeamos a interface de compartilhamento de buffers seguros.

### `struct mem_buf_lend_kernel_arg`
Controla o empréstimo (lend) de páginas de memória física do Kernel para as partições seguras da GPU/CP:
```c
struct mem_buf_lend_kernel_arg {
	u32 nr_acl_entries; // Offset 0
	int *vmids;         // Offset 8
	int *perms;         // Offset 16
	u32 handle;         // Offset 24
};
```

### `struct mem_buf_retrieve_kernel_arg`
Gerencia a recuperação e reintegração de buffers devolvidos pelas VMs seguras:
```c
struct mem_buf_retrieve_kernel_arg {
	u32 sender_vmid;      // Offset 0
	u32 nr_acl_entries;   // Offset 4
	int *vmids;           // Offset 8
	int *perms;           // Offset 16
	u32 memparcel_hdl;    // Offset 24
	u32 fd_flags;         // Offset 28
};
```

---

## 3. Validação das Funções do KGSL
No arquivo `kgsl.c`, o driver utiliza as seguintes chamadas da API `mem_buf` para garantir o isolamento de buffers pixel/non-pixel:

* **`mem_buf_dma_buf_copy_vmperm`**: Usado para copiar a lista de permissões da VM associada ao dma-buf importado. O KGSL valida se o ID da VM de destino (`vmid`) confere com a permissão exigida (`VMID_CP_PIXEL`).
* **`mem_buf_dma_buf_exclusive_owner`**: Garante que buffers em modo protegido (`SECURE`) não possuam outros donos de hardware concorrentes ou acessos indevidos da HLOS (Linux).

---

## 4. Validação Dinâmica via KernelSU Overlay
* **Status:** Concluído com sucesso.
* **Procedimento:** O módulo `msm_kgsl.ko` compilado a partir do código reconstruído foi injetado via bind-mount usando o KernelSU-Next na partição `vendor_dlkm`.
* **Resultados:**
  * O driver de GPU inicializou corretamente sem travar ou causar Kernel Panic.
  * O firmware da GPU (`gen80200_zap.mbn` e `gen80200_aqe.fw`) carregou com sucesso.
  * A tabela de frequências de overclock de 1200MHz (`max_gpuclk` = 1.2 GHz) foi exibida e validada através de `/sys/class/kgsl/kgsl-3d0/freq_table_mhz` e `/sys/class/kgsl/kgsl-3d0/max_gpuclk`.
  * Os contadores de energia (`num_pwrlevels` = 18) e estatísticas de uso da GPU (`gpu_clock_stats`) funcionaram sem anomalias de ABI ou desalinhamento.


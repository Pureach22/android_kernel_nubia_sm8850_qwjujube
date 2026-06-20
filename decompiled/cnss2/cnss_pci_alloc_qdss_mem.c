__int64 __fastcall cnss_pci_alloc_qdss_mem(_QWORD *a1)
{
  __int64 v1; // x20
  unsigned int v2; // w8
  unsigned int v4; // w21
  __int64 v5; // x22
  __int64 *v6; // x23
  __int64 v7; // x0
  unsigned __int64 StatusReg; // x8
  const char *v9; // x1
  __int16 v10; // w9
  const char *v11; // x8
  unsigned int v12; // w9
  __int64 v13; // x10
  unsigned int v14; // w11

  v1 = a1[1];
  v2 = *(_DWORD *)(v1 + 4144);
  if ( !v2 )
    return 0;
  v4 = 0;
  v5 = v1 + 4152;
  while ( 1 )
  {
    v6 = (__int64 *)(v5 + 40LL * (int)v4);
    if ( v6[1] || !*v6 )
      goto LABEL_3;
    v7 = dma_alloc_attrs(*a1 + 200LL, *v6, v6 + 2, 3264, 0);
    v6[1] = v7;
    if ( !v7 )
      break;
    v2 = *(_DWORD *)(v1 + 4144);
LABEL_3:
    if ( ++v4 >= v2 )
      goto LABEL_14;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0 )
  {
    v9 = "irq";
  }
  else
  {
    v10 = *(_DWORD *)(StatusReg + 16);
    v11 = (const char *)(StatusReg + 2320);
    if ( (v10 & 0xFF00) != 0 )
      v9 = "soft_irq";
    else
      v9 = v11;
  }
  cnss_debug_ipc_log_print(
    cnss_ipc_log_context,
    v9,
    "cnss_pci_alloc_qdss_mem",
    3u,
    3u,
    "Failed to allocate QDSS memory for FW, size: 0x%zx, type: %u, chuck-ID: %d\n",
    *v6,
    *((unsigned int *)v6 + 7),
    v4);
  v2 = *(_DWORD *)(v1 + 4144);
LABEL_14:
  if ( v4 < v2 )
  {
    v12 = v4;
    do
    {
      v13 = v5 + 40LL * (int)v12++;
      *(_QWORD *)v13 = 0;
      v14 = *(_DWORD *)(v1 + 4144);
      *(_DWORD *)(v13 + 28) = 0;
    }
    while ( v12 < v14 );
    *(_DWORD *)(v1 + 4144) = v4;
  }
  return 0;
}

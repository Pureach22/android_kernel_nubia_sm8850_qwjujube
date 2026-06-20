__int64 __fastcall cnss_pci_alloc_fw_mem(__int64 *a1)
{
  __int64 v1; // x23
  __int64 v2; // x27
  unsigned int v3; // w24
  unsigned __int64 StatusReg; // x21
  __int64 v5; // x26
  __int64 v6; // x1
  __int64 v7; // x0
  __int64 v8; // x7
  __int64 v9; // x8
  const char *v10; // x1
  unsigned __int64 v12; // x19
  const char *v13; // x1
  __int64 v14; // x7
  const char *v15; // x1
  char vars0; // [xsp+0h] [xbp+0h]
  char vars0a; // [xsp+0h] [xbp+0h]

  v1 = a1[1];
  if ( *(_DWORD *)(v1 + 1720) )
  {
    v2 = *a1;
    v3 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v5 = v1 + 1728 + 40LL * (int)v3;
      if ( !*(_QWORD *)(v5 + 8) )
      {
        v6 = *(_QWORD *)v5;
        if ( *(_QWORD *)v5 )
        {
          while ( 1 )
          {
            v7 = dma_alloc_attrs(v2 + 200, v6, v5 + 16, 3264, *(_QWORD *)(v5 + 32));
            *(_QWORD *)(v5 + 8) = v7;
            if ( v7 )
              break;
            v9 = *(_QWORD *)(v5 + 32);
            if ( (v9 & 0x40) == 0 )
            {
              v12 = _ReadStatusReg(SP_EL0);
              if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
              {
                v13 = "irq";
              }
              else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
              {
                v13 = "soft_irq";
              }
              else
              {
                v13 = (const char *)(v12 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v13,
                "cnss_pci_alloc_fw_mem",
                3u,
                3u,
                "Failed to allocate memory for FW, size: 0x%zx, type: %u\n",
                *(_QWORD *)v5,
                *(unsigned int *)(v5 + 28),
                vars0);
              if ( (*(_DWORD *)(v12 + 16) & 0xF0000) != 0 )
              {
                v15 = "irq";
              }
              else if ( (*(_DWORD *)(v12 + 16) & 0xFF00) != 0 )
              {
                v15 = "soft_irq";
              }
              else
              {
                v15 = (const char *)(v12 + 2320);
              }
              cnss_debug_ipc_log_print(
                cnss_ipc_log_context,
                v15,
                "cnss_pci_alloc_fw_mem",
                3u,
                3u,
                "ASSERT at line %d\n",
                5633,
                v14,
                vars0a);
              __break(0x800u);
              return 4294967284LL;
            }
            v10 = "irq";
            *(_QWORD *)(v5 + 32) = v9 & 0xFFFFFFFFFFFFFFBFLL;
            if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
            {
              if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
                v10 = "soft_irq";
              else
                v10 = (const char *)(StatusReg + 2320);
            }
            cnss_debug_ipc_log_print(
              cnss_ipc_log_context,
              v10,
              "cnss_pci_alloc_fw_mem",
              7u,
              7u,
              "Fallback to non-contiguous memory for FW, Mem type: %u\n",
              *(unsigned int *)(v5 + 28),
              v8,
              vars0);
            v6 = *(_QWORD *)v5;
          }
        }
      }
      ++v3;
    }
    while ( v3 < *(_DWORD *)(v1 + 1720) );
  }
  return 0;
}

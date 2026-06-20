__int64 __fastcall cnss_pci_free_qdss_mem(__int64 result)
{
  __int64 v1; // x22
  unsigned int v2; // w8
  _QWORD *v3; // x19
  unsigned int v4; // w23
  unsigned __int64 StatusReg; // x27
  __int64 *v6; // x25
  const char *v7; // x1

  v1 = *(_QWORD *)(result + 8);
  v2 = *(_DWORD *)(v1 + 4144);
  if ( v2 )
  {
    v3 = (_QWORD *)result;
    v4 = 0;
    StatusReg = _ReadStatusReg(SP_EL0);
    do
    {
      v6 = (__int64 *)(v1 + 4152 + 40LL * (int)v4);
      if ( v6[1] && *v6 )
      {
        v7 = "irq";
        if ( (*(_DWORD *)(StatusReg + 16) & 0xF0000) == 0 )
        {
          if ( (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
            v7 = "soft_irq";
          else
            v7 = (const char *)(StatusReg + 2320);
        }
        cnss_debug_ipc_log_print(
          cnss_ipc_log_context,
          v7,
          "cnss_pci_free_qdss_mem",
          7u,
          7u,
          "Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
          (__int64)(v6 + 2),
          *v6,
          *((_DWORD *)v6 + 7));
        result = dma_free_attrs(*v3 + 200LL, *v6, v6[1], v6[2], 0);
        *v6 = 0;
        v6[1] = 0;
        v6[2] = 0;
        v2 = *(_DWORD *)(v1 + 4144);
        *((_DWORD *)v6 + 7) = 0;
      }
      ++v4;
    }
    while ( v4 < v2 );
  }
  *(_DWORD *)(v1 + 4144) = 0;
  return result;
}

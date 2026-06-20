__int64 __fastcall icnss_free_qdss_mem(__int64 result)
{
  unsigned int v1; // w8
  __int64 v2; // x19
  __int64 v3; // x23
  unsigned int i; // w21
  _QWORD *v5; // x26

  v1 = *(_DWORD *)(result + 3280);
  v2 = result;
  if ( v1 )
  {
    v3 = *(_QWORD *)(result + 8);
    for ( i = 0; i < v1; ++i )
    {
      v5 = (_QWORD *)(v2 + 3288 + 40LL * (int)i);
      if ( v5[1] && *v5 )
      {
        ipc_log_string(
          icnss_ipc_log_context,
          "icnss2: Freeing memory for QDSS: pa: %pa, size: 0x%zx, type: %u\n",
          v5 + 2,
          *v5,
          *((_DWORD *)v5 + 7));
        result = dma_free_attrs(v3 + 16, *v5, v5[1], v5[2], 0);
        *v5 = 0;
        v5[1] = 0;
        v5[2] = 0;
        v1 = *(_DWORD *)(v2 + 3280);
        *((_DWORD *)v5 + 7) = 0;
      }
    }
  }
  *(_DWORD *)(v2 + 3280) = 0;
  return result;
}

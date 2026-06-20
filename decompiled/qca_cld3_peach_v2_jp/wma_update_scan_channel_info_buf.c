__int64 __fastcall wma_update_scan_channel_info_buf(
        __int64 result,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v13; // x20
  _DWORD *v14; // x23
  __int64 v15; // x24
  int *v16; // x25
  int v17; // t1

  if ( a3 )
  {
    v13 = result;
    *(_BYTE *)(a2 + 32) = 0;
    if ( a4 )
    {
      v14 = (_DWORD *)(a2 + 36);
      if ( a4 >= 0x10 )
        v15 = 16;
      else
        v15 = a4;
      v16 = (int *)(a3 + 4);
      do
      {
        v17 = *v16;
        v16 += 2;
        *v14++ = v17;
        result = qdf_trace_msg(
                   0x36u,
                   8u,
                   "%s: cca_info->rx_clear_count:%d",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "wma_update_scan_channel_info_buf");
        --v15;
        ++*(_BYTE *)(a2 + 32);
      }
      while ( v15 );
    }
    *(_BYTE *)(a2 + 33) = 1;
    *(_DWORD *)(a2 + 28) = *(_DWORD *)(v13 + 56);
  }
  return result;
}

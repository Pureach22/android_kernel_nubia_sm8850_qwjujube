__int64 __fastcall crypto_free_list(
        __int64 result,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x24
  __int64 v11; // x19
  unsigned __int8 *v12; // x23
  unsigned int v19; // w9
  __int64 v20; // [xsp+0h] [xbp-10h]

  v10 = *a2;
  if ( *a2 )
  {
    v11 = result;
    do
    {
      v12 = (unsigned __int8 *)v10;
      v10 = *(_QWORD *)(v10 + 152);
      LODWORD(v20) = v12[5];
      qdf_trace_msg(
        0x1Cu,
        8u,
        "%s: crypto delete for link_id %d mac_addr %02x:%02x:%02x:**:**:%02x",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "crypto_free_list",
        v12[9],
        *v12,
        v12[1],
        v12[2],
        v20);
      result = _qdf_mem_free((__int64)v12);
      if ( *(_DWORD *)(v11 + 64) )
      {
        _X8 = (unsigned int *)(v11 + 64);
        __asm { PRFM            #0x11, [X8] }
        do
          v19 = __ldxr(_X8);
        while ( __stxr(v19 - 1, _X8) );
      }
      else
      {
        result = qdf_trace_msg(
                   0x1Cu,
                   8u,
                   "%s: Invalid crypto_key_cnt",
                   a3,
                   a4,
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   "crypto_free_list");
      }
    }
    while ( v10 );
  }
  return result;
}

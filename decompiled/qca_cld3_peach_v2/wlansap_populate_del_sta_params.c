__int64 __fastcall wlansap_populate_del_sta_params(
        const void *a1,
        unsigned __int16 a2,
        unsigned __int8 a3,
        _DWORD *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v15; // x5
  unsigned __int16 v16; // w8
  __int64 v17; // x6
  __int64 v18; // x7
  int v19; // w9
  int v20; // w10

  if ( a1 )
  {
    qdf_mem_copy(a4, a1, 6u);
  }
  else
  {
    *((_WORD *)a4 + 2) = -1;
    *a4 = -1;
  }
  v15 = a3;
  if ( a2 )
    v16 = a2;
  else
    v16 = 3;
  *((_WORD *)a4 + 6) = v16;
  if ( a3 != 12 && a3 != 10 )
  {
    v15 = 12;
    *((_BYTE *)a4 + 14) = 12;
    if ( a4 )
      goto LABEL_10;
LABEL_12:
    v19 = 0;
    v17 = 0;
    v18 = 0;
    v20 = 0;
    return qdf_trace_msg(
             0x39u,
             8u,
             "%s: Delete STA with RC:%hu subtype:%hhu MAC::%02x:%02x:%02x:**:**:%02x",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "wlansap_populate_del_sta_params",
             v16,
             v15,
             v17,
             v18,
             v19,
             v20);
  }
  *((_BYTE *)a4 + 14) = a3;
  if ( !a4 )
    goto LABEL_12;
LABEL_10:
  v17 = *(unsigned __int8 *)a4;
  v18 = *((unsigned __int8 *)a4 + 1);
  v19 = *((unsigned __int8 *)a4 + 2);
  v20 = *((unsigned __int8 *)a4 + 5);
  return qdf_trace_msg(
           0x39u,
           8u,
           "%s: Delete STA with RC:%hu subtype:%hhu MAC::%02x:%02x:%02x:**:**:%02x",
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           "wlansap_populate_del_sta_params",
           v16,
           v15,
           v17,
           v18,
           v19,
           v20);
}

__int64 __fastcall wlan_conn_rec_print(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x9
  const char *v14; // x7
  int v15; // w9
  int v16; // w10
  int v17; // w11
  int v18; // w13
  int v19; // w14
  unsigned int v20; // w1
  int v22; // [xsp+18h] [xbp-18h]

  v12 = *(unsigned int *)(a1 + 8);
  if ( (a4 & 1) != 0 )
  {
    if ( (unsigned int)v12 > 0x19 )
      v14 = "unknown";
    else
      v14 = off_9E6778[v12];
    v15 = *(_DWORD *)(a1 + 32);
    v16 = *(_DWORD *)(a1 + 36);
    v17 = *(unsigned __int8 *)(a1 + 16);
    v18 = *(unsigned __int8 *)(a1 + 18);
    v19 = *(unsigned __int8 *)(a1 + 21);
    v22 = *(unsigned __int8 *)(a1 + 17);
    v20 = 4;
  }
  else
  {
    if ( (unsigned int)v12 > 0x19 )
      v14 = "unknown";
    else
      v14 = off_9E6778[v12];
    v15 = *(_DWORD *)(a1 + 32);
    v16 = *(_DWORD *)(a1 + 36);
    v17 = *(unsigned __int8 *)(a1 + 16);
    v18 = *(unsigned __int8 *)(a1 + 18);
    v19 = *(unsigned __int8 *)(a1 + 21);
    v20 = 8;
    v22 = *(unsigned __int8 *)(a1 + 17);
  }
  return qdf_trace_msg(
           0x59u,
           v20,
           "i %d ti 0x%08llx ms %u vdv %d %s a1 0x%x a2 0x%x %02x:%02x:%02x:**:**:%02x",
           a5,
           a6,
           a7,
           a8,
           a9,
           a10,
           a11,
           a12,
           a2,
           *(_QWORD *)a1,
           a3,
           (unsigned int)*(char *)(a1 + 12),
           v14,
           v15,
           v16,
           v17,
           v22,
           v18,
           v19);
}

__int64 __fastcall wlan_hdd_release_intf_addr(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v17; // x4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  __int64 v21; // x20
  unsigned __int64 v22; // x8
  unsigned __int64 v23; // x9
  __int64 v24; // x8
  const char *v25; // x2
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x4
  __int64 v35; // x5
  __int64 v36; // x6
  __int64 v37; // x7
  __int64 result; // x0
  unsigned __int64 v44; // x10
  unsigned __int64 v47; // x10

  if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3696) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3700) )
  {
    v21 = a1 + 3696;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3704) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3708) )
  {
    v21 = a1 + 3704;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3712) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3716) )
  {
    v21 = a1 + 3712;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3720) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3724) )
  {
    v21 = a1 + 3720;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3728) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3732) )
  {
    v21 = a1 + 3728;
  }
  else
  {
    if ( *(_DWORD *)a2 != *(_DWORD *)(a1 + 3736) || *((unsigned __int16 *)a2 + 2) != *(unsigned __int16 *)(a1 + 3740) )
    {
      if ( a2 )
      {
        v17 = *a2;
        v18 = a2[1];
        v19 = a2[2];
        v20 = a2[5];
      }
      else
      {
        v19 = 0;
        v17 = 0;
        v18 = 0;
        v20 = 0;
      }
      return qdf_trace_msg(
               0x33u,
               8u,
               "%s: Releasing non existing MAC %02x:%02x:%02x:**:**:%02x",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "wlan_hdd_release_intf_addr",
               v17,
               v18,
               v19,
               v20);
    }
    v21 = a1 + 3736;
  }
  v22 = *(unsigned __int8 *)(v21 + 7);
  v23 = v22 >> 6;
  v24 = 1LL << v22;
  if ( *(_BYTE *)(v21 + 6) == 1 )
  {
    _X9 = (unsigned __int64 *)(a1 + 3832 + 8 * v23);
    __asm { PRFM            #0x11, [X9] }
    do
      v44 = __ldxr(_X9);
    while ( __stxr(v44 & ~v24, _X9) );
    v25 = "%s: Releasing MAC from provisioned list";
  }
  else
  {
    _X9 = (unsigned __int64 *)(a1 + 3840 + 8 * v23);
    __asm { PRFM            #0x11, [X9] }
    do
      v47 = __ldxr(_X9);
    while ( __stxr(v47 & ~v24, _X9) );
    v25 = "%s: Releasing MAC from derived list";
  }
  qdf_trace_msg(0x33u, 8u, v25, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_release_intf_addr");
  if ( a2 )
  {
    v34 = *a2;
    v35 = a2[1];
    v36 = a2[2];
    v37 = a2[5];
  }
  else
  {
    v36 = 0;
    v34 = 0;
    v35 = 0;
    v37 = 0;
  }
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: %02x:%02x:%02x:**:**:%02x",
             v26,
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             "wlan_hdd_release_intf_addr",
             v34,
             v35,
             v36,
             v37);
  *(_QWORD *)v21 = 0;
  return result;
}

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
  __int64 v18; // x4
  __int64 v19; // x5
  __int64 v20; // x6
  __int64 v21; // x7
  __int64 v22; // x20
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x9
  __int64 v25; // x8
  const char *v26; // x2
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  __int64 result; // x0
  unsigned __int64 v45; // x10
  unsigned __int64 v48; // x10

  if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3696) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3700) )
  {
    v22 = a1 + 3696;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3704) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3708) )
  {
    v22 = a1 + 3704;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3712) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3716) )
  {
    v22 = a1 + 3712;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3720) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3724) )
  {
    v22 = a1 + 3720;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3728) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3732) )
  {
    v22 = a1 + 3728;
  }
  else if ( *(_DWORD *)a2 == *(_DWORD *)(a1 + 3736) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(a1 + 3740) )
  {
    v22 = a1 + 3736;
  }
  else
  {
    if ( *(_DWORD *)a2 != *(_DWORD *)(a1 + 3744) || *((unsigned __int16 *)a2 + 2) != *(unsigned __int16 *)(a1 + 3748) )
    {
      if ( a2 )
      {
        v18 = *a2;
        v19 = a2[1];
        v20 = a2[2];
        v21 = a2[5];
      }
      else
      {
        v20 = 0;
        v18 = 0;
        v19 = 0;
        v21 = 0;
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
               v18,
               v19,
               v20,
               v21);
    }
    v22 = a1 + 3744;
  }
  v23 = *(unsigned __int8 *)(v22 + 7);
  v24 = v23 >> 6;
  v25 = 1LL << v23;
  if ( *(_BYTE *)(v22 + 6) == 1 )
  {
    _X9 = (unsigned __int64 *)(a1 + 3856 + 8 * v24);
    __asm { PRFM            #0x11, [X9] }
    do
      v45 = __ldxr(_X9);
    while ( __stxr(v45 & ~v25, _X9) );
    v26 = "%s: Releasing MAC from provisioned list";
  }
  else
  {
    _X9 = (unsigned __int64 *)(a1 + 3864 + 8 * v24);
    __asm { PRFM            #0x11, [X9] }
    do
      v48 = __ldxr(_X9);
    while ( __stxr(v48 & ~v25, _X9) );
    v26 = "%s: Releasing MAC from derived list";
  }
  qdf_trace_msg(0x33u, 8u, v26, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_hdd_release_intf_addr");
  if ( a2 )
  {
    v35 = *a2;
    v36 = a2[1];
    v37 = a2[2];
    v38 = a2[5];
  }
  else
  {
    v37 = 0;
    v35 = 0;
    v36 = 0;
    v38 = 0;
  }
  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: %02x:%02x:%02x:**:**:%02x",
             v27,
             v28,
             v29,
             v30,
             v31,
             v32,
             v33,
             v34,
             "wlan_hdd_release_intf_addr",
             v35,
             v36,
             v37,
             v38);
  *(_QWORD *)v22 = 0;
  return result;
}

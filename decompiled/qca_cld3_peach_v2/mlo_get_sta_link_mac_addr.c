__int64 __fastcall mlo_get_sta_link_mac_addr(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13,
        __int64 a14,
        __int64 a15,
        unsigned __int16 a16)
{
  __int64 v16; // x29
  unsigned __int16 *v17; // x30
  int v18; // w8
  __int64 v19; // x8
  __int16 v20; // w9
  int v21; // w8

  if ( !a2 )
    return 16;
  v18 = *(unsigned __int8 *)(a2 + 2497);
  if ( !*(_BYTE *)(a2 + 2497) )
    return 16;
  if ( *(_DWORD *)(a2 + 2500) == (unsigned __int8)a1 )
  {
    v19 = a2 + 2500;
LABEL_5:
    v20 = *(_WORD *)(v19 + 44);
    v21 = *(_DWORD *)(v19 + 40);
    *(_WORD *)(a3 + 4) = v20;
    *(_DWORD *)a3 = v21;
    return 0;
  }
  if ( v18 == 1 )
    goto LABEL_8;
  if ( *(_DWORD *)(a2 + 2552) == (unsigned __int8)a1 )
  {
    v19 = a2 + 2552;
    goto LABEL_5;
  }
  if ( v18 == 2 )
    goto LABEL_8;
  if ( *(_DWORD *)(a2 + 2604) == (unsigned __int8)a1 )
  {
    v19 = a2 + 2604;
    goto LABEL_5;
  }
  if ( v18 == 3 )
  {
LABEL_8:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: Link mac addr not found",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "mlo_get_sta_link_mac_addr",
      v16,
      v17);
    return 16;
  }
  else
  {
    __break(0x5512u);
    __stxr(a16, v17);
    return mlo_roam_get_chan_freq(a1, a2);
  }
}

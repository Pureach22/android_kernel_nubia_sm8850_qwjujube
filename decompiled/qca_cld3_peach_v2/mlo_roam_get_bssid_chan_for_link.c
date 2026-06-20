__int64 __fastcall mlo_roam_get_bssid_chan_for_link(
        unsigned __int8 a1,
        __int64 a2,
        __int64 a3,
        void *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w8
  __int64 v13; // x19
  __int64 v14; // x20
  int v15; // w9
  __int64 v17; // x0

  if ( !a2 )
    return 16;
  v12 = *(unsigned __int8 *)(a2 + 2497);
  if ( !*(_BYTE *)(a2 + 2497) )
    return 16;
  if ( *(_DWORD *)(a2 + 2500) == a1 )
  {
    v13 = a3;
    v14 = a2 + 2500;
LABEL_5:
    qdf_mem_copy(a4, (const void *)(v14 + 8), 0x1Cu);
    v15 = *(_DWORD *)(v14 + 40);
    *(_WORD *)(v13 + 4) = *(_WORD *)(v14 + 44);
    *(_DWORD *)v13 = v15;
    return 0;
  }
  if ( v12 == 1 )
    goto LABEL_7;
  if ( *(_DWORD *)(a2 + 2552) == a1 )
  {
    v13 = a3;
    v14 = a2 + 2552;
    goto LABEL_5;
  }
  if ( v12 == 2 )
    goto LABEL_7;
  if ( *(_DWORD *)(a2 + 2604) == a1 )
  {
    v13 = a3;
    v14 = a2 + 2604;
    goto LABEL_5;
  }
  if ( v12 == 3 )
  {
LABEL_7:
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: roam sync info not found for vdev id %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "mlo_roam_get_bssid_chan_for_link");
    return 16;
  }
  __break(0x5512u);
  v17 = ((__int64 (*)(void))unk_7ABB2C)();
  return mlo_check_if_all_vdev_up(v17);
}

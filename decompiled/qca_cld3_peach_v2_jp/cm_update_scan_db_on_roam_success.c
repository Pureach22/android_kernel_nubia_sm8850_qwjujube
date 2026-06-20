__int64 __fastcall cm_update_scan_db_on_roam_success(
        __int64 a1,
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
  __int64 result; // x0
  __int64 *v17; // x23
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w3
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  int v35; // w3

  result = cm_get_cm_ctx_fl(a1, (__int64)"cm_update_scan_db_on_roam_success", 0x48Fu, a5, a6, a7, a8, a9, a10, a11, a12);
  if ( result )
  {
    v17 = (__int64 *)result;
    if ( *(_DWORD *)(a2 + 88) )
    {
      wlan_mlme_get_src_addr_from_frame(a2 + 88);
      if ( a3 )
        v26 = *(_DWORD *)(a3 + 64);
      else
        v26 = 0;
      cm_inform_bcn_probe(
        v17,
        *(char **)(a2 + 96),
        *(_DWORD *)(a2 + 88),
        v26,
        *(char *)(a3 + 60),
        a4,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25);
    }
    wlan_mlme_get_src_addr_from_frame(a2 + 72);
    if ( a3 )
    {
      v35 = *(_DWORD *)(a3 + 64);
      if ( v35 )
        cm_inform_bcn_probe(
          v17,
          *(char **)(a2 + 80),
          *(_DWORD *)(a2 + 72),
          v35,
          *(char *)(a3 + 60),
          a4,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34);
    }
    return cm_update_scan_mlme_on_roam(a1, (int *)(a2 + 8), 2, v27, v28, v29, v30, v31, v32, v33, v34);
  }
  return result;
}

__int64 __fastcall hdd_handle_nud_fail_sta(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  __int64 v21; // x22
  __int16 v22; // w10
  __int64 v23; // x0
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x1
  int v36; // [xsp+0h] [xbp-40h] BYREF
  __int16 v37; // [xsp+4h] [xbp-3Ch]
  _QWORD v38[4]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+30h] [xbp-10h]
  __int64 v41; // [xsp+38h] [xbp-8h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0;
  v40 = 0;
  memset(v38, 0, sizeof(v38));
  if ( (hdd_is_roaming_in_progress(a1, a3, a4, a5, a6, a7, a8, a9, a10) & 1) != 0 )
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: Roaming already in progress, cannot trigger roam.",
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               v19,
               "hdd_handle_nud_fail_sta");
  }
  else
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: nud fail detected, try roaming to better BSSID, vdev id: %d",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "hdd_handle_nud_fail_sta",
      *(unsigned __int8 *)(*(_QWORD *)(a2 + 52824) + 8LL));
    v21 = *(_QWORD *)(a2 + 52824);
    qdf_mem_set(v38, 0x30u, 0);
    v22 = *(_WORD *)(v21 + 304);
    v23 = a1[1];
    LODWORD(v38[0]) = *(_DWORD *)(v21 + 300);
    v39 = 0x100000002LL;
    WORD2(v38[0]) = v22;
    LODWORD(v40) = 1;
    ucfg_dlm_add_bssid_to_reject_list(v23, (__int64)v38);
    v24 = *a1;
    LOBYTE(v36) = 0;
    result = ucfg_mlme_get_roaming_offload(v24, (char *)&v36);
    if ( (unsigned __int8)v36 == 1 )
    {
      v33 = *(_QWORD *)(a2 + 52824);
      v34 = a1[1];
      v37 = 0;
      v35 = *(unsigned __int8 *)(v33 + 8);
      v36 = 0;
      result = ucfg_wlan_cm_roam_invoke(
                 v34,
                 v35,
                 (unsigned __int8 *)&v36,
                 0,
                 2u,
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

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
  __int64 v22; // x11
  int v23; // w8
  __int16 v24; // w9
  __int64 v25; // x0
  __int64 v26; // x1
  __int64 v27; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x1
  int v39; // [xsp+8h] [xbp-78h] BYREF
  __int16 v40; // [xsp+Ch] [xbp-74h]
  _QWORD v41[11]; // [xsp+10h] [xbp-70h] BYREF
  __int64 v42; // [xsp+68h] [xbp-18h]
  __int64 v43; // [xsp+70h] [xbp-10h]
  __int64 v44; // [xsp+78h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v42 = 0;
  v43 = 0;
  memset(v41, 0, sizeof(v41));
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
      *(unsigned __int8 *)(*(_QWORD *)(a2 + 52832) + 8LL));
    v21 = *(_QWORD *)(a2 + 52832);
    qdf_mem_set(v41, 0x68u, 0);
    v22 = *(_QWORD *)(a2 + 52832);
    LODWORD(v43) = 1;
    v23 = *(_DWORD *)(v21 + 308);
    v42 = 0x100000002LL;
    v24 = *(_WORD *)(v21 + 312);
    v25 = a1[1];
    v26 = *(unsigned __int8 *)(v22 + 8);
    LODWORD(v41[0]) = v23;
    WORD2(v41[0]) = v24;
    ((void (__fastcall *)(__int64, __int64, _QWORD *))dlm_update_mlo_reject_ap_info)(v25, v26, v41);
    ucfg_dlm_add_bssid_to_reject_list(a1[1], (__int64)v41);
    v27 = *a1;
    LOBYTE(v39) = 0;
    result = ucfg_mlme_get_roaming_offload(v27, (char *)&v39);
    if ( (unsigned __int8)v39 == 1 )
    {
      v36 = *(_QWORD *)(a2 + 52832);
      v37 = a1[1];
      v40 = 0;
      v38 = *(unsigned __int8 *)(v36 + 8);
      v39 = 0;
      result = ucfg_wlan_cm_roam_invoke(
                 v37,
                 v38,
                 (unsigned __int8 *)&v39,
                 0,
                 2u,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 v33,
                 v34,
                 v35);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

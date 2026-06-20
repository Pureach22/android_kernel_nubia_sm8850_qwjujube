__int64 __fastcall cm_handle_roam_reason_suitable_ap(
        unsigned __int8 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x20
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  __int64 v46; // x8
  __int64 v47; // [xsp+8h] [xbp-38h] BYREF
  __int64 v48; // [xsp+10h] [xbp-30h]
  __int64 (__fastcall *v49)(__int64); // [xsp+18h] [xbp-28h]
  __int64 v50; // [xsp+20h] [xbp-20h]
  __int64 v51; // [xsp+28h] [xbp-18h]
  __int64 v52; // [xsp+30h] [xbp-10h]
  __int64 v53; // [xsp+38h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = (__int64)_cds_get_context(54, (__int64)"wma_handle_roam_reason_suitable_ap", a3, a4, a5, a6, a7, a8, a9, a10);
  if ( result )
  {
    v21 = result;
    mlme_set_roam_reason_better_ap(
      *(_QWORD *)(*(_QWORD *)(result + 520) + 488LL * a1),
      1,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20);
    mlme_set_hb_ap_rssi(*(_QWORD *)(*(_QWORD *)(v21 + 520) + 488LL * a1), a2, v22, v23, v24, v25, v26, v27, v28, v29);
    qdf_trace_msg(
      0x36u,
      8u,
      "%s: Bmiss scan AP found for vdevid %x, rssi %d",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      "wma_handle_roam_reason_suitable_ap",
      a1,
      a2);
    v51 = 0;
    v52 = 0;
    v49 = nullptr;
    v50 = 0;
    v47 = 0;
    v48 = 0;
    result = _qdf_mem_malloc(0x10u, "wma_roam_better_ap_handler", 2653);
    if ( result )
    {
      v46 = *(_QWORD *)(v21 + 32);
      *(_BYTE *)result = a1;
      *(_QWORD *)(result + 8) = v46;
      v48 = result;
      v49 = wlan_cm_host_roam_start;
      qdf_trace_msg(
        0x36u,
        8u,
        "%s: Posting ROam start ind to connection manager, vdev %d",
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        "wma_roam_better_ap_handler",
        a1);
      result = scheduler_post_message_debug(
                 0x36u,
                 0x48u,
                 21,
                 (unsigned __int16 *)&v47,
                 0xA69u,
                 (__int64)"wma_roam_better_ap_handler");
      if ( (_DWORD)result )
        result = _qdf_mem_free(v48);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

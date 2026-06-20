__int64 __fastcall rrm_send_sta_stats_req(__int64 a1, __int64 a2, const void *a3)
{
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  unsigned int v15; // w20
  __int64 v16; // x8
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x20
  _QWORD *context; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x8
  __int64 (*v37)(void); // x8
  unsigned int v38; // w0
  int v39; // w9
  int v40; // w8
  int v41; // w9
  int v42; // w9
  int v43; // w8
  int v44; // w9
  unsigned int v45; // w0
  const char *v46; // x2
  unsigned int v48; // w0
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // [xsp+10h] [xbp-60h] BYREF
  __int64 v58; // [xsp+18h] [xbp-58h] BYREF
  _QWORD v59[2]; // [xsp+20h] [xbp-50h] BYREF
  __int64 v60; // [xsp+30h] [xbp-40h]
  __int64 v61; // [xsp+38h] [xbp-38h]
  __int64 v62; // [xsp+40h] [xbp-30h]
  _QWORD v63[2]; // [xsp+48h] [xbp-28h] BYREF
  void *v64; // [xsp+58h] [xbp-18h]
  __int64 v65; // [xsp+60h] [xbp-10h]
  __int64 v66; // [xsp+68h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 21552);
  v64 = nullptr;
  v65 = 0;
  v63[0] = 0;
  v63[1] = 0;
  v61 = 0;
  v62 = 0;
  v60 = 0;
  v57 = 0;
  v58 = 0;
  wlan_cp_stats_infra_cp_get_context(v6, &v58, &v57);
  if ( v58 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: another request already in progress",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "rrm_send_sta_stats_req");
    v15 = 16;
    goto LABEL_22;
  }
  v16 = *(_QWORD *)(a2 + 16);
  v64 = &rmm_sta_stats_response_cb;
  LODWORD(v16) = *(unsigned __int8 *)(v16 + 104);
  v59[0] = 6;
  v59[1] = 0;
  HIDWORD(v61) = 1;
  v62 = (unsigned int)v16 | 0x100000000LL;
  HIDWORD(v60) = 0;
  *(_BYTE *)(a1 + 21496) = v16;
  qdf_mem_copy(v63, a3, 6u);
  v17 = _qdf_mem_malloc(0xA428u, "rrm_update_vdev_stats", 737);
  if ( !v17 )
  {
    v15 = 2;
    goto LABEL_20;
  }
  v26 = v17;
  context = _cds_get_context(71, (__int64)"rrm_update_vdev_stats", v18, v19, v20, v21, v22, v23, v24, v25);
  if ( context && *context )
  {
    v36 = *(_QWORD *)(*context + 32LL);
    if ( v36 )
    {
      v37 = *(__int64 (**)(void))(v36 + 200);
      if ( v37 )
      {
        if ( *((_DWORD *)v37 - 1) != 1504611911 )
          __break(0x8228u);
        v38 = v37();
        if ( v38 )
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: Failed to get stats %d",
            v28,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            "rrm_update_vdev_stats",
            v38);
          _qdf_mem_free(v26);
          v15 = 16;
LABEL_20:
          v46 = "%s: Failed to register resp callback: %d";
LABEL_21:
          qdf_trace_msg(0x35u, 2u, v46, v18, v19, v20, v21, v22, v23, v24, v25, "rrm_send_sta_stats_req", v15);
          goto LABEL_22;
        }
      }
    }
  }
  else
  {
    qdf_trace_msg(0x89u, 8u, "%s: Invalid Instance", v28, v29, v30, v31, v32, v33, v34, v35, "cdp_host_get_vdev_stats");
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "counter stats count: fragment (tx: %d rx: %d) group tx: %llu mac stats count: retry : %d multiple retry: %d frame duplicate %d",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    *(unsigned int *)(v26 + 4184),
    *(unsigned int *)(v26 + 6172),
    *(_QWORD *)(v26 + 2504),
    *(unsigned int *)(v26 + 3328),
    *(unsigned int *)(v26 + 3336),
    *(_DWORD *)(v26 + 6168));
  if ( *(_BYTE *)(a1 + 21234) == 1 )
  {
    v42 = *(_DWORD *)(a1 + 21240);
    *(_DWORD *)(a1 + 21236) = *(_DWORD *)(v26 + 3328) - *(_DWORD *)(a1 + 21236);
    v43 = *(_DWORD *)(v26 + 3336) - v42;
    v44 = *(_DWORD *)(a1 + 21244);
    *(_DWORD *)(a1 + 21240) = v43;
    *(_DWORD *)(a1 + 21244) = *(_DWORD *)(v26 + 6168) - v44;
  }
  else if ( !*(_BYTE *)(a1 + 21234) )
  {
    v39 = *(_DWORD *)(a1 + 21260);
    *(_DWORD *)(a1 + 21236) = *(_DWORD *)(v26 + 4184) - *(_DWORD *)(a1 + 21236);
    v40 = *(_DWORD *)(v26 + 6172) - v39;
    v41 = *(_DWORD *)(a1 + 21240);
    *(_DWORD *)(a1 + 21260) = v40;
    *(_DWORD *)(a1 + 21240) = *(_DWORD *)(v26 + 2504) - v41;
  }
  _qdf_mem_free(v26);
  v45 = wlan_cp_stats_infra_cp_register_resp_cb(*(_QWORD *)(a1 + 21552), v59);
  if ( v45 )
  {
    v15 = v45;
    goto LABEL_20;
  }
  v48 = wlan_cp_stats_send_infra_cp_req(*(_QWORD *)(a1 + 21552), v59);
  if ( !v48 )
  {
    v15 = 0;
    goto LABEL_22;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to send stats request status: %d",
    v49,
    v50,
    v51,
    v52,
    v53,
    v54,
    v55,
    v56,
    "rrm_send_sta_stats_req",
    v48);
  v15 = wlan_cp_stats_infra_cp_deregister_resp_cb(*(_QWORD *)(a1 + 21552));
  if ( v15 )
  {
    v46 = "%s: failed to deregister callback %d";
    goto LABEL_21;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return v15;
}

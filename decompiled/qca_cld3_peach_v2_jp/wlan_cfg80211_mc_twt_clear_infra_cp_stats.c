__int64 __fastcall wlan_cfg80211_mc_twt_clear_infra_cp_stats(
        __int64 a1,
        int a2,
        const void *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x8
  __int64 v23; // x23
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  unsigned int v33; // w20
  const char *v34; // x2
  __int64 v35; // x0
  __int64 v36; // x19
  __int64 v37; // x24
  __int64 v38; // x25
  __int64 v39; // x0
  unsigned int v40; // w9
  __int64 bsspeer; // x0
  double v42; // d0
  double v43; // d1
  double v44; // d2
  double v45; // d3
  double v46; // d4
  double v47; // d5
  double v48; // d6
  double v49; // d7
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w21
  unsigned int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v77; // w21
  unsigned int v78; // w0
  double v79; // d0
  double v80; // d1
  double v81; // d2
  double v82; // d3
  double v83; // d4
  double v84; // d5
  double v85; // d6
  double v86; // d7
  unsigned int v87; // w21
  __int64 v88; // x8
  __int64 v89; // x0
  unsigned int v90; // w0
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // [xsp+0h] [xbp-60h] BYREF
  __int64 v100; // [xsp+8h] [xbp-58h] BYREF
  __int64 v101; // [xsp+10h] [xbp-50h] BYREF
  __int64 v102; // [xsp+18h] [xbp-48h]
  __int64 v103; // [xsp+20h] [xbp-40h]
  __int64 v104; // [xsp+28h] [xbp-38h]
  __int64 v105; // [xsp+30h] [xbp-30h]
  __int64 v106; // [xsp+38h] [xbp-28h] BYREF
  __int64 v107; // [xsp+40h] [xbp-20h]
  __int64 (__fastcall *v108)(); // [xsp+48h] [xbp-18h]
  __int64 v109; // [xsp+50h] [xbp-10h]
  __int64 v110; // [xsp+58h] [xbp-8h]

  v110 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v108 = nullptr;
  v109 = 0;
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v102 = 0;
  v103 = 0;
  v100 = 0;
  v101 = 0;
  qdf_trace_msg(
    0x48u,
    8u,
    "%s: Enter",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_cfg80211_mc_twt_clear_infra_cp_stats",
    0);
  v22 = *(_QWORD *)(a1 + 152);
  if ( v22 )
  {
    v23 = *(_QWORD *)(v22 + 80);
    if ( v23 )
    {
      if ( !(unsigned int)wlan_cp_stats_infra_cp_get_context(
                            *(_QWORD *)(v22 + 80),
                            &v100,
                            &v99,
                            v14,
                            v15,
                            v16,
                            v17,
                            v18,
                            v19,
                            v20,
                            v21) )
      {
        if ( v100 )
        {
          v33 = -22;
          v34 = "%s: another request already in progress";
        }
        else
        {
          v35 = osif_request_alloc(&wlan_cfg80211_mc_twt_clear_infra_cp_stats_params);
          if ( !v35 )
          {
            result = 4294967284LL;
            goto LABEL_5;
          }
          v36 = v35;
          v37 = osif_request_cookie(v35);
          v38 = osif_request_priv(v36);
          v39 = _qdf_mem_malloc(0x38u, "wlan_cfg80211_mc_twt_clear_infra_cp_stats", 1035);
          *(_QWORD *)(v38 + 16) = v39;
          if ( v39 )
          {
            v40 = *(unsigned __int8 *)(a1 + 104);
            HIDWORD(v103) = 0;
            v101 = 0x100000003LL;
            v102 = v37;
            v108 = infra_cp_stats_reset_cb;
            HIDWORD(v104) = 1;
            v105 = v40 | 0x100000000LL;
            qdf_mem_copy(&v106, a3, 6u);
            LODWORD(v107) = a2;
            HIDWORD(v103) = 0;
            bsspeer = wlan_objmgr_vdev_try_get_bsspeer(a1, 0x26u);
            if ( bsspeer )
            {
              wlan_objmgr_peer_release_ref(bsspeer, 0x26u, v42, v43, v44, v45, v46, v47, v48, v49);
              v58 = ucfg_infra_cp_stats_register_resp_cb(v23, (__int64)&v101, v50, v51, v52, v53, v54, v55, v56, v57);
              if ( v58 )
              {
                v67 = v58;
                qdf_trace_msg(
                  0x48u,
                  2u,
                  "%s: Failed to register resp callback: %d",
                  v59,
                  v60,
                  v61,
                  v62,
                  v63,
                  v64,
                  v65,
                  v66,
                  "wlan_cfg80211_mc_twt_clear_infra_cp_stats",
                  v58);
                v33 = qdf_status_to_os_return(v67);
              }
              else
              {
                v68 = ucfg_send_infra_cp_stats_request(a1, v59, v60, v61, v62, v63, v64, v65, v66);
                if ( v68 )
                {
                  v77 = v68;
                  qdf_trace_msg(
                    0x48u,
                    2u,
                    "%s: Failed to send twt stats request status: %d",
                    v69,
                    v70,
                    v71,
                    v72,
                    v73,
                    v74,
                    v75,
                    v76,
                    "wlan_cfg80211_mc_twt_clear_infra_cp_stats",
                    v68);
                  v78 = qdf_status_to_os_return(v77);
                }
                else
                {
                  v78 = osif_request_wait_for_response(v36);
                  if ( v78 )
                  {
                    v87 = v78;
                    qdf_trace_msg(
                      0x48u,
                      2u,
                      "%s: wait failed or timed out ret: %d",
                      v79,
                      v80,
                      v81,
                      v82,
                      v83,
                      v84,
                      v85,
                      v86,
                      "wlan_cfg80211_mc_twt_clear_infra_cp_stats",
                      v78);
                    v78 = v87;
                  }
                }
                v88 = *(_QWORD *)(a1 + 152);
                v33 = v78;
                if ( v88 )
                  v89 = *(_QWORD *)(v88 + 80);
                else
                  v89 = 0;
                v90 = ucfg_infra_cp_stats_deregister_resp_cb(v89, v79, v80, v81, v82, v83, v84, v85, v86);
                if ( v90 )
                  qdf_trace_msg(
                    0x33u,
                    2u,
                    "%s: Failed to deregister resp callback: %d",
                    v91,
                    v92,
                    v93,
                    v94,
                    v95,
                    v96,
                    v97,
                    v98,
                    "wlan_cfg80211_mc_twt_clear_infra_cp_stats",
                    v90);
              }
            }
            else
            {
              qdf_trace_msg(
                0x48u,
                2u,
                "%s: peer is null",
                v42,
                v43,
                v44,
                v45,
                v46,
                v47,
                v48,
                v49,
                "wlan_cfg80211_mc_twt_clear_infra_cp_stats");
              v33 = -22;
            }
          }
          else
          {
            v33 = -12;
          }
          osif_request_put(v36);
          v34 = "%s: Exit";
        }
        qdf_trace_msg(
          0x48u,
          8u,
          v34,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          "wlan_cfg80211_mc_twt_clear_infra_cp_stats");
        result = v33;
        goto LABEL_5;
      }
    }
  }
  result = 4294967274LL;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}

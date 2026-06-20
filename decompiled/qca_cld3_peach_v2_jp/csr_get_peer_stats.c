__int64 __fastcall csr_get_peer_stats(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v5; // x0
  __int64 psoc_ext_obj_fl; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x22
  __int64 v16; // x0
  __int64 v17; // x9
  int v18; // w10
  int v19; // w8
  __int64 v20; // x21
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w0
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  unsigned int *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 result; // x0
  double rx_retry_cnt; // d0
  unsigned int *v49; // x8
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  int v57; // [xsp+0h] [xbp-40h]
  __int64 v58; // [xsp+8h] [xbp-38h]
  _QWORD v59[2]; // [xsp+10h] [xbp-30h] BYREF
  int v60; // [xsp+20h] [xbp-20h]
  int v61; // [xsp+24h] [xbp-1Ch]
  __int64 v62; // [xsp+28h] [xbp-18h] BYREF
  int v63; // [xsp+30h] [xbp-10h] BYREF
  __int16 v64; // [xsp+34h] [xbp-Ch]
  __int64 v65; // [xsp+38h] [xbp-8h]

  v65 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 21552);
  v63 = a3;
  v64 = WORD2(a3);
  v62 = 0;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(v5);
  if ( psoc_ext_obj_fl )
  {
    *(_DWORD *)(psoc_ext_obj_fl + 7436) = 0;
    v15 = psoc_ext_obj_fl;
    v16 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            *(_QWORD *)(a1 + 21552),
            a2,
            11);
    if ( v16 )
    {
      v17 = *(_QWORD *)(v16 + 152);
      v18 = *(unsigned __int8 *)(v16 + 104);
      v59[0] = a1;
      v59[1] = csr_get_peer_stats_cb;
      v19 = *(unsigned __int8 *)(v17 + 40);
      v20 = v16;
      v60 = v18;
      v61 = v19;
      qdf_mem_copy(&v62, &v63, 6u);
      v57 = HIBYTE(v64);
      qdf_trace_msg(
        0x34u,
        8u,
        "%s: vdev %d peer_mac %02x:%02x:%02x:**:**:%02x",
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        "csr_get_peer_stats",
        a2,
        (unsigned __int8)v63,
        BYTE1(v63),
        BYTE2(v63),
        v57,
        v58,
        a1,
        csr_get_peer_stats_cb);
      *(_BYTE *)(v15 + 7432) = v60;
      v29 = ucfg_mc_cp_stats_send_stats_request(v20, 2, v59);
      if ( !v29 )
      {
        qdf_mc_timer_start(v15 + 7440, 0xC8u);
        rx_retry_cnt = wma_get_rx_retry_cnt(a1, a2, &v62);
        result = wlan_objmgr_vdev_release_ref(v20, 0xBu, v49, rx_retry_cnt, v50, v51, v52, v53, v54, v55, v56);
        goto LABEL_8;
      }
      qdf_trace_msg(
        0x34u,
        2u,
        "%s: stats req failed: %d",
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        "csr_get_peer_stats",
        v29);
      wlan_objmgr_vdev_release_ref(v20, 0xBu, v38, v39, v40, v41, v42, v43, v44, v45, v46);
    }
    result = csr_continue_peer_disconnect_after_get_stats(a1);
  }
  else
  {
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: NULL mlme psoc object",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "csr_get_peer_stats");
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}

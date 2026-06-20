__int64 __fastcall lim_process_probe_rsp_frame(
        __int64 a1,
        unsigned int *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v14; // x0
  __int64 v15; // x19
  _BYTE *v16; // x23
  __int64 v17; // x1
  __int64 v18; // x4
  __int64 result; // x0
  const char *v20; // x2
  unsigned int v21; // w24
  __int64 v22; // x25
  int v23; // w4
  unsigned int v24; // w5
  __int64 v25; // x0
  bool v26; // zf
  __int64 v27; // x8
  unsigned int v28; // w0
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  __int64 ap_link_by_link_id; // x0
  _WORD *v38; // x8
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  char v47; // w24
  int v48; // w8
  __int64 v49; // x0
  size_t v50; // x0
  void *v51; // x0
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x3
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  int v69; // w9
  double v70; // d0
  double v71; // d1
  double v72; // d2
  double v73; // d3
  double v74; // d4
  double v75; // d5
  double v76; // d6
  double v77; // d7
  double v78; // d0
  double v79; // d1
  double v80; // d2
  double v81; // d3
  double v82; // d4
  double v83; // d5
  double v84; // d6
  double v85; // d7
  int v86; // w1
  double v87; // d0
  double v88; // d1
  double v89; // d2
  double v90; // d3
  double v91; // d4
  double v92; // d5
  double v93; // d6
  double v94; // d7
  char v95[4]; // [xsp+2Ch] [xbp-24h] BYREF
  _DWORD v96[2]; // [xsp+30h] [xbp-20h] BYREF
  int v97; // [xsp+38h] [xbp-18h] BYREF
  unsigned __int16 v98; // [xsp+3Ch] [xbp-14h]
  __int64 v99; // [xsp+48h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v96, 0, 6);
  v95[0] = 0;
  if ( !a3 )
  {
    v20 = "%s: session_entry is NULL";
LABEL_10:
    result = qdf_trace_msg(0x35u, 2u, v20, a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_probe_rsp_frame");
    goto LABEL_11;
  }
  v14 = _qdf_mem_malloc(0x1A08u, "lim_process_probe_rsp_frame", 349);
  if ( !v14 )
  {
    v20 = "%s: Unable to allocate memory";
    goto LABEL_10;
  }
  *(_BYTE *)(v14 + 12) = 0;
  v15 = v14;
  *(_BYTE *)(v14 + 620) = 0;
  v16 = *((_BYTE **)a2 + 2);
  *(_BYTE *)(a1 + 12208) = a2[2];
  if ( a2[10] >= 0xE )
  {
    v17 = *((_QWORD *)a2 + 3);
    v97 = 0;
    if ( !(unsigned int)sir_validate_and_rectify_ies(a1, v17) )
    {
      v21 = a2[10];
      v22 = *((_QWORD *)a2 + 3);
      a2[8] += v97;
      if ( (unsigned int)sir_convert_probe_frame2_struct(a1, v22, v21, v15) == 16 || !*(_BYTE *)(v15 + 2460) )
      {
        v18 = v21;
        goto LABEL_6;
      }
      v23 = *(_DWORD *)(v15 + 72);
      v24 = *a2;
      if ( !v23
        || v23 != v24
        && (qdf_trace_msg(
              0x35u,
              8u,
              "%s: mismatch freq %d rx %d op %d",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "lim_process_probe_rsp_frame"),
            v24 = *a2,
            *a2 == *(_DWORD *)(a3 + 284)) )
      {
        *(_DWORD *)(v15 + 72) = v24;
      }
      if ( *(_BYTE *)(v15 + 3437) == 1 )
      {
        v25 = *(_QWORD *)(a3 + 16);
        v98 = 0;
        v97 = 0;
        if ( (wlan_vdev_mlme_is_mlo_vdev(v25, a4, a5, a6, a7, a8, a9, a10, a11) & 1) != 0 )
        {
          if ( (unsigned int)wlan_vdev_get_bss_peer_mld_mac(
                               *(_QWORD *)(a3 + 16),
                               &v97,
                               a4,
                               a5,
                               a6,
                               a7,
                               a8,
                               a9,
                               a10,
                               a11) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: Failed to fetch MLD address for ML VDEV",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "lim_validate_probe_rsp_mld_addr");
            goto LABEL_7;
          }
          if ( !(*(_DWORD *)(v15 + 3441) | *(unsigned __int16 *)(v15 + 3445))
            || (*(_DWORD *)(v15 + 3441) == v97 ? (v26 = *(unsigned __int16 *)(v15 + 3445) == v98) : (v26 = 0), !v26) )
          {
            qdf_trace_msg(
              0x35u,
              2u,
              "%s: prb rsp MLD %02x:%02x:%02x:**:**:%02x, bss peer MLD %02x:%02x:%02x:**:**:%02x",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              "lim_validate_probe_rsp_mld_addr",
              *(unsigned __int8 *)(v15 + 3441),
              *(unsigned __int8 *)(v15 + 3442),
              *(unsigned __int8 *)(v15 + 3443),
              *(unsigned __int8 *)(v15 + 3446),
              (unsigned __int8)v97,
              BYTE1(v97),
              BYTE2(v97),
              HIBYTE(v98));
            goto LABEL_7;
          }
        }
      }
      v27 = *(_QWORD *)(a3 + 112);
      if ( v27 && *(_BYTE *)(v27 + 4545) == 1 )
      {
        v28 = lim_add_bcn_probe(
                *(_QWORD *)(a1 + 21632),
                v16,
                a2[8],
                0,
                *(_DWORD *)(v15 + 72),
                *(char *)(a1 + 12208),
                *((_BYTE *)a2 + 4),
                a2[12]);
        if ( v28 )
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: failed to add assoc link probe rsp %d freq %d",
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            "lim_update_mlo_mgr_prb_info",
            v28,
            *(unsigned int *)(v15 + 72));
        lim_update_mlo_mgr_info(
          a1,
          *(_QWORD *)(a3 + 16),
          v16 + 16,
          *(unsigned __int8 *)(*(_QWORD *)(a3 + 112) + 4544LL),
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          v36);
        ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(
                               *(_QWORD *)(*(_QWORD *)(a3 + 16) + 1360LL),
                               *(unsigned __int8 *)(*(_QWORD *)(a3 + 112) + 4544LL));
        if ( ap_link_by_link_id )
        {
          v38 = *(_WORD **)(ap_link_by_link_id + 32);
          if ( v38 && *v38 )
            goto LABEL_36;
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: fail to update ch freq for link id %d, freq %d",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "lim_update_mlo_mgr_prb_info",
            *(unsigned __int8 *)(*(_QWORD *)(a3 + 112) + 4544LL),
            *(unsigned int *)(v15 + 72));
        }
        else
        {
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: fail to get link info for link id %d",
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10,
            a11,
            "lim_update_mlo_mgr_prb_info",
            *(unsigned __int8 *)(*(_QWORD *)(a3 + 112) + 4544LL));
        }
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: fail to update mlo info status %d rx freq %d prb freq %d op freq %d",
          v87,
          v88,
          v89,
          v90,
          v91,
          v92,
          v93,
          v94,
          "lim_process_probe_rsp_frame",
          4,
          *a2,
          *(unsigned int *)(v15 + 72),
          *(unsigned int *)(a3 + 284));
        goto LABEL_7;
      }
LABEL_36:
      lim_process_bcn_prb_rsp_t2lm(a1, a3, (char *)v15, a4, a5, a6, a7, a8, a9, a10, a11);
      lim_gen_link_specific_probe_rsp(
        a1,
        a3,
        v15,
        v22,
        v21,
        *(char *)(a1 + 12208),
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46);
      if ( (mlo_is_mld_sta(*(_QWORD *)(a3 + 16)) & 1) != 0 )
      {
        if ( (unsigned int)lim_get_bpcc_from_mlo_ie(v15, v95) )
          v47 = 0;
        else
          v47 = lim_check_cu_happens(
                  *(_QWORD *)(a3 + 16),
                  *(unsigned __int8 *)(*(_QWORD *)(a3 + 16) + 93LL),
                  (unsigned __int8)v95[0]);
        ((void (__fastcall *)(__int64, __int64, unsigned int *))lim_process_cu_for_probe_rsp)(a1, a3, a2);
      }
      else
      {
        v47 = 1;
      }
      v48 = *(_DWORD *)(a3 + 72);
      if ( v48 == 14 )
      {
        v69 = *(_DWORD *)(a3 + 26);
        LOWORD(v96[0]) = *(_WORD *)(a3 + 24);
        *(_DWORD *)((char *)v96 + 2) = v69;
        if ( !(unsigned int)qdf_mem_cmp(v96, v16 + 16, 6u) )
        {
          if ( !*(_BYTE *)(a3 + 292) )
          {
            qdf_trace_msg(
              0x35u,
              3u,
              "%s: Recved Probe Resp from AP,AP-alive",
              v70,
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              "lim_process_probe_rsp_frame");
            if ( *(_BYTE *)(v15 + 1260) )
              v86 = wlan_reg_legacy_chan_to_freq(
                      *(_QWORD *)(a1 + 21632),
                      *(unsigned __int8 *)(v15 + 1261),
                      v78,
                      v79,
                      v80,
                      v81,
                      v82,
                      v83,
                      v84,
                      v85);
            else
              v86 = *(_DWORD *)(v15 + 72);
            lim_received_hb_handler(a1, v86, a3);
          }
          if ( (v47 & 1) != 0 )
            lim_process_updated_ies_in_probe_rsp(a1, a3, (_BYTE *)v15);
        }
      }
      else if ( v48 == 2 )
      {
        v49 = *(_QWORD *)(a3 + 320);
        if ( v49 )
        {
          _qdf_mem_free(v49);
          *(_QWORD *)(a3 + 320) = 0;
          *(_DWORD *)(a3 + 312) = 0;
        }
        v50 = a2[8];
        *(_DWORD *)(a3 + 312) = v50;
        v51 = (void *)_qdf_mem_malloc(v50, "lim_process_probe_rsp_frame", 448);
        *(_QWORD *)(a3 + 320) = v51;
        if ( v51 )
          qdf_mem_copy(v51, *((const void **)a2 + 2), *(unsigned int *)(a3 + 312));
        else
          qdf_trace_msg(
            0x35u,
            2u,
            "%s: No Memory to store beacon",
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            "lim_process_probe_rsp_frame");
        mgmt_txrx_frame_hex_dump((__int64)v16, a2[8], 0, v60, v61, v62, v63, v64, v65, v66, v67, v68);
        lim_check_and_announce_join_success(a1, v15, (__int16 *)v16, a3);
      }
      goto LABEL_7;
    }
  }
  v18 = 0;
LABEL_6:
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Parse error ProbeResponse, length=%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_process_probe_rsp_frame",
    v18);
LABEL_7:
  result = _qdf_mem_free(v15);
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall wma_pasn_peer_create(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned int a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 *context; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 *v25; // x19
  __int64 tgt_res_cfg; // x0
  __int64 objmgr_peer; // x0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  __int64 v36; // x25
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  const char *v53; // x2
  __int64 result; // x0
  void *v55; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  __int64 v64; // x24
  double v65; // d0
  double v66; // d1
  double v67; // d2
  double v68; // d3
  double v69; // d4
  double v70; // d5
  double v71; // d6
  double v72; // d7
  __int64 v73; // x4
  __int64 v74; // x5
  __int64 v75; // x6
  __int64 v76; // x7
  double v77; // d0
  double v78; // d1
  double v79; // d2
  double v80; // d3
  double v81; // d4
  double v82; // d5
  double v83; // d6
  double v84; // d7
  double v85; // d0
  double v86; // d1
  double v87; // d2
  double v88; // d3
  double v89; // d4
  double v90; // d5
  double v91; // d6
  double v92; // d7
  __int64 v93; // x0
  double v94; // d0
  double v95; // d1
  double v96; // d2
  double v97; // d3
  double v98; // d4
  double v99; // d5
  double v100; // d6
  double v101; // d7
  __int64 v102; // [xsp+10h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  context = _cds_get_context(54, (__int64)"wma_pasn_peer_create", a5, a6, a7, a8, a9, a10, a11, a12);
  if ( context )
  {
    v25 = context;
    tgt_res_cfg = lmac_get_tgt_res_cfg(a1, v17, v18, v19, v20, v21, v22, v23, v24);
    if ( tgt_res_cfg )
    {
      if ( *(_DWORD *)(v25[65] + 488LL * (unsigned __int8)a3 + 244) >= *(_DWORD *)(tgt_res_cfg + 4) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: the peer count exceeds the limit %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wma_pasn_peer_create");
      }
      else if ( (*a2 & 1) != 0 || !(*(_DWORD *)a2 | *((unsigned __int16 *)a2 + 2)) )
      {
        qdf_trace_msg(
          0x36u,
          2u,
          "%s: Invalid peer address received reject it",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wma_pasn_peer_create");
      }
      else
      {
        wma_acquire_wakelock((__int64)(v25 + 391), 0x1F40u, v17, v18, v19, v20, v21, v22, v23, v24);
        objmgr_peer = wma_create_objmgr_peer((__int64)v25, a3, a2, 6, nullptr);
        if ( objmgr_peer )
        {
          v36 = objmgr_peer;
          LODWORD(v102) = 6;
          if ( !(unsigned int)wmi_unified_peer_create_send(*v25) )
          {
            if ( (*(_BYTE *)(v25[3] + 23) & 0x10) != 0 )
            {
              v55 = (void *)_qdf_mem_malloc(6u, "wma_pasn_peer_create", 237);
              if ( !v55 )
              {
                wlan_objmgr_peer_obj_delete(v36, v56, v57, v58, v59, v60, v61, v62, v63);
                wma_release_wakelock((__int64)(v25 + 391), v77, v78, v79, v80, v81, v82, v83, v84);
                result = 2;
                goto LABEL_16;
              }
              v64 = (__int64)v55;
              qdf_mem_copy(v55, a2, 6u);
              if ( !wma_fill_hold_req(v25, a3, 0x11C5u, a4, a2, v64, 0x1F40u) )
              {
                qdf_trace_msg(
                  0x36u,
                  2u,
                  "%s: vdev:%d failed to fill peer create req",
                  v65,
                  v66,
                  v67,
                  v68,
                  v69,
                  v70,
                  v71,
                  v72,
                  "wma_pasn_peer_create",
                  (unsigned __int8)a3);
                v93 = wma_remove_peer_req((__int64)v25, a3, a4, (__int64)a2, v85, v86, v87, v88, v89, v90, v91, v92);
                if ( a4 == 12 )
                {
                  wma_nan_pasn_peer_remove(v94, v95, v96, v97, v98, v99, v100, v101, v93, a3, a2, 0xDu, 0);
                }
                else if ( a4 == 10 )
                {
                  wma_pasn_peer_remove(v94, v95, v96, v97, v98, v99, v100, v101, v93, a2, a3, 0);
                }
                wma_release_wakelock((__int64)(v25 + 391), v94, v95, v96, v97, v98, v99, v100, v101);
                _qdf_mem_free(v64);
                goto LABEL_15;
              }
              if ( a2 )
              {
                v73 = *a2;
                v74 = a2[1];
                v75 = a2[2];
                v76 = a2[5];
              }
              else
              {
                v75 = 0;
                v73 = 0;
                v74 = 0;
                v76 = 0;
              }
              HIDWORD(v102) = (unsigned __int8)a3;
              qdf_trace_msg(
                0x36u,
                8u,
                "%s: Created PASN peer peer_addr %02x:%02x:%02x:**:**:%02x vdev_id %d",
                v65,
                v66,
                v67,
                v68,
                v69,
                v70,
                v71,
                v72,
                "wma_pasn_peer_create",
                v73,
                v74,
                v75,
                v76,
                (unsigned __int8)a3,
                a2,
                v102,
                0);
            }
            else
            {
              wma_release_wakelock((__int64)(v25 + 391), v37, v38, v39, v40, v41, v42, v43, v44);
            }
            result = 0;
            goto LABEL_16;
          }
          qdf_trace_msg(
            0x36u,
            2u,
            "%s: Unable to create peer in Target",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "wma_pasn_peer_create");
          wlan_objmgr_peer_obj_delete(v36, v45, v46, v47, v48, v49, v50, v51, v52);
        }
        wma_release_wakelock((__int64)(v25 + 391), v28, v29, v30, v31, v32, v33, v34, v35);
      }
LABEL_15:
      result = 16;
      goto LABEL_16;
    }
    v53 = "%s: psoc target res cfg is null";
  }
  else
  {
    v53 = "%s: wma_handle is NULL";
  }
  qdf_trace_msg(0x36u, 2u, v53, v17, v18, v19, v20, v21, v22, v23, v24, "wma_pasn_peer_create");
  result = 4;
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}

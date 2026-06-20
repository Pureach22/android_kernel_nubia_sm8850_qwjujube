__int64 __fastcall tdls_process_rx_frame(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x24
  __int64 v11; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x20
  __int64 *comp_private_obj; // x0
  unsigned int *v22; // x8
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _QWORD *v31; // x23
  unsigned int *v32; // x21
  __int64 *v33; // x25
  __int64 v34; // x26
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w4
  __int64 v44; // x5
  __int64 v45; // x6
  __int64 v46; // x7
  int v47; // w8
  unsigned int v48; // w21
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  void (__fastcall *v57)(__int64, unsigned int *); // x8
  __int64 v58; // x0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  void (__fastcall *v75)(__int64, unsigned int *); // x8
  __int64 v76; // x0
  __int64 v78; // [xsp+0h] [xbp-20h]
  __int64 v79; // [xsp+8h] [xbp-18h]

  v9 = *(_QWORD *)(a1 + 8);
  if ( v9 )
  {
    v11 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
            **(_QWORD **)v9,
            *(unsigned int *)(*(_QWORD *)(v9 + 8) + 8LL),
            17);
    if ( v11 )
    {
      v20 = v11;
      qdf_trace_msg(
        0,
        8u,
        "%s: vdev:%d tdls rx mgmt frame received",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "tdls_process_rx_frame",
        *(unsigned __int8 *)(v11 + 104));
      comp_private_obj = (__int64 *)wlan_objmgr_vdev_get_comp_private_obj(v20, 0xAu);
      if ( comp_private_obj )
      {
        v31 = *(_QWORD **)v9;
        if ( *(_QWORD *)v9 && (v32 = *(unsigned int **)(v9 + 8)) != nullptr )
        {
          v33 = comp_private_obj;
          v34 = *comp_private_obj;
          qdf_trace_msg(
            0,
            8u,
            "%s: soc:%pK, frame_len:%d, rx_freq:%d, vdev_id:%d, frm_type:%d, rx_rssi:%d, buf:%pK",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "tdls_process_rx_mgmt",
            *v31,
            *v32,
            v32[1],
            v32[2],
            v32[3],
            v32[4],
            v32 + 5);
          v43 = *((unsigned __int8 *)v32 + 45);
          if ( v43 == 14 )
          {
            if ( v32 == (unsigned int *)-30LL )
            {
              v46 = 0;
              v44 = 0;
              v45 = 0;
              v47 = 0;
            }
            else
            {
              v44 = *((unsigned __int8 *)v32 + 30);
              v45 = *((unsigned __int8 *)v32 + 31);
              v46 = *((unsigned __int8 *)v32 + 32);
              v47 = *((unsigned __int8 *)v32 + 35);
            }
            LODWORD(v79) = v32[4];
            LODWORD(v78) = v47;
            qdf_trace_msg(
              0,
              4u,
              "%s: [TDLS] vdev:%d TDLS Discovery Response,%02x:%02x:%02x:**:**:%02x RSSI[%d] <--- OTA",
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              v42,
              "tdls_process_rx_mgmt",
              *(unsigned __int8 *)(v34 + 104),
              v44,
              v45,
              v46,
              v78,
              v79);
            v57 = (void (__fastcall *)(__int64, unsigned int *))v31[29];
            if ( v57 )
            {
              v58 = v31[30];
              if ( *((_DWORD *)v57 - 1) != -2109187 )
                __break(0x8228u);
              v57(v58, v32);
            }
            else
            {
              qdf_trace_msg(
                0,
                8u,
                "%s: rx mgmt, but no valid up layer callback",
                v49,
                v50,
                v51,
                v52,
                v53,
                v54,
                v55,
                v56,
                "tdls_process_rx_mgmt");
            }
            tdls_recv_discovery_resp(v33, (char *)v32 + 30, v59, v60, v61, v62, v63, v64, v65, v66);
            tdls_set_rssi(*v33, (unsigned __int8 *)v32 + 30, v32[4], v67, v68, v69, v70, v71, v72, v73, v74);
          }
          else
          {
            if ( *((_BYTE *)v32 + 44) == 12 )
            {
              if ( v43 < 0xB )
                qdf_trace_msg(
                  0,
                  4u,
                  "%s: [TDLS] %s <--- OTA",
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  "tdls_process_rx_mgmt",
                  tdls_action_frames_type[*((unsigned __int8 *)v32 + 45)]);
              else
                qdf_trace_msg(
                  0,
                  8u,
                  "%s: [TDLS] unknown[%d] <--- OTA",
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  v42,
                  "tdls_process_rx_mgmt");
            }
            v75 = (void (__fastcall *)(__int64, unsigned int *))v31[29];
            if ( v75 )
            {
              v76 = v31[30];
              if ( *((_DWORD *)v75 - 1) != -2109187 )
                __break(0x8228u);
              v75(v76, v32);
            }
            else
            {
              qdf_trace_msg(
                0,
                8u,
                "%s: rx mgmt, but no valid up layer callback",
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                v42,
                "tdls_process_rx_mgmt");
            }
          }
          v48 = 0;
        }
        else
        {
          qdf_trace_msg(
            0,
            2u,
            "%s: invalid psoc object or rx mgmt",
            v23,
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            "tdls_process_rx_mgmt");
          v48 = 4;
        }
      }
      else
      {
        v48 = 16;
      }
      wlan_objmgr_vdev_release_ref(v20, 0x11u, v22, v23, v24, v25, v26, v27, v28, v29, v30);
    }
    else
    {
      v48 = 16;
    }
    _qdf_mem_free(*(_QWORD *)(v9 + 8));
    _qdf_mem_free(*(_QWORD *)(a1 + 8));
    *(_QWORD *)(a1 + 8) = 0;
  }
  else
  {
    qdf_trace_msg(0, 2u, "%s: invalid message body", a2, a3, a4, a5, a6, a7, a8, a9, "tdls_process_rx_frame");
    return 4;
  }
  return v48;
}

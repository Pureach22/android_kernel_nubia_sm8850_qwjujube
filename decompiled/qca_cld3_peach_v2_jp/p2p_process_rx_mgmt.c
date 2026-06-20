__int64 __fastcall p2p_process_rx_mgmt(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int8 *v9; // x19
  __int64 v10; // x20
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x4
  __int64 v29; // x24
  unsigned int v30; // w25
  const char *v31; // x4
  unsigned int v32; // w20
  int v33; // w8
  unsigned int v34; // w23
  __int64 v35; // x22
  __int64 v36; // x22
  __int64 v37; // x22
  const char *v38; // x2
  __int64 current_roc_ctx; // x0
  unsigned int v40; // w22
  __int64 v41; // x23
  unsigned int v42; // w8
  __int64 v43; // x9
  void (__fastcall *v44)(__int64, unsigned __int8 *); // x8
  __int64 v45; // x0
  __int64 v47; // [xsp+0h] [xbp-30h]
  __int64 v48; // [xsp+18h] [xbp-18h] BYREF
  __int64 v49; // [xsp+20h] [xbp-10h]
  __int64 v50; // [xsp+28h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *a1;
  v9 = (unsigned __int8 *)a1[1];
  v48 = 0;
  v49 = 0;
  if ( v10 && *(_QWORD *)(v10 + 88) )
  {
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: soc:%pK, frame_len:%d, rx_freq:%d, vdev_id:%d, frm_type:%d, rx_rssi:%d, buf:%pK",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "p2p_process_rx_mgmt",
      *(_QWORD *)v10,
      *(unsigned int *)v9,
      *((unsigned int *)v9 + 1),
      *((unsigned int *)v9 + 2),
      *((_DWORD *)v9 + 3),
      *((_DWORD *)v9 + 4),
      v9 + 20);
    v19 = *((_DWORD *)v9 + 3);
    if ( v19 != 31 )
    {
LABEL_50:
      if ( v19 == 28 )
        p2p_get_frame_info(v9 + 20, *(_DWORD *)v9, (__int64)&v48, v11, v12, v13, v14, v15, v16, v17, v18);
      v43 = *(_QWORD *)(v10 + 88);
      v44 = *(void (__fastcall **)(__int64, unsigned __int8 *))v43;
      if ( *(_QWORD *)v43 )
      {
        v45 = *(_QWORD *)(v43 + 8);
        if ( *((_DWORD *)v44 - 1) != -590873904 )
          __break(0x8228u);
        v44(v45, v9);
        goto LABEL_58;
      }
      v38 = "%s: rx mgmt, but no valid up layer callback";
      goto LABEL_57;
    }
    p2p_get_frame_info(v9 + 20, *(_DWORD *)v9, (__int64)&v48, v11, v12, v13, v14, v15, v16, v17, v18);
    if ( v9 == (unsigned __int8 *)-30LL )
    {
      qdf_trace_msg(
        0x4Eu,
        2u,
        "%s: invalid p2p_soc_obj:%pK or rx_frame_info:%pK, mac_from:%pK",
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        "p2p_rx_update_connection_status",
        v10,
        &v48,
        0);
      v28 = (unsigned int)v49;
    }
    else
    {
      v28 = (unsigned int)v49;
      if ( (_DWORD)v49 != 17 )
      {
        v29 = jiffies;
        if ( p2p_rx_update_connection_status___last_ticks - jiffies + 125 < 0 )
        {
          if ( (_DWORD)v48 == 1 )
          {
            v30 = v49;
            v31 = "Not support frame";
          }
          else if ( HIDWORD(v48) == 14 )
          {
            v30 = v49;
            v31 = "Not support sub frame";
          }
          else if ( HIDWORD(v49) == 1 )
          {
            v30 = v49;
            v31 = "P2P action presence request";
          }
          else if ( HIDWORD(v49) == 2 )
          {
            v30 = v49;
            v31 = "P2P action presence response";
          }
          else
          {
            v30 = v49;
            if ( (unsigned int)v49 > 0x10 )
              v31 = "Other frame";
            else
              v31 = off_9FDC68[(unsigned int)v49];
          }
          LODWORD(v47) = v9[35];
          qdf_trace_msg(
            0x4Eu,
            4u,
            "%s: %s <--- OTA from %02x:%02x:%02x:**:**:%02x",
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            "p2p_rx_update_connection_status",
            v31,
            v9[30],
            v9[31],
            v9[32],
            v47);
          v28 = v30;
          p2p_rx_update_connection_status___last_ticks = v29;
        }
        if ( (unsigned int)v28 <= 7 )
        {
          if ( ((1 << v28) & 0x83) != 0 )
          {
            v34 = v28;
            p2p_status_update(v10, 1);
            v36 = jiffies;
            if ( p2p_rx_update_connection_status___last_ticks_169 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x4Eu,
                4u,
                "%s: [P2P State]Inactive state to GO negotiation progress state",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                "p2p_rx_update_connection_status");
              p2p_rx_update_connection_status___last_ticks_169 = v36;
              v28 = v34;
              goto LABEL_37;
            }
            goto LABEL_28;
          }
          if ( ((1 << v28) & 0x14) != 0 )
          {
            v33 = *(_DWORD *)(v10 + 276);
            if ( v33 == 1 )
            {
              v34 = v28;
              p2p_status_update(v10, 2);
              v35 = jiffies;
              if ( p2p_rx_update_connection_status___last_ticks_170 - jiffies + 125 < 0 )
              {
                qdf_trace_msg(
                  0x4Eu,
                  4u,
                  "%s: [P2P State]GO negotiation progress to GO negotiation completed state",
                  v20,
                  v21,
                  v22,
                  v23,
                  v24,
                  v25,
                  v26,
                  v27,
                  "p2p_rx_update_connection_status");
                p2p_rx_update_connection_status___last_ticks_170 = v35;
                v28 = v34;
                goto LABEL_37;
              }
LABEL_28:
              v28 = v34;
              goto LABEL_37;
            }
            if ( (_DWORD)v28 != 3 )
              goto LABEL_37;
          }
          else
          {
            if ( (_DWORD)v28 != 3 )
              goto LABEL_37;
            v33 = *(_DWORD *)(v10 + 276);
          }
          if ( !v33 )
          {
            p2p_status_update(v10, 2);
            v37 = jiffies;
            if ( p2p_rx_update_connection_status___last_ticks_172 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x4Eu,
                4u,
                "%s: [P2P State]Inactive state to GO negotiation completed state Autonomous GO formation",
                v20,
                v21,
                v22,
                v23,
                v24,
                v25,
                v26,
                v27,
                "p2p_rx_update_connection_status");
              p2p_rx_update_connection_status___last_ticks_172 = v37;
            }
          }
          v28 = 3;
        }
      }
    }
LABEL_37:
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: action_sub_type %u, action_type %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "p2p_process_rx_mgmt",
      v28,
      HIDWORD(v49));
    if ( (_DWORD)v49 == 17 && HIDWORD(v49) == 3 )
    {
      v38 = "%s: non-p2p frame, drop it";
LABEL_57:
      qdf_trace_msg(0x4Eu, 8u, v38, v11, v12, v13, v14, v15, v16, v17, v18, "p2p_process_rx_mgmt");
LABEL_58:
      v32 = 0;
      goto LABEL_59;
    }
    qdf_trace_msg(
      0x4Eu,
      8u,
      "%s: p2p frame, extend roc accordingly",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "p2p_process_rx_mgmt");
    current_roc_ctx = p2p_find_current_roc_ctx(v10);
    if ( current_roc_ctx )
    {
      if ( (unsigned int)v49 > 5 || ((0x2Bu >> v49) & 1) == 0 )
      {
LABEL_49:
        v19 = *((_DWORD *)v9 + 3);
        goto LABEL_50;
      }
      v40 = dword_9FDCF0[(unsigned int)v49];
      v41 = current_roc_ctx;
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: extend roc timer, duration:%d",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_extend_roc_timer",
        v40);
      *(_DWORD *)(v41 + 48) = v40;
      p2p_restart_roc_timer(v41);
    }
    else
    {
      qdf_trace_msg(
        0x4Eu,
        8u,
        "%s: no running roc request currently",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "p2p_extend_roc_timer");
    }
    if ( !(_DWORD)v49 && wlan_reg_is_24ghz_ch_freq(*((_DWORD *)v9 + 1)) )
    {
      v42 = *((_DWORD *)v9 + 1) - 2412;
      if ( v42 > 0x32 || ((1LL << v42) & 0x4000002000001LL) == 0 )
      {
        qdf_trace_msg(
          0x4Eu,
          8u,
          "%s: Drop P2P Negotiation Req due to non-Social channel: %d",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "p2p_process_rx_mgmt");
        goto LABEL_58;
      }
    }
    goto LABEL_49;
  }
  qdf_trace_msg(
    0x4Eu,
    2u,
    "%s: Invalid psoc object or start parameters",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "p2p_process_rx_mgmt");
  v32 = 4;
LABEL_59:
  _qdf_mem_free((__int64)v9);
  _ReadStatusReg(SP_EL0);
  return v32;
}

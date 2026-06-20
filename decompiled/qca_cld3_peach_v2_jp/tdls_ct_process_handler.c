__int64 __fastcall tdls_ct_process_handler(__int64 a1)
{
  __int64 result; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x21
  unsigned int *v12; // x19
  unsigned __int64 StatusReg; // x8
  unsigned int v14; // w8
  __int64 v15; // x23
  __int64 v16; // x8
  __int64 v17; // x24
  char *v18; // x22
  __int64 peer; // x0
  int v20; // w8
  int v21; // w9
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x8
  __int64 v31; // x19
  const char *v32; // x24
  unsigned int *v33; // x27
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x1
  __int64 v43; // x25
  _QWORD *v44; // x28
  __int64 v45; // x21
  int v46; // w8
  unsigned int v47; // w8
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w8
  const char *v57; // x23
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  unsigned int v66; // w8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  unsigned int v75; // w26
  __int64 v76; // x24
  __int64 v77; // [xsp+0h] [xbp-100h]
  __int64 v78; // [xsp+8h] [xbp-F8h]
  __int64 v79; // [xsp+10h] [xbp-F0h]
  __int64 v80; // [xsp+18h] [xbp-E8h]
  __int64 v81; // [xsp+20h] [xbp-E0h]
  __int64 v82; // [xsp+28h] [xbp-D8h]
  __int64 v83; // [xsp+30h] [xbp-D0h] BYREF
  unsigned int *v84; // [xsp+38h] [xbp-C8h] BYREF
  __int64 v85; // [xsp+40h] [xbp-C0h] BYREF
  int v86; // [xsp+48h] [xbp-B8h] BYREF
  __int16 v87; // [xsp+4Ch] [xbp-B4h]
  _QWORD v88[22]; // [xsp+50h] [xbp-B0h] BYREF

  v88[20] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v84 = nullptr;
  v85 = 0;
  v83 = 0;
  result = tdls_get_vdev_objects(a1, &v84, &v83);
  if ( !(_DWORD)result )
  {
    v11 = v83;
    if ( (*((_BYTE *)&qword_D4 + v83) & 1) != 0 )
    {
      v12 = v84;
      v87 = 0;
      v86 = 0;
      memset(v88, 0, 160);
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(v83 + 352);
        v14 = *((unsigned __int8 *)v12 + 944);
        if ( *((_BYTE *)v12 + 944) )
        {
LABEL_7:
          if ( v14 >= 8 )
            v15 = 8;
          else
            v15 = v14;
          qdf_mem_copy(v88, v12 + 196, (unsigned int)(20 * v15));
          qdf_mem_set(v12 + 196, (unsigned int)(20 * v15), 0);
          *((_BYTE *)v12 + 944) = 0;
          v16 = *(__int64 *)((char *)&qword_164 + v11 + 4);
          if ( (v16 & 1) != 0 )
          {
            *(__int64 *)((char *)&qword_164 + v11 + 4) = v16 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v11 + 352);
          }
          else
          {
            raw_spin_unlock(v11 + 352);
          }
          v17 = 0;
          while ( 1 )
          {
            v18 = (char *)v88 + v17;
            qdf_mem_copy(&v86, (char *)v88 + v17, 6u);
            peer = tdls_find_peer(v12, &v86);
            if ( peer )
            {
              if ( (unsigned __int64)(v17 - 152) < 0xFFFFFFFFFFFFFF60LL
                || (*(_WORD *)(peer + 44) = *((_DWORD *)v18 + 2), (unsigned __int64)(v17 - 148) < 0xFFFFFFFFFFFFFF60LL) )
              {
LABEL_88:
                __break(1u);
              }
              *(_WORD *)(peer + 46) = *(_DWORD *)((char *)&v88[1] + v17 + 4);
            }
            else
            {
              if ( (unsigned __int64)(v17 - 152) < 0xFFFFFFFFFFFFFF60LL )
                goto LABEL_88;
              v20 = *((_DWORD *)v18 + 2);
              if ( v20 )
              {
                if ( (unsigned __int64)(v17 - 148) < 0xFFFFFFFFFFFFFF60LL )
                  goto LABEL_88;
                v21 = *(_DWORD *)((char *)&v88[1] + v17 + 4);
                if ( v21 && v21 + v20 >= v12[184] && !tdls_add_peer(v12, &v86) )
                  qdf_trace_msg(
                    0,
                    8u,
                    "%s: Unable to add peer for mac: %02x:%02x:%02x:**:**:%02x",
                    v22,
                    v23,
                    v24,
                    v25,
                    v26,
                    v27,
                    v28,
                    v29,
                    "tdls_ct_sampling_tx_rx",
                    (unsigned __int8)v86,
                    BYTE1(v86),
                    BYTE2(v86),
                    HIBYTE(v87));
              }
            }
            --v15;
            v17 += 20;
            if ( !v15 )
              goto LABEL_30;
          }
        }
      }
      else
      {
        raw_spin_lock_bh(v83 + 352);
        *(__int64 *)((char *)&qword_164 + v11 + 4) |= 1uLL;
        v14 = *((unsigned __int8 *)v12 + 944);
        if ( *((_BYTE *)v12 + 944) )
          goto LABEL_7;
      }
      v30 = *(__int64 *)((char *)&qword_164 + v11 + 4);
      if ( (v30 & 1) != 0 )
      {
        *(__int64 *)((char *)&qword_164 + v11 + 4) = v30 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v11 + 352);
      }
      else
      {
        raw_spin_unlock(v11 + 352);
      }
LABEL_30:
      v31 = 0;
      v32 = "%s: %02x:%02x:%02x:**:**:%02xlink_status %d tdls_support %d tx %d rx %d rssi %d vdev %d";
      do
      {
        v33 = &v84[6 * v31];
        if ( !(unsigned int)qdf_list_peek_front((_QWORD *)v33 + 1, &v85) )
        {
          while ( 1 )
          {
            v44 = v84;
            v43 = v85;
            v45 = v83;
            v46 = *(_DWORD *)(v85 + 32);
            if ( !v46 )
              break;
            if ( v46 == 1 )
            {
              if ( *(unsigned __int16 *)(v85 + 46) | *(unsigned __int16 *)(v85 + 44) )
              {
                LODWORD(v80) = *(unsigned __int16 *)(v85 + 46);
                LODWORD(v82) = *(unsigned __int8 *)(*(_QWORD *)v84 + 104LL);
                LODWORD(v81) = *(char *)(v85 + 31);
                LODWORD(v79) = *(unsigned __int16 *)(v85 + 44);
                LODWORD(v78) = 1;
                LODWORD(v77) = *(_DWORD *)(v85 + 36);
                qdf_trace_msg(
                  0,
                  8u,
                  v32,
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  "tdls_ct_process_cap_supported",
                  *(unsigned __int8 *)(v85 + 24),
                  *(unsigned __int8 *)(v85 + 25),
                  *(unsigned __int8 *)(v85 + 26),
                  *(unsigned __int8 *)(v85 + 29),
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82);
              }
              v47 = *(_DWORD *)(v43 + 36);
              if ( v47 >= 2 )
              {
                if ( v47 == 4 )
                {
                  v57 = v32;
                  LODWORD(v80) = *(unsigned __int8 *)(v43 + 672);
                  LODWORD(v79) = *(unsigned __int16 *)(v43 + 46);
                  LODWORD(v78) = *(unsigned __int16 *)(v43 + 44);
                  LODWORD(v77) = *((_DWORD *)v44 + 187);
                  qdf_trace_msg(
                    0,
                    8u,
                    "%s: Peer: %02x:%02x:%02x:**:**:%02x idle_packet_n:%d tx_pkt:%d rx_pkt:%d idle_timer_initialised:%d",
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    v41,
                    "tdls_ct_process_connected_link",
                    *(unsigned __int8 *)(v43 + 24),
                    *(unsigned __int8 *)(v43 + 25),
                    *(unsigned __int8 *)(v43 + 26),
                    *(unsigned __int8 *)(v43 + 29),
                    v77,
                    v78,
                    v79,
                    v80);
                  v66 = *((_DWORD *)v44 + 187);
                  if ( !v66 || v66 <= *(unsigned __int16 *)(v43 + 44) || v66 <= *(unsigned __int16 *)(v43 + 46) )
                  {
                    if ( *(_DWORD *)(v43 + 652) == 21 )
                    {
                      qdf_trace_msg(
                        0,
                        3u,
                        "%s: Tx/Rx Idle timer stop: %02x:%02x:%02x:**:**:%02x",
                        v58,
                        v59,
                        v60,
                        v61,
                        v62,
                        v63,
                        v64,
                        v65,
                        "tdls_ct_process_connected_link",
                        *(unsigned __int8 *)(v43 + 24),
                        *(unsigned __int8 *)(v43 + 25),
                        *(unsigned __int8 *)(v43 + 26),
                        *(unsigned __int8 *)(v43 + 29));
                      qdf_mc_timer_stop(v43 + 504);
                    }
                    goto LABEL_35;
                  }
                  if ( (*(_BYTE *)(v43 + 672) & 1) == 0 )
                  {
                    if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 35), (const void *)(v43 + 24), 6u) )
                    {
                      if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 44), (const void *)(v43 + 24), 6u) )
                      {
                        if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 53), (const void *)(v43 + 24), 6u) )
                        {
                          if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 62), (const void *)(v43 + 24), 6u) )
                          {
                            if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 71), (const void *)(v43 + 24), 6u) )
                            {
                              if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 80), (const void *)(v43 + 24), 6u) )
                              {
                                v75 = 6;
                                if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 89), (const void *)(v43 + 24), 6u) )
                                {
                                  if ( (unsigned int)qdf_mem_cmp((const void *)(v45 + 98), (const void *)(v43 + 24), 6u) )
                                  {
                                    qdf_trace_msg(
                                      0,
                                      2u,
                                      "%s: tdls peer does not exists",
                                      v67,
                                      v68,
                                      v69,
                                      v70,
                                      v71,
                                      v72,
                                      v73,
                                      v74,
                                      "tdls_get_conn_info");
                                    v76 = 0;
                                    goto LABEL_82;
                                  }
                                  v76 = v45 + 95;
                                  v75 = 7;
                                }
                                else
                                {
                                  v76 = v45 + 86;
                                }
                              }
                              else
                              {
                                v76 = v45 + 77;
                                v75 = 5;
                              }
                            }
                            else
                            {
                              v76 = v45 + 68;
                              v75 = 4;
                            }
                          }
                          else
                          {
                            v76 = v45 + 59;
                            v75 = 3;
                          }
                        }
                        else
                        {
                          v76 = v45 + 50;
                          v75 = 2;
                        }
                      }
                      else
                      {
                        v76 = v45 + 41;
                        v75 = 1;
                      }
                    }
                    else
                    {
                      v75 = 0;
                      v76 = v45 + 32;
                    }
                    LODWORD(v77) = *(unsigned __int8 *)(v43 + 29);
                    qdf_trace_msg(
                      0,
                      8u,
                      "%s: tdls peer exists idx %d %02x:%02x:%02x:**:**:%02x",
                      v67,
                      v68,
                      v69,
                      v70,
                      v71,
                      v72,
                      v73,
                      v74,
                      "tdls_get_conn_info",
                      v75,
                      *(unsigned __int8 *)(v43 + 24),
                      *(unsigned __int8 *)(v43 + 25),
                      *(unsigned __int8 *)(v43 + 26),
                      v77);
                    *(_BYTE *)(v76 + 2) = v75;
LABEL_82:
                    qdf_mc_timer_init(v43 + 504, 0, (__int64)tdls_ct_idle_handler, v76);
                    *(_BYTE *)(v43 + 672) = 1;
                  }
                  v32 = v57;
                  if ( *(_DWORD *)(v43 + 652) != 21 )
                  {
                    qdf_trace_msg(
                      0,
                      3u,
                      "%s: Tx/Rx Idle timer start: %02x:%02x:%02x:**:**:%02x",
                      v58,
                      v59,
                      v60,
                      v61,
                      v62,
                      v63,
                      v64,
                      v65,
                      "tdls_ct_process_connected_link",
                      *(unsigned __int8 *)(v43 + 24),
                      *(unsigned __int8 *)(v43 + 25),
                      *(unsigned __int8 *)(v43 + 26),
                      *(unsigned __int8 *)(v43 + 29));
                    tdls_timer_restart(*v44, v43 + 504, *((unsigned int *)v44 + 186));
                  }
                }
              }
              else
              {
                if ( (*(_BYTE *)(v43 + 489) & 1) == 0 && byte_9C[v45] < 0
                  || *(unsigned __int16 *)(v43 + 46) + (unsigned int)*(unsigned __int16 *)(v43 + 44) < *((_DWORD *)v44 + 184) )
                {
                  goto LABEL_35;
                }
                if ( *(unsigned __int16 *)((char *)&word_CA + v45) < 9u )
                {
                  qdf_trace_msg(
                    0,
                    4u,
                    "%s: vdev:%d Throughput trigger TDLS discovery",
                    v34,
                    v35,
                    v36,
                    v37,
                    v38,
                    v39,
                    v40,
                    v41,
                    "tdls_ct_process_idle_and_discovery",
                    *(unsigned __int8 *)(*v44 + 104LL));
LABEL_54:
                  v44[97] = v43;
                  tdls_implicit_send_discovery_request(v44, v48, v49, v50, v51, v52, v53, v54, v55);
                  goto LABEL_35;
                }
                qdf_trace_msg(
                  0,
                  4u,
                  "%s: Maximum peers connected already! %d",
                  v34,
                  v35,
                  v36,
                  v37,
                  v38,
                  v39,
                  v40,
                  v41,
                  "tdls_ct_process_idle_and_discovery");
              }
            }
LABEL_35:
            v42 = (_QWORD *)v85;
            *(_DWORD *)(v43 + 44) = 0;
            if ( (unsigned int)qdf_list_peek_next((_QWORD *)v33 + 1, v42, &v85) )
              goto LABEL_31;
          }
          if ( (*(_BYTE *)(v85 + 489) & 1) == 0 && byte_9C[v83] < 0 )
            goto LABEL_35;
          if ( *(unsigned __int16 *)(v85 + 46) | *(unsigned __int16 *)(v85 + 44) )
          {
            LODWORD(v80) = *(unsigned __int16 *)(v85 + 46);
            LODWORD(v81) = *(unsigned __int8 *)(*(_QWORD *)v84 + 104LL);
            LODWORD(v79) = *(unsigned __int16 *)(v85 + 44);
            LODWORD(v78) = 0;
            LODWORD(v77) = *(_DWORD *)(v85 + 36);
            qdf_trace_msg(
              0,
              8u,
              "%s: %02x:%02x:%02x:**:**:%02x link_status %d tdls_support %d tx %d rx %d vdev %d",
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              v41,
              "tdls_ct_process_cap_unknown",
              *(unsigned __int8 *)(v85 + 24),
              *(unsigned __int8 *)(v85 + 25),
              *(unsigned __int8 *)(v85 + 26),
              *(unsigned __int8 *)(v85 + 29),
              v77,
              v78,
              v79,
              v80,
              v81);
          }
          v56 = *(_DWORD *)(v43 + 36);
          if ( (v56 & 0xFFFFFFFE) == 4 )
            goto LABEL_35;
          if ( (*(_BYTE *)(v43 + 489) & 1) == 0
            && *((_DWORD *)v44 + 185) <= (unsigned int)*(unsigned __int16 *)(v43 + 42) )
          {
            if ( v56 != 3 )
            {
              LODWORD(v77) = *(unsigned __int8 *)(v43 + 29);
              qdf_trace_msg(
                0,
                8u,
                "%s: vdev:%d %02x:%02x:%02x:**:**:%02x set link not supported ",
                v34,
                v35,
                v36,
                v37,
                v38,
                v39,
                v40,
                v41,
                "tdls_ct_process_cap_unknown",
                *(unsigned __int8 *)(*v44 + 104LL),
                *(unsigned __int8 *)(v43 + 24),
                *(unsigned __int8 *)(v43 + 25),
                *(unsigned __int8 *)(v43 + 26),
                v77);
              *(_DWORD *)(v43 + 32) = -1;
              tdls_set_peer_link_status(v43, 0, 4294967294LL);
            }
            goto LABEL_35;
          }
          qdf_trace_msg(
            0,
            8u,
            "%s: TDLS initiate discovery is_forced_peer:%d disc_attempts:%d",
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v41,
            "tdls_ct_process_cap_unknown");
          goto LABEL_54;
        }
LABEL_31:
        ++v31;
      }
      while ( v31 != 16 );
      result = tdls_timer_restart(*(_QWORD *)v84, v84 + 98, v84[183]);
    }
    else
    {
      result = qdf_trace_msg(
                 0,
                 4u,
                 "%s: vdev:%d Connection tracker is disabled",
                 v3,
                 v4,
                 v5,
                 v6,
                 v7,
                 v8,
                 v9,
                 v10,
                 "tdls_ct_process_handler",
                 *(unsigned __int8 *)(a1 + 104));
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall osif_indicate_reassoc_results(__int64 a1, __int64 **a2, unsigned __int8 *a3)
{
  __int64 **v4; // x22
  __int64 v5; // x26
  __int64 *v6; // x8
  __int64 v7; // x19
  __int64 result; // x0
  __int64 v9; // x8
  __int64 channel_khz; // x24
  unsigned int v11; // w8
  __int64 v12; // x9
  __int64 v13; // x19
  __int64 v14; // x20
  unsigned __int8 *v15; // x23
  __int64 v16; // x24
  __int64 is_mlo_vdev; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 peer_by_mac; // x0
  __int64 v21; // x19
  unsigned __int16 v22; // w8
  _QWORD *v23; // x9
  int v24; // w25
  __int64 v25; // x8
  unsigned int v26; // w8
  unsigned __int64 v27; // x20
  unsigned __int8 *v28; // x24
  __int64 v29; // x28
  __int64 v30; // x25
  int v32; // w6
  int v33; // w7
  int v34; // w8
  int v35; // w9
  unsigned __int64 v36; // x19
  int v37; // w11
  int v38; // w12
  int v39; // w13
  int v40; // w14
  unsigned __int64 v41; // x9
  int v42; // w6
  int v43; // w7
  int v44; // w8
  int v45; // w10
  unsigned int v46; // w0
  __int64 v47; // x28
  __int64 v48; // x20
  __int64 v49; // x8
  __int64 v50; // x0
  __int64 v51; // x26
  unsigned int v52; // w27
  unsigned __int8 *v53; // x24
  unsigned int v54; // w25
  int v55; // w19
  __int64 v56; // x0
  __int64 *v57; // x22
  __int64 v58; // x28
  int v59; // w19
  __int64 v60; // x7
  __int64 v61; // x6
  int v62; // w19
  __int64 v63; // x0
  __int64 v64; // x19
  char v65; // w0
  __int64 v66; // x8
  __int64 v67; // x8
  __int64 v68; // x19
  __int64 v69; // x20
  __int64 ap_link_by_link_id; // x0
  __int64 v71; // x28
  __int64 chan_bss_from_kernel; // x0
  __int64 v73; // x1
  __int64 *v74; // x8
  unsigned int v75; // w4
  __int64 v76; // x2
  int v77; // w0
  __int64 v78; // x0
  unsigned int v79; // w0
  __int64 v80; // [xsp+48h] [xbp-348h]
  __int64 v81; // [xsp+50h] [xbp-340h]
  int v82; // [xsp+58h] [xbp-338h]
  __int64 bss; // [xsp+60h] [xbp-330h]
  unsigned __int8 *v84; // [xsp+68h] [xbp-328h] BYREF
  __int64 v85; // [xsp+70h] [xbp-320h] BYREF
  __int64 v86; // [xsp+78h] [xbp-318h] BYREF
  __int64 v87; // [xsp+80h] [xbp-310h] BYREF
  char v88[4]; // [xsp+8Ch] [xbp-304h] BYREF
  _QWORD v89[72]; // [xsp+90h] [xbp-300h] BYREF
  _QWORD v90[24]; // [xsp+2D0h] [xbp-C0h] BYREF

  v4 = a2;
  v5 = a1;
  v90[22] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a2;
  v86 = 0;
  v87 = 0;
  v84 = nullptr;
  v85 = 0;
  v7 = v6[4];
  result = wlan_vdev_mlme_is_mlo_vdev(a1);
  if ( ((result & 1) == 0 || (*(_BYTE *)(v5 + 60) & 2) == 0) && !*((_DWORD *)a3 + 13) )
  {
    v9 = *(_QWORD *)(v5 + 216);
    if ( v9 )
    {
      if ( *(_QWORD *)(v9 + 80) )
      {
        channel_khz = ieee80211_get_channel_khz(**v4, (unsigned int)(1000 * *((_DWORD *)a3 + 12)));
        bss = wlan_cfg80211_get_bss(**v4, channel_khz, a3 + 8, a3 + 15, a3[14]);
        if ( bss || (bss = wlan_cfg80211_get_bss(**v4, channel_khz, a3 + 8, 0, 0)) != 0 )
        {
          if ( (a3[1] & 0x10) != 0 )
          {
            osif_cm_get_assoc_req_ie_data((__int64)(a3 + 104), &v87, &v86);
          }
          else
          {
            v11 = *((_DWORD *)a3 + 26);
            if ( v11 > 0xA )
            {
              v12 = *((_QWORD *)a3 + 14);
              if ( v12 )
              {
                v86 = v12 + 10;
                v87 = v11 - 10;
              }
            }
          }
          v80 = v7;
          osif_cm_get_assoc_rsp_ie_data((__int64)(a3 + 120), &v85, &v84);
          v13 = v86;
          v14 = v87;
          v15 = v84;
          v16 = v85;
          memset(&v89[4], 0, 0x220u);
          if ( (wlan_vdev_mlme_is_mlo_vdev(v5) & 1) == 0 )
            v89[15] = bss;
          v89[0] = v13;
          v89[1] = v14;
          v89[2] = v15;
          v89[3] = v16;
          v81 = v5;
          is_mlo_vdev = wlan_vdev_mlme_is_mlo_vdev(v5);
          if ( (is_mlo_vdev & 1) == 0 )
            goto LABEL_54;
          v18 = *(_QWORD *)(v5 + 216);
          if ( v18 )
            v19 = *(_QWORD *)(v18 + 80);
          else
            v19 = 0;
          peer_by_mac = wlan_objmgr_get_peer_by_mac(v19, a3 + 8, 6);
          if ( !peer_by_mac )
          {
            is_mlo_vdev = qdf_trace_msg(
                            72,
                            2,
                            "%s: Unable to fill peer mld address: %d",
                            "osif_fill_mlo_roam_params",
                            4);
            goto LABEL_54;
          }
          v89[10] = peer_by_mac + 792;
          wlan_objmgr_peer_release_ref();
          v21 = *(unsigned __int8 *)(v5 + 93);
          v22 = LOWORD(v89[11]) | (1LL << v21);
          LOWORD(v89[11]) = v22;
          if ( (unsigned int)v21 < 0xF )
          {
            v23 = &v89[4 * v21 + 12];
            *v23 = v5 + 74;
            v23[1] = a3 + 8;
            v24 = v22;
            v23[3] = bss;
            mlo_mgr_osif_update_connect_info(v5, (unsigned int)v21);
            v82 = v21;
            is_mlo_vdev = qdf_trace_msg(
                            72,
                            8,
                            "%s: Vdev %d, Num partner links %d, valid links mask 0x%x Assoc link %u",
                            "osif_fill_mlo_roam_params",
                            *a3,
                            a3[160],
                            v24,
                            v21);
            v25 = *(_QWORD *)(v5 + 216);
            memset(v90, 0, 176);
            v88[0] = 0;
            if ( !v25 || (is_mlo_vdev = osif_get_partner_info_from_mlie((__int64)a3, (__int64)v90), (_DWORD)is_mlo_vdev) )
            {
LABEL_24:
              v26 = a3[160];
              if ( a3[160] )
              {
                v27 = 0;
                while ( 1 )
                {
                  if ( v27 == 4 )
                    goto LABEL_110;
                  v28 = &a3[48 * v27 + 168];
                  v29 = v28[6];
                  if ( (unsigned int)v29 > 0xE )
                    goto LABEL_110;
                  v30 = v89[4 * v29 + 15];
                  if ( v30 )
                  {
                    if ( (_DWORD)v29 != v82 && v30 == bss )
                    {
                      if ( v28 )
                      {
                        v32 = *v28;
                        v33 = v28[1];
                        v34 = v28[2];
                        v35 = v28[5];
                      }
                      else
                      {
                        v34 = 0;
                        v32 = 0;
                        v33 = 0;
                        v35 = 0;
                      }
                      is_mlo_vdev = qdf_trace_msg(
                                      72,
                                      4,
                                      "%s: link bss, link_id %d freq %d bssid %02x:%02x:%02x:**:**:%02x same as assoc bss"
                                      ", link %d freq %d bssid %02x:%02x:%02x:**:**:%02x",
                                      "osif_debug_mlo_roam_duplicate_bss",
                                      v29,
                                      *((unsigned __int16 *)v28 + 5),
                                      v32,
                                      v33,
                                      v34,
                                      v35,
                                      v82,
                                      *((_DWORD *)a3 + 12),
                                      a3[8],
                                      a3[9],
                                      a3[10],
                                      a3[13]);
                      v26 = a3[160];
                    }
                    if ( v26 )
                      break;
                  }
LABEL_26:
                  if ( ++v27 >= v26 )
                    goto LABEL_54;
                }
                v36 = 0;
                v15 = a3 + 168;
                while ( 1 )
                {
                  if ( v36 > v27 )
                  {
                    if ( v36 > 3 )
                      goto LABEL_110;
                    v41 = v15[6];
                    if ( v41 > 0xE )
                      goto LABEL_110;
                    if ( v89[4 * v41 + 15] == v30 )
                      break;
                  }
LABEL_43:
                  ++v36;
                  v15 += 48;
                  if ( v36 >= v26 )
                    goto LABEL_26;
                }
                if ( v28 )
                {
                  v42 = *v28;
                  v43 = v28[1];
                  v44 = v28[2];
                  v45 = v28[5];
                  if ( !v15 )
                    goto LABEL_52;
                }
                else
                {
                  v44 = 0;
                  v42 = 0;
                  v43 = 0;
                  v45 = 0;
                  if ( !v15 )
                  {
LABEL_52:
                    v39 = 0;
                    v37 = 0;
                    v38 = 0;
                    v40 = 0;
                    goto LABEL_42;
                  }
                }
                v37 = *v15;
                v38 = v15[1];
                v39 = v15[2];
                v40 = v15[5];
LABEL_42:
                is_mlo_vdev = qdf_trace_msg(
                                72,
                                4,
                                "%s: link bss, link_id %d freq %d bssid %02x:%02x:%02x:**:**:%02x same as link bss, link "
                                "%d freq %d bssid %02x:%02x:%02x:**:**:%02x",
                                "osif_debug_mlo_roam_duplicate_bss",
                                v29,
                                *((unsigned __int16 *)v28 + 5),
                                v42,
                                v43,
                                v44,
                                v45,
                                v41,
                                *((unsigned __int16 *)v15 + 5),
                                v37,
                                v38,
                                v39,
                                v40);
                v26 = a3[160];
                goto LABEL_43;
              }
LABEL_54:
              v46 = qdf_mem_malloc_flags(is_mlo_vdev);
              v47 = v80;
              cfg80211_roamed(v80, v89, v46);
              v48 = v81;
              v49 = *(_QWORD *)(v81 + 216);
              if ( v49 )
                v50 = *(_QWORD *)(v49 + 80);
              else
                v50 = 0;
              v51 = v86;
              v52 = v87;
              v53 = v84;
              v54 = v85;
              LOBYTE(v90[0]) = 0;
              result = ucfg_mlme_get_roaming_offload(v50, v90);
              if ( LOBYTE(v90[0]) == 1 )
              {
                v15 = *((unsigned __int8 **)a3 + 18);
                v55 = *((_DWORD *)v15 + 28);
                v56 = wlan_vdev_mlme_is_mlo_vdev(v81);
                v57 = *v4;
                v58 = *v57;
                if ( (v56 & 1) != 0 )
                {
                  v59 = v54 + v52 + 13 * a3[160] + v15[2] + v15[35] + v55;
                  v60 = (unsigned int)qdf_mem_malloc_flags(v56);
                  v61 = (unsigned int)(v59 + 222);
                }
                else
                {
                  v62 = v54 + v52 + v15[2] + v15[35] + v55;
                  v60 = (unsigned int)qdf_mem_malloc_flags(v56);
                  v61 = (unsigned int)(v62 + 228);
                }
                v63 = _cfg80211_alloc_event_skb(v58, v57, 103, 197, 0, 12, v61, v60);
                v47 = v80;
                v48 = v81;
                v4 = (__int64 **)v63;
                if ( v63 )
                {
                  v64 = *(_QWORD *)(v81 + 184);
                  if ( !v64 )
                    goto LABEL_70;
                  v65 = wlan_vdev_mlme_is_mlo_vdev(v81);
                  v66 = 48;
                  if ( (v65 & 1) != 0 )
                    v66 = 792;
                  if ( !(v64 + v66) )
                  {
LABEL_70:
                    qdf_trace_msg(72, 2, "%s: Invalid bss mac addr", "osif_send_roam_auth_event");
                    goto LABEL_71;
                  }
                  if ( (unsigned int)nla_put(v4, 1, 6, v64 + v66)
                    || (unsigned int)nla_put(v4, 2, v52, v51)
                    || (unsigned int)nla_put(v4, 3, v54, v53) )
                  {
                    goto LABEL_69;
                  }
                  if ( *v15 != 2 )
                  {
                    qdf_trace_msg(72, 8, "%s: No Auth Params TLV's", "osif_send_roam_auth_event");
                    LOBYTE(v89[0]) = 0;
                    if ( (unsigned int)nla_put(v4, 4, 1, v89) )
                      goto LABEL_69;
                    goto LABEL_101;
                  }
                  qdf_trace_msg(72, 8, "%s: Include Auth Params TLV's", "osif_send_roam_auth_event");
                  LOBYTE(v89[0]) = 1;
                  if ( (unsigned int)nla_put(v4, 4, 1, v89) )
                    goto LABEL_69;
                  if ( (wlan_crypto_get_param(v81, 7) & 0x13304860) == 0 && (unsigned int)nla_put(v4, 5, 8, v15 + 100) )
                  {
                    qdf_trace_msg(72, 2, "%s: non FT/non CCKM connection", "osif_send_roam_auth_event");
                    qdf_trace_msg(72, 2, "%s: failed to send replay counter", "osif_send_roam_auth_event");
                    goto LABEL_71;
                  }
                  v75 = v15[35];
                  if ( v75 > 0x40 )
                    goto LABEL_98;
                  v76 = v15[2];
                  if ( (unsigned int)v76 > 0x20 )
                    goto LABEL_98;
                  v77 = nla_put(v4, 6, v76, v15 + 3);
                  v75 = v15[35];
                  if ( v77 )
                    goto LABEL_98;
                  if ( (unsigned int)nla_put(v4, 7, v15[35], v15 + 36) )
                  {
                    v75 = v15[35];
LABEL_98:
                    qdf_trace_msg(72, 2, "%s: nla put fail, kek_len %d", "osif_send_roam_auth_event", v75);
LABEL_99:
                    v47 = v80;
                    v48 = v81;
                    goto LABEL_71;
                  }
LABEL_111:
                  LOWORD(v89[0]) = osif_get_roam_reason(*((unsigned __int16 *)v15 + 55));
                  if ( (unsigned int)nla_put(v4, 14, 2, v89) )
                  {
                    qdf_trace_msg(72, 2, "%s: roam reason send failure", "osif_send_roam_auth_event");
                    goto LABEL_99;
                  }
                  v47 = v80;
                  v48 = v81;
                  if ( (unsigned int)osif_add_fils_params_roam_auth_event(v4, v15) )
                  {
LABEL_71:
                    result = sk_skb_reason_drop(0, v4, 2);
                    v67 = *((_QWORD *)a3 + 17);
                    if ( !v67 )
                      goto LABEL_4;
                    goto LABEL_75;
                  }
                  osif_cm_save_gtk(v81, a3);
                  qdf_trace_msg(
                    72,
                    8,
                    "%s: replay_ctr 0x%llx kck %d kek %d",
                    "osif_send_roam_auth_event",
                    *(_QWORD *)(v15 + 100),
                    v15[2],
                    v15[35]);
LABEL_101:
                  qdf_trace_msg(
                    72,
                    8,
                    "%s: Auth Status = %d Subnet Change Status = %d",
                    "osif_send_roam_auth_event",
                    *v15,
                    v15[108]);
                  if ( !v15[108] || (LOBYTE(v89[0]) = v15[108], !(unsigned int)nla_put(v4, 8, 1, v89)) )
                  {
                    v78 = wlan_vdev_mlme_is_mlo_vdev(v48);
                    if ( (v78 & 1) == 0
                      || (v78 = ((__int64 (__fastcall *)(__int64 **, __int64, unsigned __int8 *))osif_send_roam_auth_mlo_links_event)(
                                  v4,
                                  v48,
                                  a3),
                          !(_DWORD)v78) )
                    {
                      v79 = qdf_mem_malloc_flags(v78);
                      result = _cfg80211_send_event_skb(v4, v79);
                      v67 = *((_QWORD *)a3 + 17);
                      if ( !v67 )
                        goto LABEL_4;
LABEL_75:
                      if ( *(_WORD *)(v67 + 2440) )
                        result = osif_cm_set_hlp_data(v47, v48, a3);
                      goto LABEL_4;
                    }
                    qdf_trace_msg(72, 2, "%s: Send mlo link fail", "osif_send_roam_auth_event");
                    goto LABEL_71;
                  }
LABEL_69:
                  qdf_trace_msg(72, 2, "%s: nla put fail", "osif_send_roam_auth_event");
                  goto LABEL_71;
                }
                result = qdf_trace_msg(72, 2, "%s: cfg80211_vendor_event_alloc failed", "osif_send_roam_auth_event");
              }
              v67 = *((_QWORD *)a3 + 17);
              if ( !v67 )
                goto LABEL_4;
              goto LABEL_75;
            }
            if ( !a3[160] )
              goto LABEL_54;
            v68 = 0;
            v15 = (_BYTE *)(&off_0 + 1);
            v69 = 48LL * a3[160];
            while ( v68 != 192 )
            {
              is_mlo_vdev = ((__int64 (__fastcall *)(unsigned __int8 *, _QWORD *, char *))osif_get_link_id_from_assoc_ml_ie)(
                              &a3[v68 + 168],
                              v90,
                              v88);
              if ( !(_DWORD)is_mlo_vdev )
              {
                ap_link_by_link_id = mlo_mgr_get_ap_link_by_link_id(*(_QWORD *)(v5 + 1360), (unsigned __int8)v88[0]);
                if ( ap_link_by_link_id )
                {
                  v71 = ap_link_by_link_id;
                  chan_bss_from_kernel = osif_get_chan_bss_from_kernel(v5, &a3[v68 + 168], (__int64)a3);
                  v73 = (unsigned __int8)v88[0];
                  v24 |= 1LL << v88[0];
                  LOWORD(v89[11]) = v24;
                  if ( (unsigned __int8)v88[0] >= 0xFuLL )
                    break;
                  v74 = &v89[4 * (unsigned __int8)v88[0] + 12];
                  *v74 = v71;
                  v74[1] = v71 + 24;
                  if ( chan_bss_from_kernel )
                    v74[3] = chan_bss_from_kernel;
                  v5 = v81;
                  is_mlo_vdev = mlo_mgr_osif_update_connect_info(v81, v73);
                }
                else
                {
                  is_mlo_vdev = qdf_trace_msg(
                                  72,
                                  8,
                                  "%s: link info not found for link_id:%d",
                                  "osif_populate_partner_links_roam_mlo_params",
                                  (unsigned __int8)v88[0]);
                }
              }
              v68 += 48;
              if ( v69 == v68 )
                goto LABEL_24;
            }
          }
LABEL_110:
          __break(0x5512u);
          goto LABEL_111;
        }
        qdf_trace_msg(
          72,
          3,
          "%s: BSS %02x:%02x:%02x:**:**:%02x is null, issue disconnect",
          "osif_indicate_reassoc_results",
          a3[8],
          a3[9],
          a3[10],
          a3[13]);
        result = osif_cm_disconnect(v7, v5, 1u);
        if ( (_DWORD)result )
          result = qdf_trace_msg(72, 2, "%s: Disconnect failed with status %d", "osif_indicate_reassoc_results", result);
      }
    }
  }
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}

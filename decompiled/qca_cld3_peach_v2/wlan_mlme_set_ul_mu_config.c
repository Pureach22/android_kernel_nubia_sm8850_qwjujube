__int64 __fastcall wlan_mlme_set_ul_mu_config(__int64 a1, __int64 a2, char a3)
{
  unsigned int v4; // w22
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x24
  __int64 v16; // x19
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int bss_peer_mac; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w21
  const char *v35; // x2
  __int64 v36; // x4
  unsigned int *v37; // x8
  const char *v38; // x2
  _QWORD *peer_by_mac; // x0
  int v41; // w21
  unsigned int sta_rx_nss; // w0
  unsigned int sta_tx_nss; // w0
  unsigned int op_chan_freq_info_vdev_id; // w0
  unsigned int v45; // w0
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 v62; // [xsp+54h] [xbp-2Ch] BYREF
  _BYTE v63[4]; // [xsp+5Ch] [xbp-24h] BYREF
  _BYTE v64[4]; // [xsp+60h] [xbp-20h] BYREF
  unsigned int v65; // [xsp+64h] [xbp-1Ch] BYREF
  __int64 v66; // [xsp+68h] [xbp-18h] BYREF
  int v67; // [xsp+70h] [xbp-10h] BYREF
  __int16 v68; // [xsp+74h] [xbp-Ch]
  __int64 v69; // [xsp+78h] [xbp-8h]

  v4 = a2;
  v69 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v66 = 0;
  v65 = 0;
  v64[0] = 0;
  v63[0] = 0;
  v68 = 0;
  v67 = 0;
  v62 = 0;
  v6 = ((__int64 (__fastcall *)(__int64, __int64, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 67);
  if ( v6 )
  {
    v15 = *(_QWORD *)(v6 + 216);
    v16 = v6;
    if ( v15 )
    {
      if ( (cm_is_vdevid_connected(*(_QWORD *)(v6 + 216), v4) & 1) == 0 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: STA is not connected, Session_id: %d",
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          "wlan_mlme_set_ul_mu_config",
          (unsigned __int8)v4);
        goto LABEL_12;
      }
      bss_peer_mac = wlan_vdev_get_bss_peer_mac(v16, &v67, v17, v18, v19, v20, v21, v22, v23, v24);
      if ( bss_peer_mac )
      {
        v34 = bss_peer_mac;
        v35 = "%s: Failed to get bss peer mac, Err : %d";
LABEL_6:
        v36 = v34;
LABEL_7:
        qdf_trace_msg(0x68u, 2u, v35, v26, v27, v28, v29, v30, v31, v32, v33, "wlan_mlme_set_ul_mu_config", v36);
LABEL_13:
        wlan_objmgr_vdev_release_ref(v16, 0x43u, v37, v26, v27, v28, v29, v30, v31, v32, v33);
        goto LABEL_14;
      }
      peer_by_mac = wlan_objmgr_get_peer_by_mac(a1, &v67, 2u);
      if ( !peer_by_mac )
      {
        v35 = "%s: Failed to get peer phymode, Err : %d";
        v36 = 29;
        v34 = 29;
        goto LABEL_7;
      }
      v41 = *((_DWORD *)peer_by_mac + 18);
      wlan_objmgr_peer_release_ref((__int64)peer_by_mac, 2u, v26, v27, v28, v29, v30, v31, v32, v33);
      if ( (unsigned int)(v41 - 21) < 0x14 )
      {
        sta_rx_nss = wlan_mlme_get_sta_rx_nss(a1, v16, v64);
        if ( sta_rx_nss )
        {
          v34 = sta_rx_nss;
          v35 = "%s: Failed to get sta_rx_nss, Err : %d";
        }
        else
        {
          sta_tx_nss = wlan_mlme_get_sta_tx_nss(a1, v16, v63);
          if ( sta_tx_nss )
          {
            v34 = sta_tx_nss;
            v35 = "%s: Failed to get sta_tx_nss, Err : %d";
          }
          else
          {
            op_chan_freq_info_vdev_id = wlan_get_op_chan_freq_info_vdev_id(v15, v4, (_DWORD *)&v62 + 1, &v62, &v65);
            if ( op_chan_freq_info_vdev_id )
            {
              v34 = op_chan_freq_info_vdev_id;
              v35 = "%s: Failed to get bw, Err : %d";
            }
            else
            {
              HIDWORD(v66) = 7;
              v45 = set_omi_ch_width(v65, (char *)&v66 + 4);
              if ( v45 )
              {
                v34 = v45;
                v35 = "%s: Failed to set bw, Err : %d";
              }
              else
              {
                HIDWORD(v66) = HIDWORD(v66) & 0xFFFD863F
                             | (((v64[0] - 1) & 7) << 6) & 0x87FF
                             | (((v63[0] - 1) & 7) << 12)
                             | ((a3 & 1) << 11);
                qdf_mem_copy(&v66, (char *)&v66 + 4, 4u);
                qdf_trace_msg(
                  0x68u,
                  8u,
                  "%s: OMI: BW %d TxNSTS %d RxNSS %d ULMU %d OMI_VHT %d OMI_HE %d, EHT OMI: BW %d RxNSS %d TxNSS %d, para"
                  "m val: %08X, bssid:%02x:%02x:%02x:**:**:%02x",
                  v46,
                  v47,
                  v48,
                  v49,
                  v50,
                  v51,
                  v52,
                  v53,
                  "wlan_mlme_set_ul_mu_config",
                  (HIDWORD(v66) >> 9) & 3,
                  (HIDWORD(v66) >> 12) & 7,
                  (HIDWORD(v66) >> 6) & 7,
                  (HIDWORD(v66) >> 11) & 1,
                  BYTE4(v66) & 1,
                  (HIDWORD(v66) >> 1) & 1,
                  (HIDWORD(v66) >> 19) & 1,
                  (HIDWORD(v66) >> 18) & 1,
                  (HIDWORD(v66) >> 20) & 1,
                  v66,
                  (unsigned __int8)v67,
                  BYTE1(v67),
                  BYTE2(v67),
                  HIBYTE(v68));
                v34 = wlan_util_vdev_peer_set_param_send(
                        v16,
                        (unsigned __int8 *)&v67,
                        28,
                        v66,
                        v54,
                        v55,
                        v56,
                        v57,
                        v58,
                        v59,
                        v60,
                        v61);
                if ( !v34 )
                  goto LABEL_13;
                v35 = "%s: set_peer_param_cmd returned %d";
              }
            }
          }
        }
        goto LABEL_6;
      }
      v38 = "%s: Invalid mode";
    }
    else
    {
      v38 = "%s: pdev is NULL";
    }
    qdf_trace_msg(0x68u, 2u, v38, v7, v8, v9, v10, v11, v12, v13, v14, "wlan_mlme_set_ul_mu_config");
LABEL_12:
    v34 = 4;
    goto LABEL_13;
  }
  qdf_trace_msg(
    0x68u,
    2u,
    "%s: vdev %d: vdev is NULL",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "wlan_mlme_set_ul_mu_config",
    (unsigned __int8)v4);
  v34 = 4;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v34;
}

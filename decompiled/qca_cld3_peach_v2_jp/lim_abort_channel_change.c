__int64 __fastcall lim_abort_channel_change(__int64 a1, unsigned __int8 a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  __int64 result; // x0
  __int64 session_by_bssid; // x0
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7
  __int64 v24; // x21
  __int64 v25; // x0
  _DWORD *sap_ch_sw_info; // x0
  int v27; // w8
  __int64 v28; // x0
  int v29; // w8
  __int64 v30; // [xsp+8h] [xbp-48h] BYREF
  __int64 v31; // [xsp+10h] [xbp-40h]
  __int64 v32; // [xsp+18h] [xbp-38h]
  __int64 v33; // [xsp+20h] [xbp-30h]
  __int64 v34; // [xsp+28h] [xbp-28h]
  __int64 v35; // [xsp+30h] [xbp-20h]
  _BYTE v36[4]; // [xsp+3Ch] [xbp-14h] BYREF
  int v37; // [xsp+40h] [xbp-10h] BYREF
  __int16 v38; // [xsp+44h] [xbp-Ch]
  __int64 v39; // [xsp+48h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21560);
  v38 = 0;
  v37 = 0;
  v36[0] = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  if ( (unsigned int)wlan_mlme_get_mac_vdev_id(v4, a2, &v37) )
  {
    v13 = "%s: Failed to get vdev ID";
  }
  else
  {
    session_by_bssid = pe_find_session_by_bssid(a1, &v37, v36);
    if ( !session_by_bssid )
    {
      result = qdf_trace_msg(
                 0x35u,
                 2u,
                 "%s: Session does not exist for bssid %02x:%02x:%02x:**:**:%02x",
                 v16,
                 v17,
                 v18,
                 v19,
                 v20,
                 v21,
                 v22,
                 v23,
                 "lim_abort_channel_change",
                 (unsigned __int8)v37,
                 BYTE1(v37),
                 BYTE2(v37),
                 HIBYTE(v38));
      goto LABEL_4;
    }
    v24 = session_by_bssid;
    v25 = *(_QWORD *)(session_by_bssid + 16);
    *(_WORD *)(v24 + 152) = 3;
    sap_ch_sw_info = (_DWORD *)wlan_get_sap_ch_sw_info(v25, v16, v17, v18, v19, v20, v21, v22, v23);
    if ( sap_ch_sw_info )
    {
      *sap_ch_sw_info = *(_DWORD *)(v24 + 284);
      v27 = *(_DWORD *)(v24 + 7176);
      sap_ch_sw_info[4] = v27;
      sap_ch_sw_info[5] = v27;
      wlan_vdev_mlme_sm_deliver_evt(*(_QWORD *)(v24 + 16), 0x1Eu, 0x2A28u, v24, v5, v6, v7, v8, v9, v10, v11, v12);
      v28 = _qdf_mem_malloc(0xCu, "lim_abort_channel_change", 10387);
      if ( v28 )
      {
        v29 = *(_DWORD *)(v24 + 284);
        *(_BYTE *)(v28 + 8) = 0;
        *(_BYTE *)v28 = a2;
        *(_DWORD *)(v28 + 4) = v29;
        v31 = v28;
        LOWORD(v30) = 5205;
        HIDWORD(v30) = 0;
        result = sys_process_mmh_msg(a1, &v30);
        goto LABEL_4;
      }
      v13 = "%s: Failed to allocate chan_change_rsp";
    }
    else
    {
      v13 = "%s: Invalid channel info";
    }
  }
  result = qdf_trace_msg(0x35u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "lim_abort_channel_change");
LABEL_4:
  _ReadStatusReg(SP_EL0);
  return result;
}

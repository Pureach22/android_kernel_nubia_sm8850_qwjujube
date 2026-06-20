__int64 __fastcall wlan_hdd_setup_driver_overrides(__int64 a1)
{
  __int64 *v2; // x8
  __int64 result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 *v12; // x21
  _DWORD *v13; // x20
  int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  int v31; // w8
  int v32; // w8
  bool is_24ghz_ch_freq; // w8
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  _BYTE v43[4]; // [xsp+Ch] [xbp-24h] BYREF
  _BYTE v44[4]; // [xsp+10h] [xbp-20h] BYREF
  _BYTE v45[4]; // [xsp+14h] [xbp-1Ch] BYREF
  int v46; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v47[4]; // [xsp+1Ch] [xbp-14h] BYREF
  _BYTE v48[4]; // [xsp+20h] [xbp-10h] BYREF
  _BYTE v49[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v50; // [xsp+28h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(a1 + 24);
  v43[0] = 0;
  result = wlan_mlme_get_vendor_acs_support(*v2, v43);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x33u,
               2u,
               "%s: get_vendor_acs_support failed, set default",
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               "wlan_hdd_setup_driver_overrides");
  if ( (v43[0] & 1) == 0 )
  {
    v12 = *(__int64 **)(a1 + 24);
    v49[0] = 0;
    v13 = *(_DWORD **)(a1 + 52832);
    v48[0] = 0;
    v47[0] = 0;
    v14 = v13[180];
    v46 = 0;
    v45[0] = 0;
    v44[0] = 0;
    result = wlan_reg_is_6ghz_chan_freq(v14);
    if ( (result & 1) == 0 )
    {
      wlan_mlme_get_sap_force_11n_for_11ac(*v12, v48);
      wlan_mlme_get_go_force_11n_for_11ac(*v12, v47);
      wlan_mlme_is_go_11ac_override(*v12, v45);
      wlan_mlme_is_sap_11ac_override(*v12, v44);
      result = cds_is_sub_20_mhz_enabled(v15, v16, v17, v18, v19, v20, v21, v22);
      if ( (result & 1) == 0 )
      {
        v31 = v13[80];
        if ( v31 <= 511 )
        {
          if ( v31 != 16 && v31 != 256 )
            goto LABEL_30;
        }
        else if ( v31 != 512 && v31 != 4096 && v31 != 2048 )
        {
          goto LABEL_30;
        }
        v32 = *(_DWORD *)(a1 + 40);
        if ( v32 == 3 )
        {
          if ( (v47[0] & 1) != 0 || v45[0] != 1 )
            goto LABEL_30;
        }
        else if ( v32 != 1 || (v48[0] & 1) != 0 || (v44[0] & 1) == 0 )
        {
          goto LABEL_30;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: ** Driver force 11AC override for SAP/Go **",
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "wlan_hdd_sap_p2p_11ac_overrides");
        if ( v13[80] == 16 )
          v13[80] = 256;
        is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v13[180]);
        v34 = *v12;
        if ( is_24ghz_ch_freq )
        {
          result = ucfg_mlme_get_channel_bonding_24ghz(v34, &v46);
          v13[188] = v13[188] && v46;
        }
        else
        {
          result = wlan_mlme_get_vht_channel_width(v34, v49);
          if ( (_DWORD)result )
            result = qdf_trace_msg(
                       0x33u,
                       2u,
                       "%s: Failed to set channel_width",
                       v35,
                       v36,
                       v37,
                       v38,
                       v39,
                       v40,
                       v41,
                       v42,
                       "wlan_hdd_sap_p2p_11ac_overrides");
          v13[188] = v49[0];
        }
      }
    }
  }
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return result;
}

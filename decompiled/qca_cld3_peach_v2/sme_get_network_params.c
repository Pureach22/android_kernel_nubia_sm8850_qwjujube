__int64 __fastcall sme_get_network_params(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int opmode_from_vdev_id; // w21
  unsigned int phy_mode_band_for_bss; // w22
  char v7; // w0
  __int64 v8; // x1
  double v9; // d0
  int v10; // w0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w8
  unsigned __int8 *v27; // x0
  char v28; // w1
  char v29; // w2
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // [xsp+0h] [xbp-10h] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  BYTE4(v38) = 1;
  LOBYTE(v38) = 0;
  if ( a1 )
  {
    result = qdf_mutex_acquire(a1 + 12848);
    if ( !(_DWORD)result )
    {
      wlan_mlme_get_sap_chan_switch_rate_enabled(*(_QWORD *)(a1 + 21624), (_BYTE *)&v38 + 4);
      ucfg_policy_mgr_get_mcc_scc_switch(*(_QWORD *)(a1 + 21624), &v38);
      if ( (_BYTE)v38 )
        BYTE4(v38) = 0;
      opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21632), *(_BYTE *)a2);
      phy_mode_band_for_bss = csr_roam_get_phy_mode_band_for_bss(a1, a2);
      v7 = csr_translate_to_wni_cfg_dot11_mode(a1, phy_mode_band_for_bss);
      v8 = *(unsigned int *)(a2 + 20);
      *(_BYTE *)(a2 + 12) = v7;
      v9 = csr_convert_mode_to_nw_type(phy_mode_band_for_bss, v8);
      *(_DWORD *)(a2 + 16) = v10;
      if ( !cds_is_sub_20_mhz_enabled(v9, v11, v12, v13, v14, v15, v16, v17)
        && BYTE4(v38) == 1
        && (*(_BYTE *)(a2 + 24) || *(_BYTE *)(a2 + 37)) )
      {
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: Use the rates from the hostapd",
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          "sme_get_network_params",
          v38,
          v39);
LABEL_20:
        qdf_mutex_release(a1 + 12848);
        result = 0;
        goto LABEL_21;
      }
      *(_BYTE *)(a2 + 37) = 0;
      v26 = *(_DWORD *)(a2 + 16);
      *(_BYTE *)(a2 + 24) = 0;
      v27 = (unsigned __int8 *)(a2 + 24);
      if ( v26 == 2 )
      {
        if ( (opmode_from_vdev_id & 0xFFFFFFFE) != 2 && phy_mode_band_for_bss != 6 )
        {
          wlan_populate_basic_rates(v27, 0, 1);
          v27 = (unsigned __int8 *)(a2 + 37);
          v28 = 1;
          v29 = 0;
          goto LABEL_19;
        }
      }
      else
      {
        if ( v26 == 1 )
        {
          v28 = 0;
          v29 = 1;
          goto LABEL_19;
        }
        if ( v26 )
        {
          qdf_mutex_release(a1 + 12848);
          qdf_trace_msg(
            0x34u,
            2u,
            "%s: Unknown network type %d",
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            "sme_get_network_params",
            *(unsigned int *)(a2 + 16));
          result = 16;
          goto LABEL_21;
        }
      }
      v28 = 1;
      v29 = 1;
LABEL_19:
      wlan_populate_basic_rates(v27, v28, v29);
      goto LABEL_20;
    }
  }
  else
  {
    result = 16;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}

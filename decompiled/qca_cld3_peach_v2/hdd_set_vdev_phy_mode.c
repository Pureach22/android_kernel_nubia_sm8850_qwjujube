__int64 __fastcall hdd_set_vdev_phy_mode(__int64 a1, unsigned int a2)
{
  __int64 v2; // x24
  __int64 *v4; // x19
  __int64 v5; // x20
  __int64 v6; // x21
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  double v16; // d0
  unsigned int v17; // w0
  unsigned int v18; // w23
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned int max_phymode; // w0
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x0
  unsigned int v36; // w22
  __int64 v37; // x0
  unsigned int v38; // w23
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  unsigned int v47; // w22
  char is_6ghz_supported; // w0
  unsigned int wifi_standard; // w21
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // w0
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  unsigned int v67; // w19
  _BYTE v68[4]; // [xsp+8h] [xbp-18h] BYREF
  unsigned int v69; // [xsp+Ch] [xbp-14h] BYREF
  unsigned int v70; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v71; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v72; // [xsp+18h] [xbp-8h]

  v2 = a1 + 49152;
  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(__int64 **)(a1 + 24);
  v5 = *(_QWORD *)(a1 + 52832);
  v71 = 0;
  v69 = 0;
  v70 = 0;
  v6 = *v4;
  v68[0] = 0;
  if ( (hdd_cm_is_vdev_connected(v5) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Station is connected, command is not supported",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "hdd_set_vdev_phy_mode");
    result = 4294967274LL;
  }
  else
  {
    result = hdd_vendor_mode_to_phymode(a2, &v71);
    if ( (result & 0x80000000) == 0 )
    {
      v16 = csr_convert_to_reg_phy_mode(v71, 0);
      v18 = v17;
      max_phymode = wlan_reg_get_max_phymode(v4[1], v17, 0, v16, v19, v20, v21, v22, v23, v24, v25);
      if ( v18 == max_phymode )
      {
        v35 = v71;
        v70 = a2;
      }
      else
      {
        v36 = max_phymode;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: reg_max_phymode %d, req_req_phymode %d",
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          "hdd_set_vdev_phy_mode",
          max_phymode,
          v18);
        v37 = csr_convert_from_reg_phy_mode(v36);
        v38 = v37;
        result = hdd_phymode_to_vendor_mode(v37, &v70);
        if ( (_DWORD)result )
          goto LABEL_13;
        a2 = v70;
        v35 = v38;
      }
      *(_DWORD *)(v2 + 3676) = a2;
      result = hdd_phymode_to_dot11_mode(v35, &v69);
      if ( !(_DWORD)result )
      {
        v47 = v70;
        is_6ghz_supported = wlan_reg_is_6ghz_supported(v6, v39, v40, v41, v42, v43, v44, v45, v46);
        result = hdd_vendor_mode_to_band(v47, v68, is_6ghz_supported & 1);
        if ( !(_DWORD)result )
        {
          wifi_standard = hdd_get_wifi_standard(v4, v69, v68[0]);
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: wifi_standard %d, vendor_phy_mode %d",
            v50,
            v51,
            v52,
            v53,
            v54,
            v55,
            v56,
            v57,
            "hdd_set_vdev_phy_mode",
            wifi_standard,
            v70);
          v58 = sme_cli_set_command(*(unsigned __int8 *)(v5 + 8), 190, wifi_standard, 1);
          if ( v58 )
          {
            v67 = v58;
            qdf_trace_msg(
              0x33u,
              2u,
              "%s: Failed to set standard version to fw",
              v59,
              v60,
              v61,
              v62,
              v63,
              v64,
              v65,
              v66,
              "hdd_set_vdev_phy_mode");
            result = v67;
          }
          else
          {
            ucfg_mlme_set_vdev_wifi_std(*v4, *(unsigned __int8 *)(v5 + 8), wifi_standard);
            result = 0;
          }
        }
      }
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

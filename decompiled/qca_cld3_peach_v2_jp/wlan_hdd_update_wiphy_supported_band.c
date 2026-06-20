__int64 __fastcall wlan_hdd_update_wiphy_supported_band(__int64 *a1)
{
  __int64 result; // x0
  __int64 v3; // x21
  unsigned int *v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w8
  unsigned int v14; // w8
  _BYTE v15[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  result = 0;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[3];
  v15[0] = 0;
  if ( (*(_BYTE *)(v3 + 1304) & 1) != 0 )
    goto LABEL_22;
  v4 = (unsigned int *)a1[13];
  if ( (hdd_is_2g_supported(a1) & 1) != 0 )
  {
    if ( !a1[14] )
      goto LABEL_21;
    *(_QWORD *)(v3 + 328) = &wlan_hdd_band_2_4_ghz;
    wlan_hdd_band_2_4_ghz = a1[14];
    qdf_mem_copy((void *)wlan_hdd_band_2_4_ghz, &hdd_channels_2_4_ghz, 0x380u);
    if ( (unsigned int)wlan_mlme_get_vht_for_24ghz(*a1, v15) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: could not get VHT capability",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_hdd_update_wiphy_supported_band");
    if ( v15[0] == 1 && (sme_is_feature_supported_by_fw(2) & 1) != 0 && *v4 <= 0xC && ((1 << *v4) & 0x1B01) != 0 )
      byte_1496C = 1;
  }
  if ( (hdd_is_5g_supported(a1) & 1) == 0 )
    goto LABEL_20;
  v13 = *v4 - 2;
  if ( v13 < 6 && ((0x2Bu >> v13) & 1) != 0 )
    goto LABEL_20;
  if ( !a1[15] )
  {
LABEL_21:
    result = 2;
    goto LABEL_22;
  }
  *(_QWORD *)(v3 + 336) = &wlan_hdd_band_5_ghz;
  wlan_hdd_band_5_ghz = a1[15];
  *(_DWORD *)(*(_QWORD *)(v3 + 336) + 20LL) = 28;
  qdf_mem_copy(**(void ***)(v3 + 336), &hdd_channels_5_ghz, 0x640u);
  qdf_mem_copy((void *)(**(_QWORD **)(v3 + 336) + 1600LL), &hdd_5dot9_ghz_ch, 0xC0u);
  v14 = *v4;
  if ( *v4 > 0xC || ((1 << v14) & 0x1B01) == 0 )
  {
    byte_14A64 = 0;
    v14 = *v4;
  }
  result = 0;
  if ( v14 <= 0xC && ((1 << v14) & 0x1801) != 0 )
  {
    hdd_init_6ghz(a1);
LABEL_20:
    result = 0;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall hdd_test_config_6ghz_security_test_mode(__int64 *a1, __int64 a2)
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
  __int64 result; // x0
  unsigned int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x0
  unsigned int v17; // w1
  _BYTE v18[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+8h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a1;
  v18[0] = 0;
  if ( (unsigned int)wlan_mlme_is_rf_test_mode_enabled(v4, v18) )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Get rf test mode failed",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "hdd_test_config_6ghz_security_test_mode");
    result = 4294967274LL;
  }
  else
  {
    if ( v18[0] == 1 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: rf test mode is enabled, ignore setting",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_test_config_6ghz_security_test_mode");
    }
    else
    {
      v14 = *(unsigned __int8 *)(a2 + 4);
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: safe mode setting %d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "hdd_test_config_6ghz_security_test_mode",
        v14);
      wlan_mlme_set_safe_mode_enable(*a1, v14 != 0);
      v15 = *a1;
      if ( v14 )
      {
        wlan_cm_set_check_6ghz_security(v15, 0);
        v16 = *a1;
        v17 = -1;
      }
      else
      {
        wlan_cm_set_check_6ghz_security(v15, 1);
        v16 = *a1;
        v17 = 436207293;
      }
      wlan_cm_set_6ghz_key_mgmt_mask(v16, v17);
    }
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

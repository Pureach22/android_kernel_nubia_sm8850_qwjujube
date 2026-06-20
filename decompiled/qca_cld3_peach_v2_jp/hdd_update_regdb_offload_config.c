__int64 __fastcall hdd_update_regdb_offload_config(__int64 *a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  _BYTE v20[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v20[0] = 0;
  wlan_mlme_get_ignore_fw_reg_offload_ind(v2, v20);
  if ( (v20[0] & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Ignore regdb offload Indication from FW",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "hdd_update_regdb_offload_config");
    result = ucfg_set_ignore_fw_reg_offload_ind(*a1, v11, v12, v13, v14, v15, v16, v17, v18);
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: regdb offload is based on firmware capability",
               v3,
               v4,
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               "hdd_update_regdb_offload_config");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall drv_cmd_set_roam_mode(__int64 a1, __int64 *a2, __int64 a3)
{
  unsigned int v5; // w0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w22
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x21
  __int64 result; // x0
  _BOOL4 v25; // w8
  __int64 v26; // x21
  bool v27[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27[0] = 1;
  v5 = kstrtou8(a3 + 12, 10, v27);
  if ( (v5 & 0x80000000) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: kstrtou8 failed range [%d - %d]",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_roam_mode",
      0,
      1);
    result = 4294967274LL;
  }
  else
  {
    v14 = v5;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: Received Command to Set Roam Mode = %d",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "drv_cmd_set_roam_mode",
      v27[0]);
    if ( (sme_roaming_in_progress(a2[2], *(unsigned __int8 *)(a1 + 8)) & 1) != 0 )
    {
      v23 = jiffies;
      if ( drv_cmd_set_roam_mode___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Roaming in progress for vdev %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "drv_cmd_set_roam_mode",
          *(unsigned __int8 *)(a1 + 8));
        drv_cmd_set_roam_mode___last_ticks = v23;
      }
      result = 4294967285LL;
    }
    else
    {
      v25 = v27[0];
      v26 = a2[2];
      v27[0] = !v27[0];
      if ( v25 )
      {
        sme_update_is_fast_roam_ini_feature_enabled(v26, *(unsigned __int8 *)(a1 + 8), 0);
        ucfg_mlme_set_roam_scan_offload_enabled(*a2, v27[0]);
      }
      else
      {
        ucfg_mlme_set_roam_scan_offload_enabled(*a2, 1);
        sme_update_is_fast_roam_ini_feature_enabled(v26, *(unsigned __int8 *)(a1 + 8), v27[0]);
      }
      result = v14;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall drv_cmd_set_ccx_mode(__int64 a1, __int64 *a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v8; // x20
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 result; // x0
  unsigned int v18; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v27; // w21
  unsigned int v28; // [xsp+0h] [xbp-10h] BYREF
  _BYTE v29[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+8h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v29[0] = 0;
  v28 = 0;
  hdd_get_pmkid_modes(a2, &v28);
  v8 = a2[2];
  if ( (ucfg_cm_get_is_ese_feature_enabled(*a2) & 1) != 0
    && (v28 & 1) != 0
    && (ucfg_cm_get_is_ft_feature_enabled(*a2) & 1) != 0 )
  {
    qdf_trace_msg(
      0x33u,
      3u,
      "%s: OKC/ESE/11R are supported simultaneously hence this operation is not permitted!",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "drv_cmd_set_ccx_mode");
    result = 0xFFFFFFFFLL;
  }
  else
  {
    v18 = kstrtou8(a3 + a4 + 1, 10, v29);
    if ( (v18 & 0x80000000) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: kstrtou8 failed range [%d - %d]",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "drv_cmd_set_ccx_mode",
        0,
        1);
      result = 4294967274LL;
    }
    else
    {
      v27 = v18;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: Received Command to change ese mode = %d",
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        v25,
        v26,
        "drv_cmd_set_ccx_mode",
        v29[0]);
      sme_update_is_ese_feature_enabled(v8, *(unsigned __int8 *)(a1 + 8), v29[0] != 0);
      result = v27;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

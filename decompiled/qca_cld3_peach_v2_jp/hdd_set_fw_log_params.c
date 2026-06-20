__int64 __fastcall hdd_set_fw_log_params(
        _QWORD *a1,
        unsigned __int8 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 result; // x0
  unsigned int v14; // w0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  _WORD v32[2]; // [xsp+0h] [xbp-10h] BYREF
  unsigned __int16 v33; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v34; // [xsp+8h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = a1[13];
  v33 = 0;
  v32[0] = 0;
  if ( *(_BYTE *)(v10 + 37) )
  {
    result = ucfg_fwol_get_enable_fw_log_type(*a1, v32);
    if ( !(_DWORD)result )
    {
      v14 = sme_cli_set_command(a2, 7, v32[0], 4);
      if ( v14 )
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Failed to enable FW log type ret %d",
          v15,
          v16,
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          "hdd_set_fw_log_params",
          v14);
      result = ucfg_fwol_get_enable_fw_log_level(*a1, &v33);
      if ( !(_DWORD)result )
      {
        v23 = sme_cli_set_command(a2, 1, v33, 4);
        if ( v23 )
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: Failed to enable FW log level ret %d",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "hdd_set_fw_log_params",
            v23);
        result = sme_enable_fw_module_log_level(a1[2], a2);
      }
    }
  }
  else
  {
    result = qdf_trace_msg(
               0x33u,
               8u,
               "%s: enable_fw_log not enabled in INI",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "hdd_set_fw_log_params");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

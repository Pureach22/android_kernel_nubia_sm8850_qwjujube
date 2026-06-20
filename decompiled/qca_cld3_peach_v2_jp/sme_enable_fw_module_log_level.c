__int64 __fastcall sme_enable_fw_module_log_level(__int64 a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w25
  __int64 v15; // x27
  unsigned __int8 i; // w26
  const char *v17; // x2
  unsigned __int8 *v18; // x8
  unsigned int v19; // w4
  unsigned int v20; // w5
  __int64 v22; // x0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  unsigned int v31; // w24
  __int64 v32; // x26
  unsigned __int8 j; // w25
  const char *v34; // x2
  unsigned __int8 *v35; // x8
  unsigned int v36; // w4
  unsigned int v37; // w5
  _BYTE v39[4]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v40[2]; // [xsp+10h] [xbp-10h] BYREF

  v40[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 21552);
  v40[0] = 0;
  v39[0] = 0;
  result = ucfg_fwol_get_enable_fw_module_log_level(v4, v40, v39);
  if ( !(_DWORD)result )
  {
    v14 = v39[0];
    if ( v39[0] )
    {
      v15 = v40[0];
      for ( i = 0; v14 > i; i += 2 )
      {
        v18 = (unsigned __int8 *)(v15 + i);
        v19 = *v18;
        v20 = v18[1];
        if ( v19 > 0x9D || v20 >= 7 )
        {
          v17 = "%s: Module id %d or dbglog level %d input value is more than max";
        }
        else
        {
          if ( !(unsigned int)wma_cli_set_command(a2, 6, v20 | (v19 << 16), 4) )
            continue;
          v17 = "%s: Failed to enable FW module log level %d ret %d";
        }
        qdf_trace_msg(0x34u, 2u, v17, v6, v7, v8, v9, v10, v11, v12, v13, "__sme_enable_fw_module_log_level");
      }
    }
    v22 = *(_QWORD *)(a1 + 21552);
    v39[0] = 0;
    result = ucfg_fwol_wow_get_enable_fw_module_log_level(v22, v40, v39);
    if ( !(_DWORD)result )
    {
      v31 = v39[0];
      if ( v39[0] )
      {
        v32 = v40[0];
        for ( j = 0; v31 > j; j += 2 )
        {
          v35 = (unsigned __int8 *)(v32 + j);
          v36 = *v35;
          v37 = v35[1];
          if ( v36 > 0x9D || v37 >= 7 )
          {
            v34 = "%s: Module id %d or dbglog level %d input value is more than max";
          }
          else
          {
            result = wma_cli_set_command(a2, 9, v37 | (v36 << 16), 4);
            if ( !(_DWORD)result )
              continue;
            v34 = "%s: Failed to enable FW module log level %d ret %d";
          }
          result = qdf_trace_msg(
                     0x34u,
                     2u,
                     v34,
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     v30,
                     "__sme_enable_fw_module_log_level");
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall hdd_set_pcie_params(__int64 *a1, unsigned __int8 a2, _DWORD *a3)
{
  __int64 v5; // x0
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w8
  _DWORD *v16; // x8
  int v17; // w9
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  _BYTE v26[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *a1;
  v26[0] = 0;
  result = ucfg_fwol_get_pcie_config(v5, v26);
  if ( !(_DWORD)result )
  {
    if ( curr_con_mode == 5 )
    {
      if ( !a2 )
      {
        v15 = v26[0];
        result = 0;
        *a3 = 229;
        a3[1] = v15;
        goto LABEL_8;
      }
    }
    else if ( a2 <= 7u )
    {
      v16 = &a3[2 * a2];
      v17 = v26[0];
      result = 0;
      *v16 = 229;
      v16[1] = v17;
      goto LABEL_8;
    }
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: Index:%d OOB to fill param",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "mlme_check_index_setparam",
      a2);
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: failed to set wmi_pdev_param_pcie_config",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "hdd_set_pcie_params");
    result = 16;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}

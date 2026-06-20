__int64 __fastcall cam_cpas_util_set_max_camnoc_axi_clk_rate(__int64 a1, __int64 a2)
{
  __int64 v4; // x23
  __int64 v5; // x26
  unsigned int v6; // w22
  unsigned int valid_clk_rate; // w0
  unsigned int v8; // w21
  const char *v9; // x5
  __int64 v10; // x4
  unsigned int v11; // w8
  unsigned int v12; // w9
  __int64 v13; // x1
  unsigned int v14; // w0
  __int64 *settings; // x0
  unsigned __int64 v17; // x0
  int v18; // w0
  int v19; // w0
  __int64 v20; // [xsp+8h] [xbp-18h] BYREF
  unsigned __int64 v21[2]; // [xsp+10h] [xbp-10h] BYREF

  v4 = a1 + 155648;
  v21[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a2 + 3296);
  v20 = 0;
  v21[0] = 0;
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_util_set_max_camnoc_axi_clk_rate",
      1426,
      "Finding max of hlos axi floor lvl: %d and hlos axi lvl: %d",
      *(_DWORD *)(a1 + 159436),
      *(_DWORD *)(a1 + 159440));
  if ( *(_DWORD *)(v4 + 3788) <= *(_DWORD *)(v4 + 3792) )
    v6 = *(_DWORD *)(v4 + 3792);
  else
    v6 = *(_DWORD *)(v4 + 3788);
  valid_clk_rate = cam_soc_util_get_valid_clk_rate(a2, v6, v21);
  if ( valid_clk_rate )
  {
    v8 = valid_clk_rate;
    v9 = "Failed in getting valid total clk rate to apply rc: %d";
    v10 = 1436;
  }
  else
  {
    v11 = *(_DWORD *)(v4 + 3788);
    v12 = *(_DWORD *)(v4 + 3808);
    if ( v11 <= v12 )
      v13 = v12;
    else
      v13 = v11;
    v14 = cam_soc_util_get_valid_clk_rate(a2, v13, &v20);
    if ( !v14 )
    {
      settings = cam_debug_get_settings();
      if ( settings )
      {
        v17 = settings[10];
        if ( v17 )
          v21[0] = cam_common_util_mul_then_div(v17, 1u, *(unsigned int *)(v5 + 1040));
      }
      if ( (debug_mdl & 4) != 0 && !debug_priority )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 4,
          4,
          "cam_cpas_util_set_max_camnoc_axi_clk_rate",
          1460,
          "Highest valid lvl: %d, applying corresponding rate %lld",
          v6,
          v21[0]);
      if ( (((__int64 (__fastcall *)(__int64))cam_is_crmb_supported)(a2) & 1) != 0 )
      {
        v18 = cam_soc_util_set_cesta_crmb_sw_client_clk_rate(a2, -1, *(_QWORD *)(v4 + 3800), v20);
        if ( v18 )
        {
          v8 = v18;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_util_set_max_camnoc_axi_clk_rate",
            1469,
            "Failed in setting camnoc axi clk RT[%lld], ICP/NRT[%lld], rc:%d",
            *(_QWORD *)(v4 + 3800),
            v20,
            v18);
          goto LABEL_15;
        }
      }
      else
      {
        v19 = cam_soc_util_set_src_clk_rate(a2, 0xFFFFFFFF, v21[0], 0);
        if ( v19 )
        {
          v8 = v19;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_util_set_max_camnoc_axi_clk_rate",
            1479,
            "Failed in setting camnoc axi clk applied rate:[%lld] rc:%d",
            v21[0],
            v19);
          goto LABEL_15;
        }
      }
      v8 = 0;
      *(_QWORD *)(a1 + 8152) = v21[0];
      goto LABEL_15;
    }
    v8 = v14;
    v9 = "Failed in getting valid NRT/ICP clk rate to apply rc: %d";
    v10 = 1448;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    4,
    1,
    "cam_cpas_util_set_max_camnoc_axi_clk_rate",
    v10,
    v9,
    v8);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return v8;
}

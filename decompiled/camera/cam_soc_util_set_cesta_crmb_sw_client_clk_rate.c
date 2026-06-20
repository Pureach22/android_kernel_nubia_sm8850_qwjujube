__int64 __fastcall cam_soc_util_set_cesta_crmb_sw_client_clk_rate(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x21
  const char *v5; // x5
  __int64 v6; // x6
  __int64 v7; // x4
  __int64 v8; // x19
  __int64 v10; // x24
  __int64 v11; // x20
  const char *v12; // x22
  __int64 v13; // x23
  int v14; // w27
  __int64 v15; // x0
  int v16; // w8
  int v17; // w24
  int v18; // w0
  __int64 v19; // x25
  __int64 v20; // [xsp+8h] [xbp-18h]

  if ( !a1 )
  {
    LODWORD(v4) = -1;
    goto LABEL_6;
  }
  v4 = *(unsigned int *)(a1 + 2796);
  if ( (unsigned int)v4 >= 0x20 )
  {
LABEL_6:
    v5 = "Invalid src_clk_idx: %d";
    v7 = 2298;
    v6 = (unsigned int)v4;
    goto LABEL_7;
  }
  if ( a2 >= 1 )
  {
    v5 = "Invalid client index for SW client idx: %d";
    v6 = (unsigned int)a2;
    v7 = 2304;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_cesta_crmb_sw_client_clk_rate",
      v7,
      v5,
      v6);
    LODWORD(v8) = -22;
    return (unsigned int)v8;
  }
  v10 = a1 + 872;
  v11 = a3;
  v12 = *(const char **)(a1 + 872 + 8 * v4);
  v13 = *(_QWORD *)(a1 + 8 * v4 + 1128);
  if ( a4 >= 1 )
  {
    v14 = a2;
    v15 = cam_wrapper_clk_round_rate(*(_QWORD *)(a1 + 8 * v4 + 1128), a4);
    v8 = v15;
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_set_cesta_crmb_sw_client_clk_rate",
        2315,
        "new IB rate %d",
        v15);
      if ( (v8 & 0x8000000000000000LL) == 0 )
      {
LABEL_13:
        v12 = *(const char **)(v10 + 8 * v4);
        a2 = v14;
        LODWORD(a3) = v11;
        v16 = debug_mdl;
        if ( (debug_mdl & 0x20000) == 0 )
          goto LABEL_17;
        goto LABEL_16;
      }
    }
    else if ( (v15 & 0x8000000000000000LL) == 0 )
    {
      goto LABEL_13;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_cesta_crmb_sw_client_clk_rate",
      2319,
      "round failed for clock %s rc = %d",
      v12,
      v8);
    return (unsigned int)v8;
  }
  v8 = 0;
  v16 = debug_mdl;
  if ( (debug_mdl & 0x20000) == 0 )
  {
LABEL_17:
    v17 = a2;
    goto LABEL_18;
  }
LABEL_16:
  if ( debug_priority )
    goto LABEL_17;
  v19 = v10;
  v17 = a2;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    *(_QWORD *)&v16 & 0x20000LL,
    4,
    "cam_soc_util_set_cesta_crmb_sw_client_clk_rate",
    2325,
    "Voting %s clk through crmb AB rate [%d] IB rate [%d]",
    v12,
    a3,
    v8);
  v12 = *(const char **)(v19 + 8 * v4);
LABEL_18:
  v18 = cam_wrapper_qcom_clk_crmb_set_rate(v13, 1, 0, 0, v11, v8, v12);
  if ( v18 )
  {
    v20 = v8;
    LODWORD(v8) = v18;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_cesta_crmb_sw_client_clk_rate",
      2335,
      "Failed in setting crmb AB/IB clk rate, client idx: %u pwr state: %u AB_rate: %llu IB_rate: %llu rc: %d",
      v17,
      0,
      v11,
      v20,
      v18);
  }
  else
  {
    LODWORD(v8) = 0;
  }
  return (unsigned int)v8;
}

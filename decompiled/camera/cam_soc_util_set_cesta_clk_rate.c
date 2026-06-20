__int64 __fastcall cam_soc_util_set_cesta_clk_rate(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        __int64 *a5,
        __int64 *a6)
{
  __int64 v6; // x22
  __int64 v7; // x26
  __int64 v10; // x23
  __int64 v14; // x9
  __int64 v15; // x26
  const char *v16; // x6
  unsigned int v17; // w9
  unsigned int v18; // w0
  unsigned int v19; // w21
  __int64 result; // x0
  unsigned int v21; // w0
  __int64 v22; // x5
  __int64 v23; // x6
  int v24; // w8
  __int64 v25; // x12
  const char *v26; // x6
  __int64 v27; // x1
  unsigned int v28; // w9
  unsigned int v29; // w0
  unsigned int v30; // w20
  unsigned int v31; // w0
  __int64 v32; // x26
  const void *v33; // x23
  __int64 v34; // x27
  unsigned int v35; // w0
  __int64 v36; // x3
  __int64 v37; // x4
  __int64 v38; // x5
  __int64 v39; // x6
  const char *v40; // x5
  unsigned int v41; // w7
  __int64 v42; // x4
  __int64 v43; // x6
  unsigned int v44; // w0
  unsigned int v45; // w23
  const char *v46; // x6
  __int64 v47; // x26
  __int64 v48; // x23
  __int64 v49; // x23
  __int64 v50; // [xsp+28h] [xbp-28h]
  __int64 v51; // [xsp+34h] [xbp-1Ch] BYREF
  int v52; // [xsp+3Ch] [xbp-14h]
  unsigned int v53; // [xsp+40h] [xbp-10h]
  int v54; // [xsp+44h] [xbp-Ch]
  __int64 v55; // [xsp+48h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    LODWORD(v6) = -1;
    goto LABEL_14;
  }
  v6 = *(unsigned int *)(a1 + 2796);
  if ( (unsigned int)v6 >= 0x20 )
  {
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_cesta_clk_rate",
      707,
      "Invalid src_clk_idx: %d",
      v6);
    result = 4294967274LL;
    goto LABEL_45;
  }
  v7 = a1 + 8 * v6;
  v10 = *(_QWORD *)(v7 + 1128);
  if ( skip_mmrm_set_rate || !*(_QWORD *)(a1 + 3192) )
    goto LABEL_4;
  v24 = debug_priority;
  v25 = a1 + 872;
  v26 = *(const char **)(a1 + 872 + 8 * v6);
  v27 = debug_mdl & 0x20000;
  v28 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 17);
  if ( *(_BYTE *)(a1 + 3201) == 1 )
  {
    if ( v28 )
    {
      v50 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v27,
        4,
        "cam_is_crmb_supported",
        227,
        "CRMB is supported for clk %s",
        v26);
      a1 = v50;
    }
LABEL_4:
    if ( (debug_mdl & 0x20000) != 0 && !debug_priority )
    {
      v46 = *(const char **)(v7 + 872);
      v47 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x20000,
        4,
        "cam_soc_util_set_cesta_clk_rate",
        745,
        "%s Requested clk rate [high low]: [%llu %llu] cesta_client_idx: %d",
        v46,
        a3,
        a4,
        a2);
      a1 = v47;
    }
    v14 = *(unsigned int *)(a1 + 2796);
    if ( (unsigned int)v14 >= 0x20 )
    {
      __break(0x5512u);
      JUMPOUT(0x10EDF4);
    }
    v15 = a1 + 872;
    v16 = *(const char **)(a1 + 872 + 8 * v14);
    v17 = (debug_priority == 0) & ((unsigned int)debug_mdl >> 17);
    if ( *(_BYTE *)(a1 + 3201) == 1 )
    {
      if ( v17 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_is_crmb_supported",
          227,
          "CRMB is supported for clk %s",
          v16);
      v18 = cam_wrapper_qcom_clk_crmb_set_rate(v10, 0, a2, 1, a3, 0, *(_QWORD *)(v15 + 8 * v6));
      if ( v18 )
      {
        v19 = v18;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, unsigned int))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_set_cesta_clk_rate",
          757,
          "Failed in setting cesta crm_B high clk rate, client idx: %u pwr state: %u clk_val: %llu rc: %d",
          a2,
          1,
          a3,
          v18);
LABEL_19:
        result = v19;
        goto LABEL_45;
      }
      v29 = cam_wrapper_qcom_clk_crmb_set_rate(v10, 0, a2, 0, a4, 0, *(_QWORD *)(v15 + 8 * v6));
      if ( v29 )
      {
        v30 = v29;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, unsigned int))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_set_cesta_clk_rate",
          767,
          "Failed in setting cesta crm_B low clk rate, client idx: %u pwr state: %u clk_val: %llu rc: %d",
          a2,
          0,
          a4,
          v29);
LABEL_28:
        result = v30;
        goto LABEL_45;
      }
    }
    else
    {
      if ( v17 )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          debug_mdl & 0x20000,
          4,
          "cam_is_crmb_supported",
          230,
          "CRMB is NOT supported for clk %s",
          v16);
      v21 = cam_wrapper_qcom_clk_crm_set_rate(v10, a2, 1, a3, *(_QWORD *)(v15 + 8 * v6), a6, v16);
      if ( v21 )
      {
        v19 = v21;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, __int64, __int64, unsigned int))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_set_cesta_clk_rate",
          779,
          "Failed in setting cesta high clk rate, client idx: %u pwr state: %u clk_val: %llu rc: %d",
          a2,
          1,
          a3,
          v21);
        goto LABEL_19;
      }
      v31 = cam_wrapper_qcom_clk_crm_set_rate(v10, a2, 0, a4, *(_QWORD *)(v15 + 8 * v6), v22, v23);
      if ( v31 )
      {
        v30 = v31;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, __int64, unsigned int))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_soc_util_set_cesta_clk_rate",
          789,
          "Failed in setting cesta low clk rate, client idx: %u pwr state: %u clk_val: %llu rc: %d",
          a2,
          0,
          a4,
          v31);
        goto LABEL_28;
      }
    }
    goto LABEL_41;
  }
  v32 = a1 + 872;
  if ( v28 )
  {
    v49 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v27,
      4,
      "cam_is_crmb_supported",
      230,
      "CRMB is NOT supported for clk %s",
      v26);
    v24 = debug_priority;
    v25 = v32;
    a1 = v49;
    v27 = debug_mdl & 0x20000;
    if ( (debug_mdl & 0x20000) == 0 )
      goto LABEL_33;
  }
  else if ( !v27 )
  {
    goto LABEL_33;
  }
  if ( !v24 )
  {
    v48 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v27,
      4,
      "cam_soc_util_set_cesta_clk_rate",
      725,
      "cesta mmrm hw client: set %s, high-rate %lld low-rate %lld",
      *(const char **)(v25 + 8 * v6),
      a3,
      a4);
    v24 = debug_priority;
    a1 = v48;
    v27 = debug_mdl & 0x20000;
  }
LABEL_33:
  v33 = *(const void **)(a1 + 3192);
  v34 = a1;
  v52 = 1;
  v53 = a2;
  v51 = 1;
  v54 = 1;
  if ( v27 && !v24 )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v27,
      4,
      "cam_soc_util_set_hw_client_rate_through_mmrm",
      820,
      "hw client mmrm=%pK, high_val %ld, low_val %ld, num_blocks=%d, pwr_state: %u, client_idx: %d",
      v33,
      a3,
      a4,
      1,
      1,
      a2);
  v35 = mmrm_client_set_value(v33, &v51, a3, a4, a5, a6, v26);
  if ( v35 )
  {
    v40 = "Set high rate failed rate %ld rc %d";
    v41 = v35;
    v42 = 826;
    v43 = a3;
LABEL_40:
    v45 = v41;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_hw_client_rate_through_mmrm",
      v42,
      v40,
      v43);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x20000,
      1,
      "cam_soc_util_set_cesta_clk_rate",
      737,
      "set_hw_client_rate through mmrm failed on %s clk_id %d low_val %llu high_val %llu client idx=%d",
      *(const char **)(v32 + 8 * v6),
      *(_DWORD *)(v34 + 4 * v6 + 2664),
      a4,
      a3,
      a2);
    result = v45;
    goto LABEL_45;
  }
  v54 = 0;
  v44 = mmrm_client_set_value(v33, &v51, a4, v36, v37, v38, v39);
  if ( v44 )
  {
    v40 = "Set low rate failed rate %ld rc %d";
    v41 = v44;
    v42 = 836;
    v43 = a4;
    goto LABEL_40;
  }
LABEL_41:
  if ( a5 )
    *a5 = a3;
  result = 0;
  if ( a6 )
    *a6 = a4;
LABEL_45:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall cam_cpas_vmrm_callback_handler(__int64 a1, __int64 a2)
{
  __int64 v3; // x23
  int v4; // w6
  __int64 v5; // x21
  __int64 v6; // x20
  __int64 v7; // x19
  __int64 v8; // x20
  int v9; // w22
  int v10; // w22
  unsigned __int64 v11; // x20
  __int64 v12; // x22
  unsigned int v13; // w19
  unsigned int updated; // w21
  __int64 v15; // x8
  unsigned int v16; // w19
  unsigned int v17; // w21
  __int64 v18; // x3
  __int64 v19; // x20
  __int64 v20; // x4
  unsigned int clk_level; // w0
  __int64 v22; // x0
  unsigned int valid_clk_rate; // w0
  const char *v24; // x5
  __int64 v25; // x4
  __int64 v26; // x8
  __int64 v27; // x8
  __int64 v28; // x20
  int v29; // w19
  __int64 v30; // x9
  __int64 v31; // x8
  unsigned int v38; // [xsp+20h] [xbp-40h]
  unsigned int v39; // [xsp+24h] [xbp-3Ch]
  unsigned __int64 v40; // [xsp+28h] [xbp-38h] BYREF
  int v41; // [xsp+34h] [xbp-2Ch] BYREF
  char s1[8]; // [xsp+38h] [xbp-28h] BYREF
  __int64 v43; // [xsp+40h] [xbp-20h]
  __int64 v44; // [xsp+48h] [xbp-18h]
  __int64 v45; // [xsp+50h] [xbp-10h]
  __int64 v46; // [xsp+58h] [xbp-8h]
  __int64 vars0; // [xsp+60h] [xbp+0h] BYREF

  _X29 = &vars0;
  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 112);
  v4 = *(_DWORD *)(a2 + 8);
  v41 = 0;
  v5 = *(_QWORD *)(v3 + 3680);
  v40 = 0;
  v44 = 0;
  v45 = 0;
  *(_QWORD *)s1 = 0;
  v43 = 0;
  if ( (debug_mdl & 4) == 0 || debug_priority )
  {
    if ( v4 > 5 )
      goto LABEL_4;
LABEL_68:
    if ( v4 == 4 )
    {
      updated = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD, _QWORD))cam_soc_util_enable_platform_resource)(
                  v3 + 96,
                  0xFFFFFFFFLL,
                  1,
                  *(unsigned int *)(v3 + 2968),
                  0);
      if ( !updated )
        goto LABEL_91;
      v24 = "cpas soc enable resource failed %d";
      v25 = 2099;
      goto LABEL_74;
    }
    if ( v4 != 5 )
      goto LABEL_75;
    updated = ((__int64 (__fastcall *)(__int64, __int64, __int64, _QWORD))cam_soc_util_disable_platform_resource)(
                v3 + 96,
                0xFFFFFFFFLL,
                1,
                0);
    if ( updated )
    {
      v24 = "cpas soc disable resource failed %d";
      v25 = 2106;
      goto LABEL_74;
    }
LABEL_91:
    _ReadStatusReg(SP_EL0);
    return updated;
  }
  v28 = a2;
  v29 = v4;
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 4,
    4,
    "cam_cpas_vmrm_callback_handler",
    2092,
    "msg type %d",
    v4);
  v4 = v29;
  a2 = v28;
  if ( v29 <= 5 )
    goto LABEL_68;
LABEL_4:
  if ( v4 == 6 )
  {
    v11 = *(_QWORD *)(a2 + 40);
    v12 = *(_QWORD *)(a2 + 48);
    v13 = *(_DWORD *)(a2 + 32);
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      v30 = *(unsigned int *)(v3 + 2892);
      if ( (unsigned int)v30 >= 0x20 )
        goto LABEL_92;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_vmrm_callback_handler",
        2117,
        "set %s, cesta_client_idx %d rate [%ld %ld] dev_name %s",
        *(const char **)(v3 + 8 * v30 + 968),
        v13,
        v11,
        v12,
        *(const char **)(v3 + 120));
    }
    updated = cam_soc_util_set_src_clk_rate(v3 + 96, v13, v11, v12);
    if ( updated )
    {
      v15 = *(unsigned int *)(v3 + 2892);
      if ( (unsigned int)v15 > 0x1F )
        goto LABEL_92;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_vmrm_callback_handler",
        2124,
        "set %s, cesta_client_idx %d rate [%ld %ld] dev_name %s",
        *(const char **)(v3 + 8 * v15 + 968),
        v13,
        v11,
        v12,
        *(const char **)(v3 + 120));
    }
    goto LABEL_91;
  }
  if ( v4 == 7 )
  {
    v17 = *(_DWORD *)(a2 + 32);
    v16 = *(_DWORD *)(a2 + 36);
    v18 = *(unsigned int *)(a2 + 40);
    v19 = *(_QWORD *)(a2 + 48);
    v20 = *(unsigned __int8 *)(a2 + 44);
    if ( (debug_mdl & 4) != 0 && !debug_priority )
    {
      v31 = *(unsigned int *)(v3 + 2892);
      if ( (unsigned int)v31 > 0x1F )
        goto LABEL_92;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_vmrm_callback_handler",
        2138,
        "set %s, cesta_client_idx %d level [%d %d] rate %ld dev_name %s do_not_set_src_clk %d",
        *(const char **)(v3 + 8 * v31 + 968),
        v17,
        v16,
        v18,
        v19,
        *(const char **)(v3 + 120),
        v18);
      v18 = v38;
      v20 = v39;
      if ( v19 )
        goto LABEL_46;
    }
    else if ( v19 )
    {
LABEL_46:
      clk_level = cam_soc_util_get_clk_level((_BYTE *)(v3 + 96), v19, *(_DWORD *)(v3 + 2892), &v41);
      if ( clk_level )
      {
        updated = clk_level;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          4,
          1,
          "cam_cpas_vmrm_callback_handler",
          2146,
          "failed to get clk lvl: %d, src clk idx: %d, hlos clk rate %lld",
          clk_level,
          *(_DWORD *)(v3 + 2892),
          v19);
        goto LABEL_91;
      }
      if ( (int)v16 <= v41 )
        v16 = v41;
      valid_clk_rate = cam_soc_util_get_valid_clk_rate(v3 + 96, v16, &v40);
      if ( !valid_clk_rate )
      {
        if ( (debug_mdl & 4) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 4,
            4,
            "cam_cpas_vmrm_callback_handler",
            2161,
            "Highest valid lvl: %d, applying corresponding rate %lld",
            v16,
            v40);
        updated = cam_soc_util_set_src_clk_rate(v3 + 96, 0xFFFFFFFF, v40, 0);
        if ( updated )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            4,
            1,
            "cam_cpas_vmrm_callback_handler",
            2167,
            "Failed in setting camnoc axi clk applied rate:[%lld] rc:%d",
            v40,
            updated);
        goto LABEL_91;
      }
      updated = valid_clk_rate;
      v24 = "Failed in getting valid clk rate to apply rc: %d";
      v25 = 2155;
LABEL_74:
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_vmrm_callback_handler",
        v25,
        v24,
        updated);
      goto LABEL_91;
    }
    updated = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, __int64, __int64))cam_soc_util_set_clk_rate_level)(
                v3 + 96,
                v17,
                v16,
                v18,
                v20);
    if ( updated )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_vmrm_callback_handler",
        2176,
        "Failed in scaling clock rate level %d for cpas",
        v16);
    goto LABEL_91;
  }
  if ( v4 != 8 )
  {
LABEL_75:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      1,
      "cam_cpas_vmrm_callback_handler",
      2227,
      "Invalid msg type:%d",
      v4);
LABEL_90:
    updated = -22;
    goto LABEL_91;
  }
  v6 = a2;
  scnprintf(s1, 32, "%s", (const char *)(a2 + 32));
  v7 = *(_QWORD *)(v6 + 64);
  v8 = *(_QWORD *)(v6 + 72);
  if ( (debug_mdl & 4) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 4,
      4,
      "cam_cpas_vmrm_callback_handler",
      2188,
      "name %s, ab %llu ib %llu",
      s1,
      v7,
      v8);
  if ( !strcmp(s1, *(const char **)(v5 + 2920)) )
  {
    v22 = *(_QWORD *)(v5 + 3088);
    if ( v22 )
      goto LABEL_49;
    goto LABEL_89;
  }
  v9 = *(_DWORD *)(v5 + 2780);
  if ( !v9 )
    goto LABEL_24;
  if ( !strcmp(s1, *(const char **)(v5 + 3168)) )
  {
    v26 = v5 + 3104;
    goto LABEL_88;
  }
  if ( v9 == 1 )
    goto LABEL_24;
  if ( !strcmp(s1, *(const char **)(v5 + 3576)) )
  {
    v26 = v5 + 3512;
    goto LABEL_88;
  }
  if ( v9 == 2 )
    goto LABEL_24;
  if ( !strcmp(s1, *(const char **)(v5 + 3984)) )
  {
    v26 = v5 + 3920;
    goto LABEL_88;
  }
  if ( v9 == 3 )
    goto LABEL_24;
  if ( !strcmp(s1, *(const char **)(v5 + 4392)) )
  {
    v27 = 4328;
    goto LABEL_87;
  }
  if ( v9 == 4 )
    goto LABEL_24;
  if ( !strcmp(s1, *(const char **)(v5 + 4800)) )
  {
    v27 = 4736;
    goto LABEL_87;
  }
  if ( v9 == 5 )
    goto LABEL_24;
  if ( !strcmp(s1, *(const char **)(v5 + 5208)) )
  {
    v27 = 5144;
    goto LABEL_87;
  }
  if ( v9 == 6 )
  {
LABEL_24:
    v10 = *(_DWORD *)(v5 + 2784);
    if ( !v10 )
      goto LABEL_89;
    if ( !strcmp(s1, *(const char **)(v5 + 5616)) )
    {
      v27 = 5552;
    }
    else
    {
      if ( v10 == 1 )
        goto LABEL_89;
      if ( !strcmp(s1, *(const char **)(v5 + 6024)) )
      {
        v27 = 5960;
      }
      else
      {
        if ( v10 == 2 )
          goto LABEL_89;
        if ( !strcmp(s1, *(const char **)(v5 + 6432)) )
        {
          v27 = 6368;
        }
        else
        {
          if ( v10 == 3 )
            goto LABEL_89;
          if ( !strcmp(s1, *(const char **)(v5 + 6840)) )
          {
            v27 = 6776;
          }
          else
          {
            if ( v10 == 4 )
              goto LABEL_89;
            if ( strcmp(s1, *(const char **)(v5 + 7248)) )
            {
              if ( v10 != 5 )
              {
                if ( strcmp(s1, *(const char **)(v5 + 7656)) )
                {
                  if ( v10 != 6 )
                    goto LABEL_92;
                  goto LABEL_89;
                }
                v27 = 7592;
                goto LABEL_87;
              }
LABEL_89:
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                4,
                1,
                "cam_cpas_vmrm_callback_handler",
                2215,
                "Invalid bus client name %s",
                s1);
              goto LABEL_90;
            }
            v27 = 7184;
          }
        }
      }
    }
LABEL_87:
    v26 = v5 + v27;
LABEL_88:
    v22 = *(_QWORD *)(v26 + 232);
    if ( !v22 )
      goto LABEL_89;
LABEL_49:
    updated = cam_soc_bus_client_update_bw(v22, v7, v8, 0);
    if ( updated )
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        4,
        1,
        "cam_cpas_vmrm_callback_handler",
        2222,
        "bus client %s ab %llu ib %llu update bw failed %d",
        s1,
        v7,
        v8,
        updated);
    goto LABEL_91;
  }
LABEL_92:
  __break(0x5512u);
  __asm { SUBG            X24, X29, #0x3B0, #7 }
  return cam_cpas_axi_util_path_type_to_string();
}

__int64 __fastcall dsi_panel_parse_bl_config(const char **a1)
{
  const char *v2; // x0
  bool v3; // zf
  const char *v4; // x9
  const char *v5; // x0
  const char *v6; // x1
  const char *v7; // x0
  long double v8; // q0
  const char *v9; // x20
  int v10; // w8
  const char *v11; // x9
  const char *v12; // x0
  const char *v13; // x0
  long double v14; // q0
  const char *v15; // x20
  int v16; // w8
  const char *v17; // x0
  const char *v18; // x8
  long double v19; // q0
  int v20; // w8
  const char *v21; // x9
  const char *v22; // x0
  long double v23; // q0
  int v24; // w8
  const char *v25; // x9
  const char *v26; // x0
  long double v27; // q0
  int v28; // w8
  const char *v29; // x9
  const char *v30; // x0
  long double v31; // q0
  int v32; // w8
  const char *v33; // x9
  const char *v34; // x0
  char v35; // w0
  const char *v36; // x8
  char v37; // w9
  const char *v38; // x0
  const char *v39; // x0
  const char *v40; // x20
  const char *v41; // x8
  const char *v42; // x0
  int v43; // w0
  unsigned int v44; // w20
  __int64 result; // x0
  const char *v46; // x8
  const char *v47; // x0
  int v48; // w20
  int v49; // [xsp+0h] [xbp-10h] BYREF
  int v50; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+8h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[1];
  v49 = 0;
  v3 = strcmp(v2, "primary") == 0;
  v4 = a1[229];
  v5 = a1[227];
  if ( v3 )
    v6 = "qcom,mdss-dsi-bl-pmic-control-type";
  else
    v6 = "qcom,mdss-dsi-sec-bl-pmic-control-type";
  if ( *((_DWORD *)v4 - 1) != -1612502898 )
    __break(0x8229u);
  v7 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v4)(v5, v6, 0);
  if ( !v7 )
    goto LABEL_13;
  v9 = v7;
  if ( !strcmp(v7, "bl_ctrl_pwm") )
  {
    v10 = 0;
  }
  else if ( !strcmp(v9, "bl_ctrl_wled") )
  {
    v10 = 1;
  }
  else if ( !strcmp(v9, "bl_ctrl_dcs") )
  {
    v10 = 2;
  }
  else if ( !strcmp(v9, "bl_ctrl_external") )
  {
    v10 = 3;
  }
  else
  {
    if ( strcmp(v9, "bl_ctrl_i2c") )
    {
      *(double *)&v8 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] bl-pmic-control-type unknown-%s\n", *a1, v9);
LABEL_13:
      v10 = 5;
      goto LABEL_19;
    }
    v10 = 4;
  }
LABEL_19:
  v11 = a1[229];
  v12 = a1[227];
  *((_DWORD *)a1 + 368) = v10;
  if ( *((_DWORD *)v11 - 1) != -1612502898 )
    __break(0x8229u);
  v13 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v11)(
                        v12,
                        "qcom,bl-update-flag",
                        0,
                        v8);
  if ( !v13 )
    goto LABEL_24;
  v15 = v13;
  if ( strcmp(v13, "delay_until_first_frame") )
  {
    *(double *)&v14 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] No valid bl-update-flag: %s\n", *a1, v15);
LABEL_24:
    v16 = 1;
    goto LABEL_26;
  }
  v16 = 0;
LABEL_26:
  *((_DWORD *)a1 + 369) = v16;
  v17 = a1[227];
  *(const char **)((char *)a1 + 1500) = (const char *)0xFFFF00000400LL;
  v18 = a1[231];
  a1[191] = (const char *)0x100000000LL;
  *((_BYTE *)a1 + 1536) = 0;
  if ( *((_DWORD *)v18 - 1) != 309187163 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v18)(
         v17,
         "qcom,mdss-dsi-bl-min-level",
         &v49,
         v14) )
  {
    *(double *)&v19 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] bl-min-level unspecified, defaulting to zero\n", *a1);
    v20 = 0;
  }
  else
  {
    v20 = v49;
  }
  v21 = a1[231];
  v22 = a1[227];
  *((_DWORD *)a1 + 370) = v20;
  if ( *((_DWORD *)v21 - 1) != 309187163 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v21)(
         v22,
         "qcom,mdss-dsi-bl-max-level",
         &v49,
         v19) )
  {
    *(double *)&v23 = _drm_dev_dbg(
                        0,
                        0,
                        0,
                        "[msm-dsi-debug]: [%s] bl-max-level unspecified, defaulting to max level\n",
                        *a1);
    v24 = 4096;
  }
  else
  {
    v24 = v49;
  }
  v25 = a1[231];
  v26 = a1[227];
  *((_DWORD *)a1 + 371) = v24;
  if ( *((_DWORD *)v25 - 1) != 309187163 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v25)(
         v26,
         "qcom,mdss-brightness-max-level",
         &v49,
         v23) )
  {
    *(double *)&v27 = _drm_dev_dbg(
                        0,
                        0,
                        0,
                        "[msm-dsi-debug]: [%s] brigheness-max-level unspecified, defaulting to 255\n",
                        *a1);
    v28 = 255;
  }
  else
  {
    v28 = v49;
  }
  v29 = a1[231];
  v30 = a1[227];
  *((_DWORD *)a1 + 372) = v28;
  if ( *((_DWORD *)v29 - 1) != 309187163 )
    __break(0x8229u);
  if ( ((unsigned int (__fastcall *)(const char *, const char *, int *, long double))v29)(
         v30,
         "qcom,mdss-dsi-bl-ctrl-dcs-subtype",
         &v49,
         v27) )
  {
    *(double *)&v31 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] bl-ctrl-dcs-subtype, defautling to zero\n", *a1);
    v32 = 0;
  }
  else
  {
    v32 = v49;
  }
  v33 = a1[233];
  v34 = a1[227];
  *((_DWORD *)a1 + 377) = v32;
  if ( *((_DWORD *)v33 - 1) != -834495637 )
    __break(0x8229u);
  v35 = ((__int64 (__fastcall *)(const char *, const char *, long double))v33)(
          v34,
          "qcom,mdss-dsi-bl-inverted-dbv",
          v31);
  v36 = a1[229];
  v37 = v35 & 1;
  v38 = a1[227];
  *((_BYTE *)a1 + 1512) = v37;
  if ( *((_DWORD *)v36 - 1) != -1612502898 )
    __break(0x8228u);
  v39 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD))v36)(v38, "qcom,bl-dsc-cmd-state", 0);
  if ( !v39 || (v40 = v39, !strcmp(v39, "dsi_hs_mode")) )
  {
    *((_BYTE *)a1 + 1576) = 0;
    if ( *((_DWORD *)a1 + 368) )
      goto LABEL_63;
  }
  else if ( !strcmp(v40, "dsi_lp_mode") )
  {
    *((_BYTE *)a1 + 1576) = 1;
    if ( *((_DWORD *)a1 + 368) )
      goto LABEL_63;
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: bl-dsc-cmd-state command state unrecognized-%s\n", v40);
    if ( *((_DWORD *)a1 + 368) )
      goto LABEL_63;
  }
  v41 = a1[231];
  v42 = a1[227];
  v50 = 0;
  if ( *((_DWORD *)v41 - 1) != 309187163 )
    __break(0x8228u);
  v43 = ((__int64 (__fastcall *)(const char *, const char *, int *))v41)(v42, "qcom,bl-pmic-pwm-period-usecs", &v50);
  if ( v43 )
  {
    v44 = v43;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: bl-pmic-pwm-period-usecs is not defined, rc=%d\n", v43);
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] failed to parse pwm config, rc=%d\n", *a1, v44);
    result = v44;
    goto LABEL_69;
  }
  *((_DWORD *)a1 + 389) = v50;
LABEL_63:
  v46 = a1[243];
  v47 = a1[227];
  if ( *((_DWORD *)v46 - 1) != -222936480 )
    __break(0x8228u);
  v48 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD))v46)(v47, "qcom,platform-bklight-en-gpio", 0);
  result = 0;
  *((_DWORD *)a1 + 385) = v48;
  if ( v48 < 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] failed to get bklt gpio, rc=%d\n", *a1, 0);
    if ( v48 == -517 )
      result = 4294966779LL;
    else
      result = 0;
  }
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall dsi_panel_parse_gpios(const char **a1)
{
  int v2; // w0
  bool v3; // zf
  const char *v4; // x1
  const char *v5; // x9
  const char *v6; // x0
  const char *v7; // x20
  const char *v8; // x21
  int v9; // w0
  long double v10; // q0
  const char *v11; // x8
  const char *v12; // x0
  int v13; // w0
  long double v14; // q0
  long double v15; // q0
  const char *v16; // x8
  const char *v17; // x0
  int v18; // w0
  const char *v19; // x8
  const char *v20; // x0
  int v21; // w0
  const char *v22; // x8
  const char *v23; // x0
  unsigned int v24; // w0
  int v25; // w4
  long double v26; // q0
  const char *v27; // x8
  const char *v28; // x0
  const char *v29; // x0
  const char *v30; // x20
  int v31; // w8
  int v32; // w8
  const char *v33; // x8
  const char *v34; // x0
  int v35; // w0
  unsigned int v36; // w22
  const char *v37; // x8
  const char *v38; // x0
  unsigned int v39; // w21
  __int64 v40; // x20
  const char *v41; // x8
  const char *v42; // x0
  __int64 v43; // x3
  unsigned int v44; // w0
  unsigned int v46; // w23
  unsigned __int64 v47; // x22
  __int64 v48; // x0
  unsigned int v49; // w8
  unsigned int v50; // w9
  unsigned int v51; // w8
  unsigned __int64 v52; // x13
  unsigned __int64 v53; // x11
  unsigned __int64 v54; // x12
  unsigned __int64 v55; // x14
  unsigned int v56; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v57; // [xsp+8h] [xbp-8h]

  v57 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = strcmp(a1[1], "primary");
  v3 = v2 == 0;
  if ( v2 )
    v4 = "qcom,platform-sec-reset-gpio";
  else
    v4 = "qcom,platform-reset-gpio";
  v5 = a1[243];
  v6 = a1[227];
  if ( v3 )
    v7 = "qcom,panel-mode-gpio";
  else
    v7 = "qcom,panel-sec-mode-gpio";
  if ( v3 )
    v8 = "qcom,platform-oled-en-gpio";
  else
    v8 = "qcom,platform-sec-oled-en-gpio";
  if ( *((_DWORD *)v5 - 1) != -222936480 )
    __break(0x8229u);
  v9 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD))v5)(v6, v4, 0);
  *((_DWORD *)a1 + 399) = v9;
  if ( v9 < 0 && (*((_BYTE *)a1 + 1274) & 1) == 0 )
    *(double *)&v10 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] reset gpio not set, rc=%d\n", *a1, v9);
  v11 = a1[243];
  v12 = a1[227];
  if ( *((_DWORD *)v11 - 1) != -222936480 )
    __break(0x8228u);
  v13 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v11)(
          v12,
          "qcom,5v-boost-gpio",
          0,
          v10);
  *((_DWORD *)a1 + 400) = v13;
  if ( v13 < 0 )
  {
    *(double *)&v15 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] 5v-boot-gpio is not set, rc=%d\n", *a1, 0);
    v16 = a1[243];
    v17 = a1[227];
    if ( *((_DWORD *)v16 - 1) != -222936480 )
      __break(0x8228u);
    v18 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v16)(
            v17,
            "qcom,platform-en-gpio",
            0,
            v15);
    *((_DWORD *)a1 + 400) = v18;
    if ( v18 < 0 )
      *(double *)&v14 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] platform-en-gpio is not set, rc=%d\n", *a1, 0);
  }
  if ( *((_BYTE *)a1 + 2232) == 1 )
  {
    v19 = a1[243];
    v20 = a1[227];
    if ( *((_DWORD *)v19 - 1) != -222936480 )
      __break(0x8228u);
    v21 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v19)(v20, v8, 0, v14);
    *((_DWORD *)a1 + 401) = v21;
    if ( v21 < 0 )
      *(double *)&v14 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: [%s] oled-en-gpio is not set\n", *a1);
  }
  v22 = a1[243];
  v23 = a1[227];
  if ( *((_DWORD *)v22 - 1) != -222936480 )
    __break(0x8228u);
  v24 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v22)(v23, v7, 0, v14);
  v25 = v24;
  *((_DWORD *)a1 + 402) = v24;
  if ( (v24 & 0x80000000) != 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: mode gpio not specified\n", v24);
    v25 = *((_DWORD *)a1 + 402);
  }
  *(double *)&v26 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: mode gpio=%d\n", v25);
  v27 = a1[229];
  v28 = a1[227];
  if ( *((_DWORD *)v27 - 1) != -1612502898 )
    __break(0x8228u);
  v29 = (const char *)((__int64 (__fastcall *)(const char *, const char *, _QWORD, long double))v27)(
                        v28,
                        "qcom,mdss-dsi-mode-sel-gpio-state",
                        0,
                        v26);
  if ( !v29 )
    goto LABEL_39;
  v30 = v29;
  if ( !strcmp(v29, "single_port") )
  {
    v31 = 2;
    goto LABEL_42;
  }
  if ( !strcmp(v30, "dual_port") )
  {
LABEL_39:
    v31 = 1;
  }
  else if ( !strcmp(v30, "high") )
  {
    v31 = 3;
  }
  else
  {
    if ( strcmp(v30, "low") )
      goto LABEL_43;
    v31 = 4;
  }
LABEL_42:
  *((_DWORD *)a1 + 403) = v31;
LABEL_43:
  v32 = *((unsigned __int8 *)a1 + 1274);
  v56 = 0;
  if ( v32 != 1 )
  {
    v37 = a1[229];
    v38 = a1[227];
    if ( *((_DWORD *)v37 - 1) != -1612502898 )
      __break(0x8228u);
    if ( ((__int64 (__fastcall *)(const char *, const char *, unsigned int *))v37)(
           v38,
           "qcom,mdss-dsi-reset-sequence",
           &v56) )
    {
      if ( (v56 & 1) == 0 )
      {
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: RESET SEQ LENGTH = %d\n", v56);
        v39 = v56 & 0xFFFFFFFC;
        v56 >>= 2;
        v40 = _kmalloc_noprof(v39, 3520);
        if ( v40 )
        {
          v41 = a1[234];
          v42 = a1[227];
          v43 = v56;
          if ( *((_DWORD *)v41 - 1) != 905330014 )
            __break(0x8228u);
          v44 = ((__int64 (__fastcall *)(const char *, const char *, __int64, __int64))v41)(
                  v42,
                  "qcom,mdss-dsi-reset-sequence",
                  v40,
                  v43);
          if ( v44 )
          {
            v36 = v44;
            drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] cannot read dso-reset-seqience\n", *a1);
          }
          else
          {
            v46 = v56 >> 1;
            v47 = 8 * (v56 >> 1);
            v48 = _kmalloc_noprof(v47, 3520);
            if ( v48 )
            {
              v49 = v56;
              a1[198] = (const char *)v48;
              *((_DWORD *)a1 + 398) = v46;
              if ( v49 )
              {
                v50 = v56;
                v51 = 0;
                v52 = 0;
                v53 = 8 * v46;
                v54 = v39;
                do
                {
                  if ( v39 < v52
                    || v54 < 4
                    || v47 < v52
                    || v53 < 4
                    || v39 < v52
                    || v47 < v52
                    || (v55 = v52 + 4, *(_DWORD *)(v48 + v52) = *(_DWORD *)(v40 + v52), v39 < v52 + 4)
                    || v54 - 4 < 4
                    || v47 < v55
                    || v53 - 4 < 4
                    || v39 < v55
                    || v47 < v55 )
                  {
                    __break(1u);
                  }
                  v51 += 2;
                  v54 -= 8LL;
                  v53 -= 8LL;
                  *(_DWORD *)(v48 + v52 + 4) = *(_DWORD *)(v40 + 4 + v52);
                  v52 += 8LL;
                }
                while ( v51 < v50 );
              }
              kfree(v40);
              goto LABEL_44;
            }
            v36 = -12;
          }
          kfree(v40);
        }
        else
        {
          v36 = -12;
        }
LABEL_61:
        drm_dev_printk(
          0,
          &unk_248D72,
          "*ERROR* [msm-dsi-error]: [%s] failed to parse reset sequence, rc=%d\n",
          *a1,
          v36);
        goto LABEL_62;
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] syntax error for dsi-reset-sequence\n", *a1);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: [%s] dsi-reset-sequence not found\n", *a1);
    }
    v36 = -22;
    goto LABEL_61;
  }
LABEL_44:
  v33 = a1[243];
  v34 = a1[227];
  if ( *((_DWORD *)v33 - 1) != -222936480 )
    __break(0x8228u);
  v35 = ((__int64 (__fastcall *)(const char *, const char *, _QWORD))v33)(v34, "qcom,mdss-dsi-panel-test-pin", 0);
  v36 = 0;
  *((_DWORD *)a1 + 554) = v35;
  if ( v35 < 0 )
  {
    _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s:%d panel test gpio not specified\n", "dsi_panel_parse_gpios", 3198);
    v36 = 0;
  }
LABEL_62:
  _ReadStatusReg(SP_EL0);
  return v36;
}

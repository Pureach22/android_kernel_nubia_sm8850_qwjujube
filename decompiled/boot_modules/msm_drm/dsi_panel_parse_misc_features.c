__int64 __fastcall dsi_panel_parse_misc_features(__int64 a1)
{
  __int64 (__fastcall *v2)(__int64, const char *); // x8
  __int64 v3; // x0
  char v4; // w0
  const char *v5; // x5
  long double v6; // q0
  __int64 (__fastcall *v7)(__int64, const char *, long double); // x8
  __int64 v8; // x0
  char v9; // w0
  const char *v10; // x5
  long double v11; // q0
  __int64 (__fastcall *v12)(__int64, const char *, long double); // x8
  __int64 v13; // x0
  char v14; // w0
  __int64 (__fastcall *v15)(__int64, const char *); // x8
  char v16; // w9
  __int64 v17; // x0
  char v18; // w0
  __int64 (__fastcall *v19)(__int64, const char *); // x8
  char v20; // w9
  __int64 v21; // x0
  char v22; // w0
  __int64 (__fastcall *v23)(__int64, const char *); // x8
  char v24; // w9
  __int64 v25; // x0
  char v26; // w0
  __int64 (__fastcall *v27)(__int64, const char *); // x8
  char v28; // w9
  __int64 v29; // x0
  char v30; // w0
  __int64 (__fastcall *v31)(__int64, const char *); // x8
  char v32; // w9
  __int64 v33; // x0
  char v34; // w9
  __int64 (__fastcall *v35)(__int64, const char *, char **); // x10
  __int64 v36; // x0
  __int64 result; // x0
  const char *v38; // x20
  int v39; // w8
  __int64 (__fastcall *v40)(__int64, const char *, char **); // x8
  __int64 v41; // x0
  const char *v42; // x20
  int v43; // w8
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v3 = *(_QWORD *)(a1 + 1816);
  s1[0] = nullptr;
  if ( *((_DWORD *)v2 - 1) != -834495637 )
    __break(0x8228u);
  v4 = v2(v3, "qcom,ulps-enabled");
  if ( (v4 & 1) != 0 )
    v5 = "enabled";
  else
    v5 = "disabled";
  *(_BYTE *)(a1 + 1961) = v4 & 1;
  *(double *)&v6 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: %s: ulps feature %s\n", "dsi_panel_parse_misc_features", v5);
  v7 = *(__int64 (__fastcall **)(__int64, const char *, long double))(a1 + 1864);
  v8 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v7 - 1) != -834495637 )
    __break(0x8228u);
  v9 = v7(v8, "qcom,suspend-ulps-enabled", v6);
  if ( (v9 & 1) != 0 )
    v10 = "enabled";
  else
    v10 = "disabled";
  *(_BYTE *)(a1 + 1962) = v9 & 1;
  *(double *)&v11 = _drm_dev_dbg(
                      0,
                      0,
                      0,
                      "[msm-dsi-debug]: %s: ulps during suspend feature %s\n",
                      "dsi_panel_parse_misc_features",
                      v10);
  v12 = *(__int64 (__fastcall **)(__int64, const char *, long double))(a1 + 1864);
  v13 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v12 - 1) != -834495637 )
    __break(0x8228u);
  v14 = v12(v13, "qcom,mdss-dsi-te-using-wd", v11);
  v15 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v16 = v14 & 1;
  v17 = *(_QWORD *)(a1 + 1816);
  *(_BYTE *)(a1 + 1974) = v16;
  if ( *((_DWORD *)v15 - 1) != -834495637 )
    __break(0x8228u);
  v18 = v15(v17, "qcom,cmd-sync-wait-broadcast");
  v19 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v20 = v18 & 1;
  v21 = *(_QWORD *)(a1 + 1816);
  *(_BYTE *)(a1 + 2200) = v20;
  if ( *((_DWORD *)v19 - 1) != -834495637 )
    __break(0x8228u);
  v22 = v19(v21, "qcom,mdss-dsi-lp11-init");
  v23 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v24 = v22 & 1;
  v25 = *(_QWORD *)(a1 + 1816);
  *(_BYTE *)(a1 + 1960) = v24;
  if ( *((_DWORD *)v23 - 1) != -834495637 )
    __break(0x8228u);
  v26 = v23(v25, "qcom,platform-reset-gpio-always-on");
  v27 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v28 = v26 & 1;
  v29 = *(_QWORD *)(a1 + 1816);
  *(_BYTE *)(a1 + 1964) = v28;
  if ( *((_DWORD *)v27 - 1) != -834495637 )
    __break(0x8228u);
  v30 = v27(v29, "qcom,event-notification-disabled");
  v31 = *(__int64 (__fastcall **)(__int64, const char *))(a1 + 1864);
  v32 = v30 & 1;
  v33 = *(_QWORD *)(a1 + 1816);
  *(_BYTE *)(a1 + 2048) = v32;
  if ( *((_DWORD *)v31 - 1) != -834495637 )
    __break(0x8228u);
  v34 = v31(v33, "qcom,skip-panel-power-off") & 1;
  v35 = *(__int64 (__fastcall **)(__int64, const char *, char **))(a1 + 1880);
  v36 = *(_QWORD *)(a1 + 1816);
  *(_BYTE *)(a1 + 2188) = 0;
  *(_BYTE *)(a1 + 1972) = v34;
  *(_DWORD *)(a1 + 2192) = 5;
  if ( *((_DWORD *)v35 - 1) != 173720059 )
    __break(0x822Au);
  result = v35(v36, "qcom,spr-pack-type", s1);
  if ( !(_DWORD)result )
  {
    v38 = s1[0];
    v39 = (unsigned __int8)*s1[0];
    if ( *s1[0] )
    {
      result = strcmp(s1[0], "pentile");
      if ( (_DWORD)result )
      {
        result = strcmp(v38, "rgbw");
        if ( (_DWORD)result )
        {
          result = strcmp(v38, "yygm");
          if ( (_DWORD)result )
          {
            result = strcmp(v38, "yygw");
            if ( (_DWORD)result )
              goto LABEL_26;
            v39 = 4;
          }
          else
          {
            v39 = 3;
          }
        }
        else
        {
          v39 = 2;
        }
      }
      else
      {
        v39 = 1;
      }
    }
    *(_DWORD *)(a1 + 2192) = v39;
    *(_BYTE *)(a1 + 2188) = 1;
    if ( v39 != 1 )
      goto LABEL_60;
    goto LABEL_38;
  }
LABEL_26:
  if ( *(_DWORD *)(a1 + 2192) != 1 )
    goto LABEL_60;
LABEL_38:
  v40 = *(__int64 (__fastcall **)(__int64, const char *, char **))(a1 + 1880);
  v41 = *(_QWORD *)(a1 + 1816);
  if ( *((_DWORD *)v40 - 1) != 173720059 )
    __break(0x8228u);
  result = v40(v41, "qcom,spr-pentile-pack-type", s1);
  if ( !(_DWORD)result )
  {
    v42 = s1[0];
    result = strcmp(s1[0], "None");
    if ( !(_DWORD)result )
    {
      v43 = 0;
      goto LABEL_59;
    }
    result = strcmp(v42, "RG-BG Type A");
    if ( !(_DWORD)result )
    {
      v43 = 1;
      goto LABEL_59;
    }
    result = strcmp(v42, "BG-RG Type A");
    if ( !(_DWORD)result )
    {
      v43 = 2;
      goto LABEL_59;
    }
    result = strcmp(v42, "GR-GB Type A");
    if ( !(_DWORD)result )
    {
      v43 = 3;
      goto LABEL_59;
    }
    result = strcmp(v42, "GB-GR Type A");
    if ( !(_DWORD)result )
    {
      v43 = 4;
      goto LABEL_59;
    }
    result = strcmp(v42, "RG-BG Type B");
    if ( !(_DWORD)result )
    {
      v43 = 5;
      goto LABEL_59;
    }
    result = strcmp(v42, "BG-RG Type B");
    if ( !(_DWORD)result )
    {
      v43 = 6;
      goto LABEL_59;
    }
    result = strcmp(v42, "GR-GB Type B");
    if ( !(_DWORD)result )
    {
      v43 = 7;
      goto LABEL_59;
    }
    result = strcmp(v42, "GB-GR Type B");
    if ( !(_DWORD)result )
    {
      v43 = 8;
LABEL_59:
      *(_DWORD *)(a1 + 2196) = v43;
    }
  }
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return result;
}

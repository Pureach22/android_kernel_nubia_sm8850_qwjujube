__int64 __fastcall dsi_pwr_parse_supply_node(_QWORD *a1, __int64 a2, _QWORD *a3)
{
  _DWORD *v6; // x8
  __int64 v7; // x0
  __int64 v8; // x22
  int v9; // w27
  __int64 v10; // x8
  long double v11; // q0
  __int64 (__fastcall *v12)(__int64, __int64, long double); // x8
  __int64 (__fastcall *v13)(__int64, const char *, const char **); // x8
  unsigned int v14; // w0
  __int64 (__fastcall *v15)(__int64, const char *, int *); // x8
  unsigned int v16; // w0
  __int64 (__fastcall *v17)(__int64, const char *, int *); // x8
  unsigned int v18; // w0
  __int64 (__fastcall *v19)(__int64, const char *, int *); // x8
  unsigned int v20; // w0
  __int64 (__fastcall *v21)(__int64, const char *, int *); // x8
  unsigned int v22; // w0
  __int64 (__fastcall *v23)(__int64, const char *, int *); // x8
  int v24; // w0
  long double v25; // q0
  int v26; // w8
  unsigned int (__fastcall *v27)(__int64, const char *, int *, long double); // x8
  long double v28; // q0
  unsigned int (__fastcall *v29)(__int64, const char *, int *, long double); // x8
  long double v30; // q0
  unsigned int (__fastcall *v31)(__int64, const char *, int *, long double); // x8
  long double v32; // q0
  unsigned int (__fastcall *v33)(__int64, const char *, int *, long double); // x8
  long double v34; // q0
  unsigned int (__fastcall *v35)(__int64, const char *, int *, long double); // x8
  unsigned int v36; // w28
  const char *v38; // [xsp+8h] [xbp-18h] BYREF
  int v39; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v40; // [xsp+18h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = (_DWORD *)a1[13];
  v39 = 0;
  if ( *(v6 - 1) != -816260946 )
    __break(0x8228u);
  v7 = ((__int64 (__fastcall *)(__int64, _QWORD))v6)(a2, 0);
  if ( v7 )
  {
    v8 = v7;
    v9 = 0;
    while ( 1 )
    {
      v13 = (__int64 (__fastcall *)(__int64, const char *, const char **))a1[8];
      v38 = nullptr;
      if ( *((_DWORD *)v13 - 1) != 173720059 )
        __break(0x8228u);
      v14 = v13(v8, "qcom,supply-name", &v38);
      if ( v14 )
      {
        v36 = v14;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read name, rc = %d\n", v14);
        goto LABEL_59;
      }
      snprintf((char *)(*a3 + 80LL * v9 + 8), 0x20u, "%s", v38);
      v15 = (__int64 (__fastcall *)(__int64, const char *, int *))a1[4];
      if ( *((_DWORD *)v15 - 1) != 309187163 )
        __break(0x8228u);
      v16 = v15(v8, "qcom,supply-min-voltage", &v39);
      if ( v16 )
      {
        v36 = v16;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read min voltage, rc = %d\n", v16);
        goto LABEL_59;
      }
      *(_DWORD *)(*a3 + 80LL * v9 + 40) = v39;
      v17 = (__int64 (__fastcall *)(__int64, const char *, int *))a1[4];
      if ( *((_DWORD *)v17 - 1) != 309187163 )
        __break(0x8228u);
      v18 = v17(v8, "qcom,supply-max-voltage", &v39);
      if ( v18 )
      {
        v36 = v18;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read max voltage, rc = %d\n", v18);
        goto LABEL_59;
      }
      *(_DWORD *)(*a3 + 80LL * v9 + 44) = v39;
      v19 = (__int64 (__fastcall *)(__int64, const char *, int *))a1[4];
      if ( *((_DWORD *)v19 - 1) != 309187163 )
        __break(0x8228u);
      v20 = v19(v8, "qcom,supply-enable-load", &v39);
      if ( v20 )
      {
        v36 = v20;
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read enable load, rc = %d\n", v20);
        goto LABEL_59;
      }
      *(_DWORD *)(*a3 + 80LL * v9 + 48) = v39;
      v21 = (__int64 (__fastcall *)(__int64, const char *, int *))a1[4];
      if ( *((_DWORD *)v21 - 1) != 309187163 )
        __break(0x8228u);
      v22 = v21(v8, "qcom,supply-disable-load", &v39);
      if ( v22 )
        break;
      *(_DWORD *)(*a3 + 80LL * v9 + 52) = v39;
      v23 = (__int64 (__fastcall *)(__int64, const char *, int *))a1[4];
      if ( *((_DWORD *)v23 - 1) != 309187163 )
        __break(0x8228u);
      v24 = v23(v8, "qcom,supply-lp2-load", &v39);
      if ( v24 )
      {
        *(double *)&v25 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: lp2-load not specified, rc = %d\n", v24);
        v26 = 0;
      }
      else
      {
        v26 = v39;
      }
      *(_DWORD *)(*a3 + 80LL * v9 + 56) = v26;
      v27 = (unsigned int (__fastcall *)(__int64, const char *, int *, long double))a1[4];
      if ( *((_DWORD *)v27 - 1) != 309187163 )
        __break(0x8228u);
      if ( v27(v8, "qcom,supply-off-min-voltage", &v39, v25) )
        *(double *)&v28 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: off-min-voltage not specified\n");
      else
        *(_DWORD *)(*a3 + 80LL * v9 + 60) = v39;
      v29 = (unsigned int (__fastcall *)(__int64, const char *, int *, long double))a1[4];
      if ( *((_DWORD *)v29 - 1) != 309187163 )
        __break(0x8228u);
      if ( v29(v8, "qcom,supply-pre-on-sleep", &v39, v28) )
        *(double *)&v30 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: pre-on-sleep not specified\n");
      else
        *(_DWORD *)(*a3 + 80LL * v9 + 64) = v39;
      v31 = (unsigned int (__fastcall *)(__int64, const char *, int *, long double))a1[4];
      if ( *((_DWORD *)v31 - 1) != 309187163 )
        __break(0x8228u);
      if ( v31(v8, "qcom,supply-pre-off-sleep", &v39, v30) )
        *(double *)&v32 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: pre-off-sleep not specified\n");
      else
        *(_DWORD *)(*a3 + 80LL * v9 + 72) = v39;
      v33 = (unsigned int (__fastcall *)(__int64, const char *, int *, long double))a1[4];
      if ( *((_DWORD *)v33 - 1) != 309187163 )
        __break(0x8228u);
      if ( v33(v8, "qcom,supply-post-on-sleep", &v39, v32) )
        *(double *)&v34 = _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: post-on-sleep not specified\n");
      else
        *(_DWORD *)(*a3 + 80LL * v9 + 68) = v39;
      v35 = (unsigned int (__fastcall *)(__int64, const char *, int *, long double))a1[4];
      if ( *((_DWORD *)v35 - 1) != 309187163 )
        __break(0x8228u);
      if ( v35(v8, "qcom,supply-post-off-sleep", &v39, v34) )
        _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: post-off-sleep not specified\n");
      else
        *(_DWORD *)(*a3 + 80LL * v9 + 76) = v39;
      v10 = *a3 + 80LL * v9;
      *(double *)&v11 = _drm_dev_dbg(
                          0,
                          0,
                          0,
                          "[msm-dsi-debug]: [%s] minv=%d maxv=%d, en_load=%d, dis_load=%d\n",
                          (const char *)(v10 + 8),
                          *(_DWORD *)(v10 + 40),
                          *(_DWORD *)(v10 + 44),
                          *(_DWORD *)(v10 + 48),
                          *(_DWORD *)(v10 + 52));
      v12 = (__int64 (__fastcall *)(__int64, __int64, long double))a1[13];
      ++v9;
      if ( *((_DWORD *)v12 - 1) != -816260946 )
        __break(0x8228u);
      v8 = v12(a2, v8, v11);
      if ( !v8 )
        goto LABEL_53;
    }
    v36 = v22;
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read disable load, rc = %d\n", v22);
  }
  else
  {
LABEL_53:
    v36 = 0;
  }
LABEL_59:
  _ReadStatusReg(SP_EL0);
  return v36;
}

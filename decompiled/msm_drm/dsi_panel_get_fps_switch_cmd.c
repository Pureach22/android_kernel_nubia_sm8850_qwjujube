__int64 __fastcall dsi_panel_get_fps_switch_cmd(__int64 *a1, __int64 a2, int a3)
{
  __int64 v6; // x28
  __int64 v7; // x20
  __int64 (__fastcall *v8)(__int64, const char *); // x8
  __int64 v9; // x0
  __int64 (*v10)(void); // x8
  __int64 v11; // x23
  __int64 v12; // x0
  __int64 v13; // x24
  __int64 result; // x0
  __int64 (__fastcall *v15)(__int64, __int64); // x8
  __int64 (__fastcall *v16)(__int64, const char *); // x8
  __int64 v17; // x0
  __int64 (*v18)(void); // x8
  __int64 v19; // x25
  __int64 v20; // x0
  __int64 v21; // x27
  __int64 (__fastcall *v22)(__int64, __int64); // x8
  __int64 (__fastcall *v23)(__int64, const char *, int *); // x8
  int v24; // w0
  int v25; // w0
  int v26; // w0
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  if ( a1 && a2 )
  {
    mutex_lock(a1 + 130);
    v6 = *(_QWORD *)(a2 + 184);
    v7 = a1[227];
    v8 = (__int64 (__fastcall *)(__int64, const char *))a1[237];
    if ( *((_DWORD *)v8 - 1) != 387453051 )
      __break(0x8228u);
    v9 = v8(v7, "qcom,mdss-dsi-display-timings");
    if ( v9 )
    {
      v10 = (__int64 (*)(void))a1[240];
      v11 = v9;
      if ( *((_DWORD *)v10 - 1) != -816260946 )
        __break(0x8228u);
      v12 = v10();
      if ( v12 )
      {
        v13 = v12;
        while ( 1 )
        {
          v16 = (__int64 (__fastcall *)(__int64, const char *))a1[237];
          a1[227] = v13;
          if ( *((_DWORD *)v16 - 1) != 387453051 )
            __break(0x8228u);
          v17 = v16(v13, "qcom,mdss-dsi-dfps-commands");
          if ( !v17 )
          {
            _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: no display fps nodes defined\n");
            goto LABEL_34;
          }
          v18 = (__int64 (*)(void))a1[240];
          v19 = v17;
          if ( *((_DWORD *)v18 - 1) != -816260946 )
            __break(0x8228u);
          v20 = v18();
          if ( v20 )
            break;
LABEL_11:
          v15 = (__int64 (__fastcall *)(__int64, __int64))a1[240];
          if ( *((_DWORD *)v15 - 1) != -816260946 )
            __break(0x8228u);
          v13 = v15(v11, v13);
          if ( !v13 )
            goto LABEL_34;
        }
        v21 = v20;
        while ( 1 )
        {
          v23 = (__int64 (__fastcall *)(__int64, const char *, int *))a1[231];
          a1[227] = v21;
          if ( *((_DWORD *)v23 - 1) != 309187163 )
            __break(0x8228u);
          v24 = v23(v21, "qcom,dsi-fps-value", &v27);
          if ( v24 )
            break;
          if ( v27 == a3 )
          {
            v25 = dsi_panel_parse_cmd_sets_sub(v6 + 1600, 0x28u, a1 + 227);
            if ( v25 )
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to parse fps switch command %d\n", v25);
            v26 = dsi_panel_parse_cmd_sets_sub(v6 + 160, 4u, a1 + 227);
            if ( v26 )
              _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: failed to parse post panel on command %d\n", v26);
          }
          v22 = (__int64 (__fastcall *)(__int64, __int64))a1[240];
          if ( *((_DWORD *)v22 - 1) != -816260946 )
            __break(0x8228u);
          v21 = v22(v19, v21);
          if ( !v21 )
            goto LABEL_11;
        }
        drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: failed to read qcom,dsi-fps-value, rc=%d\n", v24);
      }
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: no display timing_np nodes defined\n");
    }
LABEL_34:
    a1[227] = v7;
    result = mutex_unlock(a1 + 130);
  }
  else
  {
    result = drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

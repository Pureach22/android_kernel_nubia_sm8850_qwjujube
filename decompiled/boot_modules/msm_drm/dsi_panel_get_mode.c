void __fastcall dsi_panel_get_mode(_QWORD *a1, __int64 a2, __int64 a3)
{
  __int64 (__fastcall *v4)(__int64, const char *); // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 (*v7)(void); // x8
  __int64 v8; // x25
  int v9; // w3
  _DWORD *v10; // x8

  _ReadStatusReg(SP_EL0);
  if ( a1 && a3 )
  {
    mutex_lock(a1 + 130);
    v4 = (__int64 (__fastcall *)(__int64, const char *))a1[237];
    v5 = a1[227];
    if ( *((_DWORD *)v4 - 1) != 387453051 )
      __break(0x8228u);
    v6 = v4(v5, "qcom,mdss-dsi-display-timings");
    if ( v6 )
    {
      v7 = (__int64 (*)(void))a1[238];
      v8 = v6;
      if ( *((_DWORD *)v7 - 1) != -1880641320 )
        __break(0x8228u);
      v9 = v7();
      if ( v9 && v9 < 33 )
      {
        v10 = (_DWORD *)a1[240];
        if ( *(v10 - 1) != -816260946 )
          __break(0x8228u);
        if ( ((__int64 (__fastcall *)(__int64, _QWORD))v10)(v8, 0) )
        {
          _ReadStatusReg(SP_EL0);
          JUMPOUT(0x1F6218);
        }
        JUMPOUT(0x1F61C0);
      }
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid count of timing nodes: %d\n", v9);
    }
    else
    {
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: no display timing nodes defined\n");
    }
    JUMPOUT(0x1F6178);
  }
  drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: invalid params\n");
  JUMPOUT(0x1F6184);
}

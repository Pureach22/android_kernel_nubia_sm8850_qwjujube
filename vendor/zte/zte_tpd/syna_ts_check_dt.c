__int64 __fastcall syna_ts_check_dt(__int64 a1)
{
  int v2; // w0
  int v3; // w21
  unsigned int v4; // w22
  unsigned int v5; // w20
  void *v6; // x0
  __int64 v7; // x0
  const char **v8; // x26
  unsigned __int64 panel; // x0
  __int64 v10; // x19
  _QWORD v12[11]; // [xsp+8h] [xbp-58h] BYREF

  v12[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = of_count_phandle_with_args(*(_QWORD *)(a1 + 744), "panel", 0);
  if ( v2 >= 1 )
  {
    v3 = v2;
    v4 = 0;
    v5 = -1;
    while ( 1 )
    {
      v7 = *(_QWORD *)(a1 + 744);
      memset(v12, 0, 80);
      if ( (unsigned int)_of_parse_phandle_with_args(v7, "panel", 0, 0, v4, v12) )
        v8 = nullptr;
      else
        v8 = (const char **)v12[0];
      if ( v8 )
        printk(unk_31E60, "syna_ts_check_dt", "syna_ts_check_dt");
      panel = of_drm_find_panel(v8);
      if ( panel <= 0xFFFFFFFFFFFFF000LL )
      {
        v10 = panel;
        strncpy(DEVICE_NODE_NAME, *v8, 0x64u);
        v5 = 0;
        active_panel = v10;
        goto LABEL_17;
      }
      if ( panel == -19 )
      {
        v5 = -19;
        v6 = unk_33BEE;
      }
      else
      {
        if ( panel != -517 )
          goto LABEL_5;
        v5 = -517;
        v6 = unk_3351C;
      }
      printk(v6, "syna_ts_check_dt", "syna_ts_check_dt");
LABEL_5:
      if ( v3 == ++v4 )
        goto LABEL_17;
    }
  }
  v5 = -19;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return v5;
}

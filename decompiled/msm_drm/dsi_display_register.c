__int64 dsi_display_register()
{
  __int64 v0; // x8
  char v1; // w9
  __int64 v2; // x28
  char v3; // w26
  char *v4; // x27
  const char *v5; // x21
  size_t v6; // x0
  unsigned __int64 v7; // x2
  size_t v8; // x0
  size_t v9; // x2
  unsigned __int64 v10; // x0
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 result; // x0
  __int64 v14; // x0
  char v15[512]; // [xsp+0h] [xbp-210h] BYREF
  __int64 v16; // [xsp+200h] [xbp-10h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  dsi_phy_drv_register();
  dsi_ctrl_drv_register();
  memset(v15, 0, sizeof(v15));
  v0 = 0;
  v1 = 1;
  do
  {
    v2 = 552 * v0;
    v3 = v1;
    v4 = (char *)&boot_displays + 552 * v0;
    v5 = *((const char **)v4 + 64);
    v6 = strnlen(v5, 0x200u);
    if ( v6 == -1 )
      goto LABEL_26;
    if ( v6 == 512 )
      v7 = 512;
    else
      v7 = v6 + 1;
    if ( v7 >= 0x201 )
      goto LABEL_27;
    sized_strscpy(v15, v5);
    v8 = strnlen(v15, 0x200u);
    v9 = v8;
    if ( v8 >= 0x201 )
      goto LABEL_24;
    if ( v8 == 512 )
    {
      v6 = _fortify_panic(4, 512, 513);
LABEL_26:
      _fortify_panic(2, -1, v6 + 1);
LABEL_27:
      v14 = 7;
LABEL_28:
      _fortify_panic(v14, 512, v7);
    }
    v10 = strnstr(v15, ":", v8);
    if ( v10 )
    {
      if ( (unsigned __int64)v15 >= v10 )
      {
        v12 = 0;
      }
      else
      {
        v11 = 0;
        v12 = v10 - (_QWORD)v15;
        do
        {
          if ( v11 == 512 )
            goto LABEL_22;
          v4[v11] = v15[v11];
          ++v11;
        }
        while ( v12 != v11 );
        if ( (_DWORD)v12 == 512 )
        {
LABEL_22:
          __break(0x5512u);
LABEL_23:
          __break(1u);
LABEL_24:
          v7 = v9 + 1;
          v14 = 2;
          goto LABEL_28;
        }
      }
      if ( (unsigned __int64)(v12 + v2) > 0x44F )
        goto LABEL_23;
      v4[v12] = 0;
      v4[520] = 1;
    }
    else
    {
      _drm_dev_dbg(0, 0, 0, "[msm-dsi-debug]: display name[%s]is not valid\n", v15);
    }
    v1 = 0;
    v0 = 1;
  }
  while ( (v3 & 1) != 0 );
  result = _platform_driver_register(&dsi_display_driver, &_this_module);
  _ReadStatusReg(SP_EL0);
  return result;
}

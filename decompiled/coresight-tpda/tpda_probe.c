unsigned __int64 __fastcall tpda_probe(__int64 a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  unsigned __int64 optional_enabled; // x0
  unsigned __int64 v6; // x21
  __int64 v7; // x8
  unsigned int v8; // w20
  __int64 v9; // [xsp+8h] [xbp-58h] BYREF
  __int64 v10; // [xsp+10h] [xbp-50h]
  void *v11; // [xsp+18h] [xbp-48h]
  __int64 v12; // [xsp+20h] [xbp-40h]
  __int64 v13; // [xsp+28h] [xbp-38h]
  _UNKNOWN **v14; // [xsp+30h] [xbp-30h]
  char v16; // [xsp+40h] [xbp-20h]
  _BYTE v17[7]; // [xsp+41h] [xbp-1Fh] BYREF
  unsigned __int64 v18; // [xsp+48h] [xbp-18h]
  __int64 v19; // [xsp+50h] [xbp-10h]
  __int64 v20; // [xsp+58h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  v10 = 0;
  result = coresight_get_platform_data();
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    *(_QWORD *)(a1 + 144) = result;
    v3 = devm_kmalloc(a1, 64, 3520);
    if ( !v3 )
      goto LABEL_9;
    v4 = v3;
    *(_QWORD *)(v3 + 8) = a1;
    *(_QWORD *)(a1 + 152) = v3;
    optional_enabled = devm_clk_get_optional_enabled(a1, "atclk");
    *(_QWORD *)(v4 + 56) = optional_enabled;
    if ( optional_enabled >= 0xFFFFFFFFFFFFF001LL )
    {
      v8 = optional_enabled;
      dev_err(a1, "enable/get atclk fail, ret = %d\n", optional_enabled);
      if ( v8 == -110 )
        result = 4294966779LL;
      else
        result = v8;
      goto LABEL_10;
    }
    result = devm_ioremap_resource(a1, a1 + 912);
    v6 = result;
    if ( result >= 0xFFFFFFFFFFFFF001LL )
    {
      result = (unsigned int)result;
      goto LABEL_10;
    }
    *(_QWORD *)v4 = result;
    *(_DWORD *)(v4 + 24) = 0;
    *(_BYTE *)(v4 + 43) = 1;
    if ( !coresight_alloc_device_name(&tpda_devs, a1) )
    {
LABEL_9:
      result = 4294967284LL;
      goto LABEL_10;
    }
    v7 = *(_QWORD *)(a1 + 144);
    LODWORD(v9) = 1;
    v11 = &tpda_cs_ops;
    v12 = v7;
    LODWORD(v10) = 0;
    v13 = a1;
    v14 = &tpda_attr_grps;
    v16 = 1;
    memset(v17, 0, sizeof(v17));
    v18 = v6;
    v19 = 0;
    result = coresight_register(&v9);
    *(_QWORD *)(v4 + 16) = result;
    if ( result < 0xFFFFFFFFFFFFF001LL )
    {
      _pm_runtime_idle(a1, 4);
      result = 0;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}

unsigned __int64 __fastcall static_tpdm_probe(__int64 a1)
{
  __int64 v1; // x19
  unsigned __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x20
  _QWORD v7[2]; // [xsp+8h] [xbp-58h] BYREF
  void *v8; // [xsp+18h] [xbp-48h]
  __int64 v9; // [xsp+20h] [xbp-40h]
  __int64 v10; // [xsp+28h] [xbp-38h]
  _UNKNOWN **v11; // [xsp+30h] [xbp-30h]
  __int64 v13; // [xsp+40h] [xbp-20h]
  __int64 v14; // [xsp+48h] [xbp-18h]
  __int64 v15; // [xsp+50h] [xbp-10h]
  __int64 v16; // [xsp+58h] [xbp-8h]

  v1 = a1 + 16;
  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14 = 0;
  v15 = 0;
  v13 = 0;
  v10 = 0;
  v11 = nullptr;
  v8 = nullptr;
  v9 = 0;
  v7[1] = 0;
  if ( !coresight_alloc_device_name(&tpdm_devs, a1 + 16) )
    goto LABEL_6;
  v7[0] = 0x300000003LL;
  v8 = &static_tpdm_cs_ops;
  v11 = &static_tpdm_attr_grps;
  result = coresight_get_platform_data(v1);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_7;
  *(_QWORD *)(a1 + 160) = result;
  v4 = devm_kmalloc(v1, 72, 3520);
  if ( !v4 )
  {
LABEL_6:
    result = 4294967284LL;
    goto LABEL_7;
  }
  v5 = *(_QWORD *)(a1 + 160);
  *(_QWORD *)(v4 + 8) = v1;
  *(_QWORD *)(a1 + 168) = v4;
  v6 = v4;
  v9 = v5;
  v10 = v1;
  result = coresight_register(v7);
  *(_QWORD *)(v6 + 16) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    pm_runtime_enable(v1);
    dev_info(v1, "static tpdm initialized\n");
    result = 0;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}

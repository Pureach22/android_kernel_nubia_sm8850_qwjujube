unsigned __int64 __fastcall trace_noc_probe(_QWORD *a1)
{
  unsigned __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  void *v6; // x8
  __int64 v7; // x9
  __int64 v8; // [xsp+8h] [xbp-58h] BYREF
  __int64 v9; // [xsp+10h] [xbp-50h]
  void *v10; // [xsp+18h] [xbp-48h]
  __int64 v11; // [xsp+20h] [xbp-40h]
  _QWORD *v12; // [xsp+28h] [xbp-38h]
  _UNKNOWN **v13; // [xsp+30h] [xbp-30h]
  __int64 v15; // [xsp+40h] [xbp-20h]
  __int64 v16; // [xsp+48h] [xbp-18h]
  __int64 v17; // [xsp+50h] [xbp-10h]
  __int64 v18; // [xsp+58h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = 0;
  v17 = 0;
  v15 = 0;
  v12 = nullptr;
  v13 = nullptr;
  v10 = nullptr;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  if ( !coresight_alloc_device_name(&trace_noc_devs, a1) )
    goto LABEL_9;
  result = coresight_get_platform_data(a1);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_10;
  a1[18] = result;
  v3 = devm_kmalloc(a1, 56, 3520);
  if ( !v3
    || (v4 = v3,
        *(_QWORD *)(v3 + 8) = a1,
        a1[19] = v3,
        v5 = devm_ioremap_resource(a1, a1 + 114),
        (*(_QWORD *)v4 = v5) == 0) )
  {
LABEL_9:
    result = 4294967284LL;
    goto LABEL_10;
  }
  if ( of_find_property(a1[93], "qcom,trace-noc-v2", 0) )
    *(_DWORD *)(v4 + 28) = 1;
  if ( of_find_property(a1[93], "qcom,interconnect-trace-noc", 0) )
  {
    *(_DWORD *)(v4 + 36) = 0;
    v6 = &interconnect_trace_noc_cs_ops;
  }
  else
  {
    *(_DWORD *)(v4 + 48) = 1;
    *(_BYTE *)(v4 + 34) = 1;
    v6 = &trace_noc_cs_ops;
    v13 = &trace_noc_attr_grps;
  }
  LODWORD(v9) = 0;
  LODWORD(v8) = 1;
  v7 = a1[18];
  v12 = a1;
  v10 = v6;
  v11 = v7;
  result = coresight_register(&v8);
  *(_QWORD *)(v4 + 16) = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    _pm_runtime_idle(a1, 4);
    result = 0;
    *(_DWORD *)(v4 + 24) = 0;
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}

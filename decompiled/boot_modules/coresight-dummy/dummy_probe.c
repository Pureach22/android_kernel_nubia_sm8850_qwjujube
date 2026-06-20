unsigned __int64 __fastcall dummy_probe(_QWORD *a1)
{
  _QWORD *v2; // x21
  __int64 v3; // x20
  void **v4; // x8
  __int64 (__fastcall ***v5)(); // x9
  unsigned __int64 result; // x0
  _QWORD *v7; // x0
  __int64 v8; // x8
  _QWORD *v9; // x22
  char v10; // w8
  int v11; // [xsp+4h] [xbp-5Ch] BYREF
  _QWORD v12[2]; // [xsp+8h] [xbp-58h] BYREF
  void *v13; // [xsp+18h] [xbp-48h] BYREF
  __int64 v14; // [xsp+20h] [xbp-40h]
  _QWORD *v15; // [xsp+28h] [xbp-38h]
  __int64 v16; // [xsp+30h] [xbp-30h] BYREF
  __int64 v17; // [xsp+38h] [xbp-28h]
  __int64 v18; // [xsp+40h] [xbp-20h]
  __int64 v19; // [xsp+48h] [xbp-18h]
  __int64 v20; // [xsp+50h] [xbp-10h]
  __int64 v21; // [xsp+58h] [xbp-8h]

  v2 = a1 + 2;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a1[95];
  v19 = 0;
  v20 = 0;
  v17 = 0;
  v18 = 0;
  v15 = nullptr;
  v16 = 0;
  v13 = nullptr;
  v14 = 0;
  v12[0] = 0;
  v12[1] = 0;
  v11 = 0;
  if ( (unsigned int)of_device_is_compatible(v3, "arm,coresight-dummy-source") )
  {
    v17 = coresight_alloc_device_name(&source_devs, v2);
    if ( !v17 )
      goto LABEL_11;
    v4 = (void **)&v16;
    v12[0] = 0x400000003LL;
    v5 = (__int64 (__fastcall ***)())&dummy_source_attr_grps;
    v13 = &dummy_source_cs_ops;
  }
  else
  {
    if ( !(unsigned int)of_device_is_compatible(v3, "arm,coresight-dummy-sink") )
    {
      dev_err(v2, "Device type not set\n");
      result = 4294967274LL;
      goto LABEL_12;
    }
    v17 = coresight_alloc_device_name(&sink_devs, v2);
    if ( !v17 )
      goto LABEL_11;
    v4 = &v13;
    v12[0] = 0;
    v5 = &dummy_sink_cs_ops;
  }
  *v4 = v5;
  result = coresight_get_platform_data(v2);
  if ( result >= 0xFFFFFFFFFFFFF001LL )
    goto LABEL_12;
  a1[20] = result;
  v7 = (_QWORD *)devm_kmalloc(v2, 24, 3520);
  if ( !v7 )
  {
LABEL_11:
    result = 4294967284LL;
    goto LABEL_12;
  }
  v8 = a1[20];
  v9 = v7;
  *v7 = v2;
  a1[21] = v7;
  v14 = v8;
  v15 = v2;
  result = coresight_register(v12);
  v9[1] = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    pm_runtime_enable(v2);
    result = of_device_is_compatible(v3, "arm,coresight-dummy-source");
    if ( (_DWORD)result )
    {
      if ( (of_property_read_variable_u32_array(a1[95], "atid", &v11, 1, 0) & 0x80000000) != 0 )
      {
        result = 0;
      }
      else
      {
        v10 = v11;
        result = 0;
        *((_BYTE *)v9 + 17) = 1;
        *((_BYTE *)v9 + 16) = v10;
      }
    }
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}

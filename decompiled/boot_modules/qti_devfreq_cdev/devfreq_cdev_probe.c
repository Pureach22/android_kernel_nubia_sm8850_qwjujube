unsigned __int64 __fastcall devfreq_cdev_probe(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 v4; // x19
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 device_by_node; // x0
  __int64 v8; // x24
  __int64 v9; // x21
  __int64 v10; // x22
  unsigned int opp_count; // w0
  unsigned int v12; // w22
  unsigned __int64 v13; // x23
  __int64 v14; // x0
  __int64 v15; // x24
  unsigned __int64 v16; // x25
  unsigned __int64 result; // x0
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  unsigned __int64 v20; // x0
  unsigned __int64 v21; // x20
  __int64 v22; // [xsp+0h] [xbp-60h] BYREF
  _QWORD v23[11]; // [xsp+8h] [xbp-58h] BYREF

  v1 = a1 + 16;
  v23[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v22 = -1;
  v3 = devm_kmalloc(a1 + 16, 136, 3520);
  if ( !v3 )
  {
LABEL_18:
    result = 4294967284LL;
    goto LABEL_24;
  }
  v4 = v3;
  *(_QWORD *)(v3 + 8) = v1;
  v5 = *(_QWORD *)(a1 + 760);
  memset(v23, 0, 80);
  if ( (unsigned int)_of_parse_phandle_with_args(v5, "qcom,devfreq", 0, 0, 0, v23) )
    v6 = 0;
  else
    v6 = v23[0];
  *(_QWORD *)v4 = v6;
  device_by_node = of_find_device_by_node();
  if ( !device_by_node )
  {
LABEL_23:
    result = 4294967277LL;
    goto LABEL_24;
  }
  v8 = *(_QWORD *)(v4 + 8);
  v9 = device_by_node + 16;
  v10 = device_link_add(v8, device_by_node + 16, 32);
  put_device(v9);
  if ( !v10 )
  {
    dev_err(v8, "add gpu device_link fail\n");
    goto LABEL_23;
  }
  if ( !*(_DWORD *)(v10 + 960) )
  {
    result = 4294966779LL;
    goto LABEL_24;
  }
  *(_QWORD *)(v4 + 16) = v9;
  opp_count = dev_pm_opp_get_opp_count(v9);
  if ( (opp_count & 0x80000000) != 0 )
    goto LABEL_18;
  v12 = opp_count;
  v13 = 8LL * opp_count;
  v14 = devm_kmalloc(v8, v13, 3520);
  if ( !v14 )
    goto LABEL_18;
  v15 = v14;
  v22 = -1;
  if ( !v12 )
  {
LABEL_15:
    *(_DWORD *)(v4 + 36) = v12 - 1;
    *(_QWORD *)(v4 + 24) = v15;
    v19 = dev_pm_qos_add_request(v9, v4 + 48, 4, 0x7FFFFFFF);
    if ( (v19 & 0x80000000) != 0 )
    {
      v21 = v19;
    }
    else
    {
      v20 = thermal_cooling_device_register("gpu", v4, &devfreq_cdev_ops);
      *(_QWORD *)(v4 + 128) = v20;
      if ( v20 < 0xFFFFFFFFFFFFF001LL )
      {
        result = 0;
        *(_QWORD *)(a1 + 168) = v4;
        goto LABEL_24;
      }
      v21 = v20;
      dev_err(*(_QWORD *)(v4 + 8), "Cdev register failed for gpu, ret:%d\n", v20);
      *(_QWORD *)(v4 + 128) = 0;
    }
    dev_pm_qos_remove_request(v4 + 48);
    result = v21;
    goto LABEL_24;
  }
  v16 = 0;
  while ( 1 )
  {
    result = dev_pm_opp_find_freq_floor(v9, &v22);
    if ( result >= 0xFFFFFFFFFFFFF001LL )
      break;
    dev_pm_opp_put();
    if ( v13 <= v16 )
      __break(1u);
    v18 = (unsigned __int64)(v22 + 999) >> 3;
    --v22;
    *(_QWORD *)(v15 + v16) = (unsigned __int64)((v18 * (unsigned __int128)0x20C49BA5E353F7CFuLL) >> 64) >> 4;
    v16 += 8LL;
    if ( v13 == v16 )
      goto LABEL_15;
  }
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}

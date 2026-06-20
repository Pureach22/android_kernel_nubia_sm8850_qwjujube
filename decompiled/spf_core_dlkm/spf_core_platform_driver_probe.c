__int64 __fastcall spf_core_platform_driver_probe(__int64 a1)
{
  __int64 v2; // x19
  _QWORD *v3; // x0
  __int64 v4; // x8

  printk(&unk_6F1B, "spf_core_platform_driver_probe");
  v2 = a1 + 16;
  v3 = (_QWORD *)devm_kmalloc(v2, 104, 3520);
  spf_core_priv = (__int64)v3;
  if ( !v3 )
    return 4294967284LL;
  *v3 = v2;
  _mutex_init(v3 + 1, "&spf_core_priv->lock", &spf_core_platform_driver_probe___key);
  v4 = spf_core_priv;
  *(_QWORD *)(spf_core_priv + 72) = 0xFFFFFFFE00000LL;
  *(_QWORD *)(v4 + 80) = v4 + 80;
  *(_QWORD *)(v4 + 88) = v4 + 80;
  *(_QWORD *)(v4 + 96) = spf_core_add_child_devices;
  *(_BYTE *)(v4 + 64) = 1;
  if ( (unsigned int)_gpr_driver_register(qcom_spf_core_driver, &_this_module) )
    printk(&unk_7016, "spf_core_platform_driver_probe");
  digital_cdc_rsc_mgr_init();
  return 0;
}

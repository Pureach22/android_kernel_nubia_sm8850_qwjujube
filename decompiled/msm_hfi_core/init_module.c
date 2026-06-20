__int64 __fastcall init_module(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x30
  __int64 v5; // x20
  __int64 v6; // x3
  unsigned int v7; // w19

  v5 = v4;
  if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
    printk(&unk_1E83A, "msm_hfi_core_init", 203, a4);
  v7 = _platform_driver_register(msm_hfi_core_driver, &_this_module);
  if ( v7 )
  {
    printk(&unk_1E7BD, "msm_hfi_core_init", 208, v5);
  }
  else if ( (~msm_hfi_core_debug_level & 0x10001) == 0 )
  {
    printk(&unk_1C28B, "msm_hfi_core_init", 212, v6);
  }
  return v7;
}

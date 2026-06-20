__int64 __fastcall btfm_swr_register_hw_ep(__int64 *a1)
{
  __int64 v1; // x19
  __int64 v2; // x0
  unsigned int v3; // w19
  __int64 v4; // x20

  v1 = *a1;
  printk(&unk_7265, "btfm_swr_register_hw_ep");
  v2 = _kmalloc_cache_noprof(_kcfi_typeid_snd_soc_info_enum_double, 3520, 112);
  if ( v2 )
  {
    v4 = v2;
    *(_QWORD *)v2 = v1;
    strcpy((char *)(v2 + 8), "btfmswr_slave");
    *(_QWORD *)(v2 + 72) = btfmswr_hw_driver;
    *(_QWORD *)(v2 + 80) = &btfmswr_dai_driver;
    *(_DWORD *)(v2 + 96) = 5;
    printk(&unk_7429, "btfm_swr_register_hw_ep");
    *(_DWORD *)(v4 + 100) = 3;
    *(_QWORD *)(v4 + 88) = &status_controls;
    v3 = btfmcodec_register_hw_ep(v4);
    kfree(v4);
    if ( v3 )
      printk(&unk_7725, "btfm_swr_register_hw_ep");
    else
      printk(&unk_7297, "btfm_swr_register_hw_ep");
  }
  else
  {
    printk(&unk_733F, "btfm_swr_register_hw_ep");
    return (unsigned int)-12;
  }
  return v3;
}

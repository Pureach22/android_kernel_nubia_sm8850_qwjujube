__int64 __fastcall btfm_slim_register_hw_ep(__int64 *a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x19
  __int64 v4; // x0
  unsigned int v6; // w0
  __int64 v7; // x2
  unsigned int v8; // w19

  v3 = *a1;
  printk(&unk_8698, "btfm_slim_register_hw_ep", a3);
  v4 = _kmalloc_cache_noprof(class_destroy, 3520, 112);
  if ( v4 )
  {
    *(_QWORD *)v4 = v3;
    strcpy((char *)(v4 + 8), "btfmslim");
    *(_QWORD *)(v4 + 72) = btfmslim_hw_driver;
    *(_QWORD *)(v4 + 80) = &btfmslim_dai_driver;
    *(_QWORD *)(v4 + 88) = &status_controls;
    *(_QWORD *)(v4 + 96) = 0x300000002LL;
    v6 = btfmcodec_register_hw_ep();
    if ( v6 )
    {
      v8 = v6;
      printk(&unk_8DDC, "btfm_slim_register_hw_ep", v6);
      return v8;
    }
    else
    {
      printk(&unk_86CA, "btfm_slim_register_hw_ep", v7);
      return 0;
    }
  }
  else
  {
    printk(&unk_8761, "btfm_slim_register_hw_ep", "btfm_slim_register_hw_ep");
    return 4294967284LL;
  }
}

__int64 __fastcall btfmcodec_unregister_hw_ep(const char *a1)
{
  __int64 btfmcodec; // x19
  __int64 v3; // x21
  void *v4; // x0

  btfmcodec = btfm_get_btfmcodec();
  mutex_lock(btfmcodec + 1040);
  if ( btfmcodec )
  {
    v3 = *(_QWORD *)(btfmcodec + 984);
    if ( v3 )
    {
      if ( !strncmp((const char *)(v3 + 8), a1, 0x40u) )
      {
        btfm_unregister_codec();
        kfree(v3);
        v4 = &unk_CBD0;
      }
      else
      {
        v4 = &unk_D499;
      }
      printk(v4, "btfmcodec_unregister_hw_ep");
    }
    else
    {
      printk(&unk_C86D, "btfmcodec_unregister_hw_ep");
    }
  }
  else
  {
    printk(&unk_C74B, "btfmcodec_unregister_hw_ep");
  }
  mutex_unlock(btfmcodec + 1040);
  return 0xFFFFFFFFLL;
}

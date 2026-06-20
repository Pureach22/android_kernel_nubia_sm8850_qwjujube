__int64 __fastcall msm_vidc_fw_unload_handler(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x20
  int v3; // w19
  void *v4; // x0
  __int64 v5; // x20

  v1 = result - 6232;
  if ( result == 6232 )
  {
    if ( (msm_vidc_debug & 1) != 0 )
    {
      v4 = &unk_8E4ED;
      return printk(v4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_fw_unload_handler");
    }
  }
  else
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      v5 = result;
      printk(&unk_84F3A, "high", 0xFFFFFFFFLL, "codec", "msm_vidc_fw_unload_handler");
      result = v5;
    }
    v2 = result - 2376;
    mutex_lock(result - 2376);
    v3 = msm_vidc_core_deinit_locked(v1, 0);
    result = mutex_unlock(v2);
    if ( v3 && (msm_vidc_debug & 1) != 0 )
    {
      v4 = &unk_8A85A;
      return printk(v4, "err ", 0xFFFFFFFFLL, "codec", "msm_vidc_fw_unload_handler");
    }
  }
  return result;
}

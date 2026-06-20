__int64 __fastcall handle_system_init(__int64 a1, __int64 a2)
{
  if ( (*(_DWORD *)(a2 + 8) & 1) != 0 )
  {
    core_lock(a1);
    if ( *(_DWORD *)(a2 + 20) == *(_DWORD *)(a1 + 6608) )
    {
      msm_vidc_change_core_state(a1, 2u, (__int64)"handle_system_init");
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_90CDF, "high", 0xFFFFFFFFLL, "codec", "handle_system_init");
    }
    else if ( (msm_vidc_debug & 1) != 0 )
    {
      printk(&unk_934C6, "err ", 0xFFFFFFFFLL, "codec", "handle_system_init");
    }
    core_unlock(a1);
  }
  else if ( (msm_vidc_debug & 2) != 0 )
  {
    printk(&unk_8F7B8, "high", 0xFFFFFFFFLL, "codec", "handle_system_init");
  }
  return 0;
}

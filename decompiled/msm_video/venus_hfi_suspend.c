__int64 __fastcall venus_hfi_suspend(__int64 a1)
{
  __int64 v2; // x4

  if ( (mutex_is_locked(a1 + 3856) & 1) != 0 )
  {
    if ( *(_QWORD *)(a1 + 4288) )
    {
      if ( (msm_vidc_debug & 2) != 0 )
        printk(&unk_8C50C, "high", 0xFFFFFFFFLL, "codec", v2);
      if ( (unsigned int)_power_collapse(a1, 1) )
      {
        if ( (msm_vidc_debug & 1) != 0 )
          printk(&unk_83BBA, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_suspend");
        return 4294967280LL;
      }
      if ( *(_QWORD *)(a1 + 4288) )
        cancel_delayed_work(a1 + 6112);
    }
    else if ( (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_93FD4, "high", 0xFFFFFFFFLL, "codec", v2);
    }
    return 0;
  }
  __break(0x800u);
  if ( (msm_vidc_debug & 1) != 0 )
    printk(&unk_94E60, "err ", 0xFFFFFFFFLL, "codec", "venus_hfi_suspend");
  return 4294967274LL;
}

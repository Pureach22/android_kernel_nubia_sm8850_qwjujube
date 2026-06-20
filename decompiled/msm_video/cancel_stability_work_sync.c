__int64 __fastcall cancel_stability_work_sync(__int64 a1)
{
  if ( a1 )
  {
    cancel_work_sync(a1 + 3920);
    return 0;
  }
  else
  {
    if ( (msm_vidc_debug & 1) != 0 )
      printk(&unk_8E20F, "err ", 0xFFFFFFFFLL, "codec", "cancel_stability_work_sync");
    return 4294967274LL;
  }
}

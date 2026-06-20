__int64 __fastcall lpass_cdc_rx_macro_core_vote(__int64 *a1, char a2)
{
  __int64 v3; // x0
  __int64 v5; // x0
  __int64 v6; // x19

  if ( !a1 )
  {
    if ( (unsigned int)__ratelimit(&lpass_cdc_rx_macro_core_vote__rs, "lpass_cdc_rx_macro_core_vote") )
    {
      printk(&unk_F527, "lpass_cdc_rx_macro_core_vote");
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  if ( (a2 & 1) != 0 && (*((_BYTE *)a1 + 95) & 1) == 0 )
    return 4294967274LL;
  v3 = *a1;
  if ( (a2 & 1) != 0 )
  {
    _pm_runtime_resume(v3, 4);
    if ( (lpass_cdc_check_core_votes(*a1) & 1) != 0 )
      return 0;
    else
      return 4294966774LL;
  }
  else
  {
    v5 = _pm_runtime_suspend(v3, 13);
    v6 = *a1;
    *(_QWORD *)(v6 + 520) = ktime_get_mono_fast_ns(v5);
    return 0;
  }
}

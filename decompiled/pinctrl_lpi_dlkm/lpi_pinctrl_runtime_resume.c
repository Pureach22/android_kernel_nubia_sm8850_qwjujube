__int64 __fastcall lpi_pinctrl_runtime_resume(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x20

  v1 = *(_QWORD *)(a1 + 152);
  v3 = *(_QWORD *)(v1 + 648);
  if ( v3 || (v3 = *(_QWORD *)(v1 + 656)) != 0 )
  {
    mutex_lock(v1 + 720);
    if ( (digital_cdc_rsc_mgr_hw_vote_enable(v3, a1) & 0x80000000) != 0 )
    {
      pm_runtime_set_autosuspend_delay(a1, 1);
      if ( (unsigned int)__ratelimit(&lpi_pinctrl_runtime_resume__rs, "lpi_pinctrl_runtime_resume") )
        dev_err(a1, "%s:lpass core hw island enable failed\n", "lpi_pinctrl_runtime_resume");
    }
    else
    {
      *(_BYTE *)(v1 + 712) = 1;
      pm_runtime_set_autosuspend_delay(a1, 100);
    }
    mutex_unlock(v1 + 720);
  }
  return 0;
}

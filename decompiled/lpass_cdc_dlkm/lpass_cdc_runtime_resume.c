__int64 __fastcall lpass_cdc_runtime_resume(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  mutex_lock(v2 + 168);
  if ( *(_QWORD *)(v2 + 856) )
  {
    v3 = *(_DWORD *)(v2 + 872);
    if ( v3 )
    {
LABEL_5:
      *(_DWORD *)(v2 + 872) = v3 + 1;
      goto LABEL_6;
    }
    if ( (digital_cdc_rsc_mgr_hw_vote_enable() & 0x80000000) == 0 )
    {
      v3 = *(_DWORD *)(v2 + 872);
      goto LABEL_5;
    }
    if ( (unsigned int)__ratelimit(&lpass_cdc_runtime_resume__rs, "lpass_cdc_runtime_resume") )
      dev_err(a1, "%s:lpass core hw enable failed\n", "lpass_cdc_runtime_resume");
  }
LABEL_6:
  if ( !*(_QWORD *)(v2 + 864) )
    goto LABEL_15;
  v4 = *(_DWORD *)(v2 + 876);
  if ( !v4 )
  {
    if ( (digital_cdc_rsc_mgr_hw_vote_enable() & 0x80000000) != 0 )
    {
      if ( (unsigned int)__ratelimit(&lpass_cdc_runtime_resume__rs_39, "lpass_cdc_runtime_resume") )
        dev_err(a1, "%s:lpass audio hw enable failed\n", "lpass_cdc_runtime_resume");
      goto LABEL_11;
    }
    v4 = *(_DWORD *)(v2 + 876);
  }
  *(_DWORD *)(v2 + 876) = v4 + 1;
LABEL_11:
  v5 = *(_DWORD *)(v2 + 880);
  if ( v5 )
  {
LABEL_14:
    *(_DWORD *)(v2 + 880) = v5 + 1;
    goto LABEL_15;
  }
  if ( (lpass_cdc_clk_rsc_request_clock(a1, 0, 0, 1) & 0x80000000) == 0 )
  {
    v5 = *(_DWORD *)(v2 + 880);
    goto LABEL_14;
  }
  if ( (unsigned int)__ratelimit(&lpass_cdc_runtime_resume__rs_41, "lpass_cdc_runtime_resume") )
    dev_err(a1, "%s:lpass Tx core clk enable failed\n", "lpass_cdc_runtime_resume");
LABEL_15:
  mutex_unlock(v2 + 168);
  pm_runtime_set_autosuspend_delay(*(_QWORD *)v2, 100);
  return 0;
}

__int64 __fastcall lpass_bt_swr_runtime_resume(__int64 a1)
{
  __int64 v1; // x20
  int v3; // w8
  int v4; // w8

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 8);
  if ( *(_QWORD *)(v1 + 160) )
  {
    v3 = *(_DWORD *)(v1 + 176);
    if ( v3 )
    {
LABEL_5:
      *(_DWORD *)(v1 + 176) = v3 + 1;
      goto LABEL_6;
    }
    if ( (digital_cdc_rsc_mgr_hw_vote_enable() & 0x80000000) == 0 )
    {
      v3 = *(_DWORD *)(v1 + 176);
      goto LABEL_5;
    }
    if ( (unsigned int)__ratelimit(&lpass_bt_swr_runtime_resume__rs, "lpass_bt_swr_runtime_resume") )
      dev_err(a1, "%s:lpass core hw enable failed\n", "lpass_bt_swr_runtime_resume");
  }
LABEL_6:
  if ( *(_QWORD *)(v1 + 168) )
  {
    v4 = *(_DWORD *)(v1 + 180);
    if ( v4 )
    {
LABEL_10:
      *(_DWORD *)(v1 + 180) = v4 + 1;
      goto LABEL_11;
    }
    if ( (digital_cdc_rsc_mgr_hw_vote_enable() & 0x80000000) == 0 )
    {
      v4 = *(_DWORD *)(v1 + 180);
      goto LABEL_10;
    }
    if ( (unsigned int)__ratelimit(&lpass_bt_swr_runtime_resume__rs_1, "lpass_bt_swr_runtime_resume") )
      dev_err(a1, "%s:lpass audio hw enable failed\n", "lpass_bt_swr_runtime_resume");
  }
LABEL_11:
  mutex_unlock(v1 + 8);
  pm_runtime_set_autosuspend_delay(*(_QWORD *)v1, 100);
  return 0;
}

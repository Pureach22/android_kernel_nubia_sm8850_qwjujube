__int64 __fastcall lpass_cdc_runtime_suspend(__int64 a1)
{
  __int64 v2; // x20
  int v3; // w8
  int v4; // w8
  int v5; // w8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  mutex_lock(v2 + 168);
  if ( *(_QWORD *)(v2 + 856) )
  {
    v3 = *(_DWORD *)(v2 + 872) - 1;
    *(_DWORD *)(v2 + 872) = v3;
    if ( v3 )
    {
      if ( (v3 & 0x80000000) == 0 )
        goto LABEL_4;
LABEL_9:
      *(_DWORD *)(v2 + 872) = 0;
      if ( !*(_QWORD *)(v2 + 864) )
        goto LABEL_13;
      goto LABEL_5;
    }
    digital_cdc_rsc_mgr_hw_vote_disable();
    if ( (*(_DWORD *)(v2 + 872) & 0x80000000) != 0 )
      goto LABEL_9;
  }
LABEL_4:
  if ( !*(_QWORD *)(v2 + 864) )
    goto LABEL_13;
LABEL_5:
  v4 = *(_DWORD *)(v2 + 876) - 1;
  *(_DWORD *)(v2 + 876) = v4;
  if ( v4 )
  {
    if ( (v4 & 0x80000000) == 0 )
      goto LABEL_13;
  }
  else
  {
    digital_cdc_rsc_mgr_hw_vote_disable();
    if ( (*(_DWORD *)(v2 + 876) & 0x80000000) == 0 )
      goto LABEL_13;
  }
  *(_DWORD *)(v2 + 876) = 0;
LABEL_13:
  v5 = *(_DWORD *)(v2 + 880) - 1;
  *(_DWORD *)(v2 + 880) = v5;
  if ( !v5 )
  {
    lpass_cdc_clk_rsc_request_clock(a1, 0, 0, 0);
    if ( (*(_DWORD *)(v2 + 880) & 0x80000000) == 0 )
      goto LABEL_15;
LABEL_17:
    *(_DWORD *)(v2 + 880) = 0;
    goto LABEL_15;
  }
  if ( v5 < 0 )
    goto LABEL_17;
LABEL_15:
  mutex_unlock(v2 + 168);
  return 0;
}

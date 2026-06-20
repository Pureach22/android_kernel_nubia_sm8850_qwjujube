__int64 __fastcall lpass_bt_swr_runtime_suspend(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w8
  int v3; // w8

  v1 = *(_QWORD *)(a1 + 152);
  mutex_lock(v1 + 8);
  if ( !*(_QWORD *)(v1 + 160) )
    goto LABEL_4;
  v2 = *(_DWORD *)(v1 + 176) - 1;
  *(_DWORD *)(v1 + 176) = v2;
  if ( !v2 )
  {
    digital_cdc_rsc_mgr_hw_vote_disable();
    if ( (*(_DWORD *)(v1 + 176) & 0x80000000) != 0 )
      goto LABEL_9;
LABEL_4:
    if ( !*(_QWORD *)(v1 + 168) )
      goto LABEL_13;
    goto LABEL_5;
  }
  if ( (v2 & 0x80000000) == 0 )
    goto LABEL_4;
LABEL_9:
  *(_DWORD *)(v1 + 176) = 0;
  if ( !*(_QWORD *)(v1 + 168) )
    goto LABEL_13;
LABEL_5:
  v3 = *(_DWORD *)(v1 + 180) - 1;
  *(_DWORD *)(v1 + 180) = v3;
  if ( v3 )
  {
    if ( v3 < 0 )
      goto LABEL_12;
  }
  else
  {
    digital_cdc_rsc_mgr_hw_vote_disable();
    if ( (*(_DWORD *)(v1 + 180) & 0x80000000) != 0 )
LABEL_12:
      *(_DWORD *)(v1 + 180) = 0;
  }
LABEL_13:
  mutex_unlock(v1 + 8);
  return 0;
}

__int64 __fastcall msm_qos_ctl_get(__int64 a1, __int64 a2)
{
  *(_DWORD *)(a2 + 72) = qos_vote_status;
  return 0;
}

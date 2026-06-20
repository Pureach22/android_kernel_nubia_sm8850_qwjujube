__int64 __fastcall msm_vote_against_sleep_ctl_get(__int64 a1, __int64 a2)
{
  *(_QWORD *)(a2 + 72) = (unsigned __int8)vote_against_sleep_enable;
  return 0;
}

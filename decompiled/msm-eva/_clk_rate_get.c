__int64 __fastcall clk_rate_get(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x8

  v2 = msm_cvp_clock_voting;
  if ( !msm_cvp_clock_voting )
    v2 = *(unsigned int *)(**(_QWORD **)(*(_QWORD *)(cvp_driver + 48) + 256LL) + 24LL);
  *a2 = v2;
  return 0;
}

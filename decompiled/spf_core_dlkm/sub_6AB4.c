__int64 __fastcall sub_6AB4(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned __int64 v6; // x24
  __int64 v7; // x26

  return digital_cdc_rsc_mgr_hw_vote_enable(a1, a2, a3, a4, a5, a6, v7 | ~(v6 >> 46));
}

__int64 __fastcall policy_mgr_is_dynamic_sbs_enabled(__int64 a1)
{
  __int64 context; // x0
  __int64 v3; // x19

  context = policy_mgr_get_context(a1);
  if ( context )
  {
    v3 = context;
    LOBYTE(context) = (policy_mgr_is_hw_sbs_capable(a1) & 1) != 0 && policy_mgr_can_2ghz_share_low_high_5ghz_sbs(v3);
  }
  return context & 1;
}

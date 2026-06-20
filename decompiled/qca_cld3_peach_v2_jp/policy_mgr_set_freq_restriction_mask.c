__int64 __fastcall policy_mgr_set_freq_restriction_mask(__int64 result, __int64 a2)
{
  *(_DWORD *)(result + 2672) = *(_DWORD *)(a2 + 676);
  return result;
}

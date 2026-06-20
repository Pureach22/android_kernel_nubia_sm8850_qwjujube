__int64 __fastcall sub_4AA408(__int64 a1, __int64 a2)
{
  return dp_get_soc_context_size(a1, a2, _ReadStatusReg(CNTVCTSS_EL0), 0);
}

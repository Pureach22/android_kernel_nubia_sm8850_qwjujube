bool __fastcall ipa_nat_ipv6ct_is_entry_zeroed_v_4_0(_QWORD *a1)
{
  __int64 v1; // x11
  __int64 v2; // x8

  _ReadStatusReg(SP_EL0);
  v1 = a1[7];
  v2 = *a1 | a1[1] | a1[2] | a1[3] | a1[4] | a1[5] | a1[6];
  _ReadStatusReg(SP_EL0);
  return (v2 | v1) == 0;
}

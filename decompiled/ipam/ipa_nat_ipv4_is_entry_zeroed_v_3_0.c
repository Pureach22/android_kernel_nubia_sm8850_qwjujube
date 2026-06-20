bool __fastcall ipa_nat_ipv4_is_entry_zeroed_v_3_0(_QWORD *a1)
{
  __int64 v1; // x8
  __int64 v2; // x9

  _ReadStatusReg(SP_EL0);
  v1 = *a1 | a1[1];
  v2 = a1[2] | a1[3];
  _ReadStatusReg(SP_EL0);
  return (v1 | v2) == 0;
}

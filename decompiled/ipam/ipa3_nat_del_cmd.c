__int64 __fastcall ipa3_nat_del_cmd(unsigned __int8 *a1)
{
  __int64 result; // x0
  __int16 v2; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v3; // [xsp+8h] [xbp-8h]

  v3 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  result = ipa3_del_nat_table(&v2);
  _ReadStatusReg(SP_EL0);
  return result;
}

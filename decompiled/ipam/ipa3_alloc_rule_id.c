__int64 __fastcall ipa3_alloc_rule_id(__int64 a1)
{
  unsigned int v2; // w20
  unsigned int v3; // w0

  v2 = ((__int64 (*)(void))ipahal_get_low_rule_id)();
  v3 = ((__int64 (*)(void))ipahal_get_rule_id_hi_bit)();
  return idr_alloc(a1, 0, v2, v3, 3264);
}

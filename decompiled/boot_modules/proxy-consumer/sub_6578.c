__int64 __fastcall sub_6578(__int64 a1, __int64 a2)
{
  unsigned __int64 *v2; // x12
  int v3; // kr00_4

  v3 = __ldaxp(v2);
  LODWORD(a2) = v3;
  return devm_regulator_proxy_consumer_register(a1, a2);
}

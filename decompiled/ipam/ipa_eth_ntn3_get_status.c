__int64 __fastcall ipa_eth_ntn3_get_status(__int64 a1, int a2)
{
  bool v2; // zf
  unsigned int v4; // w1
  __int64 v5; // x0
  unsigned int v6; // w20

  v2 = a2 == 0;
  if ( a2 )
    v4 = 117;
  else
    v4 = 49;
  v5 = a1 + 36;
  if ( v2 )
    v6 = 48;
  else
    v6 = 116;
  _ipa_ntn3_cons_stats_get(v5, v4);
  return ((__int64 (__fastcall *)(__int64, _QWORD))_ipa_ntn3_prod_stats_get)(a1, v6);
}

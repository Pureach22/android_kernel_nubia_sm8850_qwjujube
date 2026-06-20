__int64 *__fastcall ieee80211_tx_set_protected(__int64 a1)
{
  __int64 *result; // x0
  __int64 *i; // x8
  __int64 *v3; // t1

  v3 = *(__int64 **)(a1 + 8);
  result = (__int64 *)(a1 + 8);
  for ( i = v3; i != result; i = (__int64 *)*i )
    *(_WORD *)i[28] |= 0x4000u;
  return result;
}

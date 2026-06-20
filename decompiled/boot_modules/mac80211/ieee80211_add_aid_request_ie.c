__int64 __fastcall ieee80211_add_aid_request_ie(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  result = skb_put(a2, 3);
  *(_WORD *)result = 466;
  *(_BYTE *)(result + 2) = 0;
  return result;
}

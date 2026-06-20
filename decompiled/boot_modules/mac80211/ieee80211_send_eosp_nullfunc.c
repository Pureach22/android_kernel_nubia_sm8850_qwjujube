__int64 __fastcall ieee80211_send_eosp_nullfunc(__int64 a1, __int64 a2)
{
  _BOOL8 v2; // x4

  v2 = (ieee80211_ac_to_qos_mask[0] & (unsigned __int8)~*(_BYTE *)(a1 + 11)) == 0
    && (*(_QWORD *)(a1 - 2360) != a1 - 2360 || *(_QWORD *)(a1 - 2456) != a1 - 2456)
    || (~*(_BYTE *)(a1 + 11) & 2) == 0 && (*(_QWORD *)(a1 - 2336) != a1 - 2336 || *(_QWORD *)(a1 - 2432) != a1 - 2432)
    || (~*(_BYTE *)(a1 + 11) & 8) == 0 && (*(_QWORD *)(a1 - 2312) != a1 - 2312 || *(_QWORD *)(a1 - 2408) != a1 - 2408)
    || (~*(_BYTE *)(a1 + 11) & 4) == 0 && (*(_QWORD *)(a1 - 2288) != a1 - 2288 || *(_QWORD *)(a1 - 2384) != a1 - 2384);
  return ieee80211_send_null_response(a1 - 2688, a2, 1, 0, v2);
}

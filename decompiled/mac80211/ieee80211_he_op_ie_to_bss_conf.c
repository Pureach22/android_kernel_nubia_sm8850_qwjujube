__int64 __fastcall ieee80211_he_op_ie_to_bss_conf(__int64 result, __int64 a2)
{
  *(_QWORD *)(result + 404) = 0;
  if ( a2 )
  {
    *(_DWORD *)(result + 404) = *(_DWORD *)a2;
    *(_WORD *)(result + 408) = *(_WORD *)(a2 + 4);
  }
  return result;
}

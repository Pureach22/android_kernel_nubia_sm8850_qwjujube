__int64 __fastcall sub_56BEC(__int64 a1, __int64 a2)
{
  if ( !(_DWORD)a2 )
    JUMPOUT(0x42ED0);
  return ieee80211_send_4addr_nullfunc(a1, a2);
}

__int64 __fastcall sub_A0C44(__int64 a1, __int64 a2)
{
  if ( !(_DWORD)a2 )
    JUMPOUT(0x8CF28);
  return ieee80211_txq_remove_vlan(a1, a2);
}

__int64 __fastcall sub_56ACC(__int64 a1, int a2)
{
  if ( !a2 )
    JUMPOUT(0x42DB0);
  return ieee80211_send_pspoll();
}

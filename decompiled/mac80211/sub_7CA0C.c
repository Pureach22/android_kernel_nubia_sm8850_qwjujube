__int64 sub_7CA0C()
{
  __int16 v0; // w12

  if ( (v0 & 0x2000) == 0 )
    JUMPOUT(0x74C48);
  return ieee80211_send_eosp_nullfunc();
}

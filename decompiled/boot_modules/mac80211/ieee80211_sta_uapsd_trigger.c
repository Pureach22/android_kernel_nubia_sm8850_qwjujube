__int64 __fastcall ieee80211_sta_uapsd_trigger(__int64 result, char a2)
{
  unsigned __int64 v8; // x9

  _X8 = ieee802_1d_to_ac[a2 & 7];
  if ( (unsigned int)_X8 >= 4 )
  {
    __break(0x5512u);
LABEL_10:
    __asm { PRFM            #0x11, [X8] }
    do
      v8 = __ldxr((unsigned __int64 *)_X8);
    while ( __stxr(v8 | 0x20000, (unsigned __int64 *)_X8) );
    return result;
  }
  if ( a2 == 16 || ((unsigned __int8)ieee80211_ac_to_qos_mask[_X8] & *(_BYTE *)(result + 11)) != 0 )
  {
    _X8 = result - 2472;
    if ( (*(_QWORD *)(result - 2472) & 0x40000) == 0 )
    {
      if ( (*(_QWORD *)_X8 & 0x200) == 0 )
        return ieee80211_sta_ps_deliver_uapsd(result - 2688);
      goto LABEL_10;
    }
  }
  return result;
}

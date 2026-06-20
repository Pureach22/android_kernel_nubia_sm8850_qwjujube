__int64 __fastcall ieee80211_beacon_get_template_ema_list(unsigned __int64 a1, _DWORD *a2, unsigned int a3)
{
  _QWORD v4[2]; // [xsp+0h] [xbp-10h] BYREF

  v4[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4[0] = 0;
  if ( _ieee80211_beacon_get(a1, a2, 0, 1, a3, 0, v4) )
    __break(0x800u);
  _ReadStatusReg(SP_EL0);
  return v4[0];
}

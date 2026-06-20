__int64 __fastcall hdd_convert_cfgdot11mode_to_80211mode(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0xC )
    return 7;
  else
    return dword_A054E0[a1 - 1];
}

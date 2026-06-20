bool __fastcall ieee80211_smps_is_restrictive(int a1, int a2)
{
  if ( a1 && a2 )
  {
    switch ( a1 )
    {
      case 1:
        return a2 != 1;
      case 2:
        return 0;
      case 3:
        return a2 == 2;
    }
  }
  __break(0x800u);
  return 0;
}

__int64 __fastcall ieee80211_suspend(__int64 a1)
{
  if ( !a1 )
  {
    __break(0x800u);
    JUMPOUT(0x34CBC);
  }
  return _ieee80211_suspend(a1 + 1536);
}

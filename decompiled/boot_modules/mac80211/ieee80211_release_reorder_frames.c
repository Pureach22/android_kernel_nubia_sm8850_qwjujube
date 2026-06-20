__int64 __fastcall ieee80211_release_reorder_frames(__int64 result, __int16 a2)
{
  __int64 v2; // x19

  if ( ((*(_WORD *)(result + 144) - a2) & 0xFFFu) >= 0x801 )
  {
    v2 = result;
    do
      result = ieee80211_release_reorder_frame(v2);
    while ( ((*(_WORD *)(v2 + 144) - a2) & 0xFFFu) > 0x800 );
  }
  return result;
}

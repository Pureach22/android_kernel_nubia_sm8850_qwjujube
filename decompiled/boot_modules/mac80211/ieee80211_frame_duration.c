__int64 __fastcall ieee80211_frame_duration(int a1, __int64 a2, int a3, int a4, int a5)
{
  int v5; // w9

  if ( a1 == 1 || a4 )
    return 4 * (unsigned int)((4 * a3 + 80 * a2 + 539) / (unsigned __int64)(4 * a3)) + 36;
  if ( a5 )
    v5 = 106;
  else
    v5 = 202;
  return (unsigned int)((a3 + 80 * a2 + 319) / (unsigned __int64)a3) + v5;
}

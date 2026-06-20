__int64 __fastcall ieee80211_generic_frame_duration(__int64 a1, __int64 a2, int a3, __int64 a4, unsigned __int8 *a5)
{
  int v5; // w8
  int v6; // w9
  unsigned __int64 v7; // x10
  int v8; // w8

  if ( a2 )
  {
    v5 = *(unsigned __int8 *)(a2 + 134);
    if ( *(_BYTE *)(a2 - 968) == 1 )
      v6 = (*a5 >> 4) & 1;
    else
      v6 = 0;
  }
  else
  {
    v6 = 0;
    v5 = 0;
  }
  v7 = *((unsigned __int16 *)a5 + 2);
  if ( a3 == 1 || v6 )
    return 4 * (unsigned int)((4 * v7 + 80 * a4 + 539) / (4 * v7)) + 36;
  if ( v5 )
    v8 = 106;
  else
    v8 = 202;
  return (unsigned int)((v7 + 80 * a4 + 319) / v7) + v8;
}

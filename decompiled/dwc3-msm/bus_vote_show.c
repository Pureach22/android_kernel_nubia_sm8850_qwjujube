__int64 __fastcall bus_vote_show(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x8
  int v5; // w8
  const char *v6; // x9
  const char *v7; // x3

  v3 = *(_QWORD *)(a1 + 152);
  if ( (*(_BYTE *)(v3 + 2804) & 1) != 0 )
    return -22;
  v5 = *(_DWORD *)(v3 + 708);
  v6 = "Do not have fixed bus vote";
  if ( v5 == 4 )
    v6 = "Fixed bus vote: max";
  if ( v5 == 3 )
    v7 = "Fixed bus vote: min";
  else
    v7 = v6;
  return (int)scnprintf(a3, 4096, "%s\n", v7);
}

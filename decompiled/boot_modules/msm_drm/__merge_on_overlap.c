bool __fastcall _merge_on_overlap(unsigned __int64 *a1, unsigned __int64 *a2, unsigned __int64 *a3)
{
  unsigned __int64 v3; // x9
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x11
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x11

  v4 = *a2;
  v3 = a2[1];
  v5 = *a3;
  v6 = a3[1];
  a1[2] = 0;
  a1[3] = 0;
  *a1 = 0;
  a1[1] = 0;
  v7 = v3 + v4;
  if ( v5 <= v7 )
  {
    v8 = v6 + v5;
    if ( v4 >= v5 )
      v4 = v5;
    if ( v7 > v8 )
      v8 = v7;
    *a1 = v4;
    a1[1] = v8 - v4;
  }
  return v5 <= v7;
}

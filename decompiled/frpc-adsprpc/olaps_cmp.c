__int64 __fastcall olaps_cmp(unsigned __int64 *a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // x9
  unsigned __int64 v3; // x12
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x11
  bool v6; // zf
  unsigned int v7; // w9
  unsigned int v8; // w8

  v3 = *a2;
  v2 = a2[1];
  v5 = *a1;
  v4 = a1[1];
  v6 = v2 == v4;
  if ( v2 < v4 )
    v7 = -1;
  else
    v7 = 1;
  if ( v6 )
    v7 = 0;
  if ( v5 < v3 )
    v8 = -1;
  else
    v8 = 1;
  if ( v5 == v3 )
    return v7;
  else
    return v8;
}

unsigned __int64 __fastcall cam_soc_util_get_applied_src_clk(_QWORD *a1, char a2)
{
  unsigned __int64 v2; // x8
  unsigned __int64 v3; // x9
  unsigned __int64 v4; // x10
  unsigned __int64 v5; // x11
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9

  v2 = a1[351];
  v3 = a1[353];
  v4 = a1[355];
  if ( v2 <= v3 )
    v5 = a1[353];
  else
    v5 = a1[351];
  v6 = v3 + v2 + v4;
  if ( v5 <= v4 )
    v7 = a1[355];
  else
    v7 = v5;
  if ( (a2 & 1) != 0 )
    v6 = v7;
  if ( v6 <= a1[350] )
    return a1[350];
  else
    return v6;
}

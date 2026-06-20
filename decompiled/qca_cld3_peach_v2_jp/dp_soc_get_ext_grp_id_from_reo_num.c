__int64 __fastcall dp_soc_get_ext_grp_id_from_reo_num(unsigned __int8 *a1, char a2)
{
  int v2; // w9
  bool v3; // zf
  int v5; // w8

  v2 = 1 << a2;
  if ( a1[7801] )
    v3 = ((1 << a2) & a1[7801]) == 0;
  else
    v3 = 1;
  if ( !v3 )
    return 0;
  if ( a1[8001] && ((unsigned __int8)v2 & a1[8001]) != 0 )
    return 1;
  if ( a1[8201] && ((unsigned __int8)v2 & a1[8201]) != 0 )
    return 2;
  if ( a1[8401] && ((unsigned __int8)v2 & a1[8401]) != 0 )
    return 3;
  if ( a1[8601] && ((unsigned __int8)v2 & a1[8601]) != 0 )
    return 4;
  if ( a1[8801] && ((unsigned __int8)v2 & a1[8801]) != 0 )
    return 5;
  if ( a1[9001] && ((unsigned __int8)v2 & a1[9001]) != 0 )
    return 6;
  if ( a1[9201] && ((unsigned __int8)v2 & a1[9201]) != 0 )
    return 7;
  if ( a1[9401] && ((unsigned __int8)v2 & a1[9401]) != 0 )
    return 8;
  if ( a1[9601] && ((unsigned __int8)v2 & a1[9601]) != 0 )
    return 9;
  if ( a1[9801] && ((unsigned __int8)v2 & a1[9801]) != 0 )
    return 10;
  if ( a1[10001] && ((unsigned __int8)v2 & a1[10001]) != 0 )
    return 11;
  if ( a1[10201] && ((unsigned __int8)v2 & a1[10201]) != 0 )
    return 12;
  if ( a1[10401] && ((unsigned __int8)v2 & a1[10401]) != 0 )
    return 13;
  if ( a1[10601] && ((unsigned __int8)v2 & a1[10601]) != 0 )
    return 14;
  if ( a1[10801] && ((unsigned __int8)v2 & a1[10801]) != 0 )
    return 15;
  if ( a1[11001] && ((unsigned __int8)v2 & a1[11001]) != 0 )
    return 16;
  v5 = a1[11201];
  if ( (v2 & v5) == 0 || v5 == 0 )
    return 4294967274LL;
  else
    return 17;
}

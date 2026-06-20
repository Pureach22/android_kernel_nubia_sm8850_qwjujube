__int64 __fastcall dp_soc_get_ext_grp_id_from_reo_num(unsigned __int8 *a1, char a2)
{
  int v2; // w9
  bool v3; // zf
  int v5; // w8

  v2 = 1 << a2;
  if ( a1[7849] )
    v3 = ((1 << a2) & a1[7849]) == 0;
  else
    v3 = 1;
  if ( !v3 )
    return 0;
  if ( a1[8049] && ((unsigned __int8)v2 & a1[8049]) != 0 )
    return 1;
  if ( a1[8249] && ((unsigned __int8)v2 & a1[8249]) != 0 )
    return 2;
  if ( a1[8449] && ((unsigned __int8)v2 & a1[8449]) != 0 )
    return 3;
  if ( a1[8649] && ((unsigned __int8)v2 & a1[8649]) != 0 )
    return 4;
  if ( a1[8849] && ((unsigned __int8)v2 & a1[8849]) != 0 )
    return 5;
  if ( a1[9049] && ((unsigned __int8)v2 & a1[9049]) != 0 )
    return 6;
  if ( a1[9249] && ((unsigned __int8)v2 & a1[9249]) != 0 )
    return 7;
  if ( a1[9449] && ((unsigned __int8)v2 & a1[9449]) != 0 )
    return 8;
  if ( a1[9649] && ((unsigned __int8)v2 & a1[9649]) != 0 )
    return 9;
  if ( a1[9849] && ((unsigned __int8)v2 & a1[9849]) != 0 )
    return 10;
  if ( a1[10049] && ((unsigned __int8)v2 & a1[10049]) != 0 )
    return 11;
  if ( a1[10249] && ((unsigned __int8)v2 & a1[10249]) != 0 )
    return 12;
  if ( a1[10449] && ((unsigned __int8)v2 & a1[10449]) != 0 )
    return 13;
  if ( a1[10649] && ((unsigned __int8)v2 & a1[10649]) != 0 )
    return 14;
  if ( a1[10849] && ((unsigned __int8)v2 & a1[10849]) != 0 )
    return 15;
  if ( a1[11049] && ((unsigned __int8)v2 & a1[11049]) != 0 )
    return 16;
  v5 = a1[11249];
  if ( (v2 & v5) == 0 || v5 == 0 )
    return 4294967274LL;
  else
    return 17;
}

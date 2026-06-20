__int64 __fastcall lim_update_beacon(__int64 result)
{
  __int64 v1; // x19
  unsigned __int8 v2; // w8
  unsigned int v3; // w22
  __int64 v4; // x1
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  if ( *(_WORD *)(result + 3992) )
  {
    v1 = result;
    v2 = 0;
    do
    {
      v3 = v2;
      v4 = *(_QWORD *)(v1 + 12264) + 14000LL * v2;
      if ( *(_BYTE *)(v4 + 70) == 1 && *(_DWORD *)(v4 + 88) == 1 && *(_DWORD *)(v4 + 80) == 16 )
      {
        result = sch_set_fixed_beacon_fields(v1, v4);
        if ( !*(_BYTE *)(v1 + 14881) )
          result = lim_send_beacon_ind(v1, *(_QWORD *)(v1 + 12264) + 14000LL * v3, 0, v5, v6, v7, v8, v9, v10, v11, v12);
      }
      v2 = v3 + 1;
    }
    while ( *(unsigned __int16 *)(v1 + 3992) > (unsigned int)(unsigned __int8)(v3 + 1) );
  }
  return result;
}

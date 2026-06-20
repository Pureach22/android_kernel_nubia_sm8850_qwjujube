__int64 __fastcall clk_aggregate_vdd(__int64 a1)
{
  int v1; // w9
  int v2; // w20
  int v3; // w8
  __int64 v4; // x22
  __int64 v6; // x23
  int v7; // w21
  int v8; // w24
  __int64 result; // x0
  int v10; // w26
  __int64 v11; // x25
  unsigned int v12; // w0
  unsigned int v13; // w26
  unsigned int v14; // w26
  __int64 v15; // x25
  unsigned __int64 v16; // x8

  v1 = *(_DWORD *)(a1 + 48);
  v2 = *(_DWORD *)(a1 + 52);
  v3 = *(_DWORD *)(a1 + 24);
  v4 = *(_QWORD *)(a1 + 8);
  v6 = *(_QWORD *)(a1 + 32);
  v7 = v2 * v3;
  v8 = (v1 - 1) & ((v1 - 1) >> 31);
  while ( --v1 >= 1 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(a1 + 40) + 4LL * (v1 & 0x7FFFFFFF)) )
    {
      v8 = v1;
      break;
    }
  }
  if ( v8 == v2 )
    return 0;
  if ( v3 < 1 )
  {
LABEL_26:
    *(_DWORD *)(a1 + 52) = v8;
    return 0;
  }
  else
  {
    v10 = v8 * v3;
    v11 = 0;
    while ( 1 )
    {
      result = regulator_set_voltage(
                 *(_QWORD *)(v4 + 8 * v11),
                 *(unsigned int *)(v6 + 4LL * (v10 + (int)v11)),
                 0x7FFFFFFF);
      if ( (_DWORD)result )
        break;
      if ( v2 && v2 != *(_DWORD *)(a1 + 48) )
      {
        if ( !v8 )
        {
          v12 = regulator_disable(*(_QWORD *)(v4 + 8 * v11));
          if ( v12 )
          {
LABEL_17:
            v13 = v12;
            regulator_set_voltage(*(_QWORD *)(v4 + 8 * v11), *(unsigned int *)(v6 + 4LL * (v7 + (int)v11)), 0x7FFFFFFF);
            result = v13;
            break;
          }
        }
      }
      else
      {
        v12 = regulator_enable(*(_QWORD *)(v4 + 8 * v11));
        if ( v12 )
          goto LABEL_17;
      }
      if ( ++v11 >= *(int *)(a1 + 24) )
        goto LABEL_26;
    }
    if ( (_DWORD)v11 )
    {
      v14 = result;
      v15 = v11 - 1;
      do
      {
        regulator_set_voltage(*(_QWORD *)(v4 + 8 * v15), *(unsigned int *)(v6 + 4LL * (v7 + (int)v15)), 0x7FFFFFFF);
        if ( !v2 || v2 == *(_DWORD *)(a1 + 48) )
        {
          regulator_disable(*(_QWORD *)(v4 + 8 * v15));
        }
        else if ( !v8 )
        {
          regulator_enable(*(_QWORD *)(v4 + 8 * v15));
        }
        v16 = v15-- + 1;
      }
      while ( v16 > 1 );
      return v14;
    }
  }
  return result;
}

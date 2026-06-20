__int64 __fastcall mhi_get_free_desc_count(__int64 a1, int a2)
{
  __int64 v2; // x8
  _QWORD *v3; // x9
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x10

  v2 = 32;
  if ( a2 == 1 )
    v2 = 24;
  v3 = *(_QWORD **)(a1 + v2);
  v5 = v3[18];
  v4 = v3[19];
  if ( v4 >= v5 )
    return (unsigned int)((v5 - v3[17]) / v3[20]) + (unsigned int)((v3[17] + v3[21] - v4) / v3[20]) - 1;
  else
    return (unsigned int)((v5 - v4) / v3[20]) - 1;
}

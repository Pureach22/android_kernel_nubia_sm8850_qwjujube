unsigned __int16 *__fastcall sde_kms_rect_intersect(unsigned __int16 *result, unsigned __int16 *a2, _WORD *a3)
{
  unsigned int v3; // w9
  unsigned int v4; // w10
  unsigned int v5; // w11
  unsigned int v6; // w12
  unsigned int v7; // w8
  unsigned int v8; // w13
  unsigned int v9; // w10
  unsigned int v10; // w9
  unsigned int v11; // w11
  unsigned int v12; // w12
  bool v13; // cf
  unsigned int v14; // w10
  unsigned int v15; // w11

  if ( result && a2 && a3 )
  {
    v3 = *result;
    v4 = *a2;
    v5 = result[1];
    v6 = a2[1];
    if ( v3 <= v4 )
      v7 = *a2;
    else
      v7 = *result;
    v8 = result[2] + v3;
    v9 = a2[2] + v4;
    if ( v5 <= v6 )
      v10 = a2[1];
    else
      v10 = result[1];
    v11 = result[3] + v5;
    v12 = a2[3] + v6;
    if ( v8 < v9 )
      v9 = v8;
    if ( v11 >= v12 )
      v11 = v12;
    v13 = v9 >= v7;
    v14 = v9 - v7;
    if ( v14 != 0 && v13 && (v13 = v11 >= v10, v15 = v11 - v10, v15 != 0 && v13) )
    {
      *a3 = v7;
      a3[1] = v10;
      a3[2] = v14;
      a3[3] = v15;
    }
    else
    {
      *(_QWORD *)a3 = 0;
    }
  }
  return result;
}

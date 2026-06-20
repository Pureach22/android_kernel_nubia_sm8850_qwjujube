__int64 __fastcall fixup_8974_points(__int64 result, _DWORD *a2, _DWORD *a3)
{
  int v3; // w8
  __int64 v4; // x10
  int v5; // w11
  _DWORD *v6; // x8
  int v7; // w9
  int v8; // w9
  int v9; // w10
  int v10; // w11
  int v11; // w8
  int v12; // w8
  int v13; // w11
  int v14; // w10
  int v15; // w9

  v3 = *a2;
  if ( (_DWORD)result )
  {
    v4 = 10;
    v5 = 3;
    *a2 = v3 + 3;
    *a3 += 3;
    a2[1] += 3;
    a3[1] += 3;
    a2[2] += 3;
    a3[2] += 3;
    a2[3] += 3;
    a3[3] += 3;
    a2[4] += 3;
    a3[4] += 3;
    a2[5] += 3;
    a3[5] += 3;
    a2[6] += 3;
    a3[6] += 3;
    a2[7] += 3;
    a3[7] += 3;
    a2[8] += 3;
    a3[8] += 3;
    v6 = a3 + 9;
    a2[9] += 3;
    v7 = 3;
  }
  else
  {
    a3 = a2;
    v8 = a2[1] + 9;
    v9 = a2[2] + 3;
    *a2 = v3 + 2;
    a2[1] = v8;
    v10 = a2[4];
    v11 = a2[3] + 9;
    a2[2] = v9;
    a2[3] = v11;
    v12 = v10 + 5;
    v13 = a2[7];
    v14 = a2[6];
    v15 = a2[5] + 9;
    a2[4] = v12;
    a2[5] = v15;
    a2[6] = v14 + 7;
    a2[7] = v13 + 10;
    v6 = a2 + 8;
    v5 = 9;
    v7 = 8;
    v4 = 9;
  }
  *v6 += v7;
  a2[v4] += v5;
  a3[10] += v7;
  return result;
}

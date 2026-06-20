__int64 __fastcall tcs_list_gen(__int64 result, unsigned int a2, _DWORD *a3, __int64 a4)
{
  _QWORD *v4; // x8
  _QWORD *v5; // x9
  __int64 v6; // x10
  int v7; // w11
  __int64 v8; // x12
  __int64 v9; // x13
  int v10; // w16
  _BOOL4 v11; // w17
  _QWORD *v12; // x1
  unsigned __int64 v13; // x4
  unsigned __int64 v14; // x1
  int v15; // w5
  int v16; // w6
  int v17; // w5
  int v18; // w6
  int *v19; // x17
  int v20; // w1
  bool v21; // nf

  *(_DWORD *)(a4 + 40) = 0;
  *(_QWORD *)(a4 + 24) = 0;
  *(_QWORD *)(a4 + 32) = 0;
  *(_QWORD *)(a4 + 8) = 0;
  *(_QWORD *)(a4 + 16) = 0;
  *(_QWORD *)a4 = 0;
  v4 = (_QWORD *)(result + 72);
  v5 = *(_QWORD **)(result + 72);
  if ( v5 != (_QWORD *)(result + 72) )
  {
    v6 = 0;
    v7 = 0;
    v8 = 1LL << a2;
    v9 = a2;
    do
    {
      if ( (_QWORD *)*v5 == v4 || *((unsigned __int8 *)v5 - 2) != *(unsigned __int8 *)(*v5 - 2LL) )
      {
        v7 = 0;
        v10 = 1;
        v11 = ((unsigned int)v8 & *(_DWORD *)(result + 120)) != 0;
        if ( a3 )
        {
LABEL_10:
          v12 = &v5[v9];
          v13 = *(v12 - 9);
          v14 = *(v12 - 14);
          v15 = (v13 | v14) != 0;
          if ( v14 >= 0x3FFF )
            LODWORD(v14) = 0x3FFF;
          if ( v13 >= 0x3FFF )
            LODWORD(v13) = 0x3FFF;
          if ( v10 )
            v16 = 0x40000000;
          else
            v16 = 0;
          v17 = v16 | (v15 << 29);
          v18 = *((_DWORD *)v5 - 29);
          a3[2] = v11;
          *a3 = v18;
          a3[1] = v17 | ((_DWORD)v14 << 14) | v13;
        }
      }
      else
      {
        v10 = 0;
        v11 = 0;
        ++v7;
        if ( a3 )
          goto LABEL_10;
      }
      v19 = (int *)(a4 + 4 * v6);
      v20 = *v19 + 1;
      v21 = *v19 - 15 < 0;
      *v19 = v20;
      if ( v21 == __OFSUB__(v20, 16) )
      {
        if ( (v10 & 1) == 0 )
        {
          *v19 = v20 - v7;
          v19[1] = v7;
        }
        ++v6;
      }
      v5 = (_QWORD *)*v5;
      a3 += 3;
    }
    while ( v5 != v4 );
  }
  return result;
}

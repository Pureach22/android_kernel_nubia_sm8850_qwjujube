__int64 __fastcall ad4_roi_coordinate_offset(__int64 a1, __int64 a2)
{
  unsigned int *v2; // x3
  int v3; // w2
  unsigned int v4; // w2
  unsigned int v5; // w8
  unsigned int v6; // w5
  unsigned int v7; // w6
  unsigned int v8; // w9
  unsigned int v9; // w4
  __int64 v10; // x10
  unsigned int v11; // w11
  unsigned int v12; // w12
  unsigned int v13; // w9
  int v14; // w8

  v2 = *(unsigned int **)a1;
  if ( !*(_QWORD *)a1 )
  {
    *(_DWORD *)a2 = 0;
    *(_DWORD *)(a2 + 4) = *(_DWORD *)(a1 + 44);
    *(_DWORD *)(a2 + 8) = 0;
    v14 = *(_DWORD *)(a1 + 40);
    *(_QWORD *)(a2 + 16) = 0x40000000400LL;
    *(_DWORD *)(a2 + 12) = v14;
    return 0;
  }
  v3 = *(_DWORD *)(a1 + 8);
  if ( v3 != 24 )
  {
    _drm_err("invalid sz param exp %zd given %d cfg %pK\n", 0x18u, v3, v2);
    return (unsigned int)-22;
  }
  v5 = *v2;
  v4 = v2[1];
  v7 = *(_DWORD *)(a1 + 40);
  v6 = *(_DWORD *)(a1 + 44);
  v8 = v2[2];
  if ( *v2 >= v6 || v8 >= v7 )
  {
    v9 = v2[3];
LABEL_19:
    _drm_err("invalid roi=[%u,%u,%u,%u], display=[%u,%u]\n", v5, v4, v8, v9, v6, v7);
    return (unsigned int)-22;
  }
  v9 = v2[3];
  if ( v5 >= v4 || v8 >= v9 )
    goto LABEL_19;
  v10 = *(_QWORD *)(a1 + 32);
  if ( v4 > v6 )
  {
    v2[1] = v6;
    v7 = *(_DWORD *)(a1 + 40);
  }
  if ( v9 > v7 )
    v2[3] = v7;
  *(_DWORD *)a2 = v5;
  v11 = v2[1];
  *(_DWORD *)(a2 + 4) = v11;
  *(_DWORD *)(a2 + 8) = v2[2];
  *(_DWORD *)(a2 + 12) = v2[3];
  *(_DWORD *)(a2 + 16) = v2[4];
  *(_DWORD *)(a2 + 20) = v2[5];
  if ( *(_DWORD *)(a1 + 28) == 2 )
  {
    v12 = *(_DWORD *)(v10 + 376);
    if ( v2[1] > v12 )
    {
      v13 = *(unsigned __int8 *)(v10 + 384);
      if ( *v2 < v12 )
      {
        if ( !*(_BYTE *)(v10 + 384) )
        {
          *(_DWORD *)(a2 + 4) = v12;
          return v13;
        }
        v13 = 0;
        *(_DWORD *)a2 = 0;
        goto LABEL_27;
      }
      if ( *(_BYTE *)(v10 + 384) )
      {
        v13 = 0;
        *(_DWORD *)a2 = v5 - v12 + 6;
LABEL_27:
        *(_DWORD *)(a2 + 4) = v11 - *(_DWORD *)(v10 + 376) + 6;
        return v13;
      }
LABEL_28:
      *(_QWORD *)a2 = 0;
      *(_QWORD *)(a2 + 8) = 0;
      return v13;
    }
    if ( *(_BYTE *)(v10 + 384) == 1 )
    {
      v13 = 0;
      goto LABEL_28;
    }
  }
  return 0;
}

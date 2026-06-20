__int64 __fastcall qce_sps_add_sg_data(_DWORD *a1, __int64 a2, unsigned int a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v7; // w20
  _DWORD *v8; // x22
  unsigned int v9; // w8
  unsigned int v10; // w9
  unsigned __int64 v11; // x10
  int v12; // w11
  __int64 v13; // x12

  result = 0;
  if ( a3 && a2 )
  {
    v7 = a3;
    v8 = (_DWORD *)(*(_QWORD *)(a4 + 8) + 8LL * *(unsigned int *)(a4 + 16));
    while ( 1 )
    {
      v9 = *(_DWORD *)(a2 + 24);
      if ( v7 < v9 )
        v9 = v7;
      if ( a1[101] )
      {
        v10 = v9;
      }
      else
      {
        v10 = v9;
        if ( a1[102] <= 5u )
          v10 = (v9 + a1[100] - 1) & -a1[100];
      }
      if ( v10 )
        break;
LABEL_17:
      v7 -= v9;
      a2 = sg_next(a2);
      result = 0;
      if ( !v7 || !a2 )
        return result;
    }
    v11 = *(_QWORD *)(a2 + 16);
    v12 = *(_DWORD *)(a4 + 16);
    while ( v12 != 512 )
    {
      if ( v10 >= 0x7FC0 )
        v13 = 32704;
      else
        v13 = v10;
      v10 -= v13;
      *v8 = v11;
      v8[1] = (v11 >> 16) & 0xF0000 | v13;
      v8 += 2;
      v11 += v13;
      v12 = *(_DWORD *)(a4 + 16) + 1;
      *(_DWORD *)(a4 + 16) = v12;
      if ( !v10 )
        goto LABEL_17;
    }
    printk(&unk_15B74, "_qce_sps_add_sg_data", 512);
    return 4294967284LL;
  }
  return result;
}

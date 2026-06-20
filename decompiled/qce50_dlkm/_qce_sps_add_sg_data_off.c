__int64 __fastcall qce_sps_add_sg_data_off(_DWORD *a1, __int64 a2, unsigned int a3, unsigned int a4, __int64 a5)
{
  __int64 v5; // x22
  __int64 v6; // x23
  unsigned int v8; // w24
  __int64 v11; // x9
  __int64 result; // x0
  unsigned int v13; // w8
  unsigned int v14; // w25
  __int64 v15; // x0
  _DWORD *v16; // x22
  unsigned int v17; // w8
  unsigned int v18; // w10
  int v19; // w11
  unsigned __int64 v20; // x9
  __int64 v21; // x12
  __int64 v22; // x0

  if ( !a2 )
    return 4294967294LL;
  v5 = *(_QWORD *)(a5 + 8);
  v6 = *(unsigned int *)(a5 + 16);
  v8 = *(_DWORD *)(a2 + 24);
  if ( a4 )
  {
    while ( 1 )
    {
      if ( !a2 )
      {
        printk(&unk_14C43, "_qce_sps_add_sg_data_off", a4);
        return 4294967294LL;
      }
      v13 = *(_DWORD *)(a2 + 24);
      v14 = a4 - v13;
      if ( a4 < v13 )
        break;
      v15 = sg_next(a2);
      a2 = v15;
      if ( v15 )
        v8 = *(_DWORD *)(v15 + 24);
      a4 = v14;
      if ( !v14 )
        goto LABEL_3;
    }
    v8 = v13 - a4;
    v11 = a4;
    result = 0;
    if ( !a3 )
      return result;
  }
  else
  {
LABEL_3:
    v11 = 0;
    result = 0;
    if ( !a3 )
      return result;
  }
  if ( a2 )
  {
    v16 = (_DWORD *)(v5 + 8 * v6);
    while ( 1 )
    {
      v17 = a3 >= v8 ? v8 : a3;
      if ( a1[101] )
      {
        v18 = v17;
      }
      else
      {
        v18 = v17;
        if ( a1[102] <= 5u )
          v18 = (v17 + a1[100] - 1) & -a1[100];
      }
      if ( v18 )
        break;
LABEL_28:
      a3 -= v17;
      if ( !a3 )
        return 0;
      v22 = sg_next(a2);
      if ( !v22 )
      {
        printk(&unk_16379, "_qce_sps_add_sg_data_off", a3);
        return 4294967284LL;
      }
      v8 = *(_DWORD *)(v22 + 24);
      a2 = v22;
      v11 = 0;
    }
    v19 = *(_DWORD *)(a5 + 16);
    v20 = *(_QWORD *)(a2 + 16) + v11;
    while ( v19 != 512 )
    {
      if ( v18 >= 0x7FC0 )
        v21 = 32704;
      else
        v21 = v18;
      v18 -= v21;
      *v16 = v20;
      v16[1] = (v20 >> 16) & 0xF0000 | v21;
      v16 += 2;
      v20 += v21;
      v19 = *(_DWORD *)(a5 + 16) + 1;
      *(_DWORD *)(a5 + 16) = v19;
      if ( !v18 )
        goto LABEL_28;
    }
    printk(&unk_15B74, "_qce_sps_add_sg_data_off", 512);
    return 4294967284LL;
  }
  return result;
}

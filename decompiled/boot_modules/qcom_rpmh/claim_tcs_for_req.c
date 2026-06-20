__int64 __fastcall claim_tcs_for_req(__int64 a1, __int64 *a2, __int64 a3)
{
  signed int v6; // w8
  signed int v7; // w9
  unsigned int next_bit; // w0
  int v9; // w2
  int v10; // w8
  unsigned int v11; // w22
  int v12; // w8
  int *v13; // x9
  unsigned int v14; // w0
  int v15; // w8
  int v16; // w0
  int v17; // w23
  int v18; // w8
  int *v19; // x9
  unsigned int v20; // w0
  unsigned int v21; // w24
  int v22; // w26
  __int64 v23; // x21
  unsigned __int64 v24; // x20
  unsigned __int64 next_zero_bit; // x0
  int *v26; // x10
  int v27; // w11
  unsigned int v28; // w19
  int v29; // w20
  int v30; // w8
  int *v31; // x9
  bool v32; // cf
  __int64 result; // x0
  _QWORD v34[2]; // [xsp+0h] [xbp-10h] BYREF

  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_DWORD *)a2 + 4);
  v34[0] = 0;
  v7 = v6;
LABEL_2:
  next_bit = find_next_bit(a1 + 1112, (unsigned int)(*((_DWORD *)a2 + 5) + v6), v7);
  v9 = *((_DWORD *)a2 + 4);
  v10 = *((_DWORD *)a2 + 5);
  v11 = next_bit;
  if ( v10 + v9 > next_bit )
  {
    v12 = *(_DWORD *)(a1 + 40);
    v13 = *(int **)(a1 + 1664);
    if ( !v12 )
      v12 = *v13;
    v14 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v13[10] + v12 * next_bit));
    v15 = 0;
    v34[0] = v14;
    while ( 1 )
    {
      v16 = find_next_bit(v34, *((int *)a2 + 6), v15);
      v17 = v16;
      if ( *((_DWORD *)a2 + 6) <= v16 )
      {
        v6 = *((_DWORD *)a2 + 4);
        v7 = v11 + 1;
        goto LABEL_2;
      }
      v18 = *(_DWORD *)(a1 + 40);
      v19 = *(int **)(a1 + 1664);
      if ( !v18 )
        v18 = *v19;
      v20 = readl_relaxed((unsigned int *)(*(_QWORD *)(a1 + 32) + v19[12] + v18 * v11 + (unsigned int)(v19[1] * v16)));
      if ( *(_DWORD *)(a3 + 8) )
        break;
LABEL_6:
      v15 = v17 + 1;
    }
    v21 = v20;
    v22 = 0;
    while ( (cmd_db_match_resource_addr(*(unsigned int *)(*(_QWORD *)(a3 + 16) + 12LL * v22), v21) & 1) == 0 )
    {
      if ( (unsigned int)++v22 >= *(_DWORD *)(a3 + 8) )
        goto LABEL_6;
    }
    goto LABEL_26;
  }
  v23 = *a2;
  v24 = (unsigned int)(v10 + v9);
  next_zero_bit = find_next_zero_bit(*a2 + 1112, v24);
  if ( next_zero_bit >= v24 )
  {
LABEL_26:
    result = 4294967280LL;
    goto LABEL_27;
  }
  v26 = *(int **)(v23 + 1664);
  v27 = *(_DWORD *)(v23 + 40);
  v28 = next_zero_bit;
  if ( !v27 )
    v27 = *v26;
  readl_relaxed((unsigned int *)(*(_QWORD *)(v23 + 32) + v26[9] + (unsigned int)(v27 * next_zero_bit)));
  v29 = -100;
  while ( 1 )
  {
    v30 = *(_DWORD *)(v23 + 40);
    v31 = *(int **)(v23 + 1664);
    if ( !v30 )
      v30 = *v31;
    if ( (unsigned int)readl_relaxed((unsigned int *)(*(_QWORD *)(v23 + 32) + v31[9] + v30 * v28)) )
      break;
    _const_udelay(4295);
    v32 = __CFADD__(v29++, 1);
    result = 4294967280LL;
    if ( v32 )
      goto LABEL_27;
  }
  result = v28;
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return result;
}

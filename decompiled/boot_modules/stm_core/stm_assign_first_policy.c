__int64 __fastcall stm_assign_first_policy(__int64 a1, _DWORD *a2, _QWORD *a3, unsigned int a4)
{
  int v8; // w19
  __int64 v9; // x0
  unsigned int v10; // w22
  unsigned int v11; // w26
  __int64 v12; // x25
  unsigned int v13; // w28
  _DWORD *v14; // x8
  unsigned int v15; // w9
  bool v16; // cf
  unsigned int v17; // w9
  _DWORD *v18; // x0
  unsigned int v19; // w9
  _DWORD *v20; // x8
  unsigned int v21; // w9
  _DWORD *v22; // x24
  int next_zero_bit; // w0
  __int64 v24; // x8
  __int64 (*v26)(void); // x8
  __int64 v27; // x9
  unsigned int v28; // w8
  unsigned int v29; // w8
  unsigned int *v30; // x19
  unsigned int v31; // w8
  __int64 v32; // x22
  __int64 v33; // x23
  _DWORD *v34; // [xsp+18h] [xbp-28h]
  __int64 v35; // [xsp+20h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  if ( !*a3 )
    goto LABEL_8;
  v8 = 1;
  do
  {
    v9 = stp_policy_node_lookup(a1);
    if ( !a3[v8] )
      break;
    ++v8;
  }
  while ( !v9 );
  if ( !v9 )
  {
LABEL_8:
    v10 = -22;
    goto LABEL_39;
  }
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 984) + 24LL) < a4 )
  {
    v10 = -22;
    goto LABEL_38;
  }
  v35 = v9;
  stp_policy_node_get_ranges();
  raw_spin_lock(a1 + 1080);
  raw_spin_lock(a2);
  if ( a2[3] )
  {
    v10 = -22;
    __break(0x800u);
    goto LABEL_36;
  }
  v11 = 0;
  v34 = a2;
  v12 = a1 + 1088;
  v13 = a4 - 1;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v14 = *(_DWORD **)(a1 + 984);
    v15 = v14[4];
    if ( v11 < v15 || v14[5] < v11 || !*(_QWORD *)(v12 + 8LL * (v11 - v15)) )
      break;
    v16 = v11 >= v15;
    v17 = v11 - v15;
    if ( !v16 )
      goto LABEL_22;
LABEL_21:
    if ( v14[5] < v11 )
      goto LABEL_22;
    v20 = *(_DWORD **)(v12 + 8LL * v17);
    if ( *v20 )
      goto LABEL_24;
LABEL_12:
    if ( ++v11 )
    {
      a2 = v34;
      v10 = -28;
      goto LABEL_36;
    }
  }
  v18 = (_DWORD *)_kmalloc_noprof(
                    ((((unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1 + 984) + 24LL) + 63) >> 3) & 0x3FFFFFF8) + 8,
                    2336);
  if ( !v18 )
  {
    a2 = v34;
    v10 = -12;
    goto LABEL_36;
  }
  v14 = *(_DWORD **)(a1 + 984);
  *v18 = v14[6];
  *(_QWORD *)(v12 + 8LL * (v11 - v14[4])) = v18;
  v19 = v14[4];
  v16 = v11 >= v19;
  v17 = v11 - v19;
  if ( v16 )
    goto LABEL_21;
LABEL_22:
  v20 = nullptr;
LABEL_24:
  v21 = 0;
  v22 = v20 + 2;
  while ( 2 )
  {
    next_zero_bit = find_next_zero_bit(v22, 1, v21);
    if ( next_zero_bit + a4 > 1 )
      goto LABEL_12;
    if ( (v13 & next_zero_bit) != 0 )
    {
LABEL_25:
      v21 = (next_zero_bit + v13) & -a4;
      if ( v21 )
        goto LABEL_12;
      continue;
    }
    break;
  }
  v24 = 1;
  if ( a4 >= 2 )
  {
    while ( ((*(_QWORD *)&v22[2 * ((unsigned int)(next_zero_bit + v24) >> 6)] >> ((unsigned __int8)next_zero_bit
                                                                                + (unsigned __int8)v24))
           & 1) == 0 )
    {
      if ( a4 == ++v24 )
        goto LABEL_11;
    }
  }
  if ( (_DWORD)v24 != a4 )
  {
    next_zero_bit += v24;
    goto LABEL_25;
  }
LABEL_11:
  if ( next_zero_bit < 0 )
    goto LABEL_12;
  a2 = v34;
  v34[1] = v11;
  v34[2] = next_zero_bit;
  v34[3] = a4;
  if ( !*(_QWORD *)(*(_QWORD *)(a1 + 1064) + 32LL) )
  {
LABEL_46:
    v27 = *(_QWORD *)(a1 + 984);
    v28 = *(_DWORD *)(v27 + 16);
    v16 = v11 >= v28;
    v29 = v11 - v28;
    if ( v16 && *(_DWORD *)(v27 + 20) >= v11 )
      v30 = *(unsigned int **)(v12 + 8LL * v29);
    else
      v30 = nullptr;
    v31 = v34[3];
    if ( *v30 >= v31 )
    {
      v32 = (unsigned int)v34[2];
      v33 = 1LL << (31 - (unsigned __int8)__clz(v31));
      if ( find_next_bit(v30 + 2, (unsigned int)(v32 + v33), v32) >= (unsigned __int64)(unsigned int)(v32 + v33) )
        _bitmap_set(v30 + 2, (unsigned int)v32, (unsigned int)v33);
      v10 = 0;
      *v30 -= v34[3];
      goto LABEL_37;
    }
LABEL_56:
    v10 = 0;
    __break(0x800u);
    goto LABEL_37;
  }
  if ( !stp_policy_node_priv(v35) )
    goto LABEL_56;
  v26 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 1064) + 32LL);
  if ( *((_DWORD *)v26 - 1) != -1054839227 )
    __break(0x8228u);
  v10 = v26();
  if ( !v10 )
  {
    v11 = v34[1];
    goto LABEL_46;
  }
LABEL_36:
  a2[3] = 0;
LABEL_37:
  raw_spin_unlock(a2);
  raw_spin_unlock(a1 + 1080);
  v9 = v35;
LABEL_38:
  stp_policy_node_put(v9);
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return v10;
}

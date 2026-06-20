__int64 __fastcall gmu_core_reserve_gmuaddr(__int64 a1, __int64 a2, unsigned int a3, __int16 a4)
{
  int v5; // w11
  int *v7; // x22
  int v8; // w21
  int v9; // w10
  __int64 v10; // x23
  unsigned __int8 v11; // w24
  int v12; // w24
  __int64 v13; // x0
  int v14; // w8
  int v15; // w25
  int v16; // w26
  int v17; // w24
  unsigned int v18; // w27
  int v19; // w24
  int v20; // w8

  v5 = 1 << SHIBYTE(a4);
  if ( HIBYTE(a4) <= 0xCu )
    v5 = 4096;
  v7 = (int *)(*(_QWORD *)(a1 + 8224) + 24LL * a3);
  v8 = (v5 + *(_DWORD *)(a2 + 40) - 1) & -v5;
  if ( a3 != 4 || (v9 = **(_DWORD **)(a1 + 14264), v9 == 203264) || (unsigned int)(v9 - 703) > 0xFFFFFF98 )
  {
    v20 = 1 << a4;
    if ( (unsigned __int8)a4 <= 0xCu )
      v20 = 4096;
    v17 = (v20 + v7[2] - 1) & -v20;
    if ( v17 + v8 >= (unsigned int)(v7[1] + *v7) )
      goto LABEL_22;
    v7[2] = v17 + v8;
    goto LABEL_20;
  }
  v10 = a2;
  v11 = a4;
  raw_spin_lock(v7 + 3);
  if ( v11 <= 0xCu )
    v12 = 4096;
  else
    v12 = 1 << v11;
  v13 = rb_first(v7 + 4);
  v14 = *v7;
  v15 = v12 - 1;
  v16 = -v12;
  v17 = (*v7 + v12 - 1) & -v12;
  if ( v13 )
  {
    while ( 1 )
    {
      v18 = *(_DWORD *)(v13 + 24);
      if ( v17 + v8 <= v18 )
        break;
      v19 = *(_DWORD *)(v13 + 28);
      v13 = rb_next();
      v17 = (v18 + v15 + v19) & v16;
      if ( !v13 )
      {
        v14 = *v7;
        goto LABEL_13;
      }
    }
LABEL_14:
    raw_spin_unlock(v7 + 3);
    a2 = v10;
    if ( !v17 )
      goto LABEL_22;
LABEL_20:
    *(_DWORD *)(a2 + 184) = v17;
    return 0;
  }
LABEL_13:
  if ( v17 + v8 <= (unsigned int)(v7[1] + v14) )
    goto LABEL_14;
  raw_spin_unlock(v7 + 3);
LABEL_22:
  if ( (unsigned int)__ratelimit(&gmu_core_reserve_gmuaddr__rs, "gmu_core_reserve_gmuaddr") )
    dev_err(*(_QWORD *)(a1 + 1544) + 16LL, "Insufficient VA space size: %x in vma:%u\n", v8, a3);
  return 4294967284LL;
}

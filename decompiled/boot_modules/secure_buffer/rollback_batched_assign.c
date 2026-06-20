__int64 __fastcall rollback_batched_assign(__int64 a1, unsigned int a2, int *a3, unsigned __int64 a4)
{
  unsigned __int64 v6; // x21
  unsigned __int64 v8; // x23
  __int64 v9; // x22
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x10
  int *v15; // x10
  _DWORD *v16; // x11
  int v17; // w12
  int v18; // w13
  unsigned __int64 v19; // x10
  int *v20; // x9
  int v21; // t1
  unsigned int v22; // w19
  unsigned __int64 StatusReg; // x25
  __int64 v24; // x26
  int v26; // [xsp+0h] [xbp-10h] BYREF
  int v27; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v28; // [xsp+8h] [xbp-8h]

  v6 = 0x18 / a4;
  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v26 = 7;
  v27 = 3;
  v8 = 4 * (0x18 / a4);
  v9 = _kmalloc_noprof(v8, 3264);
  if ( v9 )
  {
    while ( (_DWORD)v6 )
    {
      v10 = v6 - 1;
      if ( v6 < v6 - 1 )
        v10 = v6;
      if ( v10 > 1 )
      {
        v12 = v10 + 1;
        v13 = 0;
        v14 = v12 & 1;
        if ( (v12 & 1) == 0 )
          v14 = 2;
        v11 = v12 - v14;
        v15 = a3;
        do
        {
          v16 = (_DWORD *)(v9 + 4 * v13);
          v17 = *v15;
          v18 = v15[6];
          v13 += 2;
          v15 += 12;
          *v16 = v17;
          v16[1] = v18;
        }
        while ( v11 != v13 );
      }
      else
      {
        v11 = 0;
      }
      v19 = 4 * v11;
      v20 = &a3[6 * v11];
      while ( v8 > v19 )
      {
        ++v11;
        v21 = *v20;
        v20 += 6;
        *(_DWORD *)(v9 + v19) = v21;
        v19 += 4LL;
        if ( v11 >= v6 )
          goto LABEL_14;
      }
      __break(1u);
      v8 = 4 * v6;
      StatusReg = _ReadStatusReg(SP_EL0);
      v24 = *(_QWORD *)(StatusReg + 80);
      *(_QWORD *)(StatusReg + 80) = &rollback_batched_assign__alloc_tag;
      v9 = _kmalloc_noprof(4 * v6, 3264);
      *(_QWORD *)(StatusReg + 80) = v24;
      if ( !v9 )
        goto LABEL_16;
    }
LABEL_14:
    v22 = hyp_assign_table(a1, a2, v9, v6, &v27, &v26, 1, 0);
    kfree(v9);
  }
  else
  {
LABEL_16:
    v22 = -12;
  }
  _ReadStatusReg(SP_EL0);
  return v22;
}

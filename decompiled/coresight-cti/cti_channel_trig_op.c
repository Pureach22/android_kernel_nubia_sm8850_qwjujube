__int64 __fastcall cti_channel_trig_op(__int64 a1, int a2, int a3, unsigned int a4, unsigned int a5)
{
  __int64 *v5; // x19
  unsigned __int64 v6; // x10
  __int64 v7; // x9
  int v8; // w23
  int v9; // w20
  unsigned int v10; // w22
  int v11; // w8
  int v12; // w9
  __int64 v13; // x24
  int v14; // w21
  __int64 v15; // x0
  __int64 v16; // x9
  int v17; // w8
  int v18; // w25
  bool v19; // zf
  int v20; // w10
  unsigned int v21; // w20
  int v22; // w23
  int v23; // w24
  unsigned int v24; // w10
  __int64 v25; // x8
  _QWORD *v26; // x8
  __int64 v28; // x9
  int v29; // w8
  int v30; // w10
  int v31; // w24
  unsigned int v32; // w10
  __int64 v33; // x8
  int v34; // w9
  __int64 v35; // x8

  v5 = *(__int64 **)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( *((_DWORD *)v5 + 16) <= a4 || *((_DWORD *)v5 + 17) <= a5 )
    return 4294967274LL;
  v6 = (unsigned __int64)a5 >> 6;
  v7 = 1LL << a5;
  if ( a3 )
  {
    if ( (v5[v6 + 12] & v7) != 0
      && (*((_BYTE *)v5 + 128) != 1
       || ((*(unsigned __int64 *)((char *)v5 + (((unsigned __int64)a5 >> 3) & 0x1FFFFFF8) + 112) >> a5) & 1) == 0) )
    {
      v8 = a3;
      v9 = a2;
      v10 = a5;
      v11 = 160;
      v12 = 2048;
      goto LABEL_10;
    }
    return 4294967274LL;
  }
  if ( (v5[v6 + 10] & v7) == 0 )
    return 4294967274LL;
  v8 = 0;
  v9 = a2;
  v10 = a5;
  v11 = 32;
  v12 = 1024;
LABEL_10:
  v13 = 1LL << a4;
  if ( *((_BYTE *)v5 + 1200) )
    v14 = v12;
  else
    v14 = v11;
  v15 = raw_spin_lock(v5 + 7);
  if ( !v8 )
  {
    if ( v10 < 0x80 )
    {
      v28 = (__int64)v5 + 4 * v10;
      v29 = v9;
      v19 = v9 == 0;
      v30 = *(_DWORD *)(v28 + 140);
      v21 = v30 | v13;
      v22 = v30 & ~(_DWORD)v13;
      v31 = v29;
      if ( v19 )
        v32 = v21;
      else
        v32 = v22;
      *(_DWORD *)(v28 + 140) = v32;
      raw_spin_unlock(v5 + 7);
      v33 = v5[151];
      v34 = *(_DWORD *)(v33 + 8);
      if ( !v31 )
      {
        if ( v34 == v10 )
          cti_trigin_gpio_enable(v5);
        goto LABEL_34;
      }
      if ( v34 != v10 || !*(_QWORD *)v33 )
        goto LABEL_33;
      devm_pinctrl_put();
      v26 = (_QWORD *)v5[151];
      goto LABEL_32;
    }
LABEL_43:
    __break(0x5512u);
    return cti_trigin_gpio_enable(v15);
  }
  if ( v10 > 0x7F )
    goto LABEL_43;
  v16 = (__int64)v5 + 4 * v10;
  v17 = v9;
  v18 = v8;
  v19 = v9 == 0;
  v20 = *(_DWORD *)(v16 + 652);
  v21 = v20 | v13;
  v22 = v20 & ~(_DWORD)v13;
  v23 = v17;
  if ( v19 )
    v24 = v21;
  else
    v24 = v22;
  *(_DWORD *)(v16 + 652) = v24;
  raw_spin_unlock(v5 + 7);
  if ( !v23 )
  {
    if ( v18 == 1 && *(_DWORD *)(v5[152] + 8) == v10 )
      cti_trigout_gpio_enable(v5);
    goto LABEL_34;
  }
  if ( v18 == 1 )
  {
    v25 = v5[152];
    if ( *(_DWORD *)(v25 + 8) == v10 )
    {
      if ( *(_QWORD *)v25 )
      {
        devm_pinctrl_put();
        v26 = (_QWORD *)v5[152];
LABEL_32:
        *v26 = 0;
      }
    }
  }
LABEL_33:
  v21 = v22;
LABEL_34:
  raw_spin_lock(v5 + 7);
  if ( *((_BYTE *)v5 + 77) == 1 && *((_BYTE *)v5 + 76) == 1 )
  {
    writel_relaxed(0xC5ACCE55, (unsigned int *)(*v5 + 4016));
    __dsb(0xFu);
    writel_relaxed(v21, (unsigned int *)(*v5 + (int)(v14 + 4 * v10)));
    v35 = *v5;
    __dsb(0xFu);
    writel_relaxed(0, (unsigned int *)(v35 + 4016));
  }
  raw_spin_unlock(v5 + 7);
  return 0;
}

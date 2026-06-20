unsigned __int64 __fastcall regmap_data_read_file(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v7; // x23
  __int64 v8; // x22
  unsigned int v9; // w24
  int v10; // w0
  int v11; // w8
  int cache; // w0
  __int64 *i; // x8
  unsigned int v14; // w10
  unsigned int v16; // w10
  __int64 v17; // x25
  unsigned __int64 v18; // x24
  __int64 v19; // x27
  __int64 v20; // x22
  int v21; // w8
  int v22; // w8
  __int64 **v23; // x26
  unsigned int v24; // w28
  int v25; // w20
  unsigned __int64 v26; // x23
  __int64 v27; // x0
  int v28; // w0
  int v29; // w8
  __int64 v30; // x21
  _QWORD *v31; // x9
  _QWORD *v32; // x8
  _QWORD *v34; // x24
  __int64 v35; // x9
  unsigned int v36; // w8
  unsigned int v37; // w21
  unsigned __int64 v38; // x21
  size_t v39; // x2
  size_t v40; // x1
  unsigned __int64 v41; // x8
  __int64 v42; // x21
  __int64 *j; // x8
  unsigned int v44; // w9
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v46; // x9
  __int64 v47; // x0
  unsigned __int64 v48; // x9
  unsigned __int64 v53; // x8
  unsigned __int64 v54; // x8
  unsigned __int64 v56; // x9
  unsigned __int64 v57; // x21
  __int64 v58; // x24
  __int64 v59; // [xsp+8h] [xbp-28h]
  unsigned __int64 v60; // [xsp+10h] [xbp-20h]
  __int64 v61; // [xsp+18h] [xbp-18h]
  int v62; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v63; // [xsp+28h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 32);
  v8 = *(_QWORD *)(v7 + 16);
  v9 = *(_DWORD *)(v7 + 32);
  if ( !*(_DWORD *)(v8 + 304) )
  {
    v10 = snprintf(nullptr, 0, "%x", *(_DWORD *)(v8 + 376));
    v11 = *(_DWORD *)(v8 + 128);
    *(_DWORD *)(v8 + 296) = v10;
    v11 *= 2;
    *(_DWORD *)(v8 + 300) = v11;
    *(_DWORD *)(v8 + 304) = v10 + v11 + 3;
  }
  cache = regmap_debugfs_generate_cache(v8);
  if ( cache < 0 )
    goto LABEL_28;
  mutex_lock(v8 + 328);
  for ( i = *(__int64 **)(v8 + 312); ; i = (__int64 *)*i )
  {
    if ( i == (__int64 *)(v8 + 312) )
    {
      mutex_unlock(v8 + 328);
      cache = -22;
LABEL_28:
      v18 = cache;
      goto LABEL_29;
    }
    v14 = *((_DWORD *)i + 8);
    _CF = v9 >= v14;
    v16 = v9 - v14;
    if ( _CF && *((_DWORD *)i + 9) >= v9 )
      break;
  }
  v60 = a2;
  v17 = i[2] + *(_DWORD *)(v8 + 304) * (v16 / *(_DWORD *)(v8 + 548));
  mutex_unlock(v8 + 328);
  v18 = -22;
  v19 = v17 + *a4;
  *a4 = v19;
  v20 = *(_QWORD *)(v7 + 16);
  v21 = *(_DWORD *)(v7 + 36);
  _CF = v21 != 0;
  v22 = v21 - 1;
  if ( _CF )
    LODWORD(v23) = v22;
  else
    LODWORD(v23) = 0;
  if ( *(_DWORD *)(v20 + 548) <= 1u )
    v24 = 1;
  else
    v24 = *(_DWORD *)(v20 + 548);
  if ( !a3 || v19 < 0 )
    goto LABEL_79;
  v25 = *(_DWORD *)(v7 + 32);
  if ( a3 >= 0x200000 )
    v26 = 0x200000;
  else
    v26 = a3;
  v62 = 0;
  v27 = _kmalloc_noprof(v26, 3520);
  if ( !v27 )
    goto LABEL_78;
  while ( 2 )
  {
    v61 = v27;
    if ( !*(_DWORD *)(v20 + 304) )
    {
      v28 = snprintf(nullptr, 0, "%x", *(_DWORD *)(v20 + 376));
      v29 = *(_DWORD *)(v20 + 128);
      *(_DWORD *)(v20 + 296) = v28;
      v29 *= 2;
      *(_DWORD *)(v20 + 300) = v29;
      *(_DWORD *)(v20 + 304) = v28 + v29 + 3;
    }
    v30 = *a4;
    v59 = v17;
    if ( (regmap_debugfs_generate_cache(v20) & 0x80000000) != 0 )
    {
      v17 = 0;
    }
    else
    {
      mutex_lock(v20 + 328);
      v31 = *(_QWORD **)(v20 + 312);
      v32 = (_QWORD *)(v20 + 312);
      if ( v31 == (_QWORD *)(v20 + 312) && (__break(0x800u), v31 = (_QWORD *)*v32, (_QWORD *)*v32 == v32) )
      {
        v17 = 0;
      }
      else
      {
        do
        {
          v34 = v31;
          v35 = v31[2];
          v19 = v34[3];
          if ( v30 >= v35 && v19 >= v30 )
          {
            v36 = *(_DWORD *)(v20 + 304);
            v37 = ((int)v30 - (int)v35) / v36;
            v19 = v35 + v37 * v36;
            mutex_unlock(v20 + 328);
            v17 = *((_DWORD *)v34 + 8) + *(_DWORD *)(v20 + 548) * v37;
            goto LABEL_39;
          }
          v31 = (_QWORD *)*v34;
        }
        while ( (_QWORD *)*v34 != v32 );
        v17 = *((unsigned int *)v34 + 9);
      }
      mutex_unlock(v20 + 328);
    }
LABEL_39:
    v18 = 0;
    if ( (v17 & 0x80000000) != 0 || (v24 = v25 + v24 * (_DWORD)v23, (unsigned int)v17 > v24) )
    {
LABEL_66:
      _check_object_size(v61, v18, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v46 = v60, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v46 = v60 & ((__int64)(v60 << 8) >> 8);
      v17 = v59;
      v47 = v18;
      if ( 0x8000000000LL - v18 >= v46 )
      {
        v48 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v53 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v53 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v53);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v48);
        v47 = _arch_copy_to_user(v60 & 0xFF7FFFFFFFFFFFFFLL, v61, v18);
        v54 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v56 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v56 - 4096);
        _WriteStatusReg(TTBR1_EL1, v56);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v54);
      }
      if ( v47 )
        v18 = -14;
      else
        *a4 += v18;
LABEL_74:
      kfree(v61);
      goto LABEL_79;
    }
    v25 = v61;
    v18 = 0;
    v23 = (__int64 **)(v20 + 312);
    while ( 2 )
    {
      if ( v19 < *a4 )
      {
LABEL_53:
        v42 = *(unsigned int *)(v20 + 304);
        if ( (regmap_printable(v20, (unsigned int)(*(_DWORD *)(v20 + 548) + v17)) & 1) != 0 )
        {
          v17 = (unsigned int)(*(_DWORD *)(v20 + 548) + v17);
        }
        else
        {
          mutex_lock(v20 + 328);
          for ( j = *v23; j != (__int64 *)v23; j = (__int64 *)*j )
          {
            if ( *((_DWORD *)j + 9) >= (unsigned int)v17 )
            {
              v44 = *((_DWORD *)j + 8);
              if ( v44 > (unsigned int)v17 )
              {
                v17 = v44;
                goto LABEL_62;
              }
            }
          }
          v17 = 4294967274LL;
LABEL_62:
          mutex_unlock(v20 + 328);
        }
        if ( (v17 & 0x80000000) != 0 || (v19 += v42, (unsigned int)v17 > v24) )
        {
LABEL_65:
          if ( !(v18 >> 31) )
            goto LABEL_66;
          __break(0x800u);
          v17 = v59;
          v18 = -14;
          goto LABEL_74;
        }
        continue;
      }
      break;
    }
    if ( v18 + *(unsigned int *)(v20 + 304) > v26 )
      goto LABEL_65;
    scnprintf(v61 + v18, v26 - v18, "%.*x: ", *(_DWORD *)(v20 + 296), v17);
    v38 = v18 + (unsigned int)(*(_DWORD *)(v20 + 296) + 2);
    if ( (unsigned int)regmap_read(v20, (unsigned int)v17, &v62) )
    {
      v39 = *(unsigned int *)(v20 + 300);
      if ( v26 >= v38 )
        v40 = v26 - v38;
      else
        v40 = 0;
      if ( v40 < v39 )
        goto LABEL_77;
      memset((void *)(v61 + v38), 88, v39);
    }
    else
    {
      scnprintf(v61 + v38, v26 - v38, "%.*x", *(_DWORD *)(v20 + 300), v62);
    }
    v41 = v38 + 2LL * *(_QWORD *)(v20 + 128);
    if ( v26 > v41 )
    {
      v18 = v41 + 1;
      *(_BYTE *)(v61 + v41) = 10;
      goto LABEL_53;
    }
    __break(1u);
LABEL_77:
    _fortify_panic(15);
    v57 = _ReadStatusReg(SP_EL0);
    v58 = *(_QWORD *)(v57 + 80);
    *(_QWORD *)(v57 + 80) = &regmap_read_debugfs__alloc_tag;
    v27 = _kmalloc_noprof(v26, 3520);
    *(_QWORD *)(v57 + 80) = v58;
    if ( v27 )
      continue;
    break;
  }
LABEL_78:
  v18 = -12;
LABEL_79:
  if ( *a4 >= v17 )
    *a4 -= v17;
  else
    v18 = -22;
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return v18;
}

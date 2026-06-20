__int64 __fastcall wsa883x_proc_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v8; // x28
  __int64 *v9; // x8
  __int64 v10; // x8
  __int64 v11; // x23
  int v12; // w22
  __int64 v13; // x26
  __int64 v14; // x8
  unsigned __int64 v15; // x24
  __int64 v16; // x22
  __int64 v17; // x23
  unsigned __int64 v18; // x27
  __int64 v19; // x19
  unsigned __int64 v20; // x1
  unsigned __int64 v21; // x19
  __int64 v22; // x8
  __int64 v24; // x20
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x10
  __int64 v27; // x0
  unsigned __int64 v28; // x10
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  unsigned __int64 StatusReg; // x19
  __int64 v38; // x22
  int v40; // [xsp+1Ch] [xbp-24h]
  __int64 v41; // [xsp+20h] [xbp-20h]
  __int64 v42; // [xsp+28h] [xbp-18h]
  int v43; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v44; // [xsp+38h] [xbp-8h]

  result = -22;
  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_40;
  if ( !a1 )
    goto LABEL_40;
  if ( !a3 )
    goto LABEL_40;
  if ( !a4 )
    goto LABEL_40;
  v8 = *a4;
  if ( *a4 < 0 )
    goto LABEL_40;
  v9 = *(__int64 **)(*(_QWORD *)(a1 + 40) + 696LL);
  if ( !v9 )
    goto LABEL_40;
  v10 = *v9;
  v43 = 0;
  v42 = v10;
  v11 = _kmalloc_noprof(a3, 3520);
  if ( !v11 )
    goto LABEL_39;
LABEL_8:
  v12 = scnprintf(v11, a3, "%x", 13823);
  regcache_cache_bypass(v42, 1);
  v41 = v11;
  if ( (unsigned int)(v8 + 12288) >> 9 <= 0x1A )
  {
    v13 = (unsigned int)(v12 + 2);
    v14 = (unsigned int)(v12 + 5) + v13;
    v15 = 0;
    v40 = v12;
    v16 = v11 + v13;
    v17 = v14 + 3;
    v18 = a3;
    while ( 1 )
    {
      scnprintf(v41 + v15, v18, "%.*x: ", v40, v8 + 12288);
      v19 = v15 + v13;
      if ( (unsigned int)regmap_read(v42, (unsigned int)(v8 + 12288), &v43) )
      {
        if ( a3 >= v19 )
          v20 = a3 - v19;
        else
          v20 = 0;
        if ( v20 <= 1 )
          goto LABEL_38;
        if ( v19 < 0 || v19 > a3 || v18 - v13 < 2 || (*(_WORD *)(v16 + v15) = 22616, v19 < -2) )
        {
LABEL_37:
          __break(1u);
LABEL_38:
          _fortify_panic(15);
          StatusReg = _ReadStatusReg(SP_EL0);
          v38 = *(_QWORD *)(StatusReg + 80);
          *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
          v11 = _kmalloc_noprof(a3, 3520);
          *(_QWORD *)(StatusReg + 80) = v38;
          if ( !v11 )
          {
LABEL_39:
            result = -12;
            goto LABEL_40;
          }
          goto LABEL_8;
        }
      }
      else
      {
        scnprintf(v16 + v15, v18 - v13, "%.*x", 2, v43);
        if ( v19 < -2 )
          goto LABEL_37;
      }
      if ( v13 + v15 + 2 >= a3 )
        goto LABEL_37;
      v21 = v19 + 3;
      v22 = *a4 + 1;
      *(_BYTE *)(v16 + v15 + 2) = 10;
      *a4 = v22;
      if ( v17 + v15 < a3 )
      {
        _ZF = (_DWORD)v8 == 1535;
        LODWORD(v8) = v8 + 1;
        v15 = v21;
        v18 += -3 - v13;
        if ( !_ZF )
          continue;
      }
      goto LABEL_27;
    }
  }
  v21 = 0;
LABEL_27:
  regcache_cache_bypass(v42, 0);
  if ( v21 >> 31 )
  {
    __break(0x800u);
    v24 = v41;
    v21 = -14;
  }
  else
  {
    v24 = v41;
    _check_object_size(v41, v21, 1);
    v25 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v25 + 70) & 0x20) != 0 || (v26 = a2, (*(_QWORD *)v25 & 0x4000000) != 0) )
      v26 = a2 & ((__int64)(a2 << 8) >> 8);
    v27 = v21;
    if ( 0x8000000000LL - v21 >= v26 )
    {
      v28 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = *(_QWORD *)(v25 + 8);
      _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v28);
      v27 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v41, v21);
      v34 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v36 - 4096);
      _WriteStatusReg(TTBR1_EL1, v36);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v34);
    }
    if ( v27 )
      v21 = -14;
  }
  kfree(v24);
  result = v21;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}

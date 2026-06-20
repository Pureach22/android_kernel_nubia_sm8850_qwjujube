__int64 __fastcall lpass_cdc_proc_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v7; // x19
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x22
  int v11; // w24
  unsigned __int64 v12; // x26
  unsigned __int64 v13; // x8
  __int64 v14; // x28
  unsigned __int64 v15; // x23
  __int64 v16; // x21
  __int64 v17; // x24
  unsigned __int64 v18; // x27
  __int64 v19; // x26
  unsigned __int64 v20; // x1
  int v21; // w22
  unsigned __int64 v22; // x8
  __int64 v23; // x20
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x10
  __int64 v26; // x0
  unsigned __int64 v27; // x10
  unsigned __int64 v33; // x9
  unsigned __int64 v34; // x8
  unsigned __int64 v36; // x9
  __int64 v37; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v39; // x22
  __int64 v40; // x0
  int v43; // [xsp+1Ch] [xbp-24h]
  __int64 v44; // [xsp+20h] [xbp-20h]
  __int64 v45; // [xsp+28h] [xbp-18h]
  int v46; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v47; // [xsp+38h] [xbp-8h]

  result = -22;
  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_42;
  if ( !a1 )
    goto LABEL_42;
  if ( !a3 )
    goto LABEL_42;
  if ( !a4 )
    goto LABEL_42;
  v7 = *a4;
  if ( *a4 < 0 )
    goto LABEL_42;
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  if ( !v8 )
    goto LABEL_42;
  v9 = *(_QWORD *)(v8 + 16);
  v46 = 0;
  v45 = v9;
  v10 = _kmalloc_noprof(a3, 3520);
  if ( !v10 )
    goto LABEL_41;
LABEL_8:
  v11 = scnprintf(v10, a3, "%x", 19428);
  regcache_cache_bypass(v45, 1);
  v12 = 0;
  v44 = v10;
  if ( (unsigned int)v7 <= 0x4BE4 )
  {
    v13 = (unsigned int)(v11 + 5);
    if ( v13 < a3 )
    {
      v14 = (unsigned int)(v11 + 2);
      v15 = 0;
      v43 = v11;
      v16 = v10 + v14;
      v17 = v13 + v14 + 3;
      v18 = a3;
      while ( 1 )
      {
        scnprintf(v44 + v15, v18, "%.*x: ", v43, v7);
        v19 = v15 + v14;
        if ( (unsigned int)regmap_read(v45, (unsigned int)v7, &v46) )
        {
          if ( a3 >= v19 )
            v20 = a3 - v19;
          else
            v20 = 0;
          if ( v20 <= 1 )
            goto LABEL_40;
          if ( v19 > a3 || v18 - v14 < 2 || v19 < 0 || v18 - v14 < 2 )
          {
LABEL_39:
            __break(1u);
LABEL_40:
            _fortify_panic(15, v20);
            StatusReg = _ReadStatusReg(SP_EL0);
            v39 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
            v40 = _kmalloc_noprof(a3, 3520);
            *(_QWORD *)(StatusReg + 80) = v39;
            v10 = v40;
            if ( !v40 )
            {
LABEL_41:
              result = -12;
              goto LABEL_42;
            }
            goto LABEL_8;
          }
          *(_WORD *)(v16 + v15) = 22616;
        }
        else
        {
          scnprintf(v16 + v15, v18 - v14, "%.*x", 2, v46);
        }
        if ( v14 + v15 + 2 >= a3 || v19 < -2 )
          goto LABEL_39;
        v12 = v19 + 3;
        v21 = v7 + 4;
        *(_BYTE *)(v16 + v15 + 2) = 10;
        if ( (unsigned int)v7 <= 0x4BE0 )
        {
          v22 = v17 + v15;
          LODWORD(v7) = v7 + 4;
          v15 = v12;
          v18 += -3 - v14;
          if ( v22 < a3 )
            continue;
        }
        goto LABEL_28;
      }
    }
  }
  v21 = v7;
LABEL_28:
  regcache_cache_bypass(v45, 0);
  *a4 = v21;
  if ( v12 >> 31 )
  {
    __break(0x800u);
    v23 = v44;
    v37 = -14;
  }
  else
  {
    v23 = v44;
    _check_object_size(v44, v12, 1);
    v24 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v24 + 70) & 0x20) != 0 || (v25 = a2, (*(_QWORD *)v24 & 0x4000000) != 0) )
      v25 = a2 & ((__int64)(a2 << 8) >> 8);
    v26 = v12;
    if ( 0x8000000000LL - v12 >= v25 )
    {
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v33 = *(_QWORD *)(v24 + 8);
      _WriteStatusReg(TTBR1_EL1, v33 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v33);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
      v26 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v44, v12);
      v34 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v36 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v36 - 4096);
      _WriteStatusReg(TTBR1_EL1, v36);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v34);
    }
    if ( v26 )
      v37 = -14;
    else
      v37 = v12;
  }
  kfree(v23);
  result = v37;
LABEL_42:
  _ReadStatusReg(SP_EL0);
  return result;
}

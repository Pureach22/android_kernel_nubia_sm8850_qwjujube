__int64 __fastcall wcd939x_proc_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 result; // x0
  __int64 v8; // x19
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x0
  unsigned int v12; // w23
  int v13; // w22
  unsigned __int64 v14; // x26
  unsigned __int64 v15; // x8
  __int64 v16; // x27
  int v17; // w3
  unsigned __int64 v18; // x25
  unsigned __int64 v19; // x28
  __int64 v20; // x24
  int v21; // w22
  __int64 v22; // x26
  unsigned __int64 v23; // x1
  __int64 v24; // x8
  unsigned __int64 v25; // x8
  __int64 v26; // x20
  unsigned __int64 v27; // x9
  unsigned __int64 v28; // x10
  __int64 v29; // x0
  unsigned __int64 v30; // x10
  unsigned __int64 v36; // x9
  unsigned __int64 v37; // x8
  unsigned __int64 v39; // x9
  __int64 v40; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v42; // x23
  __int64 v44; // [xsp+10h] [xbp-30h]
  __int64 v45; // [xsp+20h] [xbp-20h]
  __int64 v46; // [xsp+28h] [xbp-18h]
  int v47; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+38h] [xbp-8h]

  result = -22;
  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
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
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 696LL);
  if ( !v9 )
    goto LABEL_40;
  v10 = *(_QWORD *)(v9 + 32);
  v47 = 0;
  v46 = v10;
  v11 = _kmalloc_noprof(a3, 3520);
  if ( !v11 )
    goto LABEL_39;
LABEL_8:
  v12 = v8 + 12287;
  v45 = v11;
  v13 = scnprintf(v11, a3, "%x", 13734);
  regcache_cache_bypass(v46, 1);
  v14 = 0;
  if ( (unsigned int)(v8 + 12287) <= 0x35A6 )
  {
    v15 = (unsigned int)(v13 + 5);
    if ( v15 < a3 )
    {
      v16 = (unsigned int)(v13 + 2);
      v17 = v13;
      v18 = 0;
      v8 = -v16;
      v19 = a3;
      v20 = v45 + v16;
      v44 = v15 + v16 + 3;
      while ( 1 )
      {
        v21 = v17;
        scnprintf(v45 + v18, v19, "%.*x: ", v17, v12);
        v22 = v18 + v16;
        if ( (unsigned int)regmap_read(v46, v12, &v47) )
        {
          if ( a3 >= v22 )
            v23 = a3 - v22;
          else
            v23 = 0;
          if ( v23 <= 1 )
            goto LABEL_38;
          if ( v22 > a3 || v19 - v16 < 2 || v22 < 0 || v19 - v16 < 2 )
          {
LABEL_37:
            __break(1u);
LABEL_38:
            _fortify_panic(15);
            StatusReg = _ReadStatusReg(SP_EL0);
            v42 = *(_QWORD *)(StatusReg + 80);
            *(_QWORD *)(StatusReg + 80) = &regdump_read__alloc_tag;
            v11 = _kmalloc_noprof(a3, 3520);
            *(_QWORD *)(StatusReg + 80) = v42;
            if ( !v11 )
            {
LABEL_39:
              result = -12;
              goto LABEL_40;
            }
            goto LABEL_8;
          }
          v17 = v21;
          *(_WORD *)(v20 + v18) = 22616;
        }
        else
        {
          scnprintf(v20 + v18, v19 - v16, "%.*x", 2, v47);
          v17 = v21;
        }
        if ( v16 + v18 + 2 >= a3 || v22 < -2 )
          goto LABEL_37;
        v24 = *a4;
        *(_BYTE *)(v20 + v18 + 2) = 10;
        v14 = v22 + 3;
        *a4 = v24 + 1;
        if ( v12 <= 0x35A5 )
        {
          ++v12;
          v25 = v44 + v18;
          v18 = v14;
          v19 += -3 - v16;
          if ( v25 < a3 )
            continue;
        }
        break;
      }
    }
  }
  regcache_cache_bypass(v46, 0);
  if ( v14 >> 31 )
  {
    __break(0x800u);
    v26 = v45;
    v40 = -14;
  }
  else
  {
    v26 = v45;
    _check_object_size(v45, v14, 1);
    v27 = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(v27 + 70) & 0x20) != 0 || (v28 = a2, (*(_QWORD *)v27 & 0x4000000) != 0) )
      v28 = a2 & ((__int64)(a2 << 8) >> 8);
    v29 = v14;
    if ( 0x8000000000LL - v14 >= v28 )
    {
      v30 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v36 = *(_QWORD *)(v27 + 8);
      _WriteStatusReg(TTBR1_EL1, v36 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v36);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v30);
      v29 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v45, v14);
      v37 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v39 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v39 - 4096);
      _WriteStatusReg(TTBR1_EL1, v39);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v37);
    }
    if ( v29 )
      v40 = -14;
    else
      v40 = v14;
  }
  kfree(v26);
  result = v40;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}

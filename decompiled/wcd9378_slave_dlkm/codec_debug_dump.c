unsigned __int64 __fastcall codec_debug_dump(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  unsigned __int64 v4; // x28
  __int64 v6; // x21
  __int64 v7; // x8
  unsigned __int64 v9; // x24
  unsigned __int64 v10; // x26
  unsigned __int64 StatusReg; // x22
  int v12; // w23
  bool v13; // cc
  signed int v14; // w0
  __int64 v15; // x27
  __int64 v16; // x25
  unsigned __int64 v17; // x24
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v25; // x9
  unsigned __int64 v26; // x8
  unsigned __int64 v28; // x9
  _QWORD v30[2]; // [xsp+10h] [xbp-20h] BYREF
  int v31; // [xsp+20h] [xbp-10h]
  __int64 v32; // [xsp+28h] [xbp-8h]

  v4 = -22;
  v32 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_40;
  if ( !a1 )
    goto LABEL_40;
  if ( !a3 )
    goto LABEL_40;
  if ( !a4 )
    goto LABEL_40;
  v6 = *(_QWORD *)(a1 + 32);
  if ( !v6 )
    goto LABEL_40;
  v7 = *a4;
  if ( *a4 < 0 )
    goto LABEL_40;
  if ( (int)v7 > 97655 )
  {
    v4 = 0;
    goto LABEL_39;
  }
  v9 = 0;
  v10 = a3 - 1;
  StatusReg = _ReadStatusReg(SP_EL0);
  v30[0] = 0;
  v30[1] = 0;
  v31 = 0;
  v12 = (int)v7 / 12 + 64;
  while ( 1 )
  {
    if ( (unsigned int)(v12 - 1081) < 0x1BC7
      || (unsigned int)(v12 - 825) < 0xCC
      || (unsigned int)(v12 - 569) < 0xCC
      || (unsigned int)(v12 - 313) < 0xCC
      || (unsigned int)(v12 - 1065) < 7
      || (v12 & 0xFFFFFEFF) - 553 < 7
      || (unsigned int)(v12 - 297) < 7
      || (unsigned int)(v12 - 1030) < 0x1A
      || (v12 & 0xFFFFFEFE) - 518 < 0x1A
      || (unsigned int)(v12 - 262) < 0x1A
      || (v12 & 0xFFFFFFEF) - 225 < 0xF
      || (unsigned int)(v12 - 209) < 0xF
      || (unsigned int)(v12 - 86) < 0x7A
      || (unsigned int)(v12 - 71) < 3
      || (unsigned int)(v12 - 75) < 5 )
    {
      v4 = v9;
      goto LABEL_10;
    }
    swr_read(v6, *(unsigned __int8 *)(v6 + 64));
    v14 = scnprintf(v30, 20, "0x%.3x: 0x%.2x\n", v12, 0);
    if ( v14 < 0 || (v15 = v14, v4 = v9 + v14, v4 >= v10) )
    {
      v4 = v9;
      goto LABEL_39;
    }
    v16 = v14;
    if ( (unsigned int)v14 >= 0x15 )
      break;
    v17 = a2 + v9;
    _check_object_size(v30, v14, 1);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = v17, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v18 = v17 & ((__int64)(v17 << 8) >> 8);
    if ( 0x8000000000LL - v15 >= v18 )
    {
      v19 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v25 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v25 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v25);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v19);
      v16 = _arch_copy_to_user(v17 & 0xFF7FFFFFFFFFFFFFLL, v30, v15);
      v26 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v28 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v28 - 4096);
      _WriteStatusReg(TTBR1_EL1, v28);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v26);
    }
    if ( v16 )
      goto LABEL_42;
    *a4 += v15;
LABEL_10:
    v13 = v12++ < 8201;
    v9 = v4;
    if ( !v13 )
      goto LABEL_39;
  }
  _copy_overflow(20, v14);
LABEL_42:
  printk(&unk_6CE7, "wcd9378_swrslave_reg_show");
  v4 = -14;
LABEL_39:
  *a4 = 98412;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return v4;
}

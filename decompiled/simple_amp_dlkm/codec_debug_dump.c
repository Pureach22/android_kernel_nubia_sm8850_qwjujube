unsigned __int64 __fastcall codec_debug_dump(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  unsigned __int64 v4; // x24
  __int64 v6; // x21
  __int64 v7; // x8
  unsigned __int64 v9; // x28
  unsigned __int64 v10; // x26
  unsigned __int64 StatusReg; // x22
  int v12; // w23
  bool v13; // cc
  unsigned int v14; // w8
  unsigned int v15; // w0
  __int64 v16; // x25
  unsigned __int64 v17; // x28
  unsigned __int64 v18; // x8
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x8
  unsigned __int64 v29; // x9
  __int64 v30; // x2
  __int64 v31; // x3
  void *v32; // x0
  int v34; // [xsp+Ch] [xbp-24h] BYREF
  char s[8]; // [xsp+10h] [xbp-20h] BYREF
  __int64 v36; // [xsp+18h] [xbp-18h]
  int v37; // [xsp+20h] [xbp-10h]
  __int64 v38; // [xsp+28h] [xbp-8h]

  v4 = -22;
  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_53;
  if ( !a1 )
    goto LABEL_53;
  if ( !a3 )
    goto LABEL_53;
  if ( !a4 )
    goto LABEL_53;
  v6 = *(_QWORD *)(a1 + 32);
  if ( !v6 )
    goto LABEL_53;
  v7 = *a4;
  if ( *a4 < 0 )
    goto LABEL_53;
  if ( (int)v7 > 97655 )
  {
    v4 = 0;
    goto LABEL_52;
  }
  v9 = 0;
  v10 = a3 - 1;
  v34 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_QWORD *)s = 0;
  v36 = 0;
  v37 = 0;
  v12 = (int)v7 / 12 + 64;
  while ( 1 )
  {
    if ( (unsigned int)(v12 - 3894) >> 1 < 0x865
      || (unsigned int)(v12 - 3878) < 0xA
      || (unsigned int)(v12 - 3846) < 0x1A
      || (unsigned int)(v12 - 1592) < 0x8C8
      || (v14 = v12 & 0xFFFFFEF8, (v12 & 0xFFFFFEF8) - 1080 < 0xC8)
      || v14 - 568 < 0xC8
      || (unsigned int)(v12 - 312) < 0xC8
      || (v12 & 0xFFFFFFF8) == 0x628
      || v14 == 1064
      || v14 == 552
      || (v12 & 0xFFFFFFF8) == 0x128
      || (unsigned int)(v12 - 1542) < 0x1A
      || (v12 & 0xFFFFFEFE) - 1030 < 0x1A
      || (v12 & 0xFFFFFEFE) - 518 < 0x1A
      || (unsigned int)(v12 - 262) < 0x1A
      || (v12 & 0xFFFFFFEF) - 225 < 0xF
      || (unsigned int)(v12 - 209) < 0xF
      || (unsigned int)(v12 - 201) < 7
      || (unsigned int)(v12 - 194) < 6
      || (unsigned int)(v12 - 113) < 0x4F
      || (unsigned int)(v12 - 97) < 0xF
      || (unsigned int)(v12 - 71) < 3
      || (unsigned int)(v12 - 86) < 0xA )
    {
      v4 = v9;
      goto LABEL_10;
    }
    swr_read(v6, *(unsigned __int8 *)(v6 + 64), (unsigned int)v12, &v34, 1);
    v15 = snprintf(s, 0x14u, "0x%.3x: 0x%.2x\n", v12, (unsigned __int8)v34);
    if ( (v15 & 0x80000000) != 0 )
    {
      if ( !(unsigned int)__ratelimit(&swr_slave_reg_show__rs, "swr_slave_reg_show") )
        goto LABEL_51;
      v32 = &unk_C6CE;
      goto LABEL_55;
    }
    v16 = v15;
    v4 = v9 + v15;
    if ( v4 >= v10 )
    {
      v4 = v9;
      goto LABEL_52;
    }
    if ( v15 >= 0x15 )
      break;
    v17 = a2 + v9;
    _check_object_size(s, v15, 1);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v18 = v17, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v18 = v17 & ((__int64)(v17 << 8) >> 8);
    v19 = v16;
    if ( 0x8000000000LL - v16 >= v18 )
    {
      v20 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v26 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v26 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v26);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v20);
      v19 = _arch_copy_to_user(v17 & 0xFF7FFFFFFFFFFFFFLL, s, v16);
      v27 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v29 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v29 - 4096);
      _WriteStatusReg(TTBR1_EL1, v29);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v27);
    }
    if ( v19 )
      goto LABEL_50;
    *a4 += v16;
LABEL_10:
    v13 = v12++ < 8201;
    v9 = v4;
    if ( !v13 )
      goto LABEL_52;
  }
  _copy_overflow(20, v15);
LABEL_50:
  if ( !(unsigned int)__ratelimit(&swr_slave_reg_show__rs_11, "swr_slave_reg_show") )
    goto LABEL_51;
  v32 = &unk_D071;
LABEL_55:
  printk(v32, "swr_slave_reg_show", v30, v31);
LABEL_51:
  v4 = -14;
LABEL_52:
  *a4 = 98412;
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return v4;
}

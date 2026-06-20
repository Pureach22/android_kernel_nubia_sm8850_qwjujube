unsigned __int64 __fastcall swrm_debug_reg_dump(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  unsigned __int64 v4; // x23
  __int64 v6; // x21
  __int64 v7; // x22
  unsigned __int64 v9; // x27
  unsigned __int64 v10; // x26
  unsigned __int64 StatusReg; // x24
  bool v12; // cc
  int v13; // w0
  unsigned int v14; // w0
  __int64 v15; // x25
  unsigned __int64 v16; // x27
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v24; // x9
  unsigned __int64 v25; // x8
  unsigned __int64 v27; // x9
  void *v28; // x0
  char s[8]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v31; // [xsp+10h] [xbp-20h]
  __int64 v32; // [xsp+18h] [xbp-18h]
  __int64 v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v4 = -22;
  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
    goto LABEL_30;
  if ( !a1 )
    goto LABEL_30;
  if ( !a3 )
    goto LABEL_30;
  if ( !a4 )
    goto LABEL_30;
  v6 = *(_QWORD *)(a1 + 32);
  if ( !v6 )
    goto LABEL_30;
  v7 = *a4;
  if ( *a4 < 0 )
    goto LABEL_30;
  if ( (int)v7 > 24744 )
  {
    v4 = 0;
    goto LABEL_30;
  }
  v9 = 0;
  v10 = a3 - 1;
  v32 = 0;
  v33 = 0;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_QWORD *)s = 0;
  v31 = 0;
  while ( 1 )
  {
    if ( (unsigned int)(v7 - 11349) < 0x13AB )
    {
      v4 = v9;
      goto LABEL_10;
    }
    usleep_range_state(100, 150, 2);
    v13 = swr_master_read(v6, v7);
    v14 = snprintf(s, 0x19u, "0x%.3x: 0x%.2x\n", v7, v13);
    if ( (v14 & 0x80000000) != 0 )
    {
      if ( !(unsigned int)__ratelimit(&swrm_reg_show__rs, "swrm_reg_show") )
        goto LABEL_29;
      v28 = &unk_10B2F;
      goto LABEL_32;
    }
    v15 = v14;
    v4 = v9 + v14;
    if ( v4 >= v10 )
    {
      v4 = v9;
      goto LABEL_30;
    }
    if ( v14 >= 0x21 )
      break;
    v16 = a2 + v9;
    _check_object_size(s, v14, 1);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v17 = v16, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v17 = v16 & ((__int64)(v16 << 8) >> 8);
    if ( 0x8000000000LL - v15 >= v17 )
    {
      v18 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v24 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v24 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v24);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v18);
      v15 = _arch_copy_to_user(v16 & 0xFF7FFFFFFFFFFFFFLL, s, v15);
      v25 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v27 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v27 - 4096);
      _WriteStatusReg(TTBR1_EL1, v27);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v25);
    }
    if ( v15 )
      goto LABEL_28;
    v9 = v4;
    *a4 += 4;
LABEL_10:
    v12 = (int)v7 < 24741;
    LODWORD(v7) = v7 + 4;
    if ( !v12 )
      goto LABEL_30;
  }
  _copy_overflow(32, v14);
LABEL_28:
  if ( !(unsigned int)__ratelimit(&swrm_reg_show__rs_202, "swrm_reg_show") )
    goto LABEL_29;
  v28 = &unk_115DA;
LABEL_32:
  printk(v28, "swrm_reg_show");
LABEL_29:
  v4 = -14;
LABEL_30:
  _ReadStatusReg(SP_EL0);
  return v4;
}

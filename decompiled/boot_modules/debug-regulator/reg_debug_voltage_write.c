__int64 __fastcall reg_debug_voltage_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x23
  unsigned __int64 v6; // x20
  unsigned __int64 v7; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  size_t v10; // x22
  unsigned __int64 v11; // x1
  unsigned __int64 v12; // x9
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9
  int v22; // w0
  int v24; // w20
  __int64 v25; // x0
  int v26; // [xsp+8h] [xbp-48h] BYREF
  int v27; // [xsp+Ch] [xbp-44h] BYREF
  char s[8]; // [xsp+10h] [xbp-40h] BYREF
  __int64 v29; // [xsp+18h] [xbp-38h]
  __int64 v30; // [xsp+20h] [xbp-30h]
  __int64 v31; // [xsp+28h] [xbp-28h]
  __int64 v32; // [xsp+30h] [xbp-20h]
  __int64 v33; // [xsp+38h] [xbp-18h]
  __int16 v34; // [xsp+40h] [xbp-10h]
  __int64 v35; // [xsp+48h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_QWORD *)(a1 + 32);
  v6 = *(_QWORD *)(v5 + 16);
  if ( v6 )
  {
    v34 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    *(_QWORD *)s = 0;
    v29 = 0;
    v26 = -1;
    v27 = 0;
    goto LABEL_5;
  }
  v7 = regulator_get(0);
  if ( v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v34 = 0;
    v32 = 0;
    v33 = 0;
    v30 = 0;
    v31 = 0;
    *(_QWORD *)s = 0;
    v29 = 0;
    goto LABEL_27;
  }
  v6 = v7;
  *(_QWORD *)(v5 + 16) = v7;
  v34 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  *(_QWORD *)s = 0;
  v29 = 0;
  v26 = -1;
  v27 = 0;
  if ( !v7 )
  {
LABEL_27:
    printk(&unk_818A, "reg_debug_voltage_write");
    a3 = -19;
    goto LABEL_22;
  }
LABEL_5:
  if ( a3 > 0x31 )
  {
    printk(&unk_7F93, "reg_debug_voltage_write");
LABEL_25:
    a3 = -22;
    goto LABEL_22;
  }
  _check_object_size(s, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v9 = a2 & ((__int64)(a2 << 8) >> 8);
  v10 = a3;
  if ( 0x8000000000LL - a3 >= v9 )
  {
    v12 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v12);
    v10 = _arch_copy_from_user(s, a2 & 0xFF7FFFFFFFFFFFFFLL, a3);
    v19 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v21 - 4096);
    _WriteStatusReg(TTBR1_EL1, v21);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v19);
    if ( !v10 )
    {
LABEL_17:
      s[a3] = 0;
      if ( sscanf(s, "%d %d", &v27, &v26) >= 2 && (v27 & 0x80000000) == 0 && v26 >= v27 )
      {
        v22 = regulator_set_voltage(v6);
        if ( v22 )
        {
          v24 = v22;
          printk(&unk_7DAA, "reg_debug_voltage_write");
          a3 = v24;
        }
        goto LABEL_22;
      }
      printk(&unk_7C3B, "reg_debug_voltage_write");
      goto LABEL_25;
    }
  }
  if ( a3 - v10 <= 0x32 )
    v11 = 50 - (a3 - v10);
  else
    v11 = 0;
  if ( v11 >= v10 )
  {
    memset(&s[a3 - v10], 0, v10);
    if ( v10 )
    {
      a3 = -14;
LABEL_22:
      _ReadStatusReg(SP_EL0);
      return a3;
    }
    goto LABEL_17;
  }
  v25 = _fortify_panic(15);
  return reg_mode_fops_open(v25);
}

__int64 __fastcall f_cdev_ioctl(__int64 a1, unsigned int a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v4; // x19
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x9
  unsigned __int64 v8; // x10
  unsigned __int64 v14; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  __int64 (__fastcall *v19)(__int64, __int64); // x8
  __int64 v20; // x1
  __int16 v21; // w9
  __int64 result; // x0
  __int64 (__fastcall *v23)(__int64, __int64); // x8
  __int64 v24; // x1
  __int16 v25; // w9
  unsigned int (__fastcall *v26)(_QWORD); // x8
  int v28; // w20
  unsigned int (__fastcall *v29)(_QWORD); // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v31; // x11
  unsigned __int64 v33; // x11
  unsigned __int64 v35; // x8
  unsigned __int64 v36; // x8
  unsigned __int64 v38; // x9

  v4 = *(_QWORD *)(a1 + 32);
  if ( !v4 )
  {
    printk(&unk_8C38, "f_cdev_ioctl", a3, a4);
    return 8;
  }
  if ( a2 - 21526 >= 3 )
  {
    if ( a2 != 21525 )
    {
      printk(&unk_8CE7, "f_cdev_ioctl", a2, a4);
      return -515;
    }
    v26 = *(unsigned int (__fastcall **)(_QWORD))(v4 + 1472);
    if ( v26 )
    {
      if ( *((_DWORD *)v26 - 1) != 1321552129 )
        __break(0x8228u);
      v28 = 2 * (v26(v4 + 1200) != 0);
      v29 = *(unsigned int (__fastcall **)(_QWORD))(v4 + 1480);
      if ( !v29 )
        goto LABEL_25;
    }
    else
    {
      v28 = 0;
      v29 = *(unsigned int (__fastcall **)(_QWORD))(v4 + 1480);
      if ( !v29 )
      {
LABEL_25:
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v31 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v31 = a3 & ((__int64)(a3 << 8) >> 8);
        result = -14;
        if ( v31 <= 0x7FFFFFFFFCLL )
        {
          _W10 = v28 | *(_WORD *)(v4 + 1466) & 0x40 | *(_WORD *)(v4 + 1466) & 0x80;
          v33 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v35 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v35 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v35);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v33);
          __asm { STTR            W10, [X9] }
          v36 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          result = 0;
          v38 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v38 - 4096);
          _WriteStatusReg(TTBR1_EL1, v38);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v36);
        }
        *(_BYTE *)(v4 + 1548) = 0;
        return result;
      }
    }
    if ( *((_DWORD *)v29 - 1) != 1321552129 )
      __break(0x8228u);
    v28 |= 4 * (v29(v4 + 1200) != 0);
    goto LABEL_25;
  }
  v5 = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(v5 + 70) & 0x20) != 0 || (v6 = a3, (*(_QWORD *)v5 & 0x4000000) != 0) )
    v6 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v6 <= 0x7FFFFFFFFCLL )
  {
    _X9 = a3 & 0xFF7FFFFFFFFFFFFFLL;
    v8 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v14 = *(_QWORD *)(v5 + 8);
    _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v14);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v8);
    __asm { LDTR            W20, [X9] }
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
    v19 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 1520);
    if ( (_X20 & 0x80) != 0 )
    {
      if ( v19 )
      {
        v20 = 1;
        v21 = *(_WORD *)(v4 + 1466) | 0x80;
LABEL_12:
        *(_WORD *)(v4 + 1466) = v21;
        if ( *((_DWORD *)v19 - 1) != 333177109 )
          __break(0x8228u);
        LODWORD(result) = v19(v4 + 1200, v20);
        v23 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 1512);
        if ( (_X20 & 0x40) == 0 )
        {
LABEL_15:
          if ( v23 )
          {
            v24 = 0;
            v25 = *(_WORD *)(v4 + 1466) & 0xFFBF;
LABEL_34:
            *(_WORD *)(v4 + 1466) = v25;
            if ( *((_DWORD *)v23 - 1) != 333177109 )
              __break(0x8228u);
            LODWORD(result) = v23(v4 + 1200, v24);
            return (int)result;
          }
          return (int)result;
        }
LABEL_32:
        if ( v23 )
        {
          v24 = 1;
          v25 = *(_WORD *)(v4 + 1466) | 0x40;
          goto LABEL_34;
        }
        return (int)result;
      }
    }
    else if ( v19 )
    {
      v20 = 0;
      v21 = *(_WORD *)(v4 + 1466) & 0xFF7F;
      goto LABEL_12;
    }
    LODWORD(result) = 0;
    v23 = *(__int64 (__fastcall **)(__int64, __int64))(v4 + 1512);
    if ( (_X20 & 0x40) == 0 )
      goto LABEL_15;
    goto LABEL_32;
  }
  printk(&unk_8DEA, "f_cdev_ioctl", a3, a4);
  return -14;
}

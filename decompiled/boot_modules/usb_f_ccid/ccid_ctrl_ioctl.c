__int64 __fastcall ccid_ctrl_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  __int64 *v4; // x20
  __int64 v5; // x0
  int v6; // w21
  unsigned int v7; // w0
  __int64 v8; // x2
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v11; // x9
  unsigned __int64 v12; // x9
  unsigned __int64 v18; // x8
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  unsigned int v23; // w19

  v3 = *(_QWORD *)(a1 + 32);
  if ( a2 != -2147204349 )
  {
    v4 = *(__int64 **)(v3 + 264);
    v5 = *v4;
    if ( a2 == 1074021122 )
    {
      v6 = 4;
      if ( !inline_copy_from_user(v5, a3, 4u) )
        goto LABEL_7;
    }
    else
    {
      if ( a2 != 1074021121 )
        goto LABEL_8;
      if ( !inline_copy_from_user(v5, a3, 4u) )
      {
        v6 = 2;
LABEL_7:
        *((_DWORD *)v4 + 2) = v6;
LABEL_8:
        v7 = usb_ep_queue(*(_QWORD *)(v3 + 240), *(_QWORD *)(v3 + 264), 3264);
        if ( (v7 & 0x80000000) == 0 )
          return 0;
        v23 = v7;
        printk(&unk_8335, v7, v8);
        return (int)v23;
      }
    }
    return -14;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v11 = a3 & ((__int64)(a3 << 8) >> 8);
  if ( v11 > 0x7FFFFFFFFCLL )
    return -14;
  v12 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v18 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v18);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v12);
  v19 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, v3 + 696, 4);
  v20 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
  _WriteStatusReg(TTBR0_EL1, v22 - 4096);
  _WriteStatusReg(TTBR1_EL1, v22);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v20);
  if ( v19 )
    return -14;
  else
    return 0;
}

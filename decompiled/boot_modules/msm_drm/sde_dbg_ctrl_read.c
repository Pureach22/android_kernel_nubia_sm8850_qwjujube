__int64 __fastcall sde_dbg_ctrl_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  int v8; // w0
  __int64 v9; // x19
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v11; // x8
  __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x9
  unsigned __int64 v22; // x10
  _QWORD v23[4]; // [xsp+0h] [xbp-20h] BYREF

  result = -22;
  v23[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v23, 0, 24);
  if ( a2 && a4 )
  {
    if ( *a4 || (v8 = snprintf((char *)v23, 0x18u, "0x%x\n", dword_2945A4), (unsigned int)v8 > 0x17) )
    {
      result = 0;
    }
    else
    {
      if ( a3 < 0x18 )
        goto LABEL_16;
      v9 = v8;
      _check_object_size(v23, v8, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v11 = a2 & ((__int64)(a2 << 8) >> 8);
      result = v9;
      _CF = 0x8000000000LL - v9 >= v11;
      v13 = v9;
      if ( _CF )
      {
        v14 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v19 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v19);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v14);
        v13 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        result = v9;
        v20 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v22 - 4096);
        _WriteStatusReg(TTBR1_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v20);
      }
      if ( v13 )
      {
LABEL_16:
        printk(&unk_224C07, "sde_dbg_ctrl_read");
        result = -14;
      }
      else
      {
        *a4 += result;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

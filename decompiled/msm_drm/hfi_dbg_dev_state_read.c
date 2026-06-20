__int64 __fastcall hfi_dbg_dev_state_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v5; // x23
  unsigned __int64 v6; // x9
  unsigned __int64 v9; // x22
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v12; // x10
  unsigned __int64 v13; // x10
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  __int64 v23; // x19

  result = 0;
  if ( a2 && a4 )
  {
    v5 = *(_QWORD *)(hfi_dbg + 216);
    if ( v5 && (v6 = *(unsigned int *)(hfi_dbg + 224) - *a4) != 0 )
    {
      if ( v6 >= a3 )
        v9 = a3;
      else
        v9 = *(unsigned int *)(hfi_dbg + 224) - *a4;
      mutex_lock(hfi_dbg + 272);
      if ( v9 >> 31 )
      {
        __break(0x800u);
        v23 = -14;
      }
      else
      {
        v10 = v9;
        _check_object_size(v5 + *a4, v9, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v12 = a2 & ((__int64)(a2 << 8) >> 8);
        if ( 0x8000000000LL - v9 >= v12 )
        {
          v13 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v19 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v19);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v13);
          v10 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
          v20 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v22 - 4096);
          _WriteStatusReg(TTBR1_EL1, v22);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v20);
        }
        if ( v10 )
          v23 = -14;
        else
          v23 = v9;
      }
      mutex_unlock(hfi_dbg + 272);
      result = v23;
      *a4 += v23;
    }
    else
    {
      return 0;
    }
  }
  return result;
}

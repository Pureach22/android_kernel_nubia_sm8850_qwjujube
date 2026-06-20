unsigned __int64 __fastcall hfi_dbg_dump_info_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  unsigned __int64 v4; // x19
  __int64 v5; // x23
  unsigned __int64 v6; // x9
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v11; // x10
  __int64 v12; // x0
  unsigned __int64 v13; // x10
  unsigned __int64 v19; // x9
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x23

  v4 = -22;
  if ( a2 )
  {
    if ( a4 )
    {
      v5 = *(_QWORD *)(hfi_dbg + 104);
      if ( v5 )
      {
        v6 = *(unsigned int *)(hfi_dbg + 112) - *a4;
        if ( v6 )
        {
          if ( v6 >= a3 )
            v4 = a3;
          else
            v4 = *(unsigned int *)(hfi_dbg + 112) - *a4;
          mutex_lock(hfi_dbg + 272);
          if ( v4 >> 31 )
          {
            __break(0x800u);
            v23 = -14;
          }
          else
          {
            _check_object_size(v5 + *a4, v4, 1);
            StatusReg = _ReadStatusReg(SP_EL0);
            if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
              v11 = a2 & ((__int64)(a2 << 8) >> 8);
            v12 = v4;
            if ( 0x8000000000LL - v4 >= v11 )
            {
              v13 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v19 = *(_QWORD *)(StatusReg + 8);
              _WriteStatusReg(TTBR1_EL1, v19 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
              _WriteStatusReg(TTBR0_EL1, v19);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v13);
              v12 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
              v20 = _ReadStatusReg(DAIF);
              __asm { MSR             DAIFSet, #3 }
              v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
              _WriteStatusReg(TTBR0_EL1, v22 - 4096);
              _WriteStatusReg(TTBR1_EL1, v22);
              __isb(0xFu);
              _WriteStatusReg(DAIF, v20);
            }
            if ( v12 )
              v23 = -14;
            else
              v23 = v4;
          }
          mutex_unlock(hfi_dbg + 272);
          if ( (v23 & 0x8000000000000000LL) != 0 || v23 > a3 )
          {
            printk(&unk_242788, "hfi_dbg_dump_info_read");
            return 0;
          }
          else
          {
            *a4 += v23;
          }
        }
        else
        {
          return 0;
        }
      }
    }
  }
  return v4;
}

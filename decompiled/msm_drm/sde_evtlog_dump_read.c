unsigned __int64 __fastcall sde_evtlog_dump_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  unsigned __int64 v4; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  __int64 v10; // x0
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  _BYTE s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v23; // [xsp+208h] [xbp-8h]

  v4 = -22;
  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 && a4 )
  {
    memset(s, 0, sizeof(s));
    mutex_lock(&unk_2942D0);
    v4 = sde_evtlog_dump_to_buffer(sde_dbg_base, s, 512, dword_2945D0 == 0, 1);
    ++dword_2945D0;
    mutex_unlock(&unk_2942D0);
    if ( (v4 & 0x8000000000000000LL) != 0 || v4 > a3 )
    {
      printk(&unk_232224, "sde_evtlog_dump_read");
      v4 = 0;
    }
    else if ( v4 >= 0x201 )
    {
      _copy_overflow(512, v4);
      v4 = -14;
    }
    else
    {
      _check_object_size(s, v4, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v9 = a2 & ((__int64)(a2 << 8) >> 8);
      v10 = v4;
      if ( 0x8000000000LL - v4 >= v9 )
      {
        v11 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v17 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v17);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v11);
        v10 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        v18 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v20 - 4096);
        _WriteStatusReg(TTBR1_EL1, v20);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v18);
      }
      if ( v10 )
        v4 = -14;
      else
        *a4 += v4;
    }
  }
  _ReadStatusReg(SP_EL0);
  return v4;
}

__int64 __fastcall sde_dbg_power_wakelock_rd(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v9; // x8
  __int64 v10; // x9
  signed int v11; // w0
  __int64 v12; // x21
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v14; // x8
  __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v22; // x9
  unsigned __int64 v23; // x9
  unsigned __int64 v25; // x10
  _BYTE s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v27; // [xsp+108h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( *a4 )
    goto LABEL_2;
  if ( !a1 || (v9 = *(_QWORD *)(a1 + 32)) == 0 )
  {
    result = -22;
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(v9 + 96);
  if ( v10 )
    v11 = (*(_WORD *)(v10 + 268) & 1) != 0 && *(_QWORD *)(v10 + 328)
        ? scnprintf(s, 256, "%d\n", *(_DWORD *)(v9 + 464))
        : scnprintf(s, 256, "device cannot wakeup\n");
  else
    v11 = scnprintf(s, 256, "device not initialized\n");
  if ( v11 >= a3 )
  {
LABEL_2:
    result = 0;
  }
  else
  {
    v12 = v11;
    if ( (unsigned int)v11 >= 0x102 )
    {
      _copy_overflow(257, v11);
      result = -14;
    }
    else
    {
      _check_object_size(s, v11, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v14 = a2 & ((__int64)(a2 << 8) >> 8);
      result = v12;
      _CF = 0x8000000000LL - v12 >= v14;
      v16 = v12;
      if ( _CF )
      {
        v17 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v17);
        v16 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        result = v12;
        v23 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v25 - 4096);
        _WriteStatusReg(TTBR1_EL1, v25);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v23);
      }
      if ( v16 )
        result = -14;
      else
        *a4 += result;
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}

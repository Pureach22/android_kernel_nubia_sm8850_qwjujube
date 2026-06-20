unsigned __int64 __fastcall dp_debug_tpg_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  unsigned __int64 v5; // x19
  int v7; // w3
  unsigned int v9; // w0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v11; // x10
  __int64 v12; // x0
  _QWORD *v14; // x10
  unsigned __int64 v15; // x10
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x8
  unsigned __int64 v23; // x9
  _QWORD v25[2]; // [xsp+0h] [xbp-10h] BYREF

  v25[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
  {
    if ( *a4 )
    {
      v5 = 0;
    }
    else
    {
      v7 = *(_DWORD *)(v4 + 164);
      v5 = a3;
      v25[0] = 0;
      v9 = scnprintf(v25, 8, "%d\n", v7);
      if ( v9 < v5 )
        v5 = v9;
      if ( v5 >= 9 )
      {
        _copy_overflow(8, v5);
        v5 = -14;
      }
      else
      {
        _check_object_size(v25, v5, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v11 = a2 & ((__int64)(a2 << 8) >> 8);
        v12 = v5;
        _CF = 0x8000000000LL - v5 >= v11;
        v14 = a4;
        if ( _CF )
        {
          v15 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v20 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v20 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v20);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v15);
          v12 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
          v14 = a4;
          v21 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v23 - 4096);
          _WriteStatusReg(TTBR1_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v21);
        }
        if ( v12 )
          v5 = -14;
        else
          *v14 += v5;
      }
    }
  }
  else
  {
    v5 = -19;
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}

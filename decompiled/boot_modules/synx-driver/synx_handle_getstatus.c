__int64 __fastcall synx_handle_getstatus(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 result; // x0
  int status; // w0
  __int64 v7; // x19
  unsigned __int64 v8; // x20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  _QWORD v21[3]; // [xsp+8h] [xbp-18h] BYREF

  v21[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) == 16 )
  {
    v3 = *(_QWORD *)(a1 + 16);
    v21[0] = 0;
    v21[1] = 0;
    if ( inline_copy_from_user((int)v21, v3, 0x10u) )
    {
      result = 4294967282LL;
    }
    else
    {
      status = synx_get_status(a2, LODWORD(v21[0]));
      v7 = *(unsigned int *)(a1 + 4);
      HIDWORD(v21[0]) = status;
      if ( (unsigned int)v7 >= 0x11 )
      {
        _copy_overflow(16, v7);
        result = 4294967282LL;
      }
      else
      {
        v8 = *(_QWORD *)(a1 + 16);
        _check_object_size(v21, v7, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = v8, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v10 = v8 & ((__int64)(v8 << 8) >> 8);
        if ( 0x8000000000LL - v7 >= v10 )
        {
          v11 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v17 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v17);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v11);
          v7 = _arch_copy_to_user(v8 & 0xFF7FFFFFFFFFFFFFLL, v21, v7);
          v18 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v20 - 4096);
          _WriteStatusReg(TTBR1_EL1, v20);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v18);
        }
        if ( v7 )
          result = 4294967282LL;
        else
          result = 0;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

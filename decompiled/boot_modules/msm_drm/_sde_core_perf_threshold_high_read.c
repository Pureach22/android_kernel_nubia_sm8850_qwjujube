__int64 __fastcall sde_core_perf_threshold_high_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  int v8; // w0
  __int64 result; // x0
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v12; // x8
  __int64 v14; // x8
  _QWORD *v15; // x11
  unsigned __int64 v16; // x8
  unsigned __int64 v21; // x10
  unsigned __int64 v22; // x9
  unsigned __int64 v24; // x10
  _QWORD v25[2]; // [xsp+0h] [xbp-20h] BYREF
  int v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v26 = 0;
  v25[0] = 0;
  v25[1] = 0;
  if ( v4 )
  {
    if ( *a4
      || (v8 = snprintf((char *)v25, 0x14u, "%d\n", *(_DWORD *)(*(_QWORD *)(v4 + 16) + 21708LL)), (unsigned int)v8 > 0x13) )
    {
      result = 0;
    }
    else
    {
      if ( a3 < 0x14 )
        goto LABEL_14;
      v10 = v8;
      _check_object_size(v25, v8, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v12 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v12 = a2 & ((__int64)(a2 << 8) >> 8);
      result = v10;
      _CF = 0x8000000000LL - v10 >= v12;
      v14 = v10;
      v15 = a4;
      if ( _CF )
      {
        v16 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v21 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v21 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v21);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v16);
        v14 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        result = v10;
        v15 = a4;
        v22 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v24 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v24 - 4096);
        _WriteStatusReg(TTBR1_EL1, v24);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v22);
      }
      if ( v14 )
LABEL_14:
        result = -14;
      else
        *v15 += result;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

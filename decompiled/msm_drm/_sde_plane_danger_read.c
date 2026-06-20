__int64 __fastcall sde_plane_danger_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v4; // x8
  __int64 v5; // x9
  int v9; // w0
  __int64 result; // x0
  __int64 v11; // x19
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v13; // x8
  __int64 v15; // x8
  _QWORD *v16; // x11
  unsigned __int64 v17; // x8
  unsigned __int64 v22; // x10
  unsigned __int64 v23; // x9
  unsigned __int64 v25; // x10
  _QWORD v26[6]; // [xsp+0h] [xbp-30h] BYREF

  v26[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 32);
  v5 = *(_QWORD *)(v4 + 152);
  memset(v26, 0, 40);
  if ( v5 )
  {
    if ( *a4
      || (v9 = snprintf((char *)v26, 0x28u, "%d\n", *(unsigned __int8 *)(v4 + 3652) ^ 1), (unsigned int)v9 > 0x27) )
    {
      result = 0;
    }
    else
    {
      if ( a3 < 0x28 )
        goto LABEL_14;
      v11 = v9;
      _check_object_size(v26, v9, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v13 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v13 = a2 & ((__int64)(a2 << 8) >> 8);
      result = v11;
      _CF = 0x8000000000LL - v11 >= v13;
      v15 = v11;
      v16 = a4;
      if ( _CF )
      {
        v17 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v22 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v17);
        v15 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
        result = v11;
        v16 = a4;
        v23 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v25 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v25 - 4096);
        _WriteStatusReg(TTBR1_EL1, v25);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v23);
      }
      if ( v15 )
LABEL_14:
        result = -14;
      else
        *v16 += result;
    }
  }
  else
  {
    result = -19;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

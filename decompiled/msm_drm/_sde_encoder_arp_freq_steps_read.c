__int64 __fastcall sde_encoder_arp_freq_steps_read(__int64 a1, unsigned __int64 a2, __int64 a3, _QWORD *a4)
{
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x8
  _DWORD *v8; // x8
  signed int v11; // w0
  __int64 v12; // x19
  unsigned __int64 StatusReg; // x10
  unsigned __int64 v14; // x8
  __int64 v16; // x8
  _QWORD *v17; // x11
  unsigned __int64 v18; // x8
  unsigned __int64 v23; // x10
  unsigned __int64 v24; // x9
  unsigned __int64 v26; // x10
  _QWORD v27[4]; // [xsp+0h] [xbp-20h] BYREF

  result = 0;
  v27[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *a4;
  memset(v27, 0, 21);
  if ( !v6 )
  {
    if ( a1 && (v7 = *(_QWORD *)(a1 + 32)) != 0 && (v8 = *(_DWORD **)(v7 + 4896)) != nullptr )
    {
      v11 = scnprintf(v27, 21, "%u %u %u %u %u\n", *v8, v8[1], v8[2], v8[3], v8[4]);
      if ( (unsigned int)v11 <= 0x14 )
      {
        v12 = v11;
        _check_object_size(v27, v11, 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v14 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v14 = a2 & ((__int64)(a2 << 8) >> 8);
        result = v12;
        _CF = 0x8000000000LL - v12 >= v14;
        v16 = v12;
        v17 = a4;
        if ( _CF )
        {
          v18 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v23 = *(_QWORD *)(StatusReg + 8);
          _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
          _WriteStatusReg(TTBR0_EL1, v23);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v18);
          v16 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
          result = v12;
          v17 = a4;
          v24 = _ReadStatusReg(DAIF);
          __asm { MSR             DAIFSet, #3 }
          v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
          _WriteStatusReg(TTBR0_EL1, v26 - 4096);
          _WriteStatusReg(TTBR1_EL1, v26);
          __isb(0xFu);
          _WriteStatusReg(DAIF, v24);
        }
        if ( v16 )
          result = -14;
        else
          *v17 += result;
      }
      else
      {
        result = 0;
      }
    }
    else
    {
      result = -22;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

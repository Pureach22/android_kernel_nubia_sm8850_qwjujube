__int64 __fastcall sde_core_perf_threshold_high_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v5; // x0
  unsigned __int64 StatusReg; // x9
  unsigned __int64 v7; // x10
  unsigned __int64 v8; // x10
  unsigned __int64 v14; // x9
  __int64 v16; // [xsp+8h] [xbp-18h] BYREF
  __int16 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 32) )
    JUMPOUT(0x105164);
  if ( a3 > 9 )
    JUMPOUT(0x105160);
  v17 = 0;
  v16 = 0;
  v5 = _check_object_size(&v16, a3, 0);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v7 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v7 = a2 & ((__int64)(a2 << 8) >> 8);
  if ( 0x8000000000LL - a3 < v7 )
    JUMPOUT(0x10509C);
  v8 = _ReadStatusReg(DAIF);
  __asm { MSR             DAIFSet, #3 }
  v14 = *(_QWORD *)(StatusReg + 8);
  _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
  _WriteStatusReg(TTBR0_EL1, v14);
  __isb(0xFu);
  _WriteStatusReg(DAIF, v8);
  return sub_105104(v5);
}

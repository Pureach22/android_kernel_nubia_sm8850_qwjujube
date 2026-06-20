__int64 __fastcall ccid_ctrl_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x22
  __int64 v5; // x21
  __int64 result; // x0
  int v7; // w20
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9
  _QWORD v20[6]; // [xsp+0h] [xbp-30h] BYREF

  v20[5] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 32);
  if ( !*(_DWORD *)(v3 + 232) )
    goto LABEL_22;
  if ( a3 >= 4 )
    v5 = 4;
  else
    v5 = a3;
  if ( !*(_DWORD *)(v3 + 324) && *(_DWORD *)(v3 + 232) )
  {
    memset(v20, 0, 40);
    init_wait_entry(v20, 0);
    while ( 1 )
    {
      result = prepare_to_wait_event(v3 + 296, v20, 1);
      if ( *(_DWORD *)(v3 + 324) || !*(_DWORD *)(v3 + 232) )
      {
        finish_wait(v3 + 296, v20);
        goto LABEL_13;
      }
      if ( result )
        break;
      schedule();
    }
    if ( (result & 0x80000000) != 0 )
    {
      result = (int)result;
      goto LABEL_23;
    }
  }
LABEL_13:
  *(_DWORD *)(v3 + 324) = 0;
  if ( *(_DWORD *)(v3 + 232) )
  {
    v7 = v5;
    _check_object_size(v3 + 320, v5, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v9 = a2 & ((__int64)(a2 << 8) >> 8);
    if ( 0x8000000000LL - v5 >= v9 )
    {
      v10 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v16 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v16);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v10);
      v7 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL, v3 + 320, v5);
      v17 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v19 - 4096);
      _WriteStatusReg(TTBR1_EL1, v19);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v17);
    }
    if ( v7 )
      result = -14;
    else
      result = v5;
  }
  else
  {
LABEL_22:
    result = -19;
  }
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}

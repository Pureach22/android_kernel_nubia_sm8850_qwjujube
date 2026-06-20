__int64 __fastcall syna_ioctl(__int64 a1, int a2, unsigned __int64 a3)
{
  _DWORD *v4; // x20
  __int64 v5; // x0
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  unsigned __int64 v8; // x9
  unsigned __int64 v14; // x8
  __int64 v15; // x0
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v20; // x9
  unsigned __int64 v21; // x9
  unsigned __int64 v23; // x8
  unsigned __int64 v24; // x8
  unsigned __int64 v26; // x9
  __int64 result; // x0
  _QWORD v28[5]; // [xsp+8h] [xbp-38h] BYREF
  int v29; // [xsp+34h] [xbp-Ch] BYREF
  __int64 v30; // [xsp+38h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_DWORD **)(a1 + 32);
  v29 = 0;
  switch ( a2 )
  {
    case -1073451005:
      v29 = v4[270];
      mutex_lock(v4 + 284);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v20 = a3, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v20 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v20 < 0x7FFFFFFFFDLL )
      {
        v21 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v23 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v23 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v23);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v21);
        v15 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v29, 4);
        v24 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v26 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v26 - 4096);
        _WriteStatusReg(TTBR1_EL1, v26);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v24);
LABEL_20:
        if ( !v15 )
        {
          mutex_unlock(v4 + 284);
          result = 0;
          break;
        }
      }
LABEL_21:
      mutex_unlock(v4 + 284);
      result = -14;
      break;
    case -1073451006:
      v29 = v4[376];
      mutex_lock(v4 + 284);
      v6 = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(v6 + 70) & 0x20) != 0 || (v7 = a3, (*(_QWORD *)v6 & 0x4000000) != 0) )
        v7 = a3 & ((__int64)(a3 << 8) >> 8);
      if ( v7 < 0x7FFFFFFFFDLL )
      {
        v8 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v14 = *(_QWORD *)(v6 + 8);
        _WriteStatusReg(TTBR1_EL1, v14 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v14);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v8);
        v15 = _arch_copy_to_user(a3 & 0xFF7FFFFFFFFFFFFFLL, &v29, 4);
        v16 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v18 - 4096);
        _WriteStatusReg(TTBR1_EL1, v18);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v16);
        goto LABEL_20;
      }
      goto LABEL_21;
    case -1073451007:
      if ( v4[376] )
      {
        if ( !v4[282] )
        {
          memset(v28, 0, sizeof(v28));
          init_wait_entry(v28, 0);
          while ( 1 )
          {
            v5 = prepare_to_wait_event(v4 + 274, v28, 1);
            if ( v4[282] )
              break;
            if ( v5 )
              goto LABEL_26;
            schedule();
          }
          finish_wait(v4 + 274, v28);
        }
LABEL_26:
        result = 0;
        v4[282] = 0;
      }
      else
      {
        result = -11;
      }
      break;
    default:
      result = -25;
      break;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

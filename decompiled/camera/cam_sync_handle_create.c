__int64 __fastcall cam_sync_handle_create(__int64 a1)
{
  __int64 v1; // x1
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x19
  unsigned __int64 v6; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x9
  unsigned __int64 v9; // x9
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v18; // x9
  _QWORD v19[7]; // [xsp+0h] [xbp-50h] BYREF
  __int64 v20; // [xsp+38h] [xbp-18h]
  unsigned int v21; // [xsp+40h] [xbp-10h] BYREF
  __int64 v22; // [xsp+48h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_DWORD *)(a1 + 4) != 68 || (v1 = *(_QWORD *)(a1 + 16)) == 0 )
  {
    result = 4294967274LL;
    goto LABEL_6;
  }
  v21 = 0;
  v20 = 0;
  memset(v19, 0, sizeof(v19));
  if ( inline_copy_from_user_2((int)v19, v1, 0x44u) )
    goto LABEL_4;
  HIBYTE(v20) = 0;
  result = cam_sync_create_util(&v21, (const char *)v19, 0, 0);
  if ( (_DWORD)result )
    goto LABEL_6;
  v4 = a1;
  v5 = *(unsigned int *)(a1 + 4);
  if ( (unsigned int)v5 >= 0x45 )
  {
    _copy_overflow(68, v5);
LABEL_4:
    result = 4294967282LL;
    goto LABEL_6;
  }
  v6 = *(_QWORD *)(v4 + 16);
  _check_object_size(v19, v5, 1);
  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v8 = v6, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
    v8 = v6 & ((__int64)(v6 << 8) >> 8);
  result = 0;
  if ( 0x8000000000LL - v5 >= v8 )
  {
    v9 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v15 = *(_QWORD *)(StatusReg + 8);
    _WriteStatusReg(TTBR1_EL1, v15 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
    _WriteStatusReg(TTBR0_EL1, v15);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v9);
    v5 = _arch_copy_to_user(v6 & 0xFF7FFFFFFFFFFFFFLL);
    result = 0;
    v16 = _ReadStatusReg(DAIF);
    __asm { MSR             DAIFSet, #3 }
    v18 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
    _WriteStatusReg(TTBR0_EL1, v18 - 4096);
    _WriteStatusReg(TTBR1_EL1, v18);
    __isb(0xFu);
    _WriteStatusReg(DAIF, v16);
  }
  if ( v5 )
    goto LABEL_4;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}

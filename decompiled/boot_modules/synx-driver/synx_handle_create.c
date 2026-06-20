__int64 __fastcall synx_handle_create(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v7; // x19
  unsigned __int64 v8; // x21
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x9
  unsigned __int64 v11; // x9
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v20; // x9
  _QWORD v21[2]; // [xsp+8h] [xbp-88h] BYREF
  int *v22; // [xsp+18h] [xbp-78h]
  __int64 v23; // [xsp+20h] [xbp-70h]
  int v24; // [xsp+2Ch] [xbp-64h] BYREF
  _QWORD v25[8]; // [xsp+30h] [xbp-60h] BYREF
  _QWORD v26[2]; // [xsp+70h] [xbp-20h] BYREF
  __int64 v27; // [xsp+80h] [xbp-10h]
  __int64 v28; // [xsp+88h] [xbp-8h]

  v28 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v22 = nullptr;
  v23 = 0;
  if ( v2 != 88 )
  {
    result = 4294967274LL;
    goto LABEL_5;
  }
  v4 = *(_QWORD *)(a1 + 16);
  v24 = 0;
  memset(v25, 0, sizeof(v25));
  v26[0] = 0;
  v26[1] = 0;
  v27 = 0;
  if ( inline_copy_from_user((int)v25, v4, 0x58u) )
    goto LABEL_3;
  v21[0] = v25;
  v21[1] = v26;
  LODWORD(v23) = HIDWORD(v26[0]);
  if ( (v26[0] & 0x800000000LL) != 0 )
  {
    v22 = &v24;
    v24 = v27;
  }
  result = synx_create(a2, v21);
  if ( !(_DWORD)result )
  {
    v7 = *(unsigned int *)(a1 + 4);
    if ( (unsigned int)v7 >= 0x59 )
    {
      _copy_overflow(88, *(unsigned int *)(a1 + 4));
    }
    else
    {
      v8 = *(_QWORD *)(a1 + 16);
      _check_object_size(v25, v7, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = v8, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v10 = v8 & ((__int64)(v8 << 8) >> 8);
      result = 0;
      if ( 0x8000000000LL - v7 >= v10 )
      {
        v11 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v17 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v17 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v17);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v11);
        v7 = _arch_copy_to_user(v8 & 0xFF7FFFFFFFFFFFFFLL, v25, v7);
        result = 0;
        v18 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v20 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v20 - 4096);
        _WriteStatusReg(TTBR1_EL1, v20);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v18);
      }
      if ( !v7 )
        goto LABEL_5;
    }
LABEL_3:
    result = 4294967282LL;
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}

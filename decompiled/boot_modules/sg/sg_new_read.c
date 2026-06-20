unsigned __int64 __fastcall sg_new_read(__int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x24
  unsigned int v8; // w8
  unsigned __int64 v9; // x25
  __int64 v10; // x22
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v18; // x9
  __int64 v19; // x0
  unsigned __int64 v20; // x8
  unsigned __int64 v22; // x9
  int v23; // w22
  int v24; // w23
  unsigned __int64 v25; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  if ( (*(_QWORD *)StatusReg & 0x400000) == 0 )
  {
    if ( a3 >= 0x58 )
      goto LABEL_3;
LABEL_19:
    v23 = -22;
    goto LABEL_26;
  }
  if ( a3 < 0x40 )
    goto LABEL_19;
LABEL_3:
  v8 = *(unsigned __int8 *)(a4 + 65);
  *(_BYTE *)(a4 + 123) = 0;
  if ( v8 )
  {
    v9 = *(_QWORD *)(a4 + 88);
    if ( v9 )
    {
      if ( (*(_BYTE *)(a4 + 121) & 1) != 0 || (~*(unsigned __int8 *)(a4 + 144) & 0x70) == 0 )
      {
        if ( v8 >= (unsigned int)*(unsigned __int8 *)(a4 + 151) + 8 )
          v8 = *(unsigned __int8 *)(a4 + 151) + 8;
        if ( v8 >= 0x60 )
          v10 = 96;
        else
          v10 = v8;
        _check_object_size(a4 + 144, v10, 1);
        if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v11 = v9, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
          v11 = v9 & ((__int64)(v9 << 8) >> 8);
        if ( 0x8000000000LL - v10 < v11 )
          goto LABEL_17;
        v12 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v18 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v18);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v12);
        v19 = _arch_copy_to_user(v9 & 0xFF7FFFFFFFFFFFFFLL, a4 + 144, v10);
        v20 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v22 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v22 - 4096);
        _WriteStatusReg(TTBR1_EL1, v22);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v20);
        if ( v19 )
        {
LABEL_17:
          v23 = -14;
          goto LABEL_26;
        }
        *(_BYTE *)(a4 + 123) = v10;
        *(_WORD *)(a4 + 126) = 8;
      }
    }
  }
  if ( *(_BYTE *)(a4 + 121) || *(_WORD *)(a4 + 124) || *(_WORD *)(a4 + 126) )
    *(_DWORD *)(a4 + 136) |= 1u;
  v23 = put_sg_io_hdr(a4 + 56);
LABEL_26:
  v24 = sg_finish_rem_req(a4);
  sg_remove_request(a1, a4);
  v25 = v24;
  if ( !v24 )
    v25 = a3;
  if ( v23 )
    return v23;
  else
    return v25;
}

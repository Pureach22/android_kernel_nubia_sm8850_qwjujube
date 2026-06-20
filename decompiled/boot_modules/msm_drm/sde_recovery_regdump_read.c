unsigned __int64 __fastcall sde_recovery_regdump_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, _QWORD *a4)
{
  __int64 v7; // x22
  unsigned __int64 v8; // x8
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v10; // x9
  __int64 v11; // x0
  unsigned __int64 v12; // x9
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v21; // x9

  mutex_lock(&unk_2942D0);
  if ( byte_2945DC != 1 )
  {
    a3 = -95;
    goto LABEL_31;
  }
  if ( !HIDWORD(qword_2945C0) && !qword_2945C8 )
  {
    if ( !qword_2945B0 )
    {
      qword_2945B0 = vzalloc_noprof(0x200000);
      if ( !qword_2945B0 )
      {
        a3 = -12;
        goto LABEL_31;
      }
    }
    LODWORD(qword_2945C0) = 0;
    qword_2945B8 = 0x200000;
    qword_2945C8 = qword_2942A8;
    if ( !qword_2942A8 )
      goto LABEL_15;
LABEL_13:
    sde_dbg_recovery_dump_reg_blk();
    goto LABEL_15;
  }
  if ( HIDWORD(qword_2945B8) != (_DWORD)qword_2945C0 || !qword_2945C8 )
    goto LABEL_15;
  LODWORD(qword_2945C0) = 0;
  qword_2945B8 = 0x200000;
  if ( qword_2945C8 == qword_2942B0 )
  {
    qword_2945C8 = 0;
    goto LABEL_15;
  }
  qword_2945C8 = *(_QWORD *)qword_2945C8;
  if ( qword_2945C8 )
    goto LABEL_13;
LABEL_15:
  v7 = qword_2945B0;
  v8 = (unsigned int)(HIDWORD(qword_2945B8) - qword_2945C0);
  if ( (int)v8 >= 1 )
  {
    if ( v8 <= a3 )
      a3 = (unsigned int)v8;
    else
      a3 = (unsigned int)a3;
    _check_object_size(qword_2945B0 + (int)qword_2945C0, a3, 1);
    StatusReg = _ReadStatusReg(SP_EL0);
    if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v10 = a2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
      v10 = a2 & ((__int64)(a2 << 8) >> 8);
    v11 = a3;
    if ( 0x8000000000LL - a3 >= v10 )
    {
      v12 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v18 = *(_QWORD *)(StatusReg + 8);
      _WriteStatusReg(TTBR1_EL1, v18 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
      _WriteStatusReg(TTBR0_EL1, v18);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v12);
      v11 = _arch_copy_to_user(a2 & 0xFF7FFFFFFFFFFFFFLL);
      v19 = _ReadStatusReg(DAIF);
      __asm { MSR             DAIFSet, #3 }
      v21 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
      _WriteStatusReg(TTBR0_EL1, v21 - 4096);
      _WriteStatusReg(TTBR1_EL1, v21);
      __isb(0xFu);
      _WriteStatusReg(DAIF, v19);
    }
    if ( v11 )
    {
      a3 = -14;
      goto LABEL_31;
    }
    LODWORD(qword_2945C0) = qword_2945C0 + a3;
    *a4 += a3;
    if ( (_DWORD)a3 )
      goto LABEL_31;
    v7 = qword_2945B0;
  }
  a3 = 0;
  if ( v7 )
    HIDWORD(qword_2945C0) = 1;
LABEL_31:
  mutex_unlock(&unk_2942D0);
  return a3;
}

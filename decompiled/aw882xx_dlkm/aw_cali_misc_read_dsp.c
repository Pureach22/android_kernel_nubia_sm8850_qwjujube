__int64 __fastcall aw_cali_misc_read_dsp(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // x23
  unsigned int v3; // w21
  __int64 v5; // x20
  __int64 v6; // x19
  unsigned int dsp_msg; // w0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v9; // x9
  unsigned __int64 v10; // x9
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v19; // x9
  unsigned int v20; // w21
  __int64 *v21; // x8
  __int64 v22; // x1

  v2 = *(_QWORD *)(a2 + 16);
  v3 = *(_DWORD *)(a2 + 4);
  v5 = *(int *)(a2 + 12);
  v6 = _kmalloc_noprof(v5, 3520);
  if ( v6 )
  {
    dsp_msg = aw882xx_dsp_read_dsp_msg(a1, v3, v6, (unsigned int)v5);
    if ( dsp_msg )
    {
      v21 = *(__int64 **)(a1 + 112);
      v20 = dsp_msg;
      v22 = v21[14];
      if ( !v22 )
        v22 = *v21;
      printk(&unk_2324F, v22, "aw_cali_misc_read_dsp");
    }
    else if ( (v5 & 0x80000000) != 0 )
    {
      __break(0x800u);
      v20 = -14;
    }
    else
    {
      _check_object_size(v6, v5, 1);
      StatusReg = _ReadStatusReg(SP_EL0);
      if ( (*(_BYTE *)(StatusReg + 70) & 0x20) != 0 || (v9 = v2, (*(_QWORD *)StatusReg & 0x4000000) != 0) )
        v9 = v2 & ((__int64)(v2 << 8) >> 8);
      if ( 0x8000000000LL - v5 >= v9 )
      {
        v10 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v16 = *(_QWORD *)(StatusReg + 8);
        _WriteStatusReg(TTBR1_EL1, v16 & 0xFFFF000000000000LL | _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL);
        _WriteStatusReg(TTBR0_EL1, v16);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v10);
        v5 = _arch_copy_to_user(v2 & 0xFF7FFFFFFFFFFFFFLL, v6, v5);
        v17 = _ReadStatusReg(DAIF);
        __asm { MSR             DAIFSet, #3 }
        v19 = _ReadStatusReg(TTBR1_EL1) & 0xFFFFFFFFFFFFLL;
        _WriteStatusReg(TTBR0_EL1, v19 - 4096);
        _WriteStatusReg(TTBR1_EL1, v19);
        __isb(0xFu);
        _WriteStatusReg(DAIF, v17);
      }
      if ( v5 )
        v20 = -14;
      else
        v20 = 0;
    }
    kfree(v6);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v20;
}

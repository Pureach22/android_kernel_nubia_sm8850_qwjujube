__int64 __fastcall cvp_clock_reg_print(__int64 a1)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v4; // x8
  unsigned __int64 v5; // x8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8

  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_88129, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF8034u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v4 = _ReadStatusReg(SP_EL0);
    printk(&unk_85EED, *(unsigned int *)(v4 + 1800), *(unsigned int *)(v4 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF804Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v5 = _ReadStatusReg(SP_EL0);
    printk(&unk_8387A, *(unsigned int *)(v5 + 1800), *(unsigned int *)(v5 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF8068u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v6 = _ReadStatusReg(SP_EL0);
    printk(&unk_92E52, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF807Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v7 = _ReadStatusReg(SP_EL0);
    printk(&unk_8F2F6, *(unsigned int *)(v7 + 1800), *(unsigned int *)(v7 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF80A4u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    printk(&unk_8FFE5, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF80E4u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v9 = _ReadStatusReg(SP_EL0);
    printk(&unk_86AC1, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF808Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v10 = _ReadStatusReg(SP_EL0);
    printk(&unk_96CFD, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
  }
  _read_register(a1, 0xF805Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v11 = _ReadStatusReg(SP_EL0);
    printk(&unk_85729, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
  }
  _read_gcc_register(a1, 0x8F008u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v12 = _ReadStatusReg(SP_EL0);
    printk(&unk_89C65, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
  }
  _read_gcc_register(a1, 0x8F01Cu);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v13 = _ReadStatusReg(SP_EL0);
    printk(&unk_94C25, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
  }
  _read_gcc_register(a1, 0x8F004u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v14 = _ReadStatusReg(SP_EL0);
    printk(&unk_85760, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
  }
  result = _read_gcc_register(a1, 0x8F024u);
  if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
  {
    v15 = _ReadStatusReg(SP_EL0);
    return printk(&unk_8F324, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
  }
  return result;
}

__int64 __fastcall _print_sidebandmanager_regs_kaanapali(__int64 a1)
{
  int v2; // w0
  unsigned int v3; // w0
  __int64 v4; // x3
  unsigned int v5; // w0
  __int64 v6; // x3
  int v7; // w21
  unsigned __int64 v8; // x8
  __int64 result; // x0
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x8
  unsigned __int64 v14; // x8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x8
  unsigned __int64 v17; // x8
  unsigned __int64 v18; // x8
  unsigned __int64 v19; // x8
  unsigned __int64 v20; // x8
  unsigned __int64 StatusReg; // x8

  _read_register(a1, 0xD0300u);
  v2 = _read_register(a1, 0xA0168u);
  _write_register(a1, 0xA0168u, v2 | 4);
  usleep_range_state(500, 1000, 2);
  v3 = _read_register(a1, 0xA0168u);
  if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
    printk(&unk_8920C, &unk_8425A, v3, v4);
  v5 = _read_register(a1, 0xA0170u);
  if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
    printk(&unk_84B30, &unk_8425A, v5, v6);
  v7 = _read_register(a1, 0xA0168u);
  if ( (v7 & 4) != 0 )
  {
    if ( (_read_gcc_register(a1, 0x8F008u) & 0x80000000) != 0 )
    {
      if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        printk(&unk_91E6A, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      }
    }
    else
    {
      _read_register(a1, 0xD0010u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v11 = _ReadStatusReg(SP_EL0);
        printk(&unk_89A32, *(unsigned int *)(v11 + 1800), *(unsigned int *)(v11 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0248u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v12 = _ReadStatusReg(SP_EL0);
        printk(&unk_8356C, *(unsigned int *)(v12 + 1800), *(unsigned int *)(v12 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0020u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v13 = _ReadStatusReg(SP_EL0);
        printk(&unk_87292, *(unsigned int *)(v13 + 1800), *(unsigned int *)(v13 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0024u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v14 = _ReadStatusReg(SP_EL0);
        printk(&unk_8CD34, *(unsigned int *)(v14 + 1800), *(unsigned int *)(v14 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0028u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v15 = _ReadStatusReg(SP_EL0);
        printk(&unk_92B4C, *(unsigned int *)(v15 + 1800), *(unsigned int *)(v15 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD002Cu);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v16 = _ReadStatusReg(SP_EL0);
        printk(&unk_84B5E, *(unsigned int *)(v16 + 1800), *(unsigned int *)(v16 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0030u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v17 = _ReadStatusReg(SP_EL0);
        printk(&unk_91120, *(unsigned int *)(v17 + 1800), *(unsigned int *)(v17 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0034u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v18 = _ReadStatusReg(SP_EL0);
        printk(&unk_8C35A, *(unsigned int *)(v18 + 1800), *(unsigned int *)(v18 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD0038u);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v19 = _ReadStatusReg(SP_EL0);
        printk(&unk_88941, *(unsigned int *)(v19 + 1800), *(unsigned int *)(v19 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0xD003Cu);
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v20 = _ReadStatusReg(SP_EL0);
        printk(&unk_8FDBE, *(unsigned int *)(v20 + 1800), *(unsigned int *)(v20 + 1804), &unk_8E7CE);
      }
      _read_register(a1, 0x17100u);
      _read_register(a1, 0x17104u);
      _read_register(a1, 0x1710Cu);
    }
  }
  else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v8 = _ReadStatusReg(SP_EL0);
    printk(&unk_9603C, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), "warn");
  }
  result = _write_register(a1, 0xA0168u, v7 & 0xFFFFFFFB);
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    v10 = _ReadStatusReg(SP_EL0);
    return printk(&unk_96B43, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), "warn");
  }
  return result;
}

__int64 __fastcall _boot_firmware(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x8
  unsigned int (*v4)(void); // x8
  unsigned int v5; // w24
  char v6; // w22
  unsigned int v7; // w21
  __int64 v9; // x8
  void (__fastcall *v10)(_QWORD); // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(a1 + 2512);
  if ( v3 )
  {
    v4 = *(unsigned int (**)(void))(v3 + 96);
    if ( v4 )
    {
      if ( *((_DWORD *)v4 - 1) != -1303076162 )
        __break(0x8228u);
      if ( v4() && (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
        printk(&unk_8BB65, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
    }
  }
  _write_register(a1, 0xA0048u, 1u);
  v5 = 0;
  while ( 1 )
  {
    v6 = _read_register(a1, 0xA004Cu);
    if ( (v6 & 0xFE) == 4 )
      break;
    usleep_range_state(100, 200, 2);
    v7 = 0;
    if ( (v6 & 1) == 0 && v5++ < 0x1387 )
      continue;
    goto LABEL_17;
  }
  v7 = -61;
  if ( (msm_cvp_debug & 1) == 0 || msm_cvp_debug_out )
  {
LABEL_17:
    if ( (v6 & 1) != 0 )
      goto LABEL_26;
LABEL_18:
    _read_register(a1, 0xA0048u);
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8DAF0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      v9 = *(_QWORD *)(a1 + 2512);
      if ( v9 )
      {
LABEL_21:
        v10 = *(void (__fastcall **)(_QWORD))(v9 + 104);
        if ( v10 )
        {
          if ( *((_DWORD *)v10 - 1) != -639316779 )
            __break(0x8228u);
          v10(a1);
        }
      }
    }
    else
    {
      v9 = *(_QWORD *)(a1 + 2512);
      if ( v9 )
        goto LABEL_21;
    }
    v7 = -19;
    goto LABEL_26;
  }
  printk(&unk_8604D, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
  if ( (v6 & 1) == 0 )
    goto LABEL_18;
LABEL_26:
  _write_register(a1, 0xA0148u, 1u);
  _write_register(a1, 0xA0168u, 0);
  return v7;
}

__int64 __fastcall _acquire_regulator(_QWORD *a1, __int64 a2)
{
  __int64 v4; // x3
  unsigned int v5; // w19
  unsigned __int64 StatusReg; // x8
  unsigned __int64 v8; // x8
  unsigned __int64 v9; // x8

  if ( *((_BYTE *)a1 + 8) != 1 )
    goto LABEL_9;
  v5 = regulator_set_mode(*a1, 2);
  if ( !v5 )
  {
    if ( (msm_cvp_debug & 0x400) == 0 || msm_cvp_debug_out )
      goto LABEL_10;
    printk(&unk_8375D, &unk_8DA84, a1[2], v4);
LABEL_9:
    v5 = 0;
    goto LABEL_10;
  }
  if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_8FF53, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
  }
LABEL_10:
  if ( !(unsigned int)regulator_is_enabled(*a1) )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      v8 = _ReadStatusReg(SP_EL0);
      printk(&unk_86A1A, *(unsigned int *)(v8 + 1800), *(unsigned int *)(v8 + 1804), "warn");
    }
    if ( *(_BYTE *)(*(_QWORD *)(a2 + 2208) + 376LL) )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        v9 = _ReadStatusReg(SP_EL0);
        printk(&unk_8E7D2, *(unsigned int *)(v9 + 1800), *(unsigned int *)(v9 + 1804), &unk_8E7CE);
      }
      __break(0x800u);
    }
  }
  return v5;
}

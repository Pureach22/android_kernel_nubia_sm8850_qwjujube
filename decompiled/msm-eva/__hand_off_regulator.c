__int64 __fastcall _hand_off_regulator(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x3
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w19

  if ( *(_BYTE *)(a1 + 8) != 1 )
    return 0;
  result = regulator_set_mode(*(_QWORD *)a1, 1);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v5 = result;
      printk(&unk_874A0, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
      return v5;
    }
  }
  else if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
  {
    printk(&unk_83794, &unk_8DA84, *(_QWORD *)(a1 + 16), v3);
    return 0;
  }
  return result;
}

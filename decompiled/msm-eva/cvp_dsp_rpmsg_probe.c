__int64 __fastcall cvp_dsp_rpmsg_probe(__int64 a1)
{
  __int64 v2; // x8
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v5; // w19
  unsigned __int64 v6; // x8
  __int64 v7; // x2
  __int64 v8; // x3
  char *s1[2]; // [xsp+0h] [xbp-10h] BYREF

  s1[1] = *(char **)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 96);
  s1[0] = nullptr;
  result = of_property_read_string(*(_QWORD *)(v2 + 744), "label", s1);
  if ( (_DWORD)result )
  {
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      v5 = result;
      printk(&unk_8D622, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      result = v5;
    }
  }
  else if ( !strcmp(s1[0], "cdsp") )
  {
    mutex_lock(&gfa_cv);
    qword_6C660 = a1;
    dword_6C668 = 2;
    mutex_unlock(&gfa_cv);
    complete(&dword_6C788);
    result = 0;
    if ( (msm_cvp_debug & 0x800) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_9544B, "dsp", v7, v8);
      result = 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v6 = _ReadStatusReg(SP_EL0);
      printk(&unk_86693, *(unsigned int *)(v6 + 1800), *(unsigned int *)(v6 + 1804), &unk_8E7CE);
      result = 4294967274LL;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

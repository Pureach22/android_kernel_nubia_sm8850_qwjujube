__int64 __fastcall _reset_control_deassert_name(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v8; // w19

  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD *)(v2 + 312);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 320);
  if ( v4 >= v5 )
  {
LABEL_4:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_85EBB, &unk_8DA84, "__reset_control_deassert_name", s2);
      return 4294967274LL;
    }
  }
  else
  {
    while ( strcmp(*(const char **)(v4 + 16), s2) )
    {
      v4 += 24LL;
      if ( v4 >= v5 )
        goto LABEL_4;
    }
    result = reset_control_deassert(*(_QWORD *)v4);
    if ( (_DWORD)result )
    {
      if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v8 = result;
        printk(&unk_8D9C7, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
        return v8;
      }
    }
    else if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_8BA4C, &unk_8DA84, "__reset_control_deassert_name", *(_QWORD *)(v4 + 16));
      return 0;
    }
  }
  return result;
}

__int64 __fastcall _reset_control_release(__int64 a1, char *s2)
{
  __int64 v2; // x8
  unsigned __int64 v4; // x20
  unsigned __int64 v5; // x21
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  v2 = *(_QWORD *)(a1 + 2208);
  v4 = *(_QWORD *)(v2 + 312);
  v5 = v4 + 24LL * *(unsigned int *)(v2 + 320);
  if ( v4 >= v5 )
  {
LABEL_4:
    result = 4294967274LL;
    if ( (msm_cvp_debug & 0x400) == 0 || msm_cvp_debug_out )
      return result;
    printk(&unk_85EBB, &unk_8DA84, "__reset_control_release", s2);
    return 4294967274LL;
  }
  while ( strcmp(*(const char **)(v4 + 16), s2) )
  {
    v4 += 24LL;
    if ( v4 >= v5 )
      goto LABEL_4;
  }
  if ( *(_DWORD *)(v4 + 12) != 1 )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 2) == 0 || msm_cvp_debug_out )
      return result;
    StatusReg = _ReadStatusReg(SP_EL0);
    printk(&unk_8F2C1, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), "warn");
    return 4294967274LL;
  }
  reset_control_release(*(_QWORD *)v4);
  if ( (msm_cvp_debug & 0x400) != 0 && !msm_cvp_debug_out )
    printk(&unk_8A54C, &unk_8DA84, "__reset_control_release", *(_QWORD *)(v4 + 16));
  *(_DWORD *)(v4 + 12) = 2;
  return 0;
}

__int64 __fastcall cvp_print_frpc_node(int a1, __int64 a2)
{
  bool v3; // zf
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w19
  unsigned int v8; // w20
  const char *v9; // x0
  unsigned __int64 v10; // x8
  const char *debug_level_str_0; // x0

  if ( a2 )
  {
    v3 = (msm_cvp_debug & a1) == 0;
    result = 0;
    if ( !v3 && !msm_cvp_debug_out )
    {
      if ( (unsigned int)(a1 - 1) > 1 )
      {
        debug_level_str_0 = get_debug_level_str_0(a1);
        printk(&unk_9478E, debug_level_str_0, *(unsigned int *)(a2 + 16), *(unsigned int *)(a2 + 20));
      }
      else
      {
        StatusReg = _ReadStatusReg(SP_EL0);
        v7 = *(_DWORD *)(StatusReg + 1800);
        v8 = *(_DWORD *)(StatusReg + 1804);
        v9 = get_debug_level_str_0(a1);
        printk(&unk_8AC1F, v7, v8, v9);
      }
      return 0;
    }
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      v10 = _ReadStatusReg(SP_EL0);
      printk(&unk_8F9CC, *(unsigned int *)(v10 + 1800), *(unsigned int *)(v10 + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}

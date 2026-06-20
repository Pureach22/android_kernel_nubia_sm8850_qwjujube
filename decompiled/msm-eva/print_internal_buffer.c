__int64 __fastcall print_internal_buffer(__int64 result, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w21
  unsigned int v8; // w22
  const char *v9; // x0
  unsigned __int64 v12; // x8
  unsigned int v13; // w20
  unsigned int v14; // w21
  const char *v15; // x0
  const char *debug_level_str; // x0
  const char *v17; // x0

  if ( a4 && a3 && (msm_cvp_debug & (unsigned int)result) != 0 )
  {
    if ( *(_QWORD *)(*(_QWORD *)(a4 + 56) + 48LL) )
    {
      if ( !msm_cvp_debug_out )
      {
        if ( (unsigned int)(result - 1) > 1 )
        {
          debug_level_str = get_debug_level_str(result);
          return printk(&unk_8C842, debug_level_str, a2, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
        }
        else
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v7 = *(_DWORD *)(StatusReg + 1800);
          v8 = *(_DWORD *)(StatusReg + 1804);
          v9 = get_debug_level_str(result);
          return printk(&unk_95BF5, v7, v8, v9);
        }
      }
    }
    else if ( !msm_cvp_debug_out )
    {
      if ( (unsigned int)(result - 1) > 1 )
      {
        v17 = get_debug_level_str(result);
        return printk(&unk_859E2, v17, a2, (unsigned int)(*(_DWORD *)(a3 + 324) ^ *(_DWORD *)(a3 + 320)));
      }
      else
      {
        v12 = _ReadStatusReg(SP_EL0);
        v13 = *(_DWORD *)(v12 + 1800);
        v14 = *(_DWORD *)(v12 + 1804);
        v15 = get_debug_level_str(result);
        return printk(&unk_8632F, v13, v14, v15);
      }
    }
  }
  return result;
}

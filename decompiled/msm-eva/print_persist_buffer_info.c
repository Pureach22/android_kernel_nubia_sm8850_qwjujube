__int64 __fastcall print_persist_buffer_info(__int64 result, __int64 a2, unsigned int a3, __int64 a4, __int64 a5)
{
  unsigned __int64 StatusReg; // x8
  unsigned int v7; // w19
  unsigned int v8; // w20
  const char *v9; // x0
  unsigned int v10; // w8
  const char *v11; // x21
  unsigned __int64 v14; // x8
  unsigned int v15; // w21
  unsigned int v16; // w22
  const char *v17; // x0
  const char *debug_level_str; // x19
  __int64 feature_name_from_type; // x0
  const char *v20; // x0

  if ( a4 && a2 && (msm_cvp_debug & (unsigned int)result) != 0 )
  {
    if ( a5 )
    {
      if ( !msm_cvp_debug_out )
      {
        if ( (unsigned int)(result - 1) > 1 )
        {
          debug_level_str = get_debug_level_str(result);
          feature_name_from_type = get_feature_name_from_type(*(unsigned int *)(a5 + 64));
          return printk(&unk_8B4CC, debug_level_str, feature_name_from_type, *(unsigned int *)(a5 + 72));
        }
        else
        {
          StatusReg = _ReadStatusReg(SP_EL0);
          v7 = *(_DWORD *)(StatusReg + 1800);
          v8 = *(_DWORD *)(StatusReg + 1804);
          v9 = get_debug_level_str(result);
          v10 = *(_DWORD *)(a5 + 64);
          v11 = v9;
          get_feature_name_from_type(v10);
          return printk(&unk_8C7DC, v7, v8, v11);
        }
      }
    }
    else if ( !msm_cvp_debug_out )
    {
      if ( (unsigned int)(result - 1) > 1 )
      {
        v20 = get_debug_level_str(result);
        return printk(&unk_8EC7B, v20, a2, a3);
      }
      else
      {
        v14 = _ReadStatusReg(SP_EL0);
        v15 = *(_DWORD *)(v14 + 1800);
        v16 = *(_DWORD *)(v14 + 1804);
        v17 = get_debug_level_str(result);
        return printk(&unk_8EC2C, v15, v16, v17);
      }
    }
  }
  return result;
}

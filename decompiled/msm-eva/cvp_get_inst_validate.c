__int64 *__fastcall cvp_get_inst_validate(__int64 a1, __int64 *a2)
{
  __int64 *result; // x0
  __int64 v4; // x8
  unsigned int (__fastcall *v5)(__int64, const char *); // x8
  unsigned int *v6; // x19
  __int64 v7; // x0

  result = cvp_get_inst(a1, a2);
  if ( result )
  {
    v4 = *(_QWORD *)(result[16] + 256);
    if ( v4 )
    {
      v5 = *(unsigned int (__fastcall **)(__int64, const char *))(v4 + 176);
      if ( v5 )
      {
        v6 = (unsigned int *)result;
        v7 = result[40];
        if ( *((_DWORD *)v5 - 1) != 1644094253 )
          __break(0x8228u);
        if ( v5(v7, "cvp_get_inst_validate") )
        {
          cvp_put_inst(v6);
          return nullptr;
        }
        return (__int64 *)v6;
      }
    }
  }
  else if ( (msm_cvp_debug & 2) != 0 && !msm_cvp_debug_out )
  {
    if ( (unsigned int)__ratelimit(&cvp_get_inst_validate__rs, "cvp_get_inst_validate") )
      printk(&unk_8F85B, "warn", "cvp_get_inst_validate", a2);
    return nullptr;
  }
  return result;
}

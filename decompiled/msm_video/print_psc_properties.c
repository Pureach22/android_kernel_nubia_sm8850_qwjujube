__int64 __fastcall print_psc_properties(__int64 result, __int64 a2, _DWORD *a3)
{
  if ( a2 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
      return printk(&unk_8538F, "high", a2 + 340, result, HIWORD(*a3));
  }
  return result;
}

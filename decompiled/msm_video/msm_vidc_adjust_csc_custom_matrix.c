__int64 __fastcall msm_vidc_adjust_csc_custom_matrix(__int64 a1)
{
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a1 + 308) == 2 )
    goto LABEL_5;
  if ( !(unsigned int)((__int64 (*)(void))msm_vidc_get_parent_value)() )
  {
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      125,
      0,
      "msm_vidc_adjust_csc_custom_matrix");
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
  result = 4294967274LL;
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}

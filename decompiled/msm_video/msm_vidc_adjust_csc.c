__int64 __fastcall msm_vidc_adjust_csc(__int64 a1, __int64 a2)
{
  int v2; // w19
  __int64 result; // x0

  _ReadStatusReg(SP_EL0);
  if ( *(_DWORD *)(a1 + 308) == 2 )
    goto LABEL_8;
  if ( a2 )
    v2 = *(_DWORD *)(a2 + 196);
  else
    v2 = *(_DWORD *)(a1 + 25184);
  if ( !(unsigned int)((__int64 (*)(void))msm_vidc_get_parent_value)() )
  {
    ((void (__fastcall *)(__int64, __int64, _QWORD, const char *))msm_vidc_update_cap_value)(
      a1,
      124,
      v2,
      "msm_vidc_adjust_csc");
LABEL_8:
    result = 0;
    goto LABEL_9;
  }
  result = 4294967274LL;
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}

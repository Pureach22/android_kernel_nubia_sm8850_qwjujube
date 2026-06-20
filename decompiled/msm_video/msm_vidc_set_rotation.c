__int64 __fastcall msm_vidc_set_rotation(__int64 a1, __int64 a2)
{
  unsigned int v2; // w19
  __int64 result; // x0
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v2 = a2;
  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = 0;
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, int *))msm_vidc_v4l2_to_hfi_enum)(a1, a2, &v5) )
    result = 4294967274LL;
  else
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64, int *, __int64, const char *))msm_vidc_packetize_control)(
               a1,
               v2,
               1,
               &v5,
               4,
               "msm_vidc_set_rotation");
  _ReadStatusReg(SP_EL0);
  return result;
}

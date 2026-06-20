__int64 __fastcall msm_vidc_set_preprocess(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  result = ((__int64 (__fastcall *)(__int64, __int64, __int64, int *, __int64, const char *))msm_vidc_packetize_control)(
             a1,
             a2,
             9,
             &v3,
             4,
             "msm_vidc_set_preprocess");
  _ReadStatusReg(SP_EL0);
  return result;
}

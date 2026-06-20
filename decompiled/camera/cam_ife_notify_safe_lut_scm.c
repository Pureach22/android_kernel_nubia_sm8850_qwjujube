__int64 __fastcall cam_ife_notify_safe_lut_scm(char a1)
{
  __int64 result; // x0
  int v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  result = cam_cpas_get_cpas_hw_version(&v3);
  if ( !(_DWORD)result )
  {
    if ( v3 == 1507584 || v3 == 1528064 || v3 == 1507600 )
    {
      result = qcom_scm_smmu_notify_secure_lut(0, a1 & 1);
      if ( (_DWORD)result )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_notify_safe_lut_scm",
          265,
          "scm call to enable safe failed");
        result = 4294967274LL;
      }
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

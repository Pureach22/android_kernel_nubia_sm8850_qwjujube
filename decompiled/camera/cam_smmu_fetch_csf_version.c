__int64 __fastcall cam_smmu_fetch_csf_version(_DWORD *a1)
{
  unsigned int csf_version; // w19
  int v3; // w6
  int v4; // w7
  int v5; // w8
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v8 = 0;
  csf_version = smmu_proxy_get_csf_version(&v7);
  if ( csf_version )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      64,
      1,
      "cam_smmu_fetch_csf_version",
      132,
      "Failed to get CSF version from SMMU proxy: %d",
      csf_version);
  }
  else
  {
    v3 = v7;
    v4 = HIDWORD(v7);
    v5 = v8;
    *a1 = v7;
    a1[1] = v4;
    a1[2] = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      4,
      3,
      "cam_smmu_fetch_csf_version",
      148,
      "CSF version in use %d.%d.%d",
      v3,
      v4,
      v5);
  }
  _ReadStatusReg(SP_EL0);
  return csf_version;
}

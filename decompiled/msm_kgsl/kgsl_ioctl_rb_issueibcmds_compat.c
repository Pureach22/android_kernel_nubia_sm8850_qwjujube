__int64 __fastcall kgsl_ioctl_rb_issueibcmds_compat(__int64 *a1, __int64 a2, unsigned int *a3)
{
  unsigned int v4; // w8
  __int64 v5; // x9
  unsigned int v6; // w8
  __int64 result; // x0
  _QWORD v8[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v9; // [xsp+18h] [xbp-18h]
  __int64 v10; // [xsp+20h] [xbp-10h]
  __int64 v11; // [xsp+28h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v5 = a3[1];
  v9 = 0;
  v10 = 0;
  v8[1] = v5;
  v8[0] = v4;
  v6 = a3[4];
  HIDWORD(v9) = a3[3];
  LODWORD(v10) = v6;
  LODWORD(v9) = a3[2];
  LODWORD(result) = kgsl_ioctl_rb_issueibcmds(a1, a2, (__int64)v8);
  a3[3] = HIDWORD(v9);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}

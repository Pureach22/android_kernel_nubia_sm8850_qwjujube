__int64 __fastcall kgsl_ioctl_cmdstream_freememontimestamp_ctxtid_compat(__int64 *a1, __int64 a2, int *a3)
{
  __int64 v3; // x8
  int v4; // w9
  int v5; // w10
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-20h] BYREF
  int v8; // [xsp+10h] [xbp-10h]
  int v9; // [xsp+14h] [xbp-Ch]
  __int64 v10; // [xsp+18h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v3 = (unsigned int)a3[1];
  v7[0] = 0;
  v7[1] = v3;
  LODWORD(v3) = a3[2];
  v5 = a3[3];
  LODWORD(v7[0]) = v4;
  v8 = v3;
  v9 = v5;
  result = kgsl_ioctl_cmdstream_freememontimestamp_ctxtid(a1, a2, (__int64)v7);
  _ReadStatusReg(SP_EL0);
  return result;
}

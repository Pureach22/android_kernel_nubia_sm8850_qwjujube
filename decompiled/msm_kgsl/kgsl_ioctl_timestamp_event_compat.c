__int64 __fastcall kgsl_ioctl_timestamp_event_compat(_QWORD *a1, __int64 a2, _DWORD *a3)
{
  int v3; // w9
  unsigned int v4; // w8
  __int64 result; // x0
  _DWORD v6[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v7; // [xsp+10h] [xbp-20h]
  __int64 v8; // [xsp+18h] [xbp-18h]
  __int64 v9; // [xsp+20h] [xbp-10h]
  __int64 v10; // [xsp+28h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = a3[1];
  v6[0] = *a3;
  v6[1] = v3;
  v4 = a3[2];
  v8 = (unsigned int)a3[3];
  v7 = v4;
  v9 = (unsigned int)a3[4];
  result = kgsl_ioctl_timestamp_event(a1, a2, (__int64)v6);
  _ReadStatusReg(SP_EL0);
  return result;
}

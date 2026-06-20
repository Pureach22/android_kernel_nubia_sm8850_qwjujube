__int64 __fastcall kgsl_ioctl_submit_commands_compat(__int64 *a1, __int64 a2, int *a3)
{
  int v4; // w8
  int v5; // w9
  int v6; // w9
  unsigned int v7; // w9
  __int64 result; // x0
  _DWORD v9[2]; // [xsp+0h] [xbp-40h] BYREF
  __int64 v10; // [xsp+8h] [xbp-38h]
  int v11; // [xsp+10h] [xbp-30h]
  int v12; // [xsp+14h] [xbp-2Ch]
  __int64 v13; // [xsp+18h] [xbp-28h]
  unsigned __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *a3;
  v5 = a3[1];
  v15 = 0;
  v16 = 0;
  v9[0] = v4;
  v9[1] = v5;
  v6 = a3[3];
  v10 = (unsigned int)a3[2];
  v12 = 0;
  v11 = v6;
  v7 = a3[5];
  v13 = (unsigned int)a3[4];
  v14 = 0;
  v14 = __PAIR64__(a3[6], v7);
  LODWORD(result) = kgsl_ioctl_submit_commands(a1, a2, (__int64)v9);
  a3[6] = HIDWORD(v14);
  _ReadStatusReg(SP_EL0);
  return (int)result;
}

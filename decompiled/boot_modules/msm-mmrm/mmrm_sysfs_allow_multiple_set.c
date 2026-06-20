__int64 __fastcall mmrm_sysfs_allow_multiple_set(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  char v5; // w8
  __int64 v6; // x1
  char v7; // w8
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a3 )
  {
    v7 = 0;
    goto LABEL_8;
  }
  v5 = *(_BYTE *)(a3 + 1);
  v9 = 0;
  if ( ((v5 - 88) & 0xDF) != 0 )
    v6 = 10;
  else
    v6 = 16;
  if ( !(unsigned int)kstrtouint(a3, v6, &v9) )
  {
    v7 = v9;
LABEL_8:
    msm_mmrm_allow_multiple_register = v7;
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}

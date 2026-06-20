__int64 __fastcall kgsl_remove_from_minidump(const char *a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  _QWORD v9[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v10; // [xsp+20h] [xbp-20h]
  __int64 v11; // [xsp+28h] [xbp-18h]
  __int64 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  v12 = 0;
  v10 = 0;
  memset(v9, 0, sizeof(v9));
  result = msm_minidump_enabled();
  if ( (result & 1) != 0 )
  {
    scnprintf(v9, 13, a1);
    v10 = a2;
    v11 = a3;
    v12 = a4;
    result = msm_minidump_remove_region(v9);
    if ( (result & 0x80000000) != 0 && (_DWORD)result != -2 )
      result = printk(&unk_14238E);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

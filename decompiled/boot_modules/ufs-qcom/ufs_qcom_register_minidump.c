__int64 __fastcall ufs_qcom_register_minidump(__int64 a1, __int64 a2, const char *a3)
{
  __int64 result; // x0
  __int64 v7; // x8
  unsigned __int64 v8; // x12
  __int64 v9; // x9
  __int64 v10; // x8
  _QWORD v11[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v12; // [xsp+20h] [xbp-20h]
  __int64 v13; // [xsp+28h] [xbp-18h]
  __int64 v14; // [xsp+30h] [xbp-10h]
  __int64 v15; // [xsp+38h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  v14 = 0;
  v12 = 0;
  memset(v11, 0, sizeof(v11));
  result = msm_minidump_enabled(a1);
  if ( (result & 1) != 0 )
  {
    scnprintf(v11, 13, "%s_%lld", a3, 0);
    v7 = a1 << 8 >> 8;
    v14 = a2;
    v8 = (unsigned __int64)(v7 + 0x8000000000LL) >> 38;
    v9 = memstart_addr + v7 + 0x8000000000LL;
    v10 = v7 - kimage_voffset;
    if ( !v8 )
      v10 = v9;
    v12 = a1;
    v13 = v10;
    result = msm_minidump_add_region(v11);
    if ( (result & 0x80000000) != 0 )
      result = printk(&unk_18A50, a3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

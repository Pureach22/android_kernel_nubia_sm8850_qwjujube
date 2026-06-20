__int64 __fastcall register_minidump(__int64 a1, __int64 a2, const char *a3, int a4)
{
  __int64 result; // x0
  __int64 v9; // x8
  unsigned __int64 v10; // x12
  __int64 v11; // x9
  __int64 v12; // x8
  _QWORD v13[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v14; // [xsp+20h] [xbp-20h]
  __int64 v15; // [xsp+28h] [xbp-18h]
  __int64 v16; // [xsp+30h] [xbp-10h]
  __int64 v17; // [xsp+38h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15 = 0;
  v16 = 0;
  v14 = 0;
  memset(v13, 0, sizeof(v13));
  result = msm_minidump_enabled();
  if ( (result & 1) != 0 && minidump_buf_cnt <= 15 )
  {
    scnprintf(v13, 13, "%s_%d", a3, a4);
    v9 = a1 << 8 >> 8;
    v16 = a2;
    v10 = (unsigned __int64)(v9 + 0x8000000000LL) >> 38;
    v11 = memstart_addr + v9 + 0x8000000000LL;
    v12 = v9 - kimage_voffset;
    if ( !v10 )
      v12 = v11;
    v14 = a1;
    v15 = v12;
    result = msm_minidump_add_region(v13);
    if ( (result & 0x80000000) != 0 )
      result = printk(&unk_838F, a3);
    else
      ++minidump_buf_cnt;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

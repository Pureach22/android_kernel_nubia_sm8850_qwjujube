__int64 __fastcall clk_debug_register_minidump(__int64 *a1)
{
  __int64 result; // x0
  const char **v3; // x8
  const char *name; // x3
  __int64 v5; // x9
  unsigned __int64 v6; // x10
  __int64 v7; // x9
  unsigned __int64 v8; // x13
  __int64 v9; // x10
  _QWORD v10[3]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v11; // [xsp+20h] [xbp-20h]
  __int64 v12; // [xsp+28h] [xbp-18h]
  __int64 v13; // [xsp+30h] [xbp-10h]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  v11 = 0;
  memset(v10, 0, sizeof(v10));
  result = msm_minidump_enabled();
  if ( (result & 1) != 0 )
  {
    v3 = (const char **)a1[2];
    if ( v3 )
      name = *v3;
    else
      name = (const char *)clk_hw_get_name(a1);
    scnprintf(v10, 13, "%s", name);
    v5 = *a1 << 8 >> 8;
    v6 = v5 + 0x8000000000LL;
    v7 = v5 - kimage_voffset;
    v8 = v6 >> 38;
    v9 = v6 + memstart_addr;
    if ( !v8 )
      v7 = v9;
    v11 = *a1;
    v12 = v7;
    v13 = 264;
    result = msm_minidump_add_region(v10);
    if ( (result & 0x80000000) != 0 )
      result = printk(&unk_280F4);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

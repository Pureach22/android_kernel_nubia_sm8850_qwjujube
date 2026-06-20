__int64 __fastcall tpg_1_3_layer_init(int *a1)
{
  int v2; // w3
  __int64 dir; // x0
  __int64 v4; // x20
  __int64 result; // x0
  char s[8]; // [xsp+8h] [xbp-A8h] BYREF
  __int64 v7; // [xsp+10h] [xbp-A0h]
  __int64 v8; // [xsp+18h] [xbp-98h]
  __int64 v9; // [xsp+20h] [xbp-90h]
  __int64 v10; // [xsp+28h] [xbp-88h]
  __int64 v11; // [xsp+30h] [xbp-80h]
  __int64 v12; // [xsp+38h] [xbp-78h]
  __int64 v13; // [xsp+40h] [xbp-70h]
  __int64 v14; // [xsp+48h] [xbp-68h]
  __int64 v15; // [xsp+50h] [xbp-60h]
  __int64 v16; // [xsp+58h] [xbp-58h]
  __int64 v17; // [xsp+60h] [xbp-50h]
  __int64 v18; // [xsp+68h] [xbp-48h]
  __int64 v19; // [xsp+70h] [xbp-40h]
  __int64 v20; // [xsp+78h] [xbp-38h]
  __int64 v21; // [xsp+80h] [xbp-30h]
  __int64 v22; // [xsp+88h] [xbp-28h]
  __int64 v23; // [xsp+90h] [xbp-20h]
  __int64 v24; // [xsp+98h] [xbp-18h]
  __int64 v25; // [xsp+A0h] [xbp-10h]
  __int64 v26; // [xsp+A8h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a1;
  v24 = 0;
  v25 = 0;
  v22 = 0;
  v23 = 0;
  v20 = 0;
  v21 = 0;
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  v12 = 0;
  v13 = 0;
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = 0;
  *(_QWORD *)s = 0;
  v7 = 0;
  snprintf(s, 0xA0u, "tpg%d", v2);
  dir = debugfs_create_dir(s, 0);
  if ( dir )
  {
    v4 = dir;
    debugfs_create_file("tpg_xcfa_test", 420, dir, a1, &tpg_1_3_xcfa_test);
    debugfs_create_file("tpg_shdr_overlap_test", 420, v4, a1, &tpg_1_3_shdr_overlap_test);
    debugfs_create_file("tpg_shdr_offset_num_batch", 420, v4, a1, &tpg_1_3_shdr_offset_num_batch);
    debugfs_create_file("tpg_shdr_line_offset0", 420, v4, a1, &tpg_1_3_shdr_line_offset0);
    debugfs_create_file("tpg_shdr_line_offset1", 420, v4, a1, &tpg_1_3_shdr_line_offset1);
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      3,
      "tpg_1_3_layer_init",
      891,
      "Layer init called");
    result = 0;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x200000000LL,
      1,
      "tpg_1_3_layer_init",
      877,
      "Debug fs could not create directory");
    result = 4294967294LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

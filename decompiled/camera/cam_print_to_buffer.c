__int64 __fastcall cam_print_to_buffer(
        __int64 a1,
        unsigned __int64 a2,
        unsigned __int64 *a3,
        unsigned int a4,
        unsigned __int64 a5,
        const char *a6,
        __int64 a7,
        __int64 a8,
        char a9)
{
  unsigned __int64 v11; // x8
  unsigned __int64 v13; // x8
  const char *v14; // x3
  __int64 result; // x0
  unsigned __int64 v16; // x22
  const char *v17; // x4
  unsigned __int64 v18; // x1
  unsigned __int64 v20; // x22
  unsigned __int64 v21; // x1
  char *v22; // [xsp+18h] [xbp-68h] BYREF
  char **v23; // [xsp+20h] [xbp-60h]
  __int64 v24; // [xsp+28h] [xbp-58h]
  __int64 v25; // [xsp+30h] [xbp-50h]
  char *v26; // [xsp+38h] [xbp-48h]
  char **v27; // [xsp+40h] [xbp-40h]
  __int64 v28; // [xsp+48h] [xbp-38h]
  __int64 v29; // [xsp+50h] [xbp-30h]
  _QWORD v30[5]; // [xsp+58h] [xbp-28h] BYREF

  v30[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a3;
  v28 = 0;
  v29 = 0;
  v26 = nullptr;
  v27 = nullptr;
  if ( v11 >= a2 )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               0x20000,
               1,
               "cam_print_to_buffer",
               267,
               "Inadequate buffer size: %lu for length: %lu",
               a2,
               a3);
  }
  else
  {
    v26 = &a9;
    v27 = &v22;
    v22 = &a9;
    v23 = &v22;
    v29 = 4294967280LL;
    v13 = __clz(__rbit64(a5));
    v24 = v28;
    v25 = 4294967280LL;
    if ( a4 > 4 )
      v14 = "CAM_LOG";
    else
      v14 = cam_debug_tag_name[a4];
    v16 = *a3;
    if ( v13 > 0x26 )
      v17 = "CAMERA";
    else
      v17 = cam_debug_mod_name[v13];
    if ( a2 >= v16 )
      v18 = a2 - v16;
    else
      v18 = 0;
    v20 = v16 + (int)scnprintf(a1 + v16, v18, "\n%-8s: %s:\t", v14, v17);
    v30[0] = v22;
    v30[1] = v23;
    if ( a2 >= v20 )
      v21 = a2 - v20;
    else
      v21 = 0;
    v30[2] = v24;
    v30[3] = v25;
    result = vscnprintf(a1 + v20, v21, a6, v30);
    *a3 = v20 + (int)result;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

size_t __fastcall cam_ife_hw_mgr_perfcnt_bus_wr_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  size_t v3; // x19
  __int64 v5; // x0
  _BYTE *v6; // x22
  __int64 v7; // x0
  _BYTE *v8; // x21
  _BYTE *v9; // x0
  _BYTE *v10; // x20
  unsigned int v12; // w8
  __int64 *v13; // x9
  int v14; // [xsp+Ch] [xbp-54h] BYREF
  __int64 v15; // [xsp+10h] [xbp-50h] BYREF
  _QWORD v16[9]; // [xsp+18h] [xbp-48h] BYREF

  v16[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v16, 0, 64);
  v15 = 0;
  v14 = 0;
  if ( a3 > 0x3F )
    goto LABEL_2;
  v3 = a3;
  _check_object_size(v16, a3, 0);
  if ( inline_copy_from_user_4((__int64)v16, a2, v3) )
  {
    v3 = -14;
    goto LABEL_14;
  }
  *((_BYTE *)v16 + v3) = 0;
  if ( !qword_3A85B4 )
  {
    v3 = -9;
    goto LABEL_14;
  }
  v5 = strnchr(v16, v3, 95);
  if ( v5 )
  {
    v6 = (_BYTE *)v5;
    v7 = strnchr(v5 + 1, v3, 95);
    if ( v7 )
    {
      v8 = (_BYTE *)v7;
      v9 = (_BYTE *)strnchr(v7 + 1, v3, 95);
      if ( v9 )
      {
        v10 = v9;
        *v6 = 0;
        *v8 = 0;
        *v9 = 0;
        if ( !(unsigned int)kstrtouint(v6 + 1, 0, (char *)&v15 + 4)
          && !(unsigned int)kstrtouint(v8 + 1, 0, &v15)
          && !(unsigned int)kstrtouint(v10 + 1, 0, &v14) )
        {
          if ( LODWORD(v16[0]) == 6645353 )
          {
            v13 = &qword_3A8548;
            v12 = HIDWORD(v15) - 1;
            if ( HIDWORD(v15) - 1 >= (unsigned int)qword_3A85B4 )
              goto LABEL_12;
          }
          else
          {
            if ( LODWORD(v16[0]) != 6645363 || !HIDWORD(v15) || HIDWORD(v15) > HIDWORD(qword_3A85B4) )
              goto LABEL_12;
            v12 = HIDWORD(v15) - 1;
            v13 = &qword_3A8550;
          }
          *(_DWORD *)(*v13 + 4LL * v12) = v15;
          dword_3A852C = v14;
          goto LABEL_14;
        }
      }
    }
  }
LABEL_12:
  ((void (*)(__int64, __int64, __int64, const char *, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_hw_mgr_perfcnt_bus_wr_write",
    &print_fmt_cam_req_mgr_apply_request[67],
    "Failed to set perf counter debug setting - invalid input format [input: %s counter: %u counter_val: %u]",
    (unsigned int)v16);
LABEL_2:
  v3 = -22;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return v3;
}

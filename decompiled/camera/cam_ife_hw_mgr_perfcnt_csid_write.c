size_t __fastcall cam_ife_hw_mgr_perfcnt_csid_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  size_t v3; // x19
  __int64 v6; // x0
  _BYTE *v7; // x23
  __int64 v8; // x0
  _BYTE *v9; // x22
  __int64 v10; // x0
  _BYTE *v11; // x21
  _BYTE *v12; // x0
  _BYTE *v13; // x20
  __int64 v14; // [xsp+18h] [xbp-58h] BYREF
  __int64 v15; // [xsp+20h] [xbp-50h] BYREF
  _QWORD v16[9]; // [xsp+28h] [xbp-48h] BYREF

  v16[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v16, 0, 64);
  v14 = 0;
  v15 = 0;
  if ( a3 <= 0x3F )
  {
    v3 = a3;
    _check_object_size(v16, a3, 0);
    if ( inline_copy_from_user_4((__int64)v16, a2, v3) )
    {
      v3 = -14;
      goto LABEL_5;
    }
    *((_BYTE *)v16 + v3) = 0;
    if ( !dword_3A85BC )
    {
      v3 = -9;
      goto LABEL_5;
    }
    v6 = strnchr(v16, v3, 95);
    if ( v6 )
    {
      v7 = (_BYTE *)v6;
      v8 = strnchr(v6 + 1, v3, 95);
      if ( v8 )
      {
        v9 = (_BYTE *)v8;
        v10 = strnchr(v8 + 1, v3, 95);
        if ( v10 )
        {
          v11 = (_BYTE *)v10;
          v12 = (_BYTE *)strnchr(v10 + 1, v3, 95);
          if ( v12 )
          {
            v13 = v12;
            *v7 = 0;
            *v9 = 0;
            *v11 = 0;
            *v12 = 0;
            if ( !(unsigned int)kstrtouint(v7 + 1, 0, (char *)&v15 + 4)
              && !(unsigned int)kstrtouint(v9 + 1, 0, &v15)
              && !(unsigned int)kstrtouint(v11 + 1, 0, (char *)&v14 + 4)
              && !(unsigned int)kstrtouint(v13 + 1, 0, &v14)
              && !(LODWORD(v16[0]) ^ 0x64697363 | BYTE4(v16[0]))
              && HIDWORD(v15)
              && HIDWORD(v15) <= dword_3A85BC )
            {
              *(_DWORD *)(qword_3A8560 + 4LL * (unsigned int)(HIDWORD(v15) - 1)) = v15;
              *(_DWORD *)(qword_3A8568 + 4LL * (unsigned int)(HIDWORD(v15) - 1)) = HIDWORD(v14);
              byte_3A8581 = 1;
              dword_3A8558 = v14;
              goto LABEL_5;
            }
          }
        }
      }
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_hw_mgr_perfcnt_csid_write",
      18906,
      "Failed to set perf counter debug setting - invalid input format [input: %s counter: %u counter_val0: %u counter_val1: %u]",
      (const char *)v16,
      HIDWORD(v15),
      v15,
      HIDWORD(v14));
  }
  v3 = -22;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v3;
}

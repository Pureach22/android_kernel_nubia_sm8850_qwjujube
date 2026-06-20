size_t __fastcall cam_ife_hw_mgr_perfcnt_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  size_t v3; // x19
  __int64 v5; // x0
  _BYTE *v6; // x21
  _BYTE *v7; // x0
  _BYTE *v8; // x20
  int v9; // w0
  int v10; // w8
  unsigned int v12; // w9
  __int64 v13; // x10
  __int64 v14; // [xsp+10h] [xbp-20h] BYREF
  _QWORD v15[3]; // [xsp+18h] [xbp-18h] BYREF

  v15[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  v15[1] = 0;
  v14 = 0;
  if ( a3 > 0xF )
    goto LABEL_2;
  v3 = a3;
  _check_object_size(v15, a3, 0);
  if ( inline_copy_from_user_4((__int64)v15, a2, v3) )
  {
    v3 = -14;
    goto LABEL_12;
  }
  *((_BYTE *)v15 + v3) = 0;
  if ( !qword_3A85AC )
  {
    v3 = -9;
    goto LABEL_12;
  }
  v5 = strnchr(v15, v3, 95);
  if ( v5 && (v6 = (_BYTE *)v5, (v7 = (_BYTE *)strnchr(v5 + 1, v3, 95)) != nullptr) )
  {
    v8 = v7;
    *v6 = 0;
    *v7 = 0;
    v9 = kstrtouint(v6 + 1, 0, (char *)&v14 + 4);
    v10 = 0;
    if ( !v9 )
    {
      if ( !(unsigned int)kstrtouint(v8 + 1, 0, &v14) )
      {
        if ( LODWORD(v15[0]) == 6645353 )
        {
          v10 = v14;
          v12 = HIDWORD(v14) - 1;
          if ( HIDWORD(v14) - 1 >= (unsigned int)qword_3A85AC )
            goto LABEL_14;
          v13 = qword_3A8530;
        }
        else
        {
          v10 = v14;
          if ( LODWORD(v15[0]) != 6645363 || !HIDWORD(v14) || HIDWORD(v14) > HIDWORD(qword_3A85AC) )
            goto LABEL_14;
          v12 = HIDWORD(v14) - 1;
          v13 = qword_3A8538;
        }
        *(_DWORD *)(v13 + 4LL * v12) = v10;
        goto LABEL_12;
      }
      v10 = v14;
    }
  }
  else
  {
    v10 = 0;
  }
LABEL_14:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    3,
    "cam_ife_hw_mgr_perfcnt_write",
    19106,
    "Failed to set perf counter debug setting - invalid input format [input: %s counter: %u counter_val: %u]",
    (const char *)v15,
    HIDWORD(v14),
    v10);
LABEL_2:
  v3 = -22;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v3;
}

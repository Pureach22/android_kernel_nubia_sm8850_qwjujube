__int64 __fastcall cam_icp_mgr_get_hw_caps_v2(__int64 a1, _QWORD *a2)
{
  const char *v4; // x5
  __int64 v5; // x6
  __int64 v6; // x4
  unsigned int v7; // w20
  __int64 result; // x0
  int v9; // w8
  _DWORD *v10; // x9
  int v11; // w10
  int v12; // w21
  int v13; // w8
  int v14; // w10
  int v15; // w7
  int v16; // w10
  int v17; // w10
  __int64 v18; // x0
  unsigned int hw_caps_v2; // w0
  int v20; // w9
  _QWORD s[46]; // [xsp+10h] [xbp-170h] BYREF

  s[45] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x168u);
  if ( !a1 || !a2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_get_hw_caps_v2",
      9323,
      "Invalid params: %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
    goto LABEL_11;
  }
  if ( *(_DWORD *)a2 != 360 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_get_hw_caps_v2",
      9331,
      "[%s] Input query cap size:%u does not match expected query cap size: %ud",
      a1 + 112);
    result = 4294967282LL;
    goto LABEL_11;
  }
  mutex_lock(a1);
  if ( !inline_copy_from_user_6((int)s, a2[1], 0x168u) )
  {
    HIDWORD(s[41]) = 0;
    memset(&s[5], 0, 0x118u);
    if ( (*(_BYTE *)(a1 + 44180) & 3) == 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_get_hw_caps_v2",
        9358,
        "No ICP HW binded to %s",
        (const char *)(a1 + 112));
      v7 = -19;
      goto LABEL_8;
    }
    v9 = *(_DWORD *)(a1 + 64);
    s[5] = 0x100000006LL;
    if ( !v9 )
    {
      v12 = 0;
      v13 = 1;
LABEL_48:
      v18 = *(unsigned int *)(a1 + 156);
      HIDWORD(s[4]) = v13;
      hw_caps_v2 = hfi_get_hw_caps_v2(v18, s);
      if ( hw_caps_v2 )
      {
        v7 = hw_caps_v2;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_get_hw_caps_v2",
          9404,
          "[%s] Fail to get hfi caps rc:%d",
          a1 + 112);
        goto LABEL_8;
      }
      v20 = *(_DWORD *)(a1 + 152);
      HIDWORD(s[0]) = *(_DWORD *)(a1 + 148);
      LODWORD(s[1]) = v20;
      if ( v12 )
      {
        ++HIDWORD(s[41]);
        LODWORD(s[42]) |= 1u;
        HIDWORD(s[42]) = 2;
      }
      if ( !inline_copy_to_user_3(a2[1], s, 360) )
      {
        v7 = 0;
        goto LABEL_8;
      }
      v4 = "[%s] copy_to_user failed";
      v5 = a1 + 112;
      v6 = 9418;
      goto LABEL_6;
    }
    v10 = *(_DWORD **)(a1 + 56);
    v11 = v10[2];
    switch ( v11 )
    {
      case 2:
        v12 = 1;
        break;
      case 4:
        v12 = 0;
        v11 = 7;
        break;
      case 3:
        v12 = 0;
        break;
      default:
        v15 = 0;
        goto LABEL_29;
    }
    s[12] = __PAIR64__(v10[145], v11);
    if ( v9 == 1 )
    {
      v13 = 2;
      goto LABEL_48;
    }
    v14 = v10[148];
    v15 = 1;
    if ( v14 == 2 )
    {
      v12 = 1;
    }
    else if ( v14 != 3 )
    {
      if ( v14 != 4 )
        goto LABEL_29;
      v14 = 7;
    }
    LODWORD(s[19]) = v14;
    HIDWORD(s[19]) = v10[291];
    if ( v9 == 2 )
    {
      v13 = 3;
      goto LABEL_48;
    }
    v16 = v10[294];
    if ( v16 == 2 )
    {
      v12 = 1;
    }
    else if ( v16 != 3 )
    {
      if ( v16 != 4 )
      {
        v15 = 2;
        goto LABEL_29;
      }
      v16 = 7;
    }
    LODWORD(s[26]) = v16;
    HIDWORD(s[26]) = v10[437];
    if ( v9 == 3 )
    {
      v13 = 4;
      goto LABEL_48;
    }
    v17 = v10[440];
    if ( v17 == 2 )
    {
      v12 = 1;
    }
    else if ( v17 != 3 )
    {
      if ( v17 != 4 )
      {
        v15 = 3;
        goto LABEL_29;
      }
      v17 = 7;
    }
    LODWORD(s[33]) = v17;
    HIDWORD(s[33]) = v10[583];
    if ( v9 == 4 )
    {
      v13 = 5;
      goto LABEL_48;
    }
    if ( (unsigned int)(v10[586] - 2) < 3 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_get_hw_caps_v2",
        9388,
        "[%s] number of supported hw devices:%u exceeds maximum number of devices supported by query cap struct: %u",
        (const char *)(a1 + 112),
        5,
        5);
      goto LABEL_7;
    }
    v15 = 4;
LABEL_29:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_get_hw_caps_v2",
      9379,
      "[%s] Invalid icp hw type: %u",
      (const char *)(a1 + 112),
      v15);
    v7 = -57;
    goto LABEL_8;
  }
  v4 = "[%s] copy from user failed";
  v5 = a1 + 112;
  v6 = 9338;
LABEL_6:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
    3,
    256,
    1,
    "cam_icp_mgr_get_hw_caps_v2",
    v6,
    v4,
    v5);
LABEL_7:
  v7 = -14;
LABEL_8:
  mutex_unlock(a1);
  result = v7;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}

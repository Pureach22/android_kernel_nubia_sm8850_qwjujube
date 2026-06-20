__int64 __fastcall cam_icp_mgr_get_hw_caps(__int64 a1, _QWORD *a2)
{
  const char *v4; // x5
  __int64 v5; // x6
  __int64 v6; // x4
  unsigned int v7; // w20
  __int64 result; // x0
  unsigned int hw_caps; // w0
  int v10; // w9
  __int64 v11; // x0
  _QWORD v12[23]; // [xsp+8h] [xbp-B8h] BYREF

  v12[22] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v12, 0, 176);
  if ( a1 && a2 )
  {
    if ( *(_DWORD *)a2 == 176 )
    {
      mutex_lock(a1);
      if ( inline_copy_from_user_6((int)v12, a2[1], 0xB0u) )
      {
        v4 = "[%s] copy from_user failed";
        v5 = a1 + 112;
        v6 = 9286;
      }
      else
      {
        hw_caps = hfi_get_hw_caps(v12);
        if ( hw_caps )
        {
          v7 = hw_caps;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_get_hw_caps",
            9293,
            "[%s] Fail to get hfi caps",
            (const char *)(a1 + 112));
          goto LABEL_11;
        }
        v10 = *(_DWORD *)(a1 + 152);
        v11 = a2[1];
        LODWORD(v12[0]) = *(_DWORD *)(a1 + 148);
        HIDWORD(v12[0]) = v10;
        if ( !inline_copy_to_user_3(v11, v12, 176) )
        {
          v7 = 0;
          goto LABEL_11;
        }
        v4 = "[%s] copy_to_user failed";
        v5 = a1 + 112;
        v6 = 9302;
      }
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_mgr_get_hw_caps",
        v6,
        v4,
        v5);
      v7 = -14;
LABEL_11:
      mutex_unlock(a1);
      result = v7;
      goto LABEL_12;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_get_hw_caps",
      9278,
      "[%s] Input query cap size:%u does not match expected query cap size: %u",
      (const char *)(a1 + 112),
      *(_DWORD *)a2,
      176);
    result = 4294967282LL;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_get_hw_caps",
      9270,
      "Invalid params: %pK %pK",
      (const void *)a1,
      a2);
    result = 4294967274LL;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}

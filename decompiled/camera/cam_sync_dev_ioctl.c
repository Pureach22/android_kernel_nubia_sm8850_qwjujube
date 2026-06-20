__int64 __fastcall cam_sync_dev_ioctl(__int64 a1, __int64 a2, __int64 a3, int a4, _QWORD *a5)
{
  __int64 v7; // x8
  __int64 v8; // x19
  __int64 result; // x0
  __int64 v10; // x9
  bool v11; // cc
  const char *v12; // x5
  __int64 v13; // x4
  __int64 v14; // [xsp+8h] [xbp-58h] BYREF
  __int64 v15; // [xsp+10h] [xbp-50h]
  int v16[2]; // [xsp+18h] [xbp-48h]
  __int64 v17; // [xsp+20h] [xbp-40h] BYREF
  __int64 v18; // [xsp+28h] [xbp-38h]
  __int64 v19; // [xsp+30h] [xbp-30h]
  __int64 v20; // [xsp+38h] [xbp-28h]
  __int64 v21; // [xsp+40h] [xbp-20h]
  __int64 v22; // [xsp+48h] [xbp-18h]
  __int64 v23; // [xsp+50h] [xbp-10h]
  __int64 v24; // [xsp+58h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(video_devdata() + 336) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      128,
      1,
      "cam_sync_dev_ioctl",
      2334,
      "sync_dev NULL");
    goto LABEL_12;
  }
  if ( !a5 )
  {
LABEL_12:
    result = -22;
    goto LABEL_33;
  }
  if ( a4 == -1072146752 )
  {
    v8 = *a5;
    v7 = a5[1];
    LODWORD(result) = -515;
    v10 = a5[2];
    v11 = (int)*a5 <= 4;
    v14 = *a5;
    v15 = v7;
    *(_QWORD *)v16 = v10;
    if ( v11 )
    {
      if ( (int)v8 <= 1 )
      {
        if ( (_DWORD)v8 )
        {
          if ( (_DWORD)v8 == 1 )
            LODWORD(result) = cam_sync_handle_destroy(&v14);
        }
        else
        {
          LODWORD(result) = cam_sync_handle_create(&v14);
        }
      }
      else
      {
        switch ( (_DWORD)v8 )
        {
          case 2:
            LODWORD(result) = cam_sync_handle_signal(&v14);
            break;
          case 3:
            LODWORD(result) = cam_sync_handle_merge(&v14);
            break;
          case 4:
            LODWORD(result) = cam_sync_handle_register_user_payload(&v14);
            break;
        }
      }
      goto LABEL_32;
    }
    if ( (unsigned int)(v8 - 11) >= 4 )
    {
      if ( (_DWORD)v8 == 5 )
      {
        LODWORD(result) = cam_sync_handle_deregister_user_payload(&v14);
      }
      else if ( (_DWORD)v8 == 6 )
      {
        LODWORD(result) = cam_sync_handle_wait(&v14);
        *((_DWORD *)a5 + 2) = v15;
      }
      goto LABEL_32;
    }
    v22 = 0;
    v23 = 0;
    v20 = 0;
    v21 = 0;
    v18 = 0;
    v19 = 0;
    v17 = 0;
    if ( *(_QWORD *)v16 )
    {
      if ( HIDWORD(v14) == 56 )
      {
        if ( inline_copy_from_user_2((int)&v17, v16[0], 0x38u) )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            128,
            1,
            "cam_generic_fence_parser",
            2294,
            "copy from user failed for input ptr: %pK",
            *(const void **)v16);
          LODWORD(result) = -14;
LABEL_32:
          result = (int)result;
          goto LABEL_33;
        }
        if ( (_DWORD)v18 == 1 )
        {
          switch ( HIDWORD(v17) )
          {
            case 3:
              LODWORD(result) = cam_generic_fence_process_synx_obj_cmd((unsigned int)v8, &v17);
              goto LABEL_32;
            case 2:
              LODWORD(result) = cam_generic_fence_process_dma_fence_cmd((unsigned int)v8, &v17);
              goto LABEL_32;
            case 1:
              LODWORD(result) = cam_generic_fence_process_sync_obj_cmd((unsigned int)v8, &v17);
              goto LABEL_32;
          }
          v12 = "fence type: 0x%x handling not supported";
          v13 = 2319;
        }
        else
        {
          v12 = "Invalid handle type: %u";
          v13 = 2300;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          128,
          1,
          "cam_generic_fence_parser",
          v13,
          v12);
      }
      else
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          128,
          1,
          "cam_generic_fence_parser",
          2287,
          "Size mismatch expected: 0x%llx actual: 0x%llx",
          56);
      }
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        128,
        1,
        "cam_generic_fence_parser",
        2281,
        "Invalid args input ptr: %p",
        nullptr);
    }
    LODWORD(result) = -22;
    goto LABEL_32;
  }
  result = -515;
LABEL_33:
  _ReadStatusReg(SP_EL0);
  return result;
}

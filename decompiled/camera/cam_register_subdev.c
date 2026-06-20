__int64 __fastcall cam_register_subdev(__int64 a1)
{
  const char *v2; // x3
  __int64 v3; // x8
  int v4; // w9
  __int64 v5; // x2
  __int64 *v6; // x0
  unsigned int v7; // w0
  unsigned int v8; // w19
  __int64 result; // x0
  unsigned int v10; // w0
  __int64 v11; // x6
  __int64 v12; // x8
  const char *v13; // x6

  if ( (byte_2FDA98 & 1) != 0 )
  {
    if ( a1 && *(_QWORD *)(a1 + 408) )
    {
      mutex_lock(&unk_2FDA68);
      v4l2_subdev_init(a1 + 8, *(_QWORD *)(a1 + 392));
      v2 = *(const char **)(a1 + 408);
      *(_QWORD *)(a1 + 176) = *(_QWORD *)(a1 + 400);
      snprintf((char *)(a1 + 192), 0x20u, "%s", v2);
      v3 = *(_QWORD *)(a1 + 424);
      v4 = *(_DWORD *)(a1 + 416);
      v5 = cam_req_mgr_ordered_sd_list;
      v6 = (__int64 *)(a1 + 448);
      *(_WORD *)(a1 + 64) = 0;
      *(_QWORD *)(a1 + 248) = v3;
      LODWORD(v3) = *(_DWORD *)(a1 + 432);
      *(_DWORD *)(a1 + 156) = v4;
      *(_QWORD *)(a1 + 80) = 0;
      *(_DWORD *)(a1 + 52) = v3;
      if ( v5 == a1 + 448 || v6 == &cam_req_mgr_ordered_sd_list || *(__int64 **)(v5 + 8) != &cam_req_mgr_ordered_sd_list )
      {
        _list_add_valid_or_report(v6);
      }
      else
      {
        *(_QWORD *)(v5 + 8) = v6;
        *(_QWORD *)(a1 + 448) = v5;
        *(_QWORD *)(a1 + 456) = &cam_req_mgr_ordered_sd_list;
        cam_req_mgr_ordered_sd_list = a1 + 448;
      }
      list_sort(0, &cam_req_mgr_ordered_sd_list, cam_req_mgr_ordered_list_cmp);
      v7 = _v4l2_device_register_subdev(qword_2FDA58, a1 + 8, &_this_module);
      if ( v7 )
      {
        v8 = v7;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          16,
          1,
          "cam_register_subdev",
          990,
          "register subdev failed");
      }
      else
      {
        v10 = _v4l2_device_register_subdev_nodes(qword_2FDA58, 0);
        if ( v10 )
        {
          v11 = a1 + 192;
          v8 = v10;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            16,
            1,
            "cam_register_subdev",
            997,
            "Failed to register subdev node: %s, rc: %d",
            v11);
        }
        else
        {
          if ( (*(_BYTE *)(a1 + 156) & 4) != 0 )
          {
            v12 = *(_QWORD *)(a1 + 264);
            v13 = *(const char **)(v12 + 296);
            if ( !v13 )
              v13 = *(const char **)(v12 + 184);
            *(_QWORD *)(a1 + 40) = v13;
            if ( (debug_mdl & 0x10) != 0 && !debug_priority )
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                debug_mdl & 0x10,
                4,
                "cam_register_subdev",
                1003,
                "created node :%s",
                v13);
          }
          v8 = 0;
          ++dword_2FDA60;
        }
      }
      mutex_unlock(&unk_2FDA68);
      return v8;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        16,
        1,
        "cam_register_subdev",
        967,
        "invalid arguments");
      return 4294967274LL;
    }
  }
  else
  {
    result = 4294966779LL;
    if ( (debug_mdl & 0x10) != 0 && !debug_priority )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x10,
        4,
        "cam_register_subdev",
        962,
        "camera root device not ready yet");
      return 4294966779LL;
    }
  }
  return result;
}

__int64 __fastcall cam_icp_mgr_config_stream_settings(__int64 a1, __int64 *a2)
{
  __int64 v2; // x20
  __int64 v5; // x8
  int v6; // w9
  int *v7; // x19
  int v8; // w0
  int v9; // w19
  __int64 result; // x0
  unsigned int v11; // w19
  __int64 v12; // [xsp+0h] [xbp-20h] BYREF
  __int64 v13; // [xsp+8h] [xbp-18h]
  __int64 v14; // [xsp+10h] [xbp-10h]
  __int64 v15; // [xsp+18h] [xbp-8h]

  v15 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 0;
  if ( a1 && a2 && *a2 )
  {
    v2 = a2[1];
    mutex_lock(*(_QWORD *)(a1 + 88) + 48LL * *(unsigned int *)(v2 + 29224));
    v5 = *a2;
    v12 = v2;
    LODWORD(v13) = -1;
    v6 = *(_DWORD *)(v5 + 24);
    v14 = 0;
    v7 = (int *)(v5 + (v6 & 0xFFFFFFFC));
    v8 = cam_packet_util_validate_cmd_desc(v7 + 14);
    if ( !v8 )
    {
      if ( v7[17] && v7[19] == 1 )
      {
        v8 = cam_packet_util_process_generic_cmd_buffer(v7 + 14, cam_icp_packet_generic_blob_handler, (__int64)&v12);
        if ( v8 )
        {
          v9 = v8;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            256,
            1,
            "cam_icp_mgr_config_stream_settings",
            7360,
            "%s: Failed in processing cmd mem blob %d",
            (const char *)(v2 + 29824),
            v8);
          v8 = v9;
        }
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          256,
          1,
          "cam_icp_mgr_config_stream_settings",
          7351,
          "%s: Invalid cmd buffer length/metadata",
          (const char *)(v2 + 29824));
        v8 = -22;
      }
    }
    v11 = v8;
    mutex_unlock(*(_QWORD *)(a1 + 88) + 48LL * *(unsigned int *)(v2 + 29224));
    result = v11;
  }
  else
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_mgr_config_stream_settings",
      7329,
      "Invalid input arguments");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

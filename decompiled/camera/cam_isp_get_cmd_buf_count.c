__int64 __fastcall cam_isp_get_cmd_buf_count(__int64 a1, _DWORD *a2)
{
  unsigned int v4; // w22
  __int64 v5; // x24
  _DWORD *v6; // x9
  int *v7; // x21
  __int64 result; // x0
  unsigned int v9; // w8
  int v10; // w8

  if ( *(_DWORD *)(*(_QWORD *)a1 + 28LL) )
  {
    v4 = 0;
    v5 = *(_QWORD *)a1 + *(unsigned int *)(*(_QWORD *)a1 + 24LL) + 56LL;
    do
    {
      v7 = (int *)(v5 + 24LL * (int)v4);
      result = cam_packet_util_validate_cmd_desc(v7);
      if ( (_DWORD)result )
        return result;
      if ( v7[3] )
      {
        result = cam_packet_util_validate_cmd_desc((int *)(v5 + 24LL * (int)v4));
        if ( (_DWORD)result )
          return result;
        v9 = v7[5];
        if ( v9 <= 0x17 )
        {
          v10 = 1 << v9;
          v6 = a2 + 1;
          if ( (v10 & 0x7F) == 0 )
          {
            v6 = a2;
            if ( (v10 & 0x70000) == 0 )
            {
              if ( (v10 & 0xE00000) == 0 )
                goto LABEL_5;
              v6 = a2 + 2;
            }
          }
          ++*v6;
        }
      }
LABEL_5:
      ++v4;
    }
    while ( v4 < *(_DWORD *)(*(_QWORD *)a1 + 28LL) );
  }
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_isp_get_cmd_buf_count",
      2078,
      "Number of cmd buffers: isp:%u csid:%u sfe:%u",
      a2[1],
      *a2,
      a2[2]);
    return 0;
  }
  return result;
}

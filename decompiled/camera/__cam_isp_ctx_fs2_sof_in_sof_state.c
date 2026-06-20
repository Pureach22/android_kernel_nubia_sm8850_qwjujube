__int64 __fastcall _cam_isp_ctx_fs2_sof_in_sof_state(__int64 *a1, __int64 *a2)
{
  __int64 v2; // x19
  __int64 *v3; // x20
  __int64 v4; // x7
  __int64 v5; // x21
  _QWORD *v6; // x8
  _QWORD *v7; // x9
  unsigned __int64 v8; // x19
  __int64 *v10; // x21

  v2 = *a1;
  if ( a2 )
  {
    v3 = a1 + 4608;
    v4 = a1[4663];
    if ( v4 != *a2 )
    {
      ++a1[1];
      v4 = *a2;
      a1[4663] = *a2;
      a1[4664] = a2[1];
    }
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v10 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "__cam_isp_ctx_fs2_sof_in_sof_state",
        5061,
        "frame id: %lld time stamp:0x%llx, ctx: %u, link: 0x%x",
        a1[1],
        v4,
        *(_DWORD *)(v2 + 32),
        *(_DWORD *)(v2 + 64));
      a1 = v10;
    }
    if ( *(_QWORD *)(v2 + 160) == v2 + 160 )
    {
      if ( *((int *)v3 + 114) > 2 )
      {
        v8 = 0;
      }
      else
      {
        v5 = (__int64)a1;
        _cam_isp_ctx_notify_trigger_util(1, a1);
        v6 = (_QWORD *)(v2 + 128);
        v7 = (_QWORD *)(v2 + 128);
        while ( 1 )
        {
          v7 = (_QWORD *)*v7;
          if ( v7 == v6 )
            break;
          v8 = v7[3];
          if ( v8 > v3[58] )
          {
            v3[58] = v8;
            goto LABEL_16;
          }
        }
        v8 = 0;
LABEL_16:
        _cam_isp_ctx_send_sof_timestamp(v5, v8, 0);
        a1 = (__int64 *)v5;
      }
      _cam_isp_ctx_update_state_monitor_array((__int64)a1, 3, v8);
    }
    return 0;
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_fs2_sof_in_sof_state",
      5054,
      "in valid sof event data, ctx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    return 4294967274LL;
  }
}

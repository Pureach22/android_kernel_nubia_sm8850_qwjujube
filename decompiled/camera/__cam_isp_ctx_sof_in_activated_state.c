__int64 __fastcall _cam_isp_ctx_sof_in_activated_state(__int64 *a1, _QWORD *a2)
{
  __int64 v2; // x20
  _QWORD *v3; // x21
  __int64 v4; // x8
  _QWORD *v5; // x9
  unsigned __int64 v6; // x19
  __int64 v7; // x8
  __int64 result; // x0

  v2 = *a1;
  v3 = a1 + 4663;
  v4 = *a1 + 128;
  a1[5707] = jiffies;
  v5 = (_QWORD *)v4;
  while ( 1 )
  {
    v5 = (_QWORD *)*v5;
    if ( v5 == (_QWORD *)v4 )
      break;
    v6 = v5[3];
    if ( v6 > a1[4666] )
      goto LABEL_7;
  }
  v7 = *(_QWORD *)(v2 + 160);
  if ( !v7 )
  {
    v6 = 0;
    if ( a2 )
      goto LABEL_8;
LABEL_14:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "__cam_isp_ctx_sof_in_activated_state",
      3911,
      "in valid sof event data, ctx_idx: %u, link: 0x%x",
      *(_DWORD *)(v2 + 32),
      *(_DWORD *)(v2 + 64));
    return 4294967274LL;
  }
  v6 = *(_QWORD *)(v7 + 24);
LABEL_7:
  if ( !a2 )
    goto LABEL_14;
LABEL_8:
  if ( *v3 != *a2 )
  {
    ++a1[1];
    *v3 = *a2;
    a1[4664] = a2[1];
  }
  _cam_isp_ctx_update_state_monitor_array((__int64)a1, 3, v6);
  result = 0;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "__cam_isp_ctx_sof_in_activated_state",
      3923,
      "frame id:%lld timestamp sof:0x%llx boot:0x%llx, ctx:%u, request:%llu, link:0x%x",
      a1[1],
      *v3,
      v3[1],
      *(_DWORD *)(v2 + 32),
      v6,
      *(_DWORD *)(v2 + 64));
    return 0;
  }
  return result;
}

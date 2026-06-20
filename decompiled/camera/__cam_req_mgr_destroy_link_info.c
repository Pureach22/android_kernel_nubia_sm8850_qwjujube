__int64 __fastcall _cam_req_mgr_destroy_link_info(__int64 a1)
{
  _QWORD *v2; // x0
  _QWORD *v3; // x21
  int *v4; // x20
  __int64 result; // x0
  _QWORD *v6; // x20

  v2 = *(_QWORD **)(a1 + 56);
  if ( (debug_mdl & 0x10) != 0 && !debug_priority )
  {
    v6 = v2;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x10,
      4,
      "__cam_req_mgr_destroy_all_tbl",
      2624,
      "*l_tbl %pK",
      v2);
    v2 = v6;
    if ( v6 )
    {
      do
      {
LABEL_6:
        while ( 1 )
        {
          v3 = (_QWORD *)v2[3];
          if ( mem_trace_en != 1 )
            break;
          cam_mem_trace_free(v2, 0);
          v2 = v3;
          if ( !v3 )
            goto LABEL_8;
        }
        kvfree(v2);
        v2 = v3;
      }
      while ( v3 );
    }
  }
  else if ( v2 )
  {
    goto LABEL_6;
  }
LABEL_8:
  v4 = *(int **)(a1 + 48);
  *(_QWORD *)(a1 + 56) = 0;
  if ( v4 )
  {
    mutex_lock(a1 + 33056);
    memset(v4 + 2, 0, 72LL * *v4);
    *v4 = 0;
    *((_QWORD *)v4 + 433) = 0;
    result = mutex_unlock(a1 + 33056);
  }
  else
  {
    result = ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
               3,
               16,
               1,
               "__cam_req_mgr_reset_in_q",
               2683,
               "NULL in_q");
  }
  *(_DWORD *)(a1 + 64) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 4) = 0;
  *(_DWORD *)(a1 + 12) = 2;
  return result;
}

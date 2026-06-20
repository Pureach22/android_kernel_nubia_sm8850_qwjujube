__int64 __fastcall cam_jpeg_mgr_move_req_to_free_list(__int64 a1)
{
  __int64 result; // x0
  __int64 *v3; // x1

  if ( !a1 )
    return ((__int64 (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
             3,
             512,
             1,
             "cam_jpeg_mgr_move_req_to_free_list",
             61,
             "Invalid args");
  result = cam_mem_put_cpu_buf(**(_DWORD **)(a1 + 32));
  v3 = (__int64 *)qword_3AA150;
  if ( (__int64 *)a1 == &qword_3AA148 || qword_3AA150 == a1 || *(__int64 **)qword_3AA150 != &qword_3AA148 )
    return _list_add_valid_or_report(a1);
  qword_3AA150 = a1;
  *(_QWORD *)a1 = &qword_3AA148;
  *(_QWORD *)(a1 + 8) = v3;
  *v3 = a1;
  return result;
}

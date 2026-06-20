__int64 __fastcall _cam_isp_ctx_move_req_to_free_list(__int64 result, __int64 *a2)
{
  __int64 v2; // x21
  __int64 v4; // x20
  __int64 v5; // x2
  __int64 *v6; // x1

  v2 = a2[4];
  v4 = result;
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               3,
               debug_mdl & 8,
               4,
               "__cam_isp_ctx_move_req_to_free_list",
               1404,
               "Free req id: %lld, packet: 0x%x, ctx_idx: %u, link: 0x%x",
               a2[3],
               a2[17],
               *(_DWORD *)(result + 32),
               *(_DWORD *)(result + 64));
    if ( !a2[17] )
      goto LABEL_5;
    goto LABEL_4;
  }
  if ( a2[17] )
  {
LABEL_4:
    cam_mem_put_kref(*(_DWORD *)(v2 + 4328));
    result = cam_common_mem_free(a2[17]);
    a2[17] = 0;
  }
LABEL_5:
  v5 = v4 + 176;
  v6 = *(__int64 **)(v4 + 184);
  if ( (__int64 *)(v4 + 176) == a2 || v6 == a2 || *v6 != v5 )
    return _list_add_valid_or_report(a2);
  *(_QWORD *)(v4 + 184) = a2;
  *a2 = v5;
  a2[1] = (__int64)v6;
  *v6 = (__int64)a2;
  return result;
}

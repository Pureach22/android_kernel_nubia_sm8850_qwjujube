__int64 __fastcall _cam_req_mgr_free_link(__int64 a1)
{
  __int64 v2; // x0
  char v3; // w8
  __int64 result; // x0

  v2 = *(_QWORD *)(a1 + 48);
  if ( mem_trace_en == 1 )
    cam_mem_trace_free(v2, 0);
  else
    kvfree(v2);
  v3 = debug_mdl;
  *(_QWORD *)(a1 + 33160) = 0;
  if ( (v3 & 0x10) != 0 && !debug_priority )
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v3 & 0x10,
      4,
      "__cam_req_mgr_free_link",
      3012,
      "free link index %d",
      662505135 * ((a1 - (__int64)&g_links) >> 3));
  result = cam_req_mgr_core_link_reset(a1);
  if ( 0xA97B2FC4277D06AFLL * ((a1 - (__int64)&g_links) >> 3) >= 8 )
  {
    __break(0x5512u);
    return cam_req_mgr_link(result);
  }
  else
  {
    *((_DWORD *)&g_links + 2 * ((a1 - (__int64)&g_links) >> 3) + 8318) = 0;
  }
  return result;
}

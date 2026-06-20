__int64 __fastcall cm_connect_handle_event_post_fail(__int64 a1, unsigned int a2)
{
  __int64 result; // x0
  __int64 v5; // x21
  char v6; // w8

  result = _qdf_mem_malloc(0xA0u, "cm_connect_handle_event_post_fail", 304);
  if ( result )
  {
    *(_DWORD *)(result + 4) = a2;
    *(_DWORD *)(result + 52) = 16;
    v5 = result;
    v6 = *(_BYTE *)(*(_QWORD *)a1 + 104LL);
    *(_DWORD *)(result + 56) = 2;
    *(_BYTE *)result = v6;
    cm_fill_bss_info_in_connect_rsp_by_cm_id(a1, a2, result);
    cm_connect_complete(a1, v5);
    return _qdf_mem_free(v5);
  }
  return result;
}

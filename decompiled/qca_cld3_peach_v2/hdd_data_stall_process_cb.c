_DWORD *__fastcall hdd_data_stall_process_cb(_DWORD *a1)
{
  _DWORD *result; // x0
  __int64 v3; // x19
  __int64 v4; // [xsp+8h] [xbp-38h] BYREF
  __int64 v5; // [xsp+10h] [xbp-30h]
  void *v6; // [xsp+18h] [xbp-28h]
  __int64 v7; // [xsp+20h] [xbp-20h]
  __int64 v8; // [xsp+28h] [xbp-18h]
  __int64 v9; // [xsp+30h] [xbp-10h]
  __int64 v10; // [xsp+38h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  v9 = 0;
  v6 = nullptr;
  v7 = 0;
  v4 = 0;
  v5 = 0;
  result = (_DWORD *)_qdf_mem_malloc(0x14u, "hdd_data_stall_process_cb", 104);
  if ( result )
  {
    v3 = (__int64)result;
    result[1] = a1[1];
    *result = *a1;
    result[3] = a1[3];
    result[4] = a1[4];
    result[2] = a1[2];
    sys_build_message_header(3, &v4);
    v5 = v3;
    v6 = &hdd_data_stall_process_event;
    HIDWORD(v4) = 0;
    result = (_DWORD *)scheduler_post_message_debug(
                         0x33u,
                         0x33u,
                         55,
                         (unsigned __int16 *)&v4,
                         0x7Au,
                         (__int64)"hdd_data_stall_process_cb");
    if ( (_DWORD)result )
      result = (_DWORD *)_qdf_mem_free(v3);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

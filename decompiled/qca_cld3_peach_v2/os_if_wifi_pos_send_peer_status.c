void *__fastcall os_if_wifi_pos_send_peer_status(
        const void *a1,
        char a2,
        unsigned __int8 a3,
        char a4,
        _DWORD *a5,
        int a6)
{
  __int64 psoc; // x0
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x19
  void *result; // x0
  __int64 v23; // x21
  unsigned int app_pid; // w0
  const char *v25; // x2
  unsigned int v26; // w1

  psoc = wifi_pos_get_psoc(a1);
  if ( !psoc )
  {
    v25 = "%s: global wifi_pos psoc object not registered";
    v26 = 2;
    return (void *)qdf_trace_msg(
                     0x48u,
                     v26,
                     v25,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     "os_if_wifi_pos_send_peer_status");
  }
  v21 = psoc;
  if ( (wifi_pos_is_app_registered() & 1) == 0 || !(unsigned int)wifi_pos_get_app_pid(v21) )
  {
    v25 = "%s: app is not registered or pid is invalid";
    v26 = 8;
    return (void *)qdf_trace_msg(
                     0x48u,
                     v26,
                     v25,
                     v13,
                     v14,
                     v15,
                     v16,
                     v17,
                     v18,
                     v19,
                     v20,
                     "os_if_wifi_pos_send_peer_status");
  }
  result = (void *)_qdf_mem_malloc(0x30u, "os_if_wifi_pos_send_peer_status", 1035);
  if ( result )
  {
    v23 = (__int64)result;
    qdf_mem_copy(result, a1, 6u);
    *(_BYTE *)(v23 + 6) = a2;
    *(_BYTE *)(v23 + 7) = a4;
    *(_DWORD *)(v23 + 8) = a3;
    *(_DWORD *)(v23 + 12) = a6 == 0;
    if ( a5 )
    {
      *(_DWORD *)(v23 + 16) = *(unsigned __int8 *)a5;
      *(_DWORD *)(v23 + 20) = 0;
      *(_DWORD *)(v23 + 24) = a5[1];
      *(_DWORD *)(v23 + 28) = a5[2];
      *(_DWORD *)(v23 + 32) = a5[3];
      *(_DWORD *)(v23 + 36) = a5[4];
      *(_DWORD *)(v23 + 40) = a5[5];
      *(_DWORD *)(v23 + 44) = a5[6];
    }
    app_pid = wifi_pos_get_app_pid(v21);
    os_if_wifi_pos_send_rsp(v21, app_pid, 7, 48, v23);
    return (void *)_qdf_mem_free(v23);
  }
  return result;
}

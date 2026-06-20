__int64 __fastcall adsp_attach(__int64 a1)
{
  _QWORD *v1; // x22
  __int64 v3; // x20
  __int64 v4; // x19
  _QWORD *i; // x8
  int v6; // w0
  __int64 v7; // x19
  __int64 v8; // x20
  _QWORD *j; // x8
  unsigned int v11; // w19
  const char *v12; // x1

  v1 = *(_QWORD **)(a1 + 40);
  if ( *((_BYTE *)v1 + 344) != 1 )
    return 0;
  init_timer_key(v1 + 73, read_early_boot_register, 0, 0, 0);
  *((_DWORD *)v1 + 58) = 0;
  _init_swait_queue_head(v1 + 30, "&x->wait", &init_completion___key);
  read_early_boot_register((__int64)(v1 + 73));
  wait_for_completion(v1 + 29);
  timer_delete(v1 + 73);
  if ( (unsigned int)ping_subsystem(v1 + 3) )
  {
    dev_err(*v1, "Timed out on ping/pong, assuming device crashed\n");
    v12 = *(const char **)(a1 + 24);
    *(_DWORD *)(a1 + 972) = 3;
    panic("Panicking, timed out on ping/pong for %s\n", v12);
  }
  v3 = v1[63];
  *((_BYTE *)v1 + 308) = 1;
  if ( v3 )
  {
    v4 = v1[2];
    rproc_coredump_cleanup(v4);
    if ( (qcom_register_dump_segments(v4, v3) & 0x80000000) != 0 )
    {
      rproc_coredump_cleanup(v1[2]);
    }
    else
    {
      for ( i = *(_QWORD **)(v4 + 1256); i != (_QWORD *)(v4 + 1256); i = (_QWORD *)*i )
        i[2] = i[2] + v1[79] - v1[81];
    }
    return 0;
  }
  v6 = request_firmware(v1 + 63, *(_QWORD *)(a1 + 32), *v1);
  if ( v6 )
  {
    v11 = v6;
    dev_err(*v1, "request_firmware failed during attach: %d\n", v6);
    if ( v11 == -2 )
      return 0;
    else
      return v11;
  }
  else
  {
    v7 = v1[2];
    v8 = v1[63];
    rproc_coredump_cleanup(v7);
    if ( (qcom_register_dump_segments(v7, v8) & 0x80000000) != 0 )
    {
      rproc_coredump_cleanup(v1[2]);
    }
    else
    {
      for ( j = *(_QWORD **)(v7 + 1256); j != (_QWORD *)(v7 + 1256); j = (_QWORD *)*j )
        j[2] = j[2] + v1[79] - v1[81];
    }
    release_firmware(v1[63]);
    v1[63] = 0;
    return 0;
  }
}

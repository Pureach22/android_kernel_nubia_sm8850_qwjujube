__int64 __fastcall mhi_unprepare_from_transfer(_QWORD *a1)
{
  _QWORD *v1; // x19
  void (__fastcall *v3)(_QWORD); // x9
  __int64 v4; // x8
  void (__fastcall **v5)(_QWORD); // x21
  __int64 v6; // x1
  __int64 v7; // x1
  __int64 (__fastcall *v8)(_QWORD); // x8
  __int64 v9; // x9
  _QWORD *v10; // x0

  v1 = (_QWORD *)a1[2];
  v3 = (void (__fastcall *)(_QWORD))v1[65];
  v4 = *(_QWORD *)(v1[2] + 192LL);
  if ( !v3 )
  {
    if ( v4 && !*(_DWORD *)(v4 + 24) )
      ipc_log_string(*(_QWORD *)(v4 + 32), "[D][%s] Calling runtime_get()\n", "mhi_unprepare_from_transfer");
    v5 = (void (__fastcall **)(_QWORD))(v1 + 64);
    goto LABEL_9;
  }
  if ( v4 && !*(_DWORD *)(v4 + 24) )
  {
    v5 = (void (__fastcall **)(_QWORD))(v1 + 65);
    ipc_log_string(*(_QWORD *)(v4 + 32), "[D][%s] Calling runtime_get_sync()\n", "mhi_unprepare_from_transfer");
LABEL_9:
    v3 = *v5;
  }
  if ( *((_DWORD *)v3 - 1) != -700558418 )
    __break(0x8229u);
  v3(v1);
  v6 = a1[4];
  if ( v6 )
    mhi_unprepare_channel((__int64)v1, v6);
  v7 = a1[3];
  if ( v7 )
    mhi_unprepare_channel((__int64)v1, v7);
  v8 = (__int64 (__fastcall *)(_QWORD))v1[67];
  v9 = *(_QWORD *)(v1[2] + 192LL);
  if ( v8 )
  {
    if ( v9 && !*(_DWORD *)(v9 + 24) )
    {
      ipc_log_string(*(_QWORD *)(v9 + 32), "[D][%s] Calling runtime_put_autosuspend()\n", "mhi_unprepare_from_transfer");
      v8 = (__int64 (__fastcall *)(_QWORD))v1[67];
    }
    v10 = v1;
    if ( *((_DWORD *)v8 - 1) != -700558418 )
      __break(0x8228u);
  }
  else
  {
    if ( v9 && !*(_DWORD *)(v9 + 24) )
      ipc_log_string(*(_QWORD *)(v9 + 32), "[D][%s] Calling runtime_put()\n", "mhi_unprepare_from_transfer");
    v8 = (__int64 (__fastcall *)(_QWORD))v1[66];
    v10 = v1;
    if ( *((_DWORD *)v8 - 1) != -2145957670 )
      __break(0x8228u);
  }
  return v8(v10);
}

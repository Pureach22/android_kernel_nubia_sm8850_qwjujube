__int64 __fastcall get_temp_tsens_valid(__int64 *a1, _DWORD *a2)
{
  int v2; // w19
  __int64 v3; // x22
  int v6; // w0
  int v7; // w3
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  v2 = *((_DWORD *)a1 + 17);
  v3 = *a1;
  v6 = tsens_hw_to_mC();
  *a2 = v6;
  v7 = v6;
  v8 = a1[1];
  if ( v8 )
  {
    if ( v3 )
    {
      v9 = *(_QWORD *)(v3 + 2584);
      if ( v9 )
        ipc_log_string(
          v9,
          "Sensor:%s temp: %d [%s]\n",
          (const char *)(v8 + 4),
          v7,
          (const char *)(_ReadStatusReg(SP_EL0) + 2320));
    }
  }
  else if ( v3 )
  {
    v10 = *(_QWORD *)(v3 + 2584);
    if ( v10 )
      ipc_log_string(v10, "Sensor:%d temp: %d [%s]\n", v2, v7, (const char *)(_ReadStatusReg(SP_EL0) + 2320));
  }
  return 0;
}

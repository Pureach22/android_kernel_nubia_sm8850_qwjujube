__int64 __fastcall cam_sfe_stop(__int64 a1, int *a2, int a3)
{
  _QWORD *v4; // x21
  int v6; // w6
  __int64 *v7; // x8
  __int64 (__fastcall *v8)(__int64, int *, __int64); // x9
  __int64 v9; // x0
  unsigned int v10; // w21
  __int64 result; // x0
  __int64 v12; // x8
  _DWORD *v13; // x8

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_stop",
      350,
      "Invalid input arguments");
    return 4294967274LL;
  }
  v4 = *(_QWORD **)(a1 + 3680);
  mutex_lock(a1);
  v6 = *a2;
  if ( *a2 == 12 )
  {
    v12 = v4[2];
  }
  else
  {
    if ( v6 != 11 )
    {
      if ( v6 == 10 )
      {
        v7 = (__int64 *)v4[1];
        v8 = (__int64 (__fastcall *)(__int64, int *, __int64))v7[8];
        v9 = *v7;
        if ( *((_DWORD *)v8 - 1) != 1989616049 )
          __break(0x8229u);
        v10 = v8(v9, a2, 152);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000000,
          1,
          "cam_sfe_stop",
          367,
          "Invalid SFE res type: %d",
          v6);
        v10 = -22;
      }
      goto LABEL_17;
    }
    v12 = v4[3];
  }
  v13 = *(_DWORD **)(v12 + 64);
  if ( *(v13 - 1) != 1989616049 )
    __break(0x8228u);
  v10 = ((__int64 (__fastcall *)(int *, _QWORD, _QWORD))v13)(a2, 0, 0);
LABEL_17:
  mutex_unlock(a1);
  if ( (debug_mdl & 0x40000000) != 0 )
  {
    result = v10;
    if ( debug_priority )
      return result;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_stop",
      373,
      "Stop for SFE res type: %u res id: %u res_state: %d rc: %d",
      *a2,
      a2[1],
      a2[2],
      v10);
  }
  return v10;
}

__int64 __fastcall cam_sfe_start(__int64 a1, int *a2, int a3)
{
  _QWORD *v4; // x21
  int v6; // w6
  __int64 *v7; // x8
  __int64 (__fastcall *v8)(__int64, int *, __int64); // x9
  __int64 v9; // x0
  unsigned int v10; // w21
  const char *v11; // x5
  __int64 v12; // x4
  _DWORD *v13; // x8
  _DWORD *v14; // x8

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_start",
      301,
      "Invalid input arguments");
    return (unsigned int)-22;
  }
  v4 = *(_QWORD **)(a1 + 3680);
  v4[5] = *((_QWORD *)a2 + 7);
  mutex_lock(a1);
  v6 = *a2;
  if ( *a2 == 12 )
  {
    v14 = *(_DWORD **)(v4[2] + 56LL);
    if ( *(v14 - 1) != 1989616049 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(int *, _QWORD, _QWORD))v14)(a2, 0, 0);
    if ( !v10 )
      goto LABEL_22;
    v11 = "Failed to start SFE BUS WR rc: %d";
    v12 = 320;
  }
  else if ( v6 == 11 )
  {
    v13 = *(_DWORD **)(v4[3] + 56LL);
    if ( *(v13 - 1) != 1989616049 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(int *, _QWORD, _QWORD))v13)(a2, 0, 0);
    if ( !v10 )
      goto LABEL_22;
    v11 = "Failed to start SFE BUS RD rc: %d";
    v12 = 326;
  }
  else
  {
    if ( v6 != 10 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_start",
        329,
        "Invalid SFE res type:%d",
        v6);
      v10 = -22;
      goto LABEL_22;
    }
    v7 = (__int64 *)v4[1];
    v8 = (__int64 (__fastcall *)(__int64, int *, __int64))v7[7];
    v9 = *v7;
    if ( *((_DWORD *)v8 - 1) != 1989616049 )
      __break(0x8229u);
    v10 = v8(v9, a2, 152);
    if ( !v10 )
      goto LABEL_22;
    v11 = "Failed to start SFE IN rc: %d";
    v12 = 315;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_start",
    v12,
    v11,
    v10);
LABEL_22:
  mutex_unlock(a1);
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_start",
      337,
      "Start for SFE res type: %u res id: %u res_state: %d rc: %d",
      *a2,
      a2[1],
      a2[2],
      v10);
  return v10;
}

__int64 __fastcall cam_sfe_release(__int64 a1, int *a2, int a3)
{
  _QWORD *v3; // x20
  __int64 v5; // x19
  int v6; // w6
  __int64 *v7; // x8
  __int64 (__fastcall *v9)(__int64, int *, __int64); // x9
  __int64 v10; // x0
  unsigned int v11; // w20
  __int64 v12; // x19

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_release",
      261,
      "Invalid input arguments");
    return 4294967274LL;
  }
  v3 = *(_QWORD **)(a1 + 3680);
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v12 = a1;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_release",
      269,
      "SFE release for res type: %d",
      *a2);
    a1 = v12;
  }
  v5 = a1;
  mutex_lock(a1);
  v6 = *a2;
  if ( *a2 == 12 )
  {
    v7 = (__int64 *)v3[2];
    goto LABEL_14;
  }
  if ( v6 == 11 )
  {
    v7 = (__int64 *)v3[3];
    goto LABEL_14;
  }
  if ( v6 == 10 )
  {
    v7 = (__int64 *)v3[1];
LABEL_14:
    v9 = (__int64 (__fastcall *)(__int64, int *, __int64))v7[6];
    v10 = *v7;
    if ( *((_DWORD *)v9 - 1) != 1989616049 )
      __break(0x8229u);
    v11 = v9(v10, a2, 152);
    goto LABEL_18;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000000,
    1,
    "cam_sfe_release",
    286,
    "Invalid SFE res type: %d",
    v6);
  v11 = -19;
LABEL_18:
  mutex_unlock(v5);
  return v11;
}

__int64 __fastcall cam_vfe_release(__int64 a1, int *a2, int a3)
{
  _QWORD *v4; // x21
  int v6; // w6
  __int64 *v7; // x8
  unsigned int v8; // w20
  __int64 (__fastcall *v9)(__int64, int *, __int64); // x9
  __int64 v10; // x0

  if ( a1 && a2 && a3 == 152 )
  {
    v4 = *(_QWORD **)(a1 + 3680);
    mutex_lock(a1);
    v6 = *a2;
    if ( *a2 == 6 )
    {
      v7 = (__int64 *)v4[3];
      goto LABEL_12;
    }
    if ( v6 == 5 )
    {
      v7 = (__int64 *)v4[4];
      if ( v7 )
        goto LABEL_12;
    }
    else
    {
      if ( v6 == 4 )
      {
        v7 = (__int64 *)v4[2];
LABEL_12:
        v9 = (__int64 (__fastcall *)(__int64, int *, __int64))v7[6];
        v10 = *v7;
        if ( *((_DWORD *)v9 - 1) != 1989616049 )
          __break(0x8229u);
        v8 = v9(v10, a2, 152);
        goto LABEL_17;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_vfe_release",
        389,
        "Invalid res type:%d",
        v6);
    }
    v8 = -19;
LABEL_17:
    mutex_unlock(a1);
    return v8;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_release",
    367,
    "Invalid input arguments");
  return (unsigned int)-22;
}

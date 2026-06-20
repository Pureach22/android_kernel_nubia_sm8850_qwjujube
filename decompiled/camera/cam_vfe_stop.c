__int64 __fastcall cam_vfe_stop(__int64 a1, int *a2, int a3)
{
  __int64 v4; // x22
  int *v6; // x21
  int v7; // w6
  __int64 *v8; // x8
  __int64 (__fastcall *v9)(__int64, int *, __int64); // x9
  __int64 v10; // x0
  unsigned int v11; // w20
  __int64 v12; // x8
  _DWORD *v13; // x8

  if ( !a1 || !a2 || a3 != 152 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_stop",
      456,
      "Invalid input arguments");
    return (unsigned int)-22;
  }
  v4 = *(_QWORD *)(a1 + 3680);
  v6 = **(int ***)v4;
  mutex_lock(a1);
  v7 = *a2;
  if ( *a2 == 6 )
  {
    v12 = *(_QWORD *)(v4 + 24);
    goto LABEL_14;
  }
  if ( v7 == 5 )
  {
    v12 = *(_QWORD *)(v4 + 32);
    if ( !v12 )
      goto LABEL_18;
LABEL_14:
    v13 = *(_DWORD **)(v12 + 64);
    if ( *(v13 - 1) != 1989616049 )
      __break(0x8228u);
    v11 = ((__int64 (__fastcall *)(int *, _QWORD, _QWORD))v13)(a2, 0, 0);
    goto LABEL_19;
  }
  if ( v7 == 4 )
  {
    v8 = *(__int64 **)(v4 + 16);
    v9 = (__int64 (__fastcall *)(__int64, int *, __int64))v8[8];
    v10 = *v8;
    if ( *((_DWORD *)v9 - 1) != 1989616049 )
      __break(0x8229u);
    v11 = v9(v10, a2, 152);
    goto LABEL_19;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_vfe_stop",
    476,
    "Invalid res type:%d",
    v7);
LABEL_18:
  v11 = -22;
LABEL_19:
  if ( *v6 >= 1 )
  {
    ((void (__fastcall *)(_QWORD))cam_irq_controller_unsubscribe_irq)(*(_QWORD *)(v4 + 8));
    *v6 = 0;
  }
  mutex_unlock(a1);
  return v11;
}

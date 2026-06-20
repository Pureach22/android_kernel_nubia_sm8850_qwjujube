bool __fastcall cam_cpas_is_part_supported(int a1, int a2, unsigned int a3)
{
  char v3; // w23
  __int64 v7; // x19
  _BYTE *v8; // x9
  int *v9; // x8
  int v10; // w9

  v7 = *(_QWORD *)(*(_QWORD *)(g_cpas_intf + 480) + 112LL);
  mutex_lock(v7);
  v8 = *(_BYTE **)(v7 + 3680);
  v9 = *(int **)(*(_QWORD *)(*(_QWORD *)v8 + 40LL) + 48LL);
  if ( !v9 || v8[7992] != 1 )
  {
    if ( (debug_mdl & 4) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 4,
        4,
        "cam_cpas_is_part_supported",
        359,
        "Invalid address of cam_subpart_info");
    goto LABEL_10;
  }
  v10 = *v9;
  if ( !*v9 )
    goto LABEL_10;
  if ( v9[1] == a1 && v9[2] == a2 )
  {
    v3 = 0;
LABEL_39:
    LOBYTE(v9) = debug_mdl;
    if ( (debug_mdl & 4) == 0 || debug_priority )
      goto LABEL_41;
    goto LABEL_44;
  }
  if ( v10 == 1 )
    goto LABEL_10;
  if ( v9[3] == a1 && v9[4] == a2 )
  {
    v3 = 1;
    goto LABEL_39;
  }
  if ( v10 == 2 )
    goto LABEL_10;
  if ( v9[5] == a1 && v9[6] == a2 )
  {
    v3 = 2;
    goto LABEL_39;
  }
  if ( v10 == 3 )
    goto LABEL_10;
  if ( v9[7] == a1 && v9[8] == a2 )
  {
    v3 = 3;
    goto LABEL_39;
  }
  if ( v10 == 4 )
    goto LABEL_10;
  if ( v9[9] == a1 && v9[10] == a2 )
  {
    v3 = 4;
    goto LABEL_39;
  }
  if ( v10 == 5 )
    goto LABEL_10;
  if ( v9[11] == a1 && v9[12] == a2 )
  {
    v3 = 5;
    goto LABEL_39;
  }
  if ( v10 == 6 )
    goto LABEL_10;
  if ( v9[13] == a1 && v9[14] == a2 )
  {
    v3 = 6;
    goto LABEL_39;
  }
  if ( v10 == 7 )
    goto LABEL_10;
  if ( v9[15] == a1 )
  {
    LODWORD(v9) = v9[16];
    if ( (_DWORD)v9 == a2 )
    {
      v3 = 7;
      goto LABEL_39;
    }
  }
  if ( v10 == 8 )
  {
LABEL_10:
    mutex_unlock(v7);
    return 1;
  }
  __break(0x5512u);
LABEL_44:
  ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    (unsigned __int8)v9 & 4,
    4,
    "cam_cpas_is_part_supported",
    368,
    "flag: %u hw_map: %u part_info:0x%x",
    a1,
    a2,
    a3);
LABEL_41:
  mutex_unlock(v7);
  return (((unsigned __int64)a3 >> v3) & 1) == 0;
}

__int64 __fastcall cam_ife_csid_ver2_reset(__int64 a1, unsigned int *a2)
{
  __int64 v2; // x19
  unsigned int v4; // w0
  unsigned int v5; // w21
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x2
  int v9; // w20
  const char *v10; // x0
  unsigned int v12; // w0
  char v13; // w20
  int v14; // w21
  const char *v15; // x0

  v2 = *(_QWORD *)(a1 + 3680);
  mutex_lock(*(_QWORD *)(v2 + 31128));
  v4 = *a2;
  v5 = -22;
  if ( (int)*a2 > 1 )
  {
    if ( v4 == 2 )
    {
      v6 = v2;
      v7 = 2;
    }
    else
    {
      if ( v4 != 3 )
        goto LABEL_13;
      v6 = v2;
      v7 = 0;
    }
  }
  else
  {
    if ( v4 )
    {
      if ( v4 == 1 )
      {
        v6 = v2;
        v7 = 2;
        v8 = 0;
        goto LABEL_11;
      }
LABEL_13:
      v9 = *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL);
      v10 = cam_ife_csid_reset_type_to_string(v4);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_reset",
        4057,
        "CSID[%u] reset type: %s failed",
        v9,
        v10);
      goto LABEL_14;
    }
    v6 = v2;
    v7 = 1;
  }
  v8 = 1;
LABEL_11:
  v5 = cam_ife_csid_ver2_internal_reset(v6, v7, v8);
  if ( v5 )
  {
    v4 = *a2;
    goto LABEL_13;
  }
  if ( (debug_mdl & 8) != 0 && !debug_priority )
  {
    v12 = *a2;
    v13 = debug_mdl;
    v14 = *(_DWORD *)(*(_QWORD *)(v2 + 31120) + 4LL);
    v15 = cam_ife_csid_reset_type_to_string(v12);
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v13 & 8,
      4,
      "cam_ife_csid_ver2_reset",
      4061,
      "CSID[%u] reset type: %s",
      v14,
      v15);
    v5 = 0;
  }
LABEL_14:
  mutex_unlock(*(_QWORD *)(v2 + 31128));
  return v5;
}

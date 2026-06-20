__int64 __fastcall cam_vfe_bus_acquire_vfe_bus_rd(unsigned int *a1, _DWORD *a2)
{
  _BOOL4 v2; // w19
  unsigned int v3; // w7
  __int64 result; // x0
  unsigned int v5; // w8
  __int64 v6; // x20
  char v7; // w11
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x14
  int v12; // w13
  int v13; // w15
  unsigned int *v14; // x12
  unsigned int *v15; // x12
  unsigned int v16; // w15
  __int64 v17; // x11
  unsigned int *v18; // x19
  int v19; // w8
  int v20; // w8
  _BOOL4 v21; // w7
  unsigned int v22; // w19
  char v23; // w14
  int v24; // w13
  __int64 v25; // x8
  unsigned int v26; // [xsp+Ch] [xbp-14h]
  unsigned int *v27; // [xsp+10h] [xbp-10h]
  unsigned int *v28; // [xsp+10h] [xbp-10h]
  _DWORD *v29; // [xsp+18h] [xbp-8h]
  _DWORD *v30; // [xsp+18h] [xbp-8h]

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_acquire_vfe_bus_rd",
      573,
      "Invalid Param");
    return 4294967274LL;
  }
  v2 = *a2 != 5;
  if ( *a2 == 5 )
    v3 = 0;
  else
    v3 = -1;
  if ( *a2 != 5 )
    return 4294967277LL;
  v5 = a1[120];
  if ( v5 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_acquire_vfe_bus_rd",
      592,
      "VFE:%d RM:0x%x not available state:%d",
      *a1,
      5,
      v5);
    return 4294967280LL;
  }
  v6 = *((_QWORD *)a1 + 62);
  v7 = debug_mdl;
  a1[119] = 5;
  if ( (v7 & 8) != 0 && !debug_priority )
  {
    v29 = a2;
    v27 = a1;
    v26 = v3;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v7 & 8,
      4,
      "cam_vfe_bus_acquire_vfe_bus_rd",
      600,
      "VFE:%d acquire RD type:0x%x",
      **(_DWORD **)(v6 + 8),
      *a2);
    v3 = v26;
    a1 = v27;
    a2 = v29;
  }
  *(_DWORD *)(v6 + 16) = 1;
  v8 = *((_QWORD *)a2 + 1);
  *((_QWORD *)a1 + 66) = v8;
  *((_QWORD *)a1 + 79) = v8;
  v9 = *((_QWORD *)a2 + 8);
  *((_QWORD *)a1 + 65) = v9;
  *(_QWORD *)(v6 + 88) = v9;
  *(_QWORD *)(*(_QWORD *)(v6 + 8) + 304LL) = *((_QWORD *)a2 + 3);
  *(_QWORD *)(v6 + 104) = *((_QWORD *)a2 + 2);
  *(_BYTE *)(v6 + 116) = *((_BYTE *)a2 + 76);
  v11 = *((_QWORD *)a2 + 1);
  v10 = *((_QWORD *)a2 + 2);
  v12 = a2[15];
  v13 = a2[18];
  *(_QWORD *)(v6 + 24) = 0;
  if ( a1[78] <= v3 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_acquire_rm",
      369,
      "Unsupported VFE RM:%d plane:%d",
      v2,
      0);
    v20 = -22;
LABEL_21:
    v21 = v2;
    v22 = v20;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_acquire_vfe_bus_rd",
      625,
      "VFE:%d RM:%d acquire failed rc:%d",
      **(_DWORD **)(v6 + 8),
      v21,
      v20);
    return v22;
  }
  v14 = &a1[38 * v3];
  if ( v14[82] != 1 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      8,
      1,
      "cam_vfe_bus_acquire_rm",
      377,
      "VFE:%d RM:%d res not available state:%d",
      *a1);
    v20 = -114;
    goto LABEL_21;
  }
  v15 = v14 + 80;
  v16 = v13 - 2;
  v15[2] = 2;
  v17 = *((_QWORD *)v15 + 3);
  v18 = a1 + 118;
  *((_QWORD *)v15 + 7) = v11;
  *(_QWORD *)(v17 + 24) = v10;
  *(_DWORD *)(v17 + 96) = v12;
  if ( v16 > 0x2E )
    v19 = 19;
  else
    v19 = dword_44E800[v16];
  v23 = debug_mdl;
  *(_DWORD *)(v17 + 36) = 0;
  *(_DWORD *)(v17 + 68) = 512;
  *(_DWORD *)(v17 + 72) = v19;
  v24 = debug_priority;
  v25 = v23 & 8;
  *(_QWORD *)(v6 + 24) = v15;
  if ( (v23 & 8) != 0 && !v24 )
  {
    v28 = a1;
    v30 = a2;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v23 & 8,
      4,
      "cam_vfe_bus_acquire_rm",
      406,
      "VFE:%d RM:%d Acquired",
      **(_DWORD **)(v17 + 8),
      *(_DWORD *)v17);
    a1 = v28;
    a2 = v30;
    v24 = debug_priority;
    v25 = debug_mdl & 8;
  }
  a1[120] = 2;
  result = 0;
  *((_QWORD *)a2 + 6) = v18;
  if ( v25 )
  {
    if ( !v24 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v25,
        4,
        "cam_vfe_bus_acquire_vfe_bus_rd",
        634,
        "VFE:%d acquire RD 0x%x successful",
        **(_DWORD **)(v6 + 8),
        *a2);
      return 0;
    }
  }
  return result;
}

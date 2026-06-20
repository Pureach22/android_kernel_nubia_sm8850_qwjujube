__int64 __fastcall cam_sfe_bus_acquire_bus_rd(unsigned int *a1, _DWORD *a2)
{
  unsigned int v2; // w11
  unsigned int v3; // w19
  unsigned int *v4; // x9
  unsigned int *v5; // x9
  __int64 v6; // x20
  __int64 v7; // x12
  __int64 v8; // x12
  int v9; // w6
  int v10; // w7
  __int64 result; // x0
  __int64 v12; // x14
  __int64 v13; // x15
  int v14; // w11
  unsigned int v15; // w12
  __int64 v16; // x12
  unsigned int v17; // w16
  int v18; // w11
  unsigned int v19; // w14
  int v20; // w10
  const char *v21; // x5
  __int64 v22; // x4
  __int64 v23; // x6
  __int64 v24; // x7
  int v25; // w9
  unsigned int v26; // w7
  unsigned int v27; // w19
  int v28; // [xsp+0h] [xbp-20h]
  unsigned int *v29; // [xsp+8h] [xbp-18h]
  unsigned int *v30; // [xsp+10h] [xbp-10h]
  unsigned int *v31; // [xsp+10h] [xbp-10h]
  _DWORD *v32; // [xsp+18h] [xbp-8h]
  _DWORD *v33; // [xsp+18h] [xbp-8h]

  if ( !a1 || !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_acquire_bus_rd",
      991,
      "Invalid Param");
    return 4294967274LL;
  }
  v2 = a2[12];
  v3 = v2 - 20481;
  if ( v2 - 20481 > 2 )
    return 4294967277LL;
  v4 = &a1[38 * v3];
  if ( v4[584] != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_acquire_bus_rd",
      1010,
      "SFE:%d RM:0x%x not available state:%d",
      *a1,
      *a2,
      v4[584]);
    return 4294967280LL;
  }
  v5 = v4 + 582;
  v5[1] = v2;
  v6 = *((_QWORD *)v5 + 3);
  if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
  {
    v32 = a2;
    v29 = a1;
    v30 = v5;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 0x40000000,
      4,
      "cam_sfe_bus_acquire_bus_rd",
      1018,
      "SFE:%d acquire RD type:0x%x res_id 0x%x",
      **(_DWORD **)(v6 + 8),
      *a2,
      v2);
    a1 = v29;
    v5 = v30;
    a2 = v32;
  }
  *(_DWORD *)(v6 + 24) = 1;
  v7 = *((_QWORD *)a2 + 1);
  *((_QWORD *)v5 + 7) = v7;
  *((_QWORD *)a1 + 350) = v7;
  v8 = *((_QWORD *)a2 + 7);
  *((_QWORD *)v5 + 6) = v8;
  *(_QWORD *)(v6 + 64) = v8;
  *(_QWORD *)(*(_QWORD *)(v6 + 8) + 1824LL) = *((_QWORD *)a2 + 3);
  *(_QWORD *)(v6 + 72) = *((_QWORD *)a2 + 2);
  LOBYTE(v8) = *((_BYTE *)a2 + 68);
  *(_QWORD *)(v6 + 16) = a1;
  *(_BYTE *)(v6 + 88) = v8;
  if ( (v8 & 1) == 0 )
    *(_DWORD *)(v6 + 84) = 1;
  v9 = *(_DWORD *)(v6 + 80);
  v10 = *((unsigned __int8 *)a2 + 69);
  if ( v9 )
  {
    if ( v9 != v10 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000000,
        1,
        "cam_sfe_bus_acquire_bus_rd",
        1042,
        "Current Mode %u Requesting Mode %u",
        v9,
        v10);
      return 4294967274LL;
    }
  }
  else
  {
    *(_DWORD *)(v6 + 80) = v10;
  }
  v13 = *((_QWORD *)a2 + 1);
  v12 = *((_QWORD *)a2 + 2);
  v14 = a2[16];
  *(_QWORD *)(v6 + 32) = 0;
  if ( a1[466] <= v3 )
  {
    v21 = "Unsupported SFE RM:%d plane:%d";
    v22 = 486;
    v23 = v3;
    v24 = 0;
LABEL_32:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_acquire_rm",
      v22,
      v21,
      v23,
      v24,
      v28);
    v25 = -22;
LABEL_33:
    v26 = v3;
    v27 = v25;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000000,
      1,
      "cam_sfe_bus_acquire_bus_rd",
      1058,
      "SFE:%d RM:%d acquire failed rc:%d",
      **(_DWORD **)(v6 + 8),
      v26,
      v25);
    return v27;
  }
  v15 = a1[38 * v3 + 470];
  if ( v15 != 1 )
  {
    v25 = -114;
    if ( (debug_mdl & 0x40000000) != 0 && !debug_priority )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x40000000,
        4,
        "cam_sfe_bus_acquire_rm",
        494,
        "SFE:%u RM:%u res not available state:%d",
        *a1,
        v3,
        v15);
      v25 = -114;
    }
    goto LABEL_33;
  }
  v16 = *(_QWORD *)&a1[38 * v3 + 474];
  v17 = v14 - 2;
  a1[38 * v3 + 470] = 2;
  *(_QWORD *)&a1[38 * v3 + 482] = v13;
  *(_QWORD *)(v16 + 16) = v12;
  if ( (unsigned int)(v14 - 2) >= 0x2F || ((0x6084807FF40FuLL >> v17) & 1) == 0 )
  {
    *(_DWORD *)(v16 + 60) = 19;
    v21 = "SFE:%u RM:%u Invalid unpacker fmt:%u";
    v23 = *a1;
    v22 = 506;
    v24 = v3;
    v28 = v14;
    goto LABEL_32;
  }
  *(_DWORD *)(v16 + 60) = dword_44E420[v17];
  v18 = debug_mdl;
  v19 = a1[703];
  *(_WORD *)(v16 + 88) = 0;
  *(_DWORD *)(v16 + 84) = 0;
  *(_DWORD *)(v16 + 76) = 32;
  *(_DWORD *)(v16 + 56) = v19;
  *(_QWORD *)(v6 + 32) = &a1[38 * v3 + 468];
  if ( (v18 & 0x40000000) != 0 && !debug_priority )
  {
    v33 = a2;
    v31 = v5;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v18 & 0x40000000,
      4,
      "cam_sfe_bus_acquire_rm",
      521,
      "SFE:%d RM:%d Acquired",
      **(_DWORD **)v16,
      *(_DWORD *)(v16 + 24));
    v5 = v31;
    a2 = v33;
  }
  result = 0;
  v5[2] = 2;
  v20 = debug_mdl;
  *((_QWORD *)a2 + 5) = v5;
  if ( (v20 & 0x40000000) != 0 && !debug_priority )
  {
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v20 & 0x40000000,
      4,
      "cam_sfe_bus_acquire_bus_rd",
      1067,
      "SFE:%d acquire RD 0x%x successful",
      **(_DWORD **)(v6 + 8),
      *a2);
    return 0;
  }
  return result;
}

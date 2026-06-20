__int64 __fastcall cam_ife_csid_ver2_top_cfg(__int64 a1, int *a2, __int64 a3)
{
  unsigned int v3; // w20
  __int64 v4; // x21
  __int64 v5; // x19
  int v6; // w8
  int v7; // w7
  int v8; // w7
  const char *v9; // x5
  __int64 v10; // x20
  int *v11; // x22
  __int64 v12; // x4
  __int64 v13; // x6
  int v14; // w9
  char v15; // w12
  int v16; // w10
  int v17; // w11
  __int64 v18; // x8
  __int64 v19; // x24
  int v20; // w7
  __int64 v21; // x8
  int v22; // w11
  int v23; // w12
  char v24; // w9
  __int64 v26; // x24
  int *v27; // x25
  __int64 v28; // x25

  if ( !a1 )
    return (unsigned int)-22;
  v3 = 0;
  v4 = **(_QWORD **)(a1 + 31136);
  v5 = *(unsigned int *)(*(_QWORD *)(a1 + 31120) + 4LL);
  *(_BYTE *)(a1 + 2066) = 1;
  v6 = *a2;
  if ( *a2 <= 1 )
  {
    if ( v6 )
    {
      if ( v6 != 1 )
        goto LABEL_30;
      goto LABEL_26;
    }
    v3 = 0;
    *(_DWORD *)(a1 + 2048) = 0;
    *(_BYTE *)(a1 + 2066) = 0;
LABEL_30:
    v14 = *((unsigned __int8 *)a2 + 8);
    v15 = debug_mdl;
    v16 = debug_priority;
    *(_BYTE *)(a1 + 2065) = v14;
    v17 = *((unsigned __int8 *)a2 + 9);
    v18 = v15 & 8;
    *(_BYTE *)(a1 + 2067) = v17;
    if ( (v15 & 8) != 0 && !v16 )
    {
      v26 = a1;
      v27 = a2;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v15 & 8,
        4,
        "cam_ife_csid_ver2_top_cfg",
        7789,
        "CSID[%u] input_core_type:%d ife_out:%d sfe_offline:%d sfe_fs:%d",
        v5,
        *(_DWORD *)(a1 + 2048),
        *(unsigned __int8 *)(a1 + 2066),
        v14,
        v17);
      v16 = debug_priority;
      a2 = v27;
      a1 = v26;
      v18 = debug_mdl & 8;
      v19 = v26 + 28672;
      if ( (debug_mdl & 8) != 0 )
      {
LABEL_33:
        if ( !v16 )
        {
          v28 = a1;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v18,
            4,
            "cam_ife_csid_ver2_top_cfg",
            7792,
            "CSID[%u] Top config received: input_core_type%d core_idx:%d",
            v5,
            *a2,
            a2[1]);
          a1 = v28;
        }
      }
    }
    else
    {
      v19 = a1 + 28672;
      if ( (v15 & 8) != 0 )
        goto LABEL_33;
    }
    v20 = *(_DWORD *)(v19 + 3568);
    if ( v20 )
    {
      if ( v20 == 1 )
        v21 = 92;
      else
        v21 = 96;
      v22 = *(_DWORD *)(v19 + 3524);
      v23 = *(_DWORD *)(*(_QWORD *)(v4 + 232) + v21);
      v24 = debug_mdl;
      *(_BYTE *)(a1 + 2064) = 1;
      *(_DWORD *)(a1 + 2056) = v23;
      *(_DWORD *)(a1 + 2052) = v22 + 1;
      if ( (v24 & 8) != 0 && !debug_priority )
        ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          v24 & 8,
          4,
          "cam_ife_csid_ver2_top_cfg",
          7809,
          "CSID[%u] Top dual sync config core_sel: %d sync_mode: %d",
          (unsigned int)v5);
    }
    return v3;
  }
  if ( v6 == 2 )
  {
LABEL_16:
    v8 = a2[1];
    switch ( v8 )
    {
      case 2:
        v6 = 4;
        goto LABEL_26;
      case 1:
        v6 = 3;
        goto LABEL_26;
      case 0:
        v6 = 2;
        goto LABEL_26;
    }
    v9 = "CSID: %u Invalid SFE node %d";
    v10 = a1;
    v11 = a2;
    v12 = 7749;
    v13 = (unsigned int)v5;
LABEL_29:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_top_cfg",
      v12,
      v9,
      v13);
    a2 = v11;
    a1 = v10;
    v3 = -22;
    goto LABEL_30;
  }
  if ( v6 == 3 )
  {
    *(_BYTE *)(a1 + 2066) = 0;
    goto LABEL_16;
  }
  if ( v6 != 4 )
    goto LABEL_30;
  if ( (unsigned int)v5 < 8 )
  {
    v7 = a2[1];
    if ( (((unsigned __int64)*(unsigned int *)(v4 + 4 * v5 + 268) >> v7) & 1) != 0 )
    {
      if ( v7 == 1 )
      {
        v6 = 6;
        goto LABEL_26;
      }
      if ( !v7 )
      {
        v6 = 5;
LABEL_26:
        v3 = 0;
        *(_DWORD *)(a1 + 2048) = v6;
        goto LABEL_30;
      }
      v9 = "CSID: %u Invalid Cust node %d";
      v10 = a1;
      v11 = a2;
      v12 = 7775;
    }
    else
    {
      v9 = "CSID: %u not supported for cust node %d";
      v10 = a1;
      v11 = a2;
      v12 = 7760;
    }
    v13 = (unsigned int)v5;
    goto LABEL_29;
  }
  __break(0x5512u);
  return cam_ife_csid_ver2_reg_update(a1, a2, a3);
}

__int64 __fastcall cam_ife_csid_hw_ver1_hw_cfg(_DWORD *a1, __int64 a2, __int64 a3, int a4)
{
  int v4; // w8
  _DWORD *v5; // x19
  char v6; // w9
  __int64 v7; // x20
  _DWORD *v8; // x21
  __int64 v9; // x22
  int v10; // w23
  int v11; // w8
  int v12; // w9
  char v13; // w9
  int v14; // w9
  _DWORD *v15; // x8
  int v16; // w9
  int v17; // w10
  int v18; // w11
  __int64 v19; // x8
  _DWORD *v20; // x20
  __int64 v21; // x21
  int v22; // w9
  char v23; // w13
  int v24; // w11
  int v25; // w10
  int v26; // w12
  __int64 v27; // x8
  char v28; // w8
  __int64 v29; // x7
  int v30; // w8
  __int64 v31; // x7
  int v32; // w7
  int v33; // w9
  int v34; // t1
  __int64 v35; // x19
  _DWORD *v36; // x20
  _DWORD *v38; // x8
  int v39; // w8
  int v40; // w8
  _DWORD *v41; // x21
  __int64 v42; // x20
  int v43; // w22
  int v44; // [xsp+10h] [xbp-20h]
  __int64 v45; // [xsp+20h] [xbp-10h]
  __int64 v46; // [xsp+20h] [xbp-10h]
  _DWORD *v47; // [xsp+28h] [xbp-8h]
  _DWORD *v48; // [xsp+28h] [xbp-8h]
  __int64 v49; // [xsp+48h] [xbp+18h]
  __int64 v50; // [xsp+48h] [xbp+18h]
  __int64 v51; // [xsp+48h] [xbp+18h]

  v4 = a1[10];
  v5 = a1 + 6144;
  if ( v4 )
  {
    v6 = debug_mdl;
    a1[10] = v4 + 1;
    if ( (v6 & 8) != 0 && !debug_priority )
    {
      v7 = a2;
      v8 = a1;
      v9 = a3;
      v10 = a4;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        v6 & 8,
        4,
        "cam_ife_csid_hw_ver1_rx_cfg",
        1455,
        "CSID %u Rx already reserved cnt %u",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL));
      a4 = v10;
      a2 = v7;
      a1 = v8;
      a3 = v9;
    }
    goto LABEL_17;
  }
  a1[7069] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 20LL);
  a1[7067] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 12LL);
  a1[7068] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 16LL);
  a1[7098] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL);
  a1[7073] = *(unsigned __int8 *)(*(_QWORD *)(a3 + 8) + 220LL);
  v11 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL);
  if ( v11 > 16392 )
  {
    if ( v11 == 16394 )
    {
      v12 = 2;
      goto LABEL_14;
    }
    if ( v11 != 16393 )
      goto LABEL_12;
    v12 = 1;
  }
  else
  {
    v12 = 0;
    if ( v11 != 0x4000 && v11 != 16392 )
LABEL_12:
      v12 = (unsigned __int8)*(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL) - 1;
  }
LABEL_14:
  a1[7066] = v12;
  v13 = debug_mdl;
  a1[10] = 1;
  if ( (v13 & 8) != 0 && !debug_priority )
  {
    v49 = a2;
    v41 = a1;
    v42 = a3;
    v43 = a4;
    ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v13 & 8,
      4,
      "cam_ife_csid_hw_ver1_rx_cfg",
      1494,
      "CSID:%u Lane cfg:0x%x type:%u num:%u res:0x%x, res_cnt %u",
      *(_DWORD *)(*(_QWORD *)a1 + 4LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 20LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 12LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 16LL),
      *(_DWORD *)(*(_QWORD *)(a3 + 8) + 8LL),
      1);
    a2 = v49;
    a4 = v43;
    a1 = v41;
    a3 = v42;
  }
LABEL_17:
  *(_DWORD *)a2 = a4;
  *(_DWORD *)(a2 + 4) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 60LL);
  *(_DWORD *)(a2 + 8) = *(_DWORD *)(*(_QWORD *)(a3 + 16) + 4LL);
  *(_DWORD *)(a2 + 60) = *(_DWORD *)(a3 + 24);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 116LL);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 108LL);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 112LL);
  *(_BYTE *)(a2 + 64) = *(_BYTE *)(a3 + 56);
  *(_BYTE *)(a2 + 65) = *(_BYTE *)(a3 + 57);
  *(_DWORD *)(a2 + 40) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 148LL);
  *(_DWORD *)(a2 + 48) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 156LL);
  *(_DWORD *)(a2 + 56) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 160LL);
  v14 = *(_DWORD *)(a3 + 24);
  v15 = *(_DWORD **)(a3 + 8);
  if ( v14 == 2 )
  {
    v22 = v15[24];
    v23 = debug_mdl;
    v24 = debug_priority;
    *(_DWORD *)(a2 + 12) = v22;
    v25 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 100LL);
    *(_DWORD *)(a2 + 16) = v25;
    v26 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 104LL);
    v27 = v23 & 8;
    *(_DWORD *)(a2 + 20) = v26;
    if ( (v23 & 8) != 0 && !v24 )
    {
      v46 = a3;
      v48 = a1;
      v51 = a2;
      ((void (*)(__int64, _QWORD, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v23 & 8,
        4,
        "cam_ife_csid_hw_ver1_path_cfg",
        1143,
        "CSID:%d res:%d slave:start:0x%x end:0x%x width 0x%x",
        *(_DWORD *)(*(_QWORD *)a1 + 4LL),
        *(_DWORD *)(a3 + 4),
        v22,
        v25,
        v26);
      a3 = v46;
      a1 = v48;
      a2 = v51;
      v24 = debug_priority;
      v27 = debug_mdl & 8;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_33;
    }
    else if ( (v23 & 8) == 0 )
    {
      goto LABEL_33;
    }
    if ( !v24 )
    {
      v20 = a1;
      v21 = a3;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, int))cam_print_log)(
        3,
        v27,
        4,
        "cam_ife_csid_hw_ver1_path_cfg",
        1147,
        "CSID:%d res:%d slave:line start:0x%x line end:0x%x",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL),
        *(unsigned int *)(a3 + 4),
        *(_DWORD *)(a2 + 24),
        *(_DWORD *)(a2 + 28),
        v44);
      goto LABEL_60;
    }
  }
  else if ( v14 == 1 )
  {
    v16 = v15[21];
    *(_DWORD *)(a2 + 12) = v16;
    v17 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 88LL);
    *(_DWORD *)(a2 + 16) = v17;
    *(_DWORD *)(a2 + 20) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 92LL);
    if ( *(_DWORD *)(a3 + 4) <= 4u )
    {
      v17 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 100LL);
      *(_DWORD *)(a2 + 16) = v17;
      *(_DWORD *)(a2 + 20) = v17 - v16 + 1;
    }
    v18 = debug_priority;
    v19 = debug_mdl & 8;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v45 = a3;
      v47 = a1;
      v50 = a2;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_hw_ver1_path_cfg",
        1130,
        "CSID:%d res:%d master:startpixel 0x%x endpixel:0x%x",
        *(_DWORD *)(*(_QWORD *)a1 + 4LL),
        *(_DWORD *)(a3 + 4),
        v16,
        v17);
      a3 = v45;
      a1 = v47;
      a2 = v50;
      v18 = debug_priority;
      v19 = debug_mdl & 8;
      if ( (debug_mdl & 8) == 0 )
        goto LABEL_33;
    }
    else if ( (debug_mdl & 8) == 0 )
    {
      goto LABEL_33;
    }
    if ( !v18 )
    {
      v20 = a1;
      v21 = a3;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, int))cam_print_log)(
        3,
        v19,
        4,
        "cam_ife_csid_hw_ver1_path_cfg",
        1134,
        "CSID:%d res:%d master:line start:0x%x line end:0x%x",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL),
        *(unsigned int *)(a3 + 4),
        *(_DWORD *)(a2 + 24),
        *(_DWORD *)(a2 + 28),
        v44);
LABEL_60:
      a1 = v20;
      a3 = v21;
    }
  }
  else
  {
    *(_DWORD *)(a2 + 20) = v15[23];
    *(_DWORD *)(a2 + 12) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 84LL);
    v28 = debug_mdl;
    *(_DWORD *)(a2 + 16) = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 88LL);
    if ( (v28 & 8) != 0 && !debug_priority )
    {
      v20 = a1;
      v21 = a3;
      ((void (__fastcall *)(__int64, _QWORD, __int64, const char *, __int64, const char *, _QWORD, _QWORD, _DWORD, _DWORD, _DWORD))cam_print_log)(
        3,
        v28 & 8,
        4,
        "cam_ife_csid_hw_ver1_path_cfg",
        1157,
        "CSID:%d res:%d left width %d start: %d stop:%d",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL),
        *(unsigned int *)(a3 + 4),
        *(_DWORD *)(*(_QWORD *)(a3 + 8) + 92LL),
        *(_DWORD *)(*(_QWORD *)(a3 + 8) + 84LL),
        *(_DWORD *)(*(_QWORD *)(a3 + 8) + 88LL));
      goto LABEL_60;
    }
  }
LABEL_33:
  if ( *(_DWORD *)a3 == 0x4000 && (v5[936] & 1) == 0 )
  {
    v29 = *(unsigned int *)(*(_QWORD *)(a3 + 8) + 76LL);
    if ( (unsigned int)v29 >= 8 )
    {
      v35 = a3;
      v36 = a1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver1_tpg_config",
        1236,
        "CSID[%d] invalid test_pattern %d",
        *(unsigned int *)(*(_QWORD *)a1 + 4LL));
LABEL_42:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_hw_ver1_hw_cfg",
        1518,
        "CSID[%d] Res_id %d tpg config fail",
        *(_DWORD *)(*(_QWORD *)v36 + 4LL),
        *(_DWORD *)(v35 + 4));
      return 4294967274LL;
    }
    a1[17] = dword_45B630[v29];
    v30 = 1;
    v31 = *(_QWORD *)(a3 + 8);
    v34 = *(_DWORD *)(v31 + 60);
    v32 = v31 + 60;
    v33 = v34;
    if ( v34 > 4 )
    {
      if ( v33 == 5 )
      {
        v30 = 4;
        goto LABEL_50;
      }
      if ( v33 == 6 )
      {
        v30 = 5;
        goto LABEL_50;
      }
      if ( v33 != 34 )
      {
LABEL_46:
        v35 = a3;
        v36 = a1;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver1_tpg_config",
          1262,
          "CSID[%d] invalid input format %d",
          *(_DWORD *)(*(_QWORD *)a1 + 4LL),
          v32);
        goto LABEL_42;
      }
    }
    else if ( v33 != 2 )
    {
      if ( v33 == 3 )
      {
        v30 = 2;
        goto LABEL_50;
      }
      if ( v33 == 4 )
      {
        v30 = 3;
        goto LABEL_50;
      }
      goto LABEL_46;
    }
LABEL_50:
    a1[18] = v30;
    v38 = *(_DWORD **)(a3 + 8);
    if ( v38[20] )
      v39 = v38[25] + 1;
    else
      v39 = v38[23];
    a1[15] = v39;
    v40 = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 116LL);
    *((_BYTE *)v5 + 3744) = 1;
    a1[16] = v40;
    a1[20] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 24LL);
    a1[21] = *(_DWORD *)(*(_QWORD *)(a3 + 8) + 40LL);
  }
  return 0;
}

__int64 __fastcall cam_qup_i3c_write_burst(__int64 a1, _DWORD *a2)
{
  _DWORD *v2; // x21
  unsigned __int64 v4; // x22
  _BYTE *v5; // x19
  int *v6; // x24
  _DWORD *v7; // x13
  int v8; // w20
  int v9; // w23
  int v10; // w9
  int v11; // w8
  __int64 v12; // x1
  unsigned __int16 v13; // w20
  __int64 v14; // x8
  const char *v15; // x5
  __int64 v16; // x4
  unsigned int v17; // w8
  unsigned int v18; // w25
  const char *v19; // x14
  unsigned int *v20; // x24
  const char *v21; // x15
  const char *v22; // x28
  unsigned int v23; // w8
  __int64 v24; // x9
  __int16 v25; // w27
  const char *v26; // x28
  const char *v27; // x26
  _DWORD *v28; // x27
  unsigned __int64 v29; // x26
  __int64 v30; // x10
  int v31; // w9
  __int64 v32; // x1
  const char *v33; // x27
  const char *v34; // x28
  unsigned __int64 v35; // x27
  unsigned __int64 v36; // x26
  __int64 v37; // x10
  int v38; // w9
  __int64 v39; // x1
  unsigned int v40; // w7
  unsigned __int64 v41; // x28
  unsigned __int64 v42; // x27
  unsigned __int64 v43; // x26
  __int64 v44; // x9
  int v45; // w8
  __int64 v46; // x1
  const char *v47; // x27
  const char *v48; // x28
  const char *v49; // x28
  const char *v50; // x28
  const char *v51; // x28
  unsigned int v52; // w7
  __int64 v53; // x8
  int v54; // w0
  int v55; // w0
  int v56; // w22
  int v57; // w0
  int v58; // w0
  int v59; // w0
  int v60; // w0
  int v61; // w0
  int v62; // w0
  int v63; // w0
  int v64; // w0
  int v65; // w0
  __int64 v67; // [xsp+8h] [xbp-28h]
  _QWORD v68[4]; // [xsp+10h] [xbp-20h] BYREF

  v2 = a2;
  v68[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = (unsigned int)(a2[3] + a2[4] * a2[2]);
  v5 = (_BYTE *)_kmalloc_noprof(v4, 3521);
  if ( !v5 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_write_burst",
      477,
      "BUF is NULL");
    LODWORD(v2) = -12;
    goto LABEL_139;
  }
  v6 = *(int **)v2;
  v7 = &unk_393000;
  v8 = v2[3];
  v9 = v2[4];
  if ( (debug_mdl & 0x4000000000LL) == 0 || debug_priority )
  {
    if ( v8 <= 2 )
      goto LABEL_5;
LABEL_19:
    if ( v8 == 3 )
    {
      if ( v4 )
      {
        *v5 = *((_WORD *)v6 + 1);
        if ( v4 != 1 )
        {
          v5[1] = BYTE1(*v6);
          if ( v4 != 2 )
          {
            v13 = 3;
            v5[2] = *v6;
            goto LABEL_31;
          }
        }
      }
    }
    else
    {
      if ( v8 != 4 )
        goto LABEL_26;
      if ( v4 )
      {
        *v5 = *((_BYTE *)v6 + 3);
        if ( v4 != 1 )
        {
          v5[1] = *((_WORD *)v6 + 1);
          if ( v4 != 2 )
          {
            v5[2] = BYTE1(*v6);
            if ( v4 >= 4 )
            {
              v13 = 4;
              v5[3] = *v6;
              goto LABEL_31;
            }
          }
        }
      }
    }
LABEL_134:
    __break(1u);
    goto LABEL_135;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x4000000000LL,
    4,
    "cam_qup_i3c_write_burst",
    486,
    "reg addr = 0x%x data type: %d",
    *v6,
    v9);
  v7 = &unk_393000;
  if ( v8 > 2 )
    goto LABEL_19;
LABEL_5:
  if ( v8 == 1 )
  {
    if ( v4 )
    {
      v14 = debug_mdl;
      v13 = 1;
      *v5 = *(_BYTE *)v6;
      if ( (v14 & 0x4000000000LL) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          v14 & 0x4000000000LL,
          4,
          "cam_qup_i3c_write_burst",
          489,
          "byte %d: 0x%x",
          0);
        v7 = &unk_393000;
        v13 = 1;
      }
      goto LABEL_31;
    }
    goto LABEL_134;
  }
  if ( v8 != 2 )
  {
LABEL_26:
    v15 = "Invalid I2C addr type";
    v16 = 509;
LABEL_35:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_write_burst",
      v16,
      v15);
    LODWORD(v2) = -22;
    goto LABEL_123;
  }
  if ( !v4 )
    goto LABEL_134;
  v10 = *v6;
  *v5 = BYTE1(*v6);
  if ( v4 == 1 )
    goto LABEL_134;
  v11 = debug_priority;
  v12 = debug_mdl & 0x4000000000LL;
  v5[1] = *v6;
  if ( v12 && !v11 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_qup_i3c_write_burst",
      494,
      "byte %d: 0x%x",
      0,
      BYTE1(v10));
    v11 = debug_priority;
    v7 = &unk_393000;
    v12 = debug_mdl & 0x4000000000LL;
    v13 = 2;
    if ( (debug_mdl & 0x4000000000LL) == 0 )
      goto LABEL_31;
  }
  else
  {
    v13 = 2;
    if ( !v12 )
      goto LABEL_31;
  }
  if ( !v11 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_qup_i3c_write_burst",
      495,
      "byte %d: 0x%x",
      1,
      (unsigned __int8)v5[1]);
    v7 = &unk_393000;
    v13 = 2;
  }
LABEL_31:
  v17 = v2[2];
  if ( !v17 )
    goto LABEL_93;
  if ( (unsigned int)(v9 - 1) > 3 )
  {
    v15 = "Invalid Data Type";
    v16 = 554;
    goto LABEL_35;
  }
  v67 = a1;
  v18 = 0;
  v19 = "cam_qup_i3c_write_burst";
  v20 = (unsigned int *)(v6 + 1);
  v21 = "Byte %d: 0x%x";
  do
  {
    v23 = *v20;
    switch ( v9 )
    {
      case 3:
        if ( v4 <= v13 )
          goto LABEL_134;
        v35 = v13 + 1LL;
        v5[v13] = BYTE2(v23);
        if ( v4 <= v35 )
          goto LABEL_134;
        v36 = v13 + 2LL;
        v5[v35] = BYTE1(*v20);
        if ( v4 <= v36 )
          goto LABEL_134;
        v37 = debug_mdl;
        v38 = v7[919];
        v5[v36] = *v20;
        v39 = v37 & 0x4000000000LL;
        if ( (v37 & 0x4000000000LL) != 0 && !v38 )
        {
          v49 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
            3,
            v39,
            4,
            "cam_qup_i3c_write_burst",
            533,
            v21);
          v7 = &unk_393000;
          v21 = v49;
          v38 = debug_priority;
          v19 = "cam_qup_i3c_write_burst";
          v39 = debug_mdl & 0x4000000000LL;
          if ( (debug_mdl & 0x4000000000LL) == 0 )
            goto LABEL_61;
        }
        else if ( !v39 )
        {
          goto LABEL_61;
        }
        if ( !v38 )
        {
          if ( v4 <= v35 )
            goto LABEL_134;
          v50 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
            3,
            v39,
            4,
            "cam_qup_i3c_write_burst",
            535,
            v21,
            (unsigned int)v35,
            (unsigned __int8)v5[v35]);
          v7 = &unk_393000;
          v21 = v50;
          v38 = debug_priority;
          v19 = "cam_qup_i3c_write_burst";
          v39 = debug_mdl & 0x4000000000LL;
        }
LABEL_61:
        v25 = 3;
        if ( v39 && !v38 )
        {
          if ( v4 <= v36 )
            goto LABEL_134;
          goto LABEL_36;
        }
        goto LABEL_38;
      case 2:
        if ( v4 <= v13 )
          goto LABEL_134;
        v29 = v13 + 1LL;
        v5[v13] = BYTE1(v23);
        if ( v4 <= v29 )
          goto LABEL_134;
        v30 = debug_mdl;
        v31 = v7[919];
        v5[v29] = *v20;
        v32 = v30 & 0x4000000000LL;
        if ( (v30 & 0x4000000000LL) != 0 && !v31 )
        {
          v47 = v19;
          v48 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
            3,
            v32,
            4,
            v19,
            524,
            v21,
            v13,
            BYTE1(v23));
          v7 = &unk_393000;
          v21 = v48;
          v31 = debug_priority;
          v19 = v47;
          v32 = debug_mdl & 0x4000000000LL;
          v25 = 2;
          if ( (debug_mdl & 0x4000000000LL) == 0 )
            goto LABEL_38;
        }
        else
        {
          v25 = 2;
          if ( !v32 )
            goto LABEL_38;
        }
        if ( !v31 )
        {
          if ( v4 <= v29 )
            goto LABEL_134;
          v33 = v19;
          v34 = v21;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
            3,
            v32,
            4,
            v19,
            526,
            v21,
            (unsigned int)v29,
            (unsigned __int8)v5[v29]);
          v21 = v34;
          v19 = v33;
          v25 = 2;
          goto LABEL_37;
        }
        goto LABEL_38;
      case 1:
        if ( v4 <= v13 )
          goto LABEL_134;
        v24 = debug_mdl;
        v25 = 1;
        v5[v13] = v23;
        if ( (v24 & 0x4000000000LL) != 0 && !v7[919] )
        {
          v26 = v19;
          v27 = v21;
          v28 = v7;
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
            3,
            v24 & 0x4000000000LL,
            4,
            v19,
            518,
            v21,
            v13,
            (unsigned __int8)v23);
          v21 = v27;
          v19 = v26;
          v7 = v28;
          v25 = 1;
        }
        goto LABEL_38;
    }
    if ( v4 <= v13 )
      goto LABEL_134;
    v40 = HIBYTE(v23);
    v5[v13] = HIBYTE(v23);
    v41 = v13 + 1LL;
    if ( v4 <= v41 )
      goto LABEL_134;
    v42 = v13 + 2LL;
    v5[v41] = *((_WORD *)v20 + 1);
    if ( v4 <= v42 )
      goto LABEL_134;
    v43 = v13 + 3LL;
    v5[v42] = BYTE1(*v20);
    if ( v4 <= v43 )
      goto LABEL_134;
    v44 = debug_mdl;
    v45 = v7[919];
    v5[v43] = *v20;
    v46 = v44 & 0x4000000000LL;
    if ( (v44 & 0x4000000000LL) != 0 && !v45 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        v46,
        4,
        "cam_qup_i3c_write_burst",
        545,
        "Byte %d: 0x%x",
        v13,
        v40);
      v7 = &unk_393000;
      v21 = "Byte %d: 0x%x";
      v45 = debug_priority;
      v19 = "cam_qup_i3c_write_burst";
      v46 = debug_mdl & 0x4000000000LL;
      if ( (debug_mdl & 0x4000000000LL) != 0 )
      {
LABEL_72:
        if ( !v45 )
        {
          if ( v4 <= v41 )
            goto LABEL_134;
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            v46,
            4,
            "cam_qup_i3c_write_burst",
            547,
            "Byte %d: 0x%x",
            v41,
            (unsigned __int8)v5[v41]);
          v7 = &unk_393000;
          v21 = "Byte %d: 0x%x";
          v45 = debug_priority;
          v19 = "cam_qup_i3c_write_burst";
          v46 = debug_mdl & 0x4000000000LL;
        }
      }
    }
    else if ( v46 )
    {
      goto LABEL_72;
    }
    if ( v46 && !v45 )
    {
      if ( v4 <= v42 )
        goto LABEL_134;
      v51 = v21;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
        3,
        v46,
        4,
        "cam_qup_i3c_write_burst",
        549,
        v21,
        (unsigned int)v42,
        (unsigned __int8)v5[v42]);
      v7 = &unk_393000;
      v21 = v51;
      v45 = debug_priority;
      v19 = "cam_qup_i3c_write_burst";
      v25 = 4;
      if ( (debug_mdl & 0x4000000000LL) == 0 )
        goto LABEL_38;
    }
    else
    {
      v25 = 4;
      if ( !v46 )
        goto LABEL_38;
    }
    if ( !v45 )
    {
      if ( v4 <= v43 )
        goto LABEL_134;
LABEL_36:
      v22 = v21;
      ((void (*)(void))cam_print_log)();
      v21 = v22;
      v19 = "cam_qup_i3c_write_burst";
LABEL_37:
      v7 = &unk_393000;
    }
LABEL_38:
    v17 = v2[2];
    ++v18;
    v13 += v25;
    v20 += 4;
  }
  while ( v18 < v17 );
  a1 = v67;
LABEL_93:
  v52 = v2[3] + v2[4] * v17;
  if ( v52 < v13 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_write_burst",
      565,
      "Invalid Length: %u | Expected length: %u",
      v13,
      v52);
    LODWORD(v2) = -22;
    goto LABEL_123;
  }
  v53 = *(_QWORD *)(a1 + 8);
  v68[0] = 0;
  v68[1] = v5;
  WORD1(v68[0]) = v13;
  v68[2] = 0;
  if ( !v53 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_txdata",
      74,
      "qup_client is NULL");
    LODWORD(v2) = -22;
    goto LABEL_122;
  }
  v54 = i3c_device_do_priv_xfers(*(_QWORD *)(v53 + 8), v68, 1);
  if ( !v54 )
    goto LABEL_120;
  LODWORD(v2) = v54;
  if ( v54 != -107 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_txdata",
      92,
      "Failed with i3c_write: rc = %d",
      v54);
    if ( ((unsigned int)v2 & 0x80000000) != 0 )
      goto LABEL_122;
    goto LABEL_123;
  }
  usleep_range_state(1000, 1005, 2);
  v55 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v55 )
    goto LABEL_120;
  LODWORD(v2) = v55;
  if ( v55 != -107 )
  {
    v56 = 0;
    goto LABEL_125;
  }
  v56 = 1000;
  usleep_range_state(1000, 1005, 2);
  v57 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v57 )
    goto LABEL_120;
  LODWORD(v2) = v57;
  if ( v57 != -107 )
    goto LABEL_125;
  usleep_range_state(1000, 1005, 2);
  v58 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v58 )
    goto LABEL_120;
  LODWORD(v2) = v58;
  if ( v58 != -107 )
  {
    v56 = 2000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v59 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v59 )
    goto LABEL_120;
  LODWORD(v2) = v59;
  if ( v59 != -107 )
  {
    v56 = 3000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v60 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v60 )
    goto LABEL_120;
  LODWORD(v2) = v60;
  if ( v60 != -107 )
  {
    v56 = 4000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v61 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v61 )
    goto LABEL_120;
  LODWORD(v2) = v61;
  if ( v61 != -107 )
  {
    v56 = 5000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v62 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v62 )
    goto LABEL_120;
  LODWORD(v2) = v62;
  if ( v62 != -107 )
  {
    v56 = 6000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v63 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v63 )
  {
LABEL_120:
    LODWORD(v2) = 0;
    goto LABEL_123;
  }
  LODWORD(v2) = v63;
  if ( v63 != -107 )
  {
LABEL_135:
    v56 = 7000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v64 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v64 )
    goto LABEL_120;
  LODWORD(v2) = v64;
  if ( v64 != -107 )
  {
    v56 = 8000;
    goto LABEL_125;
  }
  usleep_range_state(1000, 1005, 2);
  v65 = i3c_device_do_priv_xfers(*(_QWORD *)(*(_QWORD *)(a1 + 8) + 8LL), v68, 1);
  if ( !v65 )
    goto LABEL_120;
  LODWORD(v2) = v65;
  if ( v65 == -107 )
    v56 = 10000;
  else
    v56 = 9000;
LABEL_125:
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x4000000000LL,
    1,
    "cam_qup_i3c_txdata",
    90,
    "Retry Failed i3c_write: rc = %d, us = %d",
    (_DWORD)v2,
    v56);
  if ( ((unsigned int)v2 & 0x80000000) != 0 )
LABEL_122:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i3c_write_burst",
      572,
      "failed rc: %d",
      (_DWORD)v2);
LABEL_123:
  kfree(v5);
LABEL_139:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v2;
}

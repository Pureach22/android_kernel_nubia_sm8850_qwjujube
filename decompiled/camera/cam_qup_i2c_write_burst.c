__int64 __fastcall cam_qup_i2c_write_burst(__int64 a1, __int64 *a2)
{
  __int64 v2; // x25
  unsigned __int64 v4; // x22
  _BYTE *v5; // x19
  int *v6; // x24
  _DWORD *v7; // x13
  int v8; // w20
  int v9; // w23
  int v10; // w9
  int v11; // w8
  __int64 v12; // x1
  unsigned int v13; // w20
  __int64 v14; // x8
  const char *v15; // x5
  __int64 v16; // x4
  unsigned int v17; // w8
  unsigned int v18; // w20
  const char *v19; // x14
  unsigned int *v20; // x24
  const char *v21; // x15
  const char *v22; // x28
  unsigned int v23; // w8
  __int64 v24; // x9
  int v25; // w27
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
  unsigned int v54; // w9
  __int64 v55; // x0
  int v56; // w0
  unsigned __int64 StatusReg; // x20
  __int64 v58; // x23
  __int64 v60; // [xsp+0h] [xbp-20h]
  _WORD v61[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE *v62; // [xsp+10h] [xbp-10h]
  __int64 v63; // [xsp+18h] [xbp-8h]

  v63 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !*(_QWORD *)(a1 + 8) )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_write_burst",
      469,
      "qup_client is NULL");
    v13 = -22;
    goto LABEL_104;
  }
  v2 = a1;
  v4 = (unsigned int)(*((_DWORD *)a2 + 3) + *((_DWORD *)a2 + 4) * *((_DWORD *)a2 + 2));
  v5 = (_BYTE *)_kmalloc_noprof(v4, 3520);
  if ( !v5 )
  {
LABEL_103:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_write_burst",
      478,
      "BUF is NULL");
    v13 = -12;
    goto LABEL_104;
  }
  while ( 1 )
  {
    v6 = (int *)*a2;
    v7 = &unk_393000;
    v8 = *((_DWORD *)a2 + 3);
    v9 = *((_DWORD *)a2 + 4);
    if ( (debug_mdl & 0x4000000000LL) != 0 && !debug_priority )
      break;
    if ( v8 <= 2 )
      goto LABEL_6;
LABEL_21:
    if ( v8 == 3 )
    {
      if ( v4 )
      {
        *v5 = *((_WORD *)v6 + 1);
        if ( v4 != 1 )
        {
          v60 = v2;
          v5[1] = BYTE1(*v6);
          if ( v4 != 2 )
          {
            v2 = 3;
            v5[2] = *v6;
            goto LABEL_33;
          }
        }
      }
    }
    else
    {
      if ( v8 != 4 )
      {
LABEL_28:
        v15 = "Invalid I2C addr type";
        v16 = 510;
LABEL_37:
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
          3,
          0x4000000000LL,
          1,
          "cam_qup_i2c_write_burst",
          v16,
          v15);
        v13 = -22;
        goto LABEL_99;
      }
      if ( v4 )
      {
        *v5 = *((_BYTE *)v6 + 3);
        if ( v4 != 1 )
        {
          v5[1] = *((_WORD *)v6 + 1);
          if ( v4 != 2 )
          {
            v60 = v2;
            v5[2] = BYTE1(*v6);
            if ( v4 >= 4 )
            {
              v2 = 4;
              v5[3] = *v6;
              goto LABEL_33;
            }
          }
        }
      }
    }
LABEL_102:
    __break(1u);
    StatusReg = _ReadStatusReg(SP_EL0);
    v58 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_qup_i2c_write_burst__alloc_tag;
    v4 = (unsigned int)(*((_DWORD *)a2 + 3) + *((_DWORD *)a2 + 4) * *((_DWORD *)a2 + 2));
    v5 = (_BYTE *)_kmalloc_noprof(v4, 3520);
    *(_QWORD *)(StatusReg + 80) = v58;
    if ( !v5 )
      goto LABEL_103;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    debug_mdl & 0x4000000000LL,
    4,
    "cam_qup_i2c_write_burst",
    487,
    "reg addr = 0x%x data type: %d",
    *v6,
    v9);
  v7 = &unk_393000;
  if ( v8 > 2 )
    goto LABEL_21;
LABEL_6:
  if ( v8 == 1 )
  {
    v60 = v2;
    if ( v4 )
    {
      v14 = debug_mdl;
      v2 = 1;
      *v5 = *(_BYTE *)v6;
      if ( (v14 & 0x4000000000LL) != 0 && !debug_priority )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          v14 & 0x4000000000LL,
          4,
          "cam_qup_i2c_write_burst",
          490,
          "byte %d: 0x%x",
          0);
        v7 = &unk_393000;
        v2 = 1;
      }
      goto LABEL_33;
    }
    goto LABEL_102;
  }
  if ( v8 != 2 )
    goto LABEL_28;
  if ( !v4 )
    goto LABEL_102;
  v10 = *v6;
  *v5 = BYTE1(*v6);
  if ( v4 == 1 )
    goto LABEL_102;
  v11 = debug_priority;
  v60 = v2;
  v12 = debug_mdl & 0x4000000000LL;
  v5[1] = *v6;
  if ( v12 && !v11 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      v12,
      4,
      "cam_qup_i2c_write_burst",
      495,
      "byte %d: 0x%x",
      0,
      BYTE1(v10));
    v11 = debug_priority;
    v7 = &unk_393000;
    v12 = debug_mdl & 0x4000000000LL;
    v2 = 2;
    if ( (debug_mdl & 0x4000000000LL) != 0 )
      goto LABEL_13;
  }
  else
  {
    v2 = 2;
    if ( v12 )
    {
LABEL_13:
      if ( !v11 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          v12,
          4,
          "cam_qup_i2c_write_burst",
          496,
          "byte %d: 0x%x",
          1,
          (unsigned __int8)v5[1]);
        v7 = &unk_393000;
        v2 = 2;
      }
    }
  }
LABEL_33:
  v17 = *((_DWORD *)a2 + 2);
  if ( v17 )
  {
    if ( (unsigned int)(v9 - 1) <= 3 )
    {
      v18 = 0;
      v19 = "cam_qup_i2c_write_burst";
      v20 = (unsigned int *)(v6 + 1);
      v21 = "Byte %d: 0x%x";
      while ( 1 )
      {
        v23 = *v20;
        switch ( v9 )
        {
          case 3:
            if ( v4 <= (unsigned __int16)v2 )
              goto LABEL_102;
            v35 = (unsigned __int16)v2 + 1LL;
            v5[(unsigned __int16)v2] = BYTE2(v23);
            if ( v4 <= v35 )
              goto LABEL_102;
            v36 = (unsigned __int16)v2 + 2LL;
            v5[v35] = BYTE1(*v20);
            if ( v4 <= v36 )
              goto LABEL_102;
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
                "cam_qup_i2c_write_burst",
                534,
                v21);
              v7 = &unk_393000;
              v21 = v49;
              v38 = debug_priority;
              v19 = "cam_qup_i2c_write_burst";
              v39 = debug_mdl & 0x4000000000LL;
              if ( (debug_mdl & 0x4000000000LL) != 0 )
                goto LABEL_62;
            }
            else if ( v39 )
            {
LABEL_62:
              if ( !v38 )
              {
                if ( v4 <= v35 )
                  goto LABEL_102;
                v50 = v21;
                ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
                  3,
                  v39,
                  4,
                  "cam_qup_i2c_write_burst",
                  536,
                  v21,
                  (unsigned int)v35,
                  (unsigned __int8)v5[v35]);
                v7 = &unk_393000;
                v21 = v50;
                v38 = debug_priority;
                v19 = "cam_qup_i2c_write_burst";
                v39 = debug_mdl & 0x4000000000LL;
              }
            }
            v25 = 3;
            if ( !v39 || v38 )
              goto LABEL_40;
            if ( v4 <= v36 )
              goto LABEL_102;
            goto LABEL_38;
          case 2:
            if ( v4 <= (unsigned __int16)v2 )
              goto LABEL_102;
            v29 = (unsigned __int16)v2 + 1LL;
            v5[(unsigned __int16)v2] = BYTE1(v23);
            if ( v4 <= v29 )
              goto LABEL_102;
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
                525,
                v21,
                (unsigned __int16)v2,
                BYTE1(v23));
              v7 = &unk_393000;
              v21 = v48;
              v31 = debug_priority;
              v19 = v47;
              v32 = debug_mdl & 0x4000000000LL;
              v25 = 2;
              if ( (debug_mdl & 0x4000000000LL) == 0 )
                goto LABEL_40;
            }
            else
            {
              v25 = 2;
              if ( !v32 )
                goto LABEL_40;
            }
            if ( v31 )
              goto LABEL_40;
            if ( v4 <= v29 )
              goto LABEL_102;
            v33 = v19;
            v34 = v21;
            ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
              3,
              v32,
              4,
              v19,
              527,
              v21,
              (unsigned int)v29,
              (unsigned __int8)v5[v29]);
            v21 = v34;
            v19 = v33;
            v25 = 2;
            goto LABEL_39;
          case 1:
            if ( v4 <= (unsigned __int16)v2 )
              goto LABEL_102;
            v24 = debug_mdl;
            v25 = 1;
            v5[(unsigned __int16)v2] = v23;
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
                519,
                v21,
                (unsigned __int16)v2,
                (unsigned __int8)v23);
              v21 = v27;
              v19 = v26;
              v7 = v28;
              v25 = 1;
            }
            goto LABEL_40;
        }
        if ( v4 <= (unsigned __int16)v2 )
          goto LABEL_102;
        v40 = HIBYTE(v23);
        v5[(unsigned __int16)v2] = HIBYTE(v23);
        v41 = (unsigned __int16)v2 + 1LL;
        if ( v4 <= v41 )
          goto LABEL_102;
        v42 = (unsigned __int16)v2 + 2LL;
        v5[v41] = *((_WORD *)v20 + 1);
        if ( v4 <= v42 )
          goto LABEL_102;
        v43 = (unsigned __int16)v2 + 3LL;
        v5[v42] = BYTE1(*v20);
        if ( v4 <= v43 )
          goto LABEL_102;
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
            "cam_qup_i2c_write_burst",
            546,
            "Byte %d: 0x%x",
            (unsigned __int16)v2,
            v40);
          v7 = &unk_393000;
          v21 = "Byte %d: 0x%x";
          v45 = debug_priority;
          v19 = "cam_qup_i2c_write_burst";
          v46 = debug_mdl & 0x4000000000LL;
          if ( (debug_mdl & 0x4000000000LL) != 0 )
          {
LABEL_74:
            if ( !v45 )
            {
              if ( v4 <= v41 )
                goto LABEL_102;
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                v46,
                4,
                "cam_qup_i2c_write_burst",
                548,
                "Byte %d: 0x%x",
                v41,
                (unsigned __int8)v5[v41]);
              v7 = &unk_393000;
              v21 = "Byte %d: 0x%x";
              v45 = debug_priority;
              v19 = "cam_qup_i2c_write_burst";
              v46 = debug_mdl & 0x4000000000LL;
            }
          }
        }
        else if ( v46 )
        {
          goto LABEL_74;
        }
        if ( !v46 || v45 )
        {
          v25 = 4;
          if ( !v46 )
            goto LABEL_40;
LABEL_78:
          if ( v45 )
            goto LABEL_40;
          if ( v4 <= v43 )
            goto LABEL_102;
LABEL_38:
          v22 = v21;
          ((void (*)(void))cam_print_log)();
          v21 = v22;
          v19 = "cam_qup_i2c_write_burst";
LABEL_39:
          v7 = &unk_393000;
          goto LABEL_40;
        }
        if ( v4 <= v42 )
          goto LABEL_102;
        v51 = v21;
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, _QWORD))cam_print_log)(
          3,
          v46,
          4,
          "cam_qup_i2c_write_burst",
          550,
          v21,
          (unsigned int)v42,
          (unsigned __int8)v5[v42]);
        v7 = &unk_393000;
        v21 = v51;
        v45 = debug_priority;
        v19 = "cam_qup_i2c_write_burst";
        v25 = 4;
        if ( (debug_mdl & 0x4000000000LL) != 0 )
          goto LABEL_78;
LABEL_40:
        v17 = *((_DWORD *)a2 + 2);
        ++v18;
        v2 = (unsigned int)(v2 + v25);
        v20 += 4;
        if ( v18 >= v17 )
          goto LABEL_94;
      }
    }
    v15 = "Invalid Data Type";
    v16 = 555;
    goto LABEL_37;
  }
LABEL_94:
  v52 = *((_DWORD *)a2 + 3) + *((_DWORD *)a2 + 4) * v17;
  if ( v52 >= (unsigned __int16)v2 )
  {
    v53 = **(_QWORD **)(v60 + 8);
    v54 = *(unsigned __int16 *)(v53 + 2);
    v55 = *(_QWORD *)(v53 + 24);
    v61[1] = 0;
    v61[2] = v2;
    v61[3] = 0;
    v62 = v5;
    v61[0] = v54 >> 1;
    v56 = i2c_transfer(v55, v61, 1);
    if ( v56 == 1 )
    {
      v13 = 0;
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i2c_txdata",
        89,
        "i2c transfer failed, i2c_msg_size:%d rc:%d",
        1,
        v56);
      v13 = -5;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x4000000000LL,
        1,
        "cam_qup_i2c_write_burst",
        573,
        "failed rc: %d",
        -5);
    }
  }
  else
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_qup_i2c_write_burst",
      566,
      "Invalid Length: %u | Expected length: %u",
      (unsigned __int16)v2,
      v52);
    v13 = -22;
  }
LABEL_99:
  kfree(v5);
LABEL_104:
  _ReadStatusReg(SP_EL0);
  return v13;
}

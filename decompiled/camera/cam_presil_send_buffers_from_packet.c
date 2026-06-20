__int64 __fastcall cam_presil_send_buffers_from_packet(unsigned int *a1, int a2, int a3)
{
  unsigned int v4; // w8
  unsigned int v5; // w22
  int v6; // w26
  __int64 v7; // x24
  int *v8; // x25
  int v9; // w6
  int v10; // w27
  int v11; // w6
  int v12; // w6
  __int64 v13; // x8
  int *v14; // x9
  int v15; // t1
  __int64 v16; // x8
  int *v17; // x9
  int v18; // t1
  __int64 v19; // x8
  int *v20; // x9
  int v21; // t1
  const char *v22; // x3
  const char *v23; // x5
  __int64 v24; // x1
  __int64 v25; // x4
  __int64 result; // x0
  unsigned __int64 v27; // x22
  unsigned int v28; // w25
  unsigned int v29; // w0
  int v30; // w27
  int v31; // w21
  __int64 v32; // x23
  int *v33; // x19
  unsigned int v34; // w7
  unsigned int v35; // w9
  int v36; // w8
  __int64 v38; // x9
  int *v39; // x10
  int v40; // t1
  int v41; // w8
  __int64 v42; // x26
  int v43; // w23
  __int64 v44; // x19
  int v45; // w8
  __int64 v46; // x9
  int *v47; // x10
  int v48; // t1
  unsigned int v49; // w19
  __int64 v50; // x4
  __int64 v51; // x6
  __int64 v52; // x7
  unsigned __int64 v53; // x20
  unsigned int v54; // w23
  unsigned int v55; // w0
  _QWORD v57[25]; // [xsp+20h] [xbp-1A0h] BYREF
  _QWORD v58[27]; // [xsp+E8h] [xbp-D8h] BYREF

  v58[25] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v58, 0, 200);
  memset(v57, 0, sizeof(v57));
  if ( !a1 )
  {
    v22 = "cam_presil_send_buffers_from_packet";
    v23 = "Packet is NULL";
    v24 = 0x8000000;
    v25 = 873;
LABEL_50:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      v24,
      1,
      v22,
      v25,
      v23);
    result = 4294967274LL;
    goto LABEL_117;
  }
  if ( a2 == -1 || (v4 = a1[9]) == 0 )
  {
LABEL_62:
    if ( a3 != -1 )
    {
      if ( a1[7] )
      {
        v30 = 0;
        v31 = 0;
        v32 = (__int64)a1 + a1[6] + 56;
        while ( 1 )
        {
          v33 = (int *)(v32 + 24LL * v30);
          if ( !v33 )
          {
            v22 = "cam_packet_util_validate_cmd_desc";
            v23 = "Invalid cmd desc";
            v24 = 0x20000;
            v25 = 41;
            goto LABEL_50;
          }
          v35 = v33[2];
          v34 = v33[3];
          v36 = *v33;
          if ( v34 > v35 || v36 <= 0 )
            break;
          if ( (debug_mdl & 0x8000000) == 0
            || debug_priority
            || (((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x8000000,
                  4,
                  "cam_presil_send_buffers_from_packet",
                  923,
                  "Adding CMD buffer:%d",
                  v36),
                (v36 = *v33) != 0) )
          {
            if ( v31 > 49 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x8000000,
                1,
                "cam_presil_add_unique_buf_hdl_to_list",
                846,
                "Failed to add entry num_hdls: %d max_handles:%d",
                v31,
                50);
            }
            else if ( v31 < 1 )
            {
LABEL_79:
              if ( (unsigned __int64)(4LL * v31) > 0xC8 )
                goto LABEL_119;
              *((_DWORD *)v57 + v31++) = v36;
            }
            else
            {
              v38 = (unsigned int)v31;
              v39 = (int *)v57;
              while ( 1 )
              {
                v40 = *v39++;
                if ( v40 == v36 )
                  break;
                if ( !--v38 )
                  goto LABEL_79;
              }
            }
          }
          if ( ++v30 >= a1[7] )
            goto LABEL_84;
        }
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x20000,
          1,
          "cam_packet_util_validate_cmd_desc",
          49,
          "invalid cmd arg %d %d %d %d",
          v33[1],
          v34,
          v36,
          v35);
        result = 4294967274LL;
        goto LABEL_117;
      }
      v31 = 0;
LABEL_84:
      if ( a1[11] )
      {
        v41 = 0;
        v42 = (__int64)a1 + a1[10] + 56;
        do
        {
          v43 = v41;
          v44 = v42 + 16LL * v41;
          if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x8000000,
              4,
              "cam_presil_send_buffers_from_packet",
              932,
              "Adding Patch src buffer:%d",
              *(_DWORD *)(v44 + 8));
            v45 = *(_DWORD *)(v44 + 8);
            if ( !v45 )
              goto LABEL_87;
          }
          else
          {
            v45 = *(_DWORD *)(v44 + 8);
            if ( !v45 )
              goto LABEL_87;
          }
          if ( v31 > 49 )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              0x8000000,
              1,
              "cam_presil_add_unique_buf_hdl_to_list",
              846,
              "Failed to add entry num_hdls: %d max_handles:%d",
              v31,
              50);
          }
          else if ( v31 < 1 )
          {
LABEL_96:
            if ( (unsigned __int64)(4LL * v31) > 0xC8 )
              goto LABEL_119;
            *((_DWORD *)v57 + v31++) = v45;
          }
          else
          {
            v46 = (unsigned int)v31;
            v47 = (int *)v57;
            while ( 1 )
            {
              v48 = *v47++;
              if ( v48 == v45 )
                break;
              if ( !--v46 )
                goto LABEL_96;
            }
          }
LABEL_87:
          v41 = v43 + 1;
        }
        while ( v43 + 1 < a1[11] );
      }
      if ( v31 >= 1 )
      {
        v53 = 0;
        while ( 1 )
        {
          if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
          {
            if ( v53 > 0x31 )
              goto LABEL_118;
            v54 = *((_DWORD *)v57 + v53);
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x8000000,
              4,
              "cam_presil_send_buffers_from_packet",
              939,
              "Sending Command buffer i:%d mem_handle:%d",
              v53,
              v54);
          }
          else
          {
            if ( v53 > 0x31 )
              goto LABEL_118;
            v54 = *((_DWORD *)v57 + v53);
          }
          v55 = cam_mem_mgr_send_buffer_to_presil();
          if ( v55 )
            break;
          if ( v31 == ++v53 )
            goto LABEL_112;
        }
        v49 = v55;
        v50 = 944;
        v51 = (unsigned int)v53;
        v52 = v54;
        goto LABEL_116;
      }
    }
LABEL_112:
    result = 0;
    goto LABEL_117;
  }
  v5 = 0;
  v6 = 0;
  v7 = (__int64)a1 + a1[8] + 56;
  do
  {
    v8 = (int *)(v7 + ((__int64)(int)v5 << 8));
    if ( v8[56] != 2 )
    {
      v9 = *v8;
      if ( !*v8 )
      {
LABEL_5:
        v4 = a1[9];
        goto LABEL_6;
      }
      if ( (debug_mdl & 0x8000000) == 0
        || debug_priority
        || (((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x8000000,
              4,
              "cam_presil_send_buffers_from_packet",
              892,
              "Adding IO CFG buffer:%d",
              v9),
            (v9 = *v8) != 0) )
      {
        if ( v6 <= 49 )
        {
          if ( v6 < 1 )
          {
LABEL_24:
            if ( (unsigned __int64)(4LL * v6) > 0xC8 )
              goto LABEL_119;
            v10 = v6 + 1;
            *((_DWORD *)v58 + v6) = v9;
            v11 = v8[1];
            if ( v11 )
            {
LABEL_14:
              if ( (debug_mdl & 0x8000000) == 0
                || debug_priority
                || (((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x8000000,
                      4,
                      "cam_presil_send_buffers_from_packet",
                      892,
                      "Adding IO CFG buffer:%d",
                      v11),
                    (v11 = v8[1]) != 0) )
              {
                if ( v10 <= 49 )
                {
                  if ( v10 < 1 )
                  {
LABEL_31:
                    if ( (unsigned __int64)(4LL * v10) > 0xC8 )
                      goto LABEL_119;
                    v6 = v10 + 1;
                    *((_DWORD *)v58 + v10) = v11;
                    v12 = v8[2];
                    if ( !v12 )
                      goto LABEL_5;
                    goto LABEL_33;
                  }
                  v16 = (unsigned int)v10;
                  v17 = (int *)v58;
                  while ( 1 )
                  {
                    v18 = *v17++;
                    if ( v18 == v11 )
                      break;
                    if ( !--v16 )
                      goto LABEL_31;
                  }
                }
                else
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x8000000,
                    1,
                    "cam_presil_add_unique_buf_hdl_to_list",
                    846,
                    "Failed to add entry num_hdls: %d max_handles:%d",
                    v10,
                    50);
                }
              }
              v6 = v10;
              v12 = v8[2];
              if ( !v12 )
                goto LABEL_5;
LABEL_33:
              if ( (debug_mdl & 0x8000000) == 0
                || debug_priority
                || (((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                      3,
                      debug_mdl & 0x8000000,
                      4,
                      "cam_presil_send_buffers_from_packet",
                      892,
                      "Adding IO CFG buffer:%d",
                      v12),
                    (v12 = v8[2]) != 0) )
              {
                if ( v6 <= 49 )
                {
                  if ( v6 < 1 )
                  {
LABEL_41:
                    if ( (unsigned __int64)(4LL * v6) > 0xC8 )
                      goto LABEL_119;
                    *((_DWORD *)v58 + v6++) = v12;
                  }
                  else
                  {
                    v19 = (unsigned int)v6;
                    v20 = (int *)v58;
                    while ( 1 )
                    {
                      v21 = *v20++;
                      if ( v21 == v12 )
                        break;
                      if ( !--v19 )
                        goto LABEL_41;
                    }
                  }
                }
                else
                {
                  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                    3,
                    0x8000000,
                    1,
                    "cam_presil_add_unique_buf_hdl_to_list",
                    846,
                    "Failed to add entry num_hdls: %d max_handles:%d",
                    v6,
                    50);
                }
              }
              goto LABEL_5;
            }
            goto LABEL_26;
          }
          v13 = (unsigned int)v6;
          v14 = (int *)v58;
          while ( 1 )
          {
            v15 = *v14++;
            if ( v15 == v9 )
              break;
            if ( !--v13 )
              goto LABEL_24;
          }
        }
        else
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x8000000,
            1,
            "cam_presil_add_unique_buf_hdl_to_list",
            846,
            "Failed to add entry num_hdls: %d max_handles:%d",
            v6,
            50);
        }
      }
      v10 = v6;
      v11 = v8[1];
      if ( v11 )
        goto LABEL_14;
LABEL_26:
      v6 = v10;
      goto LABEL_5;
    }
LABEL_6:
    ++v5;
  }
  while ( v5 < v4 );
  if ( v6 < 1 )
    goto LABEL_62;
  v27 = 0;
  while ( 1 )
  {
    if ( (debug_mdl & 0x8000000) != 0 && !debug_priority )
    {
      if ( v27 > 0x31 )
      {
LABEL_118:
        __break(0x5512u);
LABEL_119:
        __break(1u);
      }
      v28 = *((_DWORD *)v58 + v27);
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 0x8000000,
        4,
        "cam_presil_send_buffers_from_packet",
        900,
        "Sending Image buffer i:%d mem_handle:%d",
        v27,
        v28);
    }
    else
    {
      if ( v27 > 0x31 )
        goto LABEL_118;
      v28 = *((_DWORD *)v58 + v27);
    }
    v29 = cam_mem_mgr_send_buffer_to_presil();
    if ( v29 )
      break;
    if ( v6 == ++v27 )
      goto LABEL_62;
  }
  v49 = v29;
  v50 = 905;
  v51 = (unsigned int)v27;
  v52 = v28;
LABEL_116:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
    3,
    0x8000000,
    1,
    "cam_presil_send_buffers_from_packet",
    v50,
    "Failed to send buffer i:%d mem_handle:%d rc:%d",
    v51,
    v52,
    v49);
  result = v49;
LABEL_117:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall hfi_read_message(unsigned int a1, char *a2, unsigned __int8 a3, unsigned __int64 a4, _DWORD *a5)
{
  __int64 v6; // x24
  int v7; // w22
  unsigned __int64 v9; // x23
  char *v10; // x20
  _DWORD *v11; // x26
  __int64 v12; // x25
  unsigned int v13; // w20
  __int64 v15; // x0
  int v16; // w7
  int v17; // w8
  __int64 v18; // x22
  _DWORD *v19; // x27
  __int64 v20; // x8
  __int64 v21; // x22
  bool v22; // zf
  __int64 v23; // x28
  __int64 v24; // x21
  unsigned int v25; // w8
  unsigned __int64 v26; // x9
  unsigned __int64 v27; // x10
  int v28; // w11
  __int64 v29; // x10
  __int64 v30; // x8
  __int64 v31; // x9
  char *v32; // x21
  __int64 v33; // x10
  __int64 v34; // x11
  char *v35; // x1
  char *v36; // x0
  unsigned int v37; // w9
  int v38; // w20
  int v39; // w19
  int v40; // w22
  char *v41; // x23
  unsigned int *v42; // x23
  unsigned int v43; // w11
  unsigned int v44; // w12
  int v45; // w19
  unsigned int v46; // w22
  unsigned int v47; // w21
  __int64 v48; // [xsp+28h] [xbp-18h]
  int v49; // [xsp+34h] [xbp-Ch]
  unsigned int *v50; // [xsp+38h] [xbp-8h]

  if ( a1 >= 2 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      82,
      "Invalid HFI index: %u from hdl:%d",
      a1,
      a1);
    v13 = -22;
LABEL_9:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_read_message",
      395,
      "Failed to get hfi info rc: %d for hdl:%d",
      v13,
      a1);
    return v13;
  }
  v6 = *(_QWORD *)&g_hfi[2 * a1 + 2];
  if ( !v6 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v13 = -19;
    goto LABEL_9;
  }
  if ( a2 )
  {
    v7 = a3;
    if ( a3 == 1 )
    {
      v9 = a4;
      v10 = a2;
      v11 = a5;
      v12 = 880;
    }
    else
    {
      if ( a3 != 2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000,
          1,
          "hfi_read_message",
          413,
          "Invalid q_id: %u for read",
          a3);
        return (unsigned int)-22;
      }
      v9 = a4;
      v10 = a2;
      v11 = a5;
      v12 = 928;
    }
    v15 = mutex_lock(v6 + v12);
    v16 = *(unsigned __int8 *)(v6 + 976);
    v17 = *(unsigned __int8 *)(v6 + 1037);
    if ( v16 == 2 && (v17 & 1) != 0 )
    {
      v18 = *(_QWORD *)(v6 + 8);
      v19 = (_DWORD *)(v18 + 956LL * a3 + 24);
      if ( (cam_presil_mode_enabled(v15) & 1) != 0 )
      {
        v20 = 88;
        if ( a3 == 1 )
          v20 = 64;
        v21 = *(unsigned int *)(v6 + v20);
        v49 = *(_DWORD *)(v6 + 16) + 956 * a3 + 24;
        v50 = v19 + 223;
        cam_presil_retrieve_buffer(0, 0, 0, 4, (unsigned int)(v49 + 892), v19 + 223, 1);
        v22 = a3 == 1;
        v48 = v21;
        v23 = (unsigned int)(4 * v19[207]);
        v24 = (unsigned int)(4 * v19[223]);
        v25 = v23 + v21;
        if ( v22 )
        {
          v26 = v9;
          if ( (unsigned int)v24 < (unsigned int)v23 )
          {
            v27 = v23 - v24;
            v28 = 2048;
LABEL_33:
            LODWORD(v27) = v28 - (v27 >> 2);
LABEL_50:
            v42 = v19 + 207;
            if ( !(_DWORD)v27 )
            {
              v13 = -42;
              if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
                ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                  3,
                  debug_mdl & 0x40000,
                  4,
                  "hfi_read_message",
                  526,
                  "[%s] hfi hdl: %d Q is empty, state:%u, r idx:%u, w idx:%u",
                  (const char *)(v6 + 1004),
                  a1,
                  *(unsigned __int8 *)(v6 + 976),
                  *v42,
                  *v50);
              goto LABEL_23;
            }
            v43 = v19[63];
            if ( (unsigned int)v27 > v43 )
            {
              ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                3,
                0x40000,
                1,
                "hfi_read_message",
                532,
                "[%s] Invalid HFI message packet size - 0x%08x hfi hdl:%d",
                (const char *)(v6 + 1004),
                4 * v27,
                a1);
              v13 = -5;
              *v42 = *v50;
              goto LABEL_23;
            }
            v44 = *v42;
            if ( (unsigned int)v27 <= v26 )
              v45 = v27;
            else
              v45 = v26;
            v46 = v44 + v45;
            v47 = v44 + v45 - v43;
            if ( v44 + v45 >= v43 )
            {
              cam_presil_retrieve_buffer(0, 0, 0, 16 * (v43 - v44), v25, v10, 1);
              cam_presil_retrieve_buffer(0, 0, 0, 4 * v47, v48, &v10[4 * (v45 - v47)], 1);
              v46 = v47;
            }
            else
            {
              cam_presil_retrieve_buffer(0, 0, 0, (unsigned int)(4 * v45), v25, v10, 1);
            }
            *v42 = v46;
            *v11 = v45;
            cam_presil_send_buffer(0, 0, 0, 4, (unsigned int)(v49 + 828), v19 + 207, 1);
LABEL_63:
            __dsb(0xEu);
            v13 = 0;
            goto LABEL_23;
          }
        }
        else
        {
          v26 = v9;
          if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
          {
            ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
              3,
              debug_mdl & 0x40000,
              4,
              "hfi_read_message",
              508,
              "DBG Q read_ptr: 0x%08x write_ptr: 0x%08x",
              v23 + v21,
              v24 + v21);
            v26 = v9;
            v25 = v23 + v21;
            if ( (unsigned int)v24 < (unsigned int)v23 )
              goto LABEL_32;
          }
          else if ( (unsigned int)v24 < (unsigned int)v23 )
          {
LABEL_32:
            v27 = v23 - v24;
            v28 = 25600;
            goto LABEL_33;
          }
        }
        v27 = (unsigned __int64)(v24 - v23) >> 2;
        goto LABEL_50;
      }
      v29 = 80;
      v30 = *(unsigned int *)(v18 + 956LL * a3 + 852);
      v31 = *(unsigned int *)(v18 + 956LL * a3 + 916);
      if ( a3 == 1 )
        v29 = 56;
      v32 = *(char **)(v6 + v29);
      v33 = 4 * v30;
      v34 = 4 * v31;
      v35 = &v32[4 * v30];
      if ( &v32[4 * v31] >= v35 )
        v33 = (unsigned __int64)(v34 - v33) >> 2;
      else
        LODWORD(v33) = v19[63] - ((unsigned __int64)(v33 - v34) >> 2);
      v36 = v10;
      if ( !(_DWORD)v33 )
      {
        v13 = -42;
        if ( (debug_mdl & 0x40000) != 0 && !debug_priority )
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            debug_mdl & 0x40000,
            4,
            "hfi_read_message",
            451,
            "[%s] hfi hdl: %d Q is empty, state:%u, r idx:%u, w idx:%u",
            (const char *)(v6 + 1004),
            a1,
            *(unsigned __int8 *)(v6 + 976),
            v30,
            v31);
        goto LABEL_23;
      }
      v37 = v19[63];
      if ( (unsigned int)v33 <= v37 )
      {
        if ( (unsigned int)v33 <= v9 )
          v38 = v33;
        else
          v38 = v9;
        v39 = v38 + v30;
        v40 = v38 + v30 - v37;
        if ( v38 + (int)v30 >= v37 )
        {
          v41 = v36;
          memcpy(v36, v35, 4 * (v37 - (unsigned int)v30));
          memcpy(&v41[4 * (v38 - v40)], v32, (unsigned int)(4 * v40));
          v39 = v40;
        }
        else
        {
          memcpy(v36, v35, (unsigned int)(4 * v38));
        }
        v19[207] = v39;
        *v11 = v38;
        goto LABEL_63;
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000,
        1,
        "hfi_read_message",
        458,
        "[%s] Invalid HFI message packet size - 0x%08x hfi hdl:%d",
        (const char *)(v6 + 1004),
        4 * v33,
        a1);
      v13 = -5;
      v19[207] = v19[223];
    }
    else
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000,
        1,
        "hfi_read_message",
        422,
        "[%s] Invalid hfi state:%u msg q state: %u hfi hdl: %d q_id: %d",
        (const char *)(v6 + 1004),
        v16,
        v17,
        a1,
        v7);
      v13 = -19;
    }
LABEL_23:
    mutex_unlock(v6 + v12);
    return v13;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000,
    1,
    "hfi_read_message",
    401,
    "[%s] client hdl: %d Invalid msg",
    (const char *)(v6 + 1004),
    a1);
  return (unsigned int)-22;
}

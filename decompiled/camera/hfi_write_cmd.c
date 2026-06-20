__int64 __fastcall hfi_write_cmd(unsigned int a1, unsigned int *a2)
{
  __int64 v3; // x26
  __int64 v5; // x0
  int v6; // w7
  int v7; // w8
  _DWORD *v8; // x27
  char *v9; // x23
  int v10; // w28
  unsigned int v11; // w22
  unsigned int *v12; // x21
  unsigned int v13; // w8
  unsigned int v14; // w20
  __int64 v15; // x1
  __int64 v16; // x6
  __int64 v17; // x4
  unsigned int v19; // w8
  unsigned int v20; // w10
  __int64 v21; // x9
  unsigned int v22; // w7
  unsigned int v23; // w6
  unsigned int v24; // w10
  __int64 v25; // x11
  unsigned int v26; // w9
  unsigned int v27; // w10
  unsigned int v28; // w10
  unsigned int v29; // w24
  unsigned int v30; // w19
  char *v31; // x0
  unsigned int v32; // w9
  unsigned int v33; // w22
  char *v34; // x19
  unsigned int v35; // w10
  char *v36; // x0
  unsigned int v37; // w22
  size_t v38; // x24
  unsigned int v39; // w19
  size_t v40; // x20
  void (__fastcall *v41)(_QWORD); // x8
  __int64 v42; // x0
  unsigned int v43; // [xsp+1Ch] [xbp-4h]

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
    v14 = -22;
  }
  else
  {
    v3 = *(_QWORD *)&g_hfi[2 * a1 + 2];
    if ( v3 )
    {
      if ( !a2 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000,
          1,
          "hfi_write_cmd",
          231,
          "[%s] command is null for hfi hdl: %d",
          (const char *)(v3 + 1004),
          a1);
        return (unsigned int)-22;
      }
      v5 = mutex_lock(v3 + 832);
      v6 = *(unsigned __int8 *)(v3 + 976);
      v7 = *(unsigned __int8 *)(v3 + 1036);
      if ( v6 != 2 || (v7 & 1) == 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000,
          1,
          "hfi_write_cmd",
          240,
          "[%s] Invalid hfi state: %u cmd q state: %u hfi hdl: %d",
          (const char *)(v3 + 1004),
          v6,
          v7,
          a1);
        v14 = -19;
LABEL_15:
        mutex_unlock(v3 + 832);
        return v14;
      }
      v8 = *(_DWORD **)(v3 + 8);
      if ( (cam_presil_mode_enabled(v5) & 1) != 0 )
      {
        v9 = *(char **)(v3 + 32);
        v10 = *(_DWORD *)(v3 + 16);
        v11 = *(_DWORD *)(v3 + 40);
        v12 = v8 + 229;
        cam_presil_retrieve_buffer(0, 0, 0, 4, (unsigned int)(v10 + 852), v8 + 213, 1);
        cam_presil_retrieve_buffer(0, 0, 0, 4, (unsigned int)(v10 + 916), v8 + 229, 1);
        v13 = *a2;
        if ( *a2 <= 3 )
        {
          v14 = -22;
          if ( (debug_mdl & 0x40000) == 0 || debug_priority )
            goto LABEL_15;
          v15 = debug_mdl & 0x40000;
          v16 = v3 + 1004;
          v17 = 305;
          goto LABEL_22;
        }
        v20 = v8[213];
        v21 = *v12;
        v22 = v13 >> 2;
        if ( v20 <= (unsigned int)v21 )
          v23 = v20 - v21 + v8[69];
        else
          v23 = v20 - v21;
        if ( v23 <= v22 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000,
            1,
            "hfi_write_cmd",
            317,
            "failed: empty space %u, size_in_words %u",
            v23,
            v22);
          v14 = -5;
          goto LABEL_15;
        }
        v28 = v8[69];
        v29 = v21 + v22;
        v30 = v11 + 4 * v21;
        v31 = &v9[4 * v21];
        v32 = v21 + v22 - v28;
        if ( v29 >= v28 )
        {
          v43 = v30;
          v38 = v22 - v32;
          v39 = v32;
          memcpy(v31, a2, v38 * 4);
          cam_presil_send_buffer(0, 0, 0, (unsigned int)(v38 * 4), v43, a2, 1);
          memcpy(v9, &a2[v38], 4 * v39);
          cam_presil_send_buffer(0, 0, 0, 4 * v39, v11, &a2[v38], 1);
          v29 = v39;
        }
        else
        {
          v33 = v13 & 0xFFFFFFFC;
          memcpy(v31, a2, v13 & 0xFFFFFFFC);
          cam_presil_send_buffer(0, 0, 0, v33, v30, a2, 1);
        }
        *v12 = v29;
        cam_presil_send_buffer(0, 0, 0, 4, (unsigned int)(v10 + 916), v8 + 229, 1);
        cam_presil_send_buffer(0, 0, 0, *(unsigned int *)(v3 + 24), *(unsigned int *)(v3 + 32), v3 + 32, 1);
      }
      else
      {
        v19 = *a2;
        if ( *a2 <= 3 )
        {
          v14 = -22;
          if ( (debug_mdl & 0x40000) == 0 || debug_priority )
            goto LABEL_15;
          v15 = debug_mdl & 0x40000;
          v16 = v3 + 1004;
          v17 = 255;
LABEL_22:
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD))cam_print_log)(
            3,
            v15,
            4,
            "hfi_write_cmd",
            v17,
            "[%s] hfi hdl: %u word size is NULL",
            v16,
            a1);
          goto LABEL_15;
        }
        v24 = v8[213];
        v25 = (unsigned int)v8[229];
        v26 = v19 >> 2;
        if ( v24 <= (unsigned int)v25 )
          v27 = v24 - v25 + v8[69];
        else
          v27 = v24 - v25;
        if ( v27 <= v26 )
        {
          ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
            3,
            0x40000,
            1,
            "hfi_write_cmd",
            267,
            "[%s] hfi hdl: %u failed: empty space %u, size_in_words %u",
            (const char *)(v3 + 1004),
            a1,
            v27,
            v26);
          v14 = -5;
          goto LABEL_15;
        }
        v34 = *(char **)(v3 + 32);
        v35 = v8[69];
        v29 = v25 + v26;
        v36 = &v34[4 * v25];
        v37 = v25 + v26 - v35;
        if ( (unsigned int)v25 + v26 >= v35 )
        {
          v40 = v35 - (unsigned int)v25;
          memcpy(v36, a2, v40 * 4);
          memcpy(v34, &a2[v40], 4 * v37);
          v29 = v37;
        }
        else
        {
          memcpy(v36, a2, v19 & 0xFFFFFFFC);
        }
      }
      __dsb(0xEu);
      v8[229] = v29;
      __dsb(0xEu);
      v41 = *(void (__fastcall **)(_QWORD))(v3 + 288);
      if ( v41 )
      {
        v42 = *(_QWORD *)(v3 + 984);
        if ( *((_DWORD *)v41 - 1) != 251140989 )
          __break(0x8228u);
        v41(v42);
      }
      __dsb(0xEu);
      v14 = 0;
      goto LABEL_15;
    }
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "hfi_get_client_info",
      89,
      "[%s] HFI interface not setup for client hdl: %d",
      byte_3EC,
      a1);
    v14 = -19;
  }
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x40000,
    1,
    "hfi_write_cmd",
    225,
    "Failed to get hfi info rc: %d for hdl: %d",
    v14,
    a1);
  return v14;
}

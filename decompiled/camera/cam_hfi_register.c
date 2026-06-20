__int64 __fastcall cam_hfi_register(int *a1, __int64 *a2)
{
  __int64 v4; // x7
  __int64 v5; // x8
  unsigned int v6; // w19
  int v7; // w21
  __int64 v8; // x0
  _QWORD *v9; // x19
  int v11; // w10
  __int64 v12; // x19
  __int64 v13; // x8
  __int64 v14; // x11
  __int64 v15; // x12

  if ( a1 )
  {
    mutex_lock(&g_hfi_lock);
    v4 = (unsigned int)*a1;
    if ( (int)v4 <= 1 )
    {
      if ( (unsigned int)v4 >= 2 )
      {
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
          3,
          0x40000,
          1,
          "hfi_get_client_info",
          82,
          "Invalid HFI index: %u from hdl:%d",
          (unsigned int)v4);
      }
      else
      {
        v5 = *(_QWORD *)&g_hfi[2 * v4 + 2];
        if ( v5 )
        {
          ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
            3,
            0x40000,
            1,
            "cam_hfi_register",
            1398,
            "[%s] HFI client handle:%d is already established",
            v5 + 1004);
LABEL_22:
          v6 = -22;
          goto LABEL_23;
        }
        ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
          3,
          0x40000,
          1,
          "hfi_get_client_info",
          89,
          "[%s] HFI interface not setup for client hdl: %d",
          1004);
      }
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        0x40000,
        1,
        "cam_hfi_register",
        1392,
        "Unable to retrieve existing hfi info for handle:%d",
        *a1);
      goto LABEL_22;
    }
    if ( qword_3A8C78 )
    {
      if ( qword_3A8C80 )
      {
        v6 = -87;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          0x40000,
          1,
          "cam_hfi_register",
          1405,
          "No available hfi slots rc:%d",
          -87);
LABEL_23:
        mutex_unlock(&g_hfi_lock);
        return v6;
      }
      v7 = 1;
    }
    else
    {
      v7 = 0;
    }
    if ( mem_trace_en == 1 )
    {
      v8 = cam_mem_trace_alloc(1040, 0xCC0u, 0, "cam_hfi_register", 0x581u);
      if ( !v8 )
        goto LABEL_27;
    }
    else
    {
      v8 = _kvmalloc_node_noprof(1040, 0, 3520, 0xFFFFFFFFLL);
      if ( !v8 )
      {
LABEL_27:
        v6 = -12;
        goto LABEL_23;
      }
    }
    if ( !*(_BYTE *)(v8 + 976) )
    {
      v11 = g_hfi[0];
      *(_QWORD *)&g_hfi[2 * v7 + 2] = v8;
      g_hfi[0] = v11 + 1;
      *a1 = v7;
      v12 = v8;
      v13 = a2[3];
      v14 = *a2;
      v15 = a2[1];
      *(_QWORD *)(v8 + 1020) = a2[2];
      *(_QWORD *)(v8 + 1028) = v13;
      *(_QWORD *)(v8 + 1004) = v14;
      *(_QWORD *)(v8 + 1012) = v15;
      mutex_unlock(&g_hfi_lock);
      _mutex_init(v12 + 832, "&hfi->cmd_q_lock", &cam_hfi_register___key);
      _mutex_init(v12 + 880, "&hfi->msg_q_lock", &cam_hfi_register___key_73);
      _mutex_init(v12 + 928, "&hfi->dbg_q_lock", &cam_hfi_register___key_75);
      return 0;
    }
    v9 = (_QWORD *)v8;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x40000,
      1,
      "cam_hfi_register",
      1417,
      "hfi_init: invalid state: %u hfi idx: %u",
      *(unsigned __int8 *)(v8 + 976),
      v7);
    if ( (mem_trace_en & 1) != 0 )
      cam_mem_trace_free(v9, 0);
    else
      kvfree(v9);
    goto LABEL_22;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    0x40000,
    1,
    "cam_hfi_register",
    1383,
    "Client handle is NULL");
  return (unsigned int)-22;
}

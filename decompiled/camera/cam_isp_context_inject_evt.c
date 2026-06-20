__int64 __fastcall cam_isp_context_inject_evt(__int64 a1, unsigned __int8 *a2)
{
  int v2; // w6
  int v3; // w6
  __int64 v4; // x21
  __int64 v5; // x19
  unsigned int v6; // w7
  unsigned __int8 *v7; // x22
  __int64 v8; // x9
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 result; // x0
  const char *v12; // x6
  const char *v13; // x7
  _DWORD *v14; // x20
  unsigned int v15; // w0
  unsigned int is_cb_non_fatal_fault_en; // w0
  unsigned int v17; // w19
  const char *v18; // x5
  __int64 v19; // x4
  _BYTE v20[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v2 = *a2;
    if ( v2 != 1 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_context_inject_evt",
        10497,
        "Bufdone err injection %u not supported by ISP,ctx:%u link:0x%x",
        v2,
        *(_DWORD *)(a1 + 32),
        *(_DWORD *)(a1 + 64));
      result = 4294967274LL;
      goto LABEL_23;
    }
    v3 = *((_DWORD *)a2 + 4);
    v4 = *(_QWORD *)(a1 + 256);
    v5 = *((_QWORD *)a2 + 1);
    if ( v3 == 6 )
    {
      v14 = (_DWORD *)a1;
      v15 = *(_DWORD *)(a1 + 512);
      v7 = a2;
      v20[0] = 0;
      is_cb_non_fatal_fault_en = cam_smmu_is_cb_non_fatal_fault_en(v15, v20);
      if ( is_cb_non_fatal_fault_en )
      {
        v17 = is_cb_non_fatal_fault_en;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_context_validate_event_notify_injection",
          10446,
          "Fail to query whether device's cb has non-fatal enabled rc:%d, ctx id: %u link: 0x%x",
          is_cb_non_fatal_fault_en,
          v14[8],
          v14[16]);
LABEL_22:
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_isp_context_inject_evt",
          10492,
          "Event notif injection failed validation rc:%d, ctx:%u link:0x%x",
          v17,
          v14[8],
          v14[16]);
        result = v17;
        goto LABEL_23;
      }
      if ( (v20[0] & 1) != 0 )
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_isp_context_validate_event_notify_injection",
          10460,
          "Inject PF evt: req_id:%llu ctx:%u link:0x%x dev hdl:%d ctx found:%hhu",
          v5,
          v14[8],
          v14[16],
          v14[15],
          v7[20]);
        goto LABEL_9;
      }
      v18 = "Fail to inject pagefault event notif. Pagefault fatal for ISP,ctx:%u link:0x%x";
      v19 = 10453;
    }
    else if ( v3 == 1 )
    {
      v6 = *((_DWORD *)a2 + 5);
      if ( v6 <= 7 && ((1 << v6) & 0xB8) != 0 )
      {
        v7 = a2;
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          3,
          "cam_isp_context_validate_event_notify_injection",
          10434,
          "Inject ERR evt: err code: %u err type: %u req id: %llu ctx id: %u link: 0x%x dev hdl: %d",
          *((_DWORD *)a2 + 6),
          v6,
          v5,
          *(_DWORD *)(a1 + 32),
          *(_DWORD *)(a1 + 64),
          *(_DWORD *)(a1 + 60));
LABEL_9:
        v8 = *((_QWORD *)v7 + 3);
        v9 = *(_QWORD *)v7;
        v10 = *((_QWORD *)v7 + 1);
        result = 0;
        *(_QWORD *)(v4 + 45640) = *((_QWORD *)v7 + 2);
        *(_QWORD *)(v4 + 45648) = v8;
        *(_QWORD *)(v4 + 45624) = v9;
        *(_QWORD *)(v4 + 45632) = v10;
        *(_BYTE *)(v4 + 45652) = 1;
        goto LABEL_23;
      }
      v14 = (_DWORD *)a1;
      v18 = "Invalid error type: %u for error event injection err type: %u req id: %llu ctx id: %u link: 0x%x dev hdl: %d";
      v19 = 10427;
    }
    else
    {
      v14 = (_DWORD *)a1;
      v18 = "Event notification type not supported: %u, ctx: %u link: 0x%x";
      v19 = 10465;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      8,
      1,
      "cam_isp_context_validate_event_notify_injection",
      v19,
      v18);
    v17 = -22;
    goto LABEL_22;
  }
  if ( a1 )
    v12 = "Non-NULL";
  else
    v12 = "NULL";
  if ( a2 )
    v13 = "Non-NULL";
  else
    v13 = "NULL";
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    8,
    1,
    "cam_isp_context_inject_evt",
    10482,
    "Invalid params ctx %s event args %s",
    v12,
    v13);
  result = 4294967274LL;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}

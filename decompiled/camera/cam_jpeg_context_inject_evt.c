__int64 __fastcall cam_jpeg_context_inject_evt(_DWORD *a1, __int64 a2)
{
  int v2; // w6
  __int64 v3; // x19
  int v4; // w6
  _DWORD *v5; // x22
  __int64 v6; // x20
  const char *v7; // x3
  const char *v8; // x5
  __int64 v9; // x4
  const char *v10; // x6
  const char *v11; // x7
  unsigned int v12; // w21
  void (__fastcall *v13)(__int64, __int64); // x8
  __int64 v14; // x0
  unsigned int v15; // w0
  unsigned int is_cb_non_fatal_fault_en; // w0
  _BYTE v18[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v19; // [xsp+28h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    if ( a1 )
      v10 = "Non-NULL";
    else
      v10 = "NULL";
    if ( a2 )
      v11 = "Non-NULL";
    else
      v11 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_context_inject_evt",
      272,
      "invalid params ctx %s event args %s",
      v10,
      v11);
    v12 = -22;
    goto LABEL_31;
  }
  if ( !*(_BYTE *)a2 )
  {
    v5 = a1;
    v6 = a2;
    v7 = "cam_jpeg_context_inject_evt";
    v8 = "Inject buffer sync error %u ctx id: %u req id %llu";
    v9 = 283;
    goto LABEL_16;
  }
  v2 = *(_DWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a2 + 8);
  if ( v2 == 6 )
  {
    v5 = a1;
    v15 = a1[128];
    v6 = a2;
    v18[0] = 0;
    is_cb_non_fatal_fault_en = cam_smmu_is_cb_non_fatal_fault_en(v15, v18);
    if ( is_cb_non_fatal_fault_en )
    {
      v12 = is_cb_non_fatal_fault_en;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_context_validate_event_notify_injection",
        239,
        "Fail to query whether device's cb has non-fatal enabled rc: %d",
        is_cb_non_fatal_fault_en);
LABEL_30:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        1,
        "cam_jpeg_context_inject_evt",
        293,
        "Event notification injection failed validation rc: %d",
        v12);
      goto LABEL_31;
    }
    if ( (v18[0] & 1) != 0 )
    {
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        512,
        3,
        "cam_jpeg_context_validate_event_notify_injection",
        251,
        "Inject PF evt: req_id: %llu ctx id: %u dev hdl: %d ctx found: %hhu",
        v3,
        v5[8],
        v5[15],
        *(unsigned __int8 *)(v6 + 20));
      goto LABEL_17;
    }
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_context_validate_event_notify_injection",
      245,
      "Fail to inject page fault event notification. Page fault is fatal for JPEG");
LABEL_29:
    v12 = -22;
    goto LABEL_30;
  }
  if ( v2 != 4 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_context_validate_event_notify_injection",
      255,
      "Event notification type not supported: %u",
      v2);
    goto LABEL_29;
  }
  v4 = *(_DWORD *)(a2 + 20);
  if ( v4 != 1 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      512,
      1,
      "cam_jpeg_context_validate_event_notify_injection",
      220,
      "Invalid event type %u for node event injection event cause: %u req id: %llu ctx id: %u dev hdl: %d",
      v4,
      *(_DWORD *)(a2 + 24),
      v3,
      a1[8],
      a1[15]);
    goto LABEL_29;
  }
  v5 = a1;
  v6 = a2;
  v7 = "cam_jpeg_context_validate_event_notify_injection";
  v8 = "Inject Node evt: event type: %u event cause: %u req id: %llu ctx id: %u dev hdl: %d";
  v9 = 227;
LABEL_16:
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
    3,
    512,
    3,
    v7,
    v9,
    v8);
LABEL_17:
  v13 = *(void (__fastcall **)(__int64, __int64))(*((_QWORD *)v5 + 26) + 152LL);
  if ( v13 )
  {
    v14 = *((_QWORD *)v5 + 33);
    if ( *((_DWORD *)v13 - 1) != -72220 )
      __break(0x8228u);
    v13(v14, v6);
  }
  v12 = 0;
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return v12;
}

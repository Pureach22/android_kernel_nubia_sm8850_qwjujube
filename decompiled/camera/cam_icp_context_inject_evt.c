__int64 __fastcall cam_icp_context_inject_evt(__int64 a1, __int64 a2)
{
  int v3; // w8
  __int64 v4; // x22
  __int64 v5; // x20
  const char *v6; // x6
  const char *v7; // x7
  void (__fastcall *v8)(__int64, __int64); // x8
  __int64 v9; // x0
  __int64 result; // x0
  unsigned int v11; // w0
  int is_cb_non_fatal_fault_en; // w0
  int v13; // w21
  __int64 v14; // x7
  const char *v15; // x5
  __int64 v16; // x4
  __int64 v17; // x6
  int v18; // [xsp+0h] [xbp-30h]
  int v19; // [xsp+8h] [xbp-28h]
  __int64 v20; // [xsp+10h] [xbp-20h]
  int v21; // [xsp+18h] [xbp-18h]
  _BYTE v22[4]; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    if ( a1 )
      v6 = "Non-NULL";
    else
      v6 = "NULL";
    if ( a2 )
      v7 = "Non-NULL";
    else
      v7 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_context_inject_evt",
      442,
      "invalid params ctx %s event args %s",
      v6,
      v7);
    goto LABEL_31;
  }
  if ( !*(_BYTE *)a2 )
  {
    v5 = a2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, _QWORD))cam_print_log)(
      3,
      256,
      3,
      "cam_icp_context_inject_evt",
      454,
      "[%s] ctx[%u]: Inject buffer sync error %u req id %llu",
      a1,
      *(unsigned int *)(a1 + 32),
      *(_DWORD *)(a2 + 16),
      *(_QWORD *)(a2 + 8));
    goto LABEL_17;
  }
  v3 = *(_DWORD *)(a2 + 16);
  v4 = *(_QWORD *)(a2 + 8);
  if ( v3 == 6 )
  {
    v11 = *(_DWORD *)(a1 + 512);
    v5 = a2;
    v22[0] = 0;
    is_cb_non_fatal_fault_en = cam_smmu_is_cb_non_fatal_fault_en(v11, v22);
    if ( is_cb_non_fatal_fault_en )
    {
      v13 = is_cb_non_fatal_fault_en;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_context_validate_event_notify_injection",
        406,
        "[%s] ctx[%u]: Fail to query whether device's cb has non-fatal enabled rc: %d",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        is_cb_non_fatal_fault_en);
LABEL_30:
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        256,
        1,
        "cam_icp_context_inject_evt",
        466,
        "[%s] ctx[%u]: Event notification injection failed validation rc: %d",
        (const char *)a1,
        *(_DWORD *)(a1 + 32),
        v13);
LABEL_31:
      result = 4294967274LL;
      goto LABEL_32;
    }
    v14 = *(unsigned int *)(a1 + 32);
    if ( (v22[0] & 1) != 0 )
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, __int64, _DWORD, _DWORD))cam_print_log)(
        3,
        256,
        3,
        "cam_icp_context_validate_event_notify_injection",
        420,
        "[%s] ctx[%u]: Inject PF evt: req_id: %llu dev hdl: %d ctx found: %hhu",
        a1,
        v14,
        v4,
        *(_DWORD *)(a1 + 60),
        *(unsigned __int8 *)(v5 + 20));
      goto LABEL_17;
    }
    v15 = "[%s] ctx[%u]: Fail to inject page fault event notification. Page fault is fatal for ICP";
    v16 = 413;
    v17 = a1;
LABEL_29:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, int, int, __int64, int))cam_print_log)(
      3,
      256,
      1,
      "cam_icp_context_validate_event_notify_injection",
      v16,
      v15,
      v17,
      v14,
      v18,
      v19,
      v20,
      v21);
    v13 = -22;
    goto LABEL_30;
  }
  if ( v3 != 1 )
  {
    v14 = *(unsigned int *)(a1 + 32);
    v15 = "[%s] ctx[%u]: Event notification type not supported: %u";
    v16 = 425;
LABEL_28:
    v17 = a1;
    v18 = v3;
    goto LABEL_29;
  }
  v3 = *(_DWORD *)(a2 + 20);
  if ( v3 != 3 && v3 != 5 )
  {
    v14 = *(unsigned int *)(a1 + 32);
    v20 = *(_QWORD *)(a2 + 8);
    v21 = *(_DWORD *)(a1 + 60);
    v15 = "[%s] ctx[%u]: Invalid error type: %u for error event injection err code: %u req id: %llu dev hdl: %d";
    v19 = *(_DWORD *)(a2 + 24);
    v16 = 387;
    goto LABEL_28;
  }
  v5 = a2;
  ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, _QWORD, _DWORD, _DWORD, __int64, _DWORD))cam_print_log)(
    3,
    256,
    3,
    "cam_icp_context_validate_event_notify_injection",
    394,
    "[%s] ctx[%u]: Inject ERR evt: err code: %u err type: %u req id: %llu dev hdl: %d",
    a1,
    *(unsigned int *)(a1 + 32),
    *(_DWORD *)(a2 + 24),
    *(_DWORD *)(a2 + 20),
    v4,
    *(_DWORD *)(a1 + 60));
LABEL_17:
  v8 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 208) + 152LL);
  if ( v8 )
  {
    v9 = *(_QWORD *)(a1 + 264);
    if ( *((_DWORD *)v8 - 1) != -72220 )
      __break(0x8228u);
    v8(v9, v5);
  }
  result = 0;
LABEL_32:
  _ReadStatusReg(SP_EL0);
  return result;
}

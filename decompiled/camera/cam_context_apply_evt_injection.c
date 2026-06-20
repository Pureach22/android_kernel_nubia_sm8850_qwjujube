__int64 __fastcall cam_context_apply_evt_injection(unsigned int *a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x8
  __int64 result; // x0
  __int64 v6; // x6
  __int64 v7; // x7
  const char *v8; // x3
  const char *v9; // x5
  unsigned int v10; // w19
  __int64 v11; // x4
  const char *v12; // x6
  const char *v13; // x7
  int v14; // w6
  unsigned int v16; // w8
  int v17; // w9
  unsigned int v18; // w10
  unsigned int v19; // w11
  unsigned int v20; // w8
  __int64 v21; // x8
  const char *v22; // x5
  __int64 v23; // x4
  unsigned int v25; // w11
  unsigned int v26; // w9
  unsigned int v27; // w10
  _QWORD v29[8]; // [xsp+10h] [xbp-100h] BYREF
  _QWORD *v30; // [xsp+50h] [xbp-C0h] BYREF
  __int64 v31; // [xsp+58h] [xbp-B8h]
  unsigned __int64 v32; // [xsp+60h] [xbp-B0h]
  __int64 v33; // [xsp+68h] [xbp-A8h]
  __int64 v34; // [xsp+70h] [xbp-A0h]
  __int64 v35; // [xsp+78h] [xbp-98h]
  __int64 v36; // [xsp+80h] [xbp-90h]
  __int64 v37; // [xsp+88h] [xbp-88h]
  __int64 v38; // [xsp+90h] [xbp-80h]
  __int64 v39; // [xsp+98h] [xbp-78h]
  __int64 v40; // [xsp+A0h] [xbp-70h]
  __int64 v41; // [xsp+A8h] [xbp-68h]
  __int64 v42; // [xsp+B0h] [xbp-60h]
  __int64 v43; // [xsp+B8h] [xbp-58h]
  __int64 v44; // [xsp+C0h] [xbp-50h]
  __int64 v45; // [xsp+C8h] [xbp-48h]
  __int64 v46; // [xsp+D0h] [xbp-40h]
  __int64 v47; // [xsp+D8h] [xbp-38h]
  __int64 v48; // [xsp+E0h] [xbp-30h]
  __int64 v49; // [xsp+E8h] [xbp-28h]
  __int64 v50; // [xsp+F0h] [xbp-20h]
  __int64 v51; // [xsp+F8h] [xbp-18h]
  __int64 v52; // [xsp+100h] [xbp-10h]
  __int64 v53; // [xsp+108h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
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
      0x80000,
      1,
      "cam_context_apply_evt_injection",
      2054,
      "Invalid parameters ctx %s inject evt args %s",
      v12,
      v13);
    goto LABEL_27;
  }
  v2 = *(_QWORD *)(a2 + 8);
  if ( *(_BYTE *)v2 == 1 )
  {
    v14 = *(_DWORD *)(v2 + 16);
    switch ( v14 )
    {
      case 6:
        v36 = 0;
        v37 = 0;
        v34 = 0;
        v35 = 0;
        v32 = 0;
        v33 = 0;
        v30 = v29;
        v31 = 0;
        memset(v29, 0, sizeof(v29));
        v35 = *(_QWORD *)(v2 + 8);
        LOBYTE(v36) = *(_BYTE *)(v2 + 20);
        result = cam_context_send_pf_evt((__int64)a1, (__int64 *)&v30);
        if ( !(_DWORD)result )
          goto LABEL_28;
        v6 = *(_QWORD *)(v2 + 8);
        v7 = a1[8];
        v8 = "cam_context_apply_pf_evt_injection";
        v9 = "Fail to apply Page Fault event injection with req id: %llu ctx id: %u rc: %d";
        v10 = result;
        v11 = 1989;
        goto LABEL_7;
      case 4:
        v36 = 0;
        v37 = 0;
        v34 = 0;
        v35 = 0;
        v32 = 0;
        v33 = 0;
        v30 = nullptr;
        v31 = 0;
        v33 = *(_QWORD *)(v2 + 8);
        v25 = a1[16];
        v26 = *(_DWORD *)(v2 + 20);
        v27 = *(_DWORD *)(v2 + 24);
        LODWORD(v31) = a1[15];
        HIDWORD(v31) = v25;
        v32 = __PAIR64__(v27, v26);
        LODWORD(v30) = a1[14];
        result = cam_req_mgr_notify_message((__int64 *)&v30, 1, 0x8000000);
        if ( !(_DWORD)result )
          goto LABEL_28;
        v6 = *(_QWORD *)(v2 + 8);
        v7 = a1[8];
        v8 = "cam_context_apply_node_event_injection";
        v9 = "Fail to apply error event injection with req id: %llu ctx id: %u rc: %d";
        v10 = result;
        v11 = 2014;
        goto LABEL_7;
      case 1:
        v36 = 0;
        v37 = 0;
        v34 = 0;
        v35 = 0;
        v32 = 0;
        v33 = 0;
        v16 = *(_DWORD *)(v2 + 20);
        v17 = *(_DWORD *)(v2 + 24);
        v19 = a1[14];
        v18 = a1[15];
        v30 = nullptr;
        v31 = v16;
        v20 = a1[16];
        LODWORD(v30) = v19;
        v32 = __PAIR64__(v20, v18);
        v21 = *(_QWORD *)(v2 + 8);
        HIDWORD(v33) = v17;
        HIDWORD(v31) = v21;
        result = cam_req_mgr_notify_message((__int64 *)&v30, 1, 0x8000000);
        if ( !(_DWORD)result )
          goto LABEL_28;
        v6 = *(_QWORD *)(v2 + 8);
        v7 = a1[8];
        v8 = "cam_context_apply_error_event_injection";
        v9 = "Fail to apply V4L2 Node event injection with req id: %llu ctx id: %u rc: %d";
        v10 = result;
        v11 = 2040;
        goto LABEL_7;
    }
    v22 = "Invalid notify type %u";
    v23 = 2078;
    goto LABEL_26;
  }
  if ( *(_BYTE *)v2 )
  {
    v22 = "Invalid inject id %u";
    v23 = 2082;
LABEL_26:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_apply_evt_injection",
      v23,
      v22);
LABEL_27:
    result = 4294967274LL;
    goto LABEL_28;
  }
  v51 = 0;
  v52 = 0;
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v41 = 0;
  v42 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v3 = *(_QWORD *)(v2 + 8);
  v30 = nullptr;
  v51 = v3;
  LODWORD(v3) = *(_DWORD *)(v2 + 16);
  LODWORD(v52) = v3;
  result = cam_context_buf_done_from_hw((__int64)a1, (__int64)&v30, 1);
  if ( (_DWORD)result )
  {
    v6 = v51;
    v7 = a1[8];
    v8 = "cam_context_apply_buf_done_err_injection";
    v9 = "Fail to apply buf done error injection with req id: %llu ctx id: %u rc: %d";
    v10 = result;
    v11 = 1969;
LABEL_7:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64, __int64, unsigned int))cam_print_log)(
      3,
      0x80000,
      1,
      v8,
      v11,
      v9,
      v6,
      v7,
      v10);
    result = v10;
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}

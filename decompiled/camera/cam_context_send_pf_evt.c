__int64 __fastcall cam_context_send_pf_evt(__int64 a1, __int64 *a2)
{
  __int64 v4; // x6
  __int64 v5; // x7
  __int64 v6; // x21
  unsigned int v7; // w9
  unsigned int v8; // w10
  int v9; // w11
  __int64 v10; // x7
  __int64 v11; // x7
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // x7
  int v15; // w8
  int v16; // w9
  unsigned int v17; // w10
  __int64 v18; // x8
  __int64 result; // x0
  int v20; // w19
  char *v21; // x6
  char *v22; // x7
  int v23; // w10
  int v24; // w8
  int v25; // w20
  char v26; // w21
  const char *v27; // x8
  char v28; // [xsp+0h] [xbp-270h]
  char v29; // [xsp+0h] [xbp-270h]
  unsigned __int64 v30; // [xsp+20h] [xbp-250h] BYREF
  char s[512]; // [xsp+28h] [xbp-248h] BYREF
  __int64 v32; // [xsp+228h] [xbp-48h] BYREF
  unsigned __int64 v33; // [xsp+230h] [xbp-40h]
  __int64 v34; // [xsp+238h] [xbp-38h]
  __int64 v35; // [xsp+240h] [xbp-30h]
  __int64 v36; // [xsp+248h] [xbp-28h]
  __int64 v37; // [xsp+250h] [xbp-20h]
  __int64 v38; // [xsp+258h] [xbp-18h]
  __int64 v39; // [xsp+260h] [xbp-10h]
  __int64 v40; // [xsp+268h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  memset(s, 0, sizeof(s));
  v30 = 0;
  if ( !a2 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x80000,
      1,
      "cam_context_send_pf_evt",
      1428,
      "Invalid input PF args");
    result = 4294967274LL;
    goto LABEL_26;
  }
  v6 = *a2;
  LOBYTE(v34) = 0;
  if ( !a1 )
  {
    cam_print_to_buffer((__int64)s, 0x200u, &v30, 1u, 0x80000u, "Faulted ctx NOT found", v4, v5, v28);
    v18 = *(_QWORD *)(v6 + 16);
    if ( v18 )
      goto LABEL_17;
LABEL_22:
    BYTE1(v34) = 0;
    goto LABEL_23;
  }
  v7 = *(_DWORD *)(a1 + 60);
  v8 = *(_DWORD *)(a1 + 64);
  v9 = *((_DWORD *)a2 + 3);
  v10 = *(unsigned int *)(a1 + 32);
  LODWORD(v32) = *(_DWORD *)(a1 + 56);
  v33 = __PAIR64__(v8, v7);
  HIDWORD(v35) = v9;
  cam_print_to_buffer(
    (__int64)s,
    0x200u,
    &v30,
    1u,
    0x80000u,
    "Faulted ctx: [%s][%d] session_hdl: 0x%x, device_hdl: 0x%x, link_hdl: 0x%x, port_id: 0x%x",
    a1,
    v10,
    v32);
  if ( !*((_DWORD *)a2 + 2) )
  {
    a1 = 0;
    LOBYTE(v34) = 0;
    v18 = *(_QWORD *)(v6 + 16);
    if ( v18 )
      goto LABEL_17;
    goto LABEL_22;
  }
  v11 = *((unsigned int *)a2 + 5);
  v12 = a2[3];
  v13 = a2[5];
  HIDWORD(v34) = *((_DWORD *)a2 + 4);
  LODWORD(v35) = v11;
  a1 = 1;
  v36 = v12;
  v37 = v13;
  cam_print_to_buffer(
    (__int64)s,
    0x200u,
    &v30,
    1u,
    0x80000u,
    "buf_hdl: 0x%x, offset: 0x%x, req_id: %llu, delta: 0x%llx",
    HIDWORD(v34),
    v11,
    v13);
  if ( *((_DWORD *)a2 + 2) != 2 )
  {
    LOBYTE(v34) = 1;
    v18 = *(_QWORD *)(v6 + 16);
    if ( v18 )
      goto LABEL_17;
    goto LABEL_22;
  }
  v16 = *((_DWORD *)a2 + 8);
  v15 = *((_DWORD *)a2 + 9);
  if ( (v15 & 0x800) != 0 )
    v17 = 4;
  else
    v17 = 2;
  if ( (v15 & 0x40) != 0 )
    a1 = 3;
  else
    a1 = v17;
  BYTE3(v34) = v16;
  LOBYTE(v34) = a1;
  cam_print_to_buffer(
    (__int64)s,
    0x200u,
    &v30,
    1u,
    0x80000u,
    "Faulted patch found in patch index: %u",
    (unsigned __int8)v16,
    v14,
    v29);
  v18 = *(_QWORD *)(v6 + 16);
  if ( !v18 )
    goto LABEL_22;
LABEL_17:
  if ( *(_BYTE *)(v6 + 57) == 1 )
    v18 = 2;
  else
    v18 = 1;
  BYTE1(v34) = v18;
LABEL_23:
  v20 = *(_DWORD *)(v6 + 44);
  v21 = off_449BB8[a1];
  LOBYTE(v38) = v20;
  v22 = off_449BE0[v18];
  v23 = *(unsigned __int8 *)(v6 + 56);
  v25 = *(_DWORD *)(v6 + 48);
  v24 = *(_DWORD *)(v6 + 52);
  v26 = v24;
  WORD1(v38) = v24;
  v27 = "PF Stage: stage 2 (secure)";
  if ( !v23 )
    v27 = "PF Stage: stage 1 (non-secure)";
  BYTE2(v34) = v23;
  BYTE1(v38) = v25;
  cam_print_to_buffer((__int64)s, 0x200u, &v30, 1u, 0x80000u, "%s, %s, %s", (__int64)v21, (__int64)v22, (char)v27);
  cam_print_to_buffer(
    (__int64)s,
    0x200u,
    &v30,
    1u,
    0x80000u,
    "bid: %u, pid: %u, mid: %u",
    (unsigned __int8)v20,
    (unsigned __int8)v25,
    v26);
  ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
    3,
    0x80000,
    1,
    "cam_context_send_pf_evt",
    1475,
    "PF INFO: %s",
    s);
  result = cam_req_mgr_notify_message(&v32, 6, 0x8000000);
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}

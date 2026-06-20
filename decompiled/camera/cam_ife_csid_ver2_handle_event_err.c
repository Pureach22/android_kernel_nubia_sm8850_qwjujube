__int64 __fastcall cam_ife_csid_ver2_handle_event_err(__int64 result, unsigned int a2, int a3, char a4, __int64 a5)
{
  __int64 v5; // x19
  __int64 v6; // x8
  __int64 v7; // x8
  int v8; // w6
  __int64 v9; // x8
  __int64 v10; // x22
  __int64 v14; // x26
  __int64 v15; // x27
  __int64 v16; // x28
  int v17; // w20
  int v18; // w21
  int v19; // w22
  const char *v20; // x28
  int v21; // w0
  __int64 v22; // x0
  __int64 v23; // x26
  const char *v24; // x23
  _QWORD *v25; // x9
  __int64 v26; // x10
  __int64 v27; // x6
  unsigned int v28; // w8
  _DWORD *v29; // x8
  __int64 v30; // x0
  int v31; // [xsp+2Ch] [xbp-44h] BYREF
  __int64 v32; // [xsp+30h] [xbp-40h] BYREF
  __int64 v33; // [xsp+38h] [xbp-38h]
  __int64 v34; // [xsp+40h] [xbp-30h]
  __int64 v35; // [xsp+48h] [xbp-28h]
  int *v36; // [xsp+50h] [xbp-20h]
  int v37; // [xsp+5Ch] [xbp-14h] BYREF
  __int64 v38; // [xsp+60h] [xbp-10h]
  __int64 v39; // [xsp+68h] [xbp-8h]

  v5 = result;
  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(result + 31152);
  v38 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v31 = 0;
  if ( !v6 )
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_handle_event_err__rs, "cam_ife_csid_ver2_handle_event_err") )
      v22 = 3;
    else
      v22 = 2;
    result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
               v22,
               8,
               1,
               "cam_ife_csid_ver2_handle_event_err",
               2030,
               "CSID[%u] event cb not registered",
               *(_DWORD *)(*(_QWORD *)(v5 + 31120) + 4LL));
    goto LABEL_23;
  }
  if ( (*(_BYTE *)(result + 2161) & 1) != 0 )
  {
LABEL_23:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  v7 = *(_QWORD *)(result + 31120);
  v37 = a3;
  v8 = *(_DWORD *)(v7 + 4);
  v34 = a2;
  BYTE4(v32) = a4 & 1;
  HIDWORD(v33) = v8;
  v36 = &v37;
  if ( (a4 & 1) != 0 )
  {
LABEL_18:
    v28 = *(_DWORD *)(v5 + 2048) - 2;
    if ( v28 >= 3 )
      v28 = 0xFFFF;
    LODWORD(v35) = v28;
    ((void (__fastcall *)(__int64))cam_ife_csid_ver2_print_hbi_vbi)(v5);
    cam_ife_csid_ver2_print_camif_timestamps(v5, 0);
    cam_ife_csid_ver2_read_debug_err_vectors(v5);
    v29 = *(_DWORD **)(v5 + 31152);
    v30 = *(_QWORD *)(v5 + 31144);
    if ( *(v29 - 1) != 414296116 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(__int64, _QWORD, __int64 *))v29)(v30, 0, &v32);
    goto LABEL_23;
  }
  if ( !a5 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_handle_event_err",
      2073,
      "csid[%u] Rx Err: 0x%x status 0x%x",
      v8,
      a3,
      a2);
    goto LABEL_18;
  }
  v9 = *(unsigned int *)(a5 + 4);
  if ( (unsigned int)v9 < 0xC )
  {
    v10 = *(_QWORD *)(a5 + 24);
    v14 = **(_QWORD **)(result + 31136);
    v15 = *(_QWORD *)(*(_QWORD *)(result + 31128) + 384LL);
    v16 = *(_QWORD *)(v14 + 8 * v9 + 136);
    v17 = cam_io_r_mb(v15 + *(unsigned int *)(*(_QWORD *)(v10 + 264) + 108LL) + *(unsigned int *)(v16 + 316));
    v18 = cam_io_r_mb(v15 + *(unsigned int *)(*(_QWORD *)(v10 + 264) + 104LL) + *(unsigned int *)(v16 + 316));
    v19 = cam_io_r_mb(v15 + *(unsigned int *)(*(_QWORD *)(v10 + 264) + 152LL) + *(unsigned int *)(v16 + 316));
    v20 = "N";
    if ( *(_BYTE *)(v5 + 2213) == 1 )
    {
      v21 = cam_io_r_mb(v15 + *(unsigned int *)(*(_QWORD *)(v14 + 120) + 104LL));
      if ( (*(_BYTE *)(v5 + 2213) & 1) != 0 )
        v20 = "Y";
    }
    else
    {
      v21 = 0;
    }
    v23 = a5;
    v24 = (const char *)(a5 + 128);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      3,
      "cam_ife_csid_ver2_print_debug_reg_status",
      2767,
      "CSID:%u debug_camif_0: 0x%x debug_camif_1: 0x%x halt_status: 0x%x test_bus: %s test_bus_val: 0x%x for res: %s ",
      *(_DWORD *)(*(_QWORD *)(v5 + 31120) + 4LL),
      v17,
      v18,
      v19,
      v20,
      v21,
      v24);
    v25 = *(_QWORD **)(v23 + 24);
    v26 = *(_QWORD *)(v5 + 31120);
    LODWORD(v33) = *(_DWORD *)(v23 + 4);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_handle_event_err",
      2057,
      "csid[%u] Res:%s Err 0x%x status 0x%x time_stamp: %lld:%09lld",
      *(_DWORD *)(v26 + 4),
      v24,
      a3,
      a2,
      *v25,
      v25[1]);
    if ( *(_DWORD *)(v5 + 2084) )
    {
      v27 = *(unsigned int *)(*(_QWORD *)(v5 + 31120) + 4LL);
      v31 = *(_DWORD *)(v5 + 2088) - 1;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, __int64))cam_print_log)(
        3,
        8,
        1,
        "cam_ife_csid_ver2_handle_event_err",
        2065,
        "CSID:%u fatal error. Notify TPG: %d",
        v27);
      cam_subdev_notify_message(65554, 1u, (__int64)&v31);
    }
    goto LABEL_18;
  }
  __break(0x5512u);
  return ((__int64 (*)(void))cam_ife_csid_ver2_print_camif_timestamps)();
}

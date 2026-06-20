__int64 __fastcall cam_ife_csid_hw_ver2_check_for_illegal_dt(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x24
  __int64 v7; // x25
  __int64 v8; // x21
  __int64 v9; // x0
  __int64 v10; // x1
  unsigned int *v11; // x8
  int v12; // w23
  unsigned int v13; // w26
  __int64 v14; // x8
  __int64 result; // x0
  int v16; // w21
  int v17; // w0
  __int64 v18; // x8
  __int64 v19; // x26
  unsigned int v20; // w21
  __int64 v21; // x25
  __int64 v22; // x8
  __int64 v23; // x22
  __int64 v24; // x7
  __int64 v25; // x8
  __int64 v26; // x6
  __int64 v27; // x6
  void (__fastcall *v28)(__int64, __int64); // x8
  __int64 v29; // x9
  void (__fastcall *v30)(__int64, __int64); // x8
  int v31; // w22
  char v32; // [xsp+0h] [xbp-30h]
  char v33; // [xsp+0h] [xbp-30h]
  unsigned __int64 v34[2]; // [xsp+20h] [xbp-10h] BYREF

  v6 = a3 + 28672;
  v34[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a3 + 31128);
  v8 = **(_QWORD **)(a3 + 31136);
  v9 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + *(unsigned int *)(*(_QWORD *)(v8 + 128) + 72LL));
  v11 = *(unsigned int **)(v8 + 128);
  v12 = *(_DWORD *)(v6 + 3588);
  v13 = (v11[60] & (unsigned int)v9) >> v11[62];
  if ( v12 != v13 )
  {
    v16 = *(_DWORD *)(*(_QWORD *)(a3 + 31120) + 4LL);
    v17 = cam_io_r_mb(*(_QWORD *)(v7 + 384) + v11[10]);
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_hw_ver2_check_for_illegal_dt",
      3297,
      "CSID[%u] %s expected_dt: %u actual_dt: %u capture_cfg: 0x%x",
      v16,
      (const char *)(a2 + 128),
      v12,
      v13,
      v17);
    v18 = *(_QWORD *)(a1 + 264);
    v19 = *(unsigned int *)(a1 + 220);
    v34[0] = 0;
    v20 = *(_DWORD *)(v18 + 536);
    result = (__int64)cam_ife_csid_get_irq_reg_tag_ptr();
    v21 = **(_QWORD **)(a3 + 31136);
    v22 = *(_QWORD *)(v21 + 584) + 40LL * v20;
    if ( *(_DWORD *)v22 )
    {
      v23 = result;
      cam_print_to_buffer(
        a3 + 31160,
        0x400u,
        v34,
        1u,
        8u,
        "CSID[%u] %s detected at epoch",
        *(unsigned int *)(*(_QWORD *)(a3 + 31120) + 4LL),
        *(_QWORD *)(v22 + 8),
        v32);
      v25 = *(_QWORD *)(v21 + 584);
      v26 = *(_QWORD *)(v25 + 40LL * v20 + 16);
      if ( v26 )
      {
        cam_print_to_buffer(a3 + 31160, 0x400u, v34, 1u, 8u, "%s", v26, v24, v33);
        v25 = *(_QWORD *)(v21 + 584);
      }
      v27 = *(_QWORD *)(v25 + 40LL * v20 + 24);
      if ( v27 )
      {
        cam_print_to_buffer(a3 + 31160, 0x400u, v34, 1u, 8u, "Debug: %s", v27, v24, v33);
        v25 = *(_QWORD *)(v21 + 584);
      }
      v28 = *(void (__fastcall **)(__int64, __int64))(v25 + 40LL * v20 + 32);
      if ( v28 )
      {
        if ( *((_DWORD *)v28 - 1) != -72220 )
          __break(0x8228u);
        v28(a3, a2);
      }
      if ( v34[0] )
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_notify_illegal_dt",
          3270,
          "CSID[%u] %s status: 0x%x Errors:%s",
          *(_DWORD *)(*(_QWORD *)(a3 + 31120) + 4LL),
          *(const char **)(v23 + 8 * v19),
          v20,
          (const char *)(a3 + 31160));
      v29 = *(_QWORD *)(v21 + 584) + 40LL * v20;
      v30 = *(void (__fastcall **)(__int64, __int64))(v29 + 32);
      v31 = *(_DWORD *)(v29 + 4);
      if ( v30 )
      {
        if ( *((_DWORD *)v30 - 1) != -72220 )
          __break(0x8228u);
        v30(a3, a2);
      }
      result = cam_ife_csid_ver2_handle_event_err(a3, v20, v31, 0, a2);
    }
    goto LABEL_22;
  }
  v14 = *(unsigned int *)(a2 + 4);
  LODWORD(v34[0]) = *(_DWORD *)(*(_QWORD *)(a1 + 264) + 536LL);
  if ( (unsigned int)v14 <= 0xB )
  {
    result = cam_irq_controller_update_irq(*(_QWORD *)(a3 + 8 * v14 + 31016), *(_DWORD *)(a1 + 212), 1, (__int64)v34);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      result = ((__int64 (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
                 3,
                 debug_mdl & 8,
                 4,
                 "cam_ife_csid_hw_ver2_check_for_illegal_dt",
                 3307,
                 "CSID[%u] %s DT match has occurred, enabling illegal_dt_irq",
                 *(_DWORD *)(*(_QWORD *)(a3 + 31120) + 4LL),
                 (const char *)(a2 + 128));
LABEL_22:
    *(_BYTE *)(v6 + 3583) = 0;
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return cam_ife_csid_ver2_sof_irq_debug(v9, v10);
}

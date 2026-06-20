__int64 __fastcall cam_ife_csid_ver2_ppp_bottom_half(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  _DWORD *v7; // x7
  __int64 v8; // x8
  __int64 v9; // x19
  unsigned int v10; // w8
  __int64 v11; // x8
  unsigned int v12; // w20
  __int64 v13; // x24
  __int64 v14; // x21
  __int64 v15; // x22
  int v16; // w0
  const char *v17; // x6
  const char *v18; // x7
  unsigned int v19; // w21
  __int64 v21; // x23
  __int64 v22; // [xsp+8h] [xbp-18h]
  _QWORD v23[2]; // [xsp+10h] [xbp-10h] BYREF

  v23[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !a2 )
  {
    if ( a2 )
      v17 = "Non-NULL";
    else
      v17 = "NULL";
    if ( a1 )
      v18 = "Non-NULL";
    else
      v18 = "NULL";
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_ppp_bottom_half",
      3533,
      "Invalid params. evt_payload_priv: %s, handler_priv: %s",
      v17,
      v18);
    v19 = -22;
    goto LABEL_22;
  }
  v8 = *(_QWORD *)(a1 + 16);
  v7 = *(_DWORD **)(a1 + 24);
  v23[0] = a2;
  v9 = *(_QWORD *)(*(_QWORD *)(v8 + 112) + 3680LL);
  if ( !v7 )
  {
    v10 = -1;
    goto LABEL_20;
  }
  v10 = v7[55];
  if ( v10 >= 0x10 )
  {
LABEL_20:
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      8,
      1,
      "cam_ife_csid_ver2_ppp_bottom_half",
      3546,
      "CSID:%u Invalid params: path_cfg: %pK, irq_reg_idx: %d",
      *(_DWORD *)(*(_QWORD *)(v9 + 31120) + 4LL),
      v7,
      v10);
    v19 = -22;
LABEL_21:
    cam_ife_csid_ver2_put_evt_payload(v9, v23, v9 + 30952, v9 + 30972);
LABEL_22:
    _ReadStatusReg(SP_EL0);
    return v19;
  }
  v11 = *(unsigned int *)(a1 + 4);
  if ( (unsigned int)v11 < 0xC )
  {
    v12 = *(_DWORD *)(a2 + 16);
    v13 = *(_QWORD *)(**(_QWORD **)(v9 + 31136) + 8 * v11 + 136);
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      v22 = a2;
      v21 = a1;
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_ppp_bottom_half",
        3559,
        "CSID[%u] PPP status:0x%x",
        *(_DWORD *)(*(_QWORD *)(v9 + 31120) + 4LL),
        v12);
      a2 = v22;
      a1 = v21;
      if ( (*(_BYTE *)(v9 + 2148) & 1) != 0 )
        goto LABEL_9;
    }
    else if ( (*(_BYTE *)(v9 + 2148) & 1) != 0 )
    {
LABEL_9:
      v14 = a1;
      v15 = a2;
      raw_spin_lock(v9 + 30968);
      if ( *(_DWORD *)(*(_QWORD *)(v9 + 31128) + 92LL) == 1 )
      {
        v16 = cam_ife_csid_ver2_parse_path_irq_status(
                v9,
                v14,
                8,
                *(unsigned int *)(v13 + 500),
                *(unsigned int *)(v13 + 504),
                v12,
                v15);
        if ( v16 )
          cam_ife_csid_ver2_handle_event_err(v9, v12, v16, 0, v14);
      }
      else
      {
        ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
          3,
          8,
          1,
          "cam_ife_csid_ver2_ppp_bottom_half",
          3570,
          "CSID[%u] powered down state",
          *(_DWORD *)(*(_QWORD *)(v9 + 31120) + 4LL));
      }
      raw_spin_unlock(v9 + 30968);
LABEL_25:
      v19 = 0;
      goto LABEL_21;
    }
    v19 = 0;
    if ( (debug_mdl & 8) == 0 || debug_priority )
      goto LABEL_21;
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      debug_mdl & 8,
      4,
      "cam_ife_csid_ver2_ppp_bottom_half",
      3563,
      "CSID[%u] bottom-half after stop [0x%x]",
      *(_DWORD *)(*(_QWORD *)(v9 + 31120) + 4LL),
      v12);
    goto LABEL_25;
  }
  __break(0x5512u);
  return cam_ife_csid_ver2_parse_path_irq_status(a1, a2, a3, a4, a5, a6, a7);
}

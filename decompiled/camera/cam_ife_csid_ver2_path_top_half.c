__int64 __fastcall cam_ife_csid_ver2_path_top_half(__int64 a1, __int64 *a2)
{
  __int64 v2; // x9
  __int64 v3; // x8
  __int64 v4; // x10
  __int64 v5; // x24
  __int64 v7; // x25
  __int64 v8; // x21
  __int64 v9; // x26
  __int64 v10; // x27
  __int64 v11; // x23
  unsigned int evt_payload; // w20
  char **irq_reg_tag_ptr; // x0
  char **v14; // x22
  __int64 v15; // x0
  __int64 v16; // x0
  const char *v17; // x7
  __int64 v18; // x21
  int v19; // w8
  _DWORD *v20; // x9
  __int64 v21; // x20
  unsigned int v22; // w0
  __int64 v23; // x20
  unsigned int v24; // w0
  __int64 v25; // x20
  __int64 v26; // x0
  __int64 v27; // x1
  _QWORD v29[2]; // [xsp+10h] [xbp-10h] BYREF

  v29[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  if ( !*a2 )
  {
    if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_path_top_half__rs, "cam_ife_csid_ver2_path_top_half") )
      v16 = 3;
    else
      v16 = 2;
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      v16,
      8,
      1,
      "cam_ife_csid_ver2_path_top_half",
      1014,
      "No private returned");
    evt_payload = -19;
    goto LABEL_34;
  }
  v3 = *(unsigned int *)(v2 + 4);
  if ( (unsigned int)v3 < 0xC )
  {
    v4 = *(_QWORD *)(v2 + 16);
    v5 = *(_QWORD *)(v2 + 24);
    v29[0] = 0;
    v7 = *(_QWORD *)(v5 + 264);
    v8 = *(_QWORD *)(*(_QWORD *)(v4 + 112) + 3680LL);
    v9 = *(_QWORD *)(v8 + 31128);
    v10 = **(_QWORD **)(v8 + 31136);
    v11 = *(_QWORD *)(v10 + 8 * v3 + 136);
    evt_payload = cam_ife_csid_ver2_get_evt_payload(v8, v29, (_QWORD **)(v8 + 30952), v8 + 30972);
    irq_reg_tag_ptr = cam_ife_csid_get_irq_reg_tag_ptr();
    v14 = irq_reg_tag_ptr;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
    {
      if ( (a2[4] & 1) != 0 )
        v17 = "COMP_IRQ";
      else
        v17 = irq_reg_tag_ptr[*(unsigned int *)(v5 + 220)];
      ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_ife_csid_ver2_path_top_half",
        1036,
        "CSID:%u %s status: 0x%x",
        *(_DWORD *)(*(_QWORD *)(v8 + 31120) + 4LL),
        v17,
        *(_DWORD *)a2[2]);
      if ( evt_payload )
        goto LABEL_6;
    }
    else if ( evt_payload )
    {
LABEL_6:
      if ( (unsigned int)__ratelimit(&cam_ife_csid_ver2_path_top_half__rs_229, "cam_ife_csid_ver2_path_top_half") )
        v15 = 3;
      else
        v15 = 2;
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD, char *, _DWORD))cam_print_log)(
        v15,
        8,
        3,
        "cam_ife_csid_ver2_path_top_half",
        1042,
        "CSID:%u %s status: 0x%x",
        *(unsigned int *)(*(_QWORD *)(v8 + 31120) + 4LL),
        v14[*(unsigned int *)(v5 + 220)],
        *(_DWORD *)a2[2]);
LABEL_34:
      _ReadStatusReg(SP_EL0);
      return evt_payload;
    }
    v18 = v29[0];
    v19 = *(_DWORD *)a2[2];
    *(_DWORD *)((char *)&qword_10 + v29[0]) = v19;
    v20 = *(_DWORD **)(v5 + 264);
    if ( ((v20[130] & v19) != 0
       || (*(_BYTE *)(v11 + 584) & 0x80) != 0 && (*(_DWORD *)(*(_QWORD *)(v10 + 240) + 12LL) & v19) != 0)
      && *(_BYTE *)(v5 + 253) == 1 )
    {
      v21 = (unsigned int)cam_io_r_mb(*(_QWORD *)(v9 + 384) + *(unsigned int *)(v7 + 200) + *(unsigned int *)(v11 + 316));
      *(__int64 *)((char *)&qword_28 + v18) = v21;
      v22 = cam_io_r_mb(*(_QWORD *)(v9 + 384) + *(unsigned int *)(v7 + 196) + *(unsigned int *)(v11 + 316));
      v19 = *(_DWORD *)((char *)&qword_10 + v18);
      *(__int64 *)((char *)&qword_28 + v18) = v22 | (unsigned __int64)(v21 << 32);
      v20 = *(_DWORD **)(v5 + 264);
    }
    if ( ((v20[128] & v19) != 0
       || (*(_BYTE *)(v11 + 584) & 0x80) != 0 && (*(_DWORD *)(*(_QWORD *)(v10 + 240) + 24LL) & v19) != 0)
      && *(_BYTE *)(v5 + 253) == 1 )
    {
      v23 = (unsigned int)cam_io_r_mb(*(_QWORD *)(v9 + 384) + *(unsigned int *)(v7 + 200) + *(unsigned int *)(v11 + 316));
      *(__int64 *)((char *)&qword_28 + v18) = v23;
      v24 = cam_io_r_mb(*(_QWORD *)(v9 + 384) + *(unsigned int *)(v7 + 196) + *(unsigned int *)(v11 + 316));
      v19 = *(_DWORD *)((char *)&qword_10 + v18);
      *(__int64 *)((char *)&qword_28 + v18) = v24 | (unsigned __int64)(v23 << 32);
      v20 = *(_DWORD **)(v5 + 264);
    }
    if ( ((v20[132] & v19) != 0
       || (*(_BYTE *)(v11 + 584) & 0x80) != 0 && (*(_DWORD *)(*(_QWORD *)(v10 + 240) + 20LL) & v19) != 0)
      && *(_BYTE *)(v5 + 253) == 1 )
    {
      v25 = (unsigned int)cam_io_r_mb(*(_QWORD *)(v9 + 384) + *(unsigned int *)(v7 + 200) + *(unsigned int *)(v11 + 316));
      *(__int64 *)((char *)&qword_28 + v18) = v25;
      *(__int64 *)((char *)&qword_28 + v18) = (unsigned int)cam_io_r_mb(
                                                              *(_QWORD *)(v9 + 384)
                                                            + *(unsigned int *)(v7 + 196)
                                                            + *(unsigned int *)(v11 + 316))
                                            | (unsigned __int64)(v25 << 32);
    }
    v26 = ktime_get_with_offset(1);
    evt_payload = 0;
    *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v18) = ns_to_timespec64(v26);
    *(__int64 *)((char *)&_ksymtab_cam_cdm_detect_hang_error + v18 + 8) = v27;
    a2[3] = v18;
    goto LABEL_34;
  }
  __break(0x5512u);
  return cam_ife_csid_ver2_path_err_top_half();
}

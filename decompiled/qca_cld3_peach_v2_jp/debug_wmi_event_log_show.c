__int64 __fastcall debug_wmi_event_log_show(__int64 a1)
{
  __int64 v1; // x27
  unsigned __int64 StatusReg; // x8
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w2
  void *v13; // x21
  int v14; // w28
  int v15; // w20
  __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int *v25; // x22
  unsigned __int64 v26; // x8
  unsigned __int64 v27; // x8
  unsigned __int64 v28; // x25
  unsigned __int64 v29; // x26
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  double v38; // d0
  double v39; // d1
  double v40; // d2
  double v41; // d3
  double v42; // d4
  double v43; // d5
  double v44; // d6
  double v45; // d7
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x8
  double v55; // d0
  double v56; // d1
  double v57; // d2
  double v58; // d3
  double v59; // d4
  double v60; // d5
  double v61; // d6
  double v62; // d7

  v1 = *(_QWORD *)(a1 + 128);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 664);
    v12 = *(_DWORD *)(v1 + 480);
    if ( v12 )
      goto LABEL_5;
LABEL_29:
    v54 = *(_QWORD *)(v1 + 672);
    if ( (v54 & 1) != 0 )
    {
      *(_QWORD *)(v1 + 672) = v54 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v1 + 664);
    }
    else
    {
      raw_spin_unlock(v1 + 664);
    }
    wmi_bp_seq_printf(a1, "no elements to read from ring buffer!\n", v55, v56, v57, v58, v59, v60, v61, v62);
    return 0;
  }
  raw_spin_lock_bh(v1 + 664);
  *(_QWORD *)(v1 + 672) |= 1uLL;
  v12 = *(_DWORD *)(v1 + 480);
  if ( !v12 )
    goto LABEL_29;
LABEL_5:
  LODWORD(v13) = wmi_display_size;
  if ( v12 >= wmi_display_size )
    v14 = wmi_display_size;
  else
    v14 = v12;
  if ( **(_DWORD **)(v1 + 488) )
    v15 = **(_DWORD **)(v1 + 488);
  else
    v15 = wmi_display_size;
  wmi_bp_seq_printf(a1, "Length = %d\n", v4, v5, v6, v7, v8, v9, v10, v11);
  v16 = *(_QWORD *)(v1 + 672);
  if ( (v16 & 1) != 0 )
    goto LABEL_26;
  raw_spin_unlock(v1 + 664);
  while ( (_DWORD)v13 )
  {
    v13 = &unk_12000;
    while ( 1 )
    {
      v25 = (unsigned int *)(*(_QWORD *)(v1 + 472) + 32LL * --v15);
      v26 = *((_QWORD *)v25 + 3);
      v27 = 10 * v26 < v26 ? 10 * (v26 / 0xC0) : 10 * v26 / 0xC0;
      v28 = v27 / 0xF4240;
      v29 = v27 % 0xF4240;
      wmi_bp_seq_printf(a1, "Event ID = %x\n", v17, v18, v19, v20, v21, v22, v23, v24, *v25);
      wmi_bp_seq_printf(a1, "Event TIME = [%llu.%06llu]\n", v30, v31, v32, v33, v34, v35, v36, v37, v28, v29);
      wmi_bp_seq_printf(a1, "CMD = ", v38, v39, v40, v41, v42, v43, v44, v45);
      if ( (unsigned int)wmi_record_max_length >= 4 )
      {
        wmi_bp_seq_printf(a1, "%x ", v46, v47, v48, v49, v50, v51, v52, v53, v25[1]);
        if ( (unsigned int)wmi_record_max_length > 7 )
        {
          wmi_bp_seq_printf(a1, "%x ", v46, v47, v48, v49, v50, v51, v52, v53, v25[2]);
          if ( (unsigned int)wmi_record_max_length >= 0xC )
          {
            wmi_bp_seq_printf(a1, "%x ", v46, v47, v48, v49, v50, v51, v52, v53, v25[3]);
            if ( (unsigned int)wmi_record_max_length >= 0x10 )
            {
              wmi_bp_seq_printf(a1, "%x ", v46, v47, v48, v49, v50, v51, v52, v53, v25[4]);
              v16 = (unsigned int)wmi_record_max_length;
              if ( (unsigned int)wmi_record_max_length > 0x13 )
                break;
            }
          }
        }
      }
      --v14;
      wmi_bp_seq_printf(a1, "\n", v46, v47, v48, v49, v50, v51, v52, v53);
      if ( !v15 )
        v15 = wmi_display_size;
      if ( !v14 )
        return 0;
    }
    __break(0x5512u);
LABEL_26:
    *(_QWORD *)(v1 + 672) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1 + 664);
  }
  return 0;
}

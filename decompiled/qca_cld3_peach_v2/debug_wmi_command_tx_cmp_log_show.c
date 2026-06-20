__int64 __fastcall debug_wmi_command_tx_cmp_log_show(__int64 a1)
{
  __int64 v1; // x25
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
  int v13; // w20
  int v14; // w27
  unsigned int *v15; // x21
  __int64 v16; // x8
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  int v25; // w28
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned __int64 v34; // x8
  unsigned __int64 v35; // x8
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7

  v1 = *(_QWORD *)(a1 + 128);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 664);
    v12 = *(_DWORD *)(v1 + 448);
    if ( v12 )
      goto LABEL_5;
LABEL_30:
    v52 = *(_QWORD *)(v1 + 672);
    if ( (v52 & 1) != 0 )
    {
      *(_QWORD *)(v1 + 672) = v52 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v1 + 664);
    }
    else
    {
      raw_spin_unlock(v1 + 664);
    }
    wmi_bp_seq_printf(a1, "no elements to read from ring buffer!\n", v53, v54, v55, v56, v57, v58, v59, v60);
    return 0;
  }
  raw_spin_lock_bh(v1 + 664);
  *(_QWORD *)(v1 + 672) |= 1uLL;
  v12 = *(_DWORD *)(v1 + 448);
  if ( !v12 )
    goto LABEL_30;
LABEL_5:
  v13 = wmi_display_size;
  if ( v12 >= wmi_display_size )
    v14 = wmi_display_size;
  else
    v14 = v12;
  if ( **(_DWORD **)(v1 + 456) )
    LODWORD(v15) = **(_DWORD **)(v1 + 456);
  else
    LODWORD(v15) = wmi_display_size;
  wmi_bp_seq_printf(a1, "Length = %d\n", v4, v5, v6, v7, v8, v9, v10, v11);
  v16 = *(_QWORD *)(v1 + 672);
  if ( (v16 & 1) != 0 )
    goto LABEL_27;
  raw_spin_unlock(v1 + 664);
  while ( v13 )
  {
    v13 = 1000000;
    while ( 1 )
    {
      v25 = (_DWORD)v15 - 1;
      v15 = (unsigned int *)(*(_QWORD *)(v1 + 440) + 48LL * ((int)v15 - 1));
      wmi_bp_seq_printf(a1, "CMD ID = %x\n", v17, v18, v19, v20, v21, v22, v23, v24, *v15);
      v34 = *((_QWORD *)v15 + 3);
      v35 = 10 * v34 < v34 ? 10 * (v34 / 0xC0) : 10 * v34 / 0xC0;
      wmi_bp_seq_printf(
        a1,
        "CMD TIME = [%llu.%06llu]\n",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v35 / 0xF4240,
        v35 % 0xF4240);
      wmi_bp_seq_printf(a1, "CMD = ", v36, v37, v38, v39, v40, v41, v42, v43);
      if ( (unsigned int)wmi_record_max_length >= 4 )
      {
        wmi_bp_seq_printf(a1, "%x ", v44, v45, v46, v47, v48, v49, v50, v51, v15[1]);
        if ( (unsigned int)wmi_record_max_length > 7 )
        {
          wmi_bp_seq_printf(a1, "%x ", v44, v45, v46, v47, v48, v49, v50, v51, v15[2]);
          if ( (unsigned int)wmi_record_max_length >= 0xC )
          {
            wmi_bp_seq_printf(a1, "%x ", v44, v45, v46, v47, v48, v49, v50, v51, v15[3]);
            if ( (unsigned int)wmi_record_max_length >= 0x10 )
            {
              wmi_bp_seq_printf(a1, "%x ", v44, v45, v46, v47, v48, v49, v50, v51, v15[4]);
              v16 = (unsigned int)wmi_record_max_length;
              if ( (unsigned int)wmi_record_max_length > 0x13 )
                break;
            }
          }
        }
      }
      --v14;
      wmi_bp_seq_printf(a1, "\n", v44, v45, v46, v47, v48, v49, v50, v51);
      if ( v25 )
        LODWORD(v15) = v25;
      else
        LODWORD(v15) = wmi_display_size;
      if ( !v14 )
        return 0;
    }
    __break(0x5512u);
LABEL_27:
    *(_QWORD *)(v1 + 672) = v16 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1 + 664);
  }
  return 0;
}

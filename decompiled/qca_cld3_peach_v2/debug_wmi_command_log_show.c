__int64 __fastcall debug_wmi_command_log_show(__int64 a1)
{
  __int64 v1; // x25
  unsigned __int64 StatusReg; // x8
  unsigned int v4; // w2
  int v5; // w20
  int v6; // w27
  __int64 v7; // x21
  __int64 v8; // x8
  int v9; // w26
  unsigned __int64 v10; // x8
  unsigned __int64 v11; // x8
  __int64 v12; // x8

  v1 = *(_QWORD *)(a1 + 128);
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(v1 + 664);
    v4 = *(_DWORD *)(v1 + 416);
    if ( v4 )
      goto LABEL_5;
LABEL_30:
    v12 = *(_QWORD *)(v1 + 672);
    if ( (v12 & 1) != 0 )
    {
      *(_QWORD *)(v1 + 672) = v12 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v1 + 664);
    }
    else
    {
      raw_spin_unlock(v1 + 664);
    }
    wmi_bp_seq_printf(a1, "no elements to read from ring buffer!\n");
    return 0;
  }
  raw_spin_lock_bh(v1 + 664);
  *(_QWORD *)(v1 + 672) |= 1uLL;
  v4 = *(_DWORD *)(v1 + 416);
  if ( !v4 )
    goto LABEL_30;
LABEL_5:
  v5 = wmi_display_size;
  if ( v4 >= wmi_display_size )
    v6 = wmi_display_size;
  else
    v6 = v4;
  if ( **(_DWORD **)(v1 + 424) )
    LODWORD(v7) = **(_DWORD **)(v1 + 424);
  else
    LODWORD(v7) = wmi_display_size;
  wmi_bp_seq_printf(a1, "Length = %d\n");
  v8 = *(_QWORD *)(v1 + 672);
  if ( (v8 & 1) != 0 )
    goto LABEL_27;
  raw_spin_unlock(v1 + 664);
  while ( v5 )
  {
    v5 = 1000000;
    while ( 1 )
    {
      v9 = v7 - 1;
      v7 = *(_QWORD *)(v1 + 408) + 32LL * ((int)v7 - 1);
      wmi_bp_seq_printf(a1, "CMD ID = %x\n", *(_DWORD *)v7);
      v10 = *(_QWORD *)(v7 + 24);
      v11 = 10 * v10 < v10 ? 10 * (v10 / 0xC0) : 10 * v10 / 0xC0;
      wmi_bp_seq_printf(a1, "CMD TIME = [%llu.%06llu]\n", v11 / 0xF4240, v11 % 0xF4240);
      wmi_bp_seq_printf(a1, "CMD = ");
      if ( (unsigned int)wmi_record_max_length >= 4 )
      {
        wmi_bp_seq_printf(a1, "%x ", *(_DWORD *)(v7 + 4));
        if ( (unsigned int)wmi_record_max_length > 7 )
        {
          wmi_bp_seq_printf(a1, "%x ", *(_DWORD *)(v7 + 8));
          if ( (unsigned int)wmi_record_max_length >= 0xC )
          {
            wmi_bp_seq_printf(a1, "%x ", *(_DWORD *)(v7 + 12));
            if ( (unsigned int)wmi_record_max_length >= 0x10 )
            {
              wmi_bp_seq_printf(a1, "%x ", *(_DWORD *)(v7 + 16));
              v8 = (unsigned int)wmi_record_max_length;
              if ( (unsigned int)wmi_record_max_length > 0x13 )
                break;
            }
          }
        }
      }
      --v6;
      wmi_bp_seq_printf(a1, "\n");
      if ( v9 )
        LODWORD(v7) = v9;
      else
        LODWORD(v7) = wmi_display_size;
      if ( !v6 )
        return 0;
    }
    __break(0x5512u);
LABEL_27:
    *(_QWORD *)(v1 + 672) = v8 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(v1 + 664);
  }
  return 0;
}

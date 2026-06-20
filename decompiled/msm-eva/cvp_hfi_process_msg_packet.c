__int64 __fastcall cvp_hfi_process_msg_packet(__int64 a1, _DWORD *a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8
  int v6; // w8
  __int64 (*v7)(void); // x9
  _DWORD *v8; // x22

  if ( !a2 || !a3 || *a2 <= 7u )
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_825FF, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
    return result;
  }
  if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
  {
    v8 = a2;
    printk(&unk_87752, "hfi", (unsigned int)a2[1], a4);
    a2 = v8;
  }
  v6 = a2[1];
  if ( v6 > 35655680 )
  {
    if ( v6 > 35655685 )
    {
      switch ( v6 )
      {
        case 35655686:
          v7 = hfi_process_session_stop_done;
          goto LABEL_40;
        case 35655687:
          v7 = hfi_process_session_flush_done;
          goto LABEL_40;
        case 35655689:
          v7 = hfi_process_event_notify;
          goto LABEL_40;
      }
    }
    else
    {
      switch ( v6 )
      {
        case 35655681:
          v7 = hfi_process_session_set_buf_done;
          goto LABEL_40;
        case 35655684:
          v7 = hfi_process_session_rel_buf_done;
          goto LABEL_40;
        case 35655685:
          v7 = hfi_process_session_start_done;
          goto LABEL_40;
      }
    }
LABEL_37:
    v7 = hfi_process_session_cvp_msg;
    if ( (msm_cvp_debug & 0x4000) != 0 && !msm_cvp_debug_out )
    {
      printk(&unk_89DBD, "hfi", (unsigned int)v6, a4);
      v7 = hfi_process_session_cvp_msg;
    }
    goto LABEL_40;
  }
  if ( v6 > 34607116 )
  {
    switch ( v6 )
    {
      case 34607117:
        v7 = hfi_process_sys_property_info;
        goto LABEL_40;
      case 34607119:
        v7 = hfi_process_session_abort_done;
        goto LABEL_40;
      case 35651655:
        v7 = hfi_process_session_dump_notify;
        goto LABEL_40;
    }
    goto LABEL_37;
  }
  if ( v6 == 34607105 )
  {
    v7 = hfi_process_sys_init_done;
    goto LABEL_40;
  }
  if ( v6 == 34607110 )
  {
    v7 = hfi_process_session_init_done;
    goto LABEL_40;
  }
  if ( v6 != 34607114 )
    goto LABEL_37;
  v7 = hfi_process_session_end_done;
LABEL_40:
  if ( *((_DWORD *)v7 - 1) != -1534357799 )
    __break(0x8229u);
  return v7();
}

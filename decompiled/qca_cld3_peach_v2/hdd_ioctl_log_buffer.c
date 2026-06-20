__int64 *__fastcall hdd_ioctl_log_buffer(
        int a1,
        unsigned int a2,
        __int64 (__fastcall *a3)(int, int, int, int, int, int, int, int, char),
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 (__fastcall *v13)(int, int, int, int, int, int, int, int, char); // x20
  __int64 *result; // x0
  __int64 *v16; // x22
  __int64 *v17; // x22
  __int64 *v18; // x22
  __int64 *v19; // x22
  __int64 *v20; // x22
  __int64 *v21; // x22
  __int64 *v22; // x22

  if ( a3 )
    v13 = a3;
  else
    v13 = printk_adapter;
  if ( a1 > 3 )
  {
    if ( a1 > 5 )
    {
      if ( a1 == 6 )
      {
        result = _cds_get_context(54, (__int64)"wma_print_wmi_rx_event_log", a5, a6, a7, a8, a9, a10, a11, a12);
        if ( result )
        {
          v22 = result;
          if ( *((_DWORD *)v13 - 1) != 1872960511 )
            __break(0x8234u);
          ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(a4, "Rx Event Log (count %u)", a2);
          return (__int64 *)wmi_print_rx_event_log(*v22, a2, (__int64 (__fastcall *)(__int64, const char *))v13, a4);
        }
      }
      else
      {
        if ( a1 != 7 )
        {
LABEL_42:
          if ( *((_DWORD *)v13 - 1) != 1872960511 )
            __break(0x8234u);
          return (__int64 *)((__int64 (__fastcall *)(__int64, const char *, _QWORD))v13)(
                              a4,
                              "Invalid Log Id %d",
                              (unsigned int)a1);
        }
        result = _cds_get_context(54, (__int64)"wma_print_wmi_mgmt_event_log", a5, a6, a7, a8, a9, a10, a11, a12);
        if ( result )
        {
          v19 = result;
          if ( *((_DWORD *)v13 - 1) != 1872960511 )
            __break(0x8234u);
          ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(a4, "Management Event Log (count %u)", a2);
          return (__int64 *)wmi_print_mgmt_event_log(*v19, a2, (__int64 (__fastcall *)(__int64, const char *))v13, a4);
        }
      }
    }
    else if ( a1 == 4 )
    {
      result = _cds_get_context(54, (__int64)"wma_print_wmi_mgmt_cmd_tx_cmp_log", a5, a6, a7, a8, a9, a10, a11, a12);
      if ( result )
      {
        v20 = result;
        if ( *((_DWORD *)v13 - 1) != 1872960511 )
          __break(0x8234u);
        ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(
          a4,
          "Management Command Tx Complete Log (count %u)",
          a2);
        return (__int64 *)wmi_print_mgmt_cmd_tx_cmp_log(
                            *v20,
                            a2,
                            (__int64 (__fastcall *)(__int64, const char *))v13,
                            a4);
      }
    }
    else
    {
      result = _cds_get_context(54, (__int64)"wma_print_wmi_event_log", a5, a6, a7, a8, a9, a10, a11, a12);
      if ( result )
      {
        v17 = result;
        if ( *((_DWORD *)v13 - 1) != 1872960511 )
          __break(0x8234u);
        ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(a4, "Event Log (count %u)", a2);
        return (__int64 *)wmi_print_event_log(*v17);
      }
    }
  }
  else
  {
    if ( a1 <= 1 )
    {
      if ( !a1 )
        return (__int64 *)cds_print_htc_credit_history(a2, (__int64)v13, a4);
      if ( a1 == 1 )
      {
        result = _cds_get_context(54, (__int64)"wma_print_wmi_cmd_log", a5, a6, a7, a8, a9, a10, a11, a12);
        if ( result )
        {
          v16 = result;
          if ( *((_DWORD *)v13 - 1) != 1872960511 )
            __break(0x8234u);
          ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(a4, "Command Log (count %u)", a2);
          return (__int64 *)wmi_print_cmd_log(*v16);
        }
        return result;
      }
      goto LABEL_42;
    }
    if ( a1 == 2 )
    {
      result = _cds_get_context(54, (__int64)"wma_print_wmi_cmd_tx_cmp_log", a5, a6, a7, a8, a9, a10, a11, a12);
      if ( result )
      {
        v21 = result;
        if ( *((_DWORD *)v13 - 1) != 1872960511 )
          __break(0x8234u);
        ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(a4, "Command Tx Complete Log (count %u)", a2);
        return (__int64 *)wmi_print_cmd_tx_cmp_log(*v21, a2, (__int64 (__fastcall *)(__int64, const char *))v13, a4);
      }
    }
    else
    {
      result = _cds_get_context(54, (__int64)"wma_print_wmi_mgmt_cmd_log", a5, a6, a7, a8, a9, a10, a11, a12);
      if ( result )
      {
        v18 = result;
        if ( *((_DWORD *)v13 - 1) != 1872960511 )
          __break(0x8234u);
        ((void (__fastcall *)(__int64, const char *, _QWORD))v13)(a4, "Management Command Log (count %u)", a2);
        return (__int64 *)wmi_print_mgmt_cmd_log(*v18, a2, (__int64 (__fastcall *)(__int64, const char *))v13, a4);
      }
    }
  }
  return result;
}

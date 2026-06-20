__int64 __fastcall sme_trace_dump(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        unsigned __int16 a11)
{
  unsigned int v11; // w8
  __int64 v12; // x20
  unsigned int v14; // w19
  int v15; // w8
  const char *v16; // x9
  __int64 *v17; // x22
  const char *wma_msg_string; // x0
  int v19; // w9
  const char *v20; // x8
  const char *v21; // x7
  const char *sme_msg_string; // x0
  __int64 v23; // x3
  __int64 v24; // x5
  int v26; // [xsp+8h] [xbp-8h]

  v11 = *((unsigned __int16 *)a10 + 14);
  v12 = *a10;
  v14 = *((unsigned __int16 *)a10 + 15);
  if ( v11 == 252 )
  {
    v17 = a10;
    sme_msg_string = mac_trace_get_sme_msg_string(*((_DWORD *)a10 + 8));
    v19 = *((_DWORD *)v17 + 8);
    v20 = sme_msg_string;
    v21 = "RX WMA Msg:";
    goto LABEL_12;
  }
  if ( v11 == 251 )
  {
    v17 = a10;
    wma_msg_string = mac_trace_get_wma_msg_string(*((_DWORD *)a10 + 8));
    v19 = *((_DWORD *)v17 + 8);
    v20 = wma_msg_string;
    v21 = "TX WMA Msg:";
LABEL_12:
    v26 = v19;
    v23 = a11;
    v24 = (__int64)(v17 + 1);
    return qdf_trace_msg(
             0x34u,
             8u,
             "%04d %012llu %s S%d %-14s %-30s(0x%x)",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             v23,
             v12,
             v24,
             v14,
             v21,
             v20,
             v26);
  }
  if ( v11 != 250 )
  {
    if ( v11 > 0x5B )
      v20 = "UNKNOWN";
    else
      v20 = off_A170C0[*((unsigned __int16 *)a10 + 14)];
    v21 = "RX HDD MSG:";
    v23 = a11;
    v24 = (__int64)(a10 + 1);
    v26 = *((_DWORD *)a10 + 8);
    return qdf_trace_msg(
             0x34u,
             8u,
             "%04d %012llu %s S%d %-14s %-30s(0x%x)",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             v23,
             v12,
             v24,
             v14,
             v21,
             v20,
             v26);
  }
  v15 = *((_DWORD *)a10 + 8);
  if ( v15 > 262145 )
  {
    if ( v15 <= 262148 )
    {
      if ( v15 == 262146 )
      {
        v16 = "eSmeCommandDelTs";
      }
      else if ( v15 == 262147 )
      {
        v16 = "e_sme_command_set_hw_mode";
      }
      else
      {
        v16 = "e_sme_command_nss_update";
      }
      return qdf_trace_msg(
               0x34u,
               8u,
               "%04d %012llu %s S%d %-14s %-30s(0x%x)",
               a1,
               a2,
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a11,
               v12,
               a10 + 1,
               *((unsigned __int16 *)a10 + 15),
               "SME COMMAND:",
               v16,
               *((_DWORD *)a10 + 8));
    }
    switch ( v15 )
    {
      case 262149:
        v16 = "e_sme_command_set_dual_mac_config";
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%04d %012llu %s S%d %-14s %-30s(0x%x)",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a11,
                 v12,
                 a10 + 1,
                 *((unsigned __int16 *)a10 + 15),
                 "SME COMMAND:",
                 v16,
                 *((_DWORD *)a10 + 8));
      case 262150:
        v16 = "e_sme_command_set_antenna_mode";
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%04d %012llu %s S%d %-14s %-30s(0x%x)",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a11,
                 v12,
                 a10 + 1,
                 *((unsigned __int16 *)a10 + 15),
                 "SME COMMAND:",
                 v16,
                 *((_DWORD *)a10 + 8));
      case 262151:
        v16 = "e_sme_command_sap_ch_width_update";
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%04d %012llu %s S%d %-14s %-30s(0x%x)",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a11,
                 v12,
                 a10 + 1,
                 *((unsigned __int16 *)a10 + 15),
                 "SME COMMAND:",
                 v16,
                 *((_DWORD *)a10 + 8));
    }
    goto LABEL_38;
  }
  if ( v15 > 65537 )
  {
    switch ( v15 )
    {
      case 65538:
        v16 = "eSmeCommandWmStatusChange";
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%04d %012llu %s S%d %-14s %-30s(0x%x)",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a11,
                 v12,
                 a10 + 1,
                 *((unsigned __int16 *)a10 + 15),
                 "SME COMMAND:",
                 v16,
                 *((_DWORD *)a10 + 8));
      case 262144:
        v16 = "eSmeQosCommandMask";
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%04d %012llu %s S%d %-14s %-30s(0x%x)",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a11,
                 v12,
                 a10 + 1,
                 *((unsigned __int16 *)a10 + 15),
                 "SME COMMAND:",
                 v16,
                 *((_DWORD *)a10 + 8));
      case 262145:
        v16 = "eSmeCommandAddTs";
        return qdf_trace_msg(
                 0x34u,
                 8u,
                 "%04d %012llu %s S%d %-14s %-30s(0x%x)",
                 a1,
                 a2,
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a11,
                 v12,
                 a10 + 1,
                 *((unsigned __int16 *)a10 + 15),
                 "SME COMMAND:",
                 v16,
                 *((_DWORD *)a10 + 8));
    }
LABEL_38:
    v16 = "UNKNOWN";
    return qdf_trace_msg(
             0x34u,
             8u,
             "%04d %012llu %s S%d %-14s %-30s(0x%x)",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a11,
             v12,
             a10 + 1,
             *((unsigned __int16 *)a10 + 15),
             "SME COMMAND:",
             v16,
             *((_DWORD *)a10 + 8));
  }
  if ( !v15 )
  {
    v16 = "eSmeNoCommand";
    return qdf_trace_msg(
             0x34u,
             8u,
             "%04d %012llu %s S%d %-14s %-30s(0x%x)",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a11,
             v12,
             a10 + 1,
             *((unsigned __int16 *)a10 + 15),
             "SME COMMAND:",
             v16,
             *((_DWORD *)a10 + 8));
  }
  if ( v15 == 0x10000 )
  {
    v16 = "eSmeCsrCommandMask";
    return qdf_trace_msg(
             0x34u,
             8u,
             "%04d %012llu %s S%d %-14s %-30s(0x%x)",
             a1,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a11,
             v12,
             a10 + 1,
             *((unsigned __int16 *)a10 + 15),
             "SME COMMAND:",
             v16,
             *((_DWORD *)a10 + 8));
  }
  if ( v15 != 65537 )
    goto LABEL_38;
  v16 = "eSmeCommandRoam";
  return qdf_trace_msg(
           0x34u,
           8u,
           "%04d %012llu %s S%d %-14s %-30s(0x%x)",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           a11,
           v12,
           a10 + 1,
           *((unsigned __int16 *)a10 + 15),
           "SME COMMAND:",
           v16,
           *((_DWORD *)a10 + 8));
}

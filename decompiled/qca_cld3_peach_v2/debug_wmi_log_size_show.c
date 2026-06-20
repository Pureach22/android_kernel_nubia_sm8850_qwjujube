__int64 __fastcall debug_wmi_log_size_show(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7

  wmi_bp_seq_printf(
    a1,
    "WMI command/cmpl log max size:%d/%d\n",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    (unsigned int)wmi_cmd_log_max_entry,
    (unsigned int)wmi_cmd_cmpl_log_max_entry);
  wmi_bp_seq_printf(
    a1,
    "WMI management Tx/cmpl log max size:%d/%d\n",
    v10,
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    (unsigned int)wmi_mgmt_tx_log_max_entry,
    (unsigned int)wmi_mgmt_tx_cmpl_log_max_entry);
  wmi_bp_seq_printf(
    a1,
    "WMI event log max size:%d\n",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    (unsigned int)wmi_event_log_max_entry);
  wmi_bp_seq_printf(
    a1,
    "WMI management Rx log max size:%d\n",
    v26,
    v27,
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    (unsigned int)wmi_mgmt_rx_log_max_entry);
  wmi_bp_seq_printf(
    a1,
    "WMI diag log max size:%d\n",
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    (unsigned int)wmi_diag_log_max_entry);
  return 0;
}

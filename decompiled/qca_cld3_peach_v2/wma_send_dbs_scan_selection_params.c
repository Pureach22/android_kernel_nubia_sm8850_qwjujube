__int64 __fastcall wma_send_dbs_scan_selection_params(_QWORD *a1)
{
  return 16 * (unsigned int)((unsigned int)wmi_unified_send_dbs_scan_sel_params_cmd(*a1) != 0);
}

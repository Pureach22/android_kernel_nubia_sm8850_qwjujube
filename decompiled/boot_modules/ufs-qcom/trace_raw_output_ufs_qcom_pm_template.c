__int64 __fastcall trace_raw_output_ufs_qcom_pm_template(__int64 a1)
{
  __int64 v1; // x24
  __int64 result; // x0
  __int64 v4; // x25
  __int64 v5; // x0
  int v6; // w20
  int v7; // w21
  const char *v8; // x22
  const char *v9; // x23
  const char *v10; // x0

  v1 = *(_QWORD *)(a1 + 16552);
  result = trace_raw_output_prep();
  if ( (_DWORD)result == 1 )
  {
    v4 = *(unsigned __int16 *)(v1 + 8);
    v5 = trace_print_symbols_seq(a1 + 136, *(int *)(v1 + 12), &trace_raw_output_ufs_qcom_pm_template_symbols);
    v6 = *(_DWORD *)(v1 + 16);
    v7 = *(_DWORD *)(v1 + 20);
    v8 = (const char *)v5;
    v9 = (const char *)trace_print_symbols_seq(
                         a1 + 136,
                         *(int *)(v1 + 24),
                         &trace_raw_output_ufs_qcom_pm_template_symbols_109);
    v10 = (const char *)trace_print_symbols_seq(
                          a1 + 136,
                          *(int *)(v1 + 28),
                          &trace_raw_output_ufs_qcom_pm_template_symbols_110);
    trace_event_printf(
      a1,
      "%s: pm_op = %s, rpm_lvl = %d, spm_lvl = %d, link_state = %s, dev_pwr_mode = %s, err = %d\n",
      (const char *)(v1 + v4),
      v8,
      v6,
      v7,
      v9,
      v10,
      *(_DWORD *)(v1 + 32));
    return trace_handle_return(a1 + 8352);
  }
  return result;
}

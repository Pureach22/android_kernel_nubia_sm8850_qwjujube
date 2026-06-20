__int64 __fastcall pmo_core_psoc_handle_initial_wake_up(
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
  __int64 comp_private_obj; // x19
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  __int64 result; // x0

  if ( !a1 )
    return qdf_trace_msg(
             0x4Du,
             2u,
             "%s: cb ctx/psoc is null",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "pmo_core_psoc_handle_initial_wake_up");
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 4u);
  v18 = *(_QWORD *)(comp_private_obj + 976);
  if ( v18 )
  {
    result = hif_pm_get_wake_irq_type(v18);
    if ( (_DWORD)result == 2 )
      result = hif_rtpm_check_and_request_resume(1u);
  }
  else
  {
    result = qdf_trace_msg(
               0x4Du,
               2u,
               "%s: hif ctx is null, request resume not called",
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               "pmo_core_psoc_handle_initial_wake_up");
  }
  *(_DWORD *)(comp_private_obj + 580) = 1;
  return result;
}

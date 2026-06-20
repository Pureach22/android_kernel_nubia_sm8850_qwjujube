__int64 __fastcall target_if_pmo_set_runtime_pm_in_progress(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x0

  if ( a1 && (v10 = *(_QWORD *)(a1 + 2800)) != 0 && (v11 = *(_QWORD *)(v10 + 16)) != 0 )
    return wmi_set_runtime_pm_inprogress(v11, a2 & 1);
  else
    return qdf_trace_msg(
             0x49u,
             2u,
             "%s: Invalid wmi handle",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "target_if_pmo_set_runtime_pm_in_progress");
}

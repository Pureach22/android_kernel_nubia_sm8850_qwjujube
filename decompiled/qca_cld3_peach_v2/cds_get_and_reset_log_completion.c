__int64 __fastcall cds_get_and_reset_log_completion(_DWORD *a1, _DWORD *a2, _DWORD *a3, _BYTE *a4)
{
  __int64 v6; // x23
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  v6 = gp_cds_context;
  if ( !gp_cds_context )
  {
    printk(&unk_A3062F, "cds_get_global_context", a3, a4);
    v6 = gp_cds_context;
    if ( !gp_cds_context )
      return qdf_trace_msg(
               0x38u,
               2u,
               "%s: cds context is Invalid",
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               "cds_get_and_reset_log_completion");
  }
  qdf_spinlock_acquire(v6 + 128);
  *a1 = *(_DWORD *)(v6 + 108);
  *a2 = *(_DWORD *)(v6 + 112);
  *a3 = *(_DWORD *)(v6 + 116);
  *a4 = *(_BYTE *)(v6 + 121);
  *(_QWORD *)(v6 + 114) = 0;
  *(_QWORD *)(v6 + 108) = 0;
  return qdf_spinlock_release(v6 + 128);
}

__int64 __fastcall sme_qos_del_ts_ind_fnp(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // w8
  const char *v13; // x2
  unsigned int v15; // w21
  double v16; // d0
  double v17; // d1
  double v18; // d2
  double v19; // d3
  double v20; // d4
  double v21; // d5
  double v22; // d6
  double v23; // d7

  if ( !a2 )
  {
    v13 = "%s: Entry is NULL";
    goto LABEL_6;
  }
  v10 = *(_DWORD *)(a2 + 28);
  if ( v10 >= 5 )
  {
    __break(0x5512u);
    return sme_qos_buffer_existing_flows(a1, a2);
  }
  else
  {
    *(_DWORD *)(qword_91F2D8 + 3040LL * *(unsigned __int8 *)(a2 + 16) + 728LL * v10 + 728) = 1;
    if ( (unsigned int)sme_acquire_global_lock(a1 + 12840) )
    {
      v13 = "%s: Unable to obtain lock";
LABEL_6:
      qdf_trace_msg(0x34u, 2u, v13, a3, a4, a5, a6, a7, a8, a9, a10, "sme_qos_del_ts_ind_fnp");
      return 16;
    }
    v15 = ((__int64 (__fastcall *)(__int64, _QWORD, _QWORD, _QWORD))sme_qos_internal_release_req)(
            a1,
            *(unsigned __int8 *)(a2 + 16),
            *(unsigned int *)(a2 + 24),
            0);
    sme_release_global_lock(a1 + 12840);
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: QoS Release return status on Flow %d is %d",
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      "sme_qos_del_ts_ind_fnp",
      *(unsigned int *)(a2 + 24),
      v15);
    return 0;
  }
}

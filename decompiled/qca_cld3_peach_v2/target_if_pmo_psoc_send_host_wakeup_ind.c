__int64 __fastcall target_if_pmo_psoc_send_host_wakeup_ind(
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
  __int64 v9; // x8
  __int64 v10; // x19
  _QWORD *context; // x0
  __int64 v12; // x8
  void (*v13)(void); // x8

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    context = _cds_get_context(71, (__int64)"target_if_pmo_psoc_send_host_wakeup_ind", a2, a3, a4, a5, a6, a7, a8, a9);
    if ( context )
    {
      v12 = context[1];
      if ( v12 )
      {
        v13 = *(void (**)(void))(v12 + 336);
        if ( v13 )
        {
          if ( *((_DWORD *)v13 - 1) != -1666142433 )
            __break(0x8228u);
          v13();
        }
      }
    }
    return wmi_unified_host_wakeup_ind_to_fw_cmd(v10);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Invalid wmi handle",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_pmo_psoc_send_host_wakeup_ind");
    return 4;
  }
}

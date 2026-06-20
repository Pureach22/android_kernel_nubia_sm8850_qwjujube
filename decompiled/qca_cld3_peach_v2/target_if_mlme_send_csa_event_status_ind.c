__int64 __fastcall target_if_mlme_send_csa_event_status_ind(
        __int64 a1,
        unsigned __int8 a2,
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
  __int64 *v11; // x8
  __int64 v12; // x8
  const char *v14; // x2

  v10 = *(_QWORD *)(a1 + 216);
  if ( v10 )
  {
    v11 = *(__int64 **)(v10 + 1240);
    if ( v11 )
    {
      v12 = *v11;
      if ( v12 )
        return wmi_send_csa_event_status_ind(v12, *(unsigned __int8 *)(a1 + 168) | ((unsigned __int64)a2 << 8));
    }
    v14 = "%s: wmi_handle is null";
  }
  else
  {
    v14 = "%s: PDEV is NULL";
  }
  qdf_trace_msg(0x49u, 2u, v14, a3, a4, a5, a6, a7, a8, a9, a10, "target_if_mlme_get_wmi_handle_from_vdev");
  return 16;
}

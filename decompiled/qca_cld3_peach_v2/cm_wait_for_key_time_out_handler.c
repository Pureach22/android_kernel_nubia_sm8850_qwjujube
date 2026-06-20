__int64 __fastcall cm_wait_for_key_time_out_handler(
        __int64 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x8
  unsigned int v11; // w19
  __int64 v12; // x0
  __int64 result; // x0
  const char *v14; // x2

  v9 = *a1;
  v10 = *(_QWORD *)(*a1 + 216);
  v11 = *(unsigned __int8 *)(*a1 + 168);
  if ( !v10 || (v12 = *(_QWORD *)(v10 + 80)) == 0 )
  {
    v14 = "%s: psoc obj is NULL for vdev id %d";
    return qdf_trace_msg(0x68u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "cm_wait_for_key_time_out_handler", v11);
  }
  if ( !mlme_get_psoc_ext_obj_fl(v12) )
  {
    v14 = "%s: psoc mlme obj is NULL for vdev id %d";
    return qdf_trace_msg(0x68u, 2u, v14, a2, a3, a4, a5, a6, a7, a8, a9, "cm_wait_for_key_time_out_handler", v11);
  }
  result = ((__int64 (__fastcall *)(_QWORD))cm_csr_is_ss_wait_for_key)(v11);
  if ( (result & 1) != 0 )
  {
    cm_csr_set_ss_none(v11);
    return mlo_disconnect(v9, 8, 65526, 0);
  }
  return result;
}

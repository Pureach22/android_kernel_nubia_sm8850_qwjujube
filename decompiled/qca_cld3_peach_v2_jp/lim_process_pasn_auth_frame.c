__int64 __fastcall lim_process_pasn_auth_frame(
        __int64 a1,
        unsigned __int8 a2,
        unsigned int *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int8 *v13; // x21
  unsigned int v14; // w23

  v13 = *((unsigned __int8 **)a3 + 2);
  v14 = a3[10];
  qdf_trace_msg(0x35u, 8u, "%s: vdev_id:%d", a4, a5, a6, a7, a8, a9, a10, a11, "lim_process_pasn_auth_frame", a2);
  return lim_send_sme_mgmt_frame_ind(a1, *v13 >> 4, v13, v14 + 24, a2, *a3, a3[2], 0);
}

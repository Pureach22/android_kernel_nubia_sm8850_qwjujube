void *__fastcall qdf_dp_trace_init(void *result, char a2, __int16 a3, char a4, int a5)
{
  char v9; // w23

  l_dp_trace_lock = 0;
  v9 = (char)result;
  g_qdf_dp_trace_data = -1;
  dword_7F7648 = 0;
  dword_7F7652 = 2000;
  if ( byte_7F7658 == 1 )
    result = memset(&g_qdf_dp_trace_tbl, 0, 0x2AF80u);
  byte_7F7658 = 1;
  byte_7F7650 = 1;
  byte_7F7659 = v9 & 1;
  byte_7F765A = v9 & 1;
  byte_7F7667 = a2;
  word_7F7668 = a3;
  dword_7F764C = a5;
  byte_7F7656 = a4;
  byte_7F7657 = a4;
  qword_7F7738 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_7F7740 = (__int64)&qdf_dp_display_data_pkt_record;
  qdf_dp_trace_cb_table = (__int64)&qdf_dp_display_record;
  qword_7F76B0 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_7F7718 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_7F7720 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_7F7728 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_7F7730 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_7F7748 = (__int64)&qdf_dp_display_ptr_record;
  qword_7F7750 = (__int64)&qdf_dp_display_ptr_record;
  qword_7F77C8 = (__int64)&qdf_dp_display_ptr_record;
  qword_7F77D0 = (__int64)&qdf_dp_display_ptr_record;
  qword_7F76E8 = (__int64)&qdf_dp_display_proto_pkt;
  qword_7F76F0 = (__int64)&qdf_dp_display_proto_pkt;
  qword_7F76B8 = (__int64)&qdf_dp_display_proto_pkt;
  qword_7F76C0 = (__int64)&qdf_dp_display_proto_pkt;
  qword_7F76C8 = (__int64)&qdf_dp_display_proto_pkt;
  qword_7F76D0 = (__int64)&qdf_dp_display_mgmt_pkt;
  qword_7F7708 = (__int64)qdf_dp_display_credit_record;
  qword_7F7710 = (__int64)&qdf_dp_display_record;
  qword_7F76F8 = (__int64)&qdf_dp_display_record;
  qword_7F7700 = (__int64)&qdf_dp_display_record;
  qword_7F7758 = (__int64)&qdf_dp_display_record;
  qword_7F7760 = (__int64)&qdf_dp_display_record;
  qword_7F7768 = (__int64)&qdf_dp_display_record;
  qword_7F7770 = (__int64)&qdf_dp_display_record;
  qword_7F7778 = (__int64)&qdf_dp_display_record;
  qword_7F7780 = (__int64)&qdf_dp_display_record;
  qword_7F7788 = (__int64)&qdf_dp_display_record;
  qword_7F7790 = (__int64)&qdf_dp_display_record;
  qword_7F7798 = (__int64)&qdf_dp_display_record;
  qword_7F77A0 = (__int64)&qdf_dp_display_record;
  qword_7F77A8 = (__int64)&qdf_dp_display_record;
  qword_7F77B0 = (__int64)&qdf_dp_display_record;
  qword_7F77B8 = (__int64)&qdf_dp_display_record;
  qword_7F77C0 = (__int64)&qdf_dp_display_record;
  qword_7F77D8 = (__int64)&qdf_dp_display_record;
  qword_7F77E0 = (__int64)&qdf_dp_display_record;
  qword_7F77E8 = (__int64)&qdf_dp_display_record;
  qword_7F77F0 = (__int64)&qdf_dp_display_record;
  qword_7F77F8 = (__int64)&qdf_dp_display_record;
  qword_7F7800 = (__int64)&qdf_dp_display_record;
  qword_7F76D8 = (__int64)&qdf_dp_display_event_record;
  qword_7F76E0 = (__int64)&qdf_dp_display_record;
  qword_7F7808 = (__int64)qdf_dp_unused;
  return result;
}

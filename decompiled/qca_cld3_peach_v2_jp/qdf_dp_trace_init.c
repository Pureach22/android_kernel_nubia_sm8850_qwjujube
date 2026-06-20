void *__fastcall qdf_dp_trace_init(void *result, char a2, __int16 a3, char a4, int a5)
{
  char v9; // w23

  l_dp_trace_lock = 0;
  v9 = (char)result;
  g_qdf_dp_trace_data = -1;
  dword_73EC18 = 0;
  dword_73EC22 = 2000;
  if ( byte_73EC28 == 1 )
    result = memset(&g_qdf_dp_trace_tbl, 0, 0x2AF80u);
  byte_73EC28 = 1;
  byte_73EC20 = 1;
  byte_73EC29 = v9 & 1;
  byte_73EC2A = v9 & 1;
  byte_73EC37 = a2;
  word_73EC38 = a3;
  dword_73EC1C = a5;
  byte_73EC26 = a4;
  byte_73EC27 = a4;
  qword_73ED08 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_73ED10 = (__int64)&qdf_dp_display_data_pkt_record;
  qdf_dp_trace_cb_table = (__int64)&qdf_dp_display_record;
  qword_73EC80 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_73ECE8 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_73ECF0 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_73ECF8 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_73ED00 = (__int64)&qdf_dp_display_data_pkt_record;
  qword_73ED18 = (__int64)&qdf_dp_display_ptr_record;
  qword_73ED20 = (__int64)&qdf_dp_display_ptr_record;
  qword_73ED98 = (__int64)&qdf_dp_display_ptr_record;
  qword_73EDA0 = (__int64)&qdf_dp_display_ptr_record;
  qword_73ECB8 = (__int64)&qdf_dp_display_proto_pkt;
  qword_73ECC0 = (__int64)&qdf_dp_display_proto_pkt;
  qword_73EC88 = (__int64)&qdf_dp_display_proto_pkt;
  qword_73EC90 = (__int64)&qdf_dp_display_proto_pkt;
  qword_73EC98 = (__int64)&qdf_dp_display_proto_pkt;
  qword_73ECA0 = (__int64)&qdf_dp_display_mgmt_pkt;
  qword_73ECD8 = (__int64)qdf_dp_display_credit_record;
  qword_73ECE0 = (__int64)&qdf_dp_display_record;
  qword_73ECC8 = (__int64)&qdf_dp_display_record;
  qword_73ECD0 = (__int64)&qdf_dp_display_record;
  qword_73ED28 = (__int64)&qdf_dp_display_record;
  qword_73ED30 = (__int64)&qdf_dp_display_record;
  qword_73ED38 = (__int64)&qdf_dp_display_record;
  qword_73ED40 = (__int64)&qdf_dp_display_record;
  qword_73ED48 = (__int64)&qdf_dp_display_record;
  qword_73ED50 = (__int64)&qdf_dp_display_record;
  qword_73ED58 = (__int64)&qdf_dp_display_record;
  qword_73ED60 = (__int64)&qdf_dp_display_record;
  qword_73ED68 = (__int64)&qdf_dp_display_record;
  qword_73ED70 = (__int64)&qdf_dp_display_record;
  qword_73ED78 = (__int64)&qdf_dp_display_record;
  qword_73ED80 = (__int64)&qdf_dp_display_record;
  qword_73ED88 = (__int64)&qdf_dp_display_record;
  qword_73ED90 = (__int64)&qdf_dp_display_record;
  qword_73EDA8 = (__int64)&qdf_dp_display_record;
  qword_73EDB0 = (__int64)&qdf_dp_display_record;
  qword_73EDB8 = (__int64)&qdf_dp_display_record;
  qword_73EDC0 = (__int64)&qdf_dp_display_record;
  qword_73EDC8 = (__int64)&qdf_dp_display_record;
  qword_73EDD0 = (__int64)&qdf_dp_display_record;
  qword_73ECA8 = (__int64)&qdf_dp_display_event_record;
  qword_73ECB0 = (__int64)&qdf_dp_display_record;
  qword_73EDD8 = (__int64)qdf_dp_unused;
  return result;
}

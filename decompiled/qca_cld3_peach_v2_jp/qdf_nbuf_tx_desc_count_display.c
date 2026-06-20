__int64 qdf_nbuf_tx_desc_count_display()
{
  qdf_trace_msg(56, 8, "%s: Current Snapshot of the Driver:", "qdf_nbuf_tx_desc_count_display");
  qdf_trace_msg(56, 8, "%s: Data Packets:", "qdf_nbuf_tx_desc_count_display");
  qdf_trace_msg(
    56,
    8,
    "%s: HDD %d TXRX_Q %d TXRX %d HTT %d",
    "qdf_nbuf_tx_desc_count_display",
    dword_7169CC - (qword_7169D8 + qword_7169D0) + HIDWORD(qword_7169D0),
    qword_7169D0 - HIDWORD(qword_7169D0),
    qword_7169D8 - HIDWORD(qword_7169D8),
    HIDWORD(qword_7169D8) - qword_7169E0);
  qdf_trace_msg(
    56,
    8,
    "%s:  HTC %d  HIF %d CE %d TX_COMP %d",
    "qdf_nbuf_tx_desc_count_display",
    qword_7169E0 - HIDWORD(qword_7169E0),
    HIDWORD(qword_7169E0) - qword_7169E8,
    qword_7169E8 - HIDWORD(qword_7169E8),
    HIDWORD(qword_7169E8));
  qdf_trace_msg(56, 8, "%s: Mgmt Packets:", "qdf_nbuf_tx_desc_count_display");
  return qdf_trace_msg(
           56,
           8,
           "%s: TXRX_Q %d TXRX %d HTT %d HTC %d HIF %d CE %d TX_COMP %d",
           "qdf_nbuf_tx_desc_count_display",
           (int)qword_716A00 - HIDWORD(qword_716A00),
           (int)qword_716A08 - HIDWORD(qword_716A08),
           HIDWORD(qword_716A08) - (int)qword_716A10,
           (int)qword_716A10 - HIDWORD(qword_716A10),
           HIDWORD(qword_716A10) - (int)qword_716A18,
           (int)qword_716A18 - HIDWORD(qword_716A18),
           HIDWORD(qword_716A18));
}

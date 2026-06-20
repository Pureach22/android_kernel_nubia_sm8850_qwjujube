__int64 qdf_nbuf_tx_desc_count_display()
{
  qdf_trace_msg(56, 8, "%s: Current Snapshot of the Driver:", "qdf_nbuf_tx_desc_count_display");
  qdf_trace_msg(56, 8, "%s: Data Packets:", "qdf_nbuf_tx_desc_count_display");
  qdf_trace_msg(
    56,
    8,
    "%s: HDD %d TXRX_Q %d TXRX %d HTT %d",
    "qdf_nbuf_tx_desc_count_display",
    dword_7CF3FC - (qword_7CF408 + qword_7CF400) + HIDWORD(qword_7CF400),
    qword_7CF400 - HIDWORD(qword_7CF400),
    qword_7CF408 - HIDWORD(qword_7CF408),
    HIDWORD(qword_7CF408) - qword_7CF410);
  qdf_trace_msg(
    56,
    8,
    "%s:  HTC %d  HIF %d CE %d TX_COMP %d",
    "qdf_nbuf_tx_desc_count_display",
    qword_7CF410 - HIDWORD(qword_7CF410),
    HIDWORD(qword_7CF410) - qword_7CF418,
    qword_7CF418 - HIDWORD(qword_7CF418),
    HIDWORD(qword_7CF418));
  qdf_trace_msg(56, 8, "%s: Mgmt Packets:", "qdf_nbuf_tx_desc_count_display");
  return qdf_trace_msg(
           56,
           8,
           "%s: TXRX_Q %d TXRX %d HTT %d HTC %d HIF %d CE %d TX_COMP %d",
           "qdf_nbuf_tx_desc_count_display",
           (int)qword_7CF430 - HIDWORD(qword_7CF430),
           (int)qword_7CF438 - HIDWORD(qword_7CF438),
           HIDWORD(qword_7CF438) - (int)qword_7CF440,
           (int)qword_7CF440 - HIDWORD(qword_7CF440),
           HIDWORD(qword_7CF440) - (int)qword_7CF448,
           (int)qword_7CF448 - HIDWORD(qword_7CF448),
           HIDWORD(qword_7CF448));
}

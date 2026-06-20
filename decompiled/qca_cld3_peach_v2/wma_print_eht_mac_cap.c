__int64 __fastcall wma_print_eht_mac_cap(
        _DWORD *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  int v19; // [xsp+0h] [xbp-10h]
  __int64 v20; // [xsp+0h] [xbp-10h]
  int v21; // [xsp+8h] [xbp-8h]

  v21 = (*a1 >> 5) & 1;
  v19 = (*a1 >> 4) & 1;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: EHT MAC Cap: EPCS Priority Access: 0x%01x OM Control: 0x%01x, Trig TXOP Sharing: mode1 0x%01x mode2 0x%01x, Rest"
    "ricted TWT 0x%01x SCS Traffic Desc 0x%01x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "wma_print_eht_mac_cap",
    *a1 & 1,
    (*a1 >> 1) & 1,
    (*a1 >> 2) & 1,
    (*a1 >> 3) & 1,
    v19,
    v21);
  LODWORD(v20) = (*a1 >> 12) & 3;
  return qdf_trace_msg(
           0x36u,
           8u,
           " Max MPDU len 0x%01x, Max A-MPDU Len Exponent Ext 0x%01x EHT TRS 0x%01x, OP In TXOP Sharing Mode2 0x%01x, Two"
           " BQRs 0x%01x, EHT Link Adaptation 0x%01x",
           v10,
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           (unsigned __int8)*a1 >> 6,
           (*a1 >> 8) & 1,
           (*a1 >> 9) & 1,
           (*a1 >> 10) & 1,
           (*a1 >> 11) & 1,
           v20);
}

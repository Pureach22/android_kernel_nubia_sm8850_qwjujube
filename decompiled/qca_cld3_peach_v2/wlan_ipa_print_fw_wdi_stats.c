__int64 __fastcall wlan_ipa_print_fw_wdi_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        unsigned int *a10)
{
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v20; // [xsp+0h] [xbp-30h]
  __int64 v21; // [xsp+0h] [xbp-30h]
  unsigned int v22; // [xsp+8h] [xbp-28h]
  __int64 v23; // [xsp+8h] [xbp-28h]
  unsigned int v24; // [xsp+10h] [xbp-20h]
  unsigned int v25; // [xsp+18h] [xbp-18h]
  unsigned int v26; // [xsp+20h] [xbp-10h]
  unsigned int v27; // [xsp+28h] [xbp-8h]

  v22 = a10[7];
  v20 = a10[6];
  qdf_trace_msg(
    0x61u,
    4u,
    "%s: \n"
    "==== WLAN FW WDI TX STATS ====\n"
    "COMP RING SIZE: %d\n"
    "COMP RING DBELL IND VAL : %d\n"
    "COMP RING DBELL CACHED VAL : %d\n"
    "PKTS ENQ : %d\n"
    "PKTS COMP : %d\n"
    "IS SUSPEND : %d\n",
    a1,
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    "wlan_ipa_print_fw_wdi_stats",
    a10[1],
    a10[3],
    a10[4],
    a10[5],
    v20,
    v22);
  v27 = a10[21];
  v26 = a10[20];
  v25 = a10[19];
  v24 = a10[18];
  LODWORD(v23) = a10[17];
  LODWORD(v21) = a10[16];
  return qdf_trace_msg(
           0x61u,
           4u,
           "%s: \n"
           "==== WLAN FW WDI RX STATS ====\n"
           "IND RING SIZE: %d\n"
           "IND RING DBELL IND VAL : %d\n"
           "IND RING DBELL CACHED VAL : %d\n"
           "RDY IND CACHE VAL : %d\n"
           "RFIL IND : %d\n"
           "NUM PKT INDICAT : %d\n"
           "BUF REFIL : %d\n"
           "NUM DROP NO SPC : %d\n"
           "NUM DROP NO BUF : %d\n"
           "IS SUSPND : %d\n",
           v11,
           v12,
           v13,
           v14,
           v15,
           v16,
           v17,
           v18,
           "wlan_ipa_print_fw_wdi_stats",
           a10[10],
           a10[12],
           a10[13],
           a10[15],
           v21,
           v23,
           v24,
           v25,
           v26,
           v27);
}

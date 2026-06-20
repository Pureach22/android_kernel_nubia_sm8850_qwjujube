unsigned __int8 *__fastcall dp_peer_get_peer_mac_addr(
        unsigned __int8 *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned __int8 *v9; // x19
  int v11; // [xsp+0h] [xbp-20h]
  int v12; // [xsp+8h] [xbp-18h]
  int v13; // [xsp+10h] [xbp-10h]

  v9 = a1 + 44;
  v13 = a1[49];
  v12 = a1[48];
  v11 = a1[47];
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: peer %pK mac 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_peer_get_peer_mac_addr",
    a1,
    a1[44],
    a1[45],
    a1[46],
    v11,
    v12,
    v13);
  return v9;
}

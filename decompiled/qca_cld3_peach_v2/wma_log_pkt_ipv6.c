__int64 __fastcall wma_log_pkt_ipv6(
        __int64 result,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  __int64 v12; // x20
  unsigned int v13; // w19
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // [xsp+0h] [xbp-80h]
  __int64 v31; // [xsp+0h] [xbp-80h]
  int v32; // [xsp+8h] [xbp-78h]
  __int64 v33; // [xsp+8h] [xbp-78h]
  int v34; // [xsp+10h] [xbp-70h]
  __int64 v35; // [xsp+10h] [xbp-70h]
  int v36; // [xsp+18h] [xbp-68h]
  __int64 v37; // [xsp+18h] [xbp-68h]
  int v38; // [xsp+20h] [xbp-60h]
  __int64 v39; // [xsp+20h] [xbp-60h]
  int v40; // [xsp+28h] [xbp-58h]
  __int64 v41; // [xsp+28h] [xbp-58h]
  int v42; // [xsp+30h] [xbp-50h]
  __int64 v43; // [xsp+30h] [xbp-50h]
  int v44; // [xsp+38h] [xbp-48h]
  __int64 v45; // [xsp+38h] [xbp-48h]
  int v46; // [xsp+40h] [xbp-40h]
  __int64 v47; // [xsp+40h] [xbp-40h]
  int v48; // [xsp+48h] [xbp-38h]
  __int64 v49; // [xsp+48h] [xbp-38h]
  int v50; // [xsp+50h] [xbp-30h]
  __int64 v51; // [xsp+50h] [xbp-30h]
  __int64 v52; // [xsp+58h] [xbp-28h]

  if ( a2 >= 0x3E )
  {
    v12 = result;
    v13 = *(unsigned __int16 *)(result + 18);
    v50 = *(unsigned __int8 *)(result + 37);
    v48 = *(unsigned __int8 *)(result + 36);
    v46 = *(unsigned __int8 *)(result + 35);
    v44 = *(unsigned __int8 *)(result + 34);
    v42 = *(unsigned __int8 *)(result + 33);
    v40 = *(unsigned __int8 *)(result + 32);
    v38 = *(unsigned __int8 *)(result + 31);
    v36 = *(unsigned __int8 *)(result + 30);
    v34 = *(unsigned __int8 *)(result + 29);
    v32 = *(unsigned __int8 *)(result + 28);
    v30 = *(unsigned __int8 *)(result + 27);
    qdf_trace_msg(
      0x36u,
      4u,
      "src addr %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      *(unsigned __int8 *)(result + 22),
      *(unsigned __int8 *)(result + 23),
      *(unsigned __int8 *)(result + 24),
      *(unsigned __int8 *)(result + 25),
      *(unsigned __int8 *)(result + 26),
      v30,
      v32,
      v34,
      v36,
      v38,
      v40,
      v42,
      v44,
      v46,
      v48,
      v50,
      v52,
      v10,
      v11);
    LODWORD(v51) = *(unsigned __int8 *)(v12 + 53);
    LODWORD(v47) = *(unsigned __int8 *)(v12 + 51);
    LODWORD(v49) = *(unsigned __int8 *)(v12 + 52);
    LODWORD(v45) = *(unsigned __int8 *)(v12 + 50);
    LODWORD(v43) = *(unsigned __int8 *)(v12 + 49);
    LODWORD(v41) = *(unsigned __int8 *)(v12 + 48);
    LODWORD(v39) = *(unsigned __int8 *)(v12 + 47);
    LODWORD(v37) = *(unsigned __int8 *)(v12 + 46);
    LODWORD(v35) = *(unsigned __int8 *)(v12 + 45);
    LODWORD(v33) = *(unsigned __int8 *)(v12 + 44);
    LODWORD(v31) = *(unsigned __int8 *)(v12 + 43);
    qdf_trace_msg(
      0x36u,
      4u,
      "dst addr %02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x:%02x%02x",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      *(unsigned __int8 *)(v12 + 38),
      *(unsigned __int8 *)(v12 + 39),
      *(unsigned __int8 *)(v12 + 40),
      *(unsigned __int8 *)(v12 + 41),
      *(unsigned __int8 *)(v12 + 42),
      v31,
      v33,
      v35,
      v37,
      v39,
      v41,
      v43,
      v45,
      v47,
      v49,
      v51);
    return qdf_trace_msg(
             0x36u,
             4u,
             "%s: Pkt_len: %u, src_port: %u, dst_port: %u",
             v22,
             v23,
             v24,
             v25,
             v26,
             v27,
             v28,
             v29,
             "wma_log_pkt_ipv6",
             bswap32(v13) >> 16,
             bswap32(*(unsigned __int16 *)(v12 + 54)) >> 16,
             bswap32(*(unsigned __int16 *)(v12 + 56)) >> 16);
  }
  return result;
}

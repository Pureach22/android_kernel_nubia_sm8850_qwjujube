__int64 __fastcall wlan_hdd_display_tx_multiq_stats(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10)
{
  __int64 v10; // x16
  int v11; // w8
  int v12; // w9
  int v13; // w10
  int v14; // w11
  int v15; // w12
  int v16; // w13
  int v17; // w14
  int v18; // w15
  _DWORD *v19; // x0

  v10 = 0;
  v11 = 0;
  v12 = 0;
  v13 = 0;
  v14 = 0;
  v15 = 0;
  v16 = 0;
  v17 = 0;
  v18 = 0;
  do
  {
    v19 = (_DWORD *)(*(_QWORD *)(a10 + 55512) + 2716LL + v10);
    v10 += 96;
    v17 += *v19;
    v15 += v19[1];
    v18 += v19[12];
    v16 += v19[13];
    v13 += v19[2];
    v11 += v19[3];
    v14 += v19[14];
    v12 += v19[15];
  }
  while ( v10 != 1536 );
  return qdf_trace_msg(
           0x33u,
           8u,
           "%s: TX_MULTIQ: INV %u skb_hash %u sk_tx_map %u skb_hash_calc %u",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "wlan_hdd_display_tx_multiq_stats",
           (unsigned int)(v18 + v17),
           (unsigned int)(v16 + v15),
           (unsigned int)(v14 + v13),
           (unsigned int)(v12 + v11));
}

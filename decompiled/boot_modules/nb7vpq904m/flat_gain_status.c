__int64 __fastcall flat_gain_status(__int64 a1)
{
  unsigned __int8 *v1; // x20

  v1 = *(unsigned __int8 **)(a1 + 128);
  seq_write();
  seq_printf(
    a1,
    "TX/RX Flat Gain:\t %d\t %d\t %d\t %d\t%d\t %d\t %d\t %d\n",
    v1[156],
    v1[157],
    v1[158],
    v1[159],
    v1[160],
    v1[161],
    v1[162],
    v1[163]);
  return 0;
}

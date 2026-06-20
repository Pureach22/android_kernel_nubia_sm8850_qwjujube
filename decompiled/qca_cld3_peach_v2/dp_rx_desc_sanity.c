__int64 __fastcall dp_rx_desc_sanity(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned __int8 (__fastcall *v16)(_QWORD); // x8
  int v17; // w9
  int v18; // w8
  int v19; // w10
  int v20; // w8
  __int64 v23; // x22

  if ( a5 )
  {
    v16 = *(unsigned __int8 (__fastcall **)(_QWORD))(*(_QWORD *)(a2 + 74392) + 1440LL);
    if ( *((_DWORD *)v16 - 1) != 1690911915 )
      __break(0x8228u);
    v17 = v16(a4);
    v18 = *(_DWORD *)(a1 + 20060);
    v19 = v18 + 1;
    v20 = v18 + 3;
    if ( v19 == v17 || v20 == v17 )
      return 0;
  }
  if ( a1 )
    ++*(_DWORD *)(a1 + 14108);
  v23 = jiffies;
  if ( dp_rx_desc_sanity___last_ticks - jiffies + 125 < 0 )
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: Sanity failed for ring Desc:",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "dp_rx_desc_sanity");
    dp_rx_desc_sanity___last_ticks = v23;
  }
  ((void (__fastcall *)(__int64, __int64, __int64, _QWORD))qdf_trace_hex_dump)(
    69,
    5,
    a4,
    (unsigned int)(4 * *(_DWORD *)(a3 + 44)));
  return 29;
}

__int64 __fastcall util_validate_bv_mlie_min_seq_len(
        unsigned __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x20
  __int64 v10; // x20

  if ( a1 <= 5 )
  {
    v9 = jiffies;
    if ( util_validate_bv_mlie_min_seq_len___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload of len %zu doesn't accommodate the mandatory BV ML IE Common info len field",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "util_validate_bv_mlie_min_seq_len",
        5);
      util_validate_bv_mlie_min_seq_len___last_ticks = v9;
    }
    return 27;
  }
  if ( a1 <= 0xB )
  {
    v10 = jiffies;
    if ( util_validate_bv_mlie_min_seq_len___last_ticks_235 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x8Fu,
        2u,
        "%s: ML seq payload of len %zu doesn't accommodate the mandatory MLD addr",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "util_validate_bv_mlie_min_seq_len",
        a1);
      util_validate_bv_mlie_min_seq_len___last_ticks_235 = v10;
    }
    return 27;
  }
  return 0;
}

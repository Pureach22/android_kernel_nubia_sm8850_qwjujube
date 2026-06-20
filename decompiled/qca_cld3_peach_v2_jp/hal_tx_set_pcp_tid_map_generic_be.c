__int64 __fastcall hal_tx_set_pcp_tid_map_generic_be(__int64 a1, unsigned __int8 *a2)
{
  return hal_write32_mb_1(
           a1,
           10766016,
           (*a2
          | (8 * a2[1])
          | (a2[2] << 6)
          | (a2[3] << 9)
          | (a2[4] << 12)
          | (a2[5] << 15)
          | (a2[6] << 18)
          | (a2[7] << 21))
         & 0xFFFFFF);
}

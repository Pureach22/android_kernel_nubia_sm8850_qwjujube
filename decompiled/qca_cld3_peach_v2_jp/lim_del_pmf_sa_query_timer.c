void __fastcall lim_del_pmf_sa_query_timer(__int64 a1, __int64 a2)
{
  unsigned int v4; // w21
  __int64 v5; // x26
  __int64 hash_entry; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 v15; // x4
  __int64 v16; // x5
  __int64 v17; // x6
  __int64 v18; // x7
  __int64 v19; // [xsp+0h] [xbp-10h]

  if ( *(_BYTE *)(a1 + 12272) )
  {
    v4 = 0;
    do
    {
      hash_entry = dph_get_hash_entry(a1, ++v4, a2 + 360);
      if ( hash_entry )
      {
        v15 = *(unsigned __int16 *)(hash_entry + 336);
        v16 = *(unsigned __int8 *)(hash_entry + 338);
        v17 = *(unsigned __int8 *)(hash_entry + 339);
        v18 = *(unsigned __int8 *)(hash_entry + 340);
        if ( (*(_WORD *)hash_entry & 0x400) != 0 )
        {
          v5 = hash_entry;
          LODWORD(v19) = *(unsigned __int8 *)(hash_entry + 343);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Deleting pmfSaQueryTimer for assoc-id:%d sta mac%02x:%02x:%02x:**:**:%02x",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "lim_del_pmf_sa_query_timer",
            v15,
            v16,
            v17,
            v18,
            v19);
          tx_timer_deactivate(v5 + 360);
          tx_timer_delete(v5 + 360);
        }
        else
        {
          LODWORD(v19) = *(unsigned __int8 *)(hash_entry + 343);
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: no PMF timer for assoc-id:%d sta mac%02x:%02x:%02x:**:**:%02x",
            v7,
            v8,
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            "lim_del_pmf_sa_query_timer",
            v15,
            v16,
            v17,
            v18,
            v19);
        }
      }
    }
    while ( v4 < *(unsigned __int8 *)(a1 + 12272) );
  }
}

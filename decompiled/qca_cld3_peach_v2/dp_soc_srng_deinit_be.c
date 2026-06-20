__int64 __fastcall dp_soc_srng_deinit_be(__int64 result)
{
  __int64 v1; // x20
  __int64 v2; // x19

  v1 = result + 0x4000;
  if ( (*(_BYTE *)(result + 20096) & 2) != 0 )
  {
    if ( *(_BYTE *)(result + 20121) )
    {
      v2 = result;
      dp_ssr_dump_srng_unregister("rx_refill_buf_ring", 0);
      result = dp_srng_deinit(v2, v2 + 80, 14, 0);
      if ( *(unsigned __int8 *)(v1 + 3737) > 1u )
      {
        dp_ssr_dump_srng_unregister("rx_refill_buf_ring", 1);
        result = dp_srng_deinit(v2, v2 + 160, 14, 0);
        if ( *(unsigned __int8 *)(v1 + 3737) > 2u )
          JUMPOUT(0x5004DC);
      }
    }
  }
  return result;
}

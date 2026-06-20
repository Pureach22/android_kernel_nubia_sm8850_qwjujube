__int64 __fastcall sub_5AFF60(__int64 a1)
{
  int v1; // w30

  if ( !v1 )
  {
    dp_ssr_dump_srng_unregister("rx_refill_buf_ring", 2);
    __break(0x5512u);
    JUMPOUT(0x5004F0);
  }
  return ucfg_dlm_dump_deny_list_ap(a1);
}

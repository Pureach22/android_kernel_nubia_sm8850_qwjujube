__int64 __fastcall lim_continue_bss_peer_create(unsigned __int8 *a1)
{
  unsigned int v2; // w19

  if ( a1 )
  {
    v2 = wma_add_bss_peer_sta(*a1, a1 + 1, 1, 0, 0);
    _qdf_mem_free((__int64)a1);
  }
  else
  {
    return 4;
  }
  return v2;
}

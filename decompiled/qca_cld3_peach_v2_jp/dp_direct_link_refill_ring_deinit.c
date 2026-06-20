__int64 __fastcall dp_direct_link_refill_ring_deinit(_QWORD *a1)
{
  __int64 result; // x0

  result = _cds_get_context(71, "dp_direct_link_refill_ring_deinit");
  if ( result )
  {
    result = dp_destroy_direct_link_refill_ring(result, *(unsigned __int8 *)(*(_QWORD *)(*a1 + 8LL) + 40LL));
    a1[2] = 0;
  }
  return result;
}

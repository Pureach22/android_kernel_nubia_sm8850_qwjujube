__int64 __fastcall ce_ring_cleanup_srng(__int64 result, __int64 a2, unsigned __int8 a3)
{
  __int64 v3; // x1

  if ( a3 <= 2u )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(8LL * (a3 & 0x1F) + a2 + 136) + 80LL);
    if ( v3 )
      return hal_srng_cleanup(*(_QWORD *)(result + 2560), v3, 0);
  }
  return result;
}

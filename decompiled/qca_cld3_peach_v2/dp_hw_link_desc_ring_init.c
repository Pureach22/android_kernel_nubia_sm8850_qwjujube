__int64 __fastcall dp_hw_link_desc_ring_init(__int64 a1)
{
  if ( *(_QWORD *)(a1 + 1968) && (unsigned int)dp_srng_init(a1) )
    return 16;
  else
    return 0;
}

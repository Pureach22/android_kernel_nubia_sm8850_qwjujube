__int64 __usercall sub_4375F0@<X0>(__int64 a1@<X8>)
{
  int v1; // w15
  int v2; // w21

  *(_DWORD *)(a1 - 128) = v2;
  *(_DWORD *)(a1 - 124) = v1;
  return sme_power_debug_stats_req();
}

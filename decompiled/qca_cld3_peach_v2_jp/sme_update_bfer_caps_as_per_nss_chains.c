__int64 __fastcall sme_update_bfer_caps_as_per_nss_chains(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30
  int v12; // w8
  __int64 v13; // x19

  if ( ((*(_DWORD *)(*(_QWORD *)(result + 8) + 3248LL) >> 3) & 7u) >= *(unsigned __int8 *)(result + 6) )
    v12 = *(unsigned __int8 *)(result + 6);
  else
    v12 = (*(_DWORD *)(*(_QWORD *)(result + 8) + 3248LL) >> 3) & 7;
  if ( v12 == 1 )
  {
    v13 = result;
    result = qdf_trace_msg(
               0x34u,
               8u,
               "%s: ini support %d and firmware support %d",
               a3,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               "sme_update_bfer_caps_as_per_nss_chains",
               v10,
               v11);
    if ( *(_BYTE *)(v13 + 6) == 1 )
    {
      *(_DWORD *)(a2 + 132) = 0;
      *(_QWORD *)(a2 + 353) &= ~0x10000uLL;
    }
    *(_BYTE *)(*(_QWORD *)(v13 + 8) + 2622LL) = 0;
    *(_BYTE *)(*(_QWORD *)(v13 + 8) + 2625LL) = 0;
    *(_BYTE *)(*(_QWORD *)(v13 + 8) + 2626LL) = 0;
  }
  return result;
}

__int64 __fastcall sme_update_tgt_services(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  __int64 v14; // x5

  result = mlme_get_psoc_ext_obj_fl(*(_QWORD *)(a1 + 21624));
  if ( result )
  {
    *(_BYTE *)(a1 + 22028) = *(_BYTE *)(a2 + 49);
    *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1072LL) = *(_DWORD *)(a2 + 28) != 0;
    *(_BYTE *)(a1 + 21576) = *(_BYTE *)(a2 + 25);
    *(_BYTE *)(a1 + 21577) = *(_BYTE *)(a2 + 26);
    *(_BYTE *)(result + 2713) = *(_BYTE *)(a2 + 44);
    v13 = *(unsigned __int8 *)(a1 + 22028);
    v14 = *(unsigned __int8 *)(a1 + 21577);
    *(_BYTE *)(a1 + 21692) = *(_BYTE *)(a2 + 46);
    result = qdf_trace_msg(
               0x34u,
               8u,
               "%s: obss_scan_offload: %d pmf_offload: %d fils_roam support %d 11k_offload %d",
               v5,
               v6,
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               "sme_update_tgt_services",
               v13,
               v14,
               *(unsigned __int8 *)(result + 2713));
    *(_BYTE *)(a1 + 22029) = *(_BYTE *)(a2 + 50);
  }
  return result;
}

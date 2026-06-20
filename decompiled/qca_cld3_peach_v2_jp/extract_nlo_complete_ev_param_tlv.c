__int64 __fastcall extract_nlo_complete_ev_param_tlv(int a1, __int64 *a2, _DWORD *a3)
{
  __int64 v3; // x20

  v3 = *a2;
  qdf_mem_set(a3, 0x30u, 0);
  a3[1] = 11;
  *a3 = *(_DWORD *)(v3 + 4);
  return 0;
}

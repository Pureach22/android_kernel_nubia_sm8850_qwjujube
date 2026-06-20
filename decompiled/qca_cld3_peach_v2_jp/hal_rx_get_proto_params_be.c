__int64 __fastcall hal_rx_get_proto_params_be(__int64 a1, bool *a2)
{
  *a2 = (*(_DWORD *)(a1 + 44) & 0x1000) != 0;
  a2[1] = (*(_DWORD *)(a1 + 44) & 0x2000) != 0;
  a2[2] = (*(_DWORD *)(a1 + 44) & 0x800) != 0;
  return 0;
}

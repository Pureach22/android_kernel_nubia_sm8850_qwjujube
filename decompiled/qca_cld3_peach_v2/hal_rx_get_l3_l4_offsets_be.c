__int64 __fastcall hal_rx_get_l3_l4_offsets_be(__int64 a1, int *a2, _DWORD *a3)
{
  int v3; // w8

  *a2 = *(_WORD *)(a1 + 42) & 0x7F;
  v3 = *(unsigned __int8 *)(a1 + 43);
  *a3 = v3;
  return 0;
}

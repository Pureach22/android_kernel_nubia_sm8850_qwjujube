__int64 __fastcall hal_rx_flow_delete_entry_be(__int64 a1, __int64 a2)
{
  int v2; // w8

  v2 = *(_DWORD *)(a2 + 36);
  if ( (v2 & 0x100) == 0 )
    return 17;
  *(_DWORD *)(a2 + 36) = v2 & 0xFFFFFEFF;
  return 0;
}

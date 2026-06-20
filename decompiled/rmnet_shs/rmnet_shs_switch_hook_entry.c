__int64 __fastcall rmnet_shs_switch_hook_entry(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a1 + 41) )
    return 0;
  if ( *(_DWORD *)(a1 + 144) == 55834 )
    return 0;
  *(_BYTE *)(a1 + 41) = 1;
  rmnet_shs_assign(a1, a2);
  return 1;
}

__int64 __fastcall peer_delete_mlo_params_size(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 4) || *(_BYTE *)(a1 + 8) == 1 )
    return 16;
  else
    return 4;
}

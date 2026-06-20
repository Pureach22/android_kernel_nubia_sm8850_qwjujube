__int64 __fastcall peer_assoc_mlo_params_size(__int64 a1)
{
  __int64 v1; // x8

  v1 = 76;
  if ( *(_BYTE *)(a1 + 866) )
    v1 = 144;
  return v1 + 68LL * *(unsigned __int8 *)(a1 + 696);
}

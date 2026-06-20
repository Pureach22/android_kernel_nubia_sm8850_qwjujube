bool __fastcall lim_is_sme_deauth_req_valid(__int64 a1, __int64 a2)
{
  _BOOL8 result; // x0

  result = true;
  if ( (*(_BYTE *)(a2 + 11) & 1) != 0 && (*(_DWORD *)(a2 + 11) != -1 || *(__int16 *)(a2 + 15) != -1) )
    return false;
  return result;
}

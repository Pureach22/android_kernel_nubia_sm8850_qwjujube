__int64 __fastcall lim_check_and_reset_protection_params(__int64 a1)
{
  __int64 result; // x0

  result = pe_get_active_session_count(a1);
  if ( !(_BYTE)result )
    *(_DWORD *)(a1 + 12232) = 0;
  return result;
}

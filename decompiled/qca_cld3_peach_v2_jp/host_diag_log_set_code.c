__int64 __fastcall host_diag_log_set_code(__int64 result, __int16 a2)
{
  if ( result )
    *(_WORD *)(result + 2) = a2;
  return result;
}

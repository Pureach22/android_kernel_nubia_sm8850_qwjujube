__int64 __fastcall ucfg_dp_rx_skip_fisa(int a1)
{
  __int64 result; // x0

  result = dp_get_context();
  if ( result )
    return dp_rx_skip_fisa(result, a1);
  return result;
}

__int64 __fastcall csr_nonscan_active_ll_peek_head(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 result; // x0

  result = wlan_serialization_peek_head_active_cmd_using_psoc(
             *(_QWORD *)(a1 + 21552),
             0,
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9);
  if ( result )
  {
    if ( *(_DWORD *)(result + 16) )
      return 0;
    else
      return *(_QWORD *)(result + 40);
  }
  return result;
}

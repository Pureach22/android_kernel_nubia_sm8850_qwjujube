__int64 __fastcall rpmh_tx_done(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 216);
  if ( result )
    return complete();
  return result;
}

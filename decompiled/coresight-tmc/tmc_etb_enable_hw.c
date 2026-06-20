__int64 __fastcall tmc_etb_enable_hw(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x8
  unsigned int v4; // w19

  result = coresight_claim_device(*(_QWORD *)(a1 + 16));
  if ( !(_DWORD)result )
  {
    result = _tmc_etb_enable_hw(a1);
    if ( (_DWORD)result )
    {
      v3 = *(_QWORD *)(a1 + 16);
      v4 = result;
      coresight_disclaim_device(v3);
      return v4;
    }
  }
  return result;
}

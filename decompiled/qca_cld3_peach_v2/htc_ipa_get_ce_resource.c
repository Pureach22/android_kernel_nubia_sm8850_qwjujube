__int64 __fastcall htc_ipa_get_ce_resource(__int64 *a1)
{
  __int64 result; // x0

  result = *a1;
  if ( result )
    return hif_ipa_get_ce_resource(result);
  return result;
}

__int64 __fastcall mmrm_get_platform_data(__int64 a1)
{
  __int64 result; // x0

  result = of_match_node(&mmrm_dt_match, *(_QWORD *)(a1 + 744));
  if ( result )
    return *(_QWORD *)(result + 192);
  return result;
}

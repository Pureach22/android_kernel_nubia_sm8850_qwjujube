__int64 __fastcall mlme_is_flexible_twt_enabled(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
    return (*(unsigned __int8 *)(result + 1312) >> 6) & 1;
  return result;
}

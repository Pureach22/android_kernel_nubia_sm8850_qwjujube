__int64 __fastcall cm_is_fast_roam_enabled(__int64 a1)
{
  __int64 result; // x0

  result = mlme_get_psoc_ext_obj_fl(a1);
  if ( result )
  {
    if ( *(_BYTE *)(result + 1767) == 1 )
      return (*(_BYTE *)(result + 1685) & 1) != 0 || (unsigned int)policy_mgr_get_connection_count(a1) < 2;
    else
      return 0;
  }
  return result;
}

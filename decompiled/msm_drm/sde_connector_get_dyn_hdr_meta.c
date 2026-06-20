__int64 __fastcall sde_connector_get_dyn_hdr_meta(__int64 result)
{
  if ( result )
    return *(_QWORD *)(result + 2512) + 3192LL;
  return result;
}

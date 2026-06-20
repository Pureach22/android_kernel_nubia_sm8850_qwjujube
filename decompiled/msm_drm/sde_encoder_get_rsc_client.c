__int64 __fastcall sde_encoder_get_rsc_client(__int64 result)
{
  if ( result )
    return *(_QWORD *)(result + 624);
  return result;
}

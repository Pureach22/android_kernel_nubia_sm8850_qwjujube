bool __fastcall sde_encoder_is_self_refresh_completed(_BOOL8 result)
{
  __int64 v1; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 328);
    return v1 && *(unsigned __int16 *)(v1 + 2608) == 0;
  }
  return result;
}

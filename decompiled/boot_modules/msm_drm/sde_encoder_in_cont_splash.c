__int64 __fastcall sde_encoder_in_cont_splash(__int64 result)
{
  __int64 v1; // x8

  if ( result )
  {
    v1 = *(_QWORD *)(result + 328);
    if ( v1 )
      return *(unsigned __int8 *)(v1 + 2289);
    else
      return 0;
  }
  return result;
}

__int64 __fastcall sde_plane_clear_multirect(__int64 result)
{
  if ( result )
    *(_QWORD *)(result + 1776) = 0;
  return result;
}

__int64 __fastcall sde_plane_get_disp_op(__int64 result)
{
  __int64 v1; // x8

  if ( result )
  {
    if ( *(_QWORD *)result && (v1 = *(_QWORD *)(*(_QWORD *)result + 56LL)) != 0 )
      return *(unsigned int *)(v1 + 5912);
    else
      return 0;
  }
  return result;
}

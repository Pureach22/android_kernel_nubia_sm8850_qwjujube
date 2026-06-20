__int64 __fastcall cam_mem_mgr_check_for_supported_heaps(_BOOL8 *a1)
{
  __int64 result; // x0
  __int64 v3; // x10
  _BOOL8 v4; // x9

  if ( !a1 )
    return 4294967274LL;
  result = 0;
  v3 = 2;
  if ( qword_391BF8 )
    v3 = 3;
  if ( xmmword_391BE0 == 0 )
    v4 = qword_391BF8 != 0;
  else
    v4 = v3;
  *a1 = v4;
  return result;
}

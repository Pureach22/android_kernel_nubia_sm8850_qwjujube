__int64 __fastcall qdf_idr_destroy(__int64 a1)
{
  if ( !a1 )
    return 4;
  idr_destroy(a1 + 16);
  return 0;
}

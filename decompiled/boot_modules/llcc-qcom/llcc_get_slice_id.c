__int64 __fastcall llcc_get_slice_id(unsigned int *a1)
{
  __int64 result; // x0

  result = 4294967274LL;
  if ( a1 )
  {
    if ( (unsigned __int64)a1 <= 0xFFFFFFFFFFFFF000LL )
      return *a1;
  }
  return result;
}

__int64 __fastcall llcc_get_slice_size(unsigned __int64 a1)
{
  __int64 result; // x0

  result = 0;
  if ( a1 )
  {
    if ( a1 <= 0xFFFFFFFFFFFFF000LL )
      return *(_QWORD *)(a1 + 8);
  }
  return result;
}

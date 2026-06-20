__int64 __fastcall _qdf_mem_vfree(__int64 result)
{
  if ( result )
    return vfree();
  return result;
}

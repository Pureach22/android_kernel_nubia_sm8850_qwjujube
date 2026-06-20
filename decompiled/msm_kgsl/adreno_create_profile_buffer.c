unsigned __int64 __fastcall adreno_create_profile_buffer(unsigned __int64 result)
{
  unsigned __int64 v1; // x8
  unsigned __int64 v2; // x19
  unsigned __int64 v9; // x9

  v1 = *(_QWORD *)(result + 20448);
  v2 = result;
  if ( v1 && v1 < 0xFFFFFFFFFFFFF001LL )
  {
    *(_DWORD *)(result + 20456) = 0;
  }
  else
  {
    result = kgsl_allocate_global(
               result,
               4096,
               0,
               0,
               (*(_DWORD *)(*(_QWORD *)(result + 14264) + 32LL) >> 5) & 0x40,
               "alwayson");
    *(_QWORD *)(v2 + 20448) = result;
    *(_DWORD *)(v2 + 20456) = 0;
    if ( result > 0xFFFFFFFFFFFFF000LL )
      return result;
  }
  _X8 = (unsigned __int64 *)(v2 + 14240);
  __asm { PRFM            #0x11, [X8] }
  do
    v9 = __ldxr(_X8);
  while ( __stxr(v9 | 0x80, _X8) );
  return result;
}

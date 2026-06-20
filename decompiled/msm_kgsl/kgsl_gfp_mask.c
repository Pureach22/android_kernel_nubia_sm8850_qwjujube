__int64 __fastcall kgsl_gfp_mask(int a1)
{
  unsigned int v1; // w9

  if ( a1 <= 0 )
    v1 = 3266;
  else
    v1 = 335874;
  if ( kgsl_sharedmem_noretry_flag )
    return v1 | 0x12000;
  else
    return v1;
}

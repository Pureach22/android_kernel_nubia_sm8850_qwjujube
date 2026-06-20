__int64 __fastcall gen8_get_gpu_slice_info(__int64 result)
{
  __int64 v1; // x19
  int v2; // w20
  int v3; // w8
  unsigned int v4; // w0
  int v5; // w8

  v1 = result;
  v2 = 1;
  v3 = **(_DWORD **)(result + 14264);
  if ( v3 > 526335 )
  {
    if ( v3 == 526336 )
      goto LABEL_16;
    if ( v3 != 526592 )
    {
LABEL_13:
      if ( v3 == 525824 )
        v2 = 3;
      else
        v2 = 7;
      goto LABEL_16;
    }
  }
  else if ( (unsigned int)(v3 - 524800) >= 2 )
  {
    if ( v3 == 525056 )
      goto LABEL_16;
    goto LABEL_13;
  }
  if ( adreno_slice_mask_override != -1 )
    kgsl_regmap_write(result + 13200, (unsigned int)adreno_slice_mask_override);
  v4 = kgsl_regmap_read(v1 + 13200);
  if ( **(_DWORD **)(v1 + 14264) == 526592 )
    v5 = 7;
  else
    v5 = 15;
  v2 = v5 & v4;
  result = _sw_hweight32(v5 & v4);
  *(_DWORD *)(v1 + 14248) |= 16 * (result & 0xF);
LABEL_16:
  *(_DWORD *)(v1 + 24612) = v2;
  return result;
}

__int64 __fastcall sde_hw_sw_fuse_init(__int64 a1, int a2, unsigned int *a3)
{
  __int64 result; // x0
  unsigned int v7; // w9
  unsigned int v8; // w8
  int v9; // w8

  result = _kmalloc_cache_noprof(_drm_debug, 3520, 40);
  if ( !result )
    return -12;
  v7 = *a3;
  *(_QWORD *)result = a1;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = a2;
  v8 = HIWORD(v7);
  *(_DWORD *)(result + 20) = v7;
  if ( HIWORD(v7) - 49155 < 2u )
  {
    v9 = 136;
  }
  else if ( v8 == 53248 )
  {
    v9 = 132;
  }
  else if ( v8 == 49152 )
  {
    v9 = 124;
  }
  else
  {
    v9 = 0;
  }
  *(_DWORD *)(result + 32) = v9;
  return result;
}

__int64 __fastcall sde_hw_sid_init(__int64 a1, int a2, int *a3)
{
  __int64 result; // x0
  int v7; // w8
  int v8; // w10
  __int64 (__fastcall *v9)(__int64, int, __int64); // x8

  result = _kmalloc_cache_noprof(_drm_debug, 3520, 40);
  if ( !result )
    return -12;
  v7 = *a3;
  v8 = a3[8];
  *(_QWORD *)result = a1;
  *(_DWORD *)(result + 20) = v7;
  *(_DWORD *)(result + 24) = 0x8000;
  v9 = sde_hw_set_vm_sid;
  if ( v8 == 512 )
    v9 = sde_hw_set_vm_sid_v2;
  *(_DWORD *)(result + 8) = 0;
  *(_DWORD *)(result + 12) = a2;
  *(_QWORD *)(result + 32) = v9;
  return result;
}

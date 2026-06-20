__int64 __fastcall drm_dp_mst_add_port(__int64 a1, __int64 a2, __int64 a3, char a4)
{
  __int64 result; // x0
  __int64 v9; // x11
  __int64 v10; // x21
  __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x1
  unsigned int v20; // w8

  result = _kmalloc_cache_noprof(get_random_bytes, 3520, 1656);
  if ( !result )
    return result;
  *(_DWORD *)result = 1;
  *(_DWORD *)(result + 4) = 1;
  v9 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(result + 1616) = a3;
  *(_BYTE *)(result + 8) = a4;
  *(_QWORD *)(result + 1632) = a2;
  v10 = result;
  *(_QWORD *)(result + 48) = "DPMST";
  *(_QWORD *)(result + 1296) = v9;
  *(_BYTE *)(result + 1600) = 1;
  *(_QWORD *)(result + 1304) = a1;
  drm_dp_remote_aux_init((_QWORD *)(result + 48));
  _X0 = (unsigned int *)(a3 + 4);
  __asm { PRFM            #0x11, [X0] }
  do
    v20 = __ldxr(_X0);
  while ( __stxr(v20 + 1, _X0) );
  if ( !v20 )
  {
    v14 = 2;
    goto LABEL_13;
  }
  if ( (((v20 + 1) | v20) & 0x80000000) != 0 )
  {
    v14 = 1;
LABEL_13:
    refcount_warn_saturate(_X0, v14);
  }
  v12 = *(_QWORD *)(*(_QWORD *)(a3 + 64) + 104LL);
  if ( v12 )
    v13 = *(_QWORD *)(v12 + 8);
  else
    v13 = 0;
  _drm_dev_dbg(0, v13, 1, "mstb %p (%d)\n", (const void *)a3, *(_DWORD *)(a3 + 4));
  return v10;
}

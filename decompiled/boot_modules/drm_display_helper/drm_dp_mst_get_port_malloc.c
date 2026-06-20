__int64 __fastcall drm_dp_mst_get_port_malloc(__int64 a1)
{
  __int64 v3; // x8
  __int64 v4; // x1
  unsigned int v11; // w8

  _X0 = (unsigned int *)(a1 + 4);
  __asm { PRFM            #0x11, [X0] }
  do
    v11 = __ldxr(_X0);
  while ( __stxr(v11 + 1, _X0) );
  if ( !v11 || (((v11 + 1) | v11) & 0x80000000) != 0 )
    refcount_warn_saturate();
  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 1632) + 104LL);
  if ( v3 )
    v4 = *(_QWORD *)(v3 + 8);
  else
    v4 = 0;
  return _drm_dev_dbg(0, v4, 1, "port %p (%d)\n", (const void *)a1, *(_DWORD *)(a1 + 4));
}

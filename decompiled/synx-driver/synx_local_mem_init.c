void *synx_local_mem_init()
{
  __int64 v0; // x20
  __int64 v1; // x8
  void *result; // x0
  __int64 v3; // x8
  unsigned __int64 v10; // x9

  v0 = synx_dev;
  v1 = *(_QWORD *)(synx_dev + 152);
  if ( v1 )
  {
    memset((void *)(v1 + 8), 0, 0x800u);
    memset((void *)(*(_QWORD *)(v0 + 152) + 2064LL), 0, 0x2000u);
    memset((void *)(*(_QWORD *)(v0 + 152) + 10264LL), 0, 0x2000u);
    memset((void *)(*(_QWORD *)(v0 + 152) + 18464LL), 0, 0x800u);
    result = memset((void *)(*(_QWORD *)(v0 + 152) + 20520LL), 0, 0x800u);
    **(_DWORD **)(v0 + 152) = 0;
    v3 = synx_dev;
    *(_DWORD *)(*(_QWORD *)(synx_dev + 152) + 2056LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v3 + 152) + 10256LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v3 + 152) + 18456LL) = 0;
    *(_DWORD *)(*(_QWORD *)(v3 + 152) + 20512LL) = 0;
    _X8 = (unsigned __int64 *)(*(_QWORD *)(v3 + 152) + 22568LL);
    __asm { PRFM            #0x11, [X8] }
    do
      v10 = __ldxr(_X8);
    while ( __stxr(v10 | 1, _X8) );
  }
  return result;
}

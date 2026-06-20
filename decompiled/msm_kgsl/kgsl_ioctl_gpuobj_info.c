__int64 __fastcall kgsl_ioctl_gpuobj_info(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int v3; // w1
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x9
  __int64 v8; // x8
  int v14; // w8

  v3 = *(_DWORD *)(a3 + 40);
  if ( !v3 )
    return -22;
  _X0 = kgsl_sharedmem_find_id(*(_QWORD *)(a1 + 8), v3);
  if ( !_X0 )
    return -22;
  *(_DWORD *)(a3 + 40) = _X0[62];
  *(_QWORD *)a3 = *((_QWORD *)_X0 + 4);
  *(_QWORD *)(a3 + 8) = *((_QWORD *)_X0 + 10);
  v6 = *((_QWORD *)_X0 + 6);
  *(_QWORD *)(a3 + 16) = v6;
  if ( (_X0[21] & 4) != 0 )
  {
    v7 = 0;
  }
  else if ( (_X0[14] & 1) != 0 )
  {
    v7 = (v6 + 0x1FFF) & 0xFFFFFFFFFFFFF000LL;
  }
  else
  {
    v7 = v6;
  }
  v8 = 0;
  *(_QWORD *)(a3 + 24) = v7;
  *(_QWORD *)(a3 + 32) = 0;
  if ( (unsigned __int64)_X0 <= 0xFFFFFFFFFFFFF000LL )
  {
    __asm { PRFM            #0x11, [X0] }
    do
      v14 = __ldxr(_X0);
    while ( __stlxr(v14 - 1, _X0) );
    if ( v14 == 1 )
    {
      __dmb(9u);
      kgsl_mem_entry_destroy(_X0);
    }
    else if ( v14 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
    return 0;
  }
  return v8;
}

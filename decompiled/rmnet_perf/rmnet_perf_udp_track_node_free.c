__int64 __fastcall rmnet_perf_udp_track_node_free(__int64 a1)
{
  unsigned __int64 v1; // x8
  __int64 v3; // x19
  int v9; // w10
  __int64 v11; // [xsp+18h] [xbp+18h]

  v1 = *(_QWORD *)(a1 + 56);
  if ( v1 && v1 <= 0xFFFFFFFFFFFFF000LL )
  {
    _X9 = (unsigned int *)(v1 + 128);
    __asm { PRFM            #0x11, [X9] }
    do
      v9 = __ldxr(_X9);
    while ( __stlxr(v9 - 1, _X9) );
    if ( v9 == 1 )
    {
      __dmb(9u);
      v3 = a1;
      sk_free(v1);
      a1 = v3;
    }
    else if ( v9 <= 0 )
    {
      v11 = a1;
      refcount_warn_saturate(v1 + 128, 3);
      a1 = v11;
    }
  }
  return kfree(a1 - 16);
}

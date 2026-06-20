__int64 __fastcall drm_dp_mst_destroy_state(__int64 a1, _QWORD *a2)
{
  _QWORD *v3; // x8
  _QWORD *v4; // x21
  unsigned __int64 v5; // x8
  int v6; // w22
  _QWORD *v7; // x22
  __int64 *v8; // x20
  int v15; // w8

  v4 = a2 + 7;
  v3 = (_QWORD *)a2[7];
  if ( v3 != a2 + 7 )
  {
    do
    {
      v7 = (_QWORD *)*v3;
      v8 = v3 - 4;
      if ( (*((_BYTE *)v3 - 12) & 1) == 0 )
        drm_dp_mst_put_port_malloc(*v8);
      kfree(v8);
      v3 = v7;
    }
    while ( v7 != v4 );
  }
  if ( a2[5] )
  {
    v5 = 0;
    v6 = 1;
    do
    {
      _X0 = (unsigned int *)(*(_QWORD *)(a2[4] + 8 * v5) + 8LL);
      __asm { PRFM            #0x11, [X0] }
      do
        v15 = __ldxr(_X0);
      while ( __stlxr(v15 - 1, _X0) );
      if ( v15 == 1 )
      {
        __dmb(9u);
        _drm_crtc_commit_free();
      }
      else if ( v15 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
      v5 = v6++;
    }
    while ( a2[5] > v5 );
  }
  kfree(a2[4]);
  return kfree(a2);
}

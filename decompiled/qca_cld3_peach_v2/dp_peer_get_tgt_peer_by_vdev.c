__int64 __fastcall dp_peer_get_tgt_peer_by_vdev(__int64 a1, __int64 a2)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v11; // x8
  unsigned int v12; // w9
  unsigned int v19; // w11
  __int64 v20; // x19

  v2 = dp_sta_vdev_link_peer_ref_n_get(a1, a2, 2u);
  if ( !v2 )
    return 0;
  v11 = *(_QWORD *)(v2 + 416);
  if ( v11 )
  {
    v12 = *(_DWORD *)(v11 + 40);
    while ( v12 )
    {
      _X13 = (unsigned int *)(v11 + 40);
      __asm { PRFM            #0x11, [X13] }
      while ( 1 )
      {
        v19 = __ldxr(_X13);
        if ( v19 != v12 )
          break;
        if ( !__stlxr(v12 + 1, _X13) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v19 == v12;
      v12 = v19;
      if ( _ZF )
      {
        v20 = *(_QWORD *)(v2 + 416);
        goto LABEL_15;
      }
    }
  }
  v20 = 0;
LABEL_15:
  dp_peer_unref_delete(v2, 2u, v3, v4, v5, v6, v7, v8, v9, v10);
  return v20;
}

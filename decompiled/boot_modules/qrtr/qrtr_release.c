__int64 __fastcall qrtr_release(__int64 a1)
{
  __int64 v1; // x19
  _UNKNOWN **v3; // x9
  __int64 v4; // x8
  void (__fastcall *v5)(_QWORD); // x8
  __int64 v6; // x8
  int v13; // w8

  v1 = *(_QWORD *)(a1 + 24);
  if ( v1 )
  {
    lock_sock_nested(*(_QWORD *)(a1 + 24), 0);
    if ( *(_DWORD *)(v1 + 848) == -2 )
    {
      down_write(&qrtr_epts_lock);
      v3 = (_UNKNOWN **)qrtr_all_epts;
      if ( qrtr_all_epts != (_UNKNOWN *)&qrtr_all_epts )
      {
        do
        {
          *((_DWORD *)v3 - 25) = 0;
          *((_DWORD *)v3 - 24) = 0;
          v3 = (_UNKNOWN **)*v3;
        }
        while ( v3 != &qrtr_all_epts );
      }
      up_write(&qrtr_epts_lock);
    }
    *(_BYTE *)(v1 + 563) = 3;
    v4 = *(_QWORD *)(v1 + 96);
    if ( (v4 & 1) == 0 )
    {
      v5 = *(void (__fastcall **)(_QWORD))(v1 + 680);
      if ( *((_DWORD *)v5 - 1) != -1177737243 )
        __break(0x8228u);
      v5(v1);
      v4 = *(_QWORD *)(v1 + 96);
    }
    *(_QWORD *)(v1 + 96) = v4 | 1;
    raw_write_lock_bh(v1 + 584);
    v6 = *(_QWORD *)(v1 + 96);
    *(_QWORD *)(v1 + 288) = 0;
    *(_QWORD *)(v1 + 256) = 0;
    *(_QWORD *)(v1 + 96) = v6 | 1;
    raw_write_unlock_bh(v1 + 584);
    *(_QWORD *)(a1 + 24) = 0;
    if ( (*(_QWORD *)(v1 + 96) & 0x100) == 0 )
      qrtr_port_remove(v1);
    skb_queue_purge_reason(v1 + 168, 85);
    release_sock(v1);
    _X0 = (unsigned int *)(v1 + 128);
    __asm { PRFM            #0x11, [X0] }
    do
      v13 = __ldxr(_X0);
    while ( __stlxr(v13 - 1, _X0) );
    if ( v13 == 1 )
    {
      __dmb(9u);
      sk_free(v1);
    }
    else if ( v13 <= 0 )
    {
      refcount_warn_saturate(_X0, 3);
    }
  }
  return 0;
}

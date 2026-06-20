__int64 __fastcall qrtr_port_remove(_DWORD *a1)
{
  int v2; // w23
  __int64 v3; // x0
  __int64 v4; // x20
  int v5; // w9
  __int64 v6; // x0
  int v7; // w8
  int v8; // w9
  __int64 v9; // x0
  __int64 v10; // x21
  __int64 v11; // x0
  __int64 v12; // x22
  int v14; // w20
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x20
  __int64 result; // x0
  int v24; // w8
  int v25; // [xsp+Ch] [xbp-14h] BYREF
  unsigned __int64 v26; // [xsp+10h] [xbp-10h]
  __int64 v27; // [xsp+18h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = a1[212];
  v3 = _alloc_skb(52, 3264, 0, 0xFFFFFFFFLL);
  if ( v3 )
  {
    v4 = v3;
    v5 = *(_DWORD *)(v3 + 208) + 32;
    *(_QWORD *)(v3 + 224) += 32LL;
    *(_DWORD *)(v3 + 208) = v5;
    v6 = skb_put();
    *(_QWORD *)(v6 + 4) = 0;
    *(_QWORD *)(v6 + 12) = 0;
    *(_DWORD *)v6 = 6;
    v7 = a1[211];
    v25 = 42;
    *(_DWORD *)(v6 + 4) = v7;
    v8 = a1[212];
    v26 = 0xFFFFFFFEFFFFFFFFLL;
    *(_DWORD *)(v6 + 8) = v8;
    skb_set_owner_w(v4, a1);
    v9 = (unsigned int)a1[216];
    if ( (_DWORD)v9 == -2 )
    {
      qrtr_bcast_enqueue(v9, v4, 6, a1 + 210, &v25, 0);
    }
    else
    {
      if ( (v9 & 0x80000000) == 0 )
      {
        v9 = qrtr_node_lookup(v9);
        if ( v9 )
        {
          v10 = v9;
          v11 = skb_clone(v4, 3264);
          if ( v11 )
          {
            v12 = v11;
            skb_set_owner_w(v11, a1);
            qrtr_node_enqueue(v10, v12, 6, (__int64)(a1 + 210), (__int64)&v25, 0);
          }
          v9 = qrtr_node_release(v10);
        }
      }
      qrtr_local_enqueue(v9, v4, 6, (__int64)(a1 + 210), (__int64)&v25);
    }
  }
  _X0 = a1 + 32;
  __asm { PRFM            #0x11, [X0] }
  do
    v24 = __ldxr(_X0);
  while ( __stlxr(v24 - 1, _X0) );
  if ( v24 <= 1 )
    refcount_warn_saturate(_X0, 4);
  if ( v2 == -2 )
    v14 = 0;
  else
    v14 = v2;
  v15 = raw_spin_lock_irqsave(&qrtr_port_lock);
  v16 = v14;
  v17 = v15;
  xa_erase(&qrtr_ports, v16);
  result = raw_spin_unlock_irqrestore(&qrtr_port_lock, v17);
  _ReadStatusReg(SP_EL0);
  return result;
}

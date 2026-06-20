__int64 __fastcall qrtr_hello_work(__int64 a1)
{
  __int64 v2; // x22
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 result; // x0
  __int64 v7; // x22
  int v8; // w9
  __int64 v9; // x0
  int v10; // w9
  __int64 v11; // x1
  unsigned int v17; // w8
  int v19; // w8
  __int64 v21; // [xsp+8h] [xbp-28h] BYREF
  int v22; // [xsp+10h] [xbp-20h]
  __int64 v23; // [xsp+18h] [xbp-18h] BYREF
  int v24; // [xsp+20h] [xbp-10h]
  __int64 v25; // [xsp+28h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v24 = -2;
  v23 = 42;
  v22 = -2;
  v21 = 42;
  v2 = raw_spin_lock_irqsave(&qrtr_port_lock);
  v3 = xa_load(&qrtr_ports, 0);
  if ( !v3 )
  {
    result = raw_spin_unlock_irqrestore(&qrtr_port_lock, v2);
    goto LABEL_23;
  }
  v4 = v3;
  _X19 = (unsigned int *)(v3 + 128);
  __asm { PRFM            #0x11, [X19] }
  do
    v17 = __ldxr(_X19);
  while ( __stxr(v17 + 1, _X19) );
  if ( v17 )
  {
    if ( (((v17 + 1) | v17) & 0x80000000) == 0 )
      goto LABEL_4;
    v11 = 1;
  }
  else
  {
    v11 = 2;
  }
  refcount_warn_saturate(v3 + 128, v11);
LABEL_4:
  raw_spin_unlock_irqrestore(&qrtr_port_lock, v2);
  result = _alloc_skb(52, 3264, 0, 0xFFFFFFFFLL);
  if ( result )
  {
    v7 = result;
    v8 = *(_DWORD *)(result + 208) + 32;
    *(_QWORD *)(result + 224) += 32LL;
    *(_DWORD *)(result + 208) = v8;
    v9 = skb_put();
    *(_QWORD *)(v9 + 4) = 0;
    *(_DWORD *)v9 = 2;
    *(_QWORD *)(v9 + 12) = 0;
    v10 = *(_DWORD *)(a1 - 228);
    HIDWORD(v23) = qrtr_local_nid;
    HIDWORD(v21) = v10;
    result = qrtr_node_enqueue(a1 - 288, v7, 2, &v23, &v21, 0);
    __asm { PRFM            #0x11, [X19] }
    do
      v19 = __ldxr(_X19);
    while ( __stlxr(v19 - 1, _X19) );
    if ( v19 != 1 )
      goto LABEL_21;
    __dmb(9u);
LABEL_10:
    result = sk_free(v4);
    goto LABEL_23;
  }
  __asm { PRFM            #0x11, [X19] }
  do
    v19 = __ldxr(_X19);
  while ( __stlxr(v19 - 1, _X19) );
  if ( v19 == 1 )
  {
    __dmb(9u);
    goto LABEL_10;
  }
LABEL_21:
  if ( v19 <= 0 )
    result = refcount_warn_saturate(_X19, 3);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}

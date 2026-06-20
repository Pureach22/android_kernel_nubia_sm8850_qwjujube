__int64 __fastcall qrtr_recvmsg(__int64 a1, __int64 *a2, unsigned __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  __int64 v5; // x24
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x20
  unsigned __int64 v11; // x23
  unsigned int v12; // w0
  int v13; // w9
  int v14; // w10
  __int64 v15; // x0
  __int64 v16; // x21
  __int64 v17; // x0
  __int64 v18; // x22
  int v19; // w9
  __int64 v20; // x0
  __int64 v21; // x20
  __int64 result; // x0
  unsigned int v23; // [xsp+Ch] [xbp-24h] BYREF
  _DWORD v24[3]; // [xsp+10h] [xbp-20h] BYREF
  _DWORD v25[3]; // [xsp+1Ch] [xbp-14h] BYREF
  __int64 v26; // [xsp+28h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 24);
  v5 = *a2;
  if ( (*(_QWORD *)(v4 + 96) & 0x100) != 0 )
  {
    result = 4294967197LL;
  }
  else
  {
    v8 = *(_QWORD *)(a1 + 24);
    v23 = 0;
    v9 = skb_recv_datagram(v8, a4, &v23);
    if ( v9 )
    {
      v10 = v9;
      lock_sock_nested(v4, 0);
      v11 = *(int *)(v10 + 112);
      if ( v11 > a3 )
      {
        LODWORD(v11) = a3;
        *((_DWORD *)a2 + 17) |= 0x20u;
      }
      v23 = skb_copy_datagram_iter(v10, 0, a2 + 2, (unsigned int)v11);
      if ( (v23 & 0x80000000) == 0 )
      {
        v23 = v11;
        if ( v5 )
        {
          *(_QWORD *)v5 = 0;
          *(_DWORD *)(v5 + 8) = 0;
          *(_WORD *)v5 = 42;
          *(_DWORD *)(v5 + 4) = *(_DWORD *)(v10 + 40);
          *(_DWORD *)(v5 + 8) = *(_DWORD *)(v10 + 44);
          *((_DWORD *)a2 + 2) = 12;
        }
      }
      if ( *(_BYTE *)(v10 + 57) )
      {
        v12 = *(_DWORD *)(v10 + 40);
        v25[2] = *(_DWORD *)(v10 + 44);
        v13 = *(_DWORD *)(v10 + 48);
        v14 = *(_DWORD *)(v10 + 52);
        v25[0] = 42;
        v25[1] = v12;
        v24[0] = 42;
        v24[1] = v13;
        v24[2] = v14;
        v15 = qrtr_node_lookup(v12);
        if ( v15 )
        {
          v16 = v15;
          v17 = _alloc_skb(52, 3264, 0, 0xFFFFFFFFLL);
          if ( v17 )
          {
            v18 = v17;
            v19 = *(_DWORD *)(v17 + 208) + 32;
            *(_QWORD *)(v17 + 224) += 32LL;
            *(_DWORD *)(v17 + 208) = v19;
            v20 = skb_put();
            *(_QWORD *)(v20 + 4) = 0;
            *(_QWORD *)(v20 + 12) = 0;
            *(_DWORD *)v20 = 7;
            *(_DWORD *)(v20 + 4) = *(_DWORD *)(v10 + 48);
            *(_DWORD *)(v20 + 8) = *(_DWORD *)(v10 + 52);
            qrtr_node_enqueue(v16, v18, 7, (__int64)v24, (__int64)v25, 0);
          }
          qrtr_node_release(v16);
        }
      }
      skb_free_datagram(v4, v10);
      if ( *(_DWORD *)(v4 + 848) == -2 )
      {
        v21 = raw_spin_lock_irqsave(v4 + 908);
        if ( *(_BYTE *)(v4 + 904) == 1 )
        {
          complete_all(v4 + 872);
          *(_BYTE *)(v4 + 904) = 0;
        }
        raw_spin_unlock_irqrestore(v4 + 908, v21);
      }
      release_sock(v4);
    }
    result = v23;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

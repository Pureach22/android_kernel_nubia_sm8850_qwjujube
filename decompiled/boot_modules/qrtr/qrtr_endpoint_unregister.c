__int64 __fastcall qrtr_endpoint_unregister(__int64 a1)
{
  __int64 v1; // x20
  int v2; // w8
  __int64 v3; // x25
  bool v4; // cc
  __int64 v5; // x9
  __int64 v6; // x8
  _QWORD *v7; // x24
  __int64 v8; // t1
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x25
  int v12; // w9
  __int64 v13; // x0
  unsigned int v14; // w27
  _UNKNOWN **v15; // x23
  int v16; // w8
  int v17; // w9
  int v18; // w8
  __int64 v19; // x0
  __int64 v20; // x26
  int v21; // w9
  __int64 v22; // x0
  unsigned int v23; // w8
  __int64 v24; // x0
  __int64 v25; // x9
  __int64 v26; // x8
  _QWORD *v27; // x21
  __int64 v28; // t1
  __int64 result; // x0
  __int64 v31; // [xsp+10h] [xbp-60h] BYREF
  __int64 v32; // [xsp+18h] [xbp-58h]
  __int64 v33; // [xsp+20h] [xbp-50h]
  __int64 v34; // [xsp+28h] [xbp-48h]
  _DWORD v35[3]; // [xsp+30h] [xbp-40h] BYREF
  int v36; // [xsp+3Ch] [xbp-34h] BYREF
  int v37; // [xsp+40h] [xbp-30h]
  int v38; // [xsp+44h] [xbp-2Ch]
  __int64 v39; // [xsp+48h] [xbp-28h] BYREF
  int v40; // [xsp+50h] [xbp-20h]
  __int64 v41; // [xsp+58h] [xbp-18h] BYREF
  int v42; // [xsp+60h] [xbp-10h]
  __int64 v43; // [xsp+68h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(a1 + 8);
  v35[0] = 42;
  v35[1] = qrtr_local_nid;
  v35[2] = -2;
  v2 = *(_DWORD *)(v1 + 60);
  v36 = 42;
  v37 = v2;
  v38 = -2;
  v33 = 0;
  v34 = 0;
  mutex_lock(v1);
  *(_QWORD *)(v1 + 48) = 0;
  mutex_unlock(v1);
  v3 = raw_spin_lock_irqsave(&qrtr_nodes_lock);
  v31 = 0;
  v32 = 0;
LABEL_5:
  while ( 1 )
  {
    v9 = radix_tree_next_chunk(&qrtr_nodes, &v31, 0);
    if ( !v9 )
      break;
    v6 = v31;
    v7 = (_QWORD *)v9;
LABEL_7:
    if ( *v7 == v1 )
    {
      v37 = v6;
      raw_spin_unlock_irqrestore(&qrtr_nodes_lock, v3);
      v10 = _alloc_skb(52, 3264, 0, 0xFFFFFFFFLL);
      if ( v10 )
      {
        v11 = v10;
        v12 = *(_DWORD *)(v10 + 208) + 32;
        *(_QWORD *)(v10 + 224) += 32LL;
        *(_DWORD *)(v10 + 208) = v12;
        v13 = skb_put();
        *(_QWORD *)(v13 + 4) = 0;
        *(_QWORD *)(v13 + 12) = 0;
        *(_DWORD *)v13 = 3;
        qrtr_local_enqueue(v13, v11, 3, &v36, v35);
      }
      v14 = v31;
      v42 = -2;
      v41 = 42;
      v40 = -2;
      v39 = 42;
      down_read(&qrtr_epts_lock);
      v15 = (_UNKNOWN **)qrtr_all_epts;
      if ( qrtr_all_epts != (_UNKNOWN *)&qrtr_all_epts )
      {
        do
        {
          if ( !v1 )
            goto LABEL_22;
          if ( v15 != (_UNKNOWN **)&unk_A8 && v15 - 21 != (_UNKNOWN **)v1 && *((_DWORD *)v15 - 27) != -1 )
          {
            v18 = *((_DWORD *)v15 - 26) - *(_DWORD *)(v1 + 64);
            if ( v18 < 0 )
              v18 = *(_DWORD *)(v1 + 64) - *((_DWORD *)v15 - 26);
            if ( v18 >= 2 )
            {
LABEL_22:
              v19 = _alloc_skb(52, 3264, 0, 0xFFFFFFFFLL);
              if ( !v19 )
                goto LABEL_30;
              v20 = v19;
              v21 = *(_DWORD *)(v19 + 208) + 32;
              *(_QWORD *)(v19 + 224) += 32LL;
              *(_DWORD *)(v19 + 208) = v21;
              v22 = skb_put();
              *(_QWORD *)(v22 + 12) = 0;
              *(_DWORD *)v22 = 13;
              *(_DWORD *)(v22 + 8) = v14;
              if ( v22 )
              {
                v23 = HIWORD(v14) + (unsigned __int16)v14 + 57630;
                if ( v23 >= 0x10000 )
                {
                  v23 = HIWORD(v14) + (unsigned __int16)v14 + 57630;
                  do
                    v23 = HIWORD(v23) + (unsigned __int16)v23;
                  while ( HIWORD(v23) );
                }
                v16 = v23 ^ 0xFFFF;
              }
              else
              {
                v16 = 0;
              }
              *(_DWORD *)(v22 + 4) = v16;
              v17 = *((_DWORD *)v15 - 27);
              HIDWORD(v41) = *(_DWORD *)(v1 + 60);
              HIDWORD(v39) = v17;
              qrtr_node_enqueue(v15 - 21, v20, 13, &v41, &v39, 0);
            }
          }
          v15 = (_UNKNOWN **)*v15;
        }
        while ( v15 != &qrtr_all_epts );
      }
      up_read(&qrtr_epts_lock);
LABEL_30:
      v24 = raw_spin_lock_irqsave(&qrtr_nodes_lock);
      v6 = v31;
      v3 = v24;
    }
    v5 = ~v6 + v32;
    while ( 1 )
    {
      v4 = v5-- < 1;
      if ( v4 )
        break;
      v31 = ++v6;
      v8 = v7[1];
      ++v7;
      if ( v8 )
      {
        if ( v7 )
          goto LABEL_7;
        goto LABEL_5;
      }
    }
  }
  raw_spin_unlock_irqrestore(&qrtr_nodes_lock, v3);
  mutex_lock(v1 + 96);
  v31 = 0;
  v32 = 0;
LABEL_37:
  while ( 1 )
  {
    v27 = (_QWORD *)radix_tree_next_chunk(v1 + 80, &v31, 0);
    if ( !v27 )
      break;
LABEL_38:
    _wake_up(*v27, 1, 0, 0);
    v26 = v31 + 1;
    v25 = ~v31 + v32;
    while ( 1 )
    {
      v4 = v25-- < 1;
      if ( v4 )
        break;
      v31 = v26++;
      v28 = v27[1];
      ++v27;
      if ( v28 )
      {
        if ( v27 )
          goto LABEL_38;
        goto LABEL_37;
      }
    }
  }
  mutex_unlock(v1 + 96);
  result = qrtr_node_release(v1);
  *(_QWORD *)(a1 + 8) = 0;
  _ReadStatusReg(SP_EL0);
  return result;
}

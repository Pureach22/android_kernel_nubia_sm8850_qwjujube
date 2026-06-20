__int64 __fastcall qrtr_sendmsg(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  int v3; // w8
  __int64 v4; // x21
  __int64 result; // x0
  __int64 v6; // x19
  __int64 v10; // x8
  int v11; // w9
  unsigned int v12; // w0
  __int64 v13; // x22
  __int64 (__fastcall *v14)(__int64, __int64, int, __int64, __int64); // x26
  __int64 v15; // x0
  int v16; // w8
  bool v17; // zf
  int v18; // w10
  unsigned int v19; // w0
  unsigned int v20; // w20
  unsigned __int64 v21; // x9
  __int64 v22; // x10
  int v23; // w24
  __int64 v24; // x0
  __int64 v25; // x23
  int v26; // w9
  bool v27; // cc
  __int64 v28; // x24
  int v29; // w8
  __int64 v30; // x11
  __int64 v31; // x9
  __int64 v32; // x2
  __int64 v33; // x0
  int v34; // w9
  __int64 v35; // x0
  int v36; // w9
  int v37; // w8
  int v38; // w2
  __int64 v39; // x0
  int v40; // w8
  int v41; // w0
  __int64 v42; // x20
  unsigned int v43; // [xsp+Ch] [xbp-34h] BYREF
  __int64 v44; // [xsp+10h] [xbp-30h] BYREF
  __int64 v45; // [xsp+18h] [xbp-28h]
  int v46; // [xsp+20h] [xbp-20h]
  int v47; // [xsp+28h] [xbp-18h] BYREF
  _DWORD v48[3]; // [xsp+2Ch] [xbp-14h] BYREF
  __int64 v49; // [xsp+38h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_DWORD *)(a2 + 68);
  v4 = *(_QWORD *)a2;
  v47 = 1;
  if ( (v3 & 0xFFFFFFBF) == 0 )
  {
    if ( a3 >> 16 )
    {
      result = 4294967206LL;
      goto LABEL_72;
    }
    v6 = *(_QWORD *)(a1 + 24);
    v46 = 0;
    v44 = 0;
    v45 = 0;
    v43 = 0;
    lock_sock_nested(v6, 0);
    if ( v4 )
    {
      if ( *(_DWORD *)(a2 + 8) <= 0xBu || *(_WORD *)v4 != 42 )
      {
        release_sock(v6);
        result = 4294967274LL;
        goto LABEL_72;
      }
      if ( (*(_QWORD *)(*(_QWORD *)(a1 + 24) + 96LL) & 0x100) != 0 )
      {
        v48[2] = 0;
        v48[0] = 42;
        v48[1] = qrtr_local_nid;
        v19 = _qrtr_bind(a1, v48, 1);
        v10 = a2;
        v11 = a3;
        v43 = v19;
        if ( v19 )
        {
          v20 = v19;
          release_sock(v6);
          result = v20;
          goto LABEL_72;
        }
        goto LABEL_14;
      }
      v10 = a2;
      v43 = 0;
    }
    else
    {
      if ( *(_BYTE *)(v6 + 18) != 1 )
        goto LABEL_19;
      v10 = a2;
      v4 = v6 + 852;
    }
    v11 = a3;
LABEL_14:
    v12 = *(_DWORD *)(v4 + 4);
    if ( v12 != -1 )
    {
      if ( v12 == *(_DWORD *)(v6 + 844) )
      {
        v13 = 0;
        v14 = qrtr_local_enqueue;
        goto LABEL_32;
      }
      v15 = qrtr_node_lookup(v12);
      if ( !v15 )
      {
        release_sock(v6);
        result = 4294967192LL;
        goto LABEL_72;
      }
      v16 = *(_DWORD *)(v6 + 864);
      v13 = v15;
      if ( v16 < 0 )
      {
        v17 = v16 == -1;
        v11 = a3;
        v10 = a2;
        if ( !v17 )
          goto LABEL_31;
        v18 = *(_DWORD *)(v15 + 60);
      }
      else
      {
        v17 = v16 == *(_DWORD *)(v15 + 60);
        v11 = a3;
        v10 = a2;
        if ( v17 )
        {
LABEL_31:
          v14 = (__int64 (__fastcall *)(__int64, __int64, int, __int64, __int64))qrtr_node_enqueue;
          goto LABEL_32;
        }
        v18 = -2;
      }
      *(_DWORD *)(v6 + 864) = v18;
      goto LABEL_31;
    }
    v13 = 0;
    v14 = (__int64 (__fastcall *)(__int64, __int64, int, __int64, __int64))qrtr_bcast_enqueue;
    if ( *(_DWORD *)(v4 + 8) == -2 || qrtr_local_nid == -1 )
    {
LABEL_32:
      v21 = (v11 + 3) & 0x1FFFC;
      if ( (unsigned int)(qrtr_local_nid - 3) >= 0xFFFFFFFE )
      {
        v27 = v21 > 0x3E80;
        if ( v21 <= 0x3E80 )
          v28 = 0;
        else
          v28 = (unsigned int)(v21 - 16000);
        v29 = *(_DWORD *)(v10 + 68);
        v30 = ((_DWORD)v21 - 11905) & 0xFFFFF000;
        v31 = v21 - v28;
        if ( v27 )
          v32 = v30;
        else
          v32 = 0;
        v33 = sock_alloc_send_pskb(v6, v31 + 32, v32, v29 & 0x40, &v43, 3);
        if ( v33 )
        {
          v25 = v33;
          v34 = *(_DWORD *)(v33 + 208) + 32;
          *(_QWORD *)(v33 + 224) += 32LL;
          *(_DWORD *)(v33 + 208) = v34;
          skb_put();
          *(_DWORD *)(v25 + 112) = a3;
          *(_DWORD *)(v25 + 116) = v28;
LABEL_47:
          v43 = skb_copy_datagram_from_iter(v25, 0, a2 + 16, (unsigned int)a3);
          if ( v43 )
          {
LABEL_48:
            sk_skb_reason_drop(0, v25, 2);
LABEL_71:
            qrtr_node_release(v13);
            release_sock(v6);
            result = v43;
            goto LABEL_72;
          }
          if ( *(_DWORD *)(v6 + 848) == -2 || *(_DWORD *)(v4 + 8) == -2 )
          {
            if ( a3 <= 3 )
            {
              v43 = -22;
              goto LABEL_48;
            }
            skb_copy_bits(v25, 0, &v47, 4);
            v38 = v47;
            if ( *(_DWORD *)(v4 + 8) == -2 && v47 == 4 )
            {
              *(_DWORD *)(v6 + 864) = -2;
              skb_copy_bits(v25, 0, &v44, 20);
              v39 = qrtr_node_lookup(HIDWORD(v45));
              if ( v39 )
              {
                if ( !v13 || v13 == v39 || *(_DWORD *)(v13 + 60) == -1 )
                  goto LABEL_73;
                v40 = *(_DWORD *)(v13 + 64) - *(_DWORD *)(v39 + 64);
                if ( v40 < 0 )
                  v40 = *(_DWORD *)(v39 + 64) - *(_DWORD *)(v13 + 64);
                if ( v40 <= 1 )
                {
LABEL_73:
                  v42 = v39;
                  v43 = 0;
                  sk_skb_reason_drop(0, v25, 2);
                  qrtr_node_release(v42);
                  goto LABEL_71;
                }
              }
              qrtr_node_release(v39);
              v38 = 4;
            }
          }
          else
          {
            v38 = 1;
          }
          if ( *((_DWORD *)v14 - 1) != -1588936464 )
            __break(0x823Au);
          v41 = v14(v13, v25, v38, v6 + 840, v4);
          if ( v41 >= 0 )
            v37 = a3;
          else
            v37 = v41;
LABEL_70:
          v43 = v37;
          goto LABEL_71;
        }
      }
      else
      {
        v22 = ((_DWORD)v21 - 1) & 0xFFFFF000;
        if ( v21 <= 0x1000 )
        {
          v35 = sock_alloc_send_pskb(v6, v21 + 32, 0, *(_DWORD *)(v10 + 68) & 0x40, &v43, 3);
          if ( v35 )
          {
            v23 = a3;
            v25 = v35;
            v36 = *(_DWORD *)(v35 + 208) + 32;
            *(_QWORD *)(v35 + 224) += 32LL;
            *(_DWORD *)(v35 + 208) = v36;
            skb_put();
            *(_DWORD *)(v25 + 116) = 0;
            goto LABEL_46;
          }
        }
        else
        {
          v23 = v22 + 4096;
          v24 = sock_alloc_send_pskb(
                  v6,
                  32,
                  v21 - (unsigned int)(v21 - 4096) + v22,
                  *(_DWORD *)(v10 + 68) & 0x40,
                  &v43,
                  3);
          if ( v24 )
          {
            v25 = v24;
            v26 = *(_DWORD *)(v24 + 208) + 32;
            *(_QWORD *)(v24 + 224) += 32LL;
            *(_DWORD *)(v24 + 208) = v26;
            *(_DWORD *)(v24 + 116) = v23 - 32;
LABEL_46:
            *(_DWORD *)(v25 + 112) = v23;
            goto LABEL_47;
          }
        }
      }
      v37 = -12;
      goto LABEL_70;
    }
LABEL_19:
    release_sock(v6);
    result = 4294967189LL;
    goto LABEL_72;
  }
  result = 4294967274LL;
LABEL_72:
  _ReadStatusReg(SP_EL0);
  return result;
}

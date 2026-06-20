unsigned __int8 *__fastcall rmnet_frag_command(__int64 a1, __int64 a2, _QWORD *a3)
{
  unsigned __int8 *result; // x0
  int v6; // w8
  const void *v7; // x22
  int v8; // w1
  int v9; // w1
  _QWORD *v10; // x20
  void **v11; // x21
  int v12; // w9
  int v13; // w8
  __int64 v14; // x8
  unsigned __int64 v15; // x9
  __int64 v16; // x10
  _DWORD *v17; // x8
  _QWORD v18[3]; // [xsp+8h] [xbp-18h] BYREF

  v18[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18[0] = 0;
  v18[1] = 0;
  result = (unsigned __int8 *)rmnet_frag_header_ptr(a1, 4u, 0x10u, (__int64)v18);
  if ( result )
  {
    v6 = *result;
    v7 = result;
    if ( v6 == 1 )
    {
      v9 = *(unsigned __int8 *)(a2 + 1);
      if ( v9 == 255 )
        goto LABEL_21;
      result = rmnet_get_endpoint((__int64)a3, v9);
      if ( !result )
        goto LABEL_21;
      result = (unsigned __int8 *)rmnet_vnd_do_flow_control(*((_QWORD *)result + 1), 0);
      if ( (_DWORD)result )
        goto LABEL_21;
    }
    else
    {
      if ( v6 != 2 )
        goto LABEL_21;
      v8 = *(unsigned __int8 *)(a2 + 1);
      if ( v8 == 255 )
        goto LABEL_21;
      result = rmnet_get_endpoint((__int64)a3, v8);
      if ( !result )
        goto LABEL_21;
      result = (unsigned __int8 *)rmnet_vnd_do_flow_control(*((_QWORD *)result + 1), 1);
      if ( (_DWORD)result )
        goto LABEL_21;
    }
    v10 = (_QWORD *)*a3;
    result = (unsigned __int8 *)_alloc_skb(
                                  (unsigned __int16)((bswap32(*(unsigned __int16 *)(a2 + 2)) >> 16) + 64),
                                  2080,
                                  0,
                                  0xFFFFFFFFLL);
    if ( result )
    {
      v11 = (void **)result;
      v12 = *((_DWORD *)result + 52) + 32;
      *((_QWORD *)result + 28) += 32LL;
      *((_DWORD *)result + 52) = v12;
      skb_put();
      memcpy(v11[28], v7, bswap32(*(unsigned __int16 *)(a2 + 2)) >> 16);
      skb_push(v11, 4);
      *(_DWORD *)v11[28] = *(_DWORD *)a2;
      v13 = *((_DWORD *)v11 + 29);
      *((_WORD *)v11 + 90) = -1792;
      v11[2] = v10;
      if ( v13 && *((_DWORD *)v11 + 28) == v13 )
      {
        v14 = (__int64)v11[27] + *((unsigned int *)v11 + 53);
        v15 = 0;
        v16 = *(_QWORD *)(v14 + 88);
        if ( v16 && (v16 & 1) == 0 )
          v15 = (((v16 << 6) + 0xFFFFD000000000LL) & 0xFFFFFFFFFFF000LL | 0xFF00000000000000LL)
              + *(unsigned int *)(v14 + 100);
      }
      else
      {
        v15 = (unsigned __int64)v11[28];
      }
      *(_BYTE *)(v15 + 5) = *(_BYTE *)(v15 + 5) & 0xFC | 1;
      netif_tx_lock(v10);
      v17 = *(_DWORD **)(v10[1] + 32LL);
      if ( *(v17 - 1) != -998155505 )
        __break(0x8228u);
      ((void (__fastcall *)(void **, _QWORD *))v17)(v11, v10);
      result = (unsigned __int8 *)netif_tx_unlock(v10);
    }
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return result;
}

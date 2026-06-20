__int64 __fastcall dp_mon_rx_add_tlv(char a1, unsigned __int16 a2, const void *a3, __int64 a4)
{
  __int64 v4; // x8
  _BYTE *v9; // x0
  unsigned int v10; // w21
  __int64 v11; // x8
  unsigned __int16 *v12; // x0
  __int64 v13; // x8
  void *v14; // x0

  v4 = *(_QWORD *)(a4 + 40);
  if ( v4 )
    *(_QWORD *)(a4 + 40) = v4 - 1;
  v9 = (_BYTE *)skb_push(a4, 1);
  if ( v9 )
  {
    *v9 = a1;
    v10 = 1;
    v11 = *(_QWORD *)(a4 + 40);
    if ( !v11 )
      goto LABEL_6;
    goto LABEL_5;
  }
  v10 = 0;
  v11 = *(_QWORD *)(a4 + 40);
  if ( v11 )
LABEL_5:
    *(_QWORD *)(a4 + 40) = v11 - 2;
LABEL_6:
  v12 = (unsigned __int16 *)skb_push(a4, 2);
  if ( v12 )
  {
    v10 |= 2u;
    *v12 = a2;
  }
  v13 = *(_QWORD *)(a4 + 40);
  if ( v13 )
    *(_QWORD *)(a4 + 40) = v13 - a2;
  v14 = (void *)skb_push(a4, a2);
  if ( v14 )
  {
    qdf_mem_copy(v14, a3, a2);
    v10 += a2;
  }
  return v10;
}

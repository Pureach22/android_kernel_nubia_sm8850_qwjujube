__int64 __fastcall rmnet_rx_handler(__int64 *a1)
{
  __int64 v1; // x19
  __int64 result; // x0
  __int64 port; // x0
  int v4; // w8
  __int64 v5; // x20
  __int64 v6; // x8
  int v7; // w8
  int v8; // w23
  __int64 v9; // x21
  __int64 v10; // x24
  __int64 v11; // x8
  __int64 v12; // x25
  __int64 v13; // x0
  __int64 v14; // x22
  int v15; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *a1;
  if ( !*a1 )
    goto LABEL_14;
  if ( (*(_BYTE *)(v1 + 128) & 7) == 5 )
  {
    result = 3;
    goto LABEL_15;
  }
  v15 = 0;
  port = rmnet_get_port(*(_QWORD *)(v1 + 16));
  if ( !port )
  {
    netdev_core_stats_inc(*(_QWORD *)(v1 + 16), 16);
    goto LABEL_11;
  }
  v4 = *(unsigned __int8 *)(port + 13);
  v5 = port;
  if ( v4 == 2 )
  {
    v6 = *(_QWORD *)(port + 2056);
    if ( v6 )
    {
      *(_QWORD *)(v1 + 16) = v6;
      _dev_queue_xmit(v1, 0);
    }
    goto LABEL_14;
  }
  if ( v4 != 1 || (unsigned int)rmnet_module_hook_shs_switch(&v15, v1, port + 2784) && v15 )
  {
LABEL_14:
    result = 0;
    goto LABEL_15;
  }
  if ( *(_WORD *)(*(_QWORD *)(v1 + 16) + 544LL) == 1 )
  {
    if ( (unsigned int)pskb_expand_head(v1, 14, 0, 2080) )
    {
LABEL_11:
      sk_skb_reason_drop(0, v1, 2);
      goto LABEL_14;
    }
    skb_push(v1, 14);
  }
  v7 = *(_DWORD *)(v5 + 8);
  if ( (v7 & 0x30) != 0 && *(_DWORD *)(v1 + 116) )
  {
    rmnet_frag_ingress_handler(v1, v5);
    goto LABEL_14;
  }
  if ( (v7 & 1) == 0 )
  {
    _rmnet_map_ingress_handler(v1, v5);
    goto LABEL_14;
  }
  v8 = 0;
  v9 = v1;
  do
  {
    v10 = *(_QWORD *)v9;
    v11 = *(_QWORD *)(v9 + 216) + *(unsigned int *)(v9 + 212);
    v12 = *(_QWORD *)(v11 + 8);
    *(_QWORD *)(v11 + 8) = 0;
    *(_QWORD *)v9 = 0;
    do
    {
      v13 = rmnet_map_deaggregate(v9, v5);
      if ( !v13 )
      {
        consume_skb(v9);
        if ( v9 == v1 )
          goto LABEL_23;
LABEL_33:
        if ( v12 )
        {
          __break(0x800u);
          if ( v8 )
            goto LABEL_25;
        }
        else if ( v8 )
        {
          goto LABEL_25;
        }
        goto LABEL_26;
      }
      v14 = v13;
      _rmnet_map_ingress_handler(v13, v5);
    }
    while ( v14 != v9 );
    if ( v9 != v1 )
      goto LABEL_33;
LABEL_23:
    if ( v12 )
    {
      v8 = 1;
      v10 = v12;
      ++*(_QWORD *)(v5 + 2728);
LABEL_25:
      ++*(_QWORD *)(v5 + 2736);
      goto LABEL_26;
    }
    v10 = 0;
    if ( v8 )
      goto LABEL_25;
LABEL_26:
    result = 0;
    v9 = v10;
  }
  while ( v10 );
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}

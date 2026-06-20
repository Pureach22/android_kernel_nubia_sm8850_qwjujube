__int64 __fastcall rmnet_perf_ingress_handle(__int64 a1)
{
  int v1; // w8
  int v2; // w8
  int v3; // w9
  __int64 *v4; // x20
  int v5; // w8
  __int64 v6; // x19
  __int64 v7; // x19
  int v8; // w8
  int v9; // w9
  __int64 *v10; // x20
  unsigned int v11; // w20
  __int64 result; // x0
  __int64 v13; // x0
  int v14; // w8
  __int64 v15; // x19
  int v16; // w8
  __int64 v17; // x19
  int v18; // w8
  char v19; // [xsp+8h] [xbp-38h]
  __int64 v20; // [xsp+10h] [xbp-30h] BYREF
  __int64 v21; // [xsp+18h] [xbp-28h]
  __int64 v22; // [xsp+20h] [xbp-20h]
  __int64 v23; // [xsp+28h] [xbp-18h]
  __int64 v24; // [xsp+30h] [xbp-10h]
  __int64 v25; // [xsp+38h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int16 *)(a1 + 180);
  if ( v1 != 56710 )
  {
    if ( v1 == 8 )
    {
      v2 = *(_DWORD *)(a1 + 112);
      v3 = *(_DWORD *)(a1 + 116);
      LODWORD(v22) = 0;
      v20 = 0;
      v21 = 0;
      if ( v2 - v3 <= 19 )
      {
        if ( !a1 )
          goto LABEL_25;
        v15 = a1;
        v4 = &v20;
        v16 = skb_copy_bits(a1, 0, &v20, 20);
        a1 = v15;
        if ( v16 < 0 )
          goto LABEL_25;
      }
      else
      {
        v4 = *(__int64 **)(a1 + 224);
        if ( !v4 )
          goto LABEL_25;
      }
      if ( (*((_WORD *)v4 + 3) & 0xFF3F) == 0 )
      {
        v5 = *((unsigned __int8 *)v4 + 9);
        if ( v5 != 6 )
        {
          if ( v5 != 17 )
            goto LABEL_25;
          if ( enable_udp == 1 )
          {
            v6 = a1;
            rmnet_perf_ingress_handle_udp(a1);
            a1 = v6;
          }
          v7 = a1;
          if ( (rmnet_perf_is_quic_initial_packet(a1, 4 * (*(_BYTE *)v4 & 0xFu)) & 1) == 0 )
            goto LABEL_25;
          goto LABEL_20;
        }
        if ( enable_tcp == 1 )
          goto LABEL_24;
      }
    }
LABEL_25:
    result = 4294967274LL;
    goto LABEL_26;
  }
  v8 = *(_DWORD *)(a1 + 112);
  v9 = *(_DWORD *)(a1 + 116);
  v23 = 0;
  v24 = 0;
  v21 = 0;
  v22 = 0;
  v20 = 0;
  if ( v8 - v9 <= 39 )
  {
    if ( !a1 )
      goto LABEL_25;
    v17 = a1;
    v10 = &v20;
    v18 = skb_copy_bits(a1, 0, &v20, 40);
    a1 = v17;
    if ( v18 < 0 )
      goto LABEL_25;
  }
  else
  {
    v10 = *(__int64 **)(a1 + 224);
    if ( !v10 )
      goto LABEL_25;
  }
  v7 = a1;
  v19 = *((_BYTE *)v10 + 6);
  v11 = ipv6_skip_exthdr();
  result = 4294967274LL;
  if ( (v11 & 0x80000000) == 0 )
  {
    if ( v19 == 6 )
    {
      if ( enable_tcp != 1 )
        goto LABEL_26;
      a1 = v7;
LABEL_24:
      rmnet_perf_ingress_handle_tcp(a1);
      goto LABEL_25;
    }
    if ( v19 == 17 )
    {
      v13 = v7;
      if ( enable_udp == 1 )
      {
        rmnet_perf_ingress_handle_udp(v7);
        v13 = v7;
      }
      if ( (rmnet_perf_is_quic_initial_packet(v13, v11) & 1) == 0 )
        goto LABEL_25;
LABEL_20:
      v14 = *(_DWORD *)(v7 + 129);
      result = 0;
      *(_DWORD *)(v7 + 152) = 0;
      *(_DWORD *)(v7 + 129) = v14 | 0x400;
    }
  }
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall rmnet_perf_egress_handle(__int64 result)
{
  int v1; // w8
  int v2; // w8
  int v3; // w9
  __int64 *v4; // x20
  int v5; // w8
  __int64 v6; // x19
  __int64 v7; // x19
  __int64 v8; // x1
  int v9; // w8
  int v10; // w9
  __int64 *v11; // x20
  unsigned int v12; // w20
  __int64 v13; // x19
  int v14; // w8
  __int64 v15; // x19
  int v16; // w8
  char v17; // [xsp+8h] [xbp-38h]
  __int64 v18; // [xsp+10h] [xbp-30h] BYREF
  __int64 v19; // [xsp+18h] [xbp-28h]
  __int64 v20; // [xsp+20h] [xbp-20h]
  __int64 v21; // [xsp+28h] [xbp-18h]
  __int64 v22; // [xsp+30h] [xbp-10h]
  __int64 v23; // [xsp+38h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int16 *)(result + 180);
  if ( v1 != 56710 )
  {
    if ( v1 != 8 )
      goto LABEL_25;
    v2 = *(_DWORD *)(result + 112);
    v3 = *(_DWORD *)(result + 116);
    LODWORD(v20) = 0;
    v18 = 0;
    v19 = 0;
    if ( v2 - v3 <= 19 )
    {
      if ( !result )
        goto LABEL_25;
      v13 = result;
      v4 = &v18;
      v14 = skb_copy_bits(result, 0, &v18, 20);
      result = v13;
      if ( v14 < 0 )
        goto LABEL_25;
    }
    else
    {
      v4 = *(__int64 **)(result + 224);
      if ( !v4 )
        goto LABEL_25;
    }
    if ( (*((_WORD *)v4 + 3) & 0xFF3F) != 0 )
      goto LABEL_25;
    v5 = *((unsigned __int8 *)v4 + 9);
    if ( v5 != 6 )
    {
      if ( v5 != 17 )
        goto LABEL_25;
      if ( enable_udp == 1 )
      {
        v6 = result;
        rmnet_perf_egress_handle_udp(result);
        result = v6;
      }
      v7 = result;
      v8 = 4 * (*(_BYTE *)v4 & 0xFu);
      goto LABEL_19;
    }
    if ( enable_tcp != 1 )
      goto LABEL_25;
LABEL_24:
    result = rmnet_perf_egress_handle_tcp(result);
    goto LABEL_25;
  }
  v9 = *(_DWORD *)(result + 112);
  v10 = *(_DWORD *)(result + 116);
  v21 = 0;
  v22 = 0;
  v19 = 0;
  v20 = 0;
  v18 = 0;
  if ( v9 - v10 <= 39 )
  {
    if ( !result )
      goto LABEL_25;
    v15 = result;
    v11 = &v18;
    v16 = skb_copy_bits(result, 0, &v18, 40);
    result = v15;
    if ( v16 < 0 )
      goto LABEL_25;
  }
  else
  {
    v11 = *(__int64 **)(result + 224);
    if ( !v11 )
      goto LABEL_25;
  }
  v7 = result;
  v17 = *((_BYTE *)v11 + 6);
  result = ipv6_skip_exthdr();
  v12 = result;
  if ( (result & 0x80000000) != 0 )
    goto LABEL_25;
  if ( v17 == 6 )
  {
    if ( enable_tcp != 1 )
      goto LABEL_25;
    result = v7;
    goto LABEL_24;
  }
  if ( v17 != 17 )
    goto LABEL_25;
  if ( enable_udp == 1 )
    rmnet_perf_egress_handle_udp(v7);
  result = v7;
  v8 = v12;
LABEL_19:
  result = rmnet_perf_is_quic_initial_packet(result, v8);
  if ( (result & 1) != 0 )
    *(_DWORD *)(v7 + 144) = 14286874;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}

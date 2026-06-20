__int64 __fastcall rmnet_perf_ingress_ecn_handle(__int64 a1)
{
  int v1; // w8
  int v2; // w8
  int v3; // w9
  __int64 *v4; // x20
  int v5; // w8
  int v6; // w8
  int v7; // w9
  __int64 *v8; // x20
  __int64 result; // x0
  unsigned __int8 v10; // [xsp+Ch] [xbp-34h]
  __int64 v11; // [xsp+10h] [xbp-30h] BYREF
  __int64 v12; // [xsp+18h] [xbp-28h]
  __int64 v13; // [xsp+20h] [xbp-20h]
  __int64 v14; // [xsp+28h] [xbp-18h]
  __int64 v15; // [xsp+30h] [xbp-10h]
  __int64 v16; // [xsp+38h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int16 *)(a1 + 180);
  if ( v1 == 56710 )
  {
    v6 = *(_DWORD *)(a1 + 112);
    v7 = *(_DWORD *)(a1 + 116);
    v14 = 0;
    v15 = 0;
    v12 = 0;
    v13 = 0;
    v11 = 0;
    if ( v6 - v7 <= 39 )
    {
      if ( !a1 )
        goto LABEL_22;
      v8 = &v11;
      if ( (skb_copy_bits(a1, 0, &v11, 40) & 0x80000000) != 0 )
        goto LABEL_22;
    }
    else
    {
      v8 = *(__int64 **)(a1 + 224);
      if ( !v8 )
        goto LABEL_22;
    }
    v10 = *((_BYTE *)v8 + 6);
    if ( (ipv6_skip_exthdr() & 0x80000000) != 0 )
      goto LABEL_22;
    v5 = v10;
    if ( v10 != 6 )
    {
LABEL_7:
      if ( v5 != 17 )
        goto LABEL_22;
LABEL_15:
      if ( (unsigned int)rmnet_perf_ingress_udp_ecn() )
        goto LABEL_16;
LABEL_22:
      result = 0;
      goto LABEL_23;
    }
  }
  else
  {
    if ( v1 != 8 )
      goto LABEL_22;
    v2 = *(_DWORD *)(a1 + 112);
    v3 = *(_DWORD *)(a1 + 116);
    LODWORD(v13) = 0;
    v11 = 0;
    v12 = 0;
    if ( v2 - v3 <= 19 )
    {
      if ( !a1 )
        goto LABEL_22;
      v4 = &v11;
      if ( (skb_copy_bits(a1, 0, &v11, 20) & 0x80000000) != 0 )
        goto LABEL_22;
    }
    else
    {
      v4 = *(__int64 **)(a1 + 224);
      if ( !v4 )
        goto LABEL_22;
    }
    if ( (*((_WORD *)v4 + 3) & 0xFF3F) != 0 )
      goto LABEL_22;
    v10 = *((_BYTE *)v4 + 9);
    v5 = v10;
    if ( v10 != 6 )
      goto LABEL_7;
  }
  if ( !(unsigned int)rmnet_perf_ingress_tcp_ecn() )
  {
    if ( v10 != 17 )
      goto LABEL_22;
    goto LABEL_15;
  }
LABEL_16:
  result = 1;
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}

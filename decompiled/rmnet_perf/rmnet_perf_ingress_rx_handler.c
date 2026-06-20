__int64 __fastcall rmnet_perf_ingress_rx_handler(__int64 result)
{
  int v1; // w8
  int v2; // w8
  int v3; // w9
  __int64 *v4; // x19
  int v5; // w8
  int v6; // w9
  __int64 *v7; // x19
  char v8; // w8
  __int64 v9; // x19
  int v10; // w8
  int v11; // w8
  __int64 v12; // [xsp+0h] [xbp-40h]
  __int64 v13; // [xsp+0h] [xbp-40h]
  char v14; // [xsp+Ch] [xbp-34h]
  __int64 v15; // [xsp+10h] [xbp-30h] BYREF
  __int64 v16; // [xsp+18h] [xbp-28h]
  __int64 v17; // [xsp+20h] [xbp-20h]
  __int64 v18; // [xsp+28h] [xbp-18h]
  __int64 v19; // [xsp+30h] [xbp-10h]
  __int64 v20; // [xsp+38h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(unsigned __int16 *)(result + 180);
  if ( v1 == 56710 )
  {
    v5 = *(_DWORD *)(result + 112);
    v6 = *(_DWORD *)(result + 116);
    v18 = 0;
    v19 = 0;
    v16 = 0;
    v17 = 0;
    v15 = 0;
    if ( v5 - v6 <= 39 )
    {
      if ( !result )
        goto LABEL_14;
      v13 = result;
      v7 = &v15;
      v11 = skb_copy_bits(result, 0, &v15, 40);
      result = v13;
      if ( v11 < 0 )
        goto LABEL_14;
    }
    else
    {
      v7 = *(__int64 **)(result + 224);
      if ( !v7 )
        goto LABEL_14;
    }
    v8 = *((_BYTE *)v7 + 6);
    v9 = result;
    v14 = v8;
    result = ipv6_skip_exthdr();
    if ( (result & 0x80000000) != 0 )
      goto LABEL_14;
    result = v9;
    if ( v14 != 6 )
      goto LABEL_14;
  }
  else
  {
    if ( v1 != 8 )
      goto LABEL_14;
    v2 = *(_DWORD *)(result + 112);
    v3 = *(_DWORD *)(result + 116);
    LODWORD(v17) = 0;
    v15 = 0;
    v16 = 0;
    if ( v2 - v3 <= 19 )
    {
      if ( !result )
        goto LABEL_14;
      v12 = result;
      v4 = &v15;
      v10 = skb_copy_bits(result, 0, &v15, 20);
      result = v12;
      if ( v10 < 0 )
        goto LABEL_14;
    }
    else
    {
      v4 = *(__int64 **)(result + 224);
      if ( !v4 )
        goto LABEL_14;
    }
    if ( (*((_WORD *)v4 + 3) & 0xFF3F) != 0 || *((_BYTE *)v4 + 9) != 6 )
      goto LABEL_14;
  }
  if ( enable_tcp == 1 )
    result = rmnet_perf_ingress_rx_handler_tcp();
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}

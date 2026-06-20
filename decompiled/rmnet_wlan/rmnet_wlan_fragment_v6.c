__int64 __fastcall rmnet_wlan_fragment_v6(__int64 a1, __int16 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0
  unsigned int v6; // w8
  __int64 v7; // x8
  __int64 v8; // x9
  __int64 v11; // x25
  unsigned int v12; // w24
  int v13; // w19
  unsigned int v14; // w23
  bool v15; // w27
  char v16; // w0
  unsigned int v17; // w19
  unsigned __int8 *v18; // x28
  int v19; // w8
  char v20; // w8
  int v21; // w8
  int v22; // w9
  unsigned int v23; // w19
  char v24; // w0
  __int64 *v25; // x19
  __int64 v26; // x8
  __int64 v27; // x8
  int v28; // w9
  int v29; // w8
  int v30; // w9
  __int64 v31; // x1
  __int64 v33; // [xsp+8h] [xbp-48h] BYREF
  int v34; // [xsp+10h] [xbp-40h] BYREF
  _WORD v35[2]; // [xsp+14h] [xbp-3Ch] BYREF
  __int64 v36; // [xsp+18h] [xbp-38h] BYREF
  __int64 v37; // [xsp+20h] [xbp-30h]
  __int64 v38; // [xsp+28h] [xbp-28h]
  __int64 v39; // [xsp+30h] [xbp-20h]
  __int64 v40; // [xsp+38h] [xbp-18h]
  int v41; // [xsp+40h] [xbp-10h]
  __int64 v42; // [xsp+48h] [xbp-8h]

  result = 0xFFFFFFFFLL;
  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(unsigned __int8 *)(a3 + 5);
  v41 = 0;
  v39 = 0;
  v40 = 0;
  v37 = 0;
  v38 = 0;
  v36 = 0;
  if ( v6 > 0x32 || ((1LL << v6) & 0x4100000020040LL) == 0 )
    goto LABEL_40;
  v7 = *(_QWORD *)(a1 + 216);
  v8 = *(unsigned __int16 *)(a1 + 184);
  v33 = 0;
  v11 = v7 + v8;
  LODWORD(v7) = *(_DWORD *)(a1 + 224);
  v12 = *(unsigned __int8 *)(v11 + 6);
  v35[0] = 0;
  v13 = v11 - v7;
  v14 = v11 - v7 + 40;
  v15 = v12 == 44;
  v16 = ipv6_ext_hdr(v12);
  if ( v12 == 59 || (v16 & 1) == 0 )
  {
LABEL_27:
    if ( v15 )
      goto LABEL_28;
    goto LABEL_39;
  }
  v17 = -40 - v13;
  while ( 1 )
  {
    if ( (int)(*(_DWORD *)(a1 + 112) + v17 - *(_DWORD *)(a1 + 116)) <= 1 )
    {
      if ( !a1 )
        goto LABEL_39;
      v18 = (unsigned __int8 *)v35;
      if ( (skb_copy_bits(a1, v14, v35, 2) & 0x80000000) != 0 )
        goto LABEL_39;
    }
    else
    {
      v18 = (unsigned __int8 *)(*(_QWORD *)(a1 + 224) + (int)v14);
      if ( !v18 )
        goto LABEL_39;
    }
    if ( (unsigned __int8)v12 == 43 )
    {
      v21 = *(_DWORD *)(a1 + 112);
      v22 = *(_DWORD *)(a1 + 116);
      v34 = 0;
      if ( (int)(v21 + v17 - v22) <= 3 )
      {
        if ( !a1 || (skb_copy_bits(a1, v14, &v34, 4) & 0x80000000) != 0 )
          goto LABEL_39;
      }
      else if ( !(*(_QWORD *)(a1 + 224) + (int)v14) )
      {
        goto LABEL_39;
      }
      v20 = 3;
      goto LABEL_17;
    }
    if ( (unsigned __int8)v12 != 51 )
      break;
    v20 = 2;
LABEL_17:
    v19 = v18[1] << v20;
LABEL_18:
    v12 = *v18;
    v23 = v14 + v19;
    v35[0] = 0;
    v14 += v19 + 8;
    v15 = v12 == 44;
    v24 = ipv6_ext_hdr(v12);
    if ( v12 != 59 )
    {
      v17 = -8 - v23;
      if ( (v24 & 1) != 0 )
        continue;
    }
    goto LABEL_27;
  }
  if ( (unsigned __int8)v12 != 44 )
  {
    if ( v15 )
      goto LABEL_28;
    v19 = 8 * v18[1];
    goto LABEL_18;
  }
  v30 = *(_DWORD *)(a1 + 112);
  v29 = *(_DWORD *)(a1 + 116);
  v31 = v14 + 2;
  LOWORD(v34) = 0;
  if ( (int)(v30 - (v14 + v29) - 2) <= 1 )
  {
    if ( !a1 || (skb_copy_bits(a1, v31, &v34, 2) & 0x80000000) != 0 )
      goto LABEL_39;
LABEL_28:
    if ( (int)(*(_DWORD *)(a1 + 112) - (v14 + *(_DWORD *)(a1 + 116))) <= 7 )
    {
      if ( a1 )
      {
        v25 = &v33;
        if ( (skb_copy_bits(a1, v14, &v33, 8) & 0x80000000) == 0 )
          goto LABEL_30;
      }
    }
    else
    {
      v25 = (__int64 *)(*(_QWORD *)(a1 + 224) + (int)v14);
      if ( v25 )
      {
LABEL_30:
        LOBYTE(v41) = 6;
        v26 = *(_QWORD *)(v11 + 16);
        v36 = *(_QWORD *)(v11 + 8);
        v37 = v26;
        v27 = *(_QWORD *)(v11 + 32);
        v38 = *(_QWORD *)(v11 + 24);
        v39 = v27;
        v28 = *(unsigned __int8 *)(a3 + 5);
        LODWORD(v40) = *((_DWORD *)v25 + 1);
        LODWORD(v27) = *((unsigned __int16 *)v25 + 1);
        WORD2(v40) = a2;
        HIWORD(v40) = bswap32(v27 & 0xFFFFF8FF) >> 16;
        if ( v28 == 44 )
          WORD2(v40) = a2 + 8;
        result = rmnet_wlan_fragment_handle(a1, a3, &v36, a4);
        goto LABEL_40;
      }
    }
    rmnet_wlan_stats_update(20);
    goto LABEL_39;
  }
  if ( *(_QWORD *)(a1 + 224) + (int)v31 )
    goto LABEL_28;
LABEL_39:
  result = 0xFFFFFFFFLL;
LABEL_40:
  _ReadStatusReg(SP_EL0);
  return result;
}

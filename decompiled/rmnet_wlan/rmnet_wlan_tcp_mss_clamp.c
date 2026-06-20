__int64 __fastcall rmnet_wlan_tcp_mss_clamp(__int64 a1, int a2)
{
  int v2; // w23
  int v3; // w8
  int v4; // w9
  __int64 *v5; // x20
  unsigned __int16 v6; // w8
  int v7; // w8
  int v8; // w9
  __int64 *v9; // x20
  char v10; // w8
  int v11; // w19
  __int64 v12; // x20
  unsigned __int16 v13; // w0
  unsigned int v14; // w19
  _QWORD *v15; // x22
  unsigned int v16; // w8
  unsigned int v17; // w9
  unsigned int v18; // w8
  unsigned int v19; // w20
  unsigned int v20; // w22
  unsigned int v21; // w9
  __int64 v22; // x8
  __int64 v23; // x9
  __int64 v24; // x21
  int v25; // w8
  _QWORD *v26; // x21
  unsigned int v27; // w9
  unsigned int v28; // w9
  __int64 v29; // x10
  unsigned __int8 *v30; // x9
  unsigned int v31; // w11
  unsigned int v32; // w8
  unsigned int v33; // w9
  unsigned int v34; // w8
  __int64 v35; // x22
  __int64 result; // x0
  __int64 v37; // x0
  unsigned int v38; // w8
  __int64 v39; // x19
  _WORD *v40; // x0
  __int16 v41; // w8
  __int64 v42; // x2
  _WORD *v43; // x8
  __int16 v44; // w9
  unsigned int v45; // w10
  bool v46; // cf
  unsigned __int16 v47; // w9
  unsigned __int64 v48; // t2
  int v49; // w21
  __int64 v50; // x19
  int v51; // w0
  int v52; // w8
  int v53; // w21
  __int64 v54; // x19
  int v55; // w0
  int v56; // w8
  int v57; // w21
  __int64 v58; // x20
  int v59; // w8
  __int64 v60; // x21
  __int64 v61; // x8
  __int64 v62; // x22
  int v63; // w8
  char v64[4]; // [xsp+8h] [xbp-78h] BYREF
  __int16 v65; // [xsp+Ch] [xbp-74h] BYREF
  __int64 v66; // [xsp+10h] [xbp-70h] BYREF
  __int64 v67; // [xsp+18h] [xbp-68h]
  __int64 v68; // [xsp+20h] [xbp-60h]
  __int64 v69; // [xsp+28h] [xbp-58h]
  __int64 v70; // [xsp+30h] [xbp-50h]
  _QWORD v71[7]; // [xsp+38h] [xbp-48h] BYREF
  int v72; // [xsp+70h] [xbp-10h]
  __int64 v73; // [xsp+78h] [xbp-8h]

  v73 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(unsigned __int16 *)(a1 + 180);
  v72 = 0;
  memset(v71, 0, sizeof(v71));
  if ( v2 == 8 )
  {
    v3 = *(_DWORD *)(a1 + 112);
    v4 = *(_DWORD *)(a1 + 116);
    LODWORD(v68) = 0;
    v66 = 0;
    v67 = 0;
    if ( v3 - v4 <= 19 )
    {
      if ( !a1 )
        goto LABEL_39;
      v49 = a2;
      v50 = a1;
      v5 = &v66;
      v51 = skb_copy_bits(a1, 0, &v66, 20);
      a2 = v49;
      v52 = v51;
      a1 = v50;
      if ( v52 < 0 )
        goto LABEL_39;
    }
    else
    {
      v5 = *(__int64 **)(a1 + 224);
      if ( !v5 )
        goto LABEL_39;
    }
    if ( *((_BYTE *)v5 + 9) != 6 )
      goto LABEL_36;
    v6 = 4 * (*(_BYTE *)v5 & 0xF);
  }
  else
  {
    if ( v2 != 56710 )
      goto LABEL_39;
    v7 = *(_DWORD *)(a1 + 112);
    v8 = *(_DWORD *)(a1 + 116);
    v69 = 0;
    v70 = 0;
    v67 = 0;
    v68 = 0;
    v66 = 0;
    v65 = 0;
    v64[0] = 0;
    if ( v7 - v8 <= 39 )
    {
      if ( !a1 )
        goto LABEL_39;
      v53 = a2;
      v54 = a1;
      v9 = &v66;
      v55 = skb_copy_bits(a1, 0, &v66, 40);
      a2 = v53;
      v56 = v55;
      a1 = v54;
      if ( v56 < 0 )
        goto LABEL_39;
    }
    else
    {
      v9 = *(__int64 **)(a1 + 224);
      if ( !v9 )
        goto LABEL_39;
    }
    v10 = *((_BYTE *)v9 + 6);
    v11 = a2;
    v12 = a1;
    v64[0] = v10;
    v13 = ipv6_skip_exthdr(a1, 40, v64, &v65);
    if ( v64[0] != 6 )
      goto LABEL_36;
    v6 = v13;
    a1 = v12;
    a2 = v11;
  }
  v14 = v6;
  if ( *(_DWORD *)(a1 + 112) - *(_DWORD *)(a1 + 116) - v6 <= 19 )
  {
    if ( !a1 )
      goto LABEL_39;
    v57 = a2;
    v58 = a1;
    v15 = v71;
    v59 = skb_copy_bits(a1, v6, v71, 20);
    a1 = v58;
    a2 = v57;
    if ( v59 < 0 )
      goto LABEL_39;
  }
  else
  {
    v15 = (_QWORD *)(*(_QWORD *)(a1 + 224) + v6);
    if ( !v15 )
      goto LABEL_39;
  }
  v16 = *((_DWORD *)v15 + 3);
  if ( (v16 & a2) == 0 )
    goto LABEL_36;
  v17 = v16 >> 2;
  v18 = *(_DWORD *)(a1 + 112);
  v19 = v17 & 0x3C;
  v20 = v14 + v19;
  v21 = v18 - *(_DWORD *)(a1 + 116);
  if ( v14 + v19 > v21 )
  {
    if ( v18 < v20 )
      goto LABEL_39;
    v60 = a1;
    v61 = _pskb_pull_tail(a1, v20 - v21);
    a1 = v60;
    if ( !v61 )
      goto LABEL_39;
  }
  if ( (*(_BYTE *)(a1 + 126) & 1) != 0 )
  {
    v22 = *(_QWORD *)(a1 + 216);
    v23 = v22 + *(unsigned int *)(a1 + 212);
    if ( (unsigned __int16)*(_DWORD *)(v23 + 32) != 1
      && ((unsigned __int16)*(_DWORD *)(v23 + 32) - (*(int *)(v23 + 32) >> 16) != 1
       || v20 + *(_DWORD *)(a1 + 224) - (_DWORD)v22 > *(unsigned __int16 *)(a1 + 122)) )
    {
      v24 = a1;
      v25 = pskb_expand_head();
      a1 = v24;
      if ( v25 )
        goto LABEL_39;
    }
  }
  if ( (int)(*(_DWORD *)(a1 + 112) - *(_DWORD *)(a1 + 116) - v14) < (int)v19 )
  {
    if ( !a1 )
      goto LABEL_39;
    v62 = a1;
    v26 = v71;
    v63 = skb_copy_bits(a1, v14, v71, v19);
    a1 = v62;
    v20 = v14 + v19;
    if ( v63 < 0 )
      goto LABEL_39;
  }
  else
  {
    v26 = (_QWORD *)(*(_QWORD *)(a1 + 224) + v14);
    if ( !v26 )
      goto LABEL_39;
  }
  if ( v19 >= 0x15 )
  {
    v27 = 20;
    while ( 1 )
    {
      v29 = v27;
      v30 = (unsigned __int8 *)v26 + v27;
      v31 = *v30;
      if ( v31 == 2 )
        break;
      if ( v31 >= 2 )
        goto LABEL_25;
      v28 = 1;
LABEL_27:
      v27 = v28 + v29;
      if ( v27 >= v19 )
        goto LABEL_31;
    }
    if ( v30[1] == 4 )
    {
      v34 = *((unsigned __int16 *)v30 + 1);
      if ( v34 < 0x7405 )
      {
LABEL_36:
        v32 = 12;
        goto LABEL_40;
      }
      if ( (~*(unsigned __int8 *)(a1 + 128) & 0x60) != 0 )
      {
        HIDWORD(v48) = 29699 - *((unsigned __int16 *)v26 + 8) - v34;
        LODWORD(v48) = HIDWORD(v48);
        *((_WORD *)v26 + 8) = ~(((unsigned int)(v48 >> 16) + HIDWORD(v48)) >> 16);
      }
      *((_WORD *)v30 + 1) = 29700;
LABEL_56:
      v32 = 11;
      goto LABEL_40;
    }
LABEL_25:
    v28 = *((unsigned __int8 *)v26 + v29 + 1);
    if ( v28 <= 1 )
      v28 = 1;
    goto LABEL_27;
  }
LABEL_31:
  v32 = 12;
  if ( v19 != 60 )
  {
    v33 = *(_DWORD *)(a1 + 112);
    if ( v33 <= v20 )
    {
      if ( !*(_DWORD *)(a1 + 116) && *(_DWORD *)(a1 + 212) - *(_DWORD *)(a1 + 208) > 3 )
        goto LABEL_43;
      v35 = a1;
      if ( !(unsigned int)pskb_expand_head() )
      {
        v37 = skb_header_pointer_0(v35, v14, v19, (__int64)v71);
        if ( v37 )
        {
          v33 = *(_DWORD *)(v35 + 112);
          v26 = (_QWORD *)v37;
          a1 = v35;
LABEL_43:
          v38 = v33 - v14;
          v39 = a1;
          rmnet_wlan_inet_proto_csum_replace4(v26 + 2, a1, bswap32(v38) >> 16, bswap32(v38 + 4) >> 16, 1);
          v40 = (_WORD *)skb_put(v39, 4);
          if ( v2 == 8 )
            v41 = 6146;
          else
            v41 = 29700;
          *v40 = 1026;
          v40[1] = v41;
          rmnet_wlan_inet_proto_csum_replace4(v26 + 2, v39, 0, *(unsigned int *)v40, 0);
          v42 = *((unsigned int *)v26 + 3);
          *((_WORD *)v26 + 6) = ((_BYTE)v42 + 16) & 0xF0 | v42 & 0xFF0F;
          rmnet_wlan_inet_proto_csum_replace4(v26 + 2, v39, v42, *((unsigned int *)v26 + 3), 0);
          v43 = (_WORD *)(*(_QWORD *)(v39 + 216) + *(unsigned __int16 *)(v39 + 184));
          if ( v2 == 8 )
          {
            v44 = v43[1];
            v45 = bswap32(*(unsigned __int16 *)(v39 + 112)) >> 16;
            v46 = (unsigned __int16)(-2 - (v44 + v43[5])) >= (unsigned int)(unsigned __int16)~v44;
            v47 = v45 + -2 - (v44 + v43[5]);
            if ( !v46 )
              ++v47;
            if ( v45 > v47 )
              ++v47;
            v43[5] = ~v47;
            v43[1] = bswap32(*(unsigned __int16 *)(v39 + 112)) >> 16;
          }
          else
          {
            v43[2] = bswap32((bswap32((unsigned __int16)v43[2]) >> 16) + 4) >> 16;
          }
          goto LABEL_56;
        }
      }
LABEL_39:
      v32 = 13;
    }
  }
LABEL_40:
  result = rmnet_wlan_stats_update(v32);
  _ReadStatusReg(SP_EL0);
  return result;
}

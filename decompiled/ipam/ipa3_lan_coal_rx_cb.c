__int64 __fastcall ipa3_lan_coal_rx_cb(__int64 a1, __int64 a2, __int64 a3)
{
  unsigned int size; // w21
  int v5; // w23
  unsigned int v6; // w19
  __int64 v7; // x27
  __int64 v8; // x8
  __int64 v9; // x24
  unsigned __int16 *v10; // x28
  unsigned __int8 v11; // w8
  __int64 v12; // x17
  __int64 v13; // x12
  __int64 v14; // x13
  __int64 v15; // x14
  __int64 v16; // x15
  int v17; // w22
  int v18; // w8
  unsigned int v19; // w9
  __int64 v20; // x10
  __int64 v21; // x20
  __int64 v22; // x24
  unsigned int v23; // w8
  int v24; // w25
  unsigned int v25; // w10
  bool v26; // zf
  unsigned int v27; // w3
  char v28; // w26
  unsigned int v29; // w19
  unsigned int v30; // w26
  unsigned __int16 *v31; // x22
  __int64 v32; // x21
  unsigned int v33; // w23
  unsigned int v34; // w19
  unsigned int v35; // w27
  char v36; // w9
  int v37; // w9
  unsigned __int8 *v38; // x8
  int v39; // w10
  __int64 v40; // x9
  __int64 result; // x0
  __int64 v42; // x24
  unsigned int v43; // w10
  char v44; // w25
  unsigned int v45; // w20
  unsigned __int64 v46; // x26
  unsigned __int8 v47; // w8
  unsigned int v48; // w21
  unsigned int v49; // w6
  int v50; // w7
  __int64 v51; // x28
  unsigned int v52; // w23
  unsigned int v53; // w19
  char v54; // w10
  unsigned int v55; // w27
  _OWORD *v56; // x9
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x0
  __int64 v60; // x9
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x0
  __int64 v65; // x0
  __int64 v66; // x0
  unsigned int v67; // w20
  unsigned int v68; // w19
  __int64 v69; // x0
  __int64 v70; // x0
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x0
  __int64 v76; // [xsp+10h] [xbp-3D0h]
  __int64 v77; // [xsp+18h] [xbp-3C8h]
  __int64 v78; // [xsp+20h] [xbp-3C0h]
  __int64 v79; // [xsp+28h] [xbp-3B8h]
  __int64 v80; // [xsp+30h] [xbp-3B0h]
  __int64 v81; // [xsp+38h] [xbp-3A8h]
  __int64 v82; // [xsp+48h] [xbp-398h]
  __int64 v83; // [xsp+50h] [xbp-390h]
  unsigned int v84; // [xsp+50h] [xbp-390h]
  char v85; // [xsp+58h] [xbp-388h]
  unsigned int v86; // [xsp+5Ch] [xbp-384h]
  __int64 v87; // [xsp+60h] [xbp-380h]
  unsigned int v88; // [xsp+68h] [xbp-378h]
  __int64 v89; // [xsp+70h] [xbp-370h] BYREF
  __int64 v90; // [xsp+78h] [xbp-368h]
  __int64 v91; // [xsp+80h] [xbp-360h]
  __int64 v92; // [xsp+88h] [xbp-358h]
  __int64 v93; // [xsp+90h] [xbp-350h]
  __int64 v94; // [xsp+98h] [xbp-348h]
  __int64 v95; // [xsp+A0h] [xbp-340h]
  __int64 v96; // [xsp+A8h] [xbp-338h] BYREF
  _WORD v97[7]; // [xsp+B0h] [xbp-330h] BYREF
  __int64 v98; // [xsp+C0h] [xbp-320h] BYREF
  int v99; // [xsp+C8h] [xbp-318h]
  _OWORD s[48]; // [xsp+D0h] [xbp-310h] BYREF
  __int64 v101; // [xsp+3D0h] [xbp-10h]

  v101 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v99 = 0;
  v98 = 0;
  v96 = 0;
  memset(v97, 0, sizeof(v97));
  size = ipahal_pkt_status_get_size();
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v90 = 0;
  v91 = 0;
  v89 = 0;
  memset(s, 0, sizeof(s));
  v82 = a3;
  ++*(_QWORD *)(ipa3_ctx + 33848);
  ipahal_pkt_status_parse_thin(*(_QWORD *)(a3 + 224), &v98);
  v5 = (unsigned __int8)v99;
  if ( (unsigned __int8)v99 >= 0x25u )
  {
LABEL_125:
    __break(0x5512u);
LABEL_126:
    __break(1u);
  }
  if ( *(_DWORD *)(ipa3_ctx + 34308) <= (unsigned int)(unsigned __int8)v99
    || (v6 = HIDWORD(v98), v7 = ipa3_ctx + 480LL * (unsigned __int8)v99, v86 = BYTE1(v99), *(_DWORD *)(v7 + 624)) )
  {
    printk(&unk_3EEEAB, "ipa3_lan_coal_rx_cb");
    v71 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v72 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v72 )
      {
        ipc_log_string(v72, "ipa %s:%d drop pipe=%d\n", "ipa3_lan_coal_rx_cb", 4997, v5);
        v71 = ipa3_ctx;
      }
      v73 = *(_QWORD *)(v71 + 34160);
      if ( v73 )
        ipc_log_string(v73, "ipa %s:%d drop pipe=%d\n", "ipa3_lan_coal_rx_cb", 4997, v5);
    }
    goto LABEL_112;
  }
  v94 = 0;
  v95 = 0;
  v92 = 0;
  v93 = 0;
  v8 = *(_QWORD *)(v82 + 224);
  v90 = 0;
  v91 = 0;
  v89 = 0;
  v9 = v8 + size;
  v96 = 0;
  memset(v97, 0, sizeof(v97));
  if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64 *))ipahal_qmap_parse)(v9, &v96) )
  {
    printk(&unk_3A9B1C, "ipa3_lan_coal_rx_cb");
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v74 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v74 )
      {
        ipc_log_string(v74, "ipa %s:%d ipahal_qmap_parse fail\n", "ipa3_lan_coal_rx_cb", 5012);
        v57 = ipa3_ctx;
      }
      v75 = *(_QWORD *)(v57 + 34160);
      if ( v75 )
      {
        ipc_log_string(v75, "ipa %s:%d ipahal_qmap_parse fail\n", "ipa3_lan_coal_rx_cb", 5012);
        v57 = ipa3_ctx;
      }
    }
    v60 = 33880;
    goto LABEL_111;
  }
  if ( (unsigned int)HIBYTE(v97[3]) - 1 >= 6 )
  {
    printk(&unk_3EC2B2, "ipa3_lan_coal_rx_cb");
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v58 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v58 )
      {
        ipc_log_string(v58, "ipa %s:%d Bad num_nlos(%u) value\n", "ipa3_lan_coal_rx_cb", 5018, HIBYTE(v97[3]));
        v57 = ipa3_ctx;
      }
      v59 = *(_QWORD *)(v57 + 34160);
      if ( v59 )
      {
        ipc_log_string(v59, "ipa %s:%d Bad num_nlos(%u) value\n", "ipa3_lan_coal_rx_cb", 5018, HIBYTE(v97[3]));
        v57 = ipa3_ctx;
      }
    }
    v60 = 33888;
    goto LABEL_111;
  }
  v10 = (unsigned __int16 *)(v9 + 8);
  *(_WORD *)(v9 + 8) = bswap32(*(unsigned __int16 *)(v9 + 8)) >> 16;
  v11 = HIBYTE(v97[3]);
  if ( HIBYTE(v97[3]) )
    v11 = *(_BYTE *)(v9 + 11);
  v12 = *(unsigned __int8 *)(v9 + 10);
  *(_WORD *)(v9 + 12) = bswap32(*(unsigned __int16 *)(v9 + 12)) >> 16;
  if ( HIBYTE(v97[3]) >= 2u )
    v11 += *(_BYTE *)(v9 + 15);
  v13 = *(unsigned __int8 *)(v9 + 14);
  *(_WORD *)(v9 + 16) = bswap32(*(unsigned __int16 *)(v9 + 16)) >> 16;
  if ( HIBYTE(v97[3]) >= 3u )
    v11 += *(_BYTE *)(v9 + 19);
  v14 = *(unsigned __int8 *)(v9 + 18);
  *(_WORD *)(v9 + 20) = bswap32(*(unsigned __int16 *)(v9 + 20)) >> 16;
  if ( HIBYTE(v97[3]) >= 4u )
    v11 += *(_BYTE *)(v9 + 23);
  v15 = *(unsigned __int8 *)(v9 + 22);
  *(_WORD *)(v9 + 24) = bswap32(*(unsigned __int16 *)(v9 + 24)) >> 16;
  if ( HIBYTE(v97[3]) >= 5u )
    v11 += *(_BYTE *)(v9 + 27);
  v16 = *(unsigned __int8 *)(v9 + 26);
  *(_WORD *)(v9 + 28) = bswap32(*(unsigned __int16 *)(v9 + 28)) >> 16;
  if ( HIBYTE(v97[3]) >= 6u )
    v11 += *(_BYTE *)(v9 + 31);
  v17 = v11;
  if ( v11 >= 0x31u )
  {
    printk(&unk_3ACA02, "ipa3_lan_coal_rx_cb");
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v61 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v61 )
      {
        ipc_log_string(v61, "ipa %s:%d tot_pkts(%u) > MAX_COAL_PACKETS(%u)\n", "ipa3_lan_coal_rx_cb", 5052, v17, 48);
        v57 = ipa3_ctx;
      }
      v62 = *(_QWORD *)(v57 + 34160);
      if ( v62 )
      {
        ipc_log_string(v62, "ipa %s:%d tot_pkts(%u) > MAX_COAL_PACKETS(%u)\n", "ipa3_lan_coal_rx_cb", 5052, v17, 48);
        v57 = ipa3_ctx;
      }
    }
    v60 = 33896;
LABEL_111:
    ++*(_QWORD *)(v57 + v60);
LABEL_112:
    result = dev_kfree_skb_any_reason(v82, 2);
    goto LABEL_113;
  }
  v88 = v6;
  v80 = v14;
  v81 = v13;
  v78 = v16;
  v79 = v15;
  v76 = v12;
  v77 = *(unsigned __int8 *)(v9 + 30);
  *(_QWORD *)(ipa3_ctx + 33872) += v11;
  v18 = *(unsigned __int16 *)(v9 + 44);
  if ( v18 == 129 )
    v19 = 18;
  else
    v19 = 14;
  v20 = v9 + 32;
  if ( v18 == 43144 )
    v21 = 22;
  else
    v21 = v19;
  v22 = v20 + v21;
  v83 = v20;
  v23 = *(unsigned __int8 *)(v20 + v21);
  if ( v23 >> 4 == 4 )
  {
    v24 = *(unsigned __int8 *)(v22 + 9);
    v25 = size;
    v26 = (v23 & 0xF) == 5;
    v27 = 4 * (v23 & 0x3F);
    v28 = 4;
    goto LABEL_32;
  }
  if ( v23 >> 4 != 6 )
  {
    printk(&unk_3BDD44, "ipa3_lan_coal_rx_cb");
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v63 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v63 )
      {
        ipc_log_string(v63, "ipa %s:%d Not a v4 or v6 header...can't process\n", "ipa3_lan_coal_rx_cb", 5154);
        v57 = ipa3_ctx;
      }
      v64 = *(_QWORD *)(v57 + 34160);
      if ( v64 )
      {
        ipc_log_string(v64, "ipa %s:%d Not a v4 or v6 header...can't process\n", "ipa3_lan_coal_rx_cb", 5154);
        goto LABEL_109;
      }
    }
LABEL_110:
    v60 = 33912;
    goto LABEL_111;
  }
  v24 = *(unsigned __int8 *)(v22 + 6);
  v29 = 0;
  v30 = 40;
  if ( (ipv6_ext_hdr(*(unsigned __int8 *)(v22 + 6)) & 1) != 0 )
  {
    while ( 1 )
    {
      if ( (unsigned __int8)v24 == 59 )
      {
        v27 = -22;
        goto LABEL_104;
      }
      v38 = (unsigned __int8 *)(v22 + v30);
      if ( (unsigned __int8)v24 == 51 )
        break;
      if ( (unsigned __int8)v24 != 44 )
      {
        v36 = 3;
        goto LABEL_39;
      }
      v29 = *((unsigned __int16 *)v38 + 1);
      if ( __rev16(v29) >= 8 )
      {
        v24 = 44;
        v27 = v30;
        if ( (v30 & 0x80000000) == 0 )
          goto LABEL_30;
LABEL_104:
        v67 = bswap32(v29) >> 16;
        v68 = v27;
        printk(&unk_3C3C97, "ipa3_lan_coal_rx_cb");
        v57 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v69 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v69 )
          {
            ipc_log_string(
              v69,
              "ipa %s:%d _skip_ipv6_exthdr() failed. Errored with hdr_size(%d) and/or frag_off(%d)\n",
              "ipa3_lan_coal_rx_cb",
              5138,
              v68,
              v67);
            v57 = ipa3_ctx;
          }
          v70 = *(_QWORD *)(v57 + 34160);
          if ( v70 )
          {
            ipc_log_string(
              v70,
              "ipa %s:%d _skip_ipv6_exthdr() failed. Errored with hdr_size(%d) and/or frag_off(%d)\n",
              "ipa3_lan_coal_rx_cb",
              5138,
              v68,
              v67);
LABEL_109:
            v57 = ipa3_ctx;
          }
        }
        goto LABEL_110;
      }
      v37 = 8;
LABEL_40:
      v24 = *v38;
      v30 += v37;
      if ( (ipv6_ext_hdr(*v38) & 1) == 0 )
        goto LABEL_29;
    }
    v36 = 2;
LABEL_39:
    v37 = (v38[1] << v36) + 8;
    goto LABEL_40;
  }
LABEL_29:
  v27 = v30;
  if ( (v30 & 0x80000000) != 0 )
    goto LABEL_104;
LABEL_30:
  if ( (_WORD)v29 )
    goto LABEL_104;
  v26 = v27 == 40;
  v25 = size;
  v28 = 6;
LABEL_32:
  LODWORD(v31) = v26;
  v32 = v22 + v27;
  v87 = v7;
  if ( v24 != 17 )
  {
    v33 = v86;
    if ( v24 == 6 )
    {
      v34 = v27;
      LODWORD(v95) = bswap32(*(_DWORD *)(v32 + 4));
      v35 = (*(unsigned __int16 *)(v32 + 12) >> 2) & 0x3C;
      goto LABEL_48;
    }
    printk(&unk_3EEEC5, "ipa3_lan_coal_rx_cb");
    v57 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v65 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v65 )
      {
        ipc_log_string(v65, "ipa %s:%d Not a TCP or UDP heqder...can't process\n", "ipa3_lan_coal_rx_cb", 5182);
        v57 = ipa3_ctx;
      }
      v66 = *(_QWORD *)(v57 + 34160);
      if ( v66 )
      {
        ipc_log_string(v66, "ipa %s:%d Not a TCP or UDP heqder...can't process\n", "ipa3_lan_coal_rx_cb", 5182);
        v57 = ipa3_ctx;
      }
    }
    v60 = 33920;
    goto LABEL_111;
  }
  v34 = v27;
  v33 = v86;
  v35 = 8;
LABEL_48:
  skb_pull(v82, v25 + 32);
  LODWORD(v90) = v21;
  BYTE4(v90) = v28;
  v89 = v83;
  v91 = v22;
  LODWORD(v92) = v34;
  BYTE4(v92) = v24;
  v93 = v32;
  LODWORD(v94) = v35;
  HIDWORD(v94) = v34 + v21 + v35;
  if ( LOBYTE(v97[6]) <= 0x10uLL )
    ++*(_QWORD *)(ipa3_ctx + 8LL * LOBYTE(v97[6]) + 33928);
  if ( HIBYTE(v97[3]) == 1 )
    v39 = (int)v31;
  else
    v39 = 0;
  if ( v39 != 1 || !LOBYTE(v97[3]) )
  {
    if ( HIBYTE(v97[3]) )
    {
      v42 = v32 + v35;
      v43 = 0;
      v44 = 0;
      v45 = v35 + v34;
      v85 = (char)v31;
      v46 = v76 | (v81 << 8) | (v80 << 16) | (v79 << 24) | (v78 << 32) | (v77 << 40);
      do
      {
        v47 = *((_BYTE *)v10 + 3);
        if ( v47 )
        {
          v48 = 0;
          v49 = 0;
          v50 = 0;
          v84 = v43;
          do
          {
            if ( (v46 & 1) != 0 )
              v54 = 0;
            else
              v54 = (char)v31;
            v55 = *v10 - v45;
            if ( (v54 & 1) != 0 )
            {
              if ( v49 > 0x2F )
                goto LABEL_125;
              v56 = &s[v49];
              *(_QWORD *)v56 = v42;
              if ( ((16LL * v49) | 8uLL) > 0x300 )
                goto LABEL_126;
              v50 += v55;
              ++v49;
              *((_DWORD *)v56 + 2) = v55;
            }
            else
            {
              if ( (v46 & 1) != 0 )
                ++*(_QWORD *)(ipa3_ctx + 33904);
              v31 = v10;
              if ( v49 )
              {
                v51 = v87;
                v52 = v88;
                v53 = v86;
                prep_and_send_skb(0, v87 + 168, v88, v86, &v89, s);
              }
              else
              {
                v52 = v88;
                v53 = v86;
                v51 = v87;
              }
              *(_QWORD *)&s[0] = v42;
              DWORD2(s[0]) = v55;
              prep_and_send_skb(0, v51 + 168, v52, v53, &v89, s);
              v10 = v31;
              v47 = *((_BYTE *)v31 + 3);
              LOBYTE(v31) = v85;
              v50 = 0;
              v49 = 0;
              v33 = v53;
            }
            ++v48;
            v42 += v55;
            v46 >>= 1;
            ++v44;
          }
          while ( v48 < v47 );
          if ( v49 )
            prep_and_send_skb(0, v87 + 168, v88, v33, &v89, s);
          v43 = v84;
        }
        ++v43;
        v10 += 2;
      }
      while ( v43 < HIBYTE(v97[3]) );
    }
    goto LABEL_112;
  }
  v40 = *(_QWORD *)(v82 + 224);
  DWORD2(s[0]) = *v10 - (v35 + v34);
  *(_QWORD *)&s[0] = v40 + v34 + (_DWORD)v21 + v35;
  result = prep_and_send_skb(v82, v87 + 168, v88, v33, &v89, s);
LABEL_113:
  _ReadStatusReg(SP_EL0);
  return result;
}

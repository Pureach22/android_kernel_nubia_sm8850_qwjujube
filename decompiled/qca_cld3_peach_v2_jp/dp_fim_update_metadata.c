__int64 __fastcall dp_fim_update_metadata(__int64 a1, __int64 a2)
{
  __int64 v3; // x19
  __int64 result; // x0
  __int64 v6; // x23
  unsigned int *v7; // x21
  char v8; // w24
  unsigned int v9; // w21
  unsigned __int64 StatusReg; // x9
  __int64 *i; // x8
  int v12; // w10
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  __int64 v21; // x0
  __int64 v22; // x22
  int v23; // w8
  __int64 v24; // x10
  __int64 v25; // x4
  __int64 v26; // x11
  __int64 v27; // x6
  __int64 v28; // x7
  int v29; // w9
  int v30; // w8
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  const char *v47; // x2
  __int64 v48; // [xsp+20h] [xbp-40h] BYREF
  _QWORD v49[2]; // [xsp+28h] [xbp-38h] BYREF
  __int64 v50; // [xsp+38h] [xbp-28h]
  __int64 v51; // [xsp+40h] [xbp-20h]
  __int64 v52; // [xsp+48h] [xbp-18h]
  __int64 v53; // [xsp+50h] [xbp-10h]
  __int64 v54; // [xsp+58h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 3720);
  result = 4;
  v48 = 0;
  v49[0] = 0;
  v52 = 0;
  v53 = 0;
  v50 = 0;
  v51 = 0;
  v49[1] = 0;
  if ( !a2 || !v3 )
    goto LABEL_46;
  if ( (*(_BYTE *)v3 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 168) = 251658240;
    goto LABEL_46;
  }
  v6 = *(_QWORD *)(a2 + 24);
  if ( !v6 || !*(_DWORD *)(v6 + 556) )
  {
    ++*(_DWORD *)(v3 + 2128);
    dp_fim_parse_skb_flow_info_0(a2, (int)v49);
    if ( (_DWORD)v53 && (v53 & 0x80) == 0 )
    {
      if ( (*(_BYTE *)(a2 + 130) & 6) == 0 )
        _skb_get_hash_net(0, a2);
      v7 = (unsigned int *)(a2 + 152);
      v8 = 1;
      goto LABEL_12;
    }
LABEL_45:
    result = 4;
    ++*(_DWORD *)(v3 + 2120);
    *(_DWORD *)(a2 + 168) = 251658240;
    goto LABEL_46;
  }
  ++*(_DWORD *)(v3 + 2124);
  if ( !*(_QWORD *)(a2 + 24) || !_qdf_nbuf_sock_is_ipv4_pkt(a2) && !_qdf_nbuf_sock_is_ipv6_pkt(a2) )
    goto LABEL_45;
  v7 = (unsigned int *)(v6 + 556);
  if ( !_qdf_nbuf_sock_is_udp_pkt(a2) && !_qdf_nbuf_sock_is_tcp_pkt(a2) )
    goto LABEL_45;
  v8 = 0;
LABEL_12:
  v9 = *v7;
  StatusReg = _ReadStatusReg(SP_EL0);
  *(_DWORD *)(StatusReg + 16) += 512;
  for ( i = *(__int64 **)(v3 + 8LL * (unsigned __int8)(BYTE2(v9) ^ HIBYTE(v9) ^ BYTE1(v9) ^ v9) + 24); i; i = (__int64 *)*i )
  {
    if ( (v8 & 1) != 0 )
    {
      if ( BYTE4(v52) == 8
        && *((_DWORD *)i + 8) == LODWORD(v49[0])
        && *((_DWORD *)i + 12) == (_DWORD)v50
        && __PAIR64__(*((unsigned __int16 *)i + 33), *((unsigned __int16 *)i + 32)) == __PAIR64__(
                                                                                         WORD1(v52),
                                                                                         (unsigned __int16)v52)
        && *((_BYTE *)i + 68) == 8 )
      {
        goto LABEL_24;
      }
    }
    else if ( i[10] == *(_QWORD *)(a2 + 24) && *((_DWORD *)i + 23) == v9 )
    {
LABEL_24:
      v12 = *((_DWORD *)i + 22);
      i[12] = jiffies;
      *(_DWORD *)(a2 + 168) = v12;
      ++*((_DWORD *)i + 29);
      local_bh_enable_4();
      goto LABEL_37;
    }
  }
  local_bh_enable_4();
  if ( (v8 & 1) == 0 )
    dp_fim_parse_skb_flow_info_0(a2, (int)v49);
  if ( !(_DWORD)v53 || (v53 & 0x80) != 0 )
  {
    result = 4;
    ++*(_DWORD *)(v3 + 2120);
  }
  else
  {
    if ( (unsigned int)fpm_policy_flow_match(a1, a2, (int *)&v48 + 1, v49, &v48, v13, v14, v15, v16, v17, v18, v19, v20) == 1 )
      v48 = 0xF000000DEADBEEFLL;
    v21 = _qdf_mem_malloc(0x78u, "dp_fim_update_metadata", 329);
    if ( v21 )
    {
      v22 = v21;
      qdf_mem_copy((void *)(v21 + 32), v49, 0x30u);
      v24 = (unsigned int)v48;
      v23 = HIDWORD(v48);
      *(_QWORD *)(v22 + 80) = v6;
      *(_DWORD *)(v22 + 88) = v23;
      *(_DWORD *)(v22 + 92) = v9;
      *(_QWORD *)(v22 + 96) = jiffies;
      *(_QWORD *)(v22 + 104) = v24;
      *(_DWORD *)(a2 + 168) = v23;
      v26 = *(_QWORD *)(v22 + 96);
      v25 = *(_QWORD *)(v22 + 104);
      v27 = *(unsigned __int16 *)(v22 + 64);
      v28 = *(unsigned __int16 *)(v22 + 66);
      v29 = *(unsigned __int8 *)(v22 + 68);
      v30 = *(_DWORD *)(v22 + 116) + 1;
      LODWORD(v24) = *(_DWORD *)(v22 + 72);
      *(_DWORD *)(v22 + 116) = v30;
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: New FIM node policy_id:0x%llx metadata:%x srcport:%d dstport:%d proto:%d flags:0x%x timestamp:%lu num_pkt:%d",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "dp_fim_update_metadata",
        v25,
        *(unsigned int *)(a2 + 168),
        v27,
        v28,
        v29,
        v24,
        v26,
        v30);
      if ( *(unsigned __int16 *)(a2 + 180) == 56710 )
        v47 = "%s: src_ip:%pI6 dst_ip:%pI6";
      else
        v47 = "%s: src_ip:%pI4 dst_ip:%pI4";
      qdf_trace_msg(
        0x45u,
        5u,
        v47,
        v39,
        v40,
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        "dp_fim_update_metadata",
        v22 + 32,
        v22 + 48);
      dp_fim_hash_table_insert_node(v3, v9, v22);
LABEL_37:
      result = 0;
    }
    else
    {
      result = 2;
    }
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}

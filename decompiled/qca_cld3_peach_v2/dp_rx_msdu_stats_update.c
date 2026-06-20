__int64 __fastcall dp_rx_msdu_stats_update(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        unsigned __int8 a5,
        _QWORD *a6,
        unsigned __int8 a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15)
{
  __int64 v20; // x26
  __int64 v21; // x24
  __int64 v22; // x10
  __int64 v23; // x11
  __int64 v24; // x10
  __int64 v25; // x8
  __int64 v26; // x10
  __int64 *v27; // x8
  _QWORD *v28; // x8
  __int64 *v29; // x26
  __int64 (__fastcall *v30)(_QWORD); // x8
  char v31; // w0
  __int64 (__fastcall *v32)(_QWORD); // x8
  __int64 (__fastcall *v33)(_QWORD); // x8
  unsigned int v34; // w0
  char v35; // w24
  unsigned int v36; // w27
  __int64 (__fastcall *v37)(_QWORD); // x8
  __int64 (__fastcall *v38)(_QWORD); // x8
  unsigned int v39; // w28
  __int64 (__fastcall *v40)(_QWORD); // x8
  __int64 (__fastcall *v41)(_QWORD); // x8
  unsigned int v42; // w0
  int v43; // w25
  bool v44; // zf
  bool v46; // w8
  __int64 v47; // x8
  __int64 v48; // x8
  __int64 v49; // x8
  __int64 v50; // x8
  __int64 (__fastcall *v51)(_QWORD); // x8
  int v52; // w0
  __int64 (__fastcall *v53)(_QWORD); // x8
  __int64 result; // x0
  int v55; // w9
  __int64 v56; // x8
  __int64 v57; // x8
  __int64 v58; // x8
  bool v59; // cc
  unsigned __int8 v60; // w8
  __int64 v61; // x8
  __int64 v62; // x24
  __int64 v63; // x8
  __int64 (__fastcall *v64)(_QWORD); // x8
  __int64 (__fastcall *v65)(_QWORD); // x8
  __int64 (__fastcall *v66)(_QWORD); // x8
  __int64 *v67; // x8
  __int64 v68; // x9
  int v69; // w14
  unsigned __int64 v70; // x10
  __int64 v71; // x28
  _QWORD *v72; // x27
  __int64 v73; // x28
  _QWORD *v74; // x27
  unsigned __int8 *v75; // x8
  __int64 *v76; // x9
  __int64 v77; // x11
  __int64 *v78; // x8
  __int64 v79; // x10
  __int64 (__fastcall *v80)(_QWORD); // x8
  unsigned int v81; // [xsp+4h] [xbp-1Ch]
  unsigned int v82; // [xsp+8h] [xbp-18h]
  unsigned int v83; // [xsp+Ch] [xbp-14h]
  __int16 v84[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v85; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v86; // [xsp+18h] [xbp-8h]

  v86 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v20 = *a4;
  v21 = *(unsigned __int16 *)(a2 + 60);
  if ( a4 )
  {
    if ( a5 >= 8u )
      goto LABEL_147;
    v44 = (*(_BYTE *)(a2 + 84) & 5) == 5;
    v22 = (__int64)&a4[509 * a7 + 286 + 2 * a5];
    v23 = *(_QWORD *)(v22 + 616) + v21;
    ++*(_QWORD *)(v22 + 608);
    *(_QWORD *)(v22 + 616) = v23;
    v24 = (__int64)&a4[509 * a7 + 286];
    if ( !v44 )
    {
      ++*(_DWORD *)(v24 + 952);
      if ( (*(_BYTE *)(a2 + 84) & 8) == 0 )
        goto LABEL_9;
      goto LABEL_8;
    }
    ++*(_DWORD *)(v24 + 948);
    if ( (*(_BYTE *)(a2 + 84) & 8) != 0 )
LABEL_8:
      ++HIDWORD(a4[509 * a7 + 405]);
  }
LABEL_9:
  if ( (unsigned __int16)((unsigned __int16)*(_DWORD *)(a2 + 48) >> 14) >= 2u )
  {
    v71 = jiffies;
    if ( dp_peer_update_rx_pkt_per_lmac___last_ticks - jiffies + 125 < 0 )
    {
      v72 = a6;
      qdf_trace_msg(
        0x45u,
        2u,
        "%s: Invalid lmac_id: %u vdev_id: %u",
        a8,
        a9,
        a10,
        a11,
        a12,
        a13,
        a14,
        a15,
        "dp_peer_update_rx_pkt_per_lmac");
      a6 = v72;
      dp_peer_update_rx_pkt_per_lmac___last_ticks = v71;
    }
    if ( a4 )
    {
      v73 = jiffies;
      if ( dp_peer_update_rx_pkt_per_lmac___last_ticks_72 - jiffies + 125 < 0 )
      {
        v74 = a6;
        qdf_trace_msg(
          0x45u,
          2u,
          "%s: peer_id: %u",
          a8,
          a9,
          a10,
          a11,
          a12,
          a13,
          a14,
          a15,
          "dp_peer_update_rx_pkt_per_lmac",
          *((unsigned __int16 *)a4 + 4));
        a6 = v74;
        dp_peer_update_rx_pkt_per_lmac___last_ticks_72 = v73;
      }
    }
  }
  else if ( a4 && (*((_BYTE *)a4 + 10) & 8) != 0 )
  {
    v25 = (__int64)&a4[509 * a7 + 2 * ((unsigned __int16)*(_DWORD *)(a2 + 48) >> 14)];
    v26 = *(_QWORD *)(v25 + 3032);
    ++*(_QWORD *)(v25 + 3024);
    *(_QWORD *)(v25 + 3032) = v26 + *(unsigned __int16 *)(a2 + 60);
  }
  ++a6[34];
  if ( (*(_BYTE *)(a2 + 84) & 0x10) == 0 || *(_DWORD *)(v20 + 44) != 2 )
  {
    if ( !a4 )
      goto LABEL_18;
    v27 = &a4[509 * a7];
    ++v27[382];
    v28 = v27 + 383;
    goto LABEL_17;
  }
  v75 = *(unsigned __int8 **)(a2 + 224);
  if ( a4 )
  {
    v76 = &a4[509 * a7];
    v77 = v76[385] + v21;
    ++v76[384];
    v76[385] = v77;
  }
  ++a6[35];
  if ( *v75 == 255 && v75[1] == 255 && v75[2] == 255 && v75[3] == 255 && v75[4] == 255 && v75[5] == 255 )
  {
    if ( a4 )
    {
      v78 = &a4[509 * a7];
      v79 = v78[387] + v21;
      ++v78[386];
      v78[387] = v79;
    }
    v28 = a6 + 36;
    v21 = 1;
LABEL_17:
    *v28 += v21;
  }
LABEL_18:
  v29 = a4 + 286;
  a4[509 * a7 + 395] = jiffies;
  v30 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1528LL);
  if ( *((_DWORD *)v30 - 1) != -1147376687 )
    __break(0x8228u);
  v31 = v30(a3);
  if ( a4 && (v31 & 1) != 0 )
    ++HIDWORD(v29[509 * a7 + 376]);
  if ( !((a4 == nullptr) | v31 & 1) )
    ++LODWORD(v29[509 * a7 + 376]);
  v32 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1368LL);
  if ( *((_DWORD *)v32 - 1) != 855462014 )
    __break(0x8228u);
  v81 = v32(a3);
  v33 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1392LL);
  if ( *((_DWORD *)v33 - 1) != 855462014 )
    __break(0x8228u);
  v34 = v33(a3);
  v35 = *(_BYTE *)(a2 + 87);
  v36 = v34;
  v37 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1416LL);
  if ( *((_DWORD *)v37 - 1) != 855462014 )
    __break(0x8228u);
  v82 = v37(a3);
  v38 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 400LL);
  if ( *((_DWORD *)v38 - 1) != 855462014 )
    __break(0x8228u);
  v39 = v38(a3);
  v40 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 280LL);
  if ( *((_DWORD *)v40 - 1) != 855462014 )
    __break(0x8228u);
  v83 = v40(a3);
  v41 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1312LL);
  if ( *((_DWORD *)v41 - 1) != 855462014 )
    __break(0x8228u);
  v42 = v41(a3);
  if ( v42 <= 8 )
    v43 = hal_2_dp_pkt_type_map[v42];
  else
    v43 = 6;
  v44 = v83 == 2 && v43 == 2;
  if ( v44 )
    v36 += 8;
  v46 = (*(_BYTE *)(a2 + 84) & 1) == 0 || a4 == nullptr;
  if ( v36 > 0x10 )
  {
    if ( !v46 )
    {
      ++LODWORD(v29[509 * a7 + 440]);
      goto LABEL_58;
    }
LABEL_55:
    if ( !a4 )
      goto LABEL_65;
    goto LABEL_58;
  }
  if ( v46 )
    goto LABEL_55;
  v47 = (__int64)&v29[509 * a7] + 4 * v36;
  ++*(_DWORD *)(v47 + 3456);
LABEL_58:
  if ( v82 > 7 )
    goto LABEL_147;
  v48 = (__int64)&v29[509 * a7] + 4 * v82;
  ++*(_DWORD *)(v48 + 3424);
  if ( v83 && (unsigned int)(v43 - 2) <= 3 )
  {
    if ( v83 > 8 )
      goto LABEL_147;
    v49 = (__int64)&v29[509 * a7 - 1] + 4 * v83 + 4;
    ++*(_DWORD *)(v49 + 3360);
  }
  if ( v81 > 4 )
LABEL_147:
    __break(0x5512u);
  v50 = (__int64)&v29[509 * a7] + 4 * v81;
  ++*(_DWORD *)(v50 + 3340);
LABEL_65:
  v51 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1304LL);
  if ( *((_DWORD *)v51 - 1) != 855462014 )
    __break(0x8228u);
  v52 = v51(a3);
  if ( a4 && v52 )
    ++LODWORD(v29[509 * a7 + 115]);
  v53 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1400LL);
  if ( *((_DWORD *)v53 - 1) != 855462014 )
    __break(0x8228u);
  result = v53(a3);
  if ( a4 && (_DWORD)result )
  {
    ++HIDWORD(v29[509 * a7 + 115]);
  }
  else if ( !a4 )
  {
    goto LABEL_84;
  }
  v55 = v35 & 0xF;
  v56 = 0;
  if ( (v35 & 0xF) != 0 && v55 != 3 )
  {
    if ( (unsigned int)(v55 - 1) >= 2 )
    {
      v56 = 2;
      if ( (v35 & 0xE) != 4 )
        v56 = 3;
    }
    else
    {
      v56 = 1;
    }
  }
  v57 = (__int64)&v29[509 * a7] + 4 * v56;
  ++*(_DWORD *)(v57 + 2984);
  if ( v39 > 3 )
    goto LABEL_147;
  v58 = (__int64)&v29[509 * a7] + 4 * v39;
  ++*(_DWORD *)(v58 + 3308);
LABEL_84:
  if ( v43 > 2 )
  {
    switch ( v43 )
    {
      case 3:
        v59 = v36 > 0xB;
        break;
      case 4:
        v59 = v36 > 0xD;
        break;
      case 5:
        v60 = v36 >= 0x10 ? 16 : v36;
        if ( !a4 )
          goto LABEL_107;
        goto LABEL_104;
      default:
        goto LABEL_107;
    }
  }
  else
  {
    if ( !v43 )
    {
LABEL_88:
      v59 = v36 > 7;
      goto LABEL_100;
    }
    if ( v43 != 1 )
    {
      if ( v43 != 2 )
        goto LABEL_107;
      goto LABEL_88;
    }
    v59 = v36 > 6;
  }
LABEL_100:
  if ( v59 )
    v60 = 16;
  else
    v60 = v36;
  if ( !a4 )
    goto LABEL_107;
LABEL_104:
  if ( v60 != 17 )
  {
    if ( v60 <= 0x10u )
    {
      v61 = (__int64)&v29[509 * a7] + 68 * (unsigned int)v43 + 4 * v60;
      ++*(_DWORD *)(v61 + 2576);
      goto LABEL_107;
    }
    goto LABEL_147;
  }
LABEL_107:
  if ( (*(_BYTE *)(a2 + 84) & 0x10) == 0 )
  {
    v62 = *(_QWORD *)(a1 + 1128);
    v85 = 0;
    v63 = *(_QWORD *)(v62 + 74392);
    v84[0] = 0;
    v64 = *(__int64 (__fastcall **)(_QWORD))(v63 + 1408);
    if ( *((_DWORD *)v64 - 1) != 855462014 )
      __break(0x8228u);
    result = v64(a3);
    if ( (_DWORD)result )
    {
      v65 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v62 + 74392) + 560LL);
      if ( *((_DWORD *)v65 - 1) != -1147376687 )
        __break(0x8228u);
      result = v65(a3);
      if ( (_BYTE)result )
      {
        v66 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v62 + 74392) + 1776LL);
        if ( v66 )
        {
          if ( *((_DWORD *)v66 - 1) != 855462014 )
            __break(0x8228u);
          result = v66(a3);
          if ( (_DWORD)result == 2048 )
          {
            result = _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224));
            if ( (result & 1) != 0 )
              goto LABEL_128;
          }
          else
          {
            v80 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v62 + 74392) + 1776LL);
            if ( !v80 )
              goto LABEL_128;
            if ( *((_DWORD *)v80 - 1) != 855462014 )
              __break(0x8228u);
            result = v80(a3);
            if ( (_DWORD)result != 34525 )
              goto LABEL_128;
            result = _qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a2 + 224));
            if ( (result & 1) != 0 )
              goto LABEL_128;
          }
          if ( a4 )
          {
            *(_DWORD *)((char *)&v29[509 * a7 + 445] + 2) = ((v82 & 0xF) << 8)
                                                          | (16 * (v36 & 0xF))
                                                          | *(_DWORD *)((_BYTE *)&v29[509 * a7 + 445] + 2) & 0xFFFFF00F;
            if ( (*(_BYTE *)(a1 + 20147) & 1) != 0 )
              goto LABEL_128;
            HIDWORD(v29[509 * a7 + 440]) = v36;
          }
          else if ( (*(_BYTE *)(a1 + 20147) & 1) != 0 )
          {
            goto LABEL_128;
          }
          if ( v43 == 1 )
            LOBYTE(v83) = 1;
          result = dp_getrateindex(v81, v36, (unsigned __int8)v83 - 1, v43, v82, 0, &v85, v84);
          if ( a4 )
          {
            v67 = &v29[509 * a7];
            v68 = *((unsigned int *)v67 + 884);
            v69 = *(_DWORD *)((char *)v67 + 3562);
            *((_DWORD *)v67 + 882) = result;
            v70 = (unsigned __int64)(7 * v68 + (int)((_DWORD)result << 7)) >> 3;
            *(_DWORD *)((char *)v67 + 3562) = ((v81 & 0xF) << 12) | ((v43 & 0xF) << 16) | v83 & 0xF | v69 & 0xFFF00FF0;
            if ( !(_DWORD)v68 )
              LODWORD(v70) = (_DWORD)result << 7;
            *((_DWORD *)v67 + 884) = v70;
          }
        }
      }
    }
  }
LABEL_128:
  _ReadStatusReg(SP_EL0);
  return result;
}

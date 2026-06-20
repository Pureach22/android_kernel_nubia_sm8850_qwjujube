__int64 __fastcall dp_rx_msdu_stats_update(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 *a4,
        unsigned __int8 a5,
        _QWORD *a6,
        unsigned __int8 a7)
{
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x12
  __int64 v14; // x13
  __int64 v15; // x12
  __int64 *v16; // x9
  _QWORD *v17; // x9
  unsigned int v18; // w23
  _QWORD *v19; // x26
  __int64 (__fastcall *v20)(_QWORD); // x8
  char v21; // w0
  __int64 (__fastcall *v22)(_QWORD); // x8
  __int64 (__fastcall *v23)(_QWORD); // x8
  unsigned int v24; // w0
  char v25; // w24
  unsigned int v26; // w27
  __int64 (__fastcall *v27)(_QWORD); // x8
  __int64 (__fastcall *v28)(_QWORD); // x8
  unsigned int v29; // w28
  __int64 (__fastcall *v30)(_QWORD); // x8
  __int64 (__fastcall *v31)(_QWORD); // x8
  unsigned int v32; // w0
  int v33; // w25
  bool v34; // zf
  bool v36; // w8
  _DWORD *v37; // x8
  __int64 v38; // x8
  __int64 v39; // x8
  __int64 v40; // x8
  __int64 (__fastcall *v41)(_QWORD); // x8
  int v42; // w0
  __int64 (__fastcall *v43)(_QWORD); // x8
  __int64 result; // x0
  int v45; // w9
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x8
  unsigned __int8 v49; // w8
  bool v50; // cc
  __int64 v51; // x8
  __int64 v52; // x24
  __int64 v53; // x8
  __int64 (__fastcall *v54)(_QWORD); // x8
  __int64 (__fastcall *v55)(_QWORD); // x8
  __int64 (__fastcall *v56)(_QWORD); // x8
  _DWORD *v57; // x8
  __int64 v58; // x9
  int v59; // w14
  unsigned __int64 v60; // x10
  unsigned __int8 *v61; // x9
  __int64 *v62; // x10
  __int64 v63; // x12
  __int64 *v64; // x9
  __int64 v65; // x8
  __int64 (__fastcall *v66)(_QWORD); // x8
  unsigned int v67; // [xsp+4h] [xbp-1Ch]
  unsigned int v68; // [xsp+8h] [xbp-18h]
  unsigned int v69; // [xsp+Ch] [xbp-14h]
  _WORD v70[2]; // [xsp+10h] [xbp-10h] BYREF
  unsigned int v71; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v72; // [xsp+18h] [xbp-8h]

  v72 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *a4;
  v12 = *(unsigned __int16 *)(a2 + 60);
  if ( a4 )
  {
    if ( a5 >= 8u )
      goto LABEL_137;
    v34 = (*(_BYTE *)(a2 + 84) & 5) == 5;
    v13 = (__int64)&a4[407 * a7 + 278 + 2 * a5];
    v14 = *(_QWORD *)(v13 + 616) + v12;
    ++*(_QWORD *)(v13 + 608);
    *(_QWORD *)(v13 + 616) = v14;
    v15 = (__int64)&a4[407 * a7 + 278];
    if ( v34 )
    {
      ++*(_DWORD *)(v15 + 948);
      if ( (*(_BYTE *)(a2 + 84) & 8) == 0 )
        goto LABEL_9;
      goto LABEL_8;
    }
    ++*(_DWORD *)(v15 + 952);
    if ( (*(_BYTE *)(a2 + 84) & 8) != 0 )
LABEL_8:
      ++HIDWORD(a4[407 * a7 + 397]);
  }
LABEL_9:
  ++a6[34];
  if ( (*(_BYTE *)(a2 + 84) & 0x10) == 0 || *(_DWORD *)(v11 + 44) != 2 )
  {
    if ( !a4 )
      goto LABEL_14;
    v16 = &a4[407 * a7];
    ++v16[374];
    v17 = v16 + 375;
    goto LABEL_13;
  }
  v61 = *(unsigned __int8 **)(a2 + 224);
  if ( a4 )
  {
    v62 = &a4[407 * a7];
    v63 = v62[377] + v12;
    ++v62[376];
    v62[377] = v63;
  }
  ++a6[35];
  if ( *v61 == 255 && v61[1] == 255 && v61[2] == 255 && v61[3] == 255 && v61[4] == 255 && v61[5] == 255 )
  {
    if ( a4 )
    {
      v64 = &a4[407 * a7];
      v65 = v64[379] + v12;
      ++v64[378];
      v64[379] = v65;
    }
    v17 = a6 + 36;
    v12 = 1;
LABEL_13:
    *v17 += v12;
  }
LABEL_14:
  v18 = a7;
  v19 = a4 + 278;
  a4[407 * a7 + 387] = jiffies;
  v20 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1528LL);
  if ( *((_DWORD *)v20 - 1) != -1147376687 )
    __break(0x8228u);
  v21 = v20(a3);
  if ( a4 && (v21 & 1) != 0 )
    ++LODWORD(v19[407 * v18 + 307]);
  if ( !((a4 == nullptr) | v21 & 1) )
    ++HIDWORD(v19[407 * v18 + 306]);
  v22 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1368LL);
  if ( *((_DWORD *)v22 - 1) != 855462014 )
    __break(0x8228u);
  v67 = v22(a3);
  v23 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1392LL);
  if ( *((_DWORD *)v23 - 1) != 855462014 )
    __break(0x8228u);
  v24 = v23(a3);
  v25 = *(_BYTE *)(a2 + 87);
  v26 = v24;
  v27 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1416LL);
  if ( *((_DWORD *)v27 - 1) != 855462014 )
    __break(0x8228u);
  v68 = v27(a3);
  v28 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 400LL);
  if ( *((_DWORD *)v28 - 1) != 855462014 )
    __break(0x8228u);
  v29 = v28(a3);
  v30 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 280LL);
  if ( *((_DWORD *)v30 - 1) != 855462014 )
    __break(0x8228u);
  v69 = v30(a3);
  v31 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1312LL);
  if ( *((_DWORD *)v31 - 1) != 855462014 )
    __break(0x8228u);
  v32 = v31(a3);
  if ( v32 <= 8 )
    v33 = hal_2_dp_pkt_type_map[v32];
  else
    v33 = 5;
  v34 = v69 == 2 && v33 == 2;
  if ( v34 )
    v26 += 8;
  v36 = (*(_BYTE *)(a2 + 84) & 1) == 0 || a4 == nullptr;
  if ( v26 > 0xE )
  {
    if ( !v36 )
    {
      v37 = (_DWORD *)&v19[407 * v18 + 366] + 1;
      goto LABEL_54;
    }
LABEL_51:
    if ( !a4 )
      goto LABEL_62;
    goto LABEL_55;
  }
  if ( v36 )
    goto LABEL_51;
  v37 = (_DWORD *)&v19[407 * v18 + 359] + v26 + 1;
LABEL_54:
  ++*v37;
LABEL_55:
  if ( v68 > 7 )
    goto LABEL_137;
  v38 = (__int64)&v19[407 * v18] + 4 * v68;
  ++*(_DWORD *)(v38 + 2844);
  if ( v69 && (unsigned int)(v33 - 2) <= 2 )
  {
    if ( v69 > 8 )
      goto LABEL_137;
    v39 = (__int64)&v19[407 * v18 - 1] + 4 * v69 + 4;
    ++*(_DWORD *)(v39 + 2780);
  }
  if ( v67 > 4 )
LABEL_137:
    __break(0x5512u);
  v40 = (__int64)&v19[407 * v18] + 4 * v67;
  ++*(_DWORD *)(v40 + 2760);
LABEL_62:
  v41 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1304LL);
  if ( *((_DWORD *)v41 - 1) != 855462014 )
    __break(0x8228u);
  v42 = v41(a3);
  if ( a4 && v42 )
    ++LODWORD(v19[407 * v18 + 115]);
  v43 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1400LL);
  if ( *((_DWORD *)v43 - 1) != 855462014 )
    __break(0x8228u);
  result = v43(a3);
  if ( a4 && (_DWORD)result )
  {
    ++HIDWORD(v19[407 * v18 + 115]);
  }
  else if ( !a4 )
  {
    goto LABEL_81;
  }
  v45 = v25 & 0xF;
  v46 = 0;
  if ( (v25 & 0xF) != 0 && v45 != 3 )
  {
    if ( (unsigned int)(v45 - 1) >= 2 )
    {
      v46 = 2;
      if ( (v25 & 0xE) != 4 )
        v46 = 3;
    }
    else
    {
      v46 = 1;
    }
  }
  v47 = (__int64)&v19[407 * v18] + 4 * v46;
  ++*(_DWORD *)(v47 + 2428);
  if ( v29 > 3 )
    goto LABEL_137;
  v48 = (__int64)&v19[407 * v18] + 4 * v29;
  ++*(_DWORD *)(v48 + 2728);
LABEL_81:
  if ( v33 <= 1 )
  {
    if ( v33 )
    {
      if ( v33 != 1 )
        goto LABEL_102;
      v50 = v26 > 6;
      goto LABEL_95;
    }
    goto LABEL_93;
  }
  if ( v33 == 2 )
  {
LABEL_93:
    v50 = v26 > 7;
    goto LABEL_95;
  }
  if ( v33 == 3 )
  {
    v50 = v26 > 0xB;
LABEL_95:
    if ( v50 )
      v49 = 14;
    else
      v49 = v26;
    if ( !a4 )
      goto LABEL_102;
    goto LABEL_99;
  }
  if ( v33 != 4 )
    goto LABEL_102;
  v49 = v26 >= 0xE ? 14 : v26;
  if ( !a4 )
    goto LABEL_102;
LABEL_99:
  if ( v49 != 15 )
  {
    if ( v49 <= 0xEu )
    {
      v51 = (__int64)&v19[407 * v18] + 60 * (unsigned int)v33 + 4 * v49;
      ++*(_DWORD *)(v51 + 2128);
      goto LABEL_102;
    }
    goto LABEL_137;
  }
LABEL_102:
  if ( (*(_BYTE *)(a2 + 84) & 0x10) == 0 )
  {
    v52 = *(_QWORD *)(a1 + 1128);
    v71 = 0;
    v53 = *(_QWORD *)(v52 + 74392);
    v70[0] = 0;
    v54 = *(__int64 (__fastcall **)(_QWORD))(v53 + 1408);
    if ( *((_DWORD *)v54 - 1) != 855462014 )
      __break(0x8228u);
    result = v54(a3);
    if ( (_DWORD)result )
    {
      v55 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v52 + 74392) + 560LL);
      if ( *((_DWORD *)v55 - 1) != -1147376687 )
        __break(0x8228u);
      result = v55(a3);
      if ( (_BYTE)result )
      {
        v56 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v52 + 74392) + 1776LL);
        if ( v56 )
        {
          if ( *((_DWORD *)v56 - 1) != 855462014 )
            __break(0x8228u);
          result = v56(a3);
          if ( (_DWORD)result == 2048 )
          {
            result = _qdf_nbuf_data_is_ipv4_dhcp_pkt(*(_QWORD *)(a2 + 224));
            if ( (result & 1) != 0 )
              goto LABEL_123;
          }
          else
          {
            v66 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(v52 + 74392) + 1776LL);
            if ( !v66 )
              goto LABEL_123;
            if ( *((_DWORD *)v66 - 1) != 855462014 )
              __break(0x8228u);
            result = v66(a3);
            if ( (_DWORD)result != 34525 )
              goto LABEL_123;
            result = _qdf_nbuf_data_is_ipv6_dhcp_pkt(*(unsigned __int16 **)(a2 + 224));
            if ( (result & 1) != 0 )
              goto LABEL_123;
          }
          if ( a4 )
          {
            *(_DWORD *)((char *)&v19[407 * v18 + 371] + 2) = ((v68 & 0xF) << 8)
                                                           | (16 * (v26 & 0xF))
                                                           | *(_DWORD *)((_BYTE *)&v19[407 * v18 + 371] + 2)
                                                           & 0xFFFFF00F;
            if ( (*(_BYTE *)(a1 + 20091) & 1) != 0 )
              goto LABEL_123;
            LODWORD(v19[407 * v18 + 367]) = v26;
          }
          else if ( (*(_BYTE *)(a1 + 20091) & 1) != 0 )
          {
            goto LABEL_123;
          }
          if ( v33 == 1 )
            LOBYTE(v69) = 1;
          result = dp_getrateindex(v67, v26, (unsigned __int8)v69 - 1, v33, v68, 0, &v71, v70);
          if ( a4 )
          {
            v57 = &v19[407 * v18];
            v58 = (unsigned int)v57[737];
            v59 = *(_DWORD *)((char *)v57 + 2970);
            v57[735] = result;
            v60 = (unsigned __int64)(7 * v58 + (int)((_DWORD)result << 7)) >> 3;
            *(_DWORD *)((char *)v57 + 2970) = ((v67 & 0xF) << 12) | ((v33 & 0xF) << 16) | v69 & 0xF | v59 & 0xFFF00FF0;
            if ( !(_DWORD)v58 )
              LODWORD(v60) = (_DWORD)result << 7;
            v57[737] = v60;
          }
        }
      }
    }
  }
LABEL_123:
  _ReadStatusReg(SP_EL0);
  return result;
}

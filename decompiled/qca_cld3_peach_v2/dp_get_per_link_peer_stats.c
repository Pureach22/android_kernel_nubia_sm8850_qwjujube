__int64 __fastcall dp_get_per_link_peer_stats(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4)
{
  __int64 v4; // x21
  __int64 v7; // x8
  int v8; // w9
  __int64 v9; // x8
  __int64 v10; // x0
  _DWORD *v11; // x8
  __int64 *v12; // x8
  __int64 v13; // x8
  __int64 v14; // x11
  int v15; // w10
  int v16; // w9
  __int64 v17; // x10
  __int64 v18; // x8
  __int64 v19; // x9
  unsigned int v20; // w8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w5
  __int64 *v30; // x20
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 *v39; // x20
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  __int64 *v48; // x20
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 *v57; // x20
  double v58; // d0
  double v59; // d1
  double v60; // d2
  double v61; // d3
  double v62; // d4
  double v63; // d5
  double v64; // d6
  double v65; // d7
  double v66; // d0
  double v67; // d1
  double v68; // d2
  double v69; // d3
  double v70; // d4
  double v71; // d5
  double v72; // d6
  double v73; // d7
  int v75[2]; // [xsp+0h] [xbp-30h] BYREF
  int v76[2]; // [xsp+8h] [xbp-28h]
  int v77[2]; // [xsp+10h] [xbp-20h]
  int v78[2]; // [xsp+18h] [xbp-18h]
  __int64 v79; // [xsp+20h] [xbp-10h]
  __int64 v80; // [xsp+28h] [xbp-8h]

  v4 = a1;
  v80 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)v78 = 0;
  v79 = 0;
  v8 = *(_DWORD *)(a1 + 408);
  *(_QWORD *)v76 = 0;
  *(_QWORD *)v77 = 0;
  v9 = *(_QWORD *)(v7 + 24);
  *(_QWORD *)v75 = 0;
  v10 = *(_QWORD *)(v9 + 8);
  if ( v8 == 1 && (v11 = *(_DWORD **)(v4 + 416)) != nullptr || (v11 = (_DWORD *)v4) != nullptr )
  {
    *(_DWORD *)(a2 + 160) = v11[42];
    *(_DWORD *)(a2 + 192) = v11[43];
    *(_DWORD *)(a2 + 196) = v11[44];
    *(_DWORD *)(a2 + 200) = v11[45];
    *(_DWORD *)(a2 + 204) = v11[46];
    *(_DWORD *)(a2 + 208) = v11[47];
    *(_DWORD *)(a2 + 212) = v11[48];
    *(_DWORD *)(a2 + 916) = v11[49];
    *(_DWORD *)(a2 + 4064) = v11[50];
    *(_DWORD *)(a2 + 4068) = v11[51];
    *(_DWORD *)(a2 + 4072) = v11[52];
    *(_DWORD *)(a2 + 4076) = v11[53];
    v8 = *(_DWORD *)(v4 + 408);
  }
  if ( v8 != 1 || (v12 = *(__int64 **)(v4 + 416)) == nullptr )
    v12 = (__int64 *)v4;
  v13 = *v12;
  if ( v13 )
  {
    v14 = *(_QWORD *)(a2 + 16);
    v15 = *(_DWORD *)(a2 + 108);
    *(_QWORD *)(a2 + 8) += *(_QWORD *)(v13 + 16);
    *(_QWORD *)(a2 + 16) = v14 + *(_QWORD *)(v13 + 24);
    v16 = v15 + *(_DWORD *)(v13 + 12);
    v17 = *(_QWORD *)(a2 + 2752);
    *(_DWORD *)(a2 + 108) = v16;
    *(_QWORD *)(a2 + 2752) = v17 + *(_QWORD *)(v13 + 32);
    *(_QWORD *)(a2 + 2760) += *(_QWORD *)(v13 + 40);
  }
  v18 = *(unsigned int *)(a2 + 124);
  v19 = *(_QWORD *)(a2 + 88) + v18;
  if ( v19 )
    v20 = 100 * (int)v18 / (unsigned int)v19;
  else
    v20 = 0;
  *(_DWORD *)(a2 + 2076) = v20;
  if ( *(_DWORD *)(v4 + 408) != 2 )
    goto LABEL_47;
  dp_get_link_peers_ref_from_mld_peer(v10, v4, (int)v75);
  v29 = (unsigned __int8)v79;
  if ( (unsigned __int8)v79 > (unsigned int)a4 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: Req stats of %d link. less than total link %d",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dp_get_per_link_peer_stats",
      a4);
    v29 = (unsigned __int8)v79;
  }
  if ( a4 >= v29 )
    v4 = v29;
  else
    v4 = a4;
  if ( (_DWORD)v4 )
  {
    v30 = *(__int64 **)v75;
    if ( *(_QWORD *)v75 )
    {
      dp_get_peer_per_pkt_stats(*(__int64 **)v75, a2);
      dp_get_peer_extd_stats(v30, a2, v31, v32, v33, v34, v35, v36, v37, v38);
    }
    if ( (_DWORD)v4 != 1 )
    {
      v39 = *(__int64 **)v76;
      if ( *(_QWORD *)v76 )
      {
        dp_get_peer_per_pkt_stats(*(__int64 **)v76, a2 + 4544);
        dp_get_peer_extd_stats(v39, a2 + 4544, v40, v41, v42, v43, v44, v45, v46, v47);
      }
      if ( (_DWORD)v4 != 2 )
      {
        v48 = *(__int64 **)v77;
        if ( *(_QWORD *)v77 )
        {
          dp_get_peer_per_pkt_stats(*(__int64 **)v77, a2 + 9088);
          dp_get_peer_extd_stats(v48, a2 + 9088, v49, v50, v51, v52, v53, v54, v55, v56);
        }
        if ( (_DWORD)v4 != 3 )
        {
          v57 = *(__int64 **)v78;
          if ( *(_QWORD *)v78 )
          {
            dp_get_peer_per_pkt_stats(*(__int64 **)v78, a2 + 13632);
            dp_get_peer_extd_stats(v57, a2 + 13632, v58, v59, v60, v61, v62, v63, v64, v65);
          }
          if ( (_DWORD)v4 != 4 )
            goto LABEL_46;
        }
      }
    }
    v29 = (unsigned __int8)v79;
  }
  if ( v29 )
  {
    if ( *(_QWORD *)v75 )
    {
      dp_peer_unref_delete(*(__int64 *)v75, 8u, v21, v22, v23, v24, v25, v26, v27, v28);
      v29 = (unsigned __int8)v79;
    }
    *(_QWORD *)v75 = 0;
    if ( v29 >= 2 )
    {
      if ( *(_QWORD *)v76 )
      {
        dp_peer_unref_delete(*(__int64 *)v76, 8u, v21, v22, v23, v24, v25, v26, v27, v28);
        v29 = (unsigned __int8)v79;
      }
      *(_QWORD *)v76 = 0;
      if ( v29 >= 3 )
      {
        if ( *(_QWORD *)v77 )
        {
          dp_peer_unref_delete(*(__int64 *)v77, 8u, v21, v22, v23, v24, v25, v26, v27, v28);
          v29 = (unsigned __int8)v79;
        }
        *(_QWORD *)v77 = 0;
        if ( v29 >= 4 )
        {
          if ( *(_QWORD *)v78 )
          {
            dp_peer_unref_delete(*(__int64 *)v78, 8u, v21, v22, v23, v24, v25, v26, v27, v28);
            v29 = (unsigned __int8)v79;
          }
          *(_QWORD *)v78 = 0;
          if ( v29 > 4 )
          {
LABEL_46:
            __break(0x5512u);
LABEL_47:
            dp_get_peer_per_pkt_stats((__int64 *)v4, a2);
            dp_get_peer_extd_stats((__int64 *)v4, a2, v66, v67, v68, v69, v70, v71, v72, v73);
          }
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return 0;
}

__int64 __fastcall dp_rx_mon_drop_one_mpdu(
        unsigned __int8 *a1,
        unsigned __int8 a2,
        unsigned int *a3,
        __int64 *a4,
        __int64 *a5)
{
  unsigned int v5; // w19
  __int64 v6; // x27
  __int64 v7; // x8
  __int64 *v9; // x23
  __int64 v10; // x10
  unsigned int v11; // w20
  void (__fastcall *v12)(unsigned int *, unsigned __int64 *); // x8
  __int64 v13; // x21
  int v14; // w26
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned __int8 *v23; // x20
  __int64 v24; // x9
  unsigned int v25; // w22
  __int64 *v26; // x21
  __int64 v27; // x9
  unsigned int v28; // w8
  __int64 v29; // x9
  __int64 *v30; // x19
  __int64 v31; // x9
  _QWORD *v32; // x9
  __int64 *v33; // x8
  __int64 v34; // x10
  __int64 v35; // x8
  __int64 v36; // x20
  _QWORD *v37; // x24
  __int64 v38; // x1
  __int64 v39; // x28
  __int64 (__fastcall *v40)(__int64, __int64); // x8
  __int64 v41; // x25
  __int64 v42; // x9
  __int64 v43; // x22
  __int64 v44; // x27
  __int64 v45; // x23
  __int64 v46; // x26
  __int64 v47; // x0
  __int64 *v48; // x19
  __int64 v49; // x21
  __int64 v50; // x0
  char v51; // w8
  unsigned __int64 v52; // x1
  __int64 v53; // x2
  __int64 v54; // x3
  void (__fastcall *v55)(__int64 *, unsigned __int64, __int64, __int64); // x8
  void (__fastcall *v56)(__int64, unsigned __int64 *); // x8
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x0
  __int64 v66; // x8
  double v67; // d0
  double v68; // d1
  double v69; // d2
  double v70; // d3
  double v71; // d4
  double v72; // d5
  double v73; // d6
  double v74; // d7
  __int64 v75; // x19
  unsigned int v77; // [xsp+8h] [xbp-F8h]
  __int64 v79; // [xsp+18h] [xbp-E8h]
  __int64 v81; // [xsp+28h] [xbp-D8h]
  _DWORD *v82; // [xsp+38h] [xbp-C8h]
  unsigned int v83; // [xsp+40h] [xbp-C0h]
  int v84; // [xsp+44h] [xbp-BCh]
  __int64 v85; // [xsp+48h] [xbp-B8h]
  unsigned __int16 v86; // [xsp+54h] [xbp-ACh] BYREF
  unsigned __int64 v87; // [xsp+58h] [xbp-A8h] BYREF
  __int64 v88; // [xsp+60h] [xbp-A0h]
  __int64 v89; // [xsp+68h] [xbp-98h] BYREF
  _QWORD v90[6]; // [xsp+70h] [xbp-90h] BYREF
  _QWORD v91[12]; // [xsp+A0h] [xbp-60h] BYREF

  v5 = a2;
  v91[10] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *((_QWORD *)a1 + 1);
  v7 = *(_QWORD *)(v6 + 1128);
  v87 = 0;
  v88 = 0;
  memset(v91, 0, 80);
  v89 = 0;
  memset(v90, 0, sizeof(v90));
  v86 = 0;
  if ( a2 >= 3u )
    goto LABEL_61;
  if ( (*(_BYTE *)(*(_QWORD *)(v6 + 40) + 633LL) & 1) == 0 )
  {
    v5 = *a1;
    if ( v5 <= 4 )
    {
      v9 = a5;
      v10 = 12416;
      goto LABEL_6;
    }
LABEL_61:
    __break(0x5512u);
    __break(1u);
  }
  v9 = a5;
  v10 = 11456;
LABEL_6:
  v77 = a2 & 3;
  v11 = a3[7] >> 28;
  v12 = *(void (__fastcall **)(unsigned int *, unsigned __int64 *))(*(_QWORD *)(v7 + 74392) + 1456LL);
  v13 = v6 + v10;
  v14 = (unsigned __int8)a3[2];
  v82 = (_DWORD *)(*((_QWORD *)a1 + 12057) + 18528LL * (a2 & 3));
  if ( *((_DWORD *)v12 - 1) != -621572614 )
    __break(0x8228u);
  v12(a3, &v87);
  v87 = *a3 | ((unsigned __int64)*((unsigned __int8 *)a3 + 4) << 32);
  qdf_trace_msg(
    0x45u,
    8u,
    "[%s][%d] ReoAddr=%pK, addrInfo=%pK, paddr=0x%llx, loopcnt=%d",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hal_rx_reo_ent_buf_paddr_get",
    427,
    a3,
    a3,
    v11);
  v23 = a1;
  v24 = v13 + 120LL * v5;
  v25 = 0;
  v26 = v9;
  v81 = v24;
  while ( 1 )
  {
    v27 = *((_QWORD *)v23 + 1);
    v28 = ((unsigned int)v88 >> 5) & 0x3FF;
    if ( *(_BYTE *)(*(_QWORD *)(v27 + 40) + 633LL) == 1 )
      break;
    v30 = a4;
    if ( v28 >= *(unsigned __int16 *)(v27 + 1914) )
      goto LABEL_59;
    v32 = (_QWORD *)(v27 + 1920);
LABEL_16:
    v33 = (__int64 *)(*v32 + 24LL * v28);
    v34 = v33[2];
    v35 = *v33;
    if ( !(v35 + v87 - v34) )
      goto LABEL_59;
    v79 = v35 + v87 - v34;
    hal_rx_msdu_list_get_0(*(_QWORD *)(v6 + 1128), v79, v90, &v86);
    if ( v86 )
    {
      v36 = 0;
      v37 = v90;
      v85 = 4LL * v86;
      do
      {
        if ( v36 == 24 )
          goto LABEL_61;
        v38 = *(unsigned int *)((char *)v91 + v36);
        if ( *(_BYTE *)(*(_QWORD *)(v6 + 40) + 633LL) == 1 )
        {
          if ( (v38 & 0xF0000) == 0 )
          {
            v39 = *(_QWORD *)(*(_QWORD *)(v6 + 11480) + 8LL * (unsigned __int8)BYTE1(*(_DWORD *)((char *)v91 + v36)))
                + (unsigned __int8)*(_DWORD *)((char *)v91 + v36) * (unsigned int)*(unsigned __int16 *)(v6 + 11460);
            if ( v39 )
              goto LABEL_29;
          }
        }
        else
        {
          v40 = *(__int64 (__fastcall **)(__int64, __int64))(v6 + 1408);
          if ( *((_DWORD *)v40 - 1) != 207937137 )
            __break(0x8228u);
          v39 = v40(v6, v38);
          if ( v39 )
          {
LABEL_29:
            v41 = *(_QWORD *)v39;
            if ( !*(_QWORD *)v39 || (*(_BYTE *)(v39 + 30) & 1) == 0 )
              goto LABEL_19;
            v42 = 40;
            if ( (*(_BYTE *)(v41 + 68) & 4) != 0 )
              v42 = 80;
            if ( v37[10] == *(_QWORD *)(v41 + v42) )
            {
              if ( (*(_BYTE *)(v39 + 30) & 2) == 0 )
              {
                v83 = v25;
                v84 = v14;
                v43 = v6;
                v44 = *(_QWORD *)(v6 + 24);
                v45 = *(_QWORD *)(v41 + 40);
                v46 = *(unsigned __int16 *)(v81 + 74);
                if ( (_qdf_is_pp_nbuf(v41) & 1) != 0 && *(_QWORD *)(v41 + 40) )
                {
                  v47 = *(_QWORD *)(v44 + 40);
                  if ( (*(_BYTE *)(v47 + 844) & 0x40) == 0 )
                    _dma_sync_single_for_cpu(v47, v45);
                }
                else if ( v45 )
                {
                  v48 = v26;
                  v49 = *(int *)(v41 + 212);
                  qdf_mem_dp_rx_skb_cnt_dec();
                  qdf_mem_dp_rx_skb_dec(v49);
                  v50 = v49;
                  v26 = v48;
                  v30 = a4;
                  qdf_mem_skb_total_dec(v50);
                  dma_unmap_page_attrs(*(_QWORD *)(v44 + 40), v45, v46, 2, 0);
                }
                v6 = v43;
                v25 = v83;
                v14 = v84;
                *(_BYTE *)(v39 + 30) |= 2u;
              }
              _qdf_nbuf_free(v41);
              v51 = *(_BYTE *)(v39 + 30);
              *(_QWORD *)v39 = 0;
              *(_BYTE *)(v39 + 30) = v51 & 0xFE;
              *(_QWORD *)v39 = *v30;
              *v30 = v39;
              if ( !*v26 || !*(_QWORD *)v39 )
                *v26 = v39;
              ++v25;
              v14 = v14 + ((*(_DWORD *)v37 >> 2) & 1) - 1;
            }
            else
            {
LABEL_19:
              ++v82[752];
            }
            goto LABEL_20;
          }
        }
        ++v82[751];
LABEL_20:
        v36 += 4;
        ++v37;
      }
      while ( v85 != v36 );
    }
    v52 = v87;
    v53 = (unsigned int)v88;
    v54 = BYTE4(v88);
    v55 = *(void (__fastcall **)(__int64 *, unsigned __int64, __int64, __int64))(*(_QWORD *)(*(_QWORD *)(v6 + 1128)
                                                                                           + 74392LL)
                                                                               + 1472LL);
    if ( *((_DWORD *)v55 - 1) != -1494657337 )
      __break(0x8228u);
    v55(&v89, v52, v53, v54);
    v56 = *(void (__fastcall **)(__int64, unsigned __int64 *))(*(_QWORD *)(*(_QWORD *)(v6 + 1128) + 74392LL) + 1456LL);
    if ( *((_DWORD *)v56 - 1) != -621572614 )
      __break(0x8228u);
    v56(v79 + 4, &v87);
    v23 = a1;
    v65 = *((_QWORD *)a1 + 1);
    v66 = *(_QWORD *)(v65 + 40);
    v87 = *(unsigned int *)(v79 + 4) | ((unsigned __int64)*(unsigned __int8 *)(v79 + 8) << 32);
    if ( *(_BYTE *)(v66 + 633) == 1 )
    {
      if ( (unsigned int)dp_rx_mon_link_desc_return((__int64)a1, (unsigned int *)&v89, v77) )
        goto LABEL_54;
    }
    else if ( (unsigned int)dp_rx_link_desc_return_by_addr(
                              v65,
                              (unsigned int *)&v89,
                              0,
                              v57,
                              v58,
                              v59,
                              v60,
                              v61,
                              v62,
                              v63,
                              v64) )
    {
LABEL_54:
      v75 = jiffies;
      if ( dp_rx_mon_drop_one_mpdu___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x45u,
          5u,
          "%s: monitor link desc return failed",
          v67,
          v68,
          v69,
          v70,
          v71,
          v72,
          v73,
          v74,
          "dp_rx_mon_drop_one_mpdu");
        dp_rx_mon_drop_one_mpdu___last_ticks = v75;
      }
    }
    if ( !v87 || !v14 )
      goto LABEL_60;
  }
  v29 = *(_QWORD *)(v27 + 20112);
  v30 = a4;
  if ( v29 )
  {
    v31 = v29 + 40LL * v77;
    if ( v31 )
    {
      if ( v28 < *(unsigned __int16 *)(v31 + 2) )
      {
        v32 = (_QWORD *)(v31 + 8);
        goto LABEL_16;
      }
    }
  }
LABEL_59:
  ++v82[750];
LABEL_60:
  _ReadStatusReg(SP_EL0);
  return v25;
}

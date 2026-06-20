__int64 __fastcall dp_rx_tid_delete_cb(
        __int64 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v13; // x22
  unsigned __int64 v14; // x21
  unsigned int v15; // w6
  __int64 result; // x0
  __int64 v18; // x25
  unsigned __int64 v19; // x28
  unsigned __int64 StatusReg; // x8
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x20
  int v30; // w9
  __int64 v31; // x10
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w21
  _DWORD *v41; // x8
  int v42; // w23
  int v43; // w26
  __int64 v44; // x8
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x8
  unsigned int v70; // w9
  double v71; // d0
  double v72; // d1
  double v73; // d2
  double v74; // d3
  double v75; // d4
  double v76; // d5
  double v77; // d6
  double v78; // d7
  __int64 v79; // x22
  int v80; // w23
  _QWORD *v81; // x1
  __int64 v82; // x8
  unsigned __int64 v83; // x21
  unsigned __int64 v84; // x20
  unsigned __int64 v85; // x8
  unsigned __int64 v86; // x20
  __int64 v87; // x22
  __int64 v88; // x21
  __int64 v89; // x20
  __int64 v90; // x8
  double v91; // d0
  double v92; // d1
  double v93; // d2
  double v94; // d3
  double v95; // d4
  double v96; // d5
  double v97; // d6
  double v98; // d7
  __int64 v99; // x22
  _QWORD *v100; // x1
  __int64 v101; // [xsp+8h] [xbp-68h] BYREF
  unsigned int v102; // [xsp+14h] [xbp-5Ch] BYREF
  __int64 v103; // [xsp+18h] [xbp-58h] BYREF
  __int64 v104; // [xsp+20h] [xbp-50h]
  __int64 v105; // [xsp+28h] [xbp-48h]
  __int64 v106; // [xsp+30h] [xbp-40h]
  __int64 v107; // [xsp+38h] [xbp-38h]
  __int64 v108; // [xsp+40h] [xbp-30h] BYREF
  __int128 v109; // [xsp+48h] [xbp-28h]
  __int64 v110; // [xsp+58h] [xbp-18h]
  __int64 v111; // [xsp+60h] [xbp-10h]
  __int64 v112; // [xsp+68h] [xbp-8h]

  v112 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v102 = 0;
  v101 = 0;
  v13 = jiffies;
  v14 = jiffies;
  v15 = a3[1];
  v106 = 0;
  v107 = 0;
  v104 = 0;
  v105 = 0;
  v103 = 0;
  if ( v15 )
  {
    if ( v15 == 255 )
    {
      qdf_mem_set(a3, 0x6Cu, 0);
      a3[1] = 255;
      result = dp_reo_desc_free(a1, a2, a3);
      if ( a1 )
        ++*(_DWORD *)(a1 + 14096);
      goto LABEL_53;
    }
    v18 = jiffies;
    if ( dp_rx_tid_delete_cb___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x45u,
        5u,
        "%s: Rx tid HW desc deletion failed(%d): tid %d",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "dp_rx_tid_delete_cb",
        v15,
        *(unsigned int *)(a2 + 24));
      dp_rx_tid_delete_cb___last_ticks = v18;
    }
  }
  v19 = 1000 * (v13 / 0xFA) + 4 * (v14 % 0xFA);
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: %pK: rx_tid: %d status: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "dp_rx_tid_delete_cb",
    a1,
    *(unsigned int *)(a2 + 24));
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 17872);
  }
  else
  {
    raw_spin_lock_bh(a1 + 17872);
    *(_QWORD *)(a1 + 17880) |= 1uLL;
  }
  *(_QWORD *)(a2 + 16) = v19;
  qdf_list_insert_back_size(a1 + 17848, (_QWORD *)a2, (int *)&v102);
  if ( v102 >= 0x41 )
  {
    qdf_trace_msg(
      0x45u,
      5u,
      "%s: %lu:freedesc number %d in freelist",
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      "dp_reo_limit_clean_batch_sz",
      1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL));
    v102 = 64;
  }
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 17848), &v101) )
  {
    while ( v102 > 0x3F || v19 > *(_QWORD *)(v101 + 16) + 1000LL || v102 && (*(_BYTE *)(v101 + 168) & 1) != 0 )
    {
      qdf_list_remove_front((_DWORD *)(a1 + 17848), &v101);
      v29 = v101;
      v30 = *(unsigned __int8 *)(v101 + 168);
      --v102;
      if ( v30 == 1 )
      {
        v110 = 0;
        v111 = 0;
        v109 = 0u;
        v108 = 0;
        qdf_mem_set(&v108, 0x28u, 0);
        v31 = HIDWORD(*(_QWORD *)(v29 + 80));
        HIDWORD(v108) = *(_QWORD *)(v29 + 80);
        LOBYTE(v108) = 1;
        LOBYTE(v109) = v31;
        *(_QWORD *)((char *)&v109 + 4) = *(_QWORD *)((_BYTE *)&v109 + 4) & 0xFFFEFFFFFFFFFFFDLL | 2;
        *(_BYTE *)(v29 + 168) = 0;
        if ( (unsigned int)dp_reo_send_cmd(
                             a1,
                             5u,
                             v32,
                             v33,
                             v34,
                             v35,
                             v36,
                             v37,
                             v38,
                             v39,
                             (__int64)&v108,
                             (__int64)dp_rx_tid_delete_cb,
                             v29) )
        {
          *(_BYTE *)(v29 + 168) = 1;
          *(_QWORD *)(v29 + 16) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
          qdf_list_insert_back((_QWORD *)(a1 + 17848), (_QWORD *)v29);
          qdf_trace_msg(
            0x45u,
            5u,
            "%s: failed to send reo cmd CMD_UPDATE_RX_REO_QUEUE",
            v91,
            v92,
            v93,
            v94,
            v95,
            v96,
            v97,
            v98,
            "dp_resend_update_reo_cmd");
          if ( a1 )
LABEL_60:
            ++*(_DWORD *)(a1 + 14092);
          break;
        }
      }
      else
      {
        v40 = *(_DWORD *)(v101 + 172);
        if ( !v40 )
          v40 = *(_DWORD *)(v101 + 88);
        v41 = *(_DWORD **)(*(_QWORD *)(*(_QWORD *)(a1 + 1128) + 74392LL) + 1152LL);
        if ( v41 )
        {
          if ( *(v41 - 1) != 1946320769 )
            __break(0x8228u);
          v42 = ((__int64 (__fastcall *)(_QWORD, __int64))v41)(0, 16);
        }
        else
        {
          v42 = 128;
        }
        while ( 1 )
        {
          v43 = v40 - v42;
          if ( v40 == v42 )
            break;
          qdf_mem_set(&v103, 0x28u, 0);
          v44 = *(_QWORD *)(v29 + 80);
          HIDWORD(v103) = v40 - v42 + v44;
          LOBYTE(v104) = BYTE4(v44);
          v40 -= v42;
          if ( (unsigned int)dp_reo_send_cmd(a1, 2u, v45, v46, v47, v48, v49, v50, v51, v52, (__int64)&v103, 0, 0) )
          {
            v79 = jiffies;
            v80 = v42 + v43;
            if ( dp_rx_tid_delete_cb___last_ticks_18 - jiffies + 125 < 0 )
            {
              qdf_trace_msg(
                0x45u,
                5u,
                "%s: fail to send CMD_CACHE_FLUSH:tid %d desc %pK",
                v53,
                v54,
                v55,
                v56,
                v57,
                v58,
                v59,
                v60,
                "dp_rx_tid_delete_cb",
                *(unsigned int *)(v29 + 24),
                *(_QWORD *)(v29 + 80));
              dp_rx_tid_delete_cb___last_ticks_18 = v79;
            }
            v81 = (_QWORD *)v101;
            *(_DWORD *)(v101 + 172) = v80;
            v81[2] = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
            if ( a1 )
              ++*(_DWORD *)(a1 + 14092);
            qdf_list_insert_back((_QWORD *)(a1 + 17848), v81);
            goto LABEL_41;
          }
        }
        *(_DWORD *)(v101 + 172) = v42;
        qdf_mem_set(&v103, 0x28u, 0);
        v69 = *(_QWORD *)(v29 + 80);
        v70 = *(unsigned __int16 *)(v29 + 96);
        LOBYTE(v103) = 1;
        HIDWORD(v103) = v69;
        LOBYTE(v104) = BYTE4(v69);
        if ( v70 >= 0x101 )
          BYTE2(v105) = 1;
        BYTE4(v104) = 1;
        if ( (unsigned int)dp_reo_send_cmd(
                             a1,
                             2u,
                             v61,
                             v62,
                             v63,
                             v64,
                             v65,
                             v66,
                             v67,
                             v68,
                             (__int64)&v103,
                             (__int64)dp_reo_desc_free,
                             v101) )
        {
          v99 = jiffies;
          if ( dp_rx_tid_delete_cb___last_ticks_20 - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x45u,
              5u,
              "%s: fail to send REO cmd to flush cache: tid %d",
              v71,
              v72,
              v73,
              v74,
              v75,
              v76,
              v77,
              v78,
              "dp_rx_tid_delete_cb",
              *(unsigned int *)(v29 + 24));
            dp_rx_tid_delete_cb___last_ticks_20 = v99;
          }
          v100 = (_QWORD *)v101;
          *(_QWORD *)(v101 + 16) = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
          if ( a1 )
          {
            ++*(_DWORD *)(a1 + 14092);
            qdf_list_insert_back((_QWORD *)(a1 + 17848), v100);
            goto LABEL_60;
          }
          qdf_list_insert_back(qword_45B8, v100);
          break;
        }
      }
      if ( (unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 17848), &v101) )
        break;
    }
  }
LABEL_41:
  v82 = *(_QWORD *)(a1 + 17880);
  if ( (v82 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 17880) = v82 & 0xFFFFFFFFFFFFFFFELL;
    raw_spin_unlock_bh(a1 + 17872);
  }
  else
  {
    raw_spin_unlock(a1 + 17872);
  }
  v108 = 0;
  v83 = jiffies;
  v84 = jiffies;
  if ( (_ReadStatusReg(DAIF) & 0x80) != 0
    || (v85 = _ReadStatusReg(SP_EL0), (*(_DWORD *)(v85 + 16) & 0xF0000) != 0)
    || (*(_DWORD *)(v85 + 16) & 0xFF00) != 0 )
  {
    raw_spin_lock(a1 + 20040);
  }
  else
  {
    raw_spin_lock_bh(a1 + 20040);
    *(_QWORD *)(a1 + 20048) |= 1uLL;
  }
  if ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 20016), &v108) )
  {
    v86 = 1000 * (v83 / 0xFA) + 4 * (v84 % 0xFA);
    do
    {
      if ( v86 <= *(_QWORD *)(v108 + 16) + 30000LL )
        break;
      qdf_list_remove_front((_DWORD *)(a1 + 20016), &v108);
      v87 = *(_QWORD *)(a1 + 24);
      v88 = *(int *)(v108 + 40);
      v89 = *(_QWORD *)(v108 + 32);
      qdf_mem_skb_total_dec(v88);
      dma_unmap_page_attrs(*(_QWORD *)(v87 + 40), v89, v88, 0, 0);
      _qdf_mem_free(*(_QWORD *)(v108 + 24));
      _qdf_mem_free(v108);
      v86 = 1000 * (jiffies / 0xFAuLL) + 4 * (jiffies % 0xFAuLL);
    }
    while ( !(unsigned int)qdf_list_peek_front((_QWORD *)(a1 + 20016), &v108) );
  }
  v90 = *(_QWORD *)(a1 + 20048);
  if ( (v90 & 1) != 0 )
  {
    *(_QWORD *)(a1 + 20048) = v90 & 0xFFFFFFFFFFFFFFFELL;
    result = raw_spin_unlock_bh(a1 + 20040);
  }
  else
  {
    result = raw_spin_unlock(a1 + 20040);
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}

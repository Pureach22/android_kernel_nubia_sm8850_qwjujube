__int64 __fastcall dbglog_parse_debug_logs(
        __int64 *a1,
        __int64 *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v11; // x2
  const char *v12; // x3
  __int64 result; // x0
  unsigned int v14; // w21
  __int64 *v15; // x19
  __int64 *v16; // x20
  unsigned int v17; // w22
  size_t v18; // x20
  unsigned int *v19; // x19
  unsigned int v20; // w28
  unsigned int v21; // w23
  __int64 is_initialized; // x0
  __int64 v23; // x1
  __int64 v24; // x2
  __int64 v25; // x3
  int radio_index; // w0
  unsigned int v27; // w25
  __int64 v28; // x23
  __int64 v29; // x0
  __int64 **v30; // x24
  _QWORD *v31; // x22
  _DWORD *v32; // x0
  int v33; // w8
  _DWORD *v34; // x21
  _QWORD *v35; // x8
  __int64 v36; // x1
  unsigned int v37; // w8
  __int64 *v38; // x1
  __int64 v39; // x8
  _QWORD *v40; // x9
  int v41; // w20
  unsigned int v42; // w21
  unsigned __int64 v43; // x23
  unsigned __int64 v44; // x22
  __int64 v45; // x26
  __int64 v46; // x27
  void *v47; // x0
  double v48; // d0
  double v49; // d1
  double v50; // d2
  double v51; // d3
  double v52; // d4
  double v53; // d5
  double v54; // d6
  double v55; // d7
  int v56; // w28
  unsigned int v57; // w23
  unsigned __int64 v58; // x25
  unsigned int v59; // w8
  __int64 v60; // x25
  unsigned int v61; // w9
  unsigned int v62; // w8
  unsigned __int64 v63; // x26
  __int64 v64; // x20
  unsigned int v65; // w28
  unsigned int v66; // w21
  __int64 v67; // x22
  _DWORD *v68; // x8
  int v69; // w24
  _DWORD *v70; // x0
  __int64 v71; // x22
  _DWORD *v72; // x0
  int v73; // w8
  _DWORD *v74; // x21
  double v75; // d0
  double v76; // d1
  double v77; // d2
  double v78; // d3
  double v79; // d4
  double v80; // d5
  double v81; // d6
  double v82; // d7
  unsigned int v83; // w19
  __int64 v84; // [xsp+0h] [xbp-90h]
  unsigned int v85; // [xsp+10h] [xbp-80h]
  unsigned int v86; // [xsp+14h] [xbp-7Ch]
  _QWORD v87[15]; // [xsp+18h] [xbp-78h] BYREF

  v87[14] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    if ( (dword_17AC4 & 1) != 0 )
    {
      v11 = "%s: NULL Pointer assigned\n";
      goto LABEL_8;
    }
LABEL_10:
    result = 0xFFFFFFFFLL;
LABEL_11:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  if ( *((_BYTE *)a1 + 620) )
  {
    *((_BYTE *)a1 + 620) = 0;
    if ( a3 <= 3 )
      goto LABEL_4;
  }
  else
  {
    if ( !a2 )
    {
      if ( (dword_17AC4 & 1) == 0 )
        goto LABEL_10;
      v11 = "%s: Get NULL point message from FW\n";
      goto LABEL_8;
    }
    a3 = *((_DWORD *)a2 + 2);
    a2 = (__int64 *)*a2;
    if ( a3 <= 3 )
    {
LABEL_4:
      if ( (dword_17AC4 & 1) != 0 )
      {
        v11 = "%s: Invalid length\n";
LABEL_8:
        v12 = "dbglog_parse_debug_logs";
LABEL_9:
        qdf_trace_msg(0x38u, 2u, v11, a4, a5, a6, a7, a8, a9, a10, a11, v12);
        goto LABEL_10;
      }
      goto LABEL_10;
    }
  }
  v14 = *(_DWORD *)a2;
  if ( *(_DWORD *)a2 && (dword_17AC4 & 8) != 0 )
  {
    v15 = a1;
    v16 = a2;
    v17 = a3;
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: %d log buffers are dropped\n",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "dbglog_parse_debug_logs",
      v14);
    a1 = v15;
    a2 = v16;
    a3 = v17;
  }
  v18 = a3 - 4;
  v19 = (unsigned int *)a2 + 1;
  v20 = (unsigned int)v18 >> 2;
  v86 = (unsigned int)v18 >> 2;
  if ( dbglog_process_type != 1 )
  {
    if ( dbglog_process_type == 2 )
    {
      if ( (unsigned int)v18 < 0x5DD )
      {
        v27 = a3;
        v28 = *a1;
        v29 = _alloc_skb(1516, 3264, 0, 0xFFFFFFFFLL);
        if ( v29 )
        {
          v30 = (__int64 **)(v28 + 336);
          v31 = (_QWORD *)v29;
          v32 = (_DWORD *)skb_put(v29, 1516);
          *v32 = 2;
          v33 = jiffies;
          v32[3] = v14;
          v34 = v32 + 4;
          v32[1] = v33;
          v32[2] = v18;
          memcpy(v32 + 4, v19, v18);
          memset((char *)v34 + v18, 0, 1504 - v27);
          raw_spin_lock(v28 + 356);
          v35 = *(_QWORD **)(v28 + 344);
          *v31 = v28 + 336;
          v31[1] = v35;
          *(_QWORD *)(v28 + 344) = v31;
          *v35 = v31;
          ++*(_DWORD *)(v28 + 352);
          complete(v28 + 360, v36);
          v37 = *(_DWORD *)(v28 + 352);
          if ( v37 >= 0x15 )
          {
            do
            {
              v38 = *v30;
              if ( *v30 != (__int64 *)v30 && v38 )
              {
                *(_DWORD *)(v28 + 352) = v37 - 1;
                v39 = *v38;
                v40 = (_QWORD *)v38[1];
                *v38 = 0;
                v38[1] = 0;
                *(_QWORD *)(v39 + 8) = v40;
                *v40 = v39;
                sk_skb_reason_drop(0, v38, 2);
                v37 = *(_DWORD *)(v28 + 352);
              }
            }
            while ( v37 > 0x14 );
          }
          raw_spin_unlock(v28 + 356);
          result = 1;
        }
        else
        {
          result = 4294967284LL;
        }
        goto LABEL_11;
      }
    }
    else
    {
      if ( dbglog_process_type != 3 )
      {
        if ( (unsigned int)v18 >= 0xC )
        {
          v59 = 0;
          v60 = (__int64)a2 + 12;
          v61 = 2;
          do
          {
            result = 0;
            v63 = v19[v59 + 1];
            if ( ((unsigned int)v63 >> 26) + v61 > v20 )
              break;
            v64 = (unsigned __int8)(v63 >> 10);
            if ( (unsigned int)v64 > 0x9C )
              break;
            v65 = v59;
            v66 = v19[v59];
            v67 = v60 + 4LL * v59;
            v68 = (_DWORD *)mod_print[v64];
            if ( !v68 )
              goto LABEL_53;
            if ( *(v68 - 1) != -780336604 )
              __break(0x8228u);
            if ( (((__int64 (__fastcall *)(_QWORD, _QWORD, unsigned __int64, _QWORD, _QWORD, __int64))v68)(
                    (unsigned __int8)(v63 >> 10),
                    (unsigned __int8)((unsigned int)v63 >> 18),
                    v63 & 0x3FF,
                    v66,
                    (unsigned int)v63 >> 26,
                    v67)
                & 1) == 0 )
LABEL_53:
              dbglog_default_print_handler((unsigned __int8)(v63 >> 10));
            v62 = v65 + ((unsigned int)v63 >> 26);
            v20 = v86;
            result = 0;
            v61 = v62 + 4;
            v59 = v62 + 2;
          }
          while ( v61 < v86 );
          goto LABEL_11;
        }
        goto LABEL_67;
      }
      if ( (unsigned int)v18 < 0x5DD )
      {
        v21 = a3;
        is_initialized = nl_srv_is_initialized();
        if ( (_DWORD)is_initialized
          || (radio_index = cds_get_radio_index(is_initialized, v23, v24, v25), radio_index == -22) )
        {
          result = 4294967291LL;
          goto LABEL_11;
        }
        v69 = radio_index;
        if ( (unsigned __int8)cds_is_multicast_logging() )
        {
          v70 = (_DWORD *)_alloc_skb(1536, 3264, 0, 0xFFFFFFFFLL);
          if ( v70 )
          {
            v71 = (__int64)v70;
            if ( v70[29] || v70[53] - v70[52] < 1536 || (v72 = (_DWORD *)_nlmsg_put(v70, 0)) == nullptr )
            {
              sk_skb_reason_drop(0, v71, 2);
              result = 4294967206LL;
            }
            else
            {
              v72[4] = v69;
              v72[5] = 2;
              v73 = jiffies;
              v72[8] = v14;
              v74 = v72 + 9;
              v72[6] = v73;
              v72[7] = v18;
              memcpy(v72 + 9, v19, v18);
              memset((char *)v74 + v18, 0, 1504 - v21);
              result = nl_srv_bcast(v71, 2u, 27);
              if ( (result & 0x80000000) != 0 && (_DWORD)result != -3 && (dword_17AC4 & 0x10) != 0 )
              {
                v83 = result;
                qdf_trace_msg(
                  0x38u,
                  2u,
                  "%s: %s: nl_srv_bcast_fw_logs failed 0x%x\n",
                  v75,
                  v76,
                  v77,
                  v78,
                  v79,
                  v80,
                  v81,
                  v82,
                  "dbglog_process_netlink_data",
                  "dbglog_process_netlink_data",
                  (unsigned int)result);
                result = v83;
              }
            }
            goto LABEL_11;
          }
          if ( (dword_17AC4 & 1) == 0 )
            goto LABEL_10;
          v11 = "%s: Failed to allocate new skb\n";
          v12 = "dbglog_process_netlink_data";
          goto LABEL_9;
        }
LABEL_67:
        result = 0;
        goto LABEL_11;
      }
    }
    __break(0x800u);
    result = 4294967277LL;
    goto LABEL_11;
  }
  if ( (unsigned int)v18 < 8 )
    goto LABEL_67;
  v41 = 0;
  v42 = 1;
  memset(v87, 0, 109);
  while ( 1 )
  {
    v43 = v19[v42];
    v44 = v43 >> 26;
    if ( (unsigned int)v43 >> 27 <= 4 )
    {
      v45 = v43 & 0x3FF;
      if ( (v19[v42] & 0x3FF) <= 0xFF )
      {
        v46 = (unsigned __int8)(v43 >> 10);
        if ( (unsigned int)v46 <= 0x9C )
          break;
      }
    }
LABEL_36:
    v42 = v41 + v44 + 3;
    v41 += v44 + 2;
    if ( v42 >= v20 )
      goto LABEL_67;
  }
  v85 = v19[v41];
  v47 = qdf_mem_set(v87, 0x6Du, 0);
  if ( (unsigned int)v43 >> 26 )
  {
    v56 = v41 + 2;
    if ( (int)v44 + v41 + 2 <= v86 )
    {
      v57 = 0;
      v58 = v44;
      do
      {
        if ( v57 >= 0x6E )
          __break(0x5512u);
        v47 = (void *)snprintf((char *)v87 + v57, 109 - v57, "%x ", v19[v56]);
        --v58;
        v57 += (unsigned int)v47;
        ++v56;
      }
      while ( v58 );
    }
  }
  if ( ((v46 << 11) | (unsigned __int64)(8 * v45)) >> 11 <= 0x9C )
  {
    v20 = v86;
    if ( (&DBG_MSG_ARR[256 * v46])[v45] )
    {
      if ( (dword_17AC4 & 4) != 0 )
        qdf_trace_msg(
          0x38u,
          2u,
          "%s: fw:%s(%x %x):%s\n",
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          v54,
          v55,
          "dbglog_print_raw_data");
    }
    else if ( (dword_17AC4 & 4) != 0 )
    {
      LODWORD(v84) = v19[v42];
      qdf_trace_msg(
        0x38u,
        2u,
        "%s: fw:%s:m:%x,id:%x(%x %x):%s\n",
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        "dbglog_print_raw_data",
        "UNKNOWN",
        (unsigned int)v46,
        (unsigned int)v45,
        v85,
        v84,
        v87);
    }
    goto LABEL_36;
  }
  __break(1u);
  return dbglog_default_print_handler(v47);
}

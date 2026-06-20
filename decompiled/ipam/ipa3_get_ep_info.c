__int64 __fastcall ipa3_get_ep_info(_DWORD *a1, __int64 a2)
{
  int v2; // w8
  int v5; // w8
  unsigned __int64 v6; // x8
  _DWORD *v7; // x9
  __int64 ep_mapping; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x8
  int v16; // w8
  unsigned __int64 v17; // x8
  _DWORD *v18; // x9
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x0
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x8
  int v26; // w8
  unsigned __int64 v27; // x8
  _DWORD *v28; // x9
  __int64 v29; // x8
  __int64 v30; // x0
  __int64 v31; // x0
  __int64 v32; // x0
  __int64 v33; // x8
  __int64 v34; // x0
  __int64 v35; // x8
  __int64 v36; // x8
  __int64 v37; // x0
  __int64 v38; // x0
  __int64 result; // x0
  __int64 v40; // x8
  __int64 v41; // x0
  __int64 v42; // x0
  __int64 v43; // x0
  __int64 v44; // x8
  __int64 v45; // x0
  __int64 v46; // x8
  __int64 v47; // x8
  __int64 v48; // x0
  __int64 v49; // x0
  __int64 v50; // x0
  __int64 v51; // x8
  __int64 v52; // x0
  __int64 v53; // x8
  __int64 v54; // x0
  __int64 v55; // x0
  __int64 v56; // x0
  __int64 v57; // x8
  __int64 v58; // x0
  __int64 v59; // x8
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x0
  __int64 v63; // x0
  __int64 v64; // x8
  __int64 v65; // x0
  __int64 v66; // x8
  __int64 v67; // x0
  __int64 v68; // x0
  __int64 v69; // x0
  __int64 v70; // x8
  __int64 v71; // x8
  __int64 v72; // x0
  __int64 v73; // x0
  __int64 v74; // x0
  __int64 v75; // x8
  __int64 v76; // x8
  __int64 v77; // x0
  __int64 v78; // x0
  __int64 v79; // x0
  __int64 v80; // x8
  __int64 v81; // x0
  __int64 v82; // x8
  int v83; // w8
  __int64 v84; // x8
  __int64 v85; // x0
  __int64 v86; // x0
  __int64 v87; // x0
  __int64 v88; // x8
  __int64 v89; // x0
  __int64 v90; // x8
  __int64 v91; // x0
  __int64 v92; // x0
  __int64 v93; // x0
  __int64 v94; // x8

  v2 = *a1;
  if ( *a1 == 6 )
  {
    v26 = *((unsigned __int8 *)a1 + 8);
    *((_BYTE *)a1 + 9) = 0;
    if ( v26 )
    {
      v27 = 0;
      v28 = (_DWORD *)(a2 + 8);
      do
      {
        *((_QWORD *)v28 - 1) = -1;
        ++v27;
        *v28 = -1;
        v28 += 4;
      }
      while ( v27 < *((unsigned __int8 *)a1 + 8) );
    }
    ep_mapping = ipa_get_ep_mapping(116);
    if ( (_DWORD)ep_mapping != -1 )
    {
      if ( (unsigned int)ep_mapping >= 0x24 )
        goto LABEL_187;
      if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
      {
        *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = ep_mapping;
        ep_mapping = ipa_get_ep_mapping(117);
        if ( (_DWORD)ep_mapping == -1 )
          goto LABEL_73;
        if ( (unsigned int)ep_mapping > 0x23 )
          goto LABEL_187;
        if ( !*(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
        {
LABEL_73:
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = -1;
          v40 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v41 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v41 )
            {
              ipc_log_string(
                v41,
                "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                "ipa3_get_eth_ep_info",
                1452,
                *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
              v40 = ipa3_ctx;
            }
            v42 = *(_QWORD *)(v40 + 34160);
            if ( v42 )
            {
              ipc_log_string(
                v42,
                "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                "ipa3_get_eth_ep_info",
                1452,
                *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
              v40 = ipa3_ctx;
            }
            if ( v40 )
            {
              v43 = *(_QWORD *)(v40 + 34152);
              if ( v43 )
              {
                v44 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                ipc_log_string(
                  v43,
                  "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                  "ipa3_get_eth_ep_info",
                  1455,
                  *(_DWORD *)(v44 + 4),
                  *(_DWORD *)(v44 + 8));
                v40 = ipa3_ctx;
              }
              v45 = *(_QWORD *)(v40 + 34160);
              if ( v45 )
              {
                v46 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                ipc_log_string(
                  v45,
                  "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                  "ipa3_get_eth_ep_info",
                  1455,
                  *(_DWORD *)(v46 + 4),
                  *(_DWORD *)(v46 + 8));
              }
            }
          }
        }
        else
        {
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4) = ep_mapping;
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8) = 32;
          v29 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v30 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v30 )
            {
              ipc_log_string(
                v30,
                "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                "ipa3_get_eth_ep_info",
                1444,
                *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
              v29 = ipa3_ctx;
            }
            v31 = *(_QWORD *)(v29 + 34160);
            if ( v31 )
            {
              ipc_log_string(
                v31,
                "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                "ipa3_get_eth_ep_info",
                1444,
                *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
              v29 = ipa3_ctx;
            }
            if ( v29 )
            {
              v32 = *(_QWORD *)(v29 + 34152);
              if ( v32 )
              {
                v33 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                ipc_log_string(
                  v32,
                  "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                  "ipa3_get_eth_ep_info",
                  1447,
                  *(_DWORD *)(v33 + 4),
                  *(_DWORD *)(v33 + 8));
                v29 = ipa3_ctx;
              }
              v34 = *(_QWORD *)(v29 + 34160);
              if ( v34 )
              {
                v35 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                ipc_log_string(
                  v34,
                  "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                  "ipa3_get_eth_ep_info",
                  1447,
                  *(_DWORD *)(v35 + 4),
                  *(_DWORD *)(v35 + 8));
              }
            }
          }
          ++*((_BYTE *)a1 + 9);
        }
      }
    }
    ep_mapping = ipa_get_ep_mapping(48);
    if ( (_DWORD)ep_mapping != -1 )
    {
      if ( (unsigned int)ep_mapping > 0x23 )
        goto LABEL_187;
      if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
      {
        *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = ep_mapping;
        ep_mapping = ipa_get_ep_mapping(49);
        if ( (_DWORD)ep_mapping != -1 )
        {
          if ( (unsigned int)ep_mapping > 0x23 )
            goto LABEL_187;
          if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
          {
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4) = ep_mapping;
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8) = 31;
            v47 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v48 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v48 )
              {
                ipc_log_string(
                  v48,
                  "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                  "ipa3_get_eth_ep_info",
                  1471,
                  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
                v47 = ipa3_ctx;
              }
              v49 = *(_QWORD *)(v47 + 34160);
              if ( v49 )
              {
                ipc_log_string(
                  v49,
                  "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                  "ipa3_get_eth_ep_info",
                  1471,
                  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
                v47 = ipa3_ctx;
              }
              if ( v47 )
              {
                v50 = *(_QWORD *)(v47 + 34152);
                if ( v50 )
                {
                  v51 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                  ipc_log_string(
                    v50,
                    "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                    "ipa3_get_eth_ep_info",
                    1474,
                    *(_DWORD *)(v51 + 4),
                    *(_DWORD *)(v51 + 8));
                  v47 = ipa3_ctx;
                }
                v52 = *(_QWORD *)(v47 + 34160);
                if ( v52 )
                  ipc_log_string(
                    v52,
                    "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                    "ipa3_get_eth_ep_info",
                    1474,
                    *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4),
                    *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8));
              }
            }
            goto LABEL_174;
          }
        }
        *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = -1;
        v66 = ipa3_ctx;
        if ( !ipa3_ctx )
          return 0;
        v67 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v67 )
        {
          ipc_log_string(
            v67,
            "ipa %s:%d ep_pair_info consumer_pipe_num %d",
            "ipa3_get_eth_ep_info",
            1479,
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
          v66 = ipa3_ctx;
        }
        v68 = *(_QWORD *)(v66 + 34160);
        if ( v68 )
        {
          ipc_log_string(
            v68,
            "ipa %s:%d ep_pair_info consumer_pipe_num %d",
            "ipa3_get_eth_ep_info",
            1479,
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
          v66 = ipa3_ctx;
        }
        if ( !v66 )
          return 0;
        v69 = *(_QWORD *)(v66 + 34152);
        if ( v69 )
        {
          v70 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
          ipc_log_string(
            v69,
            "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
            "ipa3_get_eth_ep_info",
            1482,
            *(_DWORD *)(v70 + 4),
            *(_DWORD *)(v70 + 8));
          v66 = ipa3_ctx;
        }
        result = *(_QWORD *)(v66 + 34160);
        if ( !result )
          return result;
        ipc_log_string(
          result,
          "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
          "ipa3_get_eth_ep_info",
          1482,
          *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4),
          *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8));
      }
    }
    return 0;
  }
  if ( v2 == 3 )
  {
    v16 = *((unsigned __int8 *)a1 + 8);
    *((_BYTE *)a1 + 9) = 0;
    if ( v16 )
    {
      v17 = 0;
      v18 = (_DWORD *)(a2 + 8);
      do
      {
        *((_QWORD *)v18 - 1) = -1;
        ++v17;
        *v18 = -1;
        v18 += 4;
      }
      while ( v17 < *((unsigned __int8 *)a1 + 8) );
    }
    if ( *(_DWORD *)(ipa3_ctx + 32240) <= 0x14u )
    {
      ep_mapping = ipa_get_ep_mapping(112);
      if ( (_DWORD)ep_mapping != -1 )
      {
        if ( (unsigned int)ep_mapping >= 0x24 )
          goto LABEL_187;
        if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
        {
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = ep_mapping;
          ep_mapping = ipa_get_ep_mapping(113);
          if ( (_DWORD)ep_mapping == -1 )
            goto LABEL_145;
          if ( (unsigned int)ep_mapping > 0x23 )
            goto LABEL_187;
          if ( !*(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
          {
LABEL_145:
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = -1;
            v76 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v77 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v77 )
              {
                ipc_log_string(
                  v77,
                  "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                  "ipa3_get_pcie_ep_info",
                  1379,
                  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
                v76 = ipa3_ctx;
              }
              v78 = *(_QWORD *)(v76 + 34160);
              if ( v78 )
              {
                ipc_log_string(
                  v78,
                  "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                  "ipa3_get_pcie_ep_info",
                  1379,
                  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
                v76 = ipa3_ctx;
              }
              if ( v76 )
              {
                v79 = *(_QWORD *)(v76 + 34152);
                if ( v79 )
                {
                  v80 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                  ipc_log_string(
                    v79,
                    "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                    "ipa3_get_pcie_ep_info",
                    1382,
                    *(_DWORD *)(v80 + 4),
                    *(_DWORD *)(v80 + 8));
                  v76 = ipa3_ctx;
                }
                v81 = *(_QWORD *)(v76 + 34160);
                if ( v81 )
                {
                  v82 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                  ipc_log_string(
                    v81,
                    "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                    "ipa3_get_pcie_ep_info",
                    1382,
                    *(_DWORD *)(v82 + 4),
                    *(_DWORD *)(v82 + 8));
                }
              }
            }
          }
          else
          {
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4) = ep_mapping;
            *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8) = 22;
            v19 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v20 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v20 )
              {
                ipc_log_string(
                  v20,
                  "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                  "ipa3_get_pcie_ep_info",
                  1371,
                  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
                v19 = ipa3_ctx;
              }
              v21 = *(_QWORD *)(v19 + 34160);
              if ( v21 )
              {
                ipc_log_string(
                  v21,
                  "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                  "ipa3_get_pcie_ep_info",
                  1371,
                  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
                v19 = ipa3_ctx;
              }
              if ( v19 )
              {
                v22 = *(_QWORD *)(v19 + 34152);
                if ( v22 )
                {
                  v23 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                  ipc_log_string(
                    v22,
                    "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                    "ipa3_get_pcie_ep_info",
                    1374,
                    *(_DWORD *)(v23 + 4),
                    *(_DWORD *)(v23 + 8));
                  v19 = ipa3_ctx;
                }
                v24 = *(_QWORD *)(v19 + 34160);
                if ( v24 )
                {
                  v25 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                  ipc_log_string(
                    v24,
                    "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                    "ipa3_get_pcie_ep_info",
                    1374,
                    *(_DWORD *)(v25 + 4),
                    *(_DWORD *)(v25 + 8));
                }
              }
            }
            ++*((_BYTE *)a1 + 9);
          }
        }
      }
    }
    ep_mapping = ipa_get_ep_mapping(42);
    if ( (_DWORD)ep_mapping == -1 )
      return 0;
    if ( (unsigned int)ep_mapping <= 0x23 )
    {
      if ( !*(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
        return 0;
      *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = ep_mapping;
      ep_mapping = ipa_get_ep_mapping(43);
      if ( (_DWORD)ep_mapping != -1 )
      {
        if ( (unsigned int)ep_mapping > 0x23 )
          goto LABEL_187;
        if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
        {
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4) = ep_mapping;
          if ( *(_DWORD *)(ipa3_ctx + 32240) >= 0x15u )
            v83 = 4;
          else
            v83 = 21;
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8) = v83;
          v84 = ipa3_ctx;
          if ( ipa3_ctx )
          {
            v85 = *(_QWORD *)(ipa3_ctx + 34152);
            if ( v85 )
            {
              ipc_log_string(
                v85,
                "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                "ipa3_get_pcie_ep_info",
                1403,
                *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
              v84 = ipa3_ctx;
            }
            v86 = *(_QWORD *)(v84 + 34160);
            if ( v86 )
            {
              ipc_log_string(
                v86,
                "ipa %s:%d ep_pair_info consumer_pipe_num %d",
                "ipa3_get_pcie_ep_info",
                1403,
                *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
              v84 = ipa3_ctx;
            }
            if ( v84 )
            {
              v87 = *(_QWORD *)(v84 + 34152);
              if ( v87 )
              {
                v88 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
                ipc_log_string(
                  v87,
                  "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                  "ipa3_get_pcie_ep_info",
                  1406,
                  *(_DWORD *)(v88 + 4),
                  *(_DWORD *)(v88 + 8));
                v84 = ipa3_ctx;
              }
              v89 = *(_QWORD *)(v84 + 34160);
              if ( v89 )
                ipc_log_string(
                  v89,
                  "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                  "ipa3_get_pcie_ep_info",
                  1406,
                  *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4),
                  *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8));
            }
          }
          goto LABEL_174;
        }
      }
      *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = -1;
      v90 = ipa3_ctx;
      if ( !ipa3_ctx )
        return 0;
      v91 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v91 )
      {
        ipc_log_string(
          v91,
          "ipa %s:%d ep_pair_info consumer_pipe_num %d",
          "ipa3_get_pcie_ep_info",
          1411,
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
        v90 = ipa3_ctx;
      }
      v92 = *(_QWORD *)(v90 + 34160);
      if ( v92 )
      {
        ipc_log_string(
          v92,
          "ipa %s:%d ep_pair_info consumer_pipe_num %d",
          "ipa3_get_pcie_ep_info",
          1411,
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
        v90 = ipa3_ctx;
      }
      if ( !v90 )
        return 0;
      v93 = *(_QWORD *)(v90 + 34152);
      if ( v93 )
      {
        v94 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
        ipc_log_string(
          v93,
          "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
          "ipa3_get_pcie_ep_info",
          1414,
          *(_DWORD *)(v94 + 4),
          *(_DWORD *)(v94 + 8));
        v90 = ipa3_ctx;
      }
      result = *(_QWORD *)(v90 + 34160);
      if ( result )
      {
        ipc_log_string(
          result,
          "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
          "ipa3_get_pcie_ep_info",
          1414,
          *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4),
          *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8));
        return 0;
      }
      return result;
    }
LABEL_187:
    __break(0x5512u);
    return ipa3_send_pkt_threshold(ep_mapping);
  }
  if ( v2 != 2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_get_ep_info__rs, "ipa3_get_ep_info") )
      printk(&unk_3B77AC, "ipa3_get_ep_info");
    v36 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v37 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v37 )
      {
        ipc_log_string(v37, "ipa %s:%d Undefined ep_type %d\n", "ipa3_get_ep_info", 1507, *a1);
        v36 = ipa3_ctx;
      }
      v38 = *(_QWORD *)(v36 + 34160);
      if ( v38 )
        ipc_log_string(v38, "ipa %s:%d Undefined ep_type %d\n", "ipa3_get_ep_info", 1507, *a1);
    }
    return 4294967282LL;
  }
  v5 = *((unsigned __int8 *)a1 + 8);
  *((_BYTE *)a1 + 9) = 0;
  if ( v5 )
  {
    v6 = 0;
    v7 = (_DWORD *)(a2 + 8);
    do
    {
      *((_QWORD *)v7 - 1) = -1;
      ++v6;
      *v7 = -1;
      v7 += 4;
    }
    while ( v6 < *((unsigned __int8 *)a1 + 8) );
  }
  ep_mapping = ipa_get_ep_mapping(20);
  if ( (_DWORD)ep_mapping != -1 )
  {
    if ( (unsigned int)ep_mapping >= 0x24 )
      goto LABEL_187;
    if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
    {
      *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = ep_mapping;
      ep_mapping = ipa_get_ep_mapping(21);
      if ( (_DWORD)ep_mapping == -1 )
        goto LABEL_99;
      if ( (unsigned int)ep_mapping > 0x23 )
        goto LABEL_187;
      if ( !*(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
      {
LABEL_99:
        *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = -1;
        v53 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v54 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v54 )
          {
            ipc_log_string(
              v54,
              "ipa %s:%d ep_pair_info consumer_pipe_num %d",
              "ipa3_get_usb_ep_info",
              1306,
              *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
            v53 = ipa3_ctx;
          }
          v55 = *(_QWORD *)(v53 + 34160);
          if ( v55 )
          {
            ipc_log_string(
              v55,
              "ipa %s:%d ep_pair_info consumer_pipe_num %d",
              "ipa3_get_usb_ep_info",
              1306,
              *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
            v53 = ipa3_ctx;
          }
          if ( v53 )
          {
            v56 = *(_QWORD *)(v53 + 34152);
            if ( v56 )
            {
              v57 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
              ipc_log_string(
                v56,
                "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                "ipa3_get_usb_ep_info",
                1309,
                *(_DWORD *)(v57 + 4),
                *(_DWORD *)(v57 + 8));
              v53 = ipa3_ctx;
            }
            v58 = *(_QWORD *)(v53 + 34160);
            if ( v58 )
            {
              v59 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
              ipc_log_string(
                v58,
                "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                "ipa3_get_usb_ep_info",
                1309,
                *(_DWORD *)(v59 + 4),
                *(_DWORD *)(v59 + 8));
            }
          }
        }
      }
      else
      {
        *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4) = ep_mapping;
        *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8) = 12;
        v9 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v10 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v10 )
          {
            ipc_log_string(
              v10,
              "ipa %s:%d ep_pair_info consumer_pipe_num %d",
              "ipa3_get_usb_ep_info",
              1298,
              *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
            v9 = ipa3_ctx;
          }
          v11 = *(_QWORD *)(v9 + 34160);
          if ( v11 )
          {
            ipc_log_string(
              v11,
              "ipa %s:%d ep_pair_info consumer_pipe_num %d",
              "ipa3_get_usb_ep_info",
              1298,
              *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
            v9 = ipa3_ctx;
          }
          if ( v9 )
          {
            v12 = *(_QWORD *)(v9 + 34152);
            if ( v12 )
            {
              v13 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
              ipc_log_string(
                v12,
                "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                "ipa3_get_usb_ep_info",
                1301,
                *(_DWORD *)(v13 + 4),
                *(_DWORD *)(v13 + 8));
              v9 = ipa3_ctx;
            }
            v14 = *(_QWORD *)(v9 + 34160);
            if ( v14 )
            {
              v15 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
              ipc_log_string(
                v14,
                "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
                "ipa3_get_usb_ep_info",
                1301,
                *(_DWORD *)(v15 + 4),
                *(_DWORD *)(v15 + 8));
            }
          }
        }
        ++*((_BYTE *)a1 + 9);
      }
    }
  }
  ep_mapping = ipa_get_ep_mapping(18);
  if ( (_DWORD)ep_mapping == -1 )
    return 0;
  if ( (unsigned int)ep_mapping > 0x23 )
    goto LABEL_187;
  if ( !*(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
    return 0;
  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = ep_mapping;
  ep_mapping = ipa_get_ep_mapping(19);
  if ( (_DWORD)ep_mapping == -1 )
    goto LABEL_135;
  if ( (unsigned int)ep_mapping > 0x23 )
    goto LABEL_187;
  if ( *(_DWORD *)(ipa3_ctx + 480LL * (unsigned int)ep_mapping + 168) )
  {
    *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4) = ep_mapping;
    *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8) = 11;
    v60 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v61 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v61 )
      {
        ipc_log_string(
          v61,
          "ipa %s:%d ep_pair_info consumer_pipe_num %d",
          "ipa3_get_usb_ep_info",
          1325,
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
        v60 = ipa3_ctx;
      }
      v62 = *(_QWORD *)(v60 + 34160);
      if ( v62 )
      {
        ipc_log_string(
          v62,
          "ipa %s:%d ep_pair_info consumer_pipe_num %d",
          "ipa3_get_usb_ep_info",
          1325,
          *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
        v60 = ipa3_ctx;
      }
      if ( v60 )
      {
        v63 = *(_QWORD *)(v60 + 34152);
        if ( v63 )
        {
          v64 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
          ipc_log_string(
            v63,
            "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
            "ipa3_get_usb_ep_info",
            1328,
            *(_DWORD *)(v64 + 4),
            *(_DWORD *)(v64 + 8));
          v60 = ipa3_ctx;
        }
        v65 = *(_QWORD *)(v60 + 34160);
        if ( v65 )
          ipc_log_string(
            v65,
            "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
            "ipa3_get_usb_ep_info",
            1328,
            *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4),
            *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8));
      }
    }
LABEL_174:
    ++*((_BYTE *)a1 + 9);
    return 0;
  }
LABEL_135:
  *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)) = -1;
  v71 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v72 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v72 )
  {
    ipc_log_string(
      v72,
      "ipa %s:%d ep_pair_info consumer_pipe_num %d",
      "ipa3_get_usb_ep_info",
      1333,
      *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
    v71 = ipa3_ctx;
  }
  v73 = *(_QWORD *)(v71 + 34160);
  if ( v73 )
  {
    ipc_log_string(
      v73,
      "ipa %s:%d ep_pair_info consumer_pipe_num %d",
      "ipa3_get_usb_ep_info",
      1333,
      *(_DWORD *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9)));
    v71 = ipa3_ctx;
  }
  if ( !v71 )
    return 0;
  v74 = *(_QWORD *)(v71 + 34152);
  if ( v74 )
  {
    v75 = a2 + 16LL * *((unsigned __int8 *)a1 + 9);
    ipc_log_string(
      v74,
      "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
      "ipa3_get_usb_ep_info",
      1336,
      *(_DWORD *)(v75 + 4),
      *(_DWORD *)(v75 + 8));
    v71 = ipa3_ctx;
  }
  result = *(_QWORD *)(v71 + 34160);
  if ( result )
  {
    ipc_log_string(
      result,
      "ipa %s:%d  producer_pipe_num %d ep_id %d\n",
      "ipa3_get_usb_ep_info",
      1336,
      *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 4),
      *(unsigned int *)(a2 + 16LL * *((unsigned __int8 *)a1 + 9) + 8));
    return 0;
  }
  return result;
}

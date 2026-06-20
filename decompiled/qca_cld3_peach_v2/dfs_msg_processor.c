__int64 __fastcall dfs_msg_processor(__int64 a1, unsigned __int16 *a2)
{
  __int64 v4; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x4
  __int64 v14; // x19
  unsigned __int8 *v15; // x8
  unsigned int dfs_beaconing_session_id; // w21
  __int64 v17; // x4
  __int64 v18; // x3
  unsigned int v19; // w20
  const char *v20; // x2
  __int64 v21; // x8

  v4 = _qdf_mem_malloc(0x180u, "dfs_msg_processor", 1294);
  if ( v4 )
  {
    v13 = *a2;
    v14 = v4;
    if ( *a2 > 0x1489u )
    {
      if ( (_DWORD)v13 == 5258 )
      {
        dfs_beaconing_session_id = *((_DWORD *)a2 + 1);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: sapdfs: Received eWNI_SME_DFS_CAC_COMPLETE vdev %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "dfs_msg_processor",
          dfs_beaconing_session_id);
        v17 = 22;
        v18 = 48;
        goto LABEL_18;
      }
      if ( (_DWORD)v13 == 5269 )
      {
        dfs_beaconing_session_id = *((_DWORD *)a2 + 1);
        qdf_trace_msg(
          0x34u,
          8u,
          "%s: sapdfs: Received eCSR_ROAM_RESULT_DFS_CHANSW_UPDATE_REQ vdev %d",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "dfs_msg_processor",
          dfs_beaconing_session_id);
        v18 = 0;
        v17 = 17;
        goto LABEL_18;
      }
    }
    else
    {
      if ( (_DWORD)v13 == 5203 )
      {
        dfs_beaconing_session_id = policy_mgr_get_dfs_beaconing_session_id(*(_QWORD *)(a1 + 21624));
        if ( a1 )
        {
          if ( dfs_beaconing_session_id <= 5 )
          {
            v21 = *(_QWORD *)(a1 + 17296);
            if ( v21 )
            {
              if ( (*(_BYTE *)(v21 + 96LL * dfs_beaconing_session_id + 1) & 1) != 0 )
              {
                qdf_trace_msg(
                  0x34u,
                  8u,
                  "%s: sapdfs: Radar indication event occurred",
                  v5,
                  v6,
                  v7,
                  v8,
                  v9,
                  v10,
                  v11,
                  v12,
                  "dfs_msg_processor");
                v17 = 14;
                v18 = 38;
                goto LABEL_18;
              }
            }
          }
        }
        v20 = "%s: Invalid vdev %d";
        v13 = dfs_beaconing_session_id;
        goto LABEL_20;
      }
      if ( (_DWORD)v13 == 5208 )
      {
        v15 = *((unsigned __int8 **)a2 + 1);
        if ( v15 )
        {
          dfs_beaconing_session_id = *v15;
          v17 = 18;
          v18 = 40;
LABEL_18:
          csr_roam_call_callback(a1, dfs_beaconing_session_id, v14, v18, v17);
          v19 = 0;
LABEL_22:
          _qdf_mem_free(v14);
          return v19;
        }
        qdf_trace_msg(
          0x34u,
          2u,
          "%s: eWNI_SME_DFS_CSAIE_TX_COMPLETE_IND null msg",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "dfs_msg_processor");
LABEL_21:
        v19 = 16;
        goto LABEL_22;
      }
    }
    v20 = "%s: Invalid DFS message: 0x%x";
LABEL_20:
    qdf_trace_msg(0x34u, 2u, v20, v5, v6, v7, v8, v9, v10, v11, v12, "dfs_msg_processor", v13);
    goto LABEL_21;
  }
  return 2;
}

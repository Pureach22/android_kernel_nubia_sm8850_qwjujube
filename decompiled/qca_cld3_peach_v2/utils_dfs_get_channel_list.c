__int64 __fastcall utils_dfs_get_channel_list(__int64 a1, __int64 a2, __int64 a3, unsigned int *a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x22
  unsigned int v17; // w23
  unsigned int v18; // w24
  __int64 result; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned __int64 v28; // x22
  __int64 v29; // x21
  char v30; // w0
  unsigned int v31; // w1
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  unsigned int v40; // [xsp+4h] [xbp-20Ch] BYREF
  _QWORD v41[13]; // [xsp+8h] [xbp-208h] BYREF
  _DWORD s[102]; // [xsp+70h] [xbp-1A0h] BYREF
  __int64 v43; // [xsp+208h] [xbp-8h]

  v43 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v16 = *(_QWORD *)(a1 + 80);
  memset(v41, 0, 102);
  if ( v16 )
  {
    v40 = 102;
    if ( a2 )
    {
      v17 = *(unsigned __int8 *)(a2 + 168);
      v18 = policy_mgr_qdf_opmode_to_pm_con_mode(
              v16,
              *(_DWORD *)(a2 + 16),
              *(_BYTE *)(a2 + 168),
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              v14,
              v15);
    }
    else
    {
      v17 = 255;
      v18 = 1;
    }
    if ( (unsigned int)policy_mgr_mode_specific_connection_count(v16, v18, nullptr) )
      policy_mgr_get_pcl_for_scc_in_same_mode(v16, v18, (__int64)s, (__int64)&v40, (__int64)v41, 0x66u, v17);
    else
      ((void (__fastcall *)(__int64, _QWORD, _DWORD *, unsigned int *, _QWORD *, __int64, _QWORD))policy_mgr_get_pcl)(
        v16,
        v18,
        s,
        &v40,
        v41,
        102,
        v17);
    if ( *a4 >= v40 )
    {
      if ( v40 )
      {
        v28 = 0;
        v29 = a3 + 16;
        do
        {
          if ( v28 == 102 )
          {
            __break(0x5512u);
            __break(1u);
          }
          v30 = wlan_reg_freq_to_chan(a1, s[v28], v20, v21, v22, v23, v24, v25, v26, v27);
          v31 = s[v28];
          *(_BYTE *)(v29 + 2) = v30;
          *(_WORD *)(v29 - 16) = v31;
          if ( (wlan_reg_is_dfs_for_freq(a1, v31, v32, v33, v34, v35, v36, v37, v38, v39) & 1) != 0 )
            *(_WORD *)v29 |= 2u;
          ++v28;
          v29 += 32;
        }
        while ( v28 < v40 );
      }
      else
      {
        LODWORD(v28) = 0;
      }
      *a4 = v28;
      result = qdf_trace_msg(
                 0x27u,
                 4u,
                 "WLAN_DEBUG_DFS_ALWAYS : %s: num channels %d",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "utils_dfs_get_channel_list",
                 (unsigned int)v28);
    }
    else
    {
      result = qdf_trace_msg(
                 0x27u,
                 2u,
                 "WLAN_DEBUG_DFS_ALWAYS : %s: Invalid len src=%d, dst=%d",
                 v20,
                 v21,
                 v22,
                 v23,
                 v24,
                 v25,
                 v26,
                 v27,
                 "utils_dfs_get_channel_list");
      *a4 = 0;
    }
  }
  else
  {
    *a4 = 0;
    result = qdf_trace_msg(
               0x27u,
               2u,
               "WLAN_DEBUG_DFS_ALWAYS : %s: null psoc",
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               v15,
               "utils_dfs_get_channel_list");
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

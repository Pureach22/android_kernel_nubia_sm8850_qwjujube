__int64 __fastcall policy_mgr_update_mac_freq_info(
        __int64 a1,
        int a2,
        unsigned int a3,
        unsigned int *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  const char *v13; // x2
  __int64 v14; // x4
  __int64 result; // x0
  __int64 v19; // x0
  unsigned int *v20; // x1
  __int64 v21; // x2
  int v22; // w9
  int v23; // w8
  __int64 v24; // x0
  unsigned int *v25; // x1
  __int64 v26; // x2

  if ( a3 >= 2 )
  {
    v13 = "%s: mac more than two not supported: %d";
    v14 = a3;
    return qdf_trace_msg(0x4Fu, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "policy_mgr_update_mac_freq_info", v14);
  }
  result = qdf_trace_msg(
             0x4Fu,
             8u,
             "%s: hw_mode_cfg: %d mac: %d band: 0x%x, SBS cutoff freq %d, 2Ghz: %d -> %d 5Ghz: %d -> %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "policy_mgr_update_mac_freq_info",
             (unsigned int)a2,
             a3,
             a4[6],
             *(unsigned int *)(a1 + 1200),
             a4[58],
             a4[59],
             a4[60],
             a4[61]);
  if ( a2 <= 5 )
  {
    if ( a2 > 3 )
    {
      result = policy_mgr_update_freq_info(a1, a4, 1, a3);
      if ( *(_DWORD *)(a1 + 1200) || a4[60] || a4[58] )
        result = policy_mgr_update_freq_info(a1, a4, 2, a3);
      v22 = *(_DWORD *)(a1 + 1236);
      if ( v22 || *(_DWORD *)(a1 + 1244) )
      {
        v23 = *(_DWORD *)(a1 + 1252);
        if ( v23 || *(_DWORD *)(a1 + 1260) )
        {
          if ( v22 && *(_DWORD *)(a1 + 1244) )
            *(_QWORD *)(a1 + 1244) = 0;
          if ( v23 && *(_DWORD *)(a1 + 1260) )
            *(_QWORD *)(a1 + 1260) = 0;
        }
      }
    }
    else
    {
      if ( (unsigned int)(a2 - 2) >= 2 )
      {
        if ( a2 )
        {
          if ( a2 != 1 )
            goto LABEL_50;
          goto LABEL_33;
        }
        if ( a3 )
          return qdf_trace_msg(
                   0x4Fu,
                   8u,
                   "%s: MAC Phy 1 is not supported",
                   a5,
                   a6,
                   a7,
                   a8,
                   a9,
                   a10,
                   a11,
                   a12,
                   "policy_mgr_update_mac_freq_info");
        v24 = a1;
        v25 = a4;
        v26 = 0;
        return policy_mgr_update_freq_info(v24, v25, v26, 0);
      }
      result = policy_mgr_update_freq_info(a1, a4, 2, a3);
    }
    if ( (*(_DWORD *)(a1 + 1268) || *(_DWORD *)(a1 + 1276)) && (*(_DWORD *)(a1 + 1284) || *(_DWORD *)(a1 + 1292)) )
      return policy_mgr_update_sbs_freq_info(a1);
    return result;
  }
  if ( a2 > 7 )
  {
    if ( a2 == 8 )
    {
      v19 = a1;
      v20 = a4;
      v21 = 5;
      return policy_mgr_update_freq_info(v19, v20, v21, a3);
    }
    if ( a2 != 9 )
    {
      if ( a2 != 10 )
      {
LABEL_50:
        v13 = "%s: HW mode not defined %d";
        v14 = (unsigned int)a2;
        return qdf_trace_msg(0x4Fu, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "policy_mgr_update_mac_freq_info", v14);
      }
      v19 = a1;
      v20 = a4;
      v21 = 7;
      return policy_mgr_update_freq_info(v19, v20, v21, a3);
    }
    if ( a3 )
      return qdf_trace_msg(
               0x4Fu,
               8u,
               "%s: MAC Phy 1 is not supported",
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               a12,
               "policy_mgr_update_mac_freq_info");
    v24 = a1;
    v25 = a4;
    v26 = 6;
    return policy_mgr_update_freq_info(v24, v25, v26, 0);
  }
  if ( a2 != 6 )
  {
    if ( a3 )
      return policy_mgr_update_freq_info(a1, a4, 0, 1);
    return result;
  }
LABEL_33:
  if ( !*(_DWORD *)(a1 + 1236) && !*(_DWORD *)(a1 + 1244) || !*(_DWORD *)(a1 + 1252) && !*(_DWORD *)(a1 + 1260) )
  {
    v19 = a1;
    v20 = a4;
    v21 = 1;
    return policy_mgr_update_freq_info(v19, v20, v21, a3);
  }
  return result;
}

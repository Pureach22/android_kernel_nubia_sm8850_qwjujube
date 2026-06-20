__int64 __fastcall policy_mgr_update_with_safe_channel_list(
        __int64 a1,
        void *a2,
        unsigned int *a3,
        void *a4,
        unsigned int a5)
{
  __int64 result; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w26
  __int64 v20; // x24
  __int64 v21; // x27
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned __int64 i; // x28
  __int64 v31; // x9
  int v32; // w8
  const char *v33; // x2
  int v34; // [xsp+4h] [xbp-21Ch]
  int channel; // [xsp+8h] [xbp-218h]
  _BYTE v36[4]; // [xsp+Ch] [xbp-214h] BYREF
  _QWORD v37[13]; // [xsp+10h] [xbp-210h] BYREF
  _DWORD s[102]; // [xsp+78h] [xbp-1A8h] BYREF
  __int64 v39; // [xsp+210h] [xbp-10h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  memset(v37, 0, 102);
  v36[0] = 0;
  result = policy_mgr_get_context(a1);
  if ( !result )
  {
    v33 = "%s: Invalid Context";
LABEL_35:
    result = qdf_trace_msg(
               0x4Fu,
               2u,
               v33,
               v11,
               v12,
               v13,
               v14,
               v15,
               v16,
               v17,
               v18,
               "policy_mgr_update_with_safe_channel_list");
    goto LABEL_36;
  }
  if ( !a3 )
  {
    v33 = "%s: invalid number of channel length";
    goto LABEL_35;
  }
  v19 = *a3;
  v20 = result;
  if ( *a3 >= 0x66 )
    v21 = 102;
  else
    v21 = v19;
  if ( *(_WORD *)(result + 2084) )
  {
    qdf_mem_copy(s, a2, (unsigned int)(4 * v21));
    qdf_mem_set(a2, (unsigned int)(4 * v21), 0);
    qdf_mem_copy(v37, a4, 0x66u);
    qdf_mem_set(a4, a5, 0);
    policy_mgr_get_sta_sap_scc_lte_coex_chnl(a1, v36);
    channel = policy_mgr_mode_specific_get_channel(*(_QWORD *)v20, 5);
    result = wlan_nan_is_disc_active(a1);
    v34 = 0;
    if ( (result & 1) != 0 )
    {
      result = wlan_nan_get_5ghz_social_ch_freq(*(_QWORD *)(v20 + 8));
      v34 = result;
    }
    if ( v19 )
    {
      v19 = 0;
      for ( i = 0; i != v21; ++i )
      {
        if ( *(_WORD *)(v20 + 2084) )
        {
          if ( (i & 0x3FFFFFFFFFFFFFFFLL) == 0x66 )
            goto LABEL_38;
          v31 = 0;
          while ( 1 )
          {
            if ( v31 == 408 )
              goto LABEL_37;
            if ( s[i] == *(_DWORD *)(v20 + v31 + 1676) )
              break;
            v31 += 4;
            if ( 4LL * *(unsigned __int16 *)(v20 + 2084) == v31 )
              goto LABEL_19;
          }
          result = qdf_trace_msg(
                     0x4Fu,
                     8u,
                     "%s: CH %d is not safe",
                     v22,
                     v23,
                     v24,
                     v25,
                     v26,
                     v27,
                     v28,
                     v29,
                     "policy_mgr_update_with_safe_channel_list");
          if ( v36[0] && (result = policy_mgr_is_sta_sap_scc(a1, s[i], 0), (result & 1) != 0) )
          {
            result = qdf_trace_msg(
                       0x4Fu,
                       8u,
                       "%s: CH %d unsafe ignored when STA present on it",
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       "policy_mgr_update_with_safe_channel_list",
                       (unsigned int)s[i]);
          }
          else
          {
            v32 = s[i];
            if ( channel != v32 && v34 != v32 )
              continue;
            result = policy_mgr_is_force_scc(*(_QWORD *)v20);
            if ( (result & 1) == 0 )
              continue;
            result = policy_mgr_get_nan_sap_scc_on_lte_coex_chnl(*(_QWORD *)v20);
            if ( (result & 1) == 0 )
              continue;
          }
        }
        else
        {
LABEL_19:
          if ( i > 0x65 )
          {
LABEL_37:
            __break(0x5512u);
LABEL_38:
            __break(1u);
          }
        }
        if ( (i & 0x3FFFFFFFFFFFFFFFLL) == 0x66 )
          goto LABEL_38;
        *((_DWORD *)a2 + v19) = s[i];
        if ( v19 < a5 )
        {
          if ( i == 102 )
            goto LABEL_38;
          *((_BYTE *)a4 + v19) = *((_BYTE *)v37 + i);
        }
        ++v19;
      }
    }
    *a3 = v19;
  }
LABEL_36:
  _ReadStatusReg(SP_EL0);
  return result;
}

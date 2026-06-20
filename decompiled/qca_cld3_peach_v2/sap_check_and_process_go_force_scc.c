__int64 __fastcall sap_check_and_process_go_force_scc(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *context; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x8
  _QWORD *v20; // x20
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 result; // x0
  unsigned int *v30; // x20
  __int64 v31; // x21
  const char *v32; // x3
  int v33; // [xsp+Ch] [xbp-14h] BYREF
  int v34; // [xsp+10h] [xbp-10h] BYREF
  int v35; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v36; // [xsp+18h] [xbp-8h]

  v36 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v35 = 0;
  v33 = 7;
  v34 = 0;
  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a2, a3, a4, a5, a6, a7, a8, a9);
  if ( !context )
  {
    v32 = "sap_check_and_process_go_force_scc";
    goto LABEL_38;
  }
  v19 = *(_QWORD *)(a1 + 16);
  v20 = context;
  if ( *(_DWORD *)(v19 + 16) == 3
    && *(_WORD *)(v19 + 224) == 2
    && (unsigned int)policy_mgr_mode_specific_connection_count(context[2703], 3, nullptr) >= 2 )
  {
    result = (__int64)_cds_get_context(53, (__int64)"sap_get_mac_context", v21, v22, v23, v24, v25, v26, v27, v28);
    if ( result )
    {
      v30 = *(unsigned int **)(result + 14888);
      if ( v30
        && *(_DWORD *)(result + 14896) == 3
        && *((_BYTE *)v30 + 1765) == 1
        && *(unsigned __int8 *)(a1 + 12) != *((unsigned __int8 *)v30 + 12)
        || (v30 = *(unsigned int **)(result + 14904)) != nullptr
        && *(_DWORD *)(result + 14912) == 3
        && *((_BYTE *)v30 + 1765) == 1
        && *(unsigned __int8 *)(a1 + 12) != *((unsigned __int8 *)v30 + 12)
        || (v30 = *(unsigned int **)(result + 14920)) != nullptr
        && *(_DWORD *)(result + 14928) == 3
        && *((_BYTE *)v30 + 1765) == 1
        && *(unsigned __int8 *)(a1 + 12) != *((unsigned __int8 *)v30 + 12)
        || (v30 = *(unsigned int **)(result + 14936)) != nullptr
        && *(_DWORD *)(result + 14944) == 3
        && *((_BYTE *)v30 + 1765) == 1
        && *(unsigned __int8 *)(a1 + 12) != *((unsigned __int8 *)v30 + 12)
        || (v30 = *(unsigned int **)(result + 14952)) != nullptr
        && *(_DWORD *)(result + 14960) == 3
        && *((_BYTE *)v30 + 1765) == 1
        && *(unsigned __int8 *)(a1 + 12) != *((unsigned __int8 *)v30 + 12)
        || (v30 = *(unsigned int **)(result + 14968)) != nullptr
        && *(_DWORD *)(result + 14976) == 3
        && *((_BYTE *)v30 + 1765) == 1
        && *(unsigned __int8 *)(a1 + 12) != *((unsigned __int8 *)v30 + 12) )
      {
        v31 = result;
        qdf_trace_msg(
          0x39u,
          8u,
          "%s: update chan_freq %d of sessionId %d with chan_freq %d",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "sap_check_and_process_forcescc_for_go_plus_go",
          *v30);
        result = policy_mgr_process_forcescc_for_go(
                   *(_QWORD *)(v31 + 21624),
                   *((_BYTE *)v30 + 12),
                   *(_DWORD *)a1,
                   *(_DWORD *)(a1 + 1500),
                   3);
        *((_BYTE *)v30 + 1765) = 0;
      }
      goto LABEL_39;
    }
    v32 = "sap_check_and_process_forcescc_for_go_plus_go";
LABEL_38:
    result = qdf_trace_msg(0x39u, 2u, "%s: Invalid MAC context", v11, v12, v13, v14, v15, v16, v17, v18, v32);
    goto LABEL_39;
  }
  result = policy_mgr_fetch_existing_con_info(v20[2703], *(_BYTE *)(a1 + 12), *(_DWORD *)a1, &v33, &v35, &v34);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 16) + 16LL) == 3 )
  {
    result = policy_mgr_go_scc_enforced(v20[2703]);
    if ( (result & 1) != 0 )
    {
      result = policy_mgr_is_go_scc_strict(v20[2703]);
      if ( (result & 1) == 0 && *(_WORD *)(*(_QWORD *)(a1 + 16) + 224LL) == 2 && (v33 & 0xFFFFFFFD) == 0 )
        result = policy_mgr_process_forcescc_for_go(v20[2703], *(_BYTE *)(a1 + 12), v35, v34, v33);
    }
  }
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall wlan_ipa_wdi_opt_dpath_notify_flt_rsvd(char a1)
{
  _QWORD *v2; // x21
  __int64 result; // x0
  __int64 v4; // x20
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x0
  __int64 v14; // x8
  void (*v15)(void); // x8
  __int64 v16; // x0

  v2 = (_QWORD *)gp_ipa;
  result = _qdf_mem_malloc(0x20u, "wlan_ipa_wdi_opt_dpath_notify_flt_rsvd", 6858);
  if ( result )
  {
    v4 = result;
    if ( (a1 & 1) != 0 && (ipa_get_shared_smmu_enable() & 1) == 0 )
    {
      *(_WORD *)(v4 + 2) = 11;
      v13 = v2[182];
      v2[321] = v4;
      if ( v13 && *(_QWORD *)v13 && (v14 = *(_QWORD *)(*(_QWORD *)v13 + 152LL)) != 0 )
      {
        v15 = *(void (**)(void))(v14 + 208);
        if ( v15 )
        {
          if ( *((_DWORD *)v15 - 1) != -1710392634 )
            __break(0x8228u);
          v15();
        }
      }
      else
      {
        qdf_trace_msg(0x45u, 1u, "%s invalid instance", v5, v6, v7, v8, v9, v10, v11, v12, "cdp_ipa_set_smmu_mapped");
      }
      queue_work_on(32, system_wq, v2 + 315);
    }
    else
    {
      _qdf_mem_free(v4);
    }
    v16 = _qdf_mem_malloc(0x20u, "wlan_ipa_wdi_opt_dpath_notify_flt_rsvd", 6872);
    if ( v16 )
    {
      *(_WORD *)(v16 + 2) = 9;
      *(_BYTE *)(v16 + 1) = a1 & 1;
      v2[299] = v16;
      return queue_work_on(32, system_wq, v2 + 293);
    }
    else
    {
      return _qdf_mem_free(v4);
    }
  }
  return result;
}

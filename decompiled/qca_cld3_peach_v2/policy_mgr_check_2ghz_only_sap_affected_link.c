__int64 __fastcall policy_mgr_check_2ghz_only_sap_affected_link(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int8 a4,
        unsigned int *a5)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x0
  unsigned int *v19; // x8
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w23
  __int64 context; // x0
  _DWORD *v30; // x8
  __int64 v31; // x8
  unsigned int v32; // t1
  __int64 v33; // x20
  bool is_24ghz_ch_freq; // w0
  char v35; // w8
  const char *v36; // x3
  unsigned int v38; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v39; // [xsp+8h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !policy_mgr_get_context(a1) )
  {
    v36 = "policy_mgr_check_2ghz_only_sap_affected_link";
LABEL_16:
    qdf_trace_msg(0x4Fu, 2u, "%s: Invalid Context", v10, v11, v12, v13, v14, v15, v16, v17, v36);
LABEL_17:
    v35 = 0;
    goto LABEL_18;
  }
  if ( !wlan_reg_is_24ghz_ch_freq(a3) )
    goto LABEL_17;
  v18 = ((__int64 (__fastcall *)(__int64, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(a1, a2, 24);
  if ( !v18 )
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: vdev is null %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "policy_mgr_check_2ghz_only_sap_affected_link",
      (unsigned __int8)a2);
    v35 = 0;
    goto LABEL_18;
  }
  v28 = *(_DWORD *)(v18 + 16);
  wlan_objmgr_vdev_release_ref(v18, 0x18u, v19, v20, v21, v22, v23, v24, v25, v26, v27);
  if ( v28 != 1 )
    goto LABEL_17;
  v38 = 4;
  context = policy_mgr_get_context(a1);
  if ( !context )
  {
    v36 = "policy_mgr_is_acs_2ghz_only_sap";
    goto LABEL_16;
  }
  v30 = *(_DWORD **)(context + 368);
  if ( !v30 )
    goto LABEL_17;
  if ( *(v30 - 1) != -333933844 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD, unsigned int *))v30)(a1, a2, &v38);
  if ( v38 > 1 )
    goto LABEL_17;
  if ( a4 )
  {
    v31 = a4 - 1LL;
    do
    {
      v32 = *a5++;
      v33 = v31;
      is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(v32);
      if ( is_24ghz_ch_freq )
        break;
      v31 = v33 - 1;
    }
    while ( v33 );
    v35 = !is_24ghz_ch_freq;
  }
  else
  {
    v35 = 1;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v35 & 1;
}

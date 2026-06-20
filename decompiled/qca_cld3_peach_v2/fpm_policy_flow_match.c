__int64 __fastcall fpm_policy_flow_match(
        __int64 meta_data_by_id,
        __int64 a2,
        int *a3,
        _DWORD *a4,
        _DWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 *v13; // x25
  unsigned __int64 StatusReg; // x8
  __int64 *v19; // x23
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  const char *v28; // x2
  int v30; // w8
  unsigned int v31; // w20

  if ( !meta_data_by_id )
  {
    v28 = "%s: dp_intf is null";
LABEL_11:
    qdf_trace_msg(0x45u, 2u, v28, a6, a7, a8, a9, a10, a11, a12, a13, "fpm_policy_flow_match");
    return 3;
  }
  v13 = *(__int64 **)(meta_data_by_id + 3712);
  if ( !v13 )
  {
    v28 = "%s: fpm_ctx is null";
    goto LABEL_11;
  }
  if ( !a4 )
  {
    v28 = "%s: flow is null";
    goto LABEL_11;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  v19 = v13 + 9;
  *(_DWORD *)(StatusReg + 16) += 512;
  do
  {
    v19 = (__int64 *)*v19;
    if ( !v19 )
    {
      v19 = v13 + 8;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          break;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
      v19 = v13 + 7;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          break;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
      v19 = v13 + 6;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          break;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
      v19 = v13 + 5;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          break;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
      v19 = v13 + 4;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          break;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
      v19 = v13 + 3;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          break;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
      v19 = v13 + 2;
      while ( 1 )
      {
        v19 = (__int64 *)*v19;
        if ( !v19 )
          goto LABEL_43;
        meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
        if ( (meta_data_by_id & 1) != 0 )
          goto LABEL_39;
      }
    }
    meta_data_by_id = fpm_flow_regex_match((_DWORD *)v19 + 12, a4);
  }
  while ( (meta_data_by_id & 1) == 0 );
LABEL_39:
  meta_data_by_id = qdf_trace_msg(
                      0x45u,
                      5u,
                      "%s: flow matched policy_id:%llu",
                      v20,
                      v21,
                      v22,
                      v23,
                      v24,
                      v25,
                      v26,
                      v27,
                      "fpm_policy_flow_match",
                      v19[5]);
  *a5 = v19[5];
  v30 = *((_DWORD *)v19 + 24);
  if ( (v30 & 2) == 0 )
  {
    if ( (v30 & 1) != 0 )
    {
      v31 = 0;
      *a3 = *((unsigned __int8 *)v19 + 100) | 0xC000000;
      goto LABEL_45;
    }
    goto LABEL_43;
  }
  meta_data_by_id = dp_svc_get_meta_data_by_id(*((unsigned __int8 *)v19 + 101), a2, a3);
  if ( (_DWORD)meta_data_by_id )
  {
LABEL_43:
    v31 = 1;
    goto LABEL_45;
  }
  v31 = 0;
LABEL_45:
  local_bh_enable_3(meta_data_by_id);
  return v31;
}

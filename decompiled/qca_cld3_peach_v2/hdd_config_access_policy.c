__int64 __fastcall hdd_config_access_policy(unsigned __int8 *a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 v5; // x22
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  unsigned int v14; // w19
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int updated; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 result; // x0
  const char *v33; // x4
  _BYTE s[257]; // [xsp+7h] [xbp-109h] BYREF
  __int64 v35; // [xsp+108h] [xbp-8h]

  v35 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 176);
  v3 = *(_QWORD *)(a2 + 184);
  if ( *(_OWORD *)(a2 + 176) == 0 )
  {
    result = 0;
    goto LABEL_15;
  }
  v5 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  memset(s, 0, sizeof(s));
  if ( !v3 || !v2 )
  {
    if ( v2 )
      v33 = "ACCESS_POLICY_IE_LIST";
    else
      v33 = "ACCESS_POLICY";
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Missing attribute for %s",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_config_access_policy",
      v33);
    goto LABEL_14;
  }
  v14 = *(_DWORD *)(v2 + 4);
  if ( v14 >= 2 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Invalid value. access_policy %u",
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      "hdd_config_access_policy",
      v14);
LABEL_14:
    result = 4294967274LL;
    goto LABEL_15;
  }
  nla_memcpy(s, v3, 257);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: calling sme_update_access_policy_vendor_ie",
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    "hdd_config_access_policy");
  updated = sme_update_access_policy_vendor_ie(*(_QWORD *)(v5 + 16), a1[8], s, v14);
  if ( updated )
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Failed to set vendor ie and access policy, %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "hdd_config_access_policy",
      updated);
  result = qdf_status_to_os_return(updated);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}

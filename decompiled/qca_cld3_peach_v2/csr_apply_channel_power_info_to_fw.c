__int64 __fastcall csr_apply_channel_power_info_to_fw(__int64 a1, unsigned __int8 *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w8
  __int64 v13; // x20
  __int64 v14; // x8
  const char *v15; // x2
  const char *v16; // x3
  int *v17; // x9
  _DWORD *v18; // x10
  __int64 v19; // x11
  int v20; // w12
  int v21; // w13
  __int64 v22; // x9
  __int64 v23; // x8
  __int64 v24; // x10
  unsigned __int8 *v25; // x9
  _DWORD *v26; // x10
  int v27; // t1
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  __int64 v44; // x9
  int v45; // w11
  __int64 v46; // x10
  double v47; // d0
  double v48; // d1
  double v49; // d2
  double v50; // d3
  double v51; // d4
  double v52; // d5
  double v53; // d6
  double v54; // d7
  __int64 result; // x0
  double v56; // d0
  double v57; // d1
  double v58; // d2
  double v59; // d3
  double v60; // d4
  double v61; // d5
  double v62; // d6
  double v63; // d7
  _QWORD v64[3]; // [xsp+8h] [xbp-1B8h] BYREF
  _BYTE s[404]; // [xsp+24h] [xbp-19Ch] BYREF
  __int64 v66; // [xsp+1B8h] [xbp-8h]

  v66 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v12 = *a2;
  memset(v64, 0, sizeof(v64));
  if ( !v12 )
  {
    v15 = "%s: 11D channel list is empty";
    v16 = "csr_apply_channel_power_info_to_fw";
LABEL_18:
    qdf_trace_msg(0x34u, 2u, v15, v4, v5, v6, v7, v8, v9, v10, v11, v16);
    goto LABEL_19;
  }
  if ( v12 >= 0x64 )
    v13 = 100;
  else
    v13 = v12;
  if ( v12 == 1 )
  {
    v14 = 0;
  }
  else
  {
    v14 = v13 & 0x7E;
    v17 = (int *)(a2 + 8);
    v18 = &s[8];
    v19 = v14;
    do
    {
      v20 = *(v17 - 1);
      v21 = *v17;
      v19 -= 2;
      v17 += 2;
      *(v18 - 1) = v20;
      *v18 = v21;
      v18 += 2;
    }
    while ( v19 );
    if ( v14 == v13 )
      goto LABEL_13;
  }
  v22 = 4 * v14;
  v23 = v13 - v14;
  v24 = v22 + 4;
  v25 = &a2[v22 + 4];
  v26 = &s[v24];
  do
  {
    v27 = *(_DWORD *)v25;
    v25 += 4;
    --v23;
    *v26++ = v27;
  }
  while ( v23 );
LABEL_13:
  s[0] = v13;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Updating Cfg with power settings",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "csr_apply_power2_current");
  csr_save_tx_power_to_cfg(a1, a1 + 17008, 1);
  csr_save_tx_power_to_cfg(a1, a1 + 17096, 2);
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: dump valid channel list(NumChannels(%d))",
    v28,
    v29,
    v30,
    v31,
    v32,
    v33,
    v34,
    v35,
    "csr_set_cfg_valid_channel_list",
    (unsigned int)v13);
  ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(52, 8, &s[4], (unsigned int)v13);
  v44 = 0;
  do
  {
    if ( v44 == 400 )
      __break(0x5512u);
    v45 = *(_DWORD *)&s[v44 + 4];
    v46 = *(_QWORD *)(a1 + 8) + v44;
    v44 += 4;
    *(_DWORD *)(v46 + 5992) = v45;
  }
  while ( 4LL * (unsigned int)v13 != v44 );
  *(_DWORD *)(*(_QWORD *)(a1 + 8) + 6392LL) = v13;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: Scan offload is enabled, update default chan list",
    v36,
    v37,
    v38,
    v39,
    v40,
    v41,
    v42,
    v43,
    "csr_set_cfg_valid_channel_list");
  *(_BYTE *)(a1 + 17185) = 0;
  if ( (unsigned int)csr_update_channel_list(a1, v47, v48, v49, v50, v51, v52, v53, v54) )
  {
    v15 = "%s: failed to update the supported channel list";
    v16 = "csr_set_cfg_valid_channel_list";
    goto LABEL_18;
  }
LABEL_19:
  result = sme_update_add_ie(a1, (__int64)v64, 5u);
  if ( (_DWORD)result )
    result = qdf_trace_msg(
               0x34u,
               2u,
               "%s: Could not pass on edca update all profile",
               v56,
               v57,
               v58,
               v59,
               v60,
               v61,
               v62,
               v63,
               "csr_apply_channel_power_info_to_fw");
  _ReadStatusReg(SP_EL0);
  return result;
}

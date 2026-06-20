_QWORD *__fastcall crypto_plumb_peer_keys(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *result; // x0
  __int64 v15; // x1
  __int64 v16; // x8
  void (__fastcall *v17)(__int64, __int64, __int64, __int64); // x8
  __int64 v18; // x9
  __int64 v19; // x3
  _QWORD *v20; // x22
  const char *v21; // x2
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x1
  __int64 v31; // x8
  void (__fastcall *v32)(__int64, __int64, __int64, __int64); // x8
  __int64 v33; // x9
  __int64 v34; // x3
  _QWORD *v35; // x22
  __int64 v36; // x1
  __int64 v37; // x8
  void (__fastcall *v38)(__int64, __int64, __int64, __int64); // x8
  __int64 v39; // x9
  __int64 v40; // x3
  _QWORD *v41; // x22
  __int64 v42; // x1
  __int64 v43; // x8
  __int64 (__fastcall *v44)(__int64, __int64, __int64, __int64); // x8
  __int64 v45; // x9
  __int64 v46; // x3

  if ( !a1 || !a2 || !a3 )
  {
    v21 = "%s: Peer or vdev or psoc objects are null!";
    return (_QWORD *)qdf_trace_msg(0x1Cu, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, "crypto_plumb_peer_keys");
  }
  result = (_QWORD *)wlan_objmgr_peer_get_comp_private_obj(a2, 14);
  if ( !result )
  {
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: crypto_priv NULL",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "wlan_crypto_peer_get_comp_params");
    return (_QWORD *)qdf_trace_msg(
                       0x1Cu,
                       2u,
                       "%s: crypto_priv NULL",
                       v22,
                       v23,
                       v24,
                       v25,
                       v26,
                       v27,
                       v28,
                       v29,
                       "crypto_plumb_peer_keys");
  }
  v15 = result[36];
  if ( v15 && *(_BYTE *)(v15 + 1) == 1 )
  {
    v16 = *(_QWORD *)(a3 + 2128);
    if ( !v16 )
      goto LABEL_44;
    v17 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v16 + 712);
    if ( v17 )
    {
      v18 = *(_QWORD *)(v15 + 32);
      if ( v18 )
      {
        v19 = *(unsigned int *)(v18 + 8);
        v20 = result;
      }
      else
      {
        v20 = result;
        v19 = 17;
      }
      if ( *((_DWORD *)v17 - 1) != -871156935 )
        __break(0x8228u);
      v17(a1, v15, a2 + 48, v19);
      result = v20;
    }
  }
  v30 = result[37];
  if ( v30 && *(_BYTE *)(v30 + 1) == 1 )
  {
    v31 = *(_QWORD *)(a3 + 2128);
    if ( !v31 )
      goto LABEL_44;
    v32 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v31 + 712);
    if ( v32 )
    {
      v33 = *(_QWORD *)(v30 + 32);
      if ( v33 )
      {
        v34 = *(unsigned int *)(v33 + 8);
        v35 = result;
      }
      else
      {
        v35 = result;
        v34 = 17;
      }
      if ( *((_DWORD *)v32 - 1) != -871156935 )
        __break(0x8228u);
      v32(a1, v30, a2 + 48, v34);
      result = v35;
    }
  }
  v36 = result[38];
  if ( !v36 || *(_BYTE *)(v36 + 1) != 1 )
    goto LABEL_38;
  v37 = *(_QWORD *)(a3 + 2128);
  if ( !v37 )
  {
LABEL_44:
    v21 = "%s: tx_ops is NULL";
    return (_QWORD *)qdf_trace_msg(0x1Cu, 2u, v21, a4, a5, a6, a7, a8, a9, a10, a11, "crypto_plumb_peer_keys");
  }
  v38 = *(void (__fastcall **)(__int64, __int64, __int64, __int64))(v37 + 712);
  if ( v38 )
  {
    v39 = *(_QWORD *)(v36 + 32);
    if ( v39 )
    {
      v40 = *(unsigned int *)(v39 + 8);
      v41 = result;
    }
    else
    {
      v41 = result;
      v40 = 17;
    }
    if ( *((_DWORD *)v38 - 1) != -871156935 )
      __break(0x8228u);
    v38(a1, v36, a2 + 48, v40);
    result = v41;
  }
LABEL_38:
  v42 = result[39];
  if ( !v42 || *(_BYTE *)(v42 + 1) != 1 )
    return result;
  v43 = *(_QWORD *)(a3 + 2128);
  if ( !v43 )
    goto LABEL_44;
  v44 = *(__int64 (__fastcall **)(__int64, __int64, __int64, __int64))(v43 + 712);
  if ( v44 )
  {
    v45 = *(_QWORD *)(v42 + 32);
    if ( v45 )
      v46 = *(unsigned int *)(v45 + 8);
    else
      v46 = 17;
    if ( *((_DWORD *)v44 - 1) != -871156935 )
      __break(0x8228u);
    return (_QWORD *)v44(a1, v42, a2 + 48, v46);
  }
  return result;
}

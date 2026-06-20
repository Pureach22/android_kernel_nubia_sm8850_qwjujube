__int64 __fastcall wifi_update_channel_bw_info(__int64 a1, __int64 a2, unsigned __int16 a3, __int64 a4)
{
  __int64 psoc; // x0
  __int64 psoc_priv_obj; // x0
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  __int64 v18; // x23
  __int64 tx_ops; // x0
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  unsigned int (__fastcall *v28)(__int64, __int64 *); // x8
  __int64 result; // x0
  _DWORD *v30; // x8
  __int64 v31; // x1
  const char *v32; // x2
  const char *v33; // x2
  unsigned int v34; // w0
  int v35; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v36; // [xsp+8h] [xbp-18h] BYREF
  __int64 v37; // [xsp+10h] [xbp-10h]
  __int64 v38; // [xsp+18h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  psoc = wifi_pos_get_psoc(a1);
  psoc_priv_obj = wifi_pos_get_psoc_priv_obj(psoc);
  v35 = 0;
  if ( !psoc_priv_obj )
  {
    v32 = "%s: wifi_pos priv obj is null";
LABEL_16:
    result = qdf_trace_msg(0x25u, 2u, v32, v10, v11, v12, v13, v14, v15, v16, v17, "wifi_update_channel_bw_info");
    goto LABEL_17;
  }
  v18 = psoc_priv_obj;
  tx_ops = wifi_pos_get_tx_ops(a1, v10, v11, v12, v13, v14, v15, v16, v17);
  if ( !tx_ops )
  {
    v33 = "%s: tx ops null";
    v34 = 56;
LABEL_14:
    qdf_trace_msg(v34, 2u, v33, v20, v21, v22, v23, v24, v25, v26, v27, "wifi_pos_get_vht_ch_width");
LABEL_15:
    v32 = "%s: can not get vht ch width";
    goto LABEL_16;
  }
  v28 = *(unsigned int (__fastcall **)(__int64, __int64 *))(tx_ops + 40);
  if ( !v28 )
  {
    v33 = "%s: wifi pos get vht ch width is null";
    v34 = 37;
    goto LABEL_14;
  }
  if ( *((_DWORD *)v28 - 1) != 325577882 )
    __break(0x8228u);
  if ( v28(a1, &v36) )
    goto LABEL_15;
  result = wlan_reg_set_channel_params_for_pwrmode(a2, a3, 0, (__int64)&v36, 0, v10, v11, v12, v13, v14, v15, v16, v17);
  *(_DWORD *)(a4 + 12) = v37;
  v30 = *(_DWORD **)(v18 + 144);
  if ( v30 )
  {
    v31 = (unsigned int)v36;
    if ( *(v30 - 1) != -1038784190 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD, __int64, int *))v30)(a3, v31, &v35);
    *(_DWORD *)(a4 + 16) = v35;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}

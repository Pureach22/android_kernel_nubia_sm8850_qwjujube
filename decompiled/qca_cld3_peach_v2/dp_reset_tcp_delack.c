__int64 __fastcall dp_reset_tcp_delack(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x1
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  int v11; // w8
  __int64 (__fastcall *v12)(__int64, __int64 *, __int64); // x8
  __int64 v13; // x0
  const char *v14; // x2
  const char *v15; // x3
  __int64 v16; // x19
  __int64 radio_index; // x0
  __int64 (__fastcall *v18)(__int64, __int64); // x8
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  v19 = 0x100000001LL;
  if ( !result )
  {
    v14 = "%s: Unable to get DP context";
    v15 = "dp_reset_tcp_delack";
LABEL_8:
    result = qdf_trace_msg(0x45u, 2u, v14, v3, v4, v5, v6, v7, v8, v9, v10, v15, v19, v20);
    goto LABEL_9;
  }
  if ( *(_BYTE *)(result + 848) != 1 )
    goto LABEL_9;
  v11 = *(unsigned __int8 *)(result + 124);
  *(_DWORD *)(result + 1152) = 0;
  if ( v11 == 1 )
  {
    v12 = *(__int64 (__fastcall **)(__int64, __int64 *, __int64))(result + 552);
    v13 = *(_QWORD *)result;
    if ( *((_DWORD *)v12 - 1) != 1848957961 )
      __break(0x8228u);
    result = v12(v13, &v19, 1);
    goto LABEL_9;
  }
  v16 = result;
  radio_index = cds_get_radio_index(result, v2);
  if ( (_DWORD)radio_index == -22 )
  {
    v14 = "%s: Invalid radio index";
    v15 = "wlan_dp_update_tcp_rx_param";
    goto LABEL_8;
  }
  v18 = *(__int64 (__fastcall **)(__int64, __int64))(v16 + 544);
  if ( *((_DWORD *)v18 - 1) != -1162056974 )
    __break(0x8228u);
  result = v18(radio_index, 265);
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall ucfg_dp_set_cmn_dp_handle(__int64 a1, __int64 a2)
{
  __int64 comp_private_obj; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  __int64 (__fastcall *v13)(__int64, __int64, __int64 *); // x8
  __int64 v14; // x20
  __int64 result; // x0
  const char *v16; // x2
  __int64 v17; // [xsp+0h] [xbp-20h] BYREF
  __int64 v18; // [xsp+8h] [xbp-18h]
  __int64 v19; // [xsp+10h] [xbp-10h]
  __int64 v20; // [xsp+18h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( !comp_private_obj )
  {
    v16 = "%s: Unable to get DP context";
    goto LABEL_13;
  }
  *(_QWORD *)(comp_private_obj + 240) = a2;
  v17 = 0;
  if ( !a2 || !*(_QWORD *)a2 )
  {
    qdf_trace_msg(
      0x89u,
      8u,
      "%s: Invalid Instance:",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "cdp_txrx_get_psoc_param",
      v17,
      v18,
      v19,
      v20);
LABEL_11:
    v16 = "%s: Unable to fetch hal soc handle";
LABEL_13:
    result = qdf_trace_msg(0x45u, 2u, v16, v4, v5, v6, v7, v8, v9, v10, v11, "ucfg_dp_set_cmn_dp_handle", v17);
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(*(_QWORD *)a2 + 8LL);
  if ( !v12 )
    goto LABEL_11;
  v13 = *(__int64 (__fastcall **)(__int64, __int64, __int64 *))(v12 + 192);
  if ( !v13 )
    goto LABEL_11;
  v14 = comp_private_obj;
  if ( *((_DWORD *)v13 - 1) != 875927212 )
    __break(0x8228u);
  result = v13(a2, 11, &v17);
  if ( (_DWORD)result )
    goto LABEL_11;
  *(_QWORD *)(v14 + 256) = v17;
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}

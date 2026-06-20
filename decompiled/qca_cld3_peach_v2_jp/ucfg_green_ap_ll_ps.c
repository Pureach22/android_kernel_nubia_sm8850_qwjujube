__int64 __fastcall ucfg_green_ap_ll_ps(
        __int64 a1,
        __int64 a2,
        int a3,
        __int16 a4,
        _QWORD *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 comp_private_obj; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x24
  __int64 green_ap_tx_ops; // x0
  __int64 v28; // x23
  __int64 (__fastcall *v29)(__int64, __int64 *); // x8
  __int64 result; // x0
  const char *v31; // x2
  __int64 v32; // [xsp+0h] [xbp-10h] BYREF
  __int64 v33; // [xsp+8h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(
      0x5Du,
      2u,
      "%s: pdev context passed is NULL",
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "ucfg_green_ap_ll_ps",
      v32,
      v33);
    result = 4;
    goto LABEL_15;
  }
  comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x16u);
  if ( !comp_private_obj )
  {
    v31 = "%s: green ap context obtained is NULL";
LABEL_14:
    qdf_trace_msg(0x5Du, 2u, v31, v18, v19, v20, v21, v22, v23, v24, v25, "ucfg_green_ap_ll_ps", v32, v33);
    result = 16;
    goto LABEL_15;
  }
  v26 = comp_private_obj;
  green_ap_tx_ops = wlan_psoc_get_green_ap_tx_ops(comp_private_obj, v18, v19, v20, v21, v22, v23, v24, v25);
  if ( !green_ap_tx_ops )
  {
    v31 = "%s: green ap tx ops obtained are NULL";
    goto LABEL_14;
  }
  v28 = green_ap_tx_ops;
  if ( !*(_QWORD *)(green_ap_tx_ops + 48) )
  {
    v31 = "%s: tx op for sending green ap ll pwr save is NULL";
    goto LABEL_14;
  }
  *(_QWORD *)(v26 + 120) = a2;
  LOBYTE(v32) = a3;
  WORD1(v32) = a4;
  if ( a3 )
    WORD1(v32) = *(_WORD *)(v26 + 104) * a4;
  HIDWORD(v32) = wlan_green_ap_get_cookie_id(v26, a3);
  *a5 = HIDWORD(v32);
  v29 = *(__int64 (__fastcall **)(__int64, __int64 *))(v28 + 48);
  if ( *((_DWORD *)v29 - 1) != -1438755845 )
    __break(0x8228u);
  result = v29(a2, &v32);
LABEL_15:
  _ReadStatusReg(SP_EL0);
  return result;
}

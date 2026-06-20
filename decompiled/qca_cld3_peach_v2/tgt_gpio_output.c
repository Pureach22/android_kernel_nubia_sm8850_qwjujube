__int64 __fastcall tgt_gpio_output(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x8
  unsigned int v13; // w21
  __int64 (__fastcall *v15)(__int64, __int64); // x8
  unsigned int v16; // w8
  __int64 result; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 v26; // x8
  __int64 (__fastcall *v27)(__int64, unsigned __int64 *); // x8
  unsigned __int64 v28; // [xsp+0h] [xbp-10h] BYREF
  __int64 v29; // [xsp+8h] [xbp-8h]

  v29 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v28 = 0;
  if ( !a1 )
  {
    qdf_trace_msg(0x7Au, 2u, "%s: psoc_obj is null", a4, a5, a6, a7, a8, a9, a10, a11, "tgt_gpio_output", v28, v29);
    goto LABEL_10;
  }
  v11 = *(_QWORD *)(a1 + 2128);
  v13 = a2;
  if ( v11 )
  {
    v15 = *(__int64 (__fastcall **)(__int64, __int64))(v11 + 1736);
    if ( !v15 )
      goto LABEL_12;
    if ( *((_DWORD *)v15 - 1) != 1468042957 )
      __break(0x8228u);
    v16 = v15(a1, a2) - 20;
    if ( v16 >= 0x16 || ((0x29A631u >> v16) & 1) == 0 )
      goto LABEL_12;
LABEL_10:
    result = 4;
    goto LABEL_17;
  }
  qdf_trace_msg(0x7Au, 2u, "%s: tx_ops is NULL", a4, a5, a6, a7, a8, a9, a10, a11, "tgt_gpio_disabled", v28, v29);
LABEL_12:
  qdf_mem_set(&v28, 8u, 0);
  v26 = *(_QWORD *)(a1 + 2128);
  v28 = __PAIR64__(a3, v13);
  if ( v26 )
  {
    v27 = *(__int64 (__fastcall **)(__int64, unsigned __int64 *))(v26 + 1976);
    if ( *((_DWORD *)v27 - 1) != 1190134446 )
      __break(0x8228u);
    result = v27(a1, &v28);
  }
  else
  {
    qdf_trace_msg(
      0x7Au,
      2u,
      "%s: tx_ops is NULL",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "wlan_psoc_get_gpio_txops",
      v28);
    result = 29;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}

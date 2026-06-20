__int64 __fastcall tgt_gpio_config(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x8
  __int64 (__fastcall *v33)(__int64, unsigned __int64 *); // x8
  __int64 result; // x0
  unsigned __int64 v35; // [xsp+8h] [xbp-28h] BYREF
  unsigned __int64 v36; // [xsp+10h] [xbp-20h]
  unsigned __int64 v37; // [xsp+18h] [xbp-18h]
  int v38; // [xsp+20h] [xbp-10h]
  __int64 v39; // [xsp+28h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v38 = 0;
  v36 = 0;
  v37 = 0;
  v35 = 0;
  if ( a1 )
  {
    qdf_mem_set(&v35, 0x1Cu, 0);
    v32 = *(_QWORD *)(a1 + 2128);
    v35 = __PAIR64__(a3, a2);
    v36 = __PAIR64__(a5, a4);
    v37 = __PAIR64__(a7, a6);
    v38 = a8;
    if ( v32 )
    {
      v33 = *(__int64 (__fastcall **)(__int64, unsigned __int64 *))(v32 + 1968);
      if ( *((_DWORD *)v33 - 1) != -900449494 )
        __break(0x8228u);
      result = v33(a1, &v35);
    }
    else
    {
      qdf_trace_msg(0x7Au, 2u, "%s: tx_ops is NULL", v24, v25, v26, v27, v28, v29, v30, v31, "wlan_psoc_get_gpio_txops");
      result = 29;
    }
  }
  else
  {
    qdf_trace_msg(0x7Au, 2u, "%s: psoc_obj is null", a9, a10, a11, a12, a13, a14, a15, a16, "tgt_gpio_config");
    result = 4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

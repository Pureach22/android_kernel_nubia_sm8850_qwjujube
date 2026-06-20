__int64 __fastcall _hdd_ioctl(
        _QWORD *a1,
        unsigned __int64 a2,
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
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w22
  int conparam; // w0
  const char *v25; // x2
  unsigned int v26; // w1
  __int64 v28; // x8
  __int64 v29; // x0

  v14 = qdf_trace_msg(0x33u, 8u, "%s: enter(%s)", a4, a5, a6, a7, a8, a9, a10, a11, "__hdd_ioctl", a1 + 37);
  if ( (_QWORD *)a1[340] != a1 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: HDD adapter/dev inconsistency", v15, v16, v17, v18, v19, v20, v21, v22, "__hdd_ioctl");
    v23 = -19;
    goto LABEL_10;
  }
  if ( !a2 )
  {
    v25 = "%s: invalid data cmd: %d";
    v26 = 2;
LABEL_8:
    qdf_trace_msg(0x33u, v26, v25, v15, v16, v17, v18, v19, v20, v21, v22, "__hdd_ioctl", a3);
    v23 = -22;
    goto LABEL_10;
  }
  conparam = hdd_get_conparam(v14);
  if ( a3 == 35325 && conparam == 5 )
  {
    v23 = wlan_hdd_qcmbr_unified_ioctl((__int64)(a1 + 336), a2);
    goto LABEL_10;
  }
  v23 = _wlan_hdd_validate_context(a1[339], "__hdd_ioctl");
  if ( v23 )
    goto LABEL_10;
  if ( a3 != 35313 )
  {
    v25 = "%s: unknown ioctl %d";
    v26 = 3;
    goto LABEL_8;
  }
  v28 = *(_QWORD *)_ReadStatusReg(SP_EL0);
  v29 = a1[6940];
  if ( (v28 & 0x400000) != 0 )
    v23 = hdd_driver_compat_ioctl(v29, a2);
  else
    v23 = hdd_driver_ioctl(v29, a2);
LABEL_10:
  qdf_trace_msg(0x33u, 8u, "%s: exit", v15, v16, v17, v18, v19, v20, v21, v22, "__hdd_ioctl");
  return v23;
}

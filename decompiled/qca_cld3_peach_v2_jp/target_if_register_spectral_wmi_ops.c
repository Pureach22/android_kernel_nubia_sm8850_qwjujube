__int64 __fastcall target_if_register_spectral_wmi_ops(
        __int64 a1,
        _QWORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 (*v11)(void); // x8
  _QWORD *v13; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v23; // x9
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x9
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x9
  __int64 v30; // x11
  __int64 v31; // x12
  const char *v32; // x2

  if ( !a1 )
  {
    v32 = "%s: psoc is null";
LABEL_9:
    qdf_trace_msg(0x56u, 2u, v32, a3, a4, a5, a6, a7, a8, a9, a10, "get_target_if_spectral_handle_from_psoc");
    goto LABEL_10;
  }
  v10 = *(_QWORD *)(a1 + 2136);
  if ( !v10 )
  {
    v32 = "%s: rx_ops is null";
    goto LABEL_9;
  }
  v11 = *(__int64 (**)(void))(v10 + 264);
  if ( *((_DWORD *)v11 - 1) != -373219892 )
    __break(0x8228u);
  v13 = (_QWORD *)v11();
  if ( v13 )
  {
    v13[1] = *a2;
    v23 = a2[4];
    v24 = a2[1];
    v25 = a2[2];
    v13[4] = a2[3];
    v13[5] = v23;
    v13[2] = v24;
    v13[3] = v25;
    v26 = a2[8];
    v27 = a2[5];
    v28 = a2[6];
    v13[8] = a2[7];
    v13[9] = v26;
    v13[6] = v27;
    v13[7] = v28;
    v29 = a2[12];
    v30 = a2[9];
    v31 = a2[10];
    v13[12] = a2[11];
    v13[13] = v29;
    v13[10] = v30;
    v13[11] = v31;
    return 0;
  }
LABEL_10:
  qdf_trace_msg(
    0x56u,
    2u,
    "%s: Spectral LMAC object is null",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "target_if_register_spectral_wmi_ops");
  return 4;
}

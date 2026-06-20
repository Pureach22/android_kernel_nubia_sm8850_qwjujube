__int64 __fastcall target_if_spectral_check_buffer_size(
        __int64 a1,
        char a2,
        unsigned __int16 a3,
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
  __int64 v12; // x8
  __int64 (*v13)(void); // x8
  __int64 v17; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  __int64 (__fastcall *v26)(__int64, unsigned int *); // x8
  unsigned int v27; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w19
  __int64 result; // x0
  const char *v38; // x2
  char v39; // w8
  int v40; // w8
  unsigned int v41; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  if ( !a1 )
  {
    v38 = "%s: pdev is null";
LABEL_14:
    qdf_trace_msg(0x56u, 2u, v38, a4, a5, a6, a7, a8, a9, a10, a11, "get_target_if_spectral_handle_from_pdev");
LABEL_15:
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: spectral variable in null.",
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      "target_if_spectral_check_buffer_size");
    result = 29;
    goto LABEL_16;
  }
  v11 = *(_QWORD *)(a1 + 80);
  if ( !v11 )
  {
    v38 = "%s: psoc is null";
    goto LABEL_14;
  }
  v12 = *(_QWORD *)(v11 + 2136);
  if ( !v12 )
  {
    v38 = "%s: rx_ops is null";
    goto LABEL_14;
  }
  v13 = *(__int64 (**)(void))(v12 + 256);
  if ( *((_DWORD *)v13 - 1) != 1565325861 )
    __break(0x8228u);
  v17 = v13();
  if ( !v17 )
    goto LABEL_15;
  v26 = *(__int64 (__fastcall **)(__int64, unsigned int *))(v17 + 1320);
  if ( *((_DWORD *)v26 - 1) != -183143906 )
    __break(0x8228u);
  v27 = v26(a1, &v41);
  if ( v27 )
  {
    v36 = v27;
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Failed to get spectral buffer size",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "target_if_spectral_check_buffer_size");
    result = v36;
    goto LABEL_16;
  }
  if ( a3 < 2u )
  {
    v40 = 0;
  }
  else
  {
    v39 = a2;
    if ( a3 == 3 )
    {
LABEL_21:
      v40 = 1 << v39;
      goto LABEL_24;
    }
    if ( a3 == 2 )
    {
      v39 = a2 - 1;
      goto LABEL_21;
    }
    v40 = -22;
  }
LABEL_24:
  if ( v40 + 1773 <= v41 )
  {
    result = 0;
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Requested report size %u is greater than buffer size %u.",
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      "target_if_spectral_check_buffer_size");
    result = 4;
  }
LABEL_16:
  _ReadStatusReg(SP_EL0);
  return result;
}

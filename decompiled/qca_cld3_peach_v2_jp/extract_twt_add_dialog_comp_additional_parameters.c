__int64 __fastcall extract_twt_add_dialog_comp_additional_parameters(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  unsigned int v13; // w5
  __int64 v14; // x8
  __int64 v16; // x21
  unsigned int v18; // w19
  char v19; // w0
  unsigned int v20; // w9
  unsigned int v22; // w10
  const char *v23; // x2
  const char *v24; // x2
  __int64 v25; // x4

  if ( !a2 )
  {
    v23 = "%s: evt_buf is NULL";
LABEL_11:
    qdf_trace_msg(
      0x31u,
      2u,
      v23,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "extract_twt_add_dialog_comp_additional_parameters");
    return 4;
  }
  v13 = *(_DWORD *)(a2 + 24);
  if ( v13 <= a4 )
  {
    v24 = "%s: Invalid idx %d while num_twt_params = %d";
    v25 = a4;
LABEL_13:
    qdf_trace_msg(
      0x31u,
      2u,
      v24,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      "extract_twt_add_dialog_comp_additional_parameters",
      v25);
    return 4;
  }
  v14 = *(_QWORD *)(a2 + 16);
  if ( !v14 )
  {
    v23 = "%s: Unable to extract additional twt parameters";
    goto LABEL_11;
  }
  if ( 28 * v13 + 28 != a3 )
  {
    v25 = a3;
    v24 = "%s: Got invalid len data from FW %d expected %d";
    goto LABEL_13;
  }
  v16 = a4;
  v18 = *(_DWORD *)(v14 + 28LL * a4 + 4);
  *a5 = *a5 & 0xFFFFC000 | v18 & 0x3FFF;
  v19 = wmi_service_enabled(a1, 0x145u, a6, a7, a8, a9, a10, a11, a12, a13);
  v20 = *a5;
  if ( (v19 & 1) != 0 )
  {
    v20 = v20 & 0xFFFCFFFF | ((HIWORD(v18) & 3) << 16);
    *a5 = v20;
  }
  a5[1] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 28 * v16 + 8);
  a5[2] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 28 * v16 + 12);
  a5[3] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 28 * v16 + 16);
  a5[4] = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 28 * v16 + 20);
  v22 = *(_DWORD *)(*(_QWORD *)(a2 + 16) + 28 * v16 + 24);
  *a5 = v20 & 0xFFFF3FFF | ((unsigned __int16)v18 >> 14 << 14);
  a5[5] = v22;
  return 0;
}

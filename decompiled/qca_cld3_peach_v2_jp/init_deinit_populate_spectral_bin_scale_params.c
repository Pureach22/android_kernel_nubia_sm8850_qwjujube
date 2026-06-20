__int64 __fastcall init_deinit_populate_spectral_bin_scale_params(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x23
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  unsigned int v17; // w22
  unsigned int spectral_scaling_params_service_ready_ext; // w0
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  unsigned int v28; // w20

  v4 = *(unsigned int *)(a4 + 804);
  if ( !(_DWORD)v4 )
    return 0;
  v8 = _qdf_mem_malloc(24 * v4, "init_deinit_populate_spectral_bin_scale_params", 530);
  *(_QWORD *)(a4 + 3280) = v8;
  if ( v8 )
  {
    v17 = 0;
    while ( 1 )
    {
      spectral_scaling_params_service_ready_ext = wmi_extract_spectral_scaling_params_service_ready_ext(
                                                    a2,
                                                    a3,
                                                    v17,
                                                    *(_QWORD *)(a4 + 3280) + 24LL * (unsigned __int8)v17);
      if ( spectral_scaling_params_service_ready_ext )
        break;
      if ( (unsigned int)v4 <= (unsigned __int8)++v17 )
        return 0;
    }
    v28 = spectral_scaling_params_service_ready_ext;
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Extraction of scaling params failed",
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      "init_deinit_populate_spectral_bin_scale_params");
    _qdf_mem_free(*(_QWORD *)(a4 + 3280));
    *(_QWORD *)(a4 + 3280) = 0;
    return qdf_status_to_os_return(v28);
  }
  else
  {
    qdf_trace_msg(
      0x49u,
      2u,
      "%s: Mem alloc for bin scaling params failed",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "init_deinit_populate_spectral_bin_scale_params");
    return 4294967274LL;
  }
}

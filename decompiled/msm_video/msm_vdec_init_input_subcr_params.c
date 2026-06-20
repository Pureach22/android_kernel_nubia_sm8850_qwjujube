__int64 __fastcall msm_vdec_init_input_subcr_params(__int64 a1)
{
  int v1; // w8
  int v2; // w9
  int v3; // w14
  __int64 v4; // x1
  int v5; // w10
  int v6; // w8
  int v7; // w9
  unsigned __int8 v9; // w21
  unsigned __int8 v10; // w22
  unsigned __int8 v11; // w0
  int v12; // w9
  __int64 v13; // x11
  __int64 v14; // x12
  bool v15; // zf
  __int64 v16; // x9
  __int64 v17; // x12
  int v18; // w11
  __int64 v19; // x8
  __int64 v20; // x9

  v1 = *(_DWORD *)(a1 + 392);
  v2 = *(_DWORD *)(a1 + 396);
  v3 = v2 | (v1 << 16);
  v4 = *(unsigned int *)(a1 + 616);
  v5 = *(_DWORD *)(a1 + 1884) | (*(_DWORD *)(a1 + 1880) << 16);
  v6 = (v2 - *(_DWORD *)(a1 + 1892)) | ((v1 - *(_DWORD *)(a1 + 1888)) << 16);
  v7 = *(_DWORD *)(a1 + 2560);
  *(_DWORD *)(a1 + 3272) = v3;
  *(_DWORD *)(a1 + 3276) = v5;
  *(_DWORD *)(a1 + 3280) = v6;
  *(_DWORD *)(a1 + 3292) = v7;
  v9 = v4l2_color_primaries_to_driver(a1, v4, "msm_vdec_init_input_subcr_params");
  v10 = v4l2_matrix_coeff_to_driver(a1, *(unsigned __int8 *)(a1 + 782), "msm_vdec_init_input_subcr_params");
  v11 = v4l2_transfer_char_to_driver(a1, *(unsigned __int8 *)(a1 + 784), "msm_vdec_init_input_subcr_params");
  v12 = *(unsigned __int8 *)(a1 + 783);
  v13 = *(_QWORD *)(a1 + 15104);
  *(_DWORD *)(a1 + 3308) = *(_QWORD *)(a1 + 29048);
  v14 = *(_QWORD *)(a1 + 31568);
  v15 = v12 == 1;
  v16 = *(_QWORD *)(a1 + 29216);
  *(_DWORD *)(a1 + 3304) = v13;
  *(_DWORD *)(a1 + 3296) = v14;
  v17 = *(_QWORD *)(a1 + 31904);
  v18 = v15;
  v19 = *(_QWORD *)(a1 + 31736);
  *(_DWORD *)(a1 + 3312) = v16;
  v20 = *(_QWORD *)(a1 + 32072);
  *(_DWORD *)(a1 + 3324) = v19;
  *(_DWORD *)(a1 + 3284) = v20;
  *(_DWORD *)(a1 + 3300) = v10 | (v9 << 16) | (v11 << 8) | (v18 << 25);
  *(_DWORD *)(a1 + 3288) = v17 == 0;
  return 0;
}

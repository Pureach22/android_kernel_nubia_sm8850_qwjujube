__int64 __fastcall target_if_spectral_process_report_gen3(
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
  __int64 target_if_spectral_handle_from_pdev; // x0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x19
  int v21; // w8
  __int64 v22; // x9
  int v23; // w10
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w20
  __int64 result; // x0
  __int64 v34; // [xsp+0h] [xbp-40h] BYREF
  __int64 v35; // [xsp+8h] [xbp-38h] BYREF
  __int64 v36; // [xsp+10h] [xbp-30h]
  __int64 v37; // [xsp+18h] [xbp-28h]
  __int64 v38; // [xsp+20h] [xbp-20h]
  __int128 v39; // [xsp+28h] [xbp-18h]
  __int64 v40; // [xsp+38h] [xbp-8h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v39 = 0u;
  v37 = 0;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  target_if_spectral_handle_from_pdev = get_target_if_spectral_handle_from_pdev(a1, a3, a4, a5, a6, a7, a8, a9, a10);
  if ( target_if_spectral_handle_from_pdev )
  {
    v20 = target_if_spectral_handle_from_pdev;
    ++*(_DWORD *)(target_if_spectral_handle_from_pdev + 2068);
    v21 = *((unsigned __int8 *)a2 + 32);
    v34 = a2[1];
    if ( v21 == 1 )
    {
      qdf_mem_copy(&v35, (char *)a2 + 36, 0x20u);
      v22 = a2[9];
      v23 = *((_DWORD *)a2 + 20);
      LODWORD(v39) = *((_DWORD *)a2 + 17);
      *(_QWORD *)((char *)&v39 + 4) = v22;
      HIDWORD(v39) = v23;
    }
    if ( (spectral_debug_level & 0x1400) != 0 )
    {
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Printing the spectral phyerr buffer for debug",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "target_if_spectral_process_report_gen3",
        v34,
        v35,
        v36,
        v37,
        v38,
        (_QWORD)v39,
        *((_QWORD *)&v39 + 1),
        v40);
      qdf_trace_msg(
        0x56u,
        8u,
        "%s: Datalength of buffer = 0x%zx(%zd) bufptr = 0x%pK",
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        "target_if_spectral_process_report_gen3",
        *a2,
        *a2,
        a2[1]);
      target_if_spectral_hexdump(a2[1], 1024);
    }
    v32 = *(_DWORD *)(v20 + 576);
    result = target_if_consume_spectral_report_gen3(v20, &v34, v12, v13, v14, v15, v16, v17, v18, v19);
    if ( (spectral_debug_level & 0x1000) != 0 )
    {
      if ( (_DWORD)result || *(_DWORD *)(v20 + 576) == v32 + 1 )
        spectral_debug_level = 256;
      else
        result = 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Spectral target object is null",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_spectral_process_report_gen3");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

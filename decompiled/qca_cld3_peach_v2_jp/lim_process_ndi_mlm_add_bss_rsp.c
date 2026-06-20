__int64 __fastcall lim_process_ndi_mlm_add_bss_rsp(
        _QWORD *a1,
        char *a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 result; // x0
  __int16 v31; // w2
  char v32; // w8
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v41; // [xsp+0h] [xbp-10h] BYREF
  __int64 v42; // [xsp+8h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v41 = 0;
  if ( a2 )
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Status %d",
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "lim_process_ndi_mlm_add_bss_rsp",
      *((unsigned int *)a2 + 1),
      v41,
      v42);
    if ( *((_DWORD *)a2 + 1) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: WDA_ADD_BSS_REQ failed with status %d",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_process_ndi_mlm_add_bss_rsp");
      LODWORD(v41) = 532;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: WDA_ADD_BSS_RSP returned QDF_STATUS_SUCCESS",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "lim_process_ndi_mlm_add_bss_rsp");
      v31 = *(_WORD *)(a3 + 8);
      *(_DWORD *)(a3 + 72) = 4;
      qdf_trace(53, 0, v31, 4);
      v32 = *a2;
      *(_DWORD *)(a3 + 88) = 6;
      *(_BYTE *)(a3 + 10) = v32;
      *(_WORD *)(a3 + 248) = 0;
      lim_apply_configuration(a1, a3, v33, v34, v35, v36, v37, v38, v39, v40);
      LODWORD(v41) = 0;
      lim_init_peer_idxpool((__int64)a1, a3);
    }
    BYTE4(v41) = *(_BYTE *)(a3 + 8);
    result = lim_send_start_bss_confirm((__int64)a1, (unsigned __int8 *)&v41, v22, v23, v24, v25, v26, v27, v28, v29);
  }
  else
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: add_bss_rsp is NULL",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "lim_process_ndi_mlm_add_bss_rsp",
               v41,
               v42);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

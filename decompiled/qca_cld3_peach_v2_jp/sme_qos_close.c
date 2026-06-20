__int64 __fastcall sme_qos_close(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  __int64 i; // x20
  __int64 v27; // x9
  int v28; // w10
  __int64 v29; // x9
  int v30; // w10
  __int64 v31; // x9
  int v32; // w10
  __int64 v33; // x8
  __int64 v34; // x25
  __int64 v35; // x23
  __int64 v36; // x8
  int v37; // w9
  __int64 v38; // x8
  int v39; // w9
  __int64 v40; // x8
  int v41; // w9
  __int64 v42; // x8
  int v43; // w9
  __int64 v44; // x19
  double v45; // d0
  double v46; // d1
  double v47; // d2
  double v48; // d3
  double v49; // d4
  double v50; // d5
  double v51; // d6
  double v52; // d7
  __int64 v53; // x0
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  __int64 *v62; // x23
  __int64 v63; // x24
  double v64; // d0
  double v65; // d1
  double v66; // d2
  double v67; // d3
  double v68; // d4
  double v69; // d5
  double v70; // d6
  double v71; // d7
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7
  double v80; // d0
  double v81; // d1
  double v82; // d2
  double v83; // d3
  double v84; // d4
  double v85; // d5
  double v86; // d6
  double v87; // d7
  __int64 v88; // x0

  qdf_trace_msg(0x34u, 8u, "%s: closing down SME-QoS", a2, a3, a4, a5, a6, a7, a8, a9, "sme_qos_close");
  csr_ll_close((__int64)&unk_856128, v9, v10, v11, v12, v13, v14, v15, v16);
  v25 = qword_856120;
  for ( i = 0; i != 6; ++i )
  {
    v34 = v25 + 3040 * i;
    if ( v34 )
    {
      v35 = v25 + 3040 * i;
      qdf_mem_set((void *)(v35 + 4), 0x2D8u, 0);
      v36 = qword_856120 + 3040 * i;
      v37 = *(_DWORD *)(v36 + 8);
      *(_DWORD *)(v36 + 8) = 1;
      *(_DWORD *)(v36 + 12) = v37;
      qdf_mem_set((void *)(v35 + 732), 0x2D8u, 0);
      v38 = qword_856120 + 3040 * i;
      v39 = *(_DWORD *)(v38 + 736);
      *(_DWORD *)(v38 + 736) = 1;
      *(_DWORD *)(v38 + 740) = v39;
      qdf_mem_set((void *)(v35 + 1460), 0x2D8u, 0);
      v40 = qword_856120 + 3040 * i;
      v41 = *(_DWORD *)(v40 + 1464);
      *(_DWORD *)(v40 + 1464) = 1;
      *(_DWORD *)(v40 + 1468) = v41;
      qdf_mem_set((void *)(v35 + 2188), 0x2D8u, 0);
      v42 = qword_856120 + 3040 * i;
      v43 = *(_DWORD *)(v42 + 2192);
      *(_DWORD *)(v42 + 2192) = 1;
      *(_DWORD *)(v42 + 2196) = v43;
      *(_BYTE *)(v34 + 2916) = 0;
      *(_BYTE *)(v34 + 2940) = 0;
      *(_DWORD *)(v34 + 2936) = 0;
      v44 = qword_856120 + 3040 * i;
      v53 = csr_ll_peek_head(v44 + 2944, 1, v45, v46, v47, v48, v49, v50, v51, v52);
      if ( v53 )
      {
        v62 = (__int64 *)v53;
        do
        {
          v63 = csr_ll_next(v44 + 2944, (__int64)v62, 1, v54, v55, v56, v57, v58, v59, v60, v61);
          qdf_trace_msg(
            0x34u,
            8u,
            "%s: deleting entry from buffered List",
            v64,
            v65,
            v66,
            v67,
            v68,
            v69,
            v70,
            v71,
            "sme_qos_delete_buffered_requests");
          csr_ll_remove_entry(v44 + 2944, v62, 1, v72, v73, v74, v75, v76, v77, v78, v79);
          _qdf_mem_free((__int64)v62);
          v62 = (__int64 *)v63;
        }
        while ( v63 );
      }
      sme_qos_delete_existing_flows(a1, (unsigned int)i);
      v88 = *(_QWORD *)(v34 + 2920);
      if ( v88 )
      {
        _qdf_mem_free(v88);
        *(_QWORD *)(v34 + 2920) = 0;
      }
      csr_ll_close(v34 + 2944, v80, v81, v82, v83, v84, v85, v86, v87);
      v27 = qword_856120 + 3040 * i;
      v28 = *(_DWORD *)(v27 + 8);
      *(_DWORD *)(v27 + 8) = 0;
      *(_DWORD *)(v27 + 12) = v28;
      v29 = qword_856120 + 3040 * i;
      v30 = *(_DWORD *)(v29 + 736);
      *(_DWORD *)(v29 + 736) = 0;
      *(_DWORD *)(v29 + 740) = v30;
      v31 = qword_856120 + 3040 * i;
      v32 = *(_DWORD *)(v31 + 1464);
      *(_DWORD *)(v31 + 1464) = 0;
      *(_DWORD *)(v31 + 1468) = v32;
      v33 = qword_856120 + 3040 * i;
      LODWORD(v31) = *(_DWORD *)(v33 + 2192);
      *(_DWORD *)(v33 + 2192) = 0;
      *(_DWORD *)(v33 + 2196) = v31;
      *(_BYTE *)(v34 + 1) = 0;
      v25 = qword_856120;
    }
  }
  qword_856120 = 0;
  qword_856180 = 0;
  qdf_trace_msg(0x34u, 8u, "%s: closed down QoS", v17, v18, v19, v20, v21, v22, v23, v24, "sme_qos_close");
  return 0;
}

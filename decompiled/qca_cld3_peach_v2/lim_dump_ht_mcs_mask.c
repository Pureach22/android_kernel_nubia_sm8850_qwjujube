__int64 __fastcall lim_dump_ht_mcs_mask(unsigned __int8 *a1, unsigned __int8 *a2)
{
  __int64 result; // x0
  __int64 v5; // x19
  unsigned int v6; // w0
  unsigned int v7; // w23
  int v8; // w0
  __int64 v9; // x23
  int v10; // w0
  __int64 v11; // x23
  int v12; // w0
  __int64 v13; // x23
  int v14; // w0
  __int64 v15; // x23
  int v16; // w0
  __int64 v17; // x23
  int v18; // w0
  __int64 v19; // x23
  int v20; // w0
  __int64 v21; // x23
  int v22; // w0
  __int64 v23; // x23
  int v24; // w0
  __int64 v25; // x23
  int v26; // w0
  __int64 v27; // x23
  int v28; // w0
  __int64 v29; // x23
  int v30; // w0
  __int64 v31; // x23
  int v32; // w0
  __int64 v33; // x23
  int v34; // w0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  unsigned int v43; // w0
  unsigned int v44; // w22
  int v45; // w0
  __int64 v46; // x22
  int v47; // w0
  __int64 v48; // x22
  int v49; // w0
  __int64 v50; // x22
  int v51; // w0
  __int64 v52; // x22
  int v53; // w0
  __int64 v54; // x22
  int v55; // w0
  __int64 v56; // x22
  int v57; // w0
  __int64 v58; // x22
  int v59; // w0
  __int64 v60; // x22
  int v61; // w0
  __int64 v62; // x22
  int v63; // w0
  __int64 v64; // x22
  int v65; // w0
  __int64 v66; // x22
  int v67; // w0
  __int64 v68; // x22
  int v69; // w0
  __int64 v70; // x22
  int v71; // w0
  double v72; // d0
  double v73; // d1
  double v74; // d2
  double v75; // d3
  double v76; // d4
  double v77; // d5
  double v78; // d6
  double v79; // d7

  result = _qdf_mem_malloc(0x51u, "lim_dump_ht_mcs_mask", 1402);
  if ( result )
  {
    v5 = result;
    if ( a1 )
    {
      scnprintf(result, 81, "0x%x ", *a1);
      v7 = v6;
      scnprintf(v5 + v6, 81 - v6, "0x%x ", a1[1]);
      v9 = v8 + v7;
      scnprintf(v5 + v9, (unsigned int)(81 - v9), "0x%x ", a1[2]);
      v11 = (unsigned int)(v10 + v9);
      scnprintf(v5 + v11, (unsigned int)(81 - v11), "0x%x ", a1[3]);
      v13 = (unsigned int)(v12 + v11);
      scnprintf(v5 + v13, (unsigned int)(81 - v13), "0x%x ", a1[4]);
      v15 = (unsigned int)(v14 + v13);
      scnprintf(v5 + v15, (unsigned int)(81 - v15), "0x%x ", a1[5]);
      v17 = (unsigned int)(v16 + v15);
      scnprintf(v5 + v17, (unsigned int)(81 - v17), "0x%x ", a1[6]);
      v19 = (unsigned int)(v18 + v17);
      scnprintf(v5 + v19, (unsigned int)(81 - v19), "0x%x ", a1[7]);
      v21 = (unsigned int)(v20 + v19);
      scnprintf(v5 + v21, (unsigned int)(81 - v21), "0x%x ", a1[8]);
      v23 = (unsigned int)(v22 + v21);
      scnprintf(v5 + v23, (unsigned int)(81 - v23), "0x%x ", a1[9]);
      v25 = (unsigned int)(v24 + v23);
      scnprintf(v5 + v25, (unsigned int)(81 - v25), "0x%x ", a1[10]);
      v27 = (unsigned int)(v26 + v25);
      scnprintf(v5 + v27, (unsigned int)(81 - v27), "0x%x ", a1[11]);
      v29 = (unsigned int)(v28 + v27);
      scnprintf(v5 + v29, (unsigned int)(81 - v29), "0x%x ", a1[12]);
      v31 = (unsigned int)(v30 + v29);
      scnprintf(v5 + v31, (unsigned int)(81 - v31), "0x%x ", a1[13]);
      v33 = (unsigned int)(v32 + v31);
      scnprintf(v5 + v33, (unsigned int)(81 - v33), "0x%x ", a1[14]);
      v35 = scnprintf(v5 + (unsigned int)(v34 + v33), (unsigned int)(81 - (v34 + v33)), "0x%x ", a1[15]);
      qdf_trace_msg(0x35u, 8u, "SELF HT MCS: %s", v35, v36, v37, v38, v39, v40, v41, v42, v5);
    }
    if ( a2 )
    {
      scnprintf(v5, 81, "0x%x ", *a2);
      v44 = v43;
      scnprintf(v5 + v43, 81 - v43, "0x%x ", a2[1]);
      v46 = v45 + v44;
      scnprintf(v5 + v46, (unsigned int)(81 - v46), "0x%x ", a2[2]);
      v48 = (unsigned int)(v47 + v46);
      scnprintf(v5 + v48, (unsigned int)(81 - v48), "0x%x ", a2[3]);
      v50 = (unsigned int)(v49 + v48);
      scnprintf(v5 + v50, (unsigned int)(81 - v50), "0x%x ", a2[4]);
      v52 = (unsigned int)(v51 + v50);
      scnprintf(v5 + v52, (unsigned int)(81 - v52), "0x%x ", a2[5]);
      v54 = (unsigned int)(v53 + v52);
      scnprintf(v5 + v54, (unsigned int)(81 - v54), "0x%x ", a2[6]);
      v56 = (unsigned int)(v55 + v54);
      scnprintf(v5 + v56, (unsigned int)(81 - v56), "0x%x ", a2[7]);
      v58 = (unsigned int)(v57 + v56);
      scnprintf(v5 + v58, (unsigned int)(81 - v58), "0x%x ", a2[8]);
      v60 = (unsigned int)(v59 + v58);
      scnprintf(v5 + v60, (unsigned int)(81 - v60), "0x%x ", a2[9]);
      v62 = (unsigned int)(v61 + v60);
      scnprintf(v5 + v62, (unsigned int)(81 - v62), "0x%x ", a2[10]);
      v64 = (unsigned int)(v63 + v62);
      scnprintf(v5 + v64, (unsigned int)(81 - v64), "0x%x ", a2[11]);
      v66 = (unsigned int)(v65 + v64);
      scnprintf(v5 + v66, (unsigned int)(81 - v66), "0x%x ", a2[12]);
      v68 = (unsigned int)(v67 + v66);
      scnprintf(v5 + v68, (unsigned int)(81 - v68), "0x%x ", a2[13]);
      v70 = (unsigned int)(v69 + v68);
      scnprintf(v5 + v70, (unsigned int)(81 - v70), "0x%x ", a2[14]);
      v72 = scnprintf(v5 + (unsigned int)(v71 + v70), (unsigned int)(81 - (v71 + v70)), "0x%x ", a2[15]);
      qdf_trace_msg(0x35u, 8u, "PEER HT MCS: %s", v72, v73, v74, v75, v76, v77, v78, v79, v5);
    }
    return _qdf_mem_free(v5);
  }
  return result;
}

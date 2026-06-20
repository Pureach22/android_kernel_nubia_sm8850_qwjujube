__int64 __fastcall crypto_add_entry(
        __int64 a1,
        unsigned __int8 a2,
        unsigned __int8 *a3,
        __int64 a4,
        int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x0
  __int64 v31; // x0
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  int v40; // w8
  __int16 v41; // w9
  __int64 v42; // x22
  unsigned int v43; // w8
  unsigned int v44; // w24
  __int64 v45; // x10
  double v46; // d0
  double v47; // d1
  double v48; // d2
  double v49; // d3
  double v50; // d4
  double v51; // d5
  double v52; // d6
  double v53; // d7
  __int64 v54; // x22
  __int64 v55; // x4
  int v56; // w8
  int v57; // w9
  int v58; // w10
  int v59; // w11
  unsigned int v60; // w21
  double v61; // d0
  double v62; // d1
  double v63; // d2
  double v64; // d3
  double v65; // d4
  double v66; // d5
  double v67; // d6
  double v68; // d7
  __int64 v69; // x27
  __int64 v70; // x4
  int v71; // w8
  int v72; // w9
  int v73; // w10
  int v74; // w11
  __int64 v75; // x27
  __int64 v76; // x4
  int v77; // w8
  int v78; // w9
  int v79; // w10
  int v80; // w11
  __int64 v82; // x4
  __int64 v83; // x5
  __int64 v84; // x6
  __int64 v85; // x7
  unsigned int v92; // w9
  __int64 v93; // [xsp+0h] [xbp-20h]

  if ( a3 )
  {
    v18 = *a3;
    v19 = a3[1];
    v20 = a3[2];
    v21 = a3[5];
  }
  else
  {
    v20 = 0;
    v18 = 0;
    v19 = 0;
    v21 = 0;
  }
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: crypto add entry link id %d mac_addr: %02x:%02x:%02x:**:**:%02x",
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a13,
    "crypto_add_entry",
    a2,
    v18,
    v19,
    v20,
    v21);
  qdf_mutex_acquire(a1);
  if ( *(int *)(a1 + 64) >= 1024 )
  {
    if ( a3 )
    {
      v82 = *a3;
      v83 = a3[1];
      v84 = a3[2];
      v85 = a3[5];
    }
    else
    {
      v84 = 0;
      v82 = 0;
      v83 = 0;
      v85 = 0;
    }
    v60 = 2;
    qdf_trace_msg(
      0x1Cu,
      2u,
      "%s: max crypto hash entry limit reached mac_addr: %02x:%02x:%02x:**:**:%02x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "crypto_add_entry",
      v82,
      v83,
      v84,
      v85);
    goto LABEL_35;
  }
  v30 = crypto_hash_find_by_linkid_and_macaddr(a1, a2, a3);
  if ( v30 )
  {
    v42 = v30;
    goto LABEL_8;
  }
  v31 = _qdf_mem_malloc(0xA8u, "crypto_add_entry", 290);
  if ( !v31 )
  {
    v60 = 2;
    goto LABEL_35;
  }
  v40 = *(_DWORD *)a3;
  v41 = *((_WORD *)a3 + 2);
  *(_BYTE *)(v31 + 9) = a2;
  v42 = v31;
  *(_DWORD *)v31 = v40;
  *(_WORD *)(v31 + 4) = v41;
  v43 = (unsigned __int16)(v40 ^ a2 ^ v41 ^ HIWORD(v40));
  v44 = ((v43 >> *(_DWORD *)(a1 + 76)) ^ v43) & *(_DWORD *)(a1 + 72);
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: crypto hash add index %d ",
    v32,
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    "crypto_hash_add",
    v44);
  qdf_mutex_acquire(a1);
  v45 = 16LL * v44;
  *(_QWORD *)(v42 + 152) = 0;
  *(_QWORD *)(v42 + 160) = *(_QWORD *)(*(_QWORD *)(a1 + 80) + v45 + 8);
  **(_QWORD **)(*(_QWORD *)(a1 + 80) + v45 + 8) = v42;
  *(_QWORD *)(*(_QWORD *)(a1 + 80) + v45 + 8) = v42 + 152;
  qdf_mutex_release(a1);
  while ( 1 )
  {
    _X8 = (unsigned int *)(a1 + 64);
    __asm { PRFM            #0x11, [X8] }
    do
      v92 = __ldxr(_X8);
    while ( __stxr(v92 + 1, _X8) );
    *(_BYTE *)(v42 + 8) = 1;
LABEL_8:
    if ( !is_valid_keyix((unsigned __int8)a5) )
    {
      qdf_trace_msg(
        0x1Cu,
        2u,
        "%s: Invalid key index %d",
        v46,
        v47,
        v48,
        v49,
        v50,
        v51,
        v52,
        v53,
        "crypto_add_entry",
        (unsigned __int8)a5);
      v60 = 4;
      goto LABEL_35;
    }
    if ( (unsigned __int8)a5 <= 3u )
    {
      v54 = v42 + 16;
      v55 = *(_QWORD *)(v54 + 8LL * (unsigned __int8)a5);
      if ( v55 && v55 != a4 )
      {
        if ( a3 )
        {
          v56 = *a3;
          v57 = a3[1];
          v58 = a3[2];
          v59 = a3[5];
        }
        else
        {
          v58 = 0;
          v56 = 0;
          v57 = 0;
          v59 = 0;
        }
        LODWORD(v93) = v56;
        qdf_trace_msg(
          0x1Cu,
          4u,
          "%s: crypto key addr1:%pK addr2:%pK key index %d, link id %d mac_addr: %02x:%02x:%02x:**:**:%02x",
          v46,
          v47,
          v48,
          v49,
          v50,
          v51,
          v52,
          v53,
          "crypto_add_entry",
          v93,
          v57,
          v58,
          v59);
        _qdf_mem_free(*(_QWORD *)(v54 + 8LL * (unsigned __int8)a5));
      }
      v60 = 0;
      *(_QWORD *)(v54 + 8LL * (unsigned __int8)a5) = a4;
      goto LABEL_35;
    }
    if ( !is_igtk((unsigned __int8)a5) )
      break;
    a5 -= 4;
    if ( (unsigned __int8)a5 <= 1u )
    {
      v69 = v42 + 48;
      v70 = *(_QWORD *)(v42 + 48 + 8LL * (unsigned __int8)a5);
      if ( v70 && v70 != a4 )
      {
        if ( a3 )
        {
          v71 = *a3;
          v72 = a3[1];
          v73 = a3[2];
          v74 = a3[5];
        }
        else
        {
          v73 = 0;
          v71 = 0;
          v72 = 0;
          v74 = 0;
        }
        LODWORD(v93) = v71;
        qdf_trace_msg(
          0x1Cu,
          4u,
          "%s: crypto key addr1:%pK addr2:%pK key index %d, link id %d mac_addr: %02x:%02x:%02x:**:**:%02x",
          v61,
          v62,
          v63,
          v64,
          v65,
          v66,
          v67,
          v68,
          "crypto_add_entry",
          v93,
          v72,
          v73,
          v74);
        _qdf_mem_free(*(_QWORD *)(v69 + 8LL * (unsigned __int8)a5));
      }
      *(_QWORD *)(v69 + 8LL * (unsigned __int8)a5) = a4;
      v60 = 0;
      *(_BYTE *)(v42 + 149) = a5;
      *(_DWORD *)(v42 + 144) = *(_DWORD *)(a4 + 8);
      goto LABEL_35;
    }
LABEL_42:
    __break(0x5512u);
  }
  a5 -= 6;
  if ( (unsigned __int8)a5 > 1u )
    goto LABEL_42;
  v75 = v42 + 64;
  v76 = *(_QWORD *)(v42 + 64 + 8LL * (unsigned __int8)a5);
  if ( v76 && v76 != a4 )
  {
    if ( a3 )
    {
      v77 = *a3;
      v78 = a3[1];
      v79 = a3[2];
      v80 = a3[5];
    }
    else
    {
      v79 = 0;
      v77 = 0;
      v78 = 0;
      v80 = 0;
    }
    LODWORD(v93) = v77;
    qdf_trace_msg(
      0x1Cu,
      4u,
      "%s: crypto key addr1:%pK addr2:%pK key index %d, link id %d mac_addr: %02x:%02x:%02x:**:**:%02x",
      v61,
      v62,
      v63,
      v64,
      v65,
      v66,
      v67,
      v68,
      "crypto_add_entry",
      v93,
      v78,
      v79,
      v80);
    _qdf_mem_free(*(_QWORD *)(v75 + 8LL * (unsigned __int8)a5));
  }
  v60 = 0;
  *(_QWORD *)(v75 + 8LL * (unsigned __int8)a5) = a4;
  *(_BYTE *)(v42 + 150) = a5;
LABEL_35:
  qdf_mutex_release(a1);
  return v60;
}

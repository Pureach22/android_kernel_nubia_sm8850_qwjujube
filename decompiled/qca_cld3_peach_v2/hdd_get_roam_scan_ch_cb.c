__int64 __fastcall hdd_get_roam_scan_ch_cb(
        _QWORD *a1,
        unsigned __int16 *a2,
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
  __int64 v22; // x0
  __int64 v23; // x20
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned int v33; // w22
  __int64 v34; // x24
  __int64 v35; // x21
  unsigned int v36; // w9
  int v37; // w8
  bool v38; // zf
  int v39; // w10
  unsigned __int8 v40; // w11
  unsigned int *v41; // x12
  unsigned int v42; // w13
  unsigned int v43; // w14
  unsigned int v44; // w8
  unsigned int v45; // w21
  const char *v46; // x2
  int v47; // w25
  int v48; // w26
  char v49; // w0
  int v50; // w8
  unsigned __int64 v51; // x8
  __int64 result; // x0
  double v53; // d0
  double v54; // d1
  double v55; // d2
  double v56; // d3
  double v57; // d4
  double v58; // d5
  double v59; // d6
  double v60; // d7
  unsigned int v61; // w23
  __int64 v62; // x25
  __int64 v63; // x22
  unsigned int v64; // w9
  int v65; // w8
  int v66; // w10
  unsigned __int8 v67; // w11
  unsigned int *v68; // x12
  unsigned int v69; // w13
  unsigned int v70; // w14
  int v71; // w26
  int v72; // w27
  char v73; // w0
  double v74; // d0
  double v75; // d1
  double v76; // d2
  double v77; // d3
  double v78; // d4
  double v79; // d5
  double v80; // d6
  double v81; // d7
  unsigned __int64 v82; // x8
  __int64 v83; // [xsp+8h] [xbp-88h] BYREF
  __int64 v84; // [xsp+10h] [xbp-80h]
  __int64 v85; // [xsp+18h] [xbp-78h]
  __int64 v86; // [xsp+20h] [xbp-70h]
  __int64 v87; // [xsp+28h] [xbp-68h]
  __int64 v88; // [xsp+30h] [xbp-60h]
  __int64 v89; // [xsp+38h] [xbp-58h]
  __int64 v90; // [xsp+40h] [xbp-50h]
  __int64 v91; // [xsp+48h] [xbp-48h]
  __int64 v92; // [xsp+50h] [xbp-40h]
  __int64 v93; // [xsp+58h] [xbp-38h]
  __int64 v94; // [xsp+60h] [xbp-30h]
  __int64 v95; // [xsp+68h] [xbp-28h]
  __int64 v96; // [xsp+70h] [xbp-20h]
  __int64 v97; // [xsp+78h] [xbp-18h]
  __int64 v98; // [xsp+80h] [xbp-10h]
  __int64 v99; // [xsp+88h] [xbp-8h]

  v99 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: roam scan ch list event received : vdev_id:%d command resp: %d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "hdd_get_roam_scan_ch_cb",
    *a2,
    *((unsigned int *)a2 + 1));
  if ( *((_DWORD *)a2 + 1) )
  {
    v22 = osif_request_get(a3);
    if ( v22 )
    {
      v23 = v22;
      v24 = osif_request_priv(v22);
      v33 = a2[1];
      v34 = *((_QWORD *)a2 + 1);
      v35 = v24;
      v36 = v33 - 2;
      if ( v33 >= 2 )
      {
        v37 = 0;
        if ( v36 >= 0x63 )
          v36 = 99;
        do
        {
          v39 = ~v37 + v33;
          if ( v39 >= 1 )
          {
            v40 = 0;
            do
            {
              v41 = (unsigned int *)(v34 + 4LL * v40);
              v42 = *v41;
              v43 = v41[1];
              if ( *v41 < v43 )
              {
                *v41 = v43;
                v41[1] = v42;
              }
              ++v40;
            }
            while ( v39 > (unsigned int)v40 );
          }
          v38 = v37++ == v36;
        }
        while ( !v38 );
        v33 = a2[1];
        v34 = *((_QWORD *)a2 + 1);
      }
      v97 = 0;
      v98 = 0;
      v95 = 0;
      v96 = 0;
      v93 = 0;
      v94 = 0;
      v91 = 0;
      v92 = 0;
      v89 = 0;
      v90 = 0;
      v87 = 0;
      v88 = 0;
      v85 = 0;
      v86 = 0;
      v83 = 0;
      v84 = 0;
      if ( v33 )
      {
        LOBYTE(v47) = 0;
        v48 = 0;
        do
        {
          v49 = snprintf(
                  (char *)&v83 + (unsigned __int8)v47,
                  (unsigned __int8)(0x80 - v47),
                  " %d",
                  *(_DWORD *)(v34 + 4LL * (unsigned __int8)v48++));
          if ( v33 <= (unsigned __int8)v48 )
            break;
          v47 = (char)(v47 + v49);
        }
        while ( (v47 & 0x80000000) == 0 );
      }
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: No of freq:%d, freq list : %s",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_dump_roam_scan_ch_list",
        v33,
        &v83);
      v50 = a2[1];
      *(_WORD *)(v35 + 2) = v50;
      if ( v50 )
      {
        v51 = 0;
        do
        {
          *(_DWORD *)(*(_QWORD *)(v35 + 8) + 4 * v51) = *(_DWORD *)(*((_QWORD *)a2 + 1) + 4 * v51);
          if ( v51 > 0x62 )
            break;
          ++v51;
        }
        while ( *(unsigned __int16 *)(v35 + 2) > (unsigned int)(unsigned __int16)v51 );
      }
      osif_request_complete(v23);
      result = osif_request_put(v23);
      goto LABEL_49;
    }
    v46 = "%s: Obsolete request";
LABEL_48:
    result = qdf_trace_msg(0x33u, 2u, v46, v14, v15, v16, v17, v18, v19, v20, v21, "hdd_get_roam_scan_ch_cb");
    goto LABEL_49;
  }
  v44 = a2[1];
  if ( v44 < 0x1F )
  {
    if ( !a2[1] )
    {
      v46 = "%s: Invalid len";
      goto LABEL_48;
    }
    v45 = 4 * v44;
  }
  else
  {
    v45 = 120;
    a2[1] = 30;
  }
  result = _qdf_mem_malloc(v45, "hdd_get_roam_scan_ch_cb", 3592);
  if ( result )
  {
    v61 = a2[1];
    v62 = *((_QWORD *)a2 + 1);
    v63 = result;
    v64 = v61 - 2;
    if ( v61 >= 2 )
    {
      v65 = 0;
      if ( v64 >= 0x63 )
        v64 = 99;
      do
      {
        v66 = ~v65 + v61;
        if ( v66 >= 1 )
        {
          v67 = 0;
          do
          {
            v68 = (unsigned int *)(v62 + 4LL * v67);
            v69 = *v68;
            v70 = v68[1];
            if ( *v68 < v70 )
            {
              *v68 = v70;
              v68[1] = v69;
            }
            ++v67;
          }
          while ( v66 > (unsigned int)v67 );
        }
        v38 = v65++ == v64;
      }
      while ( !v38 );
      v61 = a2[1];
      v62 = *((_QWORD *)a2 + 1);
    }
    v97 = 0;
    v98 = 0;
    v95 = 0;
    v96 = 0;
    v93 = 0;
    v94 = 0;
    v91 = 0;
    v92 = 0;
    v89 = 0;
    v90 = 0;
    v87 = 0;
    v88 = 0;
    v85 = 0;
    v86 = 0;
    v83 = 0;
    v84 = 0;
    if ( v61 )
    {
      LOBYTE(v71) = 0;
      v72 = 0;
      do
      {
        v73 = snprintf(
                (char *)&v83 + (unsigned __int8)v71,
                (unsigned __int8)(0x80 - v71),
                " %d",
                *(_DWORD *)(v62 + 4LL * (unsigned __int8)v72++));
        if ( v61 <= (unsigned __int8)v72 )
          break;
        v71 = (char)(v71 + v73);
      }
      while ( (v71 & 0x80000000) == 0 );
    }
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: No of freq:%d, freq list : %s",
      v53,
      v54,
      v55,
      v56,
      v57,
      v58,
      v59,
      v60,
      "hdd_dump_roam_scan_ch_list",
      v61,
      &v83);
    if ( a2[1] )
    {
      v82 = 0;
      do
      {
        *(_DWORD *)(v63 + 4 * v82) = *(_DWORD *)(*((_QWORD *)a2 + 1) + 4 * v82);
        if ( v82 > 0x62 )
          break;
        ++v82;
      }
      while ( a2[1] > (unsigned int)(unsigned __int16)v82 );
    }
    hdd_send_roam_scan_ch_list_event(a1, v74, v75, v76, v77, v78, v79, v80, v81, *(unsigned __int8 *)a2, v45, v63);
    result = _qdf_mem_free(v63);
  }
LABEL_49:
  _ReadStatusReg(SP_EL0);
  return result;
}

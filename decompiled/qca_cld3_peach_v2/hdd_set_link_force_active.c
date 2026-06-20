__int64 __fastcall hdd_set_link_force_active(
        unsigned __int8 *a1,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x8
  __int64 v11; // x19
  __int64 v12; // x4
  __int64 result; // x0
  unsigned __int16 *v14; // x21
  unsigned int v15; // w22
  unsigned int v16; // w8
  int v17; // w2
  unsigned __int8 *v18; // x20
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  __int64 v28; // x8
  int v29; // w22
  unsigned __int16 *v30; // x21
  unsigned int v31; // w8
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  int v41; // w22
  unsigned __int16 *v42; // x21
  unsigned int v43; // w8
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  __int64 v60; // x9
  unsigned int v61; // w8
  unsigned int v62; // w9
  __int64 v63; // x8
  unsigned int v64; // w19
  __int64 v65; // [xsp+0h] [xbp-30h]
  __int64 v66; // [xsp+0h] [xbp-30h]
  __int64 v67; // [xsp+10h] [xbp-20h] BYREF
  __int64 v68; // [xsp+18h] [xbp-18h] BYREF
  __int16 v69; // [xsp+20h] [xbp-10h]
  __int64 v70; // [xsp+28h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(_QWORD *)a1;
  v11 = *(_QWORD *)(*(_QWORD *)a1 + 24LL);
  if ( v11 )
  {
    v69 = 0;
    v67 = 0;
    v68 = 0;
    if ( !a2 || *(_DWORD *)(v10 + 40) )
    {
      v12 = 0;
LABEL_23:
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: number of links to force active: %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "hdd_set_link_force_active",
        v12);
      result = 0;
      goto LABEL_24;
    }
    v14 = a2 + 2;
    v15 = (unsigned __int16)(*a2 - 4);
    if ( v15 < 4 )
    {
      v17 = 0;
      goto LABEL_22;
    }
    v16 = *v14;
    v17 = 0;
    if ( v16 < 4 || v15 < v16 )
      goto LABEL_22;
    v18 = a1;
    qdf_mem_copy(&v67, a2 + 4, 6u);
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: %02x:%02x:%02x:**:**:%02x is link[%d] mac address",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "hdd_set_link_force_active",
      (unsigned __int8)v67,
      BYTE1(v67),
      BYTE2(v67),
      BYTE5(v67),
      0);
    v28 = ((unsigned __int16)a2[2] + 3) & 0x1FFFC;
    v29 = v15 - v28;
    if ( v29 < 4 )
    {
      v17 = 1;
    }
    else
    {
      v30 = (unsigned __int16 *)((char *)v14 + v28);
      v17 = 1;
      v31 = *v30;
      if ( v31 >= 4 )
      {
        a1 = v18;
        if ( v29 < v31 )
          goto LABEL_22;
        qdf_mem_copy((char *)&v67 + 6, v30 + 2, 6u);
        LODWORD(v65) = 1;
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: %02x:%02x:%02x:**:**:%02x is link[%d] mac address",
          v32,
          v33,
          v34,
          v35,
          v36,
          v37,
          v38,
          v39,
          "hdd_set_link_force_active",
          BYTE6(v67),
          HIBYTE(v67),
          (unsigned __int8)v68,
          BYTE3(v68),
          v65);
        v40 = (*v30 + 3) & 0x1FFFC;
        v41 = v29 - v40;
        if ( v41 < 4 )
        {
          v17 = 2;
          a1 = v18;
          goto LABEL_22;
        }
        v42 = (unsigned __int16 *)((char *)v30 + v40);
        v17 = 2;
        v43 = *v42;
        if ( v43 >= 4 )
        {
          a1 = v18;
          if ( v41 < v43 )
            goto LABEL_22;
          qdf_mem_copy((char *)&v68 + 4, v42 + 2, 6u);
          LODWORD(v66) = 2;
          qdf_trace_msg(
            0x33u,
            8u,
            "%s: %02x:%02x:%02x:**:**:%02x is link[%d] mac address",
            v44,
            v45,
            v46,
            v47,
            v48,
            v49,
            v50,
            v51,
            "hdd_set_link_force_active",
            BYTE4(v68),
            BYTE5(v68),
            BYTE6(v68),
            HIBYTE(v69),
            v66);
          v60 = (*v42 + 3) & 0x1FFFC;
          v61 = v41 - v60;
          if ( v41 - (int)v60 < 4 )
          {
            v17 = 3;
          }
          else
          {
            v62 = *(unsigned __int16 *)((char *)v42 + v60);
            v17 = 3;
            if ( v62 >= 4 )
            {
              a1 = v18;
              if ( v61 >= v62 )
              {
                qdf_trace_msg(
                  0x33u,
                  2u,
                  "%s: No. of force active links %d exceeds max allowed BSS links",
                  v52,
                  v53,
                  v54,
                  v55,
                  v56,
                  v57,
                  v58,
                  v59,
                  "hdd_set_link_force_active",
                  4);
                result = 4294967274LL;
                goto LABEL_24;
              }
LABEL_22:
              v63 = *(_QWORD *)(v11 + 16);
              v64 = v17;
              sme_activate_mlo_links(v63, a1[8]);
              v12 = v64;
              goto LABEL_23;
            }
          }
        }
      }
    }
    a1 = v18;
    goto LABEL_22;
  }
  result = 4294967274LL;
LABEL_24:
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall lim_tspec_add(
        __int64 a1,
        const void *a2,
        unsigned __int16 a3,
        __int64 *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        __int64 a13,
        _QWORD *a14)
{
  int v14; // w21
  _BYTE *v18; // x23
  _BYTE *v19; // x24
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w8
  _BYTE *v29; // x9
  unsigned int v31; // w23
  __int64 v32; // x9
  __int64 v33; // x10
  __int64 v34; // x11
  __int64 v35; // x9
  __int64 v36; // x11
  __int16 v37; // w8
  __int64 v38; // x10
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int16 v47; // w8
  const char *v48; // x2

  *a14 = 0;
  v14 = a3;
  if ( *(unsigned __int16 *)(a1 + 3990) <= (unsigned int)a3 )
  {
    qdf_trace_msg(0x35u, 2u, "%s: Invalid assocId 0x%x", a5, a6, a7, a8, a9, a10, a11, a12, "lim_tspec_add", a3);
    return 16;
  }
  else
  {
    v18 = (_BYTE *)(a1 + 0x2000);
    v19 = (_BYTE *)(a1 + 8920);
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Trying to find tspec entry for assocId: %d pTsInfo->traffic.direction: %d pTsInfo->traffic.tsid: %d",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "lim_find_tspec",
      a3,
      (*(unsigned __int16 *)((char *)a4 + 3) >> 5) & 3,
      (*(unsigned __int16 *)((char *)a4 + 3) >> 1) & 0xF);
    v28 = 15;
    v29 = v19;
    do
    {
      if ( *v29
        && *((unsigned __int16 *)v29 + 4) == v14
        && ((*(_WORD *)(v29 + 13) ^ *(_WORD *)((char *)a4 + 3)) & 0x7E) == 0 )
      {
        *a14 = v29;
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: updating TSPEC table entry: %d",
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          "lim_tspec_add",
          (unsigned __int8)v29[1]);
        goto LABEL_41;
      }
      --v28;
      v29 += 163;
    }
    while ( v28 );
    if ( *v19 )
    {
      if ( v18[891] )
      {
        if ( v18[1054] )
        {
          if ( v18[1217] )
          {
            if ( v18[1380] )
            {
              if ( v18[1543] )
              {
                if ( v18[1706] )
                {
                  if ( v18[1869] )
                  {
                    if ( v18[2032] )
                    {
                      if ( v18[2195] )
                      {
                        if ( v18[2358] )
                        {
                          if ( v18[2521] )
                          {
                            if ( v18[2684] )
                            {
                              if ( v18[2847] )
                              {
                                if ( v18[3010] )
                                  return 16;
                                v19 = v18 + 3010;
                                v31 = 14;
                              }
                              else
                              {
                                v19 = v18 + 2847;
                                v31 = 13;
                              }
                            }
                            else
                            {
                              v19 = v18 + 2684;
                              v31 = 12;
                            }
                          }
                          else
                          {
                            v19 = v18 + 2521;
                            v31 = 11;
                          }
                        }
                        else
                        {
                          v19 = v18 + 2358;
                          v31 = 10;
                        }
                      }
                      else
                      {
                        v19 = v18 + 2195;
                        v31 = 9;
                      }
                    }
                    else
                    {
                      v19 = v18 + 2032;
                      v31 = 8;
                    }
                  }
                  else
                  {
                    v19 = v18 + 1869;
                    v31 = 7;
                  }
                }
                else
                {
                  v19 = v18 + 1706;
                  v31 = 6;
                }
              }
              else
              {
                v19 = v18 + 1543;
                v31 = 5;
              }
            }
            else
            {
              v19 = v18 + 1380;
              v31 = 4;
            }
          }
          else
          {
            v19 = v18 + 1217;
            v31 = 3;
          }
        }
        else
        {
          v19 = v18 + 1054;
          v31 = 2;
        }
      }
      else
      {
        v19 = v18 + 891;
        v31 = 1;
      }
    }
    else
    {
      v31 = 0;
    }
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Found free slot in TSPEC list. Add to TSPEC table entry: %d",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "lim_tspec_add",
      v31);
    v19[1] = v31;
LABEL_41:
    v32 = a4[2];
    v33 = *a4;
    v34 = a4[1];
    *(_QWORD *)(v19 + 34) = a4[3];
    *(_QWORD *)(v19 + 26) = v32;
    *(_QWORD *)(v19 + 18) = v34;
    *(_QWORD *)(v19 + 10) = v33;
    v36 = a4[5];
    v35 = a4[6];
    v37 = *((_WORD *)a4 + 28);
    v38 = a4[4];
    *((_WORD *)v19 + 4) = v14;
    *((_WORD *)v19 + 33) = v37;
    *(_QWORD *)(v19 + 58) = v35;
    *(_QWORD *)(v19 + 50) = v36;
    *(_QWORD *)(v19 + 42) = v38;
    qdf_mem_copy(v19 + 2, a2, 6u);
    v47 = *(_WORD *)((char *)a4 + 3);
    *v19 = 1;
    *a14 = v19;
    if ( (v47 & 0x180) == 0x80 )
      v48 = "%s: added entry for EDCA AccessPolicy";
    else
      v48 = "%s: added entry for HCCA AccessPolicy";
    qdf_trace_msg(0x35u, 8u, v48, v39, v40, v41, v42, v43, v44, v45, v46, "lim_tspec_add");
    return 0;
  }
}

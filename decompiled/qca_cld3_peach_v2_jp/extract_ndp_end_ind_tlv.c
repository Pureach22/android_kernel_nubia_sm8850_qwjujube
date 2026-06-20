__int64 __fastcall extract_ndp_end_ind_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        __int64 a11)
{
  __int64 v13; // x21
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w4
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  unsigned __int64 v33; // x20
  unsigned int *v34; // x23
  __int64 v35; // x24
  int v36; // w9
  __int64 v37; // x8
  __int64 v38; // [xsp+0h] [xbp-10h]

  if ( *((_DWORD *)a10 + 2) )
  {
    v13 = *a10;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: number of ndp instances = %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_ndp_end_ind_tlv");
    v22 = *((_DWORD *)a10 + 2);
    if ( v22 < 0x9249249 )
    {
      v24 = _qdf_mem_malloc(28LL * v22 + 16, "extract_ndp_end_ind_tlv", 1263);
      *(_QWORD *)a11 = v24;
      if ( v24 )
      {
        *(_DWORD *)(v24 + 8) = *((_DWORD *)a10 + 2);
        if ( *(_DWORD *)(*(_QWORD *)a11 + 8LL) )
        {
          v33 = 0;
          v34 = (unsigned int *)(v13 + 16);
          v35 = 36;
          do
          {
            LODWORD(v38) = v34[3];
            qdf_trace_msg(
              0x31u,
              8u,
              "%s: ind[%d]: type %d, reason_code %d, instance_id %d num_active %d ",
              v25,
              v26,
              v27,
              v28,
              v29,
              v30,
              v31,
              v32,
              "extract_ndp_end_ind_tlv",
              (unsigned int)v33++,
              *(v34 - 3),
              *(v34 - 1),
              *v34,
              v38);
            *(_DWORD *)(*(_QWORD *)a11 + v35) = *v34;
            *(_DWORD *)(*(_QWORD *)a11 + v35 - 24) = *(v34 - 2);
            *(_WORD *)(*(_QWORD *)a11 + v35 - 20) = v34[1];
            *(_BYTE *)(*(_QWORD *)a11 + v35 - 18) = *((_WORD *)v34 + 3);
            *(_BYTE *)(*(_QWORD *)a11 + v35 - 17) = *((_BYTE *)v34 + 7);
            *(_WORD *)(*(_QWORD *)a11 + v35 - 16) = v34[2];
            *(_DWORD *)(*(_QWORD *)a11 + v35 - 12) = v34[3];
            *(_DWORD *)(*(_QWORD *)a11 + v35 - 8) = *(v34 - 3);
            v36 = *(v34 - 1);
            v34 += 8;
            v37 = *(_QWORD *)a11 + v35;
            v35 += 28;
            *(_DWORD *)(v37 - 4) = v36;
          }
          while ( v33 < *(unsigned int *)(*(_QWORD *)a11 + 8LL) );
        }
        return 0;
      }
      else
      {
        return 2;
      }
    }
    else
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: num_ndp_end_ind_list %d too large",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "extract_ndp_end_ind_tlv");
      return 4;
    }
  }
  else
  {
    qdf_trace_msg(
      0x31u,
      2u,
      "%s: Error: Event ignored, 0 ndp instances",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "extract_ndp_end_ind_tlv");
    return 4;
  }
}

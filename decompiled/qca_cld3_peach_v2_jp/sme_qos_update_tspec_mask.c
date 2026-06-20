__int64 __fastcall sme_qos_update_tspec_mask(
        unsigned __int8 a1,
        unsigned __int64 a2,
        __int64 a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned __int64 v12; // x22
  int v13; // w26
  __int16 v15; // w21
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x25
  __int64 v26; // x0
  __int64 v27; // x23
  unsigned int v28; // w26
  __int64 v29; // x25
  __int64 result; // x0
  __int64 v31; // x28
  unsigned __int64 v32; // x8
  unsigned __int8 *v33; // x23
  unsigned int v34; // t1
  const char *v35; // x2
  unsigned int v36; // w1
  __int64 v37; // [xsp+0h] [xbp-10h]

  v12 = HIDWORD(a2);
  v13 = a4;
  v15 = a2;
  qdf_trace_msg(
    0x34u,
    8u,
    "%s: invoked on session %d for AC %d TSPEC %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "sme_qos_update_tspec_mask",
    a1,
    HIDWORD(a2),
    a4);
  if ( (unsigned int)v12 >= 4 )
  {
LABEL_17:
    v35 = "%s: Exceeded the array bounds";
    v36 = 8;
  }
  else
  {
    v25 = qword_856120;
    v26 = csr_ll_peek_head((__int64)&unk_856128, 0, v17, v18, v19, v20, v21, v22, v23, v24);
    if ( v26 )
    {
      v27 = v26;
      v28 = v13 - 1;
      v37 = BYTE4(a3);
      v29 = v25 + 3040LL * a1 + 728LL * (unsigned int)v12 + 4;
      while ( 1 )
      {
        result = csr_ll_next((__int64)&unk_856128, v27, 0, v17, v18, v19, v20, v21, v22, v23, v24);
        if ( *(unsigned __int8 *)(v27 + 16) == (unsigned __int8)v15 )
        {
          if ( (v15 & 0x800) != 0 )
          {
            if ( *(_DWORD *)(v27 + 28) != (_DWORD)v12 || *(_DWORD *)(v27 + 48) != (_DWORD)a3 )
              goto LABEL_5;
            v31 = result;
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Flow %d matches",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "sme_qos_update_tspec_mask",
              *(unsigned int *)(v27 + 24));
            v34 = *(unsigned __int8 *)(v27 + 17);
            v33 = (unsigned __int8 *)(v27 + 17);
            v32 = v34 - 1LL;
            if ( v32 >= 3 )
            {
LABEL_16:
              __break(0x5512u);
              goto LABEL_17;
            }
          }
          else
          {
            if ( (v15 & 0x1000) == 0
              || *(_DWORD *)(v27 + 28) != (_DWORD)v12
              || *(unsigned __int8 *)(v27 + 17) != BYTE4(a3) )
            {
              goto LABEL_5;
            }
            v31 = result;
            qdf_trace_msg(
              0x34u,
              8u,
              "%s: Flow %d matches",
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              v23,
              v24,
              "sme_qos_update_tspec_mask",
              *(unsigned int *)(v27 + 24));
            v32 = *(unsigned __int8 *)(v27 + 17) - 1LL;
            if ( v32 > 2 )
              goto LABEL_16;
            v33 = (unsigned __int8 *)(v27 + 17);
          }
          result = v31;
          --*(_BYTE *)(v29 + v32);
          ++*(_BYTE *)(v29 + v28);
          *v33 = a4;
        }
LABEL_5:
        v27 = result;
        if ( !result )
          return result;
      }
    }
    v35 = "%s: Flow List empty, nothing to update";
    v36 = 2;
  }
  return qdf_trace_msg(0x34u, v36, v35, v17, v18, v19, v20, v21, v22, v23, v24, "sme_qos_update_tspec_mask", v37);
}

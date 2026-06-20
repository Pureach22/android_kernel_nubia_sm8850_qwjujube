__int64 __fastcall lim_update_ext_cap_ie(__int64 a1, const void *a2, char *a3, unsigned __int16 *a4, __int64 a5)
{
  unsigned int updated; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 result; // x0
  size_t v20; // x2
  unsigned int v21; // w8
  bool v22; // cf
  unsigned int v23; // w8
  int v24; // w9
  unsigned int v25; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x8
  __int64 v35; // x8
  unsigned __int16 v36; // w8
  double v37; // d0
  double v38; // d1
  double v39; // d2
  double v40; // d3
  double v41; // d4
  double v42; // d5
  double v43; // d6
  double v44; // d7
  size_t v45; // x2
  unsigned int v46; // w9
  unsigned int v47; // w8
  unsigned __int16 v48; // w8
  size_t n[2]; // [xsp+8h] [xbp-38h] BYREF
  char v50; // [xsp+18h] [xbp-28h]
  _QWORD v51[2]; // [xsp+20h] [xbp-20h] BYREF
  char v52; // [xsp+30h] [xbp-10h]
  __int64 v53; // [xsp+38h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v52 = 0;
  v51[0] = 0;
  v51[1] = 0;
  v50 = 0;
  n[0] = 0;
  n[1] = 0;
  updated = lim_strip_extcap_update_struct(a1, a2, a4, v51);
  if ( !updated )
  {
    v20 = *a4;
    if ( (unsigned int)v20 < 0x7FF )
    {
      qdf_mem_copy(a3, a2, v20);
      a3[*a4] = 127;
      v21 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5748LL);
      v22 = v21 >= 0xE;
      v23 = 0x3F01u >> v21;
      v24 = !v22;
      v25 = populate_dot11f_ext_cap(a1, v24 & v23, n, 0);
      if ( v25 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Failed %d to create ext cap IE. Use default value instead",
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          "lim_update_ext_cap_ie",
          v25);
        a3[*a4 + 1] = 15;
        v34 = *a4;
        if ( (unsigned int)v34 < 0x7F0 )
        {
          v35 = v34 + 2;
          *a4 = v35;
          qdf_mem_copy(&a3[v35], (char *)v51 + 2, 0xFu);
          result = 0;
          v36 = *a4 + 15;
LABEL_16:
          *a4 = v36;
          goto LABEL_17;
        }
      }
      else
      {
        lim_merge_extcap_struct(n, v51, 1);
        if ( a5 )
          populate_dot11f_twt_extended_caps(a1, a5, n);
        else
          qdf_trace_msg(
            0x35u,
            8u,
            "%s: Session NULL, cannot set TWT caps",
            v37,
            v38,
            v39,
            v40,
            v41,
            v42,
            v43,
            v44,
            "lim_update_ext_cap_ie");
        v45 = BYTE1(n[0]);
        v46 = 2046 - BYTE1(n[0]);
        a3[*a4 + 1] = BYTE1(n[0]);
        v47 = *a4;
        if ( v46 >= v47 )
        {
          v48 = v47 + 2;
          *a4 = v48;
          qdf_mem_copy(&a3[v48], (char *)n + 2, v45);
          result = 0;
          v36 = *a4 + BYTE1(n[0]);
          goto LABEL_16;
        }
      }
    }
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Invalid Scan IE length",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "lim_update_ext_cap_ie");
    result = 16;
    goto LABEL_17;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Strip ext cap fails %d",
    v11,
    v12,
    v13,
    v14,
    v15,
    v16,
    v17,
    v18,
    "lim_update_ext_cap_ie",
    updated);
  result = 16;
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}

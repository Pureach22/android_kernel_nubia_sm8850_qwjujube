__int64 __fastcall wlan_defrag_elemsubelem_fragseq(
        char a1,
        char a2,
        unsigned int a3,
        unsigned __int8 *a4,
        __int64 a5,
        void *a6,
        unsigned __int64 a7,
        _QWORD *a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  unsigned __int8 v16; // w25
  __int64 result; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char v33; // w8
  __int64 v34; // x20
  const char *v35; // x2
  const char *v36; // x2
  __int64 v37; // x20
  unsigned __int8 *v38; // x10
  __int64 v39; // x9
  __int64 v40; // x11
  __int64 v41; // x19
  unsigned __int8 *v42; // x1
  __int64 v43; // x23
  unsigned __int8 *v44; // x20
  _QWORD *v45; // x9
  __int64 v46; // x21
  unsigned __int8 *v47; // x22
  size_t v48; // x23
  const void *v49; // x1
  unsigned __int64 v50; // [xsp+0h] [xbp-20h] BYREF
  __int64 v51; // [xsp+8h] [xbp-18h] BYREF
  char v52[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v53; // [xsp+18h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
    v16 = a3;
  else
    v16 = -14;
  v52[0] = 0;
  v50 = 0;
  v51 = 0;
  if ( !a4 )
  {
    v35 = "Src buff for frag seq is NULL";
LABEL_21:
    qdf_trace_msg(0x38u, 2u, v35, a9, a10, a11, a12, a13, a14, a15, a16, v50, v51);
    result = 29;
    goto LABEL_22;
  }
  if ( !a5 )
  {
    v36 = "Size of src buff for frag seq is 0";
LABEL_18:
    qdf_trace_msg(0x38u, 2u, v36, a9, a10, a11, a12, a13, a14, a15, a16, v50, v51);
    result = 4;
    goto LABEL_22;
  }
  if ( (a1 & 1) == 0 )
  {
    if ( !a6 )
    {
      v35 = "Dest buff for defragged payload is NULL";
      goto LABEL_21;
    }
    if ( !a7 )
    {
      v36 = "Size of dest buff for defragged payload is 0";
      goto LABEL_18;
    }
  }
  if ( !a8 )
  {
    v35 = "Ptr to len of defragged payload is NULL";
    goto LABEL_21;
  }
  result = wlan_get_elemsubelem_fragseq_info(
             a2 & 1,
             a9,
             a10,
             a11,
             a12,
             a13,
             a14,
             a15,
             a16,
             a3,
             (__int64)a4,
             a5,
             v52,
             &v51,
             &v50);
  if ( !(_DWORD)result )
  {
    if ( (v52[0] & 1) == 0 )
    {
      v37 = jiffies;
      if ( wlan_defrag_elemsubelem_fragseq___last_ticks_45 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "Frag seq not found at start of src buff for frag seq",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32);
        wlan_defrag_elemsubelem_fragseq___last_ticks_45 = v37;
        result = 4;
        goto LABEL_22;
      }
      goto LABEL_25;
    }
    v33 = a1;
    if ( (a1 & 1) == 0 && v50 > a7 )
    {
      v34 = jiffies;
      if ( wlan_defrag_elemsubelem_fragseq___last_ticks_47 - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x38u,
          2u,
          "(Size of dest buff for defragged payload %zu) < (size of frag seq payload %zu)",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          a7);
        wlan_defrag_elemsubelem_fragseq___last_ticks_47 = v34;
        result = 4;
        goto LABEL_22;
      }
LABEL_25:
      result = 4;
      goto LABEL_22;
    }
    v38 = a4;
    if ( (a2 & 1) == 0 && *a4 == 255 )
    {
      v39 = a4[1];
      v40 = 3;
      v41 = v39 - 1;
    }
    else
    {
      v39 = a4[1];
      v40 = 2;
      v41 = v39;
    }
    v42 = &a4[v40];
    v43 = v39 + 2;
    if ( (a1 & 1) == 0 )
    {
      qdf_mem_copy(a6, v42, (unsigned int)v41);
      v38 = a4;
      v42 = (unsigned __int8 *)a6;
      v33 = a1;
    }
    v44 = &v38[v43];
    v45 = a8;
    v46 = a5 - v43;
    v47 = &v42[v41];
    if ( v38[v43] == v16 )
    {
      while ( 1 )
      {
        v48 = v44[1];
        v49 = v44 + 2;
        if ( (v33 & 1) != 0 )
          qdf_mem_move(v47, v49, v48);
        else
          qdf_mem_copy(v47, v49, v48);
        v41 += v48;
        v45 = a8;
        v46 -= v48 + 2;
        if ( !v46 )
          break;
        v44 += v48 + 2;
        v47 += v48;
        v33 = a1;
        if ( *v44 != v16 )
          goto LABEL_37;
      }
    }
    else
    {
LABEL_37:
      if ( (v33 & 1) != 0 && v46 )
      {
        qdf_mem_move(v47, v44, (unsigned int)v46);
        v45 = a8;
      }
    }
    result = 0;
    *v45 = v41;
  }
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}

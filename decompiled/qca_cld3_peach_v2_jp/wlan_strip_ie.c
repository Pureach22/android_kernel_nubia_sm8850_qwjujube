__int64 __fastcall wlan_strip_ie(
        unsigned __int8 *a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        int a4,
        const void *a5,
        unsigned __int8 a6,
        char *a7,
        int a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        double a15,
        double a16)
{
  size_t v16; // x25
  __int64 v24; // x0
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  char *v33; // x19
  unsigned __int16 v34; // w28
  __int64 v36; // x27
  unsigned __int16 v37; // w20
  int v38; // w8
  unsigned __int8 *v39; // x26
  int v40; // w22
  char *v41; // x0
  size_t v42; // x2
  int v43; // w5
  int v44; // w8
  int v45; // w6
  __int64 v46; // x4
  unsigned __int16 v47; // w21
  int v48; // [xsp+Ch] [xbp-24h]
  unsigned __int8 *v49; // [xsp+10h] [xbp-20h]
  unsigned __int8 v51; // [xsp+20h] [xbp-10h]
  char *v52; // [xsp+28h] [xbp-8h]

  if ( !a1 )
  {
    qdf_trace_msg(0x68u, 8u, "%s: NULL addn_ie pointer", a9, a10, a11, a12, a13, a14, a15, a16, "wlan_strip_ie");
    return 4;
  }
  v16 = *a2;
  if ( !*a2 )
    return 4;
  v24 = _qdf_mem_malloc(v16, "wlan_strip_ie", 5002);
  if ( !v24 )
    return 2;
  v33 = (char *)v24;
  if ( a7 )
    qdf_mem_set(a7, (unsigned int)(a4 + a8 + 1), 0);
  v49 = a1;
  if ( (_DWORD)v16 != 1 )
  {
    v51 = a6;
    v52 = a7;
    v36 = (unsigned int)(a4 + 1);
    v37 = 0;
    v38 = v36 + a8;
    v39 = v49;
    v34 = 0;
    v40 = a3;
    v48 = v38;
    while ( 1 )
    {
      if ( a4 == 2 )
      {
        v43 = *(unsigned __int16 *)(v39 + 1);
        v44 = -3;
      }
      else
      {
        v43 = v39[1];
        v44 = -2;
      }
      v45 = v16 + v44;
      v46 = *v39;
      LODWORD(v16) = v16 + v44 - v43;
      if ( v45 < v43 )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: Invalid IEs eid: %d elem_len: %d left: %d",
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          v31,
          v32,
          "wlan_strip_ie",
          v46);
        _qdf_mem_free((__int64)v33);
        return 16;
      }
      v47 = a4 + 1 + v43;
      if ( (_DWORD)v46 != v40 || a5 && (unsigned int)qdf_mem_cmp(a5, &v39[v36], v51) )
      {
        v41 = &v33[v34];
        v42 = v47;
      }
      else
      {
        if ( !v52 )
          goto LABEL_16;
        v42 = v47;
        if ( v48 - (unsigned int)v37 >= v47 )
        {
          qdf_mem_copy(&v52[v37], v39, v47);
          v37 += v47;
          goto LABEL_16;
        }
        v41 = &v33[v34];
      }
      qdf_mem_copy(v41, v39, v42);
      v34 += v47;
LABEL_16:
      v39 += v47;
      if ( (int)v16 <= 1 )
        goto LABEL_8;
    }
  }
  v34 = 0;
LABEL_8:
  qdf_mem_copy(v49, v33, v34);
  *a2 = v34;
  _qdf_mem_free((__int64)v33);
  return 0;
}

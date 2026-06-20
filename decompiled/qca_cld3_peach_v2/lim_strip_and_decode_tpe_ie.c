unsigned __int8 *__fastcall lim_strip_and_decode_tpe_ie(unsigned __int8 *a1, unsigned __int16 a2, __int64 a3)
{
  __int16 v3; // w22
  unsigned __int8 *result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int16 v15; // w22
  unsigned __int8 *ie_ptr_from_eid; // x20
  unsigned __int64 v17; // x23
  char *v18; // x19
  unsigned __int8 v19; // w27
  unsigned int v20; // w8
  unsigned int v21; // w9
  size_t v22; // x2
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  __int64 v31; // x10
  unsigned int v32; // w11
  unsigned __int8 *v33; // x8
  size_t v34; // x2
  const void *v35; // x1
  char *v36; // x0
  int v37; // w8
  unsigned __int8 v38; // w8
  bool v39; // cf

  v3 = (__int16)a1;
  result = wlan_get_ie_ptr_from_eid(0xC3u, a1, a2);
  if ( !result )
    return result;
  v15 = v3 + a2;
  ie_ptr_from_eid = result;
  v17 = 0;
  v18 = (char *)(a3 + 12);
  while ( *ie_ptr_from_eid == 195 )
  {
    v19 = ie_ptr_from_eid[1];
    if ( !v19 )
      break;
    qdf_mem_set(v18 - 12, 0x1Bu, 0);
    v20 = ie_ptr_from_eid[2];
    *(v18 - 12) = 1;
    v21 = (v20 >> 3) & 7;
    *(v18 - 11) = v20;
    if ( v21 <= 4 && ((1 << v21) & 0x15) != 0 )
    {
      v22 = (v20 & 7) + 1;
    }
    else
    {
      v37 = v20 & 7;
      if ( !v37 )
      {
        *(v18 - 10) = 0;
        v36 = v18 - 9;
        v35 = ie_ptr_from_eid + 3;
        v34 = 1;
        goto LABEL_21;
      }
      v22 = (unsigned __int8)(1 << (v37 - 1));
    }
    *(v18 - 10) = v22;
    qdf_mem_copy(v18 - 9, ie_ptr_from_eid + 3, v22);
    v31 = (unsigned __int8)*(v18 - 10);
    if ( !(v19 + ~(_BYTE)v31) )
      goto LABEL_22;
    v32 = ((unsigned __int8)*(v18 - 11) >> 3) & 7;
    v33 = &ie_ptr_from_eid[v31 + 3];
    if ( v32 > 2 )
    {
      if ( v32 != 3 )
      {
        if ( v32 == 4 )
        {
LABEL_19:
          v38 = *v33;
          *(v18 - 10) = v31 + 1;
          *(v18 - 1) = v38;
          goto LABEL_22;
        }
        if ( v32 != 5 )
          goto LABEL_22;
      }
    }
    else if ( v32 != 1 )
    {
      goto LABEL_19;
    }
    v34 = *v33 & 0xF;
    *(v18 - 1) = *(v18 - 1) & 0xF0 | *v33 & 0xF;
    if ( (unsigned int)v34 > (unsigned __int8)(v19 + ~(_BYTE)v31 - 1) )
      goto LABEL_27;
    v35 = v33 + 1;
    v36 = v18;
LABEL_21:
    qdf_mem_copy(v36, v35, v34);
LABEL_22:
    ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(
                        0xC3u,
                        &ie_ptr_from_eid[ie_ptr_from_eid[1] + 2],
                        v15 - ((unsigned __int16)ie_ptr_from_eid + 2 + ie_ptr_from_eid[1]));
    result = nullptr;
    if ( ie_ptr_from_eid )
    {
      v39 = v17++ >= 7;
      v18 += 27;
      if ( !v39 )
        continue;
    }
    return result;
  }
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Invalid TPE IE or IE len is 0",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "lim_ieee80211_unpack_tpe");
LABEL_27:
  qdf_trace_msg(
    0x35u,
    2u,
    "%s: Failed to extract TPE IE",
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    v30,
    "lim_strip_and_decode_tpe_ie");
  return (unsigned __int8 *)&off_10;
}

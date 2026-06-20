__int64 __fastcall wlan_parse_ftie_sha384(unsigned __int8 *a1, unsigned __int16 a2, __int64 a3)
{
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  __int64 v13; // x20
  const char *v14; // x2
  __int64 v15; // x4
  const char *v16; // x2
  __int64 result; // x0
  unsigned __int8 *v18; // x21
  char *v19; // x8
  unsigned __int8 v20; // w25
  size_t v21; // x22
  __int64 v22; // x4
  char *v23; // x23
  void *v24; // x0
  __int64 v25; // x0
  void *v26; // x0
  void *v27; // x0
  __int64 v28; // x0
  void *v29; // x0

  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0x37u, a1, a2);
  if ( !ie_ptr_from_eid )
  {
    v16 = "%s: FT IE not present";
LABEL_8:
    qdf_trace_msg(0x35u, 2u, v16, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_parse_ftie_sha384");
    return 16;
  }
  v13 = ie_ptr_from_eid[1];
  if ( !ie_ptr_from_eid[1] )
  {
    v16 = "%s: FT IE length is zero";
    goto LABEL_8;
  }
  if ( (unsigned int)v13 <= 0x59 )
  {
    v14 = "%s: Invalid FTIE len:%d";
    v15 = ie_ptr_from_eid[1];
    goto LABEL_5;
  }
  v18 = ie_ptr_from_eid;
  qdf_mem_copy((void *)(a3 + 582), ie_ptr_from_eid + 2, 0x5Au);
  qdf_mem_set((void *)(a3 + 672), 0x58u, 0);
  result = 0;
  if ( (unsigned int)v13 < 0x5E )
    return result;
  v19 = (char *)(v18 + 92);
  v20 = v13 - 90;
  while ( 1 )
  {
    v21 = (unsigned __int8)v19[1];
    if ( !v19[1] || (int)v21 + 2 > (unsigned int)v20 )
    {
      v16 = "%s: Invalid FT subelem length";
      goto LABEL_8;
    }
    v22 = (unsigned __int8)*v19;
    v23 = v19 + 2;
    if ( (unsigned __int8)*v19 <= 2u )
    {
      if ( (_DWORD)v22 == 1 )
      {
        if ( (_DWORD)v21 != 6 )
        {
          v14 = "%s: Invalid R1KH-ID length: %d";
          goto LABEL_38;
        }
        *(_BYTE *)(a3 + 672) = 1;
        qdf_mem_copy((void *)(a3 + 673), v19 + 2, 6u);
      }
      else
      {
        if ( (_DWORD)v22 != 2 )
          goto LABEL_13;
        v24 = *(void **)(a3 + 680);
        if ( v24 )
        {
          qdf_mem_set(v24, *(unsigned __int8 *)(a3 + 688), 0);
          v25 = *(_QWORD *)(a3 + 680);
          *(_BYTE *)(a3 + 688) = 0;
          _qdf_mem_free(v25);
        }
        v26 = (void *)_qdf_mem_malloc(v21, "wlan_parse_ftie_sha384", 4222);
        *(_QWORD *)(a3 + 680) = v26;
        if ( !v26 )
          return 2;
        qdf_mem_copy(v26, v23, (unsigned int)v21);
        *(_BYTE *)(a3 + 688) = v21;
      }
      goto LABEL_14;
    }
    if ( (_DWORD)v22 == 3 )
      break;
    if ( (_DWORD)v22 != 4 )
    {
LABEL_13:
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: Unknown subelem id %d len:%d",
        v5,
        v6,
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        "wlan_parse_ftie_sha384",
        v22,
        (unsigned __int8)v19[1]);
      goto LABEL_14;
    }
    v27 = *(void **)(a3 + 744);
    if ( v27 )
    {
      qdf_mem_set(v27, *(unsigned __int8 *)(a3 + 752), 0);
      v28 = *(_QWORD *)(a3 + 744);
      *(_BYTE *)(a3 + 752) = 0;
      _qdf_mem_free(v28);
    }
    v29 = (void *)_qdf_mem_malloc(v21, "wlan_parse_ftie_sha384", 4247);
    *(_QWORD *)(a3 + 744) = v29;
    if ( !v29 )
      return 2;
    qdf_mem_copy(v29, v23, (unsigned int)v21);
    *(_BYTE *)(a3 + 752) = v21;
LABEL_14:
    v19 = &v23[v21];
    result = 0;
    v20 -= v21 + 2;
    if ( &v18[v13] - (unsigned __int8 *)&v23[v21] <= 1 )
      return result;
  }
  if ( (unsigned int)v21 < 0x31 )
  {
    *(_BYTE *)(a3 + 689) = 1;
    *(_BYTE *)(a3 + 690) = v21;
    qdf_mem_copy((void *)(a3 + 691), v19 + 2, (unsigned int)v21);
    goto LABEL_14;
  }
  v14 = "%s: Invalid R0KH-ID length: %d";
LABEL_38:
  v15 = (unsigned __int8)v19[1];
LABEL_5:
  qdf_trace_msg(0x35u, 2u, v14, v5, v6, v7, v8, v9, v10, v11, v12, "wlan_parse_ftie_sha384", v15);
  return 16;
}

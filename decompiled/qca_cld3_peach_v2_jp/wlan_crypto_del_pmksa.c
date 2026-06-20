__int64 __fastcall wlan_crypto_del_pmksa(
        __int64 a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x19
  unsigned __int8 v12; // w21
  __int64 v13; // x22
  __int64 v14; // x8
  __int64 result; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 i; // x19
  __int64 v26; // x8
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  _QWORD v35[9]; // [xsp+8h] [xbp-48h] BYREF

  v11 = 0;
  v12 = 0;
  v13 = a1 + 24;
  v35[8] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v35, 0, 64);
  while ( 1 )
  {
    v14 = *(_QWORD *)(v13 + 8 * v11);
    if ( !v14 )
      goto LABEL_2;
    ++v12;
    if ( *(_BYTE *)(a2 + 87) )
      break;
    if ( *(_DWORD *)a2 | *(unsigned __int16 *)(a2 + 4) )
    {
      if ( *(_DWORD *)a2 == *(_DWORD *)v14 && *(unsigned __int16 *)(a2 + 4) == *(unsigned __int16 *)(v14 + 4) )
        goto LABEL_16;
    }
LABEL_2:
    if ( ++v11 == 16 )
    {
      result = qdf_trace_msg(
                 0x1Cu,
                 8u,
                 "%s: No such pmksa entry exists: valid entries:%d",
                 a3,
                 a4,
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 "wlan_crypto_del_pmksa",
                 v12);
      goto LABEL_23;
    }
  }
  if ( (unsigned int)qdf_mem_cmp((const void *)(a2 + 88), (const void *)(v14 + 88), *(unsigned __int8 *)(a2 + 87))
    || (unsigned int)qdf_mem_cmp((const void *)(a2 + 120), (const void *)(*(_QWORD *)(v13 + 8 * v11) + 120LL), 2u) )
  {
    goto LABEL_2;
  }
  v14 = *(_QWORD *)(v13 + 8 * v11);
LABEL_16:
  qdf_mem_copy(v35, (const void *)(v14 + 22), *(unsigned __int8 *)(v14 + 86));
  qdf_mem_set(*(void **)(v13 + 8 * v11), 0x98u, 0);
  _qdf_mem_free(*(_QWORD *)(v13 + 8 * v11));
  *(_QWORD *)(v13 + 8 * v11) = 0;
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: PMKSA: Deleted PMKSA entry at index=%d",
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    "wlan_crypto_del_pmksa",
    (unsigned int)v11);
  for ( i = 0; i != 16; ++i )
  {
    v26 = *(_QWORD *)(v13 + 8 * i);
    if ( v26
      && *(_BYTE *)(v26 + 86)
      && !(unsigned int)qdf_mem_cmp((const void *)(v26 + 22), v35, *(unsigned __int8 *)(v26 + 86)) )
    {
      qdf_mem_set(*(void **)(v13 + 8 * i), 0x98u, 0);
      _qdf_mem_free(*(_QWORD *)(v13 + 8 * i));
      *(_QWORD *)(v13 + 8 * i) = 0;
      qdf_trace_msg(
        0x1Cu,
        8u,
        "%s: PMKSA: Deleted PMKSA at idx=%d",
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        "wlan_crypto_del_pmksa",
        (unsigned int)i);
    }
  }
  result = (__int64)qdf_mem_set(v35, 0x40u, 0);
LABEL_23:
  _ReadStatusReg(SP_EL0);
  return result;
}

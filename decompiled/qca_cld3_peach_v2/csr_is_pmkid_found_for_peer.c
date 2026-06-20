__int64 __fastcall csr_is_pmkid_found_for_peer(__int64 a1, unsigned __int8 *a2, const void *a3, char *a4, __int16 a5)
{
  __int64 v8; // x21
  void *v10; // x0
  __int64 v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w20

  LOWORD(v8) = a5;
  v10 = (void *)_qdf_mem_malloc(0x98u, "csr_is_pmkid_found_for_peer", 1112);
  if ( !v10 )
    return 0;
  v11 = (__int64)v10;
  qdf_mem_copy(v10, a3, 6u);
  if ( (cm_lookup_pmkid_using_bssid(*(_QWORD *)(a1 + 21624), *a2, v11) & 1) != 0 )
  {
    if ( (_WORD)v8 )
    {
      v8 = (unsigned __int16)v8;
      while ( (unsigned int)qdf_mem_cmp(a4, (const void *)(v11 + 6), 0x10u) )
      {
        --v8;
        a4 += 16;
        if ( !v8 )
          goto LABEL_7;
      }
      v20 = 1;
      goto LABEL_9;
    }
LABEL_7:
    qdf_trace_msg(
      0x34u,
      8u,
      "%s: PMKID in PmkidCacheInfo doesn't match with PMKIDs of peer",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "csr_is_pmkid_found_for_peer");
  }
  v20 = 0;
LABEL_9:
  _qdf_mem_free(v11);
  return v20;
}

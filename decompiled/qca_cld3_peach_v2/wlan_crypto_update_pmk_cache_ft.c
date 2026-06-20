__int64 __fastcall wlan_crypto_update_pmk_cache_ft(
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
  __int64 comp_private_obj; // x0
  __int64 v12; // x20
  __int64 v13; // x23
  unsigned int v14; // w22
  const char *v15; // x2
  __int64 v16; // x27
  bool v17; // zf
  int v18; // w26
  int v19; // w28
  const char *v20; // x2

  if ( !a2 )
  {
    v20 = "%s: pmksa is NULL for set operation";
LABEL_21:
    qdf_trace_msg(0x1Cu, 2u, v20, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_update_pmk_cache_ft");
    return 4;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    v20 = "%s: crypto_priv NULL";
    goto LABEL_21;
  }
  if ( *(_BYTE *)(a2 + 146) )
  {
    v12 = 0;
    v13 = comp_private_obj + 24;
    v14 = 4;
    while ( 1 )
    {
      v16 = *(_QWORD *)(v13 + 8 * v12);
      if ( v16 )
      {
        v17 = *(_DWORD *)v16 == *(_DWORD *)a2 && *(unsigned __int16 *)(v16 + 4) == *(unsigned __int16 *)(a2 + 4);
        if ( v17
          || (v18 = *(unsigned __int8 *)(v16 + 146), v19 = *(unsigned __int16 *)(v16 + 148), *(_BYTE *)(a2 + 87))
          && !(unsigned int)qdf_mem_cmp(
                              (const void *)(a2 + 88),
                              (const void *)(v16 + 88),
                              *(unsigned __int8 *)(a2 + 87))
          && !(unsigned int)qdf_mem_cmp((const void *)(a2 + 120), (const void *)(v16 + 120), 2u) )
        {
          *(_BYTE *)(v16 + 146) = 1;
          v15 = "%s: Updated the MDID at index=%d";
          *(_WORD *)(v16 + 148) = *(_WORD *)(a2 + 148);
        }
        else
        {
          if ( !v18 || *(unsigned __int16 *)(a2 + 148) != v19 )
            goto LABEL_7;
          qdf_mem_set(*(void **)(v13 + 8 * v12), 0x98u, 0);
          _qdf_mem_free(*(_QWORD *)(v13 + 8 * v12));
          v15 = "%s: Deleted PMKSA at index=%d";
          *(_QWORD *)(v13 + 8 * v12) = 0;
        }
        qdf_trace_msg(
          0x1Cu,
          8u,
          v15,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          "wlan_crypto_update_pmk_cache_ft",
          (unsigned int)v12);
        v14 = 0;
      }
LABEL_7:
      if ( ++v12 == 16 )
        return v14;
    }
  }
  return 4;
}

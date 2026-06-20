__int64 __fastcall wlan_crypto_get_pmksa(
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
  __int64 v13; // x21
  int *v14; // x8
  int v15; // w10
  int v16; // w8
  const char *v19; // x2

  if ( a2 )
  {
    comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
    if ( comp_private_obj )
    {
      v12 = 0;
      v13 = comp_private_obj + 24;
      while ( 1 )
      {
        v14 = *(int **)(v13 + 8 * v12);
        if ( v14 )
        {
          v15 = *v14;
          v16 = *((unsigned __int16 *)v14 + 2);
          if ( *(_DWORD *)a2 == v15 && *(unsigned __int16 *)(a2 + 4) == v16 )
            break;
        }
        if ( ++v12 == 16 )
          return 0;
      }
      qdf_trace_msg(
        0x1Cu,
        8u,
        "%s: PMKSA: Entry found at index %d",
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        "wlan_crypto_get_pmksa",
        (unsigned int)v12);
      return *(_QWORD *)(v13 + 8 * v12);
    }
    v19 = "%s: crypto_priv NULL";
  }
  else
  {
    v19 = "%s: bssid is NULL";
  }
  qdf_trace_msg(0x1Cu, 2u, v19, a3, a4, a5, a6, a7, a8, a9, a10, "wlan_crypto_get_pmksa");
  return 0;
}

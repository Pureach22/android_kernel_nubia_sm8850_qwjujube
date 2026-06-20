__int64 __fastcall wlan_crypto_set_del_pmksa(
        __int64 a1,
        __int64 a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x29
  __int64 v12; // x30
  const char *v14; // x2
  __int64 comp_private_obj; // x0
  _QWORD *v19; // x19
  __int64 v20; // x0
  __int64 v21; // x20
  __int64 pmksa; // x0
  size_t v23; // x2
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x9
  const char *v33; // x3
  __int64 v34; // x20
  __int64 v35; // x19
  void *v36; // x0
  unsigned int v37; // w4
  __int64 v38; // [xsp+8h] [xbp-28h]

  if ( *(_DWORD *)(a1 + 16) > 3u )
    return 11;
  v38 = v12;
  if ( !a2 && (a3 & 1) != 0 )
  {
    v14 = "%s: pmksa is NULL for set operation";
LABEL_30:
    v33 = "wlan_crypto_set_del_pmksa";
    goto LABEL_31;
  }
  comp_private_obj = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !comp_private_obj )
  {
    v14 = "%s: crypto_priv NULL";
    goto LABEL_30;
  }
  v19 = (_QWORD *)comp_private_obj;
  if ( (a3 & 1) == 0 )
  {
    if ( a2 )
    {
      wlan_crypto_del_pmksa(comp_private_obj, a2);
    }
    else
    {
      v34 = 0;
      v35 = comp_private_obj + 24;
      do
      {
        v36 = *(void **)(v35 + v34);
        if ( v36 )
        {
          qdf_mem_set(v36, 0x98u, 0);
          _qdf_mem_free(*(_QWORD *)(v35 + v34));
          *(_QWORD *)(v35 + v34) = 0;
        }
        v34 += 8;
      }
      while ( v34 != 128 );
      qdf_trace_msg(
        0x1Cu,
        8u,
        "%s: Flushed the pmksa table",
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        "wlan_crypto_pmksa_flush",
        v11,
        v38);
    }
    return 0;
  }
  v20 = a1;
  v21 = a2;
  pmksa = wlan_crypto_get_pmksa(v20, a2);
  if ( pmksa )
  {
    v23 = *(unsigned __int8 *)(a2 + 86);
    if ( *(_BYTE *)(a2 + 86) )
    {
      if ( (_DWORD)v23 == *(unsigned __int8 *)(pmksa + 86) )
      {
        v21 = a2;
        if ( !(unsigned int)qdf_mem_cmp((const void *)(pmksa + 22), (const void *)(a2 + 22), v23) )
        {
          qdf_trace_msg(
            0x1Cu,
            8u,
            "%s: PMKSA entry found with same PMK",
            v24,
            v25,
            v26,
            v27,
            v28,
            v29,
            v30,
            v31,
            "wlan_crypto_set_del_pmksa",
            v11,
            v38);
          return 14;
        }
      }
    }
  }
  wlan_crypto_del_pmksa(v19, v21);
  if ( v19[3] )
  {
    v32 = a2;
    if ( !v19[4] )
    {
      v37 = 1;
      goto LABEL_56;
    }
    if ( !v19[5] )
    {
      v37 = 2;
      goto LABEL_56;
    }
    if ( !v19[6] )
    {
      v37 = 3;
      goto LABEL_56;
    }
    if ( !v19[7] )
    {
      v37 = 4;
      goto LABEL_56;
    }
    if ( !v19[8] )
    {
      v37 = 5;
      goto LABEL_56;
    }
    if ( !v19[9] )
    {
      v37 = 6;
      goto LABEL_56;
    }
    if ( !v19[10] )
    {
      v37 = 7;
      goto LABEL_56;
    }
    if ( !v19[11] )
    {
      v37 = 8;
      goto LABEL_56;
    }
    if ( !v19[12] )
    {
      v37 = 9;
      goto LABEL_56;
    }
    if ( !v19[13] )
    {
      v37 = 10;
      goto LABEL_56;
    }
    if ( !v19[14] )
    {
      v37 = 11;
      goto LABEL_56;
    }
    if ( !v19[15] )
    {
      v37 = 12;
      goto LABEL_56;
    }
    if ( !v19[16] )
    {
      v37 = 13;
      goto LABEL_56;
    }
    if ( !v19[17] )
    {
      v37 = 14;
      goto LABEL_56;
    }
    if ( v19[18] )
    {
      v14 = "%s: no entry available for pmksa";
      v33 = "wlan_crypto_set_pmksa";
LABEL_31:
      qdf_trace_msg(0x1Cu, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, v33, v11, v38);
      return 4;
    }
    v37 = 15;
  }
  else
  {
    v37 = 0;
  }
  v32 = a2;
LABEL_56:
  v19[v37 + 3] = v32;
  qdf_trace_msg(
    0x1Cu,
    8u,
    "%s: PMKSA: Added the PMKSA entry at index=%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "wlan_crypto_set_pmksa",
    v11,
    v38);
  return 0;
}

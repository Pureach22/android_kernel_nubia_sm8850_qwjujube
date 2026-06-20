__int64 __fastcall os_if_spectral_prep_skb(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  const char *v12; // x2
  __int64 v13; // x4
  const char *v14; // x2
  __int64 comp_private_obj; // x0
  __int64 v18; // x21
  __int64 v19; // x8
  _DWORD *v20; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  __int64 v29; // x2
  int v30; // w8
  int v31; // w9
  _DWORD *v32; // x20
  int v33; // w8
  _DWORD *v34; // x19

  if ( a1 )
  {
    if ( a2 >= 3 )
    {
      v12 = "%s: Invalid Spectral message type %u";
LABEL_4:
      v13 = a2;
LABEL_9:
      qdf_trace_msg(0x48u, 2u, v12, a4, a5, a6, a7, a8, a9, a10, a11, "os_if_spectral_prep_skb", v13);
      return 0;
    }
    if ( a3 >= 2 )
    {
      v12 = "%s: Invalid Spectral message buffer type %u";
      v13 = a3;
      goto LABEL_9;
    }
    comp_private_obj = wlan_objmgr_pdev_get_comp_private_obj(a1, 0x13u);
    if ( comp_private_obj )
    {
      v18 = comp_private_obj + 24;
      if ( a3 )
      {
        v19 = *(_QWORD *)(v18 + 8LL * a2);
        if ( v19 )
          return *(_QWORD *)(v19 + 224) + 16LL;
        v12 = "%s: skb is not allocated for msg_type: %d";
        goto LABEL_4;
      }
      v20 = (_DWORD *)_qdf_nbuf_alloc(0, 3028, 0, 0, 0, "os_if_spectral_prep_skb", 287);
      *(_QWORD *)(v18 + 8LL * a2) = v20;
      if ( !v20 )
      {
        qdf_trace_msg(
          0x48u,
          2u,
          "%s: alloc skb (len=%u, msg_type=%u) failed",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "os_if_spectral_prep_skb",
          3028,
          a2);
        return 0;
      }
      if ( v20[29] )
      {
        v29 = 3028;
      }
      else
      {
        v31 = v20[52];
        v30 = v20[53];
        if ( (unsigned int)(v30 - v31) > 0xBD3 )
          goto LABEL_25;
        v29 = (unsigned int)(v31 - v30 + 3028);
      }
      v32 = v20;
      v33 = pskb_expand_head(v20, 0, v29, 2080);
      v20 = v32;
      if ( v33 )
      {
        dev_kfree_skb_any_reason(v32, 1);
        goto LABEL_26;
      }
LABEL_25:
      skb_put(v20, 3028);
LABEL_26:
      v34 = *(_DWORD **)(*(_QWORD *)(v18 + 8LL * a2) + 224LL);
      qdf_mem_set(v34, 0x10u, 0);
      v34[3] = 0;
      *(_QWORD *)v34 = 0x1D00000700LL;
      v34 += 4;
      qdf_mem_set(v34, 0x6EDu, 0);
      return (__int64)v34;
    }
    v14 = "%s: PDEV SPECTRAL object is NULL!";
  }
  else
  {
    v14 = "%s: PDEV is NULL!";
  }
  qdf_trace_msg(0x48u, 2u, v14, a4, a5, a6, a7, a8, a9, a10, a11, "os_if_spectral_prep_skb");
  return 0;
}

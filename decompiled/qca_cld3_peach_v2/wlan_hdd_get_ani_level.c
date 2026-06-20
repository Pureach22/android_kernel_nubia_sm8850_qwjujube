__int64 __fastcall wlan_hdd_get_ani_level(
        __int64 a1,
        void *a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x23
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x19
  __int64 v26; // x0
  unsigned int ani_level; // w0
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned int v36; // w21
  const char *v37; // x2
  unsigned int v38; // w1
  double v39; // d0
  double v40; // d1
  double v41; // d2
  double v42; // d3
  double v43; // d4
  double v44; // d5
  double v45; // d6
  double v46; // d7
  __int64 v47; // x0

  v12 = *(_QWORD *)(a1 + 24);
  if ( v12 )
  {
    v16 = osif_request_alloc(&wlan_hdd_get_ani_level_params);
    if ( v16 )
    {
      v25 = v16;
      v26 = osif_request_cookie(v16);
      ani_level = sme_get_ani_level(*(_QWORD *)(v12 + 16), a3, a4, hdd_get_ani_level_cb, v26);
      if ( ani_level )
      {
        v36 = ani_level;
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Unable to retrieve ani level",
          v28,
          v29,
          v30,
          v31,
          v32,
          v33,
          v34,
          v35,
          "wlan_hdd_get_ani_level");
      }
      else if ( (unsigned int)osif_request_wait_for_response(v25) )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: SME timed out while retrieving ANI level",
          v39,
          v40,
          v41,
          v42,
          v43,
          v44,
          v45,
          v46,
          "wlan_hdd_get_ani_level");
        v36 = 15;
      }
      else
      {
        v47 = osif_request_priv(v25);
        qdf_mem_copy(a2, *(const void **)(v47 + 8), (unsigned int)(8 * *(_DWORD *)v47));
        v36 = 0;
      }
      osif_request_put(v25);
      v37 = "%s: exit";
      v38 = 8;
    }
    else
    {
      v37 = "%s: Request allocation failure";
      v38 = 2;
      v36 = 2;
    }
    qdf_trace_msg(0x33u, v38, v37, v17, v18, v19, v20, v21, v22, v23, v24, "wlan_hdd_get_ani_level");
  }
  else
  {
    qdf_trace_msg(0x33u, 2u, "%s: Invalid HDD context", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_get_ani_level");
    return 4;
  }
  return v36;
}

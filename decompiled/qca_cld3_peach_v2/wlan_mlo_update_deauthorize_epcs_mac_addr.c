__int64 __fastcall wlan_mlo_update_deauthorize_epcs_mac_addr(
        __int64 a1,
        unsigned __int8 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x21
  __int64 v12; // x22
  char *v13; // x20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x4
  __int64 v23; // x5
  __int64 v24; // x6
  __int64 v25; // x7
  double v27; // d0
  double v28; // d1
  double v29; // d2
  double v30; // d3
  double v31; // d4
  double v32; // d5
  double v33; // d6
  double v34; // d7
  __int64 v35; // x4
  __int64 v36; // x5
  __int64 v37; // x6
  __int64 v38; // x7
  const char *v39; // x2

  if ( a1 )
  {
    v10 = *(_QWORD *)(a1 + 1360);
    qdf_mutex_acquire(v10 + 3088);
    v12 = 0;
    v13 = (char *)(v10 + 3153);
    while ( (unsigned int)qdf_mem_cmp(v13, a2, 6u) )
    {
      ++v12;
      v13 += 7;
      if ( v12 == 32 )
      {
        if ( a2 )
        {
          v22 = *a2;
          v23 = a2[1];
          v24 = a2[2];
          v25 = a2[5];
        }
        else
        {
          v24 = 0;
          v22 = 0;
          v23 = 0;
          v25 = 0;
        }
        v39 = "%s: Mac addr %02x:%02x:%02x:**:**:%02x not found in authorized database";
        goto LABEL_15;
      }
    }
    if ( (*(v13 - 1) & 1) == 0 )
    {
      if ( a2 )
      {
        v22 = *a2;
        v23 = a2[1];
        v39 = "%s: Mac addr %02x:%02x:%02x:**:**:%02x is already deauthorized in database";
        v24 = a2[2];
        v25 = a2[5];
      }
      else
      {
        v24 = 0;
        v22 = 0;
        v23 = 0;
        v25 = 0;
        v39 = "%s: Mac addr %02x:%02x:%02x:**:**:%02x is already deauthorized in database";
      }
LABEL_15:
      qdf_trace_msg(
        0xA0u,
        8u,
        v39,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "wlan_mlo_update_deauthorize_epcs_mac_addr",
        v22,
        v23,
        v24,
        v25);
      qdf_mutex_release(v10 + 3088);
      return 4;
    }
    *(v13 - 1) = 0;
    qdf_mutex_release(v10 + 3088);
    if ( a2 )
    {
      v35 = *a2;
      v36 = a2[1];
      v37 = a2[2];
      v38 = a2[5];
    }
    else
    {
      v37 = 0;
      v35 = 0;
      v36 = 0;
      v38 = 0;
    }
    qdf_trace_msg(
      0xA0u,
      8u,
      "%s: EPCS Stored authorize mac addr is %02x:%02x:%02x:**:**:%02x at idx %d is removed",
      v27,
      v28,
      v29,
      v30,
      v31,
      v32,
      v33,
      v34,
      "wlan_mlo_update_deauthorize_epcs_mac_addr",
      v35,
      v36,
      v37,
      v38,
      v12);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0xA0u,
      2u,
      "%s: vdev is null",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_mlo_update_deauthorize_epcs_mac_addr");
    return 4;
  }
}

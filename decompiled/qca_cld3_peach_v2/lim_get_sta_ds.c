__int64 __fastcall lim_get_sta_ds(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int8 *a3,
        _WORD *a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 v18; // x20
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  int v27; // w3
  int v28; // w4
  int v29; // w5
  int v30; // w6
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int64 v39; // x5
  __int64 v40; // x6
  __int64 v41; // x7
  int v42; // w8
  _QWORD v44[6]; // [xsp+30h] [xbp-40h] BYREF
  int v45; // [xsp+60h] [xbp-10h]
  __int64 v46; // [xsp+68h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v45 = 0;
  memset(v44, 0, sizeof(v44));
  v18 = dph_lookup_hash_entry(a6, a7, a8, a9, a10, a11, a12, a13, a1, a2, a4, a5 + 360);
  if ( !v18
    && (!(*(_DWORD *)a3 | *((unsigned __int16 *)a3 + 2))
     || (v18 = dph_lookup_hash_entry(v19, v20, v21, v22, v23, v24, v25, v26, a1, a3, a4, a5 + 360)) == 0) )
  {
    if ( (wlan_vdev_mlme_is_mlo_vdev(*(_QWORD *)(a5 + 16), v19, v20, v21, v22, v23, v24, v25, v26) & 1) == 0 )
    {
      v18 = 0;
      goto LABEL_18;
    }
    v18 = dph_lookup_hash_entry_by_mld_addr(v31, v32, v33, v34, v35, v36, v37, v38, a1, a2, a4, a5 + 360);
    if ( !v18 )
      goto LABEL_18;
  }
  if ( *(_DWORD *)a3 | *((unsigned __int16 *)a3 + 2) )
  {
    if ( a3 )
    {
      v27 = *a3;
      v28 = a3[1];
      v29 = a3[2];
      v30 = a3[5];
    }
    else
    {
      v29 = 0;
      v27 = 0;
      v28 = 0;
      v30 = 0;
    }
    v19 = scnprintf(v44, 26, " SA mld: %02x:%02x:%02x:**:**:%02x", v27, v28, v29, v30);
  }
  if ( *(_DWORD *)(v18 + 1080) | *(unsigned __int16 *)(v18 + 1084) )
    v19 = scnprintf(
            v44,
            26,
            " STA DS mld: %02x:%02x:%02x:**:**:%02x",
            *(unsigned __int8 *)(v18 + 1080),
            *(unsigned __int8 *)(v18 + 1081),
            *(unsigned __int8 *)(v18 + 1082),
            *(unsigned __int8 *)(v18 + 1085));
  if ( a2 )
  {
    v39 = *a2;
    v40 = a2[1];
    v41 = a2[2];
    v42 = a2[5];
  }
  else
  {
    v41 = 0;
    v39 = 0;
    v40 = 0;
    v42 = 0;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Vdev %d STA found for %02x:%02x:%02x:**:**:%02x%s",
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    "lim_get_sta_ds",
    *(unsigned __int8 *)(a5 + 10),
    v39,
    v40,
    v41,
    v42,
    v44);
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return v18;
}

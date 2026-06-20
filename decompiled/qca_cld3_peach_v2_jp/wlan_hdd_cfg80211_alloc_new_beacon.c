__int64 __fastcall wlan_hdd_cfg80211_alloc_new_beacon(
        __int64 a1,
        void ***a2,
        __int64 a3,
        int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  const void *v23; // x21
  __int64 v24; // x19
  __int64 v25; // x20
  _BOOL4 v26; // w23
  _QWORD *v27; // x8
  void *v28; // x8
  int v29; // w22
  const void *v30; // x24
  bool v31; // w8
  int v32; // w27
  const void *v33; // x25
  bool v34; // w8
  int v35; // w28
  __int64 v36; // x0
  size_t v37; // x11
  int v38; // w8
  void **v39; // x26
  __int64 v40; // x9
  void *src; // [xsp+0h] [xbp-20h]
  _QWORD *v43; // [xsp+8h] [xbp-18h]
  void ***v44; // [xsp+10h] [xbp-10h]

  qdf_trace_msg(0x33u, 8u, "%s: enter", a5, a6, a7, a8, a9, a10, a11, a12, "wlan_hdd_cfg80211_alloc_new_beacon");
  v23 = *(const void **)(a3 + 8);
  if ( !v23 )
  {
    v25 = *(_QWORD *)(a1 + 2160);
    if ( v25 )
    {
      LODWORD(v24) = *(_DWORD *)(v25 + 32);
      v23 = *(const void **)v25;
      v27 = (_QWORD *)(a1 + 2160);
      v26 = 1;
      v43 = v27;
      goto LABEL_6;
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: session: %d old and new heads points to NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_hdd_cfg80211_alloc_new_beacon",
      *(unsigned __int8 *)(a1 + 8));
    return 4294967274LL;
  }
  v24 = *(_QWORD *)(a3 + 96);
  if ( !v24 )
  {
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: head_len is NULL",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "wlan_hdd_cfg80211_alloc_new_beacon");
    return 4294967274LL;
  }
  v25 = *(_QWORD *)(a1 + 2160);
  v43 = (_QWORD *)(a1 + 2160);
  v26 = v25 != 0;
LABEL_6:
  v28 = *(void **)(a3 + 16);
  v44 = a2;
  if ( v28 || !v26 )
  {
    v29 = *(_DWORD *)(a3 + 104);
  }
  else
  {
    v29 = *(_DWORD *)(v25 + 36);
    v28 = *(void **)(v25 + 8);
  }
  src = v28;
  v30 = *(const void **)(a3 + 32);
  if ( v30 )
    v31 = 0;
  else
    v31 = v26;
  if ( v31 )
  {
    v32 = *(_DWORD *)(v25 + 40);
    v30 = *(const void **)(v25 + 16);
  }
  else
  {
    v32 = *(_DWORD *)(a3 + 120);
  }
  v33 = *(const void **)(a3 + 40);
  if ( v33 )
    v34 = 0;
  else
    v34 = v26;
  if ( v34 )
  {
    v35 = *(_DWORD *)(v25 + 44);
    v33 = *(const void **)(v25 + 24);
  }
  else
  {
    v35 = *(_DWORD *)(a3 + 128);
  }
  v36 = _qdf_mem_malloc((int)v24 + v29 + v32 + v35 + 56, "wlan_hdd_cfg80211_alloc_new_beacon", 5742);
  if ( !v36 )
    return 4294967284LL;
  v37 = v29;
  v38 = a4;
  v39 = (void **)v36;
  if ( !a4 )
  {
    if ( !v26 )
      goto LABEL_27;
    v38 = *(_DWORD *)(v25 + 48);
  }
  *(_DWORD *)(v36 + 48) = v38;
LABEL_27:
  *(_DWORD *)(v36 + 32) = v24;
  *(_DWORD *)(v36 + 36) = v29;
  v40 = v36 + 56 + (int)v24;
  *(_DWORD *)(v36 + 40) = v32;
  *(_DWORD *)(v36 + 44) = v35;
  *(_QWORD *)v36 = v36 + 56;
  *(_QWORD *)(v36 + 8) = v40;
  *(_QWORD *)(v36 + 16) = v40 + v29;
  *(_QWORD *)(v36 + 24) = v40 + v29 + v32;
  if ( v23 && (_DWORD)v24 )
  {
    memcpy(*(void **)v36, v23, (int)v24);
    v37 = v29;
  }
  if ( src && v29 )
    memcpy(v39[1], src, v37);
  if ( v30 && v32 )
    memcpy(v39[2], v30, v32);
  if ( v33 )
  {
    if ( v35 )
      memcpy(v39[3], v33, v35);
  }
  *v44 = v39;
  *v43 = 0;
  _qdf_mem_free(v25);
  return 0;
}

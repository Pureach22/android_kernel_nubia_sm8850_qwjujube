__int64 __fastcall wlan_hdd_update_rnrie(
        __int64 a1,
        __int64 a2,
        __int64 *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x20
  unsigned __int8 *ie_ptr_from_eid; // x0
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  unsigned __int8 *v26; // x22
  size_t v27; // x2
  const char *v28; // x2
  unsigned int v29; // w1
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  __int16 v39; // w8
  __int16 v40; // w9
  size_t v41; // x0
  void *v42; // x0
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  size_t n; // [xsp+8h] [xbp-18h] BYREF
  __int64 v52; // [xsp+10h] [xbp-10h]
  __int64 v53; // [xsp+18h] [xbp-8h]

  v53 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *a3;
  n = 0;
  v52 = 0;
  if ( !v12 || (v13 = *(_QWORD *)(v12 + 24)) == 0 || (v14 = *(_QWORD *)(v13 + 16)) == 0 )
  {
    v28 = "%s: NULL MAC context and reset rnrie buf";
    goto LABEL_9;
  }
  *(_WORD *)(a2 + 2130) = 0;
  qdf_mem_set((void *)(a2 + 1872), 0x101u, 0);
  ie_ptr_from_eid = wlan_get_ie_ptr_from_eid(0xC9u, *(unsigned __int8 **)(a1 + 8), *(_DWORD *)(a1 + 36));
  if ( !ie_ptr_from_eid || !ie_ptr_from_eid[1] )
  {
    qdf_trace_msg(0x33u, 8u, "%s: No rnr ie", v18, v19, v20, v21, v22, v23, v24, v25, "wlan_hdd_update_rnrie");
    if ( (a3[746] & 2) != 0 )
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: clean up rnrie while softap is running",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "wlan_hdd_update_rnrie");
      v39 = *((unsigned __int8 *)a3 + 8);
      v40 = *(_WORD *)(a2 + 2130);
      v52 = 0;
      LOWORD(n) = v39;
      WORD1(n) = v40;
      if ( (unsigned int)sme_update_rnr_ie(v14, &n) == 16 )
      {
        v28 = "%s: Update rnrie failure";
        v29 = 2;
        goto LABEL_10;
      }
    }
LABEL_17:
    result = 0;
    goto LABEL_12;
  }
  v26 = ie_ptr_from_eid;
  *(_WORD *)(a2 + 2130) = ie_ptr_from_eid[1] + 2;
  qdf_trace_msg(
    0x33u,
    8u,
    "%s: RNR IEs length %d, vdev id %d",
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    "wlan_hdd_update_rnrie");
  v27 = *(unsigned __int16 *)(a2 + 2130);
  if ( (unsigned int)v27 < 0x102 )
  {
    qdf_mem_copy((void *)(a2 + 1872), v26, v27);
    if ( (a3[746] & 2) != 0 )
    {
      v41 = *(unsigned __int16 *)(a2 + 2130);
      LOWORD(n) = *((unsigned __int8 *)a3 + 8);
      WORD1(n) = v41;
      v42 = (void *)_qdf_mem_malloc(v41, "wlan_hdd_update_rnrie", 7049);
      v52 = (__int64)v42;
      if ( v42 )
      {
        qdf_mem_copy(v42, (const void *)(a2 + 1872), WORD1(n));
        if ( (unsigned int)sme_update_rnr_ie(v14, &n) != 16 )
        {
          _qdf_mem_free(v52);
          result = 0;
          goto LABEL_12;
        }
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Update rnrie failure",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "wlan_hdd_update_rnrie");
        _qdf_mem_free(v52);
      }
      goto LABEL_11;
    }
    goto LABEL_17;
  }
  v28 = "%s: RNR IEs too large";
LABEL_9:
  v29 = 8;
LABEL_10:
  qdf_trace_msg(0x33u, v29, v28, a4, a5, a6, a7, a8, a9, a10, a11, "wlan_hdd_update_rnrie");
LABEL_11:
  *(_WORD *)(a2 + 2130) = 0;
  qdf_mem_set((void *)(a2 + 1872), 0x101u, 0);
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}

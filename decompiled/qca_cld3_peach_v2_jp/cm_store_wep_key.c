__int64 __fastcall cm_store_wep_key(
        __int64 result,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        __int64 a13,
        __int64 a14)
{
  __int64 v14; // x29
  __int64 v15; // x30
  int v16; // w8
  unsigned __int8 v19; // w3
  unsigned __int8 v20; // w2
  unsigned __int8 v21; // w1
  unsigned int v22; // w23
  __int64 *v23; // x21
  int v24; // w8
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x0
  _BYTE *key; // x22
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  double v43; // d0
  double v44; // d1
  double v45; // d2
  double v46; // d3
  double v47; // d4
  double v48; // d5
  double v49; // d6
  double v50; // d7
  __int64 v51; // [xsp+8h] [xbp-48h]
  __int64 v52; // [xsp+18h] [xbp-38h]

  v16 = *(_DWORD *)(a2 + 84);
  if ( (v16 & 0x18000) != 0 )
  {
    v52 = v15;
    v19 = *(_BYTE *)(a2 + 113);
    v20 = *(_BYTE *)(a2 + 112);
    v21 = *(_BYTE *)(a2 + 114);
    if ( (v16 & 0x8000) != 0 )
      v22 = 15;
    else
      v22 = 16;
    v23 = (__int64 *)result;
    v24 = wlan_crypto_validate_key_params(v22, v21, v20, v19, a4, a5, a6, a7, a8, a9, a10, a11, a13, a14);
    v33 = *v23;
    if ( v24 )
      return qdf_trace_msg(
               0x68u,
               2u,
               "%s: vdev %d cm_id 0x%x: Invalid key params",
               v25,
               v26,
               v27,
               v28,
               v29,
               v30,
               v31,
               v32,
               "cm_store_wep_key",
               *(unsigned __int8 *)(v33 + 104),
               a3);
    key = (_BYTE *)wlan_crypto_get_key(v33, a2 + 8, *(_BYTE *)(a2 + 114));
    if ( key )
    {
LABEL_8:
      qdf_mem_set(key, 0x1B0u, 0);
      *((_DWORD *)key + 2) = v22;
      *key = *(_BYTE *)(a2 + 112);
      *((_WORD *)key + 2) = *(unsigned __int8 *)(a2 + 114);
      qdf_mem_copy(key + 384, *(const void **)(a2 + 96), *(unsigned __int8 *)(a2 + 112));
      qdf_mem_copy(key + 104, *(const void **)(a2 + 104), *(unsigned __int8 *)(a2 + 113));
      return qdf_trace_msg(
               0x68u,
               8u,
               "%s: vdev %d cm_id 0x%x: cipher_type %d key_len %d, seq_len %d",
               v35,
               v36,
               v37,
               v38,
               v39,
               v40,
               v41,
               v42,
               "cm_store_wep_key",
               *(unsigned __int8 *)(*v23 + 104),
               a3,
               *((unsigned int *)key + 2),
               *(unsigned __int8 *)(a2 + 112),
               *(unsigned __int8 *)(a2 + 113),
               v51,
               v14,
               v52);
    }
    result = _qdf_mem_malloc(0x1B0u, "cm_store_wep_key", 269);
    if ( result )
    {
      key = (_BYTE *)result;
      if ( (unsigned int)((__int64 (__fastcall *)(__int64, __int64, _QWORD, __int64))wlan_crypto_save_key)(
                           *v23,
                           a2 + 8,
                           *(unsigned __int8 *)(a2 + 114),
                           result) )
      {
        qdf_trace_msg(
          0x68u,
          2u,
          "%s: vdev %d cm_id 0x%x: Failed to save key",
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          "cm_store_wep_key",
          *(unsigned __int8 *)(*v23 + 104),
          a3);
        return _qdf_mem_free((__int64)key);
      }
      goto LABEL_8;
    }
  }
  return result;
}

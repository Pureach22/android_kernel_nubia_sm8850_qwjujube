__int64 __fastcall cm_store_fils_key(
        __int64 *a1,
        char a2,
        unsigned int a3,
        unsigned __int16 a4,
        const void *a5,
        const void *a6,
        unsigned int a7)
{
  __int64 v8; // x0
  unsigned int v11; // w1
  __int64 param; // x0
  int v16; // w26
  unsigned __int8 *key; // x25
  double v18; // d0
  double v19; // d1
  double v20; // d2
  double v21; // d3
  double v22; // d4
  double v23; // d5
  double v24; // d6
  double v25; // d7
  int v26; // w9
  int v27; // w10
  int v28; // w11
  int v29; // w12
  __int64 result; // x0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7

  v8 = *a1;
  if ( (a2 & 1) != 0 )
    v11 = 1;
  else
    v11 = 2;
  param = wlan_crypto_get_param(v8, v11);
  if ( (param & 1) != 0 )
  {
    v16 = 0;
  }
  else if ( (param & 2) != 0 )
  {
    v16 = 1;
  }
  else if ( (param & 4) != 0 )
  {
    v16 = 2;
  }
  else if ( (param & 8) != 0 )
  {
    v16 = 3;
  }
  else if ( (param & 0x10) != 0 )
  {
    v16 = 4;
  }
  else if ( (param & 0x20) != 0 )
  {
    v16 = 5;
  }
  else if ( (param & 0x40) != 0 )
  {
    v16 = 6;
  }
  else if ( (param & 0x80) != 0 )
  {
    v16 = 7;
  }
  else if ( (param & 0x100) != 0 )
  {
    v16 = 8;
  }
  else if ( (param & 0x200) != 0 )
  {
    v16 = 9;
  }
  else if ( (param & 0x400) != 0 )
  {
    v16 = 10;
  }
  else if ( (param & 0x800) != 0 )
  {
    v16 = 11;
  }
  else if ( (param & 0x1000) != 0 )
  {
    v16 = 12;
  }
  else if ( (param & 0x2000) != 0 )
  {
    v16 = 13;
  }
  else if ( (param & 0x4000) != 0 )
  {
    v16 = 14;
  }
  else if ( (param & 0x8000) != 0 )
  {
    v16 = 15;
  }
  else if ( (param & 0x10000) != 0 )
  {
    v16 = 16;
  }
  else
  {
    v16 = 17;
    if ( (param & 0x20000) == 0 )
    {
      if ( (param & 0x40000) != 0 )
        v16 = 18;
      else
        v16 = 17;
    }
  }
  key = (unsigned __int8 *)wlan_crypto_get_key(*a1, (__int64)a6, a3);
  if ( key )
    goto LABEL_43;
  result = _qdf_mem_malloc(0x1B0u, "cm_store_fils_key", 341);
  if ( !result )
    return result;
  key = (unsigned __int8 *)result;
  if ( !(unsigned int)((__int64 (__fastcall *)(__int64, const void *, _QWORD, __int64))wlan_crypto_save_key)(
                        *a1,
                        a6,
                        a3,
                        result) )
  {
LABEL_43:
    qdf_mem_set(key, 0x1B0u, 0);
    *((_DWORD *)key + 2) = v16;
    *key = a4;
    *((_WORD *)key + 2) = (unsigned __int8)a3;
    qdf_mem_copy(key + 384, a5, a4);
    qdf_mem_copy(key + 16, a6, 6u);
    if ( key == (unsigned __int8 *)-16LL )
    {
      v28 = 0;
      v26 = 0;
      v27 = 0;
      v29 = 0;
    }
    else
    {
      v26 = key[16];
      v27 = key[17];
      v28 = key[18];
      v29 = key[21];
    }
    return qdf_trace_msg(
             0x68u,
             8u,
             "%s: vdev %d cm_id 0x%x: cipher_type %d key_len %d, key_id %d mac:%02x:%02x:%02x:**:**:%02x",
             v18,
             v19,
             v20,
             v21,
             v22,
             v23,
             v24,
             v25,
             "cm_store_fils_key",
             *(unsigned __int8 *)(*a1 + 104),
             a7,
             *((unsigned int *)key + 2),
             *key,
             *((unsigned __int16 *)key + 2),
             v26,
             v27,
             v28,
             v29);
  }
  else
  {
    qdf_trace_msg(
      0x68u,
      2u,
      "%s: vdev %d cm_id 0x%x: Failed to save key",
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      "cm_store_fils_key",
      *(unsigned __int8 *)(*a1 + 104),
      a7);
    return _qdf_mem_free((__int64)key);
  }
}

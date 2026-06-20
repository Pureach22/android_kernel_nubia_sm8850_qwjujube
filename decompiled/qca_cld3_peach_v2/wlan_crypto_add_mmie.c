_BYTE *__fastcall wlan_crypto_add_mmie(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _BYTE *a10,
        int a11)
{
  __int64 wlan_crypto_keys; // x0
  const char *v14; // x2
  unsigned __int8 *v15; // x25
  _WORD *v16; // x20
  __int64 v17; // x26
  int v18; // w24
  __int16 v19; // w8
  __int16 v20; // w8
  __int16 v21; // w8
  __int16 v22; // w8
  __int16 v23; // w8
  unsigned int v24; // w22
  _BYTE *result; // x0
  _BYTE *v26; // x21
  int v27; // w8
  unsigned __int8 v28; // w9
  unsigned __int8 v29; // w8
  int v30; // w22
  _QWORD v31[2]; // [xsp+8h] [xbp-28h] BYREF
  __int64 v32; // [xsp+18h] [xbp-18h] BYREF
  int v33; // [xsp+20h] [xbp-10h]
  __int64 v34; // [xsp+28h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v33 = 0;
  v31[1] = 0;
  v32 = 0;
  v31[0] = 0;
  if ( !a10 )
  {
    v14 = "%s: frame is NULL";
LABEL_29:
    qdf_trace_msg(0x1Cu, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "wlan_crypto_add_mmie");
    goto LABEL_30;
  }
  wlan_crypto_keys = wlan_crypto_get_wlan_crypto_keys();
  if ( !wlan_crypto_keys )
  {
    v14 = "%s: crypto_keys NULL";
    goto LABEL_29;
  }
  if ( *(unsigned __int8 *)(wlan_crypto_keys + 133) >= 2u )
  {
    qdf_trace_msg(0x1Cu, 2u, "%s: igtk key invalid keyid %d", a1, a2, a3, a4, a5, a6, a7, a8, "wlan_crypto_add_mmie");
LABEL_30:
    result = nullptr;
    goto LABEL_31;
  }
  v15 = *(unsigned __int8 **)(wlan_crypto_keys + 8LL * *(unsigned __int8 *)(wlan_crypto_keys + 133) + 32);
  if ( !v15 )
  {
    v14 = "%s: No igtk key present";
    goto LABEL_29;
  }
  v16 = &a10[a11];
  v17 = wlan_crypto_keys;
  qdf_mem_set(v16, 0x1Au, 0);
  *v16 = 6220;
  v16[1] = *((_WORD *)v15 + 2);
  if ( *(_DWORD *)(v17 + 128) == 6 )
  {
    v18 = a11 + 18;
    *((_BYTE *)v16 + 1) = 16;
  }
  else
  {
    v18 = a11 + 26;
  }
  v19 = ++v15[96];
  if ( (v19 & 0x100) != 0 )
  {
    v20 = ++v15[97];
    if ( (v20 & 0x100) != 0 )
    {
      v21 = ++v15[98];
      if ( (v21 & 0x100) != 0 )
      {
        v22 = ++v15[99];
        if ( (v22 & 0x100) != 0 )
        {
          v23 = ++v15[100];
          if ( (v23 & 0x100) != 0 )
            ++v15[101];
        }
      }
    }
  }
  qdf_mem_copy(v16 + 2, v15 + 96, 6u);
  v24 = v18 - 4;
  result = (_BYTE *)_qdf_mem_malloc((unsigned int)(v18 - 4), "wlan_crypto_add_mmie", 2209);
  if ( result )
  {
    v26 = result;
    qdf_mem_set(result, v24, 0);
    *v26 = *a10;
    v26[1] = a10[1] & 0xC7;
    qdf_mem_copy(v26 + 2, a10 + 4, 6u);
    qdf_mem_copy(v26 + 8, a10 + 10, 6u);
    qdf_mem_copy(v26 + 14, a10 + 16, 6u);
    qdf_mem_set(v31, 0x10u, 0);
    qdf_mem_copy(v26 + 20, a10 + 24, (unsigned int)(v18 - 24));
    v27 = *(_DWORD *)(v17 + 128);
    if ( (unsigned int)(v27 - 11) < 2 )
    {
      qdf_mem_copy(&v32, a10 + 10, 6u);
      v28 = v15[96];
      BYTE6(v32) = v15[101];
      HIBYTE(v32) = v15[100];
      LOBYTE(v33) = v15[99];
      BYTE1(v33) = v15[98];
      v29 = v15[97];
      HIBYTE(v33) = v28;
      BYTE2(v33) = v29;
      v30 = qdf_crypto_aes_gmac(
              (__int64)(v15 + 384),
              *v15,
              (__int64)&v32,
              (int)v26,
              (__int64)(v26 + 20),
              (unsigned __int16)v18 - 40,
              (__int64)(v16 + 5));
    }
    else
    {
      if ( v27 != 6 )
      {
        if ( v27 == 8 )
        {
          _qdf_mem_free((__int64)v26);
LABEL_26:
          result = &a10[v18];
          goto LABEL_31;
        }
        _qdf_mem_free((__int64)v26);
        goto LABEL_28;
      }
      v30 = qdf_crypto_aes_128_cmac((__int64)(v15 + 384), (__int64)v26, v24, v31);
      qdf_mem_copy(v16 + 5, v31, 8u);
    }
    _qdf_mem_free((__int64)v26);
    if ( (v30 & 0x80000000) == 0 )
      goto LABEL_26;
LABEL_28:
    v14 = "%s: add mmie failed";
    goto LABEL_29;
  }
LABEL_31:
  _ReadStatusReg(SP_EL0);
  return result;
}

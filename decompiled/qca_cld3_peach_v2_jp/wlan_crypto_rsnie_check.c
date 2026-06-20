__int64 __fastcall wlan_crypto_rsnie_check(_DWORD *a1, unsigned __int8 *a2, int *a3)
{
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  int v14; // w4
  unsigned __int8 v15; // w10
  unsigned __int8 *v16; // x9
  unsigned int v17; // w8
  unsigned int v18; // w12
  unsigned __int64 v19; // t2
  __int64 result; // x0
  int v21; // w9
  int v22; // w8
  int v23; // w10
  int v24; // w8
  int v25; // w13
  int v26; // w12
  unsigned __int8 *v27; // x9
  unsigned __int8 v28; // w10
  unsigned int v29; // w14
  int v30; // w14
  char v31; // w12
  int v32; // w13
  unsigned int v33; // w16
  unsigned __int64 v34; // t2
  int v35; // w8
  __int16 *v36; // x21
  unsigned __int8 v37; // w24
  int v38; // w12
  unsigned __int64 v39; // x25
  int v40; // w27
  int v41; // w0
  __int16 v42; // w8
  unsigned int v43; // w9
  _WORD *v44; // x0
  unsigned __int8 v45; // w9
  unsigned int v46; // w10
  const char *v47; // x2
  int v48; // w8
  int v49; // w0
  char v50; // w8

  if ( a2[1] <= 1u )
    goto LABEL_16;
  qdf_mem_set(a1, 0x120u, 0);
  *a1 |= 0x40u;
  v14 = *a2;
  if ( v14 == 221 )
  {
    v17 = a2[1];
    if ( v17 < 5 )
      goto LABEL_16;
    v16 = a2 + 6;
    v15 = v17 - 4;
  }
  else
  {
    if ( v14 != 48 )
    {
      qdf_trace_msg(0x1Cu, 2u, "%s: Unknown eid %x", v6, v7, v8, v9, v10, v11, v12, v13, "wlan_crypto_get_ie_offset");
      goto LABEL_16;
    }
    v15 = a2[1];
    v16 = a2 + 2;
  }
  if ( *(_WORD *)v16 != 1 )
  {
    if ( !a3 )
      return 4;
    v22 = 44;
    goto LABEL_18;
  }
  if ( v15 == 2 )
  {
    v23 = a1[5];
    v24 = a1[2] | 8;
    a1[1] |= 8u;
    a1[2] = v24;
    a1[5] = v23 | 1;
    return 0;
  }
  if ( (unsigned __int8)(v15 - 2) <= 3u )
    goto LABEL_16;
  HIDWORD(v19) = *(_DWORD *)(v16 + 2) - 11276032;
  LODWORD(v19) = HIDWORD(v19);
  v18 = v19 >> 24;
  if ( v18 >= 0xE || ((0x3F55u >> v18) & 1) == 0 )
  {
    if ( !a3 )
      return 4;
    v22 = 41;
    goto LABEL_18;
  }
  a1[2] |= 1 << dword_9DEC40[v18];
  if ( v15 == 7 )
    goto LABEL_16;
  if ( v15 == 6 )
  {
    v21 = a1[5] | 1;
    a1[1] |= 8u;
    a1[5] = v21;
    return 0;
  }
  v25 = v16[6];
  v26 = v16[7];
  v27 = v16 + 8;
  v28 = v15 - 8;
  v29 = v25 & 0xFFFF00FF | ((unsigned __int8)v26 << 8);
  if ( v29 )
  {
    if ( 4 * v29 > v28 )
      goto LABEL_16;
    v30 = v26 << 8;
    v31 = 4 * v25;
    v32 = v30 + v25 + 1;
    do
    {
      HIDWORD(v34) = *(_DWORD *)v27 - 11276032;
      LODWORD(v34) = HIDWORD(v34);
      v33 = v34 >> 24;
      if ( v33 <= 0xD && ((0x3F55u >> v33) & 1) != 0 )
        a1[1] |= 1 << dword_9DEC40[v33];
      --v32;
      v27 += 4;
    }
    while ( v32 > 1 );
    if ( !a1[1] )
    {
      if ( !a3 )
        return 4;
      v22 = 42;
      goto LABEL_18;
    }
    v28 -= v31;
  }
  else
  {
    a1[1] |= 8u;
  }
  if ( v28 == 1 )
  {
LABEL_16:
    if ( !a3 )
      return 4;
    goto LABEL_17;
  }
  if ( !v28 )
  {
    a1[5] |= 1u;
    return 0;
  }
  v35 = *v27;
  v36 = (__int16 *)(v27 + 2);
  v37 = v28 - 2;
  v38 = (unsigned __int8)v35 | (v27[1] << 8);
  if ( v38 )
  {
    if ( 4 * v38 <= (unsigned int)v37 )
    {
      v37 -= 4 * v35;
      v39 = 0;
      v40 = (v27[1] << 8) + v35 + 1;
      do
      {
        v41 = wlan_crypto_rsn_suite_to_keymgmt(v36);
        if ( (v41 & 0x80000000) == 0 )
        {
          a1[5] |= 1 << v41;
          if ( (int)v39 >= 30 )
          {
            qdf_trace_msg(
              0x1Cu,
              8u,
              "%s: Invalid AKM Index",
              v6,
              v7,
              v8,
              v9,
              v10,
              v11,
              v12,
              v13,
              "wlan_crypto_store_akm_list_in_order");
          }
          else
          {
            if ( v39 >= 0x1E )
            {
              __break(0x5512u);
              return ((__int64 (*)(void))wlan_crypto_rsn_suite_to_cipher)();
            }
            a1[v39 + 40] = v41;
          }
          ++v39;
        }
        --v40;
        v36 += 2;
      }
      while ( v40 > 1 );
      if ( a1[5] )
        goto LABEL_53;
      if ( a3 )
      {
        v22 = 43;
        goto LABEL_18;
      }
      return 4;
    }
    goto LABEL_16;
  }
  a1[5] |= 1u;
LABEL_53:
  if ( v37 <= 1u )
  {
    if ( v37 )
      goto LABEL_16;
    v42 = *((_WORD *)a1 + 76);
  }
  else
  {
    v42 = *v36;
    v43 = (unsigned __int8)(v37 - 2);
    *((_WORD *)a1 + 76) = *v36;
    if ( v43 < 2 )
    {
      if ( v43 == 1 )
      {
        v47 = "%s: PMKID is truncated";
        goto LABEL_73;
      }
    }
    else
    {
      v44 = v36 + 2;
      v45 = v37 - 4;
      if ( !v36[1] || v37 == 4 )
      {
        if ( v36[1] && v37 == 4 )
          goto LABEL_16;
      }
      else
      {
        v46 = 16 * (unsigned __int16)v36[1];
        if ( v46 > v45 )
        {
          if ( !a3 )
            return 4;
          v22 = 53;
          goto LABEL_18;
        }
        v44 = (_WORD *)((char *)v44 + v46);
        v45 -= v46;
      }
      if ( v45 )
      {
        if ( v45 <= 3u )
        {
          v47 = "%s: Mgmt cipher is truncated";
LABEL_73:
          qdf_trace_msg(0x1Cu, 2u, v47, v6, v7, v8, v9, v10, v11, v12, v13, "wlan_crypto_rsnie_check");
          if ( !a3 )
            return 4;
LABEL_17:
          v22 = 40;
LABEL_18:
          *a3 = v22;
          return 4;
        }
        v49 = wlan_crypto_rsn_suite_to_cipher(v44);
        if ( v49 < 0 )
        {
          if ( !a3 )
            return 4;
          v22 = 46;
          goto LABEL_18;
        }
        v50 = v49;
        result = 0;
        v48 = a1[3] | (1 << v50);
LABEL_77:
        a1[3] = v48;
        return result;
      }
    }
  }
  result = 0;
  if ( (v42 & 0x80) != 0 )
  {
    v48 = a1[3] | 0x40;
    goto LABEL_77;
  }
  return result;
}

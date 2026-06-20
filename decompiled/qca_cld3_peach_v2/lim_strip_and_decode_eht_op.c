unsigned __int8 *__fastcall lim_strip_and_decode_eht_op(unsigned __int8 *a1, unsigned __int16 a2, _BYTE *a3)
{
  unsigned __int8 *result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  const char *v13; // x2
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned __int8 *v22; // x20
  int v23; // w11
  unsigned __int8 v24; // w10
  unsigned int v25; // w11
  int v26; // w9
  unsigned int v27; // w11
  unsigned int v28; // w11
  unsigned int v29; // w11
  unsigned int v30; // w11
  unsigned int v31; // w11
  unsigned int v32; // w11
  unsigned int v33; // w11
  unsigned int v34; // w11
  unsigned int v35; // w11
  unsigned int v36; // w11
  unsigned int v37; // w12
  int v38; // w11
  unsigned int v39; // w11
  unsigned int v40; // w11

  result = wlan_get_ext_ie_ptr_from_ext_id("j", 1u, a1, a2);
  if ( result )
  {
    if ( result[1] > 5u )
    {
      if ( *result != 255 || result[2] != 106 )
      {
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Invalid EHT op IE",
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          "lim_ieee80211_unpack_ehtop");
        goto LABEL_11;
      }
      v22 = result;
      qdf_mem_set(a3, 0xCu, 0);
      v23 = *(_DWORD *)(a3 + 1);
      result = nullptr;
      *a3 = 1;
      v24 = v22[3];
      v25 = v23 & 0xFFFFFFFE | v24 & 1;
      *(_DWORD *)(a3 + 1) = v25;
      v26 = v22[3] & 2;
      v27 = v25 & 0xFFFFFFFD | v26;
      *(_DWORD *)(a3 + 1) = v27;
      v28 = v27 & 0xFFFFFFFB | (4 * ((v22[3] >> 2) & 1));
      *(_DWORD *)(a3 + 1) = v28;
      v29 = v28 & 0xFFFFFFF7 | (8 * ((v22[3] >> 3) & 1));
      *(_DWORD *)(a3 + 1) = v29;
      v30 = v29 & 0xFFFFFFCF | (16 * ((v22[3] >> 4) & 3));
      *(_DWORD *)(a3 + 1) = v30;
      v31 = v30 & 0xFFFFFFBF | (((v22[3] >> 6) & 1) << 6);
      *(_DWORD *)(a3 + 1) = v31;
      v32 = v31 & 0xFFFFF0FF | ((v22[4] & 0xF) << 8);
      *(_DWORD *)(a3 + 1) = v32;
      v33 = v32 & 0xFFFF0FFF | (((v22[4] >> 4) & 0xF) << 12);
      *(_DWORD *)(a3 + 1) = v33;
      v34 = v33 & 0xFFF0FFFF | ((v22[5] & 0xF) << 16);
      *(_DWORD *)(a3 + 1) = v34;
      v35 = v34 & 0xFF0FFFFF | (((v22[5] >> 4) & 0xF) << 20);
      *(_DWORD *)(a3 + 1) = v35;
      v36 = v35 & 0xF0FFFFFF | ((v22[6] & 0xF) << 24);
      *(_DWORD *)(a3 + 1) = v36;
      v37 = (v22[6] << 24) & 0xF0000000 | v36 & 0xFFFFFFF;
      v38 = *(unsigned __int16 *)(a3 + 5);
      *(_DWORD *)(a3 + 1) = v37;
      v39 = v38 & 0xFFFFFFF0 | v22[7] & 0xF;
      *(_WORD *)(a3 + 5) = v39;
      v40 = v39 & 0xFFFFFF0F | (16 * ((v22[7] >> 4) & 0xF));
      *(_WORD *)(a3 + 5) = v40;
      if ( (v24 & 1) == 0 )
        return result;
      if ( v22[1] > 8u )
      {
        *(_WORD *)(a3 + 5) = v40 & 0xF8FF | ((v22[8] & 7) << 8);
        a3[7] = v22[9];
        a3[8] = v22[10];
        if ( !v26 )
          return nullptr;
        if ( v22[1] == 11 )
        {
          a3[9] = v22[11];
          a3[10] = v22[12];
          return nullptr;
        }
        v13 = "%s: Invalid length for EHT_OP sub chan bitmap len %d";
      }
      else
      {
        v13 = "%s: Invalid length for EHT_OP param len %d";
      }
    }
    else
    {
      v13 = "%s: Invalid EHT op IE len %d";
    }
    qdf_trace_msg(0x35u, 2u, v13, v5, v6, v7, v8, v9, v10, v11, v12, "lim_ieee80211_unpack_ehtop");
LABEL_11:
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Failed to extract eht op",
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      "lim_strip_and_decode_eht_op");
    return (unsigned __int8 *)&off_10;
  }
  return result;
}

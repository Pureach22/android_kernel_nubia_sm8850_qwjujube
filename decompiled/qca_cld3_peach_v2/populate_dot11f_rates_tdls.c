__int64 __fastcall populate_dot11f_rates_tdls(
        __int64 a1,
        _BYTE *a2,
        _BYTE *a3,
        unsigned __int8 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v12; // w23
  unsigned int v16; // w22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x8
  unsigned __int8 v26; // w23
  char v27; // w21
  __int64 v28; // x8
  __int64 result; // x0
  size_t v30; // x2
  unsigned __int8 v31; // w8
  size_t v32; // [xsp+0h] [xbp-30h] BYREF
  char v33; // [xsp+8h] [xbp-28h]
  _BYTE v34[15]; // [xsp+9h] [xbp-27h] BYREF
  _QWORD v35[3]; // [xsp+18h] [xbp-18h] BYREF

  v12 = a4;
  v35[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 5964LL);
  memset(v35, 0, 13);
  *(_QWORD *)&v34[4] = 0;
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: Current operating channel %d self_dot11mode = %d",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    "populate_dot11f_rates_tdls",
    a4,
    v16,
    0,
    0);
  if ( v12 > 0xE )
  {
    v26 = 0;
  }
  else
  {
    if ( v16 > 8 || ((1 << v16) & 0x13D) == 0 )
    {
      LOBYTE(v35[0]) = 0;
LABEL_10:
      v28 = *(_QWORD *)(a1 + 8);
      v32 = *(_QWORD *)(v28 + 3024);
      wlan_mlme_get_cfg_str(v34, v28 + 3016, &v32, v17, v18, v19, v20, v21, v22, v23, v24);
      v27 = v32;
      v26 = v35[0];
      v33 = v32;
      if ( LOBYTE(v35[0]) + (unsigned int)(unsigned __int8)v32 <= 0xC )
      {
        if ( (_BYTE)v32 )
          memcpy((char *)v35 + LOBYTE(v35[0]) + 1, v34, (unsigned __int8)v32);
        else
          v27 = 0;
        goto LABEL_15;
      }
LABEL_11:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: more than %d rates in CFG",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "populate_dot11f_rates_tdls",
        12);
      result = 16;
      goto LABEL_18;
    }
    v25 = *(_QWORD *)(a1 + 8);
    v32 = *(_QWORD *)(v25 + 2984);
    wlan_mlme_get_cfg_str((char *)v35 + 1, v25 + 2976, &v32, v17, v18, v19, v20, v21, v22, v23, v24);
    v26 = v32;
  }
  LOBYTE(v35[0]) = v26;
  if ( v16 != 3 )
    goto LABEL_10;
  v27 = 0;
  v33 = 0;
  if ( v26 > 0xCu )
    goto LABEL_11;
LABEL_15:
  v30 = (unsigned __int8)(v26 + v27);
  LOBYTE(v35[0]) = v26 + v27;
  if ( (unsigned int)v30 > 8 )
  {
    a2[1] = 8;
    qdf_mem_copy(a2 + 2, (char *)v35 + 1, 8u);
    v31 = v35[0];
    *a2 = 1;
    v31 -= 8;
    a3[1] = v31;
    qdf_mem_copy(a3 + 2, (char *)&v35[1] + 1, v31);
    result = 0;
    *a3 = 1;
  }
  else
  {
    a2[1] = v26 + v27;
    qdf_mem_copy(a2 + 2, (char *)v35 + 1, v30);
    result = 0;
    *a2 = 1;
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}

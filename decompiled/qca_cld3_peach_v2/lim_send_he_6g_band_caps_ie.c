__int64 __fastcall lim_send_he_6g_band_caps_ie(__int64 a1, unsigned __int8 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 result; // x0
  double v21; // d0
  double v22; // d1
  double v23; // d2
  double v24; // d3
  double v25; // d4
  double v26; // d5
  double v27; // d6
  double v28; // d7
  unsigned int v29; // w19
  __int64 v30; // [xsp+8h] [xbp-18h] BYREF
  int v31; // [xsp+10h] [xbp-10h] BYREF
  unsigned __int8 v32; // [xsp+14h] [xbp-Ch]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v32 = 0;
  v31 = 0;
  v30 = 0;
  qdf_mem_set((char *)&v30 + 4, 4u, 0);
  populate_dot11f_he_6ghz_cap(a1, 0, (char *)&v30 + 4);
  if ( BYTE4(v30) )
  {
    qdf_mem_set(&v31, 5u, 0);
    if ( (unsigned int)dot11f_pack_ie_he_6ghz_band_cap(a1, (char *)&v30 + 4, &v31, 5, &v30) )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: pack error for HE 6g band cap for vdev %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_send_he_6g_band_caps_ie",
        a2);
      result = 16;
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        8u,
        "%s: send HE 6ghz band cap: 0x%01x 0x%01x for vdev %d",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_send_he_6g_band_caps_ie",
        HIBYTE(v31),
        v32,
        a2);
      result = lim_send_ie(a2, 255, 2, (char *)&v31 + 2, 3);
      if ( (_DWORD)result )
      {
        v29 = result;
        qdf_trace_msg(
          0x35u,
          2u,
          "%s: Unable send HE 6g band Cap IE for 5GHZ band, status: %d",
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          "lim_send_he_6g_band_caps_ie",
          (unsigned int)result);
        result = v29;
      }
    }
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: no HE 6g band cap for vdev %d",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "lim_send_he_6g_band_caps_ie",
      a2);
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

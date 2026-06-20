__int64 __fastcall lim_process_tpe_ie_from_beacon(__int64 a1, __int64 a2, __int64 a3, _BYTE *a4)
{
  __int64 result; // x0
  __int64 v9; // x19
  unsigned __int16 ielen_from_bss_description; // w24
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x9
  __int16 v21; // w11
  __int64 v22; // x12
  __int64 v23; // x8
  __int64 v24; // x9
  __int64 v25; // x11
  __int64 v26; // x11
  __int64 v27; // x8
  __int64 v28; // x8
  double v29; // d0
  double v30; // d1
  double v31; // d2
  double v32; // d3
  double v33; // d4
  double v34; // d5
  double v35; // d6
  double v36; // d7
  const char *v37; // x2
  __int64 v38; // x4
  __int64 v39; // x9
  __int64 v40; // x10
  __int64 v41; // x9
  __int64 v42; // x8
  __int64 v43; // x11
  __int64 v44; // x4
  _QWORD v45[2]; // [xsp+0h] [xbp-60h] BYREF
  __int16 v46; // [xsp+10h] [xbp-50h]
  __int64 v47; // [xsp+18h] [xbp-48h] BYREF
  __int64 v48; // [xsp+20h] [xbp-40h]
  __int64 v49; // [xsp+28h] [xbp-38h]
  __int64 v50; // [xsp+30h] [xbp-30h]
  __int64 v51; // [xsp+38h] [xbp-28h]
  __int64 v52; // [xsp+40h] [xbp-20h]
  __int64 v53; // [xsp+48h] [xbp-18h]
  int v54; // [xsp+50h] [xbp-10h]
  __int64 v55; // [xsp+58h] [xbp-8h]

  v55 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = _qdf_mem_malloc(0x1490u, "lim_process_tpe_ie_from_beacon", 6614);
  if ( result )
  {
    v9 = result;
    ielen_from_bss_description = wlan_get_ielen_from_bss_description(a3);
    v11 = dot11f_unpack_beacon_i_es(a1, a3 + 104, ielen_from_bss_description, v9, 0);
    if ( (v11 & 0x10000000) != 0 )
    {
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse Beacon IEs (0x%08x, %d bytes):",
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        "lim_process_tpe_ie_from_beacon",
        v11,
        ielen_from_bss_description);
    }
    else
    {
      if ( v11 )
        qdf_trace_msg(
          0x35u,
          8u,
          "%s: warnings (0x%08x, %d bytes):",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "lim_process_tpe_ie_from_beacon",
          v11,
          ielen_from_bss_description);
      v20 = *(_QWORD *)(v9 + 2320);
      v21 = *(_WORD *)(v9 + 2328);
      v22 = *(unsigned int *)(v9 + 1424);
      v45[0] = *(_QWORD *)(v9 + 2312);
      v45[1] = v20;
      v23 = *(_QWORD *)(v9 + 1348);
      v24 = *(_QWORD *)(v9 + 1356);
      v46 = v21;
      v25 = *(_QWORD *)(v9 + 1364);
      v51 = v23;
      v52 = v24;
      LOWORD(v23) = *(_WORD *)(v9 + 1372);
      v53 = v25;
      v26 = *(unsigned __int16 *)(v9 + 1428);
      LOWORD(v54) = v23;
      v27 = *(_QWORD *)(v9 + 1324);
      v47 = *(_QWORD *)(v9 + 1316);
      v48 = v27;
      v28 = *(_QWORD *)(v9 + 1340);
      v49 = *(_QWORD *)(v9 + 1332);
      v50 = v28;
      if ( (unsigned int)lim_strip_and_decode_eht_op(
                           a3 + 104,
                           ielen_from_bss_description,
                           v9 + 2588,
                           v22 | (v26 << 32),
                           v45,
                           &v47) )
      {
        v37 = "%s: Failed to extract eht op";
LABEL_13:
        result = qdf_trace_msg(0x35u, 2u, v37, v29, v30, v31, v32, v33, v34, v35, v36, "lim_process_tpe_ie_from_beacon");
        goto LABEL_14;
      }
      v38 = *(unsigned int *)(a2 + 284);
      v39 = *(_QWORD *)(v9 + 2284);
      v40 = *(_QWORD *)(v9 + 2292);
      v53 = *(_QWORD *)(v9 + 2300);
      v51 = v39;
      v52 = v40;
      v54 = *(_DWORD *)(v9 + 2308);
      v41 = *(_QWORD *)(v9 + 2260);
      v43 = *(_QWORD *)(v9 + 2268);
      v42 = *(_QWORD *)(v9 + 2276);
      v47 = *(_QWORD *)(v9 + 2252);
      v48 = v41;
      v49 = v43;
      v50 = v42;
      if ( (unsigned int)lim_strip_and_decode_eht_cap(a3 + 104, ielen_from_bss_description, v9 + 2496, &v47, v38, 0) )
      {
        v37 = "%s: Failed to extract eht cap";
        goto LABEL_13;
      }
      if ( (unsigned int)lim_strip_and_decode_tpe_ie(a3 + 104, ielen_from_bss_description, v9 + 1432, v9 + 1430) )
      {
        v37 = "%s: Failed to extract TPE IE";
        goto LABEL_13;
      }
      lim_parse_tpe_ie(
        a1,
        a2,
        (__int64 *)(v9 + 1432),
        *(_BYTE *)(v9 + 1430),
        v29,
        v30,
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v44,
        a4);
    }
    result = _qdf_mem_free(v9);
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}

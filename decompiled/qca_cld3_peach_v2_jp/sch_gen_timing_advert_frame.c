__int64 __fastcall sch_gen_timing_advert_frame(__int64 a1, _BYTE *a2, __int64 *a3, _DWORD *a4, _DWORD *a5)
{
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  unsigned int v19; // w24
  __int64 result; // x0
  unsigned int packed_timing_advertisement_frame_size; // w0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w24
  __int64 v31; // x0
  unsigned int v32; // w24
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  int v49; // w8
  unsigned int v50; // [xsp+4h] [xbp-13Ch] BYREF
  int v51; // [xsp+8h] [xbp-138h] BYREF
  __int16 v52; // [xsp+Ch] [xbp-134h]
  _BYTE s[296]; // [xsp+10h] [xbp-130h] BYREF
  __int64 v54; // [xsp+138h] [xbp-8h]

  v54 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v52 = -1;
  v50 = 0;
  v51 = -1;
  v10 = populate_dot11f_timing_advert_frame(a1, s);
  if ( v10 )
  {
    v19 = v10;
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Error populating TA frame %x",
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      "sch_gen_timing_advert_frame",
      v10);
    result = qdf_status_to_os_return(v19);
    goto LABEL_18;
  }
  packed_timing_advertisement_frame_size = dot11f_get_packed_timing_advertisement_frame_size(a1, s, &v50);
  if ( (packed_timing_advertisement_frame_size & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Error getting packed frame size %x",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sch_gen_timing_advert_frame",
      packed_timing_advertisement_frame_size);
LABEL_17:
    result = 4294967274LL;
    goto LABEL_18;
  }
  if ( packed_timing_advertisement_frame_size )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Warning getting packed frame size",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "sch_gen_timing_advert_frame");
  v30 = v50;
  v31 = _qdf_mem_malloc(v50 + 24, "sch_gen_timing_advert_frame", 1108);
  *a3 = v31;
  if ( !v31 )
  {
    result = 4294967284LL;
    goto LABEL_18;
  }
  v50 = 0;
  v32 = dot11f_pack_timing_advertisement_frame(a1, s, v31 + 24, v30, &v50);
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: TA payload size2 = %d",
    v33,
    v34,
    v35,
    v36,
    v37,
    v38,
    v39,
    v40,
    "sch_gen_timing_advert_frame",
    v50);
  if ( (v32 & 0x10000000) != 0 )
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: Error packing frame %x",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "sch_gen_timing_advert_frame",
      v32);
    _qdf_mem_free(*a3);
    *a3 = 0;
    goto LABEL_17;
  }
  if ( v32 )
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Warning packing frame",
      v41,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      "sch_gen_timing_advert_frame");
  lim_populate_mac_header(a1, *a3, 0, 6, &v51, a2);
  *a4 = 24;
  *a5 = 34;
  dot11f_get_packed_ie_country(a1, &s[10], a5);
  if ( s[10] == 1 )
    v49 = 5;
  else
    v49 = 2;
  result = v50 + 24;
  *a5 += v49 + 3;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}

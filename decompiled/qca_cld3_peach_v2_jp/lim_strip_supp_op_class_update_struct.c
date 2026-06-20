__int64 __fastcall lim_strip_supp_op_class_update_struct(
        __int64 a1,
        unsigned __int8 *a2,
        unsigned __int16 *a3,
        __int64 a4)
{
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int v25; // w21
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  _QWORD v35[4]; // [xsp+0h] [xbp-30h] BYREF
  __int16 v36; // [xsp+20h] [xbp-10h]
  __int64 v37; // [xsp+28h] [xbp-8h]

  v37 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  memset(v35, 0, sizeof(v35));
  qdf_mem_set(v35, 0x22u, 0);
  v16 = wlan_strip_ie(a2, a3, 0x3Bu, 1, nullptr, 0, (char *)v35, 32, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( v16 )
  {
    v25 = v16;
    qdf_trace_msg(
      0x35u,
      3u,
      "%s: Failed to strip supp_op_mode IE status: %d",
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      v23,
      v24,
      "lim_strip_supp_op_class_update_struct",
      v16);
  }
  else
  {
    if ( LOBYTE(v35[0]) == 59 && BYTE1(v35[0]) < 0x21u )
    {
      if ( !(unsigned int)dot11f_unpack_ie_supp_operating_classes(a1, (char *)v35 + 2, BYTE1(v35[0]), a4, 0) )
      {
        v25 = 0;
        goto LABEL_9;
      }
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: dot11f_unpack Parse Error",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "lim_strip_supp_op_class_update_struct");
    }
    else
    {
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Invalid IEs eid: %d elem_len: %d",
        v17,
        v18,
        v19,
        v20,
        v21,
        v22,
        v23,
        v24,
        "lim_strip_supp_op_class_update_struct");
    }
    v25 = 16;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return v25;
}

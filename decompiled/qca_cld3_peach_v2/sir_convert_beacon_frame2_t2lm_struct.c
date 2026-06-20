__int64 __fastcall sir_convert_beacon_frame2_t2lm_struct(__int64 a1, __int64 a2)
{
  void *v4; // x20
  void *v5; // x21
  __int64 result; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  char *v15; // x22
  __int64 v16; // x26
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  size_t v34; // x2
  void *v35; // x0
  const char *v36; // x25
  _QWORD v37[6]; // [xsp+8h] [xbp-148h] BYREF
  int v38; // [xsp+38h] [xbp-118h]
  _BYTE s[260]; // [xsp+3Ch] [xbp-114h] BYREF
  __int64 v40; // [xsp+140h] [xbp-10h]

  v40 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, 0x102u);
  v4 = (void *)(a2 + 5796);
  v38 = 0;
  memset(v37, 0, sizeof(v37));
  qdf_mem_set((void *)(a2 + 5796), 0x34u, 0);
  v5 = (void *)(a2 + 5852);
  *(_DWORD *)(a2 + 5796) = 4;
  result = (__int64)qdf_mem_set((void *)(a2 + 5852), 0x34u, 0);
  *(_DWORD *)(a2 + 5852) = 4;
  if ( *(_WORD *)(a1 + 2870) )
  {
    result = qdf_trace_msg(
               0x35u,
               8u,
               "%s: Number of T2LM IEs in beacon %d",
               v7,
               v8,
               v9,
               v10,
               v11,
               v12,
               v13,
               v14,
               "sir_convert_beacon_frame2_t2lm_struct");
    if ( *(_WORD *)(a1 + 2870) )
    {
      v15 = (char *)(a1 + 2874);
      v16 = 1;
      while ( 1 )
      {
        qdf_mem_set(s, 0x102u, 0);
        qdf_mem_set(v37, 0x34u, 0);
        s[0] = -1;
        if ( v16 == 3 )
          __break(0x5512u);
        v34 = (unsigned __int8)*(v15 - 1);
        s[2] = 109;
        s[1] = v34 + 1;
        qdf_mem_copy(&s[3], v15, v34);
        ((void (__fastcall *)(__int64, __int64, _BYTE *, _QWORD))qdf_trace_hex_dump)(
          53,
          8,
          s,
          (unsigned int)(unsigned __int8)*(v15 - 1) + 3);
        if ( (unsigned int)wlan_mlo_parse_t2lm_info(s, v37) )
          break;
        v35 = v5;
        v36 = "%s: Parse upcoming T2LM IE success";
        if ( (v37[0] & 0x10000000000LL) != 0
          || (v35 = v4, v36 = "%s: Parse established T2LM IE success", BYTE6(v37[0]) == 1) )
        {
          qdf_mem_copy(v35, v37, 0x34u);
          qdf_trace_msg(0x35u, 8u, v36, v17, v18, v19, v20, v21, v22, v23, v24, "sir_convert_beacon_frame2_t2lm_struct");
        }
        result = qdf_trace_msg(
                   0x35u,
                   8u,
                   "%s: Parse T2LM IE success",
                   v25,
                   v26,
                   v27,
                   v28,
                   v29,
                   v30,
                   v31,
                   v32,
                   "sir_convert_beacon_frame2_t2lm_struct");
        v15 += 257;
        if ( *(unsigned __int16 *)(a1 + 2870) <= (unsigned int)(unsigned __int16)v16++ )
          goto LABEL_13;
      }
      result = qdf_trace_msg(
                 0x35u,
                 8u,
                 "%s: Parse T2LM IE fail",
                 v25,
                 v26,
                 v27,
                 v28,
                 v29,
                 v30,
                 v31,
                 v32,
                 "sir_convert_beacon_frame2_t2lm_struct");
    }
  }
LABEL_13:
  _ReadStatusReg(SP_EL0);
  return result;
}

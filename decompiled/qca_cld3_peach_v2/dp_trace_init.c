__int64 __fastcall dp_trace_init(__int64 a1)
{
  __int64 comp_private_obj; // x0
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 v10; // x19
  unsigned __int8 v11; // w24
  const char *v12; // x21
  __int64 v13; // x8
  char *v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  unsigned int v23; // w8
  unsigned int v24; // w19
  const char *v25; // x2
  __int64 result; // x0
  int v27; // w20
  unsigned __int8 v28; // w22
  unsigned int v29; // w21
  _BOOL4 v30; // w23
  int v31; // [xsp+10h] [xbp-10h] BYREF
  int v32; // [xsp+14h] [xbp-Ch]
  __int64 v33; // [xsp+18h] [xbp-8h]

  v33 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  comp_private_obj = wlan_objmgr_psoc_get_comp_private_obj(a1, 0x2Eu);
  if ( comp_private_obj )
  {
    v10 = comp_private_obj;
    qdf_dp_set_proto_event_bitmap(*(unsigned int *)(comp_private_obj + 204));
    if ( (*(_BYTE *)(v10 + 181) & 1) != 0 )
    {
      v11 = 0;
      v12 = (const char *)(v10 + 182);
      v32 = 0;
      do
      {
        v31 = 0;
        if ( sscanf(v12, "%d", &v31) == 1 )
        {
          if ( v11 > 3u )
            __break(1u);
          v13 = v11++;
          *((_BYTE *)&v32 + v13) = v31;
        }
        v14 = strchr(v12, 44);
        if ( !v14 )
          break;
        v12 = v14 + 1;
        if ( v14 == (char *)-1LL )
          break;
      }
      while ( v11 < 4u );
      v23 = *(_DWORD *)(v10 + 88);
      if ( v23 - 1 > 0x3E7 )
      {
        if ( v23 < 0x3E9 )
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: busBandwidthComputeInterval is 0, using defaults",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "dp_trace_init");
          v24 = 10;
        }
        else
        {
          qdf_trace_msg(
            0x45u,
            2u,
            "%s: busBandwidthComputeInterval > 1000, using 1000",
            v15,
            v16,
            v17,
            v18,
            v19,
            v20,
            v21,
            v22,
            "dp_trace_init");
          v24 = 1;
        }
      }
      else
      {
        v24 = 0x3E8u / (unsigned __int16)*(_DWORD *)(v10 + 88);
      }
      v27 = 126;
      v28 = 2;
      v29 = 6;
      v30 = 1;
      if ( v11 > 2u )
      {
        if ( v11 != 3 )
        {
          if ( v11 != 4 )
          {
LABEL_28:
            qdf_trace_msg(
              0x45u,
              8u,
              "%s: live_mode %u thresh %u time_limit %u verbosity %u bitmap 0x%x",
              v15,
              v16,
              v17,
              v18,
              v19,
              v20,
              v21,
              v22,
              "dp_trace_init",
              v30,
              v29,
              v24,
              v28,
              v27);
            result = (__int64)qdf_dp_trace_init((void *)v30, v29, v24, v28, v27);
            goto LABEL_29;
          }
          v27 = HIBYTE(v32);
        }
        v11 = BYTE2(v32);
      }
      else
      {
        if ( v11 == 1 )
        {
LABEL_27:
          v30 = (_BYTE)v32 != 0;
          goto LABEL_28;
        }
        if ( v11 != 2 )
          goto LABEL_28;
      }
      v29 = BYTE1(v32);
      v28 = v11;
      goto LABEL_27;
    }
    v25 = "%s: dp trace is disabled from ini";
  }
  else
  {
    v25 = "%s: Unable to get DP context";
  }
  result = qdf_trace_msg(0x45u, 2u, v25, v2, v3, v4, v5, v6, v7, v8, v9, "dp_trace_init");
LABEL_29:
  _ReadStatusReg(SP_EL0);
  return result;
}

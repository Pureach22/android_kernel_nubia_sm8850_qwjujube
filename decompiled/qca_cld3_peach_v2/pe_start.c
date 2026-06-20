__int64 __fastcall pe_start(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
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
  unsigned int v19; // w19
  __int64 result; // x0
  __int64 v21; // x8
  char v22; // w10
  __int16 v23; // w9
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  const char *v32; // x2
  __int64 v33; // x0
  __int64 v34; // x0
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  __int64 v43; // x0
  __int64 v44; // [xsp+0h] [xbp-10h] BYREF
  __int64 v45; // [xsp+8h] [xbp-8h]

  v45 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = lim_start(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  if ( v10 )
  {
    v19 = v10;
    qdf_trace_msg(0x35u, 2u, "%s: lim_start failed!", v11, v12, v13, v14, v15, v16, v17, v18, "pe_start");
    result = v19;
  }
  else
  {
    v21 = *(_QWORD *)(a1 + 8);
    HIDWORD(v44) = 0;
    v22 = *(_BYTE *)(v21 + 3407);
    LOBYTE(v44) = 0;
    *(_BYTE *)(a1 + 12411) = v22;
    v23 = *(_DWORD *)(v21 + 5612) != 0;
    *(_WORD *)(v21 + 1288) = *(_WORD *)(v21 + 1288) & 0xFFFD | (2 * v23);
    *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1293LL) = *(_BYTE *)(*(_QWORD *)(a1 + 8) + 1293LL) & 0xFB | (4 * v23);
    *(_DWORD *)(a1 + 12808) = *(_DWORD *)(*(_QWORD *)(a1 + 8) + 3720LL) != 0;
    handle_ht_capabilityand_ht_info(a1, 0);
    if ( (unsigned int)cfg_tdls_get_buffer_sta_enable(*(_QWORD *)(a1 + 21624), &v44) )
    {
      v32 = "%s: cfg get LimTDLSBufStaEnabled failed";
    }
    else
    {
      v33 = *(_QWORD *)(a1 + 21624);
      *(_BYTE *)(a1 + 11367) = v44;
      if ( (unsigned int)cfg_tdls_get_uapsd_mask(v33, (char *)&v44 + 4)
        || (v34 = *(_QWORD *)(a1 + 21624),
            *(_BYTE *)(a1 + 11368) = BYTE4(v44),
            (unsigned int)cfg_tdls_get_off_channel_enable(v34, &v44)) )
      {
        v32 = "%s: cfg get LimTDLSUapsdMask failed";
      }
      else
      {
        v43 = *(_QWORD *)(a1 + 21624);
        *(_BYTE *)(a1 + 11369) = v44;
        result = cfg_tdls_get_wmm_mode_enable(v43, &v44);
        if ( !(_DWORD)result )
        {
          *(_BYTE *)(a1 + 11370) = v44;
          goto LABEL_9;
        }
        v32 = "%s: cfg get LimTDLSWmmMode failed";
      }
    }
    qdf_trace_msg(0x35u, 2u, v32, v24, v25, v26, v27, v28, v29, v30, v31, "__lim_init_config", v44, v45);
    qdf_trace_msg(0x35u, 2u, "%s: lim init config failed!", v35, v36, v37, v38, v39, v40, v41, v42, "pe_start");
    lim_cleanup_mlm(a1);
    result = 16;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}

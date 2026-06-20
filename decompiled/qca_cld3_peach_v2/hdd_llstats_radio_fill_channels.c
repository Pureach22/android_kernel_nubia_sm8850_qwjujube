__int64 __fastcall hdd_llstats_radio_fill_channels(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v6; // x21
  __int64 v7; // x23
  int v8; // w0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x4
  _WORD *v18; // x23
  unsigned int v19; // w21
  __int64 v20; // x27
  __int64 v21; // x26
  __int64 v22; // x28
  _WORD *v23; // x26
  int *v24; // x27
  double v25; // d0
  double v26; // d1
  double v27; // d2
  double v28; // d3
  double v29; // d4
  double v30; // d5
  double v31; // d6
  double v32; // d7
  __int64 v33; // x8
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  unsigned int v42; // w8
  __int64 v43; // x4
  const char *v44; // x2
  const char *v45; // x2
  __int64 result; // x0
  int v47; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v48; // [xsp+8h] [xbp-8h]

  v48 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a3 + 216);
  v7 = *(unsigned int *)(a3 + 208);
  v8 = nla_put(a3, 32835, 0, 0);
  v17 = *(unsigned int *)(a2 + 68);
  if ( v8 < 0 || (v18 = (_WORD *)(v6 + v7)) == nullptr )
  {
    v45 = "%s: nla_nest_start failed, %u";
LABEL_22:
    qdf_trace_msg(0x33u, 2u, v45, v9, v10, v11, v12, v13, v14, v15, v16, "hdd_llstats_radio_fill_channels", v17);
    goto LABEL_25;
  }
  if ( !(_DWORD)v17 )
  {
LABEL_23:
    result = 0;
    *v18 = *(_WORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v18;
    goto LABEL_26;
  }
  v19 = 0;
  while ( 1 )
  {
    v20 = *(_QWORD *)(a2 + 72);
    v21 = *(_QWORD *)(a3 + 216);
    v22 = *(unsigned int *)(a3 + 208);
    if ( (nla_put(a3, v19 | 0x8000, 0, 0) & 0x80000000) != 0 || (v23 = (_WORD *)(v21 + v22)) == nullptr )
    {
      v17 = *(unsigned int *)(a2 + 68);
      v45 = "%s: nla_nest_start failed, chan number %u";
      goto LABEL_22;
    }
    v24 = (int *)(v20 + 32LL * (int)v19);
    v47 = *v24;
    if ( (unsigned int)nla_put(a3, 60, 4, &v47)
      || (v47 = v24[1], (unsigned int)nla_put(a3, 61, 4, &v47))
      || (v47 = v24[2], (unsigned int)nla_put(a3, 62, 4, &v47))
      || (v47 = v24[3], (unsigned int)nla_put(a3, 63, 4, &v47))
      || (v47 = v24[4], (unsigned int)nla_put(a3, 64, 4, &v47))
      || (v47 = v24[5], (unsigned int)nla_put(a3, 65, 4, &v47)) )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: nla_put failed for channel info (%u, %d, %u)",
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        "hdd_llstats_radio_fill_channels",
        *(unsigned int *)(a2 + 68),
        v19,
        (unsigned int)v24[1]);
      goto LABEL_25;
    }
    v33 = *(_QWORD *)(a1 + 24);
    if ( !v33 || *(_BYTE *)(v33 + 6944) != 1 )
      goto LABEL_5;
    v47 = v24[6];
    if ( (unsigned int)nla_put(a3, 84, 4, &v47) )
      break;
    v47 = v24[7];
    if ( (unsigned int)nla_put(a3, 85, 4, &v47) )
      break;
    v42 = v24[4];
    if ( v42 )
    {
      LOBYTE(v47) = 100 * (v24[7] + v24[6]) / v42;
      if ( (unsigned int)nla_put(a3, 86, 1, &v47) )
      {
        v43 = *(unsigned int *)(a2 + 68);
        v44 = "%s: nla_put failed for chload (%u, %d)";
        goto LABEL_29;
      }
    }
LABEL_5:
    ++v19;
    *v23 = *(_DWORD *)(a3 + 216) + *(_DWORD *)(a3 + 208) - (_WORD)v23;
    if ( v19 >= *(_DWORD *)(a2 + 68) )
      goto LABEL_23;
  }
  v43 = *(unsigned int *)(a2 + 68);
  v44 = "%s: nla_put failed for tx time (%u, %d)";
LABEL_29:
  qdf_trace_msg(0x33u, 2u, v44, v34, v35, v36, v37, v38, v39, v40, v41, "hdd_llstats_radio_fill_channels", v43, v19);
LABEL_25:
  result = 4294967274LL;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}

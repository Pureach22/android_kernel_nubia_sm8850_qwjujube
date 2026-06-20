__int64 __fastcall hdd_set_p2p_noa(__int64 a1, char *s)
{
  __int64 v4; // x22
  size_t v5; // x0
  __int64 v6; // x0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  int v15; // w0
  const char *v16; // x2
  int v17; // w5
  signed int v18; // w8
  signed int v19; // w7
  unsigned int v20; // w9
  int v21; // w10
  __int64 result; // x0
  __int64 v23; // x12
  __int64 v24; // [xsp+20h] [xbp-40h] BYREF
  __int64 v25; // [xsp+28h] [xbp-38h] BYREF
  __int128 v26; // [xsp+30h] [xbp-30h] BYREF
  unsigned __int64 v27; // [xsp+40h] [xbp-20h]
  unsigned __int64 v28; // [xsp+48h] [xbp-18h]
  int v29; // [xsp+50h] [xbp-10h]
  __int64 v30; // [xsp+58h] [xbp-8h]

  v30 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 55520);
  v29 = 0;
  v27 = 0;
  v28 = 0;
  v26 = 0u;
  v24 = 0;
  v25 = 0;
  v5 = strlen(s);
  v6 = strnchr(s, v5, 32);
  if ( !v6 )
  {
    v16 = "%s: strnchr failed to find delimiter";
    goto LABEL_20;
  }
  v15 = sscanf((const char *)(v6 + 1), "%d %d %d %d", (char *)&v25 + 4, &v24, &v25, (char *)&v24 + 4);
  if ( v15 > 2 )
  {
    if ( v15 == 3 )
    {
      v17 = *(_DWORD *)(v4 + 1412);
      HIDWORD(v24) = v17;
    }
    else
    {
      v17 = HIDWORD(v24);
    }
    if ( (int)v24 >= 0x200000
      || (v24 & 0x80000000) != 0
      || v25 < 0
      || v17 < 0
      || (v25 & 0x80000000) != 0
      || v17 >= 0x200000
      || (int)v25 >= 0x200000 )
    {
      v16 = "%s: Invalid NOA parameters";
    }
    else
    {
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: P2P_SET GO noa: count=%d interval=%d duration=%d start=%d",
        v7,
        v8,
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        "hdd_set_p2p_noa");
      *(_QWORD *)((char *)&v26 + 4) = 0;
      v18 = (_DWORD)v25 << 10;
      v19 = HIDWORD(v24) << 10;
      HIDWORD(v24) <<= 10;
      LODWORD(v25) = (_DWORD)v25 << 10;
      if ( !HIDWORD(v25) )
      {
        v21 = 2;
        v20 = v18;
        v18 = 0;
LABEL_26:
        v23 = *(_QWORD *)(a1 + 55520);
        v28 = __PAIR64__(v21, v18);
        v29 = v24;
        HIDWORD(v26) = HIDWORD(v25);
        v27 = __PAIR64__(v19, v20);
        LODWORD(v26) = *(unsigned __int8 *)(v23 + 8);
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: P2P_PS_ATTR:opp ps %d ct window %d count %d interval %d duration %d start %d single noa duration %d ps selection %x",
          v7,
          v8,
          v9,
          v10,
          v11,
          v12,
          v13,
          v14,
          "hdd_set_p2p_noa",
          0,
          0,
          v20,
          v24,
          v18,
          v21);
        result = wlan_hdd_set_power_save(a1 + 2688, &v26);
        goto LABEL_22;
      }
      if ( HIDWORD(v25) == 1 )
      {
        v20 = 0;
        v21 = 4;
        if ( v18 > v19 )
        {
          v18 = v19;
          LODWORD(v25) = v19;
        }
        goto LABEL_26;
      }
      if ( v18 < v19 )
      {
        v21 = 2;
        v20 = v18;
        v18 = 0;
        goto LABEL_26;
      }
      v16 = "%s: Duration should be less than interval";
    }
LABEL_20:
    qdf_trace_msg(0x33u, 2u, v16, v7, v8, v9, v10, v11, v12, v13, v14, "hdd_set_p2p_noa");
    goto LABEL_21;
  }
  qdf_trace_msg(
    0x33u,
    2u,
    "%s: P2P_SET GO noa: fail to read params, ret=%d",
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    v13,
    v14,
    "hdd_set_p2p_noa",
    (unsigned int)v15);
LABEL_21:
  result = 4294967274LL;
LABEL_22:
  _ReadStatusReg(SP_EL0);
  return result;
}

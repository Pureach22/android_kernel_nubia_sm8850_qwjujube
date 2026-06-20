__int64 __fastcall sir_convert_addts_rsp2_struct(__int64 a1, unsigned __int8 *a2, unsigned int a3, _BYTE *a4)
{
  __int64 v4; // x18
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w4
  __int64 v18; // x5
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w4
  unsigned int v22; // w0
  __int64 v23; // x4
  int v24; // w8
  int v25; // w10
  int v26; // w9
  const char *v27; // x2
  unsigned int v28; // w0
  __int64 result; // x0
  int v30; // w9
  int v31; // w10
  int v32; // w1
  int v33; // w2
  int v34; // w3
  char v35; // w8
  __int64 v36; // x8
  __int64 v37; // x9
  __int64 v38; // x23
  _BYTE *v39; // x21
  __int64 v40; // x22
  char v41; // w8
  __int64 v42; // [xsp+0h] [xbp-1D0h] BYREF
  __int64 v43; // [xsp+8h] [xbp-1C8h]
  __int64 v44; // [xsp+10h] [xbp-1C0h]
  __int64 v45; // [xsp+18h] [xbp-1B8h]
  __int64 v46; // [xsp+20h] [xbp-1B0h]
  __int64 v47; // [xsp+28h] [xbp-1A8h]
  __int64 v48; // [xsp+30h] [xbp-1A0h]
  __int64 v49; // [xsp+38h] [xbp-198h]
  __int64 v50; // [xsp+40h] [xbp-190h] BYREF
  _BYTE s[380]; // [xsp+4Ch] [xbp-184h] BYREF
  __int64 v52; // [xsp+1C8h] [xbp-8h]

  v52 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v17 = a2[1];
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v42 = 0;
  if ( v17 != 1 )
  {
    v27 = "%s: Action of %d; this is not supported & is probably an error";
    goto LABEL_15;
  }
  qdf_mem_set(a4, 0xBCu, 0);
  qdf_mem_set(s, 0x17Cu, 0);
  qdf_mem_set(&v42, 0x48u, 0);
  v21 = *a2;
  if ( v21 != 17 )
  {
    if ( v21 == 1 )
    {
      v22 = dot11f_unpack_add_ts_response(a1, (__int64)a2, a3, (__int64)s, 0, v18, v19, v20);
      v23 = v22;
      if ( (v22 & 0x10000000) == 0 )
        goto LABEL_5;
LABEL_13:
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Failed to parse an Add TS Response frame (0x%08x, %d bytes):",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "sir_convert_addts_rsp2_struct",
        v23,
        a3,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        v49);
      ((void (__fastcall *)(__int64, __int64, unsigned __int8 *, _QWORD))qdf_trace_hex_dump)(53, 2, a2, a3);
LABEL_16:
      result = 16;
LABEL_17:
      _ReadStatusReg(SP_EL0);
      return result;
    }
    v27 = "%s: Category of %d; this is not supported & is probably an error";
LABEL_15:
    qdf_trace_msg(0x35u, 2u, v27, v9, v10, v11, v12, v13, v14, v15, v16, "sir_convert_addts_rsp2_struct", v42);
    goto LABEL_16;
  }
  v28 = dot11f_unpack_wmm_add_ts_response(a1, (__int64)a2, a3, (__int64)&v42, 0, v18, v19, v20);
  v23 = v28;
  if ( (v28 & 0x10000000) != 0 )
    goto LABEL_13;
LABEL_5:
  if ( (_DWORD)v23 )
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: There were warnings while unpacking an Add TS Response frame (0x%08x,%d bytes):",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "sir_convert_addts_rsp2_struct",
      v23,
      a3,
      v42,
      v43,
      v44,
      v45,
      v46,
      v47,
      v48,
      v49);
  if ( *a2 != 1 )
  {
    v30 = BYTE3(v42);
    v31 = BYTE4(v42);
    *a4 = BYTE2(v42);
    *((_DWORD *)a4 + 1) = v30;
    if ( !v31 )
    {
      v27 = "%s: Mandatory WME TSPEC element missing!";
      goto LABEL_15;
    }
    a4[186] |= 2u;
    convert_wmmtspec(a1, a4 + 14, (char *)&v42 + 4);
    if ( (_BYTE)v50 )
    {
      a4[186] |= 1u;
      qdf_mem_copy(a4 + 182, (char *)&v50 + 1, 4u);
    }
    goto LABEL_58;
  }
  v24 = *(unsigned __int16 *)&s[4];
  v25 = s[8];
  *a4 = s[2];
  *((_DWORD *)a4 + 1) = v24;
  if ( v25 )
  {
    convert_ts_delay(a1, a4 + 8, &s[8]);
    v26 = s[8];
    if ( *((_DWORD *)a4 + 1) != 47 )
      goto LABEL_24;
LABEL_22:
    if ( !v26 )
      qdf_trace_msg(
        0x35u,
        3u,
        "%s: Missing TSDelay IE",
        v9,
        v10,
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        "sir_convert_addts_rsp2_struct");
    goto LABEL_24;
  }
  v26 = 0;
  if ( v24 == 47 )
    goto LABEL_22;
LABEL_24:
  if ( !s[16] )
  {
    v27 = "%s: Mandatory TSPEC element missing in Add TS Response";
    goto LABEL_15;
  }
  convert_tspec(a1, a4 + 14, &s[16]);
  if ( !*(_WORD *)&s[76] )
    goto LABEL_35;
  a4[72] = s[76];
  if ( (unsigned int)convert_tclas(a1, a4 + 73, &s[78]) )
  {
LABEL_27:
    v27 = "%s: Failed to convert a TCLAS IE";
    goto LABEL_15;
  }
  if ( *(unsigned __int16 *)&s[76] < 2u )
    goto LABEL_35;
  if ( (unsigned int)convert_tclas(a1, a4 + 119, &s[124]) )
    goto LABEL_27;
  if ( *(unsigned __int16 *)&s[76] < 3u )
    goto LABEL_35;
  if ( (unsigned int)convert_tclas(a1, a4 + 165, &s[170]) )
    goto LABEL_27;
  if ( *(unsigned __int16 *)&s[76] < 4u )
  {
LABEL_35:
    if ( s[170] )
    {
      v35 = a4[186] | 0x10;
      a4[165] = s[171];
      a4[186] = v35;
    }
    if ( s[374] )
    {
      a4[186] |= 1u;
      qdf_mem_copy(a4 + 182, &s[375], 4u);
    }
    if ( s[172] )
    {
      a4[186] |= 0x20u;
      convert_schedule(a1, a4 + 166, &s[172]);
    }
    if ( s[196] )
    {
      a4[186] |= 0x20u;
      convert_wmm_schedule(a1, a4 + 166, &s[196]);
    }
    if ( s[212] )
    {
      a4[186] |= 4u;
      convert_wmmtspec(a1, a4 + 14, &s[212]);
    }
    if ( *(_WORD *)&s[272] )
    {
      v36 = (unsigned __int8)a4[72];
      v37 = (((_BYTE)v36 + s[272]) & 0xFE) != 0 ? 2LL : (unsigned __int8)(v36 + s[272]);
      if ( (unsigned int)v36 < (unsigned int)v37 )
      {
        v38 = v37 - v36;
        v39 = &s[48 * (unsigned __int8)a4[72] + 274];
        v40 = (__int64)&a4[46 * (unsigned __int8)a4[72] + 73];
        while ( !(unsigned int)convert_wmmtclas(a1, v40, v39) )
        {
          --v38;
          v39 += 48;
          v40 += 46;
          if ( !v38 )
            goto LABEL_53;
        }
        goto LABEL_27;
      }
    }
LABEL_53:
    if ( s[370] )
    {
      v41 = a4[186] | 0x10;
      a4[165] = s[372];
      a4[186] = v41;
    }
    if ( (unsigned __int8)a4[72] >= 2u && (a4[186] & 0x10) == 0 )
    {
      v27 = "%s: %d TCLAS IE but not TCLASPROC IE";
      goto LABEL_15;
    }
LABEL_58:
    result = 0;
    goto LABEL_17;
  }
  __break(0x5512u);
  __arm_mte_get_tag((void *)(v4 - 3728));
  return sir_convert_delts_req2_struct(0, v32, v33, v34);
}

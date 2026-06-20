__int64 __fastcall wlan_t2lm_validate_candidate(__int64 a1)
{
  unsigned __int8 *v2; // x20
  unsigned int v3; // w0
  __int64 result; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  unsigned int v13; // w20
  __int64 v14; // x5
  int v15; // w8
  unsigned __int16 v16; // w20
  unsigned int v17; // w8
  unsigned __int16 v18; // w21
  __int16 v19; // w8
  _DWORD s[212]; // [xsp+8h] [xbp-358h] BYREF
  __int64 v21; // [xsp+358h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  v2 = *(unsigned __int8 **)(a1 + 1840);
  v3 = util_scan_entry_t2lm_len(a1);
  result = wlan_mlo_parse_bcn_prbresp_t2lm_ie(s, v2, v3);
  if ( (_DWORD)result )
    goto LABEL_53;
  if ( LOBYTE(s[2]) == 1 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: T2LM ie has default link mapping",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "t2lm_find_tid_mapped_link_id");
    v13 = 0xFFFF;
  }
  else
  {
    v13 = LOWORD(s[5]);
    if ( LOWORD(s[5]) != HIWORD(s[5])
      || LOWORD(s[5]) != LOWORD(s[6])
      || LOWORD(s[5]) != HIWORD(s[6])
      || LOWORD(s[5]) != LOWORD(s[7])
      || LOWORD(s[5]) != HIWORD(s[7])
      || LOWORD(s[5]) != LOWORD(s[8])
      || LOWORD(s[5]) != HIWORD(s[8]) )
    {
      goto LABEL_51;
    }
  }
  if ( LOBYTE(s[16]) == 1 )
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: T2LM ie has default link mapping",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "t2lm_find_tid_mapped_link_id");
    v14 = 0xFFFF;
    goto LABEL_20;
  }
  v14 = LOWORD(s[19]);
  if ( LOWORD(s[19]) != HIWORD(s[19])
    || LOWORD(s[19]) != LOWORD(s[20])
    || LOWORD(s[19]) != HIWORD(s[20])
    || LOWORD(s[19]) != LOWORD(s[21])
    || LOWORD(s[19]) != HIWORD(s[21])
    || LOWORD(s[19]) != LOWORD(s[22])
    || LOWORD(s[19]) != HIWORD(s[22]) )
  {
LABEL_51:
    qdf_trace_msg(
      0x68u,
      8u,
      "%s: all tids are not mapped to same link set",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "t2lm_find_tid_mapped_link_id");
    result = 16;
    goto LABEL_53;
  }
LABEL_20:
  if ( v13 )
  {
    v15 = (v13 >> 1) & 1;
    if ( (v13 & 4) != 0 )
      LOWORD(v15) = 2;
    if ( (v13 & 8) != 0 )
      LOWORD(v15) = 3;
    if ( (v13 & 0x10) != 0 )
      LOWORD(v15) = 4;
    if ( (v13 & 0x20) != 0 )
      LOWORD(v15) = 5;
    if ( (v13 & 0x40) != 0 )
      LOWORD(v15) = 6;
    if ( (v13 & 0x80) != 0 )
      v16 = 7;
    else
      v16 = v15;
    if ( (v14 & 4) != 0 )
      LOWORD(v17) = 2;
    else
      v17 = ((unsigned int)v14 >> 1) & 1;
    if ( (v14 & 8) != 0 )
      LOWORD(v17) = 3;
    if ( (v14 & 0x10) != 0 )
      LOWORD(v17) = 4;
    if ( (v14 & 0x20) != 0 )
      LOWORD(v17) = 5;
    if ( (v14 & 0x40) != 0 )
      LOWORD(v17) = 6;
    if ( (v14 & 0x80) != 0 )
      v18 = 7;
    else
      v18 = v17;
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: self link id %d established_tid_mapped_link_id 0x%x upcoming_tid_mapped_link_id 0x%x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_t2lm_validate_candidate",
      *(unsigned __int8 *)(a1 + 1919),
      v16,
      v18);
    v19 = v18 & v16;
    if ( (v18 & v16) == 0 )
      v19 = v16;
    result = 16 * (unsigned int)(*(unsigned __int8 *)(a1 + 1919) != v19);
  }
  else
  {
    qdf_trace_msg(
      0x99u,
      8u,
      "%s: established TID mapping: 0x%x not present, upcoming TID mapping: 0x%x",
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      "wlan_t2lm_validate_candidate",
      0,
      v14);
    result = 0;
  }
LABEL_53:
  _ReadStatusReg(SP_EL0);
  return result;
}

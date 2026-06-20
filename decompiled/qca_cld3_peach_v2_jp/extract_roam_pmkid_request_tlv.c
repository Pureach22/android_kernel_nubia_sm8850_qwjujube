__int64 __fastcall extract_roam_pmkid_request_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 *a10,
        unsigned int a11,
        __int64 *a12)
{
  __int64 v12; // x23
  __int64 v13; // x20
  const char *v14; // x2
  __int64 result; // x0
  __int64 v16; // x19
  const char *v17; // x2
  __int64 v18; // x4
  __int64 v19; // x22
  _BYTE *v21; // x0
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  __int64 v30; // x20
  __int64 v31; // x25
  _BYTE *v32; // x26
  unsigned int *v33; // x28
  unsigned int v34; // w11
  _BYTE *v35; // x9
  bool v36; // zf
  __int64 v37; // [xsp+0h] [xbp-20h]

  _ReadStatusReg(SP_EL0);
  if ( !a10 || !a11 )
  {
    v14 = "%s: received null event from target";
LABEL_9:
    qdf_trace_msg(0x31u, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_pmkid_request_tlv");
    goto LABEL_10;
  }
  v12 = *a10;
  if ( !*a10 )
  {
    v14 = "%s: received null event data from target";
    goto LABEL_9;
  }
  if ( *(_DWORD *)(v12 + 4) >= 6u )
  {
    v13 = jiffies;
    if ( extract_roam_pmkid_request_tlv___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x31u,
        2u,
        "%s: Invalid vdev_id %d",
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        "extract_roam_pmkid_request_tlv");
      extract_roam_pmkid_request_tlv___last_ticks = v13;
    }
    goto LABEL_10;
  }
  v16 = *((unsigned int *)a10 + 6);
  if ( (unsigned int)v16 >= 0xB )
  {
    v17 = "%s: num bssid entries:%d exceeds maximum value";
    v18 = (unsigned int)v16;
LABEL_16:
    qdf_trace_msg(0x31u, 2u, v17, a1, a2, a3, a4, a5, a6, a7, a8, "extract_roam_pmkid_request_tlv", v18);
    goto LABEL_10;
  }
  if ( 12 * (unsigned __int64)(unsigned int)v16 + 8 > a11 )
  {
    v18 = a11;
    v17 = "%s: Invalid length: %d";
    goto LABEL_16;
  }
  v19 = a10[2];
  v21 = (_BYTE *)_qdf_mem_malloc(6LL * (unsigned int)v16 + 24, "extract_roam_pmkid_request_tlv", 3478);
  if ( !v21 )
  {
    result = 2;
    goto LABEL_11;
  }
  v30 = (__int64)v21;
  *v21 = *(_DWORD *)(v12 + 4);
  if ( !(_DWORD)v16 )
  {
LABEL_29:
    result = 0;
    *(_DWORD *)(v30 + 16) = v16;
    *a12 = v30;
    goto LABEL_11;
  }
  v31 = 0;
  v32 = v21 + 20;
  v33 = (unsigned int *)(v19 + 4);
  while ( 1 )
  {
    v34 = *v33;
    v35 = &v32[v31];
    *(_WORD *)v35 = *v33;
    v35[2] = BYTE2(*v33);
    v35[3] = *((_BYTE *)v33 + 3);
    *((_WORD *)v35 + 2) = v33[1];
    if ( !(*(_DWORD *)&v32[v31] | *(unsigned __int16 *)&v32[v31 + 4]) )
      break;
    v36 = *(_DWORD *)v35 == -1 && *((__int16 *)v35 + 2) == -1;
    if ( v36 || (v34 & 1) != 0 )
      break;
    v33 += 3;
    LODWORD(v37) = *(_DWORD *)(v12 + 4);
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Received pmkid fallback for bssid: %02x:%02x:%02x:**:**:%02x vdev_id:%d",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "extract_roam_pmkid_request_tlv",
      v37);
    v31 += 6;
    if ( 6 * v16 == v31 )
      goto LABEL_29;
  }
  qdf_trace_msg(
    0x31u,
    2u,
    "%s: Invalid bssid",
    v22,
    v23,
    v24,
    v25,
    v26,
    v27,
    v28,
    v29,
    "extract_roam_pmkid_request_tlv");
  _qdf_mem_free(v30);
LABEL_10:
  result = 4;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}

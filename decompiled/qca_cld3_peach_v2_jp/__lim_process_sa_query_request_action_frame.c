__int64 __fastcall _lim_process_sa_query_request_action_frame(
        __int64 result,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w20
  __int64 v12; // x23
  __int64 v13; // x24
  const char *v15; // x2
  __int64 v16; // x22
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 v25; // x21
  __int64 v26; // [xsp+0h] [xbp-10h] BYREF
  __int64 v27; // [xsp+8h] [xbp-8h]

  v27 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = *(_DWORD *)(a2 + 40);
  WORD2(v26) = 0;
  LOWORD(v26) = 0;
  if ( v11 <= 3 )
  {
    result = qdf_trace_msg(
               0x35u,
               2u,
               "%s: Invalid frame length %d",
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "__lim_process_sa_query_request_action_frame",
               v11,
               v26,
               v27);
    goto LABEL_18;
  }
  v12 = *(_QWORD *)(a2 + 16);
  if ( (*(_WORD *)v12 & 0x4000) == 0 )
    goto LABEL_18;
  v13 = *(_QWORD *)(a2 + 24);
  if ( *(_DWORD *)(a3 + 88) == 2 && *(_BYTE *)(result + 21505) == 1 )
  {
    v15 = "%s: 11w offload enabled, SA Query req isn't expected";
LABEL_13:
    result = qdf_trace_msg(
               0x35u,
               2u,
               v15,
               a4,
               a5,
               a6,
               a7,
               a8,
               a9,
               a10,
               a11,
               "__lim_process_sa_query_request_action_frame",
               v26,
               v27);
    goto LABEL_18;
  }
  v16 = result;
  qdf_mem_copy((char *)&v26 + 4, (const void *)(v13 + 2), 2u);
  v25 = dph_lookup_hash_entry(
          v17,
          v18,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v16,
          (unsigned __int8 *)(v12 + 10),
          &v26,
          a3 + 360);
  result = lim_check_oci_match(v16, a3, v13 + 4, v12 + 10, v11 - 4);
  if ( (result & 1) != 0 )
  {
    if ( v25 && (*(_WORD *)v25 & 0x800) != 0 )
    {
      *(_WORD *)v25 &= ~0x1000u;
      *(_DWORD *)(v25 + 832) = *(_DWORD *)(a3 + 284);
    }
    result = lim_send_sa_query_response_frame(v16, (char *)&v26 + 4, v12 + 10, a3);
    if ( (_DWORD)result )
    {
      v15 = "%s: fail to send SA query response action frame";
      goto LABEL_13;
    }
  }
  else if ( v25 && (*(_WORD *)v25 & 0x800) != 0 && *(_DWORD *)(v25 + 832) != *(_DWORD *)(a3 + 284) )
  {
    *(_WORD *)v25 &= ~0x1000u;
    result = lim_send_deauth_mgmt_frame(v16, 65518, v12 + 10, a3, 0);
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}

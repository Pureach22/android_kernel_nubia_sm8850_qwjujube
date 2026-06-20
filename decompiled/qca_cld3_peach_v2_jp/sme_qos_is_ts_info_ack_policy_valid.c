__int64 __fastcall sme_qos_is_ts_info_ack_policy_valid(
        __int64 a1,
        __int64 a2,
        unsigned __int8 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // x4
  __int64 v12; // x9
  __int64 v13; // x8
  unsigned __int16 *v14; // x8
  unsigned int v16; // w19
  const char *v17; // x2
  __int64 result; // x0
  __int64 v19; // [xsp+0h] [xbp-10h] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v11 = a3;
  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v19 = 0;
  if ( !a1 || a3 > 5u || (v12 = *(_QWORD *)(a1 + 17224)) == 0 || (*(_BYTE *)(v12 + 96LL * a3 + 1) & 1) == 0 )
  {
    v17 = "%s: Session Id %d is invalid";
    goto LABEL_10;
  }
  v13 = qword_856120 + 3040LL * a3;
  if ( (*(_BYTE *)(v13 + 1) & 1) == 0 )
  {
    v17 = "%s: Session %d is inactive";
    goto LABEL_10;
  }
  v14 = *(unsigned __int16 **)(v13 + 2920);
  if ( !v14 )
  {
    v17 = "%s: Session %d has an Invalid BSS Descriptor";
    goto LABEL_10;
  }
  v16 = a3;
  if ( (unsigned int)csr_get_parsed_bss_description_ies(a1, v14, &v19) )
  {
    v17 = "%s: On session %d unable to parse BSS IEs";
    v11 = v16;
LABEL_10:
    qdf_trace_msg(
      0x34u,
      2u,
      v17,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      "sme_qos_is_ts_info_ack_policy_valid",
      v11,
      v19,
      v20);
    goto LABEL_11;
  }
  if ( *(_BYTE *)(v19 + 1256) || *(_DWORD *)(a2 + 4) != 3 )
  {
    _qdf_mem_free(v19);
    result = 1;
    goto LABEL_12;
  }
  qdf_trace_msg(
    0x34u,
    2u,
    "%s: On session %d HT Caps aren't present but application set ack policy to HT ",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "sme_qos_is_ts_info_ack_policy_valid",
    v16);
  _qdf_mem_free(v19);
LABEL_11:
  result = 0;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}

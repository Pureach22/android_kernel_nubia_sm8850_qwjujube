__int64 __fastcall extract_is_conn_ap_frm_param_tlv(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        _BYTE *a11)
{
  __int64 v11; // x8
  const char *v13; // x2

  if ( !a10 )
  {
    v13 = "%s: Got NULL point message from FW";
LABEL_8:
    qdf_trace_msg(0x31u, 2u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_is_conn_ap_frm_param_tlv");
    return 4;
  }
  if ( !a11 )
  {
    v13 = "%s:  is connected ap param is NULL";
    goto LABEL_8;
  }
  v11 = *(_QWORD *)(a10 + 128);
  if ( v11 )
  {
    *a11 = *(_DWORD *)(v11 + 4);
    a11[1] = *(_DWORD *)(v11 + 8);
  }
  return 0;
}

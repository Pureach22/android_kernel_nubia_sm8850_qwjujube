__int64 __fastcall extract_mgmt_rx_ext_params_tlv(
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
        _DWORD *a11)
{
  _DWORD *v11; // x8
  unsigned int v12; // w4
  const char *v13; // x2
  const char *v14; // x2
  int v16; // w10
  unsigned int v17; // w8

  a11[1] = 0;
  if ( !a10 )
  {
    v14 = "%s: param_tlvs is NULL";
LABEL_10:
    qdf_trace_msg(0x31u, 2u, v14, a1, a2, a3, a4, a5, a6, a7, a8, "extract_mgmt_rx_ext_params_tlv");
    return 4;
  }
  if ( !*(_QWORD *)a10 )
  {
    v14 = "%s: Rx event is NULL";
    goto LABEL_10;
  }
  v11 = *(_DWORD **)(a10 + 64);
  if ( v11 )
  {
    if ( (v11[1] & 7) == 1 )
    {
      *a11 = 1;
      v16 = (unsigned __int16)v11[3];
      *((_WORD *)a11 + 2) = v11[3];
      if ( (unsigned int)(v16 - 1) <= 0xFD )
        qdf_mem_copy((char *)a11 + 6, *(const void **)(a10 + 176), (unsigned int)v11[3]);
    }
    else if ( (v11[1] & 7) == 0 )
    {
      *a11 = 0;
      v12 = (unsigned __int16)v11[2];
      *((_WORD *)a11 + 2) = v11[2];
      if ( v12 >= 0x401 )
      {
        v13 = "%s: ba win size %d from TLV is Invalid";
LABEL_15:
        qdf_trace_msg(0x31u, 4u, v13, a1, a2, a3, a4, a5, a6, a7, a8, "extract_mgmt_rx_ext_params_tlv");
        return 4;
      }
      v17 = v11[2];
      *((_WORD *)a11 + 3) = HIWORD(v17);
      if ( HIWORD(v17) >= 0x801u )
      {
        v13 = "%s: reo win size %d from TLV is Invalid";
        goto LABEL_15;
      }
    }
  }
  return 0;
}

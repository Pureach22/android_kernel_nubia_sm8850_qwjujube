__int64 __fastcall qdf_dp_trace_data_pkt(__int64 result, unsigned int a2, unsigned int a3, unsigned __int16 a4, int a5)
{
  __int64 v8; // x21
  int v10; // w8
  unsigned int v11; // w8
  unsigned __int8 *v12; // x24
  __int64 v13; // x25
  unsigned int arp_subtype; // w3
  unsigned int v15; // w2
  bool is_dns_query; // w0
  __int64 v17; // x2
  _BOOL8 v18; // x6
  __int64 v19; // x3
  unsigned __int16 v20; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+8h] [xbp-8h]

  v8 = result;
  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !result )
  {
LABEL_9:
    v10 = 8;
    if ( a3 != 1 )
      goto LABEL_26;
    goto LABEL_10;
  }
  result = _qdf_nbuf_data_is_dns_query(*(_QWORD *)(result + 224));
  if ( (result & 1) == 0 )
  {
    result = _qdf_nbuf_data_is_dns_response(*(_QWORD *)(v8 + 224));
    if ( (result & 1) == 0 )
    {
      v11 = ((*(unsigned __int8 *)(v8 + 71) >> 3) & 0xF) - 1;
      if ( v11 <= 3 )
      {
        v10 = dword_A30300[v11];
        if ( a3 != 1 )
          goto LABEL_26;
        goto LABEL_10;
      }
      goto LABEL_9;
    }
  }
  v10 = 7;
  if ( a3 != 1 )
    goto LABEL_26;
LABEL_10:
  if ( v10 > 1 )
  {
    if ( v10 == 2 )
    {
      if ( (dword_73EC70 & 0x10) == 0 )
        goto LABEL_26;
      v12 = *(unsigned __int8 **)(v8 + 224);
      v13 = (__int64)(v12 + 6);
      arp_subtype = _qdf_nbuf_data_get_arp_subtype((__int64)v12);
      v15 = 2;
      goto LABEL_25;
    }
    if ( v10 == 7 && (dword_73EC70 & 1) != 0 )
    {
      v12 = *(unsigned __int8 **)(v8 + 224);
      v13 = (__int64)(v12 + 6);
      is_dns_query = _qdf_nbuf_data_is_dns_query((__int64)v12);
      v15 = 7;
      if ( is_dns_query )
        arp_subtype = 35;
      else
        arp_subtype = 36;
      goto LABEL_25;
    }
  }
  else
  {
    if ( !v10 )
    {
      if ( (dword_73EC70 & 4) == 0 )
        goto LABEL_26;
      v12 = *(unsigned __int8 **)(v8 + 224);
      v13 = (__int64)(v12 + 6);
      arp_subtype = _qdf_nbuf_data_get_dhcp_subtype(v12);
      v15 = 0;
      goto LABEL_25;
    }
    if ( v10 == 1 && (dword_73EC70 & 2) != 0 )
    {
      v12 = *(unsigned __int8 **)(v8 + 224);
      v13 = (__int64)(v12 + 6);
      arp_subtype = _qdf_nbuf_data_get_eapol_subtype((__int64)v12);
      v15 = 1;
LABEL_25:
      result = qdf_dp_log_proto_pkt_info(v13, v12, v15, arp_subtype, 0, a4, 4u);
    }
  }
LABEL_26:
  v20 = a4;
  if ( byte_73EC28 != 1 )
    goto LABEL_52;
  if ( (unsigned __int8)byte_73EC26 > 1u )
  {
    if ( byte_73EC26 == 2 )
    {
      if ( a3 >= 0x17 )
        goto LABEL_52;
    }
    else if ( byte_73EC26 != 4 && (byte_73EC26 != 3 || a3 >= 0x23) )
    {
      goto LABEL_52;
    }
LABEL_40:
    if ( !v8 || a5 )
    {
      if ( v8 && a5 == 1 )
      {
        if ( (*(_BYTE *)(v8 + 85) & 1) == 0 )
          goto LABEL_52;
      }
      else if ( !v8 )
      {
        v19 = 0;
        v17 = 0;
        v18 = 0;
        goto LABEL_51;
      }
    }
    else if ( (*(_BYTE *)(v8 + 71) & 1) == 0 || (*(_WORD *)(v8 + 69) & 0x700) != 0x100 )
    {
      goto LABEL_52;
    }
    v17 = *(_QWORD *)(v8 + 224);
    v18 = *(char *)(v8 + 71) < 0;
    v19 = (unsigned int)(*(_DWORD *)(v8 + 112) - *(_DWORD *)(v8 + 116));
LABEL_51:
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, __int64, unsigned __int16 *, __int64, _BOOL8))qdf_dp_add_record)(
               a3,
               a2,
               v17,
               v19,
               &v20,
               2,
               v18);
    goto LABEL_52;
  }
  if ( !byte_73EC26 )
  {
    if ( a3 > 7 )
      goto LABEL_52;
    goto LABEL_40;
  }
  if ( byte_73EC26 == 1 && a3 < 0xE )
    goto LABEL_40;
LABEL_52:
  _ReadStatusReg(SP_EL0);
  return result;
}

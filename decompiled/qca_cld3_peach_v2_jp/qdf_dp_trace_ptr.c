__int64 __fastcall qdf_dp_trace_ptr(
        __int64 result,
        unsigned int a2,
        unsigned int a3,
        const void *a4,
        unsigned __int8 a5,
        unsigned __int16 a6,
        __int16 a7,
        unsigned int a8,
        unsigned int a9)
{
  __int64 v12; // x23
  unsigned int v17; // w27
  int v18; // w8
  unsigned int arp_subtype; // w0
  unsigned int v20; // w28
  __int64 v21; // x6
  unsigned int v22; // [xsp+4h] [xbp-1Ch]
  __int64 v23; // [xsp+8h] [xbp-18h] BYREF
  __int64 v24; // [xsp+10h] [xbp-10h]
  __int64 v25; // [xsp+18h] [xbp-8h]

  v12 = result;
  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v23 = 0;
  v24 = 0;
  if ( !result )
    goto LABEL_7;
  result = _qdf_nbuf_data_is_dns_query(*(_QWORD *)(result + 224));
  if ( (result & 1) != 0 || (result = _qdf_nbuf_data_is_dns_response(*(_QWORD *)(v12 + 224)), (result & 1) != 0) )
  {
    v17 = 7;
    goto LABEL_8;
  }
  v18 = ((*(unsigned __int8 *)(v12 + 71) >> 3) & 0xF) - 1;
  if ( (unsigned int)v18 <= 3 )
    v17 = dword_A30300[v18];
  else
LABEL_7:
    v17 = 8;
LABEL_8:
  if ( (a2 & 0xFFFFFFFE) != 0x14 )
    goto LABEL_28;
  if ( (int)v17 > 1 )
  {
    if ( v17 == 2 )
    {
      if ( (unsigned __int16)a8 != 1 && (dword_73EC70 & 0x10) != 0 )
      {
        v22 = a3;
        arp_subtype = _qdf_nbuf_data_get_arp_subtype(*(_QWORD *)(v12 + 224));
        goto LABEL_26;
      }
    }
    else if ( v17 == 7 && (unsigned __int16)a8 != 1 && (dword_73EC70 & 1) != 0 )
    {
      v22 = a3;
      if ( _qdf_nbuf_data_is_dns_query(*(_QWORD *)(v12 + 224)) )
        v20 = 35;
      else
        v20 = 36;
      goto LABEL_27;
    }
  }
  else
  {
    if ( !v17 )
    {
      if ( (dword_73EC70 & 4) == 0 )
        goto LABEL_28;
      v22 = a3;
      arp_subtype = _qdf_nbuf_data_get_dhcp_subtype(*(_BYTE **)(v12 + 224));
      goto LABEL_26;
    }
    if ( v17 == 1 && (dword_73EC70 & 2) != 0 )
    {
      v22 = a3;
      arp_subtype = _qdf_nbuf_data_get_eapol_subtype(*(_QWORD *)(v12 + 224));
LABEL_26:
      v20 = arp_subtype;
LABEL_27:
      qdf_dp_log_proto_pkt_info(*(_QWORD *)(v12 + 224) + 6LL, *(unsigned __int8 **)(v12 + 224), v17, v20, 0, a6, a8);
      qdf_fill_wlan_connectivity_log(
        v17,
        v20,
        0,
        a8,
        a9,
        *(unsigned __int8 *)(v12 + 65),
        v12,
        (*(unsigned __int8 *)(v12 + 61) >> 1) & 7);
      result = wlan_cp_stats_cstats_pkt_log(
                 *(_QWORD *)(v12 + 224) + 6LL,
                 *(_QWORD *)(v12 + 224),
                 v17,
                 v20,
                 0,
                 a8,
                 *(unsigned __int8 *)(v12 + 65),
                 a9);
      a3 = v22;
    }
  }
LABEL_28:
  if ( byte_73EC28 != 1 )
    goto LABEL_46;
  if ( (unsigned __int8)byte_73EC26 <= 1u )
  {
    if ( byte_73EC26 )
    {
      if ( byte_73EC26 != 1 || a2 >= 0xE )
        goto LABEL_46;
    }
    else if ( a2 > 7 )
    {
      goto LABEL_46;
    }
  }
  else if ( byte_73EC26 == 2 )
  {
    if ( a2 >= 0x17 )
      goto LABEL_46;
  }
  else if ( byte_73EC26 != 4 && (byte_73EC26 != 3 || a2 >= 0x23) )
  {
    goto LABEL_46;
  }
  if ( !v12 || (*(_BYTE *)(v12 + 71) & 1) != 0 && (*(_WORD *)(v12 + 69) & 0x700) == 0x100 )
  {
    qdf_mem_copy(&v23, a4, a5);
    v21 = *(unsigned __int8 *)(v12 + 71) >> 7;
    LOWORD(v24) = a6;
    WORD1(v24) = a7;
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64 *, __int64, _QWORD, _QWORD, __int64))qdf_dp_add_record)(
               a2,
               a3,
               &v23,
               16,
               0,
               0,
               v21);
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return result;
}

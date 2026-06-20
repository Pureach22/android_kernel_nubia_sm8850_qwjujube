__int64 __fastcall qdf_dp_track_noack_check(__int64 result, _DWORD *a2)
{
  __int64 v3; // x20
  int v4; // w9
  int v5; // w8
  int v6; // w8

  if ( result )
  {
    v3 = result;
    if ( _qdf_nbuf_data_is_dns_query(*(_QWORD *)(result + 224)) || _qdf_nbuf_data_is_dns_response(*(_QWORD *)(v3 + 224)) )
    {
      if ( byte_7F7658 != 1 )
        goto LABEL_21;
      v4 = dword_7F764C & 1;
      v5 = 7;
    }
    else
    {
      v6 = (*(unsigned __int8 *)(v3 + 71) >> 3) & 0xF;
      if ( v6 == 4 )
      {
        v5 = 0;
        if ( (byte_7F7658 & 1) == 0 )
        {
          result = 0;
          goto LABEL_22;
        }
        v4 = dword_7F764C & 4;
      }
      else if ( v6 == 2 )
      {
        if ( (byte_7F7658 & 1) == 0 )
          goto LABEL_21;
        v4 = dword_7F764C & 0x10;
        v5 = 2;
      }
      else
      {
        if ( v6 != 1 || (byte_7F7658 & 1) == 0 )
          goto LABEL_21;
        v4 = dword_7F764C & 2;
        v5 = 1;
      }
    }
    if ( v4 )
    {
      if ( v5 > 1 )
      {
        if ( v5 == 2 )
        {
          result = _qdf_nbuf_data_get_arp_subtype(*(_QWORD *)(v3 + 224));
        }
        else if ( _qdf_nbuf_data_is_dns_query(*(_QWORD *)(v3 + 224)) )
        {
          result = 35;
        }
        else
        {
          result = 36;
        }
      }
      else if ( v5 )
      {
        result = _qdf_nbuf_data_get_eapol_subtype(*(_QWORD *)(v3 + 224));
      }
      else
      {
        result = _qdf_nbuf_data_get_dhcp_subtype(*(_BYTE **)(v3 + 224));
      }
      goto LABEL_22;
    }
LABEL_21:
    result = 0;
  }
LABEL_22:
  *a2 = result;
  return result;
}

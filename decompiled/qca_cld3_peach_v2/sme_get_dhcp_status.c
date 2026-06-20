__int64 __fastcall sme_get_dhcp_status(__int64 a1, unsigned __int8 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x8
  char v13; // w20

  if ( (unsigned int)qdf_mutex_acquire(a1 + 12848) )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Failed to acquire sme lock", v4, v5, v6, v7, v8, v9, v10, v11, "sme_get_dhcp_status");
LABEL_7:
    v13 = 0;
    return v13 & 1;
  }
  if ( a2 > 5u || (v12 = *(_QWORD *)(a1 + 17296) + 96LL * a2) == 0 )
  {
    qdf_trace_msg(0x34u, 2u, "%s: Session: %d not found", v4, v5, v6, v7, v8, v9, v10, v11, "sme_get_dhcp_status");
    qdf_mutex_release(a1 + 12848);
    goto LABEL_7;
  }
  v13 = *(_BYTE *)(v12 + 88);
  qdf_mutex_release(a1 + 12848);
  return v13 & 1;
}

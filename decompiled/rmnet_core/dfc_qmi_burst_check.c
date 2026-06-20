__int64 __fastcall dfc_qmi_burst_check(__int64 a1, __int64 a2, unsigned int a3, unsigned int a4, unsigned int a5)
{
  __int64 flow_map; // x0
  __int64 v11; // x23
  unsigned int v12; // w8
  unsigned int v13; // w10
  unsigned int v14; // w9

  raw_spin_lock_bh(a2 + 332);
  flow_map = qmi_rmnet_get_flow_map(a2, a4, a3);
  if ( flow_map )
  {
    v11 = *(_QWORD *)(flow_map + 32);
    if ( v11 )
    {
      v12 = *(_DWORD *)(v11 + 24);
      *(_DWORD *)(v11 + 44) += a5;
      if ( v12 )
      {
        v13 = *(_DWORD *)(v11 + 28);
        v14 = v12 - a5;
        if ( v12 < a5 )
          v14 = 0;
        *(_DWORD *)(v11 + 24) = v14;
        if ( v12 > v13 )
        {
          if ( v14 > v13 )
            return raw_spin_unlock_bh(a2 + 332);
          dfc_send_ack(a1, *(unsigned __int8 *)(v11 + 16), *(unsigned __int16 *)(v11 + 32), *(_BYTE *)(a2 + 16), 2);
          v14 = *(_DWORD *)(v11 + 24);
        }
        if ( !v14 )
        {
          if ( *(_DWORD *)(v11 + 64) != 255 )
            qmi_rmnet_flow_control(a1);
          qmi_rmnet_flow_control(a1);
          if ( *(_BYTE *)(v11 + 34) )
            dfc_send_ack(a1, *(unsigned __int8 *)(v11 + 16), *(unsigned __int16 *)(v11 + 32), *(_BYTE *)(a2 + 16), 1);
        }
      }
    }
  }
  return raw_spin_unlock_bh(a2 + 332);
}

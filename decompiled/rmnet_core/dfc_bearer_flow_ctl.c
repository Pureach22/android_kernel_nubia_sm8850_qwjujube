__int64 __fastcall dfc_bearer_flow_ctl(__int64 a1, __int64 a2, __int64 a3)
{
  int v5; // w22

  v5 = *(_DWORD *)(a2 + 24);
  if ( *(_DWORD *)(a2 + 64) != 255 )
    qmi_rmnet_flow_control(a1);
  qmi_rmnet_flow_control(a1);
  if ( !v5 && *(_BYTE *)(a2 + 34) )
    dfc_send_ack(a1, *(unsigned __int8 *)(a2 + 16), *(unsigned __int16 *)(a2 + 32), *(unsigned __int8 *)(a3 + 16), 1);
  return 0;
}

__int64 __fastcall dfc_all_bearer_flow_ctl(__int64 result, __int64 a2, char a3, char a4, __int64 a5)
{
  __int64 *v5; // x23
  __int64 *v6; // x24
  __int64 v10; // x22
  char v11; // w25
  __int64 v12; // x0
  int v13; // w1
  int v14; // w26
  __int16 v15; // w8

  v5 = (__int64 *)(a2 + 56);
  v6 = *(__int64 **)(a2 + 56);
  if ( v6 != (__int64 *)(a2 + 56) )
  {
    v10 = result;
    v11 = a4 & 1;
    do
    {
      v12 = *(unsigned int *)(a5 + 4);
      *((_DWORD *)v6 + 6) = v12;
      *((_DWORD *)v6 + 7) = qmi_rmnet_grant_per(v12);
      v13 = *((_DWORD *)v6 + 16);
      v14 = *((_DWORD *)v6 + 6);
      v15 = *(_WORD *)(a5 + 8);
      *((_BYTE *)v6 + 34) = a3;
      *((_BYTE *)v6 + 52) = v11;
      *((_WORD *)v6 + 16) = v15;
      *((_DWORD *)v6 + 9) = *(_DWORD *)(a5 + 4);
      *((_WORD *)v6 + 20) = *(_WORD *)(a5 + 8);
      *((_DWORD *)v6 + 12) = *(_DWORD *)(a5 + 4);
      if ( v13 != 255 )
        qmi_rmnet_flow_control(v10);
      result = qmi_rmnet_flow_control(v10);
      if ( !v14 )
      {
        if ( *((_BYTE *)v6 + 34) )
          result = dfc_send_ack(
                     v10,
                     *((unsigned __int8 *)v6 + 16),
                     *((unsigned __int16 *)v6 + 16),
                     *(_BYTE *)(a2 + 16),
                     1);
      }
      v6 = (__int64 *)*v6;
    }
    while ( v6 != v5 );
  }
  return result;
}

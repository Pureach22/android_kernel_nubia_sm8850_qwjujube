__int64 __fastcall gsi_rndis_open(__int64 a1)
{
  __int64 v1; // x8
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned int v5; // w9
  unsigned int v6; // w8
  __int64 v7; // x2

  v1 = *(_QWORD *)(a1 + 48);
  v3 = *(_QWORD *)(a1 + 264);
  v4 = **(_QWORD **)(v1 + 48);
  v5 = *(_DWORD *)(v4 + 76);
  if ( v5 < 5 )
  {
    if ( v5 < 3 )
      goto LABEL_8;
    v6 = *(_DWORD *)(v4 + 72);
LABEL_6:
    if ( v6 == 3 )
    {
      v7 = 4259840;
      goto LABEL_9;
    }
LABEL_8:
    v7 = 97280;
    goto LABEL_9;
  }
  v6 = *(_DWORD *)(v4 + 72);
  if ( v6 <= 4 )
    goto LABEL_6;
  v7 = 8519680;
LABEL_9:
  rndis_set_param_medium(v3, 0, v7);
  return rndis_signal_connect(*(_QWORD *)(a1 + 264));
}

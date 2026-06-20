__int64 __fastcall wlan_crypto_set_sae_single_pmk_bss_cap(__int64 a1, __int64 a2, char a3)
{
  __int64 result; // x0
  double v6; // d0
  double v7; // d1
  double v8; // d2
  double v9; // d3
  double v10; // d4
  double v11; // d5
  double v12; // d6
  double v13; // d7
  __int64 v14; // x8
  __int64 v15; // x10
  int *v16; // x11
  int v17; // w13
  int v18; // w11

  result = wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !result )
    return qdf_trace_msg(
             0x1Cu,
             2u,
             "%s: crypto_priv NULL",
             v6,
             v7,
             v8,
             v9,
             v10,
             v11,
             v12,
             v13,
             "wlan_crypto_set_sae_single_pmk_bss_cap");
  v14 = 0;
  v15 = result + 24;
  do
  {
    v16 = *(int **)(v15 + v14);
    if ( v16 )
    {
      v17 = *v16;
      v18 = *((unsigned __int16 *)v16 + 2);
      if ( *(_DWORD *)a2 == v17 && *(unsigned __int16 *)(a2 + 4) == v18 )
        *(_BYTE *)(*(_QWORD *)(v15 + v14) + 144LL) = a3 & 1;
    }
    v14 += 8;
  }
  while ( v14 != 128 );
  return result;
}

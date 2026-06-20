char *__fastcall wlan_crypto_set_sae_single_pmk_info(__int64 a1, __int64 a2)
{
  char *result; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  __int64 v12; // x20
  char *v13; // x21
  int *v14; // x8
  int v15; // w10
  int v16; // w8
  bool v17; // zf
  size_t v18; // x2

  result = (char *)wlan_objmgr_vdev_get_comp_private_obj(a1, 14);
  if ( !result )
    return (char *)qdf_trace_msg(
                     0x1Cu,
                     2u,
                     "%s: crypto_priv NULL",
                     v4,
                     v5,
                     v6,
                     v7,
                     v8,
                     v9,
                     v10,
                     v11,
                     "wlan_crypto_set_sae_single_pmk_info");
  v12 = 0;
  v13 = result + 24;
  do
  {
    v14 = *(int **)&v13[v12];
    if ( v14 )
    {
      v15 = *v14;
      v16 = *((unsigned __int16 *)v14 + 2);
      v17 = *(_DWORD *)a2 == v15 && *(unsigned __int16 *)(a2 + 4) == v16;
      if ( v17 && *(_BYTE *)(a2 + 144) == 1 )
      {
        if ( *(_BYTE *)(a2 + 86) )
        {
          *(_BYTE *)(*(_QWORD *)&v13[v12] + 144LL) = 1;
          v18 = *(unsigned __int8 *)(a2 + 86);
          *(_BYTE *)(*(_QWORD *)&v13[v12] + 86LL) = v18;
          result = (char *)qdf_mem_copy((void *)(*(_QWORD *)&v13[v12] + 22LL), (const void *)(a2 + 22), v18);
        }
      }
    }
    v12 += 8;
  }
  while ( v12 != 128 );
  return result;
}

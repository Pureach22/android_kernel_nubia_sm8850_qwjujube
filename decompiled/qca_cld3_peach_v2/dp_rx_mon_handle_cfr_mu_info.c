__int64 __fastcall dp_rx_mon_handle_cfr_mu_info(__int64 result, __int64 a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v4; // x19
  char *v5; // x20
  __int64 v6; // x23
  __int64 v7; // x22
  __int64 v8; // x21
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7

  if ( *(_BYTE *)(a2 + 19) )
  {
    v3 = *(unsigned __int8 *)(a2 + 19) - 1;
    v4 = *(_QWORD *)(result + 8);
    v5 = (char *)(a3 + 422);
    v6 = a2 + 416;
    if ( v3 >= 0x24 )
      v3 = 36;
    v7 = v3 + 1;
    do
    {
      result = dp_peer_get_ref_by_id_1(v4, *(unsigned __int16 *)(v6 + 2));
      if ( result )
      {
        v8 = result;
        qdf_mem_copy(v5, (const void *)(result + 44), 6u);
        result = dp_peer_unref_delete(v8, 6u, v9, v10, v11, v12, v13, v14, v15, v16);
      }
      else
      {
        *((_WORD *)v5 - 27) = -1;
      }
      --v7;
      v6 += 344;
      v5 += 128;
    }
    while ( v7 );
  }
  return result;
}

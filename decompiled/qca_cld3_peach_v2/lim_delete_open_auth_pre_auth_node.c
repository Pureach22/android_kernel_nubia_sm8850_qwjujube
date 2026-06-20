__int64 __fastcall lim_delete_open_auth_pre_auth_node(__int64 a1)
{
  _QWORD *v1; // x22
  unsigned int v3; // w20
  _QWORD *v4; // x21
  _QWORD *v5; // x24
  _QWORD *v6; // x23
  _QWORD *v7; // x8
  int v8; // w9
  __int64 v9; // x20

  v1 = *(_QWORD **)(a1 + 11424);
  if ( v1 )
  {
    v3 = 0;
    v4 = (_QWORD *)(a1 + 11424);
    v5 = *(_QWORD **)(a1 + 11424);
    do
    {
      if ( *((_DWORD *)v1 + 5) != 9
        || *((_DWORD *)v1 + 4)
        || qdf_mc_timer_get_system_ticks() <= v1[69] + 500LL && qdf_mc_timer_get_system_ticks() >= v1[69] )
      {
        v6 = (_QWORD *)*v1;
      }
      else
      {
        v6 = (_QWORD *)*v1;
        if ( (_QWORD *)*v4 == v1 )
          v7 = v4;
        else
          v7 = v5;
        if ( (_QWORD *)*v4 == v1 )
          v5 = (_QWORD *)*v1;
        *v7 = v6;
        v8 = *((_DWORD *)v1 + 4);
        *((_BYTE *)v1 + 278) |= 4u;
        if ( v8 == 3 && *((_BYTE *)v1 + 560) == 1 )
        {
          v9 = v1[71];
          lim_free_assoc_req_frm_buf(v9);
          _qdf_mem_free(v9);
          v1[71] = 0;
          *((_BYTE *)v1 + 560) = 0;
        }
        qdf_trace(53, 0xEu, 255, 7);
        tx_timer_deactivate(v1 + 35);
        v3 = 1;
        v1 = v5;
        --*(_DWORD *)(a1 + 11404);
      }
      v5 = v1;
      v1 = v6;
    }
    while ( v6 );
  }
  else
  {
    return 0;
  }
  return v3;
}

__int64 __fastcall ipa_get_gsi_pipe_info(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v5; // x9
  int v6; // w8
  unsigned int v7; // w21
  unsigned int peripheral_ee; // w0
  unsigned int v9; // w21
  unsigned int v10; // w0
  unsigned int v11; // w21
  unsigned int v12; // w0
  __int64 v13; // x0
  int v14; // w8
  unsigned int v15; // w20
  unsigned int v16; // w0
  __int64 result; // x0

  v2 = *(_DWORD *)(a2 + 4);
  *(_DWORD *)(a1 + 84) = v2;
  v5 = *(_QWORD *)(a2 + 472);
  if ( v5 )
  {
    *(_DWORD *)(a1 + 56) = *(_DWORD *)(v5 + 1600);
    *(_DWORD *)(a1 + 96) = *(unsigned __int8 *)(*(_QWORD *)(a2 + 472) + 124LL);
    v2 = *(_DWORD *)(a2 + 4);
  }
  *(_DWORD *)(a1 + 60) = 0;
  if ( v2 >= 0x86 )
    v6 = 0;
  else
    v6 = v2 & 1;
  *(_DWORD *)(a1 + 80) = v6;
  *(_DWORD *)(a1 + 88) = *(_QWORD *)(a2 + 8);
  *(_DWORD *)(a1 + 92) = *(_QWORD *)(a2 + 16);
  *(_DWORD *)(a1 + 100) = gsi_get_chan_prot_type(*(unsigned int *)(a2 + 8));
  *(_DWORD *)(a1 + 104) = gsi_get_chan_state(*(unsigned int *)(a2 + 8));
  v7 = *(_DWORD *)(a2 + 8);
  peripheral_ee = gsi_get_peripheral_ee();
  *(_DWORD *)(a1 + 108) = gsi_get_chan_stop_stm(v7, peripheral_ee);
  *(_DWORD *)(a1 + 112) = gsi_get_chan_poll_mode(*(unsigned int *)(a2 + 8));
  *(_DWORD *)(a1 + 52) = gsi_get_ring_len(*(unsigned int *)(a2 + 8));
  *(_DWORD *)(a1 + 116) = (unsigned __int8)gsi_get_chan_props_db_in_bytes(*(unsigned int *)(a2 + 8));
  *(_QWORD *)a1 = gsi_read_chan_ring_bp(*(unsigned int *)(a2 + 8));
  v9 = *(_DWORD *)(a2 + 8);
  v10 = gsi_get_peripheral_ee();
  *(_QWORD *)(a1 + 8) = gsi_read_chan_ring_rp(v9, v10);
  v11 = *(_DWORD *)(a2 + 8);
  v12 = gsi_get_peripheral_ee();
  *(_QWORD *)(a1 + 16) = gsi_read_chan_ring_wp(v11, v12);
  v13 = ((__int64 (__fastcall *)(_QWORD))ipa_get_gsi_ep_info)(*(unsigned int *)(a2 + 4));
  if ( v13 )
  {
    *(_DWORD *)(a1 + 64) = *(_DWORD *)(v13 + 8);
    v14 = *(_DWORD *)(v13 + 12);
  }
  else
  {
    v14 = 0;
    *(_DWORD *)(a1 + 64) = 0;
  }
  *(_DWORD *)(a1 + 68) = v14;
  *(_DWORD *)(a1 + 72) = gsi_get_evt_ring_re_size(*(unsigned int *)(a2 + 16));
  *(_DWORD *)(a1 + 48) = gsi_get_evt_ring_len(*(unsigned int *)(a2 + 16));
  *(_QWORD *)(a1 + 24) = gsi_read_event_ring_bp(*(unsigned int *)(a2 + 16));
  *(_QWORD *)(a1 + 32) = gsi_get_evt_ring_rp(*(unsigned int *)(a2 + 16));
  v15 = *(_DWORD *)(a2 + 16);
  v16 = gsi_get_peripheral_ee();
  result = gsi_read_event_ring_wp(v15, v16);
  *(_QWORD *)(a1 + 40) = result;
  return result;
}

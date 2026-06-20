__int64 __fastcall lim_handle_delete_bss_rsp(__int64 a1, __int64 a2)
{
  __int64 session_by_vdev_id_and_state; // x0
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7
  int v13; // w8

  session_by_vdev_id_and_state = pe_find_session_by_vdev_id_and_state(a1, *(unsigned __int8 *)(a2 + 4), 17);
  if ( session_by_vdev_id_and_state )
  {
    v13 = *(_DWORD *)(session_by_vdev_id_and_state + 88);
    *(_BYTE *)(session_by_vdev_id_and_state + 8674) = 0;
    if ( v13 == 6 )
    {
      lim_ndi_del_bss_rsp(a1, a2, session_by_vdev_id_and_state);
    }
    else if ( v13 )
    {
      lim_process_mlm_del_bss_rsp(a1, a2, session_by_vdev_id_and_state, v5, v6, v7, v8, v9, v10, v11, v12);
    }
    else
    {
      lim_process_sme_del_bss_rsp(a1, session_by_vdev_id_and_state, v5, v6, v7, v8, v9, v10, v11, v12);
    }
  }
  return _qdf_mem_free(a2);
}

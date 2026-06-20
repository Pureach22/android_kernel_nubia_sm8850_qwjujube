__int64 __fastcall lim_mgmt_tdls_tx_complete(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v11; // w8
  _BOOL4 v14; // w22
  int v16; // w9
  unsigned __int8 *v17; // x23
  int v18; // w0

  v11 = *(_DWORD *)(a1 + 12368);
  if ( v11 == 255 )
  {
    v14 = 0;
  }
  else
  {
    if ( a2
      && ((*(_BYTE *)(a2 + 68) & 4) != 0 ? (v16 = *(unsigned __int16 *)(a2 + 66)) : (v16 = 0),
          (unsigned int)(*(_DWORD *)(a2 + 112) + v16) >= 0x11) )
    {
      v17 = *(unsigned __int8 **)(a2 + 224);
      v18 = qdf_mem_cmp(v17 + 12, &eth_890d_tdls_discvory_frm_hdr, 5u);
      v11 = *(_DWORD *)(a1 + 12368);
      v14 = v18 == 0;
      if ( !(v18 | a3) )
      {
        wlan_tdls_increment_discovery_attempts(*(_QWORD *)(a1 + 21552), v11, v17);
        v11 = *(_DWORD *)(a1 + 12368);
      }
    }
    else
    {
      v14 = 0;
    }
    lim_send_sme_mgmt_tx_completion(a1, v11, a3);
    *(_DWORD *)(a1 + 12368) = 255;
  }
  qdf_trace_msg(
    0x35u,
    8u,
    "%s: tdls_frm_session_id: %x tx_complete: %x is_discovery:%d",
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    "lim_mgmt_tdls_tx_complete",
    255,
    a3,
    v14);
  if ( a2 )
    _qdf_nbuf_free(a2);
  return 0;
}

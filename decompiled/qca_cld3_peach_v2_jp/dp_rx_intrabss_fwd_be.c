__int64 __fastcall dp_rx_intrabss_fwd_be(__int64 a1, _BYTE *a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v5; // x29
  __int64 v6; // x30
  __int64 v13; // x25
  __int64 ref_by_id; // x0
  int *v15; // x9
  int v16; // w11
  int v17; // w9
  bool v18; // zf
  _BYTE *v19; // x8
  __int64 v20; // x27
  __int64 v21; // x28
  unsigned int v22; // w24
  __int64 v23; // x7
  __int64 v25; // [xsp+8h] [xbp-58h]

  if ( ((*(_QWORD *)(a4 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(a4 + 87) & 0xFu) >= 0xA )
  {
    __break(0x5512u);
    goto LABEL_31;
  }
  v25 = v6;
  v13 = *(_QWORD *)(*(_QWORD *)a2 + 24LL)
      + 5472 * ((*(_QWORD *)(a4 + 72) >> 18) & 0xFLL)
      + 608LL * (*(_BYTE *)(a4 + 87) & 0xF);
  if ( (*(_BYTE *)(a4 + 84) & 0x10) == 0 || (a2[88] & 2) != 0 )
  {
    if ( !_qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a4 + 224))
      || ((v15 = *(int **)(a4 + 224),
           v16 = *v15,
           v17 = *((unsigned __int16 *)v15 + 2),
           *(_DWORD *)(*(_QWORD *)a2 + 96LL) == v16)
        ? (v18 = *(unsigned __int16 *)(*(_QWORD *)a2 + 100LL) == v17)
        : (v18 = 0),
          v18) )
    {
      if ( (*(_BYTE *)(a4 + 84) & 0x30) == 0x20 )
      {
        ref_by_id = dp_peer_get_ref_by_id(a1, *(_WORD *)(a3 + 22) & 0x3FFF, 2);
        if ( !ref_by_id )
          return ref_by_id & 1;
        v19 = *(_BYTE **)ref_by_id;
        if ( *(_QWORD *)ref_by_id )
        {
          if ( (a2[88] & 4) != 0 || v19 == a2 || (v19[88] & 6) != 0 )
          {
            dp_txrx_peer_unref_delete(ref_by_id, 2);
          }
          else
          {
            v20 = *(_QWORD *)v19;
            v21 = *(_QWORD *)a2;
            v22 = *(unsigned __int8 *)(*(_QWORD *)v19 + 59LL);
            dp_txrx_peer_unref_delete(ref_by_id, 2);
            if ( v21 == v20 )
            {
              LOBYTE(ref_by_id) = dp_rx_intrabss_ucast_fwd(a1, a2, v22, a3, a4, v13 + 41856, a5, v23, v5, v25);
              return ref_by_id & 1;
            }
          }
        }
        else
        {
          dp_peer_unref_delete(ref_by_id, 2);
        }
      }
      LOBYTE(ref_by_id) = 0;
      return ref_by_id & 1;
    }
    if ( a4 )
      _qdf_nbuf_free(a4);
    if ( a1 )
    {
      LOBYTE(ref_by_id) = 1;
      ++*(_DWORD *)(a1 + 14128);
      return ref_by_id & 1;
    }
LABEL_31:
    LOBYTE(ref_by_id) = 1;
    return ref_by_id & 1;
  }
  LOBYTE(ref_by_id) = dp_rx_intrabss_mcbc_fwd(a1, a2, a3, a4, v13 + 41856, a5);
  return ref_by_id & 1;
}

__int64 __fastcall dp_rx_intrabss_fwd_be(__int64 a1, _BYTE *a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 v11; // x25
  __int64 ref_by_id; // x0
  int *v13; // x9
  int v14; // w11
  int v15; // w9
  int *v17; // x9
  int v18; // w11
  int v19; // w9
  _QWORD *v21; // x8
  _BYTE *v22; // x8
  __int64 v23; // x8
  __int64 v24; // x9
  unsigned int v25; // w24
  int v26; // w24
  int v27; // w27
  int v28; // w28
  int v30; // [xsp+8h] [xbp-68h]
  unsigned int v31; // [xsp+Ch] [xbp-64h]

  if ( ((*(_QWORD *)(a4 + 72) >> 18) & 0xFuLL) > 7 || (*(_BYTE *)(a4 + 87) & 0xFu) >= 0xA )
  {
    __break(0x5512u);
    goto LABEL_42;
  }
  v11 = *(_QWORD *)(*(_QWORD *)a2 + 24LL)
      + 5472 * ((*(_QWORD *)(a4 + 72) >> 18) & 0xFLL)
      + 608LL * (*(_BYTE *)(a4 + 87) & 0xF);
  if ( (*(_BYTE *)(a4 + 84) & 0x10) != 0 && (a2[88] & 2) == 0 )
  {
    LOBYTE(ref_by_id) = dp_rx_intrabss_mcbc_fwd(a1, a2, a3, a4, v11 + 42680, a5);
    return ref_by_id & 1;
  }
  if ( _qdf_nbuf_data_is_ipv4_eapol_pkt(*(_QWORD *)(a4 + 224)) )
  {
    v13 = *(int **)(a4 + 224);
    v14 = *v13;
    v15 = *((unsigned __int16 *)v13 + 2);
    if ( *(_DWORD *)(*(_QWORD *)a2 + 96LL) != v14 || *(unsigned __int16 *)(*(_QWORD *)a2 + 100LL) != v15 )
    {
      v17 = *(int **)(a4 + 224);
      v18 = *v17;
      v19 = *((unsigned __int16 *)v17 + 2);
      if ( *(_DWORD *)(*(_QWORD *)a2 + 104LL) != v18 || *(unsigned __int16 *)(*(_QWORD *)a2 + 108LL) != v19 )
      {
        if ( a4 )
          _qdf_nbuf_free(a4);
        if ( a1 )
        {
          LOBYTE(ref_by_id) = 1;
          ++*(_DWORD *)(a1 + 14184);
          return ref_by_id & 1;
        }
LABEL_42:
        LOBYTE(ref_by_id) = 1;
        return ref_by_id & 1;
      }
    }
  }
  if ( (*(_BYTE *)(a4 + 84) & 0x30) != 0x20 )
  {
    LOBYTE(ref_by_id) = 0;
    return ref_by_id & 1;
  }
  ref_by_id = dp_peer_get_ref_by_id(
                a1,
                ((unsigned __int8)((unsigned int)(*(_DWORD *)(a1 + 13356) & HIWORD(*(_DWORD *)(a3 + 20))) >> *(_BYTE *)(a1 + 13352)) << *(_DWORD *)(a1 + 13328))
              | ((unsigned int)(HIWORD(*(_DWORD *)(a3 + 20)) & *(_DWORD *)(a1 + 13340)) >> *(_BYTE *)(a1 + 13336)),
                2);
  if ( ref_by_id )
  {
    if ( *(_DWORD *)(ref_by_id + 408) != 1 || (v21 = *(_QWORD **)(ref_by_id + 416)) == nullptr )
      v21 = (_QWORD *)ref_by_id;
    v22 = (_BYTE *)*v21;
    if ( !v22 )
    {
      dp_peer_unref_delete(ref_by_id, 2);
      LOBYTE(ref_by_id) = 0;
      return ref_by_id & 1;
    }
    if ( (a2[88] & 4) != 0 || v22 == a2 || (v22[88] & 6) != 0 )
    {
      dp_txrx_peer_unref_delete(ref_by_id, 2);
      LOBYTE(ref_by_id) = 0;
      return ref_by_id & 1;
    }
    v23 = *(_QWORD *)v22;
    v24 = *(_QWORD *)a2;
    v25 = *(unsigned __int8 *)(v23 + 59);
    if ( *(_QWORD *)a2 == v23 )
    {
      dp_txrx_peer_unref_delete(ref_by_id, 2);
    }
    else
    {
      v31 = *(unsigned __int8 *)(v23 + 59);
      v26 = *(_DWORD *)(v24 + 104);
      v27 = *(_DWORD *)(v23 + 104);
      v28 = *(unsigned __int16 *)(v23 + 108);
      v30 = *(unsigned __int16 *)(v24 + 108);
      dp_txrx_peer_unref_delete(ref_by_id, 2);
      LOBYTE(ref_by_id) = 0;
      if ( v26 != v27 )
        return ref_by_id & 1;
      v25 = v31;
      if ( v30 != v28 )
        return ref_by_id & 1;
    }
    LOBYTE(ref_by_id) = dp_rx_intrabss_ucast_fwd(a1, a2, v25, a3, a4, v11 + 42680, a5);
  }
  return ref_by_id & 1;
}

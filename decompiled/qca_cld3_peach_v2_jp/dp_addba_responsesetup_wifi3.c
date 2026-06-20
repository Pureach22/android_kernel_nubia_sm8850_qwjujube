__int64 __fastcall dp_addba_responsesetup_wifi3(
        __int64 a1,
        unsigned __int16 *a2,
        unsigned __int8 a3,
        unsigned __int8 a4,
        _BYTE *a5,
        _WORD *a6,
        _WORD *a7,
        _WORD *a8)
{
  __int64 v14; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x24
  __int64 v24; // x19
  unsigned __int64 StatusReg; // x8
  char v26; // w9
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7

  v14 = dp_peer_find_hash_find(a1, a2, 0, a3, 7u);
  if ( v14 )
  {
    v23 = *(_QWORD *)(v14 + 88) + 144LL * a4;
    v24 = v14;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v23 + 88);
    }
    else
    {
      raw_spin_lock_bh(v23 + 88);
      *(_QWORD *)(v23 + 96) |= 1uLL;
    }
    v26 = *(_BYTE *)(v23 + 76);
    ++*(_DWORD *)(v23 + 8);
    *a5 = v26;
    *a6 = *(_WORD *)(v23 + 78);
    *a7 = *(_WORD *)(v23 + 72);
    *a8 = 0;
    v27 = *(_QWORD *)(v23 + 96);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(v23 + 96) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v23 + 88);
    }
    else
    {
      raw_spin_unlock(v23 + 88);
    }
    dp_peer_unref_delete(v24, 7u, v28, v29, v30, v31, v32, v33, v34, v35);
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x81u,
      8u,
      "%s: %pK: Peer is NULL!",
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      v21,
      v22,
      "dp_addba_responsesetup_wifi3",
      a1);
    return 16;
  }
}

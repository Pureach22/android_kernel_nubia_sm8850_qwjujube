__int64 __fastcall dp_get_peer_state(__int64 a1, unsigned int a2, unsigned __int16 *a3, char a4)
{
  __int64 v8; // x19
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  __int64 v17; // x5
  unsigned int v18; // w20
  __int64 v19; // x6
  __int64 v20; // x7
  int v21; // w8
  int v22; // w9
  int v23; // w10
  int v24; // w11
  int v25; // w12
  int v26; // w13
  _DWORD *v27; // x8

  v8 = dp_peer_find_hash_find(a1, a3, 0, a2, 7u);
  if ( v8 )
    goto LABEL_21;
  v27 = *(_DWORD **)(a1 + 1536);
  if ( v27 )
  {
    if ( *(v27 - 1) != 69695039 )
      __break(0x8228u);
    v8 = ((__int64 (__fastcall *)(__int64, unsigned __int16 *, _QWORD, __int64, _QWORD))v27)(a1, a3, 0, 7, a2);
    if ( v8 )
    {
LABEL_21:
      if ( *(_DWORD *)(v8 + 408) != 1 || (v17 = *(_QWORD *)(v8 + 416)) == 0 )
        v17 = v8;
      v18 = *(_DWORD *)(v17 + 124);
      if ( (a4 & 1) == 0 )
        goto LABEL_17;
      if ( v8 == -44 )
      {
        v21 = 0;
        v19 = 0;
        v20 = 0;
        v22 = 0;
        if ( v17 != -44 )
          goto LABEL_8;
      }
      else
      {
        v19 = *(unsigned __int8 *)(v8 + 44);
        v20 = *(unsigned __int8 *)(v8 + 45);
        v21 = *(unsigned __int8 *)(v8 + 46);
        v22 = *(unsigned __int8 *)(v8 + 49);
        if ( v17 != -44 )
        {
LABEL_8:
          v23 = *(unsigned __int8 *)(v17 + 44);
          v24 = *(unsigned __int8 *)(v17 + 45);
          v25 = *(unsigned __int8 *)(v17 + 46);
          v26 = *(unsigned __int8 *)(v17 + 49);
LABEL_16:
          qdf_trace_msg(
            0x81u,
            5u,
            "%s: peer %pK tgt_peer: %pK peer MAC %02x:%02x:%02x:**:**:%02x tgt peer MAC %02x:%02x:%02x:**:**:%02x tgt peer state %d",
            v9,
            v10,
            v11,
            v12,
            v13,
            v14,
            v15,
            v16,
            "dp_get_peer_state",
            v8,
            v17,
            v19,
            v20,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            *(_DWORD *)(v17 + 124));
LABEL_17:
          dp_peer_unref_delete(v8, 7u, v9, v10, v11, v12, v13, v14, v15, v16);
          return v18;
        }
      }
      v25 = 0;
      v23 = 0;
      v24 = 0;
      v26 = 0;
      goto LABEL_16;
    }
  }
  return 0;
}

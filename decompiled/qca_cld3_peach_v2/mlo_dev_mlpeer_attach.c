__int64 __fastcall mlo_dev_mlpeer_attach(__int64 a1, __int64 a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v13; // d0
  double v14; // d1
  double v15; // d2
  double v16; // d3
  double v17; // d4
  double v18; // d5
  double v19; // d6
  double v20; // d7
  int v21; // [xsp+0h] [xbp-10h]
  int v22; // [xsp+0h] [xbp-10h]

  qdf_mutex_acquire(a1 + 1584);
  if ( mlo_get_mlpeer(a1, a2 + 104) )
  {
    qdf_mutex_release(a1 + 1584);
    v21 = *(unsigned __int8 *)(a2 + 109);
    qdf_trace_msg(
      0x8Fu,
      2u,
      "%s: MLD ID %d ML Peer exists with mac %02x:%02x:%02x:**:**:%02x",
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      v11,
      "mlo_dev_mlpeer_attach",
      *(unsigned __int8 *)(a1 + 16),
      *(unsigned __int8 *)(a2 + 104),
      *(unsigned __int8 *)(a2 + 105),
      *(unsigned __int8 *)(a2 + 106),
      v21);
    return 14;
  }
  else
  {
    qdf_list_insert_back((_QWORD *)(a1 + 24LL * (*(_BYTE *)(a2 + 109) & 0x3F) + 48), (_QWORD *)a2);
    qdf_mutex_release(a1 + 1584);
    v22 = *(unsigned __int8 *)(a2 + 109);
    qdf_trace_msg(
      0x8Fu,
      8u,
      "%s: MLD ID %d ML Peer %02x:%02x:%02x:**:**:%02x is attached",
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      v20,
      "mlo_dev_mlpeer_attach",
      *(unsigned __int8 *)(a1 + 16),
      *(unsigned __int8 *)(a2 + 104),
      *(unsigned __int8 *)(a2 + 105),
      *(unsigned __int8 *)(a2 + 106),
      v22);
    return 0;
  }
}

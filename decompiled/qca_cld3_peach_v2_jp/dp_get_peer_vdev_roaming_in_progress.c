__int64 __fastcall dp_get_peer_vdev_roaming_in_progress(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x19
  __int64 v10; // x20
  __int64 (__fastcall *v11)(_QWORD); // x8
  __int64 v12; // x0
  char v13; // w0
  int v14; // w8
  unsigned __int8 v16[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16[0] = -1;
  if ( a1 )
  {
    v9 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL) + 8LL) + 8LL);
    if ( v9 )
    {
      if ( *(_QWORD *)(v9 + 192) )
      {
        v10 = a1;
        dp_get_vdevid(
          *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 24LL) + 8LL),
          (unsigned __int16 *)(a1 + 44),
          3,
          v16);
        v11 = *(__int64 (__fastcall **)(_QWORD))(v9 + 192);
        v12 = v16[0];
        if ( *((_DWORD *)v11 - 1) != -1896783675 )
          __break(0x8228u);
        v13 = v11(v12);
        v14 = v16[0];
        LOBYTE(v9) = v13;
        a1 = v10;
        goto LABEL_10;
      }
      LOBYTE(v9) = 0;
    }
    v14 = 255;
LABEL_10:
    qdf_trace_msg(
      0x81u,
      5u,
      "%s: peer: %02x:%02x:%02x:**:**:%02x, vdev_id: %d, is_roaming: %d",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "dp_get_peer_vdev_roaming_in_progress",
      *(unsigned __int8 *)(a1 + 44),
      *(unsigned __int8 *)(a1 + 45),
      *(unsigned __int8 *)(a1 + 46),
      *(unsigned __int8 *)(a1 + 49),
      v14,
      v9 & 1);
    goto LABEL_11;
  }
  qdf_trace_msg(
    0x81u,
    5u,
    "%s: Peer is NULL. No roaming possible",
    a2,
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    "dp_get_peer_vdev_roaming_in_progress");
  LOBYTE(v9) = 0;
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return v9 & 1;
}

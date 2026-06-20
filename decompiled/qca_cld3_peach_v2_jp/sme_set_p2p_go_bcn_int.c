__int64 __fastcall sme_set_p2p_go_bcn_int(__int64 a1, unsigned __int8 a2, __int16 a3)
{
  unsigned int opmode_from_vdev_id; // w0
  double v7; // d0
  double v8; // d1
  double v9; // d2
  double v10; // d3
  double v11; // d4
  double v12; // d5
  double v13; // d6
  double v14; // d7
  __int64 result; // x0
  __int64 v16; // x8
  unsigned int v17; // w20

  opmode_from_vdev_id = wlan_get_opmode_from_vdev_id(*(_QWORD *)(a1 + 21560), a2);
  if ( opmode_from_vdev_id == 3 )
  {
    result = qdf_mutex_acquire(a1 + 12776);
    if ( !(_DWORD)result )
    {
      v16 = 96LL * a2;
      *(_BYTE *)(*(_QWORD *)(a1 + 17224) + v16 + 50) = 1;
      *(_WORD *)(*(_QWORD *)(a1 + 17224) + v16 + 48) = a3;
      v17 = csr_send_chng_mcc_beacon_interval(a1, a2);
      qdf_mutex_release(a1 + 12776);
      return v17;
    }
  }
  else
  {
    qdf_trace_msg(
      0x34u,
      2u,
      "%s: Invalid opmode %d for GO bcn int update",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      "sme_set_p2p_go_bcn_int",
      opmode_from_vdev_id);
    return 4;
  }
  return result;
}

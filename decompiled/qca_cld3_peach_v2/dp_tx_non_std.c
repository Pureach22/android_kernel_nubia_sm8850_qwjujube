__int64 *__fastcall dp_tx_non_std(__int64 a1, unsigned __int8 a2, char a3, __int64 *a4)
{
  __int64 ref_by_id_1; // x0
  unsigned int *v9; // x8
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7

  ref_by_id_1 = dp_vdev_get_ref_by_id_1(a1, a2, 0x14u);
  if ( ref_by_id_1 )
  {
    if ( (a3 & 0x20) != 0 )
    {
      v9 = (_DWORD *)(&off_0 + 1);
      *(_BYTE *)(ref_by_id_1 + 329) = 1;
    }
    dp_vdev_unref_delete(a1, ref_by_id_1, 0x14u, v9, v10, v11, v12, v13, v14, v15, v16, v17);
    return dp_tx_send(a1, a2, a4);
  }
  else
  {
    qdf_trace_msg(
      0x45u,
      2u,
      "%s: vdev handle for id %d is NULL",
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      "dp_tx_non_std",
      a2);
    return nullptr;
  }
}

__int64 __fastcall hdd_set_tdls_offchannel(__int64 a1, __int64 a2, __int16 a3)
{
  __int64 vdev_by_user; // x0
  __int64 v5; // x20
  unsigned int v6; // w19
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  unsigned int v16; // w0

  if ( *(_BYTE *)(a1 + 1800) == 1
    && (vdev_by_user = _hdd_objmgr_get_vdev_by_user(*(_QWORD *)(a2 + 52824), 0x57u, (__int64)"hdd_set_tdls_offchannel")) != 0 )
  {
    v5 = vdev_by_user;
    v6 = ucfg_set_tdls_offchannel(vdev_by_user, a3);
    _hdd_objmgr_put_vdev_by_user(
      v5,
      0x57u,
      (__int64)"hdd_set_tdls_offchannel",
      v7,
      v8,
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15);
    v16 = v6;
  }
  else
  {
    v16 = 16;
  }
  return qdf_status_to_os_return(v16);
}

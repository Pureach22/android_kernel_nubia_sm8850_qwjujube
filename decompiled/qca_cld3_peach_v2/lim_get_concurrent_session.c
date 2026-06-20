__int64 __fastcall lim_get_concurrent_session(__int64 a1, unsigned __int8 a2, int a3)
{
  __int64 v6; // x0
  unsigned __int8 conc_vdev_on_same_mac; // w0
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 session_by_vdev_id; // x0
  __int64 v17; // x1
  unsigned __int8 v19[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(_QWORD *)(a1 + 21624);
  v19[0] = 0;
  policy_mgr_get_mac_id_by_session_id(v6, a2, v19);
  conc_vdev_on_same_mac = policy_mgr_get_conc_vdev_on_same_mac(*(_QWORD *)(a1 + 21624), a2, v19[0]);
  session_by_vdev_id = pe_find_session_by_vdev_id(a1, conc_vdev_on_same_mac, v8, v9, v10, v11, v12, v13, v14, v15);
  if ( !session_by_vdev_id )
  {
LABEL_9:
    v17 = 0;
    goto LABEL_12;
  }
  v17 = 0;
  if ( a3 <= 1 )
  {
    if ( a3 )
    {
      if ( a3 != 1 )
        goto LABEL_12;
LABEL_10:
      if ( (*(_DWORD *)(session_by_vdev_id + 7036) | 2) == 2 )
        goto LABEL_11;
      goto LABEL_9;
    }
    goto LABEL_8;
  }
  if ( a3 == 3 )
    goto LABEL_10;
  if ( a3 == 2 )
  {
LABEL_8:
    if ( (*(_DWORD *)(session_by_vdev_id + 7036) | 2) == 3 )
    {
LABEL_11:
      v17 = session_by_vdev_id;
      goto LABEL_12;
    }
    goto LABEL_9;
  }
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return v17;
}

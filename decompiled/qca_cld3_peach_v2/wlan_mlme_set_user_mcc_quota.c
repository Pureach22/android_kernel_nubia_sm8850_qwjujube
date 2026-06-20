__int64 __fastcall wlan_mlme_set_user_mcc_quota(__int64 a1, unsigned int *a2)
{
  __int64 psoc_ext_obj_fl; // x0
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  unsigned int v12; // w8

  if ( !a2 )
    return 29;
  psoc_ext_obj_fl = mlme_get_psoc_ext_obj_fl(a1);
  if ( !psoc_ext_obj_fl )
    return 16;
  v12 = *((unsigned __int8 *)a2 + 4);
  if ( v12 < 0xA )
  {
    LOBYTE(v12) = 10;
LABEL_9:
    *((_BYTE *)a2 + 4) = v12;
    goto LABEL_10;
  }
  if ( v12 >= 0x5B )
  {
    LOBYTE(v12) = 90;
    goto LABEL_9;
  }
LABEL_10:
  *(_BYTE *)(psoc_ext_obj_fl + 1140) = v12;
  *(_DWORD *)(psoc_ext_obj_fl + 1136) = *a2;
  *(_BYTE *)(psoc_ext_obj_fl + 1141) = *((_BYTE *)a2 + 5);
  qdf_trace_msg(
    0x68u,
    8u,
    "%s: quota : %u, op_mode : %d, vdev_id : %u",
    v4,
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    "wlan_mlme_set_user_mcc_quota",
    *((unsigned __int8 *)a2 + 4),
    *a2);
  return 0;
}

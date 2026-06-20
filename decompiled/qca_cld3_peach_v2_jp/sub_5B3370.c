__int64 __fastcall sub_5B3370(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // x11
  __int64 v4; // d20
  __int64 v5; // d31

  *(_QWORD *)(v3 + 176) = v5;
  *(_QWORD *)(v3 + 184) = v4;
  return cm_fw_send_vdev_roam_event(a1, a2, a3);
}

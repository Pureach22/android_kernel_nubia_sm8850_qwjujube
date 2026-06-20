__int64 __fastcall sub_2B32EC(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v8; // x3

  __asm { LDLAR           W3, [X28] }
  v8 = _OFF;
  __asm { LDLAR           W3, [X28] }
  return target_if_cm_roam_send_vdev_set_pcl_cmd(a1, a2, a3, v8);
}

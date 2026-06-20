__int64 __fastcall cam_isp_subdev_close_internal(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  unsigned int v3; // w19

  v1 = *(_QWORD *)(a1 + 240);
  mutex_lock(&unk_3A8B38);
  if ( dword_3A8B68 <= 0 )
  {
    v3 = -22;
    if ( (debug_mdl & 8) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 8,
        4,
        "cam_isp_subdev_close_internal",
        141,
        "ISP subdev is already closed");
  }
  else
  {
    v2 = --dword_3A8B68;
    if ( v1 )
    {
      if ( !v2 )
        cam_node_shutdown(v1);
      v3 = 0;
    }
    else
    {
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        8,
        1,
        "cam_isp_subdev_close_internal",
        148,
        "Node ptr is NULL");
      v3 = -22;
    }
  }
  mutex_unlock(&unk_3A8B38);
  return v3;
}

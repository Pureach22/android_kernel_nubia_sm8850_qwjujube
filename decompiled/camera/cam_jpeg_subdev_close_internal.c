__int64 __fastcall cam_jpeg_subdev_close_internal(__int64 a1)
{
  __int64 v1; // x19
  int v2; // w8
  unsigned int v3; // w19

  v1 = *(_QWORD *)(a1 + 240);
  mutex_lock(&unk_3C37B0);
  if ( dword_3C37E0 <= 0 )
  {
    v3 = -22;
    if ( (debug_mdl & 0x200) != 0 && !debug_priority )
      ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
        3,
        debug_mdl & 0x200,
        4,
        "cam_jpeg_subdev_close_internal",
        121,
        "JPEG subdev is already closed");
  }
  else
  {
    v2 = --dword_3C37E0;
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
        512,
        1,
        "cam_jpeg_subdev_close_internal",
        129,
        "Node ptr is NULL");
      v3 = -22;
    }
  }
  mutex_unlock(&unk_3C37B0);
  return v3;
}

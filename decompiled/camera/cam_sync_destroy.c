__int64 __fastcall cam_sync_destroy(unsigned int a1)
{
  return cam_sync_deinit_object(*(_QWORD *)(sync_dev + 128), a1, 0, 0);
}

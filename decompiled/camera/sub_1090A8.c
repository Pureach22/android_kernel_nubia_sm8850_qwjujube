__int64 sub_1090A8()
{
  __asm { STLLRB          W30, [X30] }
  return cam_mem_mgr_release_mem();
}

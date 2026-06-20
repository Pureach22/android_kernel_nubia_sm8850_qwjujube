__int64 __fastcall sub_6871A8(__int64 a1)
{
  __asm { FMLAL2          V22.2S, V20.2H, V13.H[6] }
  return hdd_wait_for_debugfs_threads_completion(a1);
}

__int64 __fastcall debugfs_panic_state_read(__int64 a1, __int64 *a2)
{
  *a2 = (unsigned __int8)word_A62E | (2LL * HIBYTE(word_A62E));
  return 0;
}

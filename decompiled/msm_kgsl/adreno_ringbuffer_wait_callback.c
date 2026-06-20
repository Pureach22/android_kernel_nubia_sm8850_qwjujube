__int64 __fastcall adreno_ringbuffer_wait_callback(__int64 a1, __int64 a2)
{
  return _wake_up(*(_QWORD *)(a2 + 128) + 1256LL, 3, 0, 0);
}

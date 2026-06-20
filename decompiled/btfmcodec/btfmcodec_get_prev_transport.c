__int64 __fastcall btfmcodec_get_prev_transport(__int64 a1)
{
  unsigned int v2; // w20

  mutex_lock(a1);
  v2 = *(_DWORD *)(a1 + 48);
  mutex_unlock(a1);
  return v2;
}

__int64 __fastcall hif_exec_napi_schedule(__int64 a1)
{
  unsigned int v1; // w8
  __int64 result; // x0

  v1 = *(_DWORD *)(_ReadStatusReg(SP_EL0) + 40);
  if ( v1 >= 0x20 )
  {
    __break(0x5512u);
    return hif_exec_napi_kill();
  }
  else
  {
    ++*(_DWORD *)(a1 + 72LL * v1 + 376);
    result = napi_schedule_prep(a1 + 6208);
    if ( (result & 1) != 0 )
      return _napi_schedule(a1 + 6208);
  }
  return result;
}

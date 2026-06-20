__int64 __fastcall stm_probe(__int64 a1)
{
  __int64 result; // x0

  result = _stm_probe();
  if ( !(_DWORD)result )
  {
    _pm_runtime_idle(a1, 5);
    return 0;
  }
  return result;
}

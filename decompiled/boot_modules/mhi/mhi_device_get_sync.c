__int64 __fastcall mhi_device_get_sync(__int64 a1)
{
  __int64 result; // x0

  result = _mhi_device_get_sync(*(_QWORD *)(a1 + 16));
  if ( !(_DWORD)result )
    ++*(_DWORD *)(a1 + 972);
  return result;
}

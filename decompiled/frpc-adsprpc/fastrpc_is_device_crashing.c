__int64 __fastcall fastrpc_is_device_crashing(__int64 a1)
{
  __int64 result; // x0

  result = *(_QWORD *)(a1 + 160);
  if ( result )
  {
    result = rproc_get_by_child();
    if ( result )
      return *(_BYTE *)(result + 1204) == 1 && *(_DWORD *)(result + 972) == 3;
  }
  return result;
}

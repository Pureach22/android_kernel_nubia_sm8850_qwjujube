bool __fastcall hdd_is_2g_supported(_BOOL8 result)
{
  if ( result )
    return *(_DWORD *)(result + 3252) != 2;
  return result;
}

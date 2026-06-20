bool __fastcall qdf_is_macaddr_broadcast(__int64 a1)
{
  return *(_DWORD *)a1 == -1 && *(__int16 *)(a1 + 4) == -1;
}

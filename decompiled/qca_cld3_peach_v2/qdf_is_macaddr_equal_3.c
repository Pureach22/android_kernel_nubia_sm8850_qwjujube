bool __fastcall qdf_is_macaddr_equal_3(__int64 a1, __int64 a2)
{
  return *(_DWORD *)a1 == *(_DWORD *)a2 && *(unsigned __int16 *)(a1 + 4) == *(unsigned __int16 *)(a2 + 4);
}

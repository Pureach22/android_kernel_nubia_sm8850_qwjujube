__int64 __fastcall wma_get_hemu_mode(int *a1, __int64 a2)
{
  __int64 result; // x0

  result = 16;
  if ( a1 )
  {
    if ( a2 )
    {
      *a1 = 48;
      *a1 = (*(_DWORD *)(*(_QWORD *)(a2 + 8) + 1317LL) >> 15) & 0xA
          | (4 * ((*(_DWORD *)(*(_QWORD *)(a2 + 8) + 1317LL) >> 17) & 1))
          | (*(_DWORD *)(*(_QWORD *)(a2 + 8) + 1317LL) >> 17) & 1
          | 0x30;
      return 0;
    }
  }
  return result;
}

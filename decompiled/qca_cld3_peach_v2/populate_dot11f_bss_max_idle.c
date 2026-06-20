__int64 __fastcall populate_dot11f_bss_max_idle(__int64 result, __int64 a2, __int64 a3)
{
  *(_BYTE *)a3 = 0;
  if ( *(_BYTE *)(a2 + 8676) == 1 )
  {
    if ( *(_DWORD *)(*(_QWORD *)(result + 8) + 3504LL) )
    {
      *(_BYTE *)a3 = 1;
      *(_WORD *)(a3 + 2) = *(_DWORD *)(*(_QWORD *)(result + 8) + 3504LL);
      *(_BYTE *)(a3 + 4) = *(_BYTE *)(a3 + 4) & 0xFE | ((*(_BYTE *)(a2 + 7024) & 0x10) != 0);
    }
  }
  return result;
}

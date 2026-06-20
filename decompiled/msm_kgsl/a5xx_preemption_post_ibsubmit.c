__int64 __fastcall a5xx_preemption_post_ibsubmit(__int64 a1, __int64 a2)
{
  if ( (*(_QWORD *)(a1 + 14240) & 0x200) == 0 )
    return 0;
  *(_QWORD *)a2 = 1886060548;
  *(_QWORD *)(a2 + 8) = 0x100000000LL;
  *(_DWORD *)(a2 + 16) = 1;
  return 5;
}

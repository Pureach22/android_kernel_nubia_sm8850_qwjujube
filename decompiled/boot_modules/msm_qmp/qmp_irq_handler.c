__int64 __fastcall qmp_irq_handler(__int64 a1, __int64 a2)
{
  if ( *(_BYTE *)(a2 + 153) == 1 && (*(_BYTE *)(a2 + 152) & 1) != 0 )
    return 0;
  if ( *(_QWORD *)(a2 + 48) )
    writel_relaxed(*(unsigned int *)(a2 + 56));
  ++*(_DWORD *)(a2 + 68);
  return 2;
}

__int64 __fastcall stm_mmio_addr(__int64 a1, __int64 a2, int a3, char a4)
{
  if ( ((*(_QWORD *)(a1 - 16) + (unsigned int)(a3 << 8)) & 0xFFFLL) == 0 && (a4 & 0xF) == 0 )
    return *(_QWORD *)(a1 - 16) + (unsigned int)(a3 << 8);
  else
    return 0;
}

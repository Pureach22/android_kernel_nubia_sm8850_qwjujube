__int64 __fastcall av8l_fast_iova_to_phys_public(__int64 a1, unsigned __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9

  v2 = *(_QWORD *)((a2 >> 27) & 0xFF8 | *(_QWORD *)(a1 + 72));
  if ( (~*(_DWORD *)((a2 >> 27) & 0xFF8 | *(_QWORD *)(a1 + 72)) & 3LL) != 0 )
    return 0;
  v3 = *(_QWORD *)(((v2 & 0x7FFFFFF000LL | (a2 >> 18) & 0xFF8) - memstart_addr) | 0xFFFFFF8000000000LL);
  if ( (~*(_BYTE *)(((v2 & 0x7FFFFFF000LL | (a2 >> 18) & 0xFF8) - memstart_addr) | 0xFFFFFF8000000000LL) & 3) != 0
    || (~*(_DWORD *)((((a2 >> 9) & 0xFF8) - memstart_addr + (v3 & 0x7FFFFFF000LL)) | 0xFFFFFF8000000000LL) & 3LL) != 0 )
  {
    return 0;
  }
  else
  {
    return *(_QWORD *)((((a2 >> 9) & 0xFF8) - memstart_addr + (v3 & 0x7FFFFFF000LL)) | 0xFFFFFF8000000000LL)
         & 0xFFFFFFFFF000LL
         | a2 & 0xFFF;
  }
}

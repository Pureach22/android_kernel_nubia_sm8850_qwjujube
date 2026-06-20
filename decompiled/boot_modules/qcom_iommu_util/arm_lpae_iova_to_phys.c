__int64 __fastcall arm_lpae_iova_to_phys(__int64 a1, unsigned __int64 a2)
{
  unsigned __int64 v3; // x24
  int v4; // w21
  __int64 v6; // x1
  int v7; // w8
  char v8; // w10
  int v9; // w15
  __int64 v10; // x24
  __int64 v12; // x16
  __int64 v13; // x15
  __int64 v15; // x8
  char v16; // w9

  v3 = *(_QWORD *)(a1 + 88);
  v4 = *(_DWORD *)(a1 + 76);
  v6 = raw_spin_lock_irqsave(a1 + 120);
  if ( v3 )
  {
    v7 = *(_DWORD *)(a1 + 80);
    v8 = v7 * (4 - v4) + 3;
    do
    {
      if ( *(_DWORD *)(a1 + 76) == v4 )
        v9 = *(_DWORD *)(a1 + 72) - v7;
      else
        LOBYTE(v9) = 0;
      v10 = *(_QWORD *)(v3 + 8 * ((a2 >> v8) & (unsigned int)~(-1 << (v9 + v7))));
      if ( !v10 )
        break;
      if ( *(_DWORD *)(a1 - 128) != 5 && v4 == 3 )
        v12 = 3;
      else
        v12 = 1;
      if ( (v10 & 3) == v12 )
      {
        raw_spin_unlock_irqrestore(a1 + 120, v6);
        v15 = v10 & 0xFFFFFFFFF000LL;
        v16 = *(_DWORD *)(a1 + 80);
        if ( (unsigned __int64)(8LL << v16) >= 0x10000 )
          v15 = (0x1000000001LL * (v10 & 0xFFFFFFFFF000LL)) & 0xFFFFFFFFF0000LL;
        return v15 | a2 & ~(-1LL << (v16 * (4 - (unsigned __int8)v4) + 3));
      }
      v13 = v10 & 0xFFFFFFFFF000LL;
      ++v4;
      v8 -= v7;
      if ( (unsigned __int64)(8LL << v7) >= 0x10000 )
        v13 = (0x1000000001LL * (v10 & 0xFFFFFFFFF000LL)) & 0x7FFFFF0000LL;
      v3 = (v13 - memstart_addr) | 0xFFFFFF8000000000LL;
    }
    while ( v4 < 4 );
  }
  raw_spin_unlock_irqrestore(a1 + 120, v6);
  return 0;
}

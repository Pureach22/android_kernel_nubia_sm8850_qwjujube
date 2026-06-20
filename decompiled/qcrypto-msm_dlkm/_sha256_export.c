__int64 __fastcall sha256_export(__int64 a1, __int64 a2)
{
  __int64 v4; // t1
  __int64 v5; // x12
  __int64 v6; // x10
  __int64 v7; // x11
  __int64 v8; // x9
  __int64 v9; // x10
  __int64 v10; // x8
  __int64 v11; // x11

  *(_QWORD *)(a2 + 32) = *(_QWORD *)(a1 + 216);
  *(_DWORD *)a2 = bswap32(*(_DWORD *)(a1 + 456));
  *(_DWORD *)(a2 + 4) = bswap32(*(_DWORD *)(a1 + 460));
  *(_DWORD *)(a2 + 8) = bswap32(*(_DWORD *)(a1 + 464));
  *(_DWORD *)(a2 + 12) = bswap32(*(_DWORD *)(a1 + 468));
  *(_DWORD *)(a2 + 16) = bswap32(*(_DWORD *)(a1 + 472));
  *(_DWORD *)(a2 + 20) = bswap32(*(_DWORD *)(a1 + 476));
  *(_DWORD *)(a2 + 24) = bswap32(*(_DWORD *)(a1 + 480));
  *(_DWORD *)(a2 + 28) = bswap32(*(_DWORD *)(a1 + 484));
  v4 = *(_QWORD *)(a1 + 226);
  a1 += 226;
  v5 = *(_QWORD *)(a1 + 8);
  v7 = *(_QWORD *)(a1 + 16);
  v6 = *(_QWORD *)(a1 + 24);
  *(_QWORD *)(a2 + 40) = v4;
  *(_QWORD *)(a2 + 48) = v5;
  *(_QWORD *)(a2 + 56) = v7;
  *(_QWORD *)(a2 + 64) = v6;
  v9 = *(_QWORD *)(a1 + 48);
  v8 = *(_QWORD *)(a1 + 56);
  v11 = *(_QWORD *)(a1 + 32);
  v10 = *(_QWORD *)(a1 + 40);
  *(_QWORD *)(a2 + 88) = v9;
  *(_QWORD *)(a2 + 96) = v8;
  *(_QWORD *)(a2 + 72) = v11;
  *(_QWORD *)(a2 + 80) = v10;
  return 0;
}

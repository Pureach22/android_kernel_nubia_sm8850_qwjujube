__int64 __fastcall gen8_preemption_prepare_postamble(__int64 result)
{
  __int64 v1; // x10
  unsigned int v2; // w9
  char v3; // w11
  __int64 v4; // x10
  __int64 v5; // x14
  unsigned int v6; // w11

  v1 = *(_QWORD *)(*(_QWORD *)(result + 48) + 8LL);
  if ( *(_QWORD *)(*(_QWORD *)(result + 14264) + 216LL) )
  {
    *(_QWORD *)(v1 + 800) = 0x870C28003LL;
    *(_QWORD *)(v1 + 808) = *(_QWORD *)(*(_QWORD *)(result + 20496) + 24LL) + 32LL;
    v2 = 4;
  }
  else
  {
    v2 = 0;
  }
  v3 = *(_BYTE *)(result + 23968);
  *(_DWORD *)(result + 20592) = v2;
  if ( (v3 & 1) == 0 )
  {
    v4 = v1 + 800;
    *(_DWORD *)(v4 + 4LL * (v2 | 1)) = 1;
    v5 = v4 + 4LL * v2;
    *(_DWORD *)(v4 + 4LL * (v2 | 3)) = 1;
    *(_DWORD *)(v4 + 4LL * (v2 | 2)) = 1208346625;
    *(_DWORD *)v5 = 1208240385;
    *(_QWORD *)(v5 + 16) = 0x370BC8006LL;
    *(_QWORD *)(v5 + 24) = 415;
    *(_DWORD *)(v4 + 4LL * (v2 | 8)) = 1;
    *(_DWORD *)(v4 + 4LL * (v2 | 9)) = 1;
    v6 = v2 | 0xA;
    v2 |= 0xBu;
    *(_DWORD *)(v4 + 4LL * v6) = 0;
  }
  *(_DWORD *)(result + 20588) = v2;
  return result;
}

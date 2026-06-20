__int64 __fastcall mhi_ring_chan_db(__int64 a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 v3; // x9
  __int64 v4; // x10
  __int64 (__fastcall *v5)(__int64, __int64, __int64); // x8
  __int64 v6; // x2
  __int64 v7; // x1

  v2 = *(_QWORD *)(a2 + 152);
  v3 = *(_QWORD *)(a2 + 136);
  v4 = *(_QWORD *)(a2 + 112);
  __dmb(2u);
  **(_QWORD **)(a2 + 120) = v2 - v3 + v4;
  v5 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a2 + 248);
  v6 = *(_QWORD *)(a2 + 192);
  v7 = a2 + 224;
  if ( *((_DWORD *)v5 - 1) != -396405511 )
    __break(0x8228u);
  return v5(a1, v7, v6);
}

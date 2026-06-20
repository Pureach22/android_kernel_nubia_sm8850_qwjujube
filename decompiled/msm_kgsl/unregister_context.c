__int64 __fastcall unregister_context(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 1824) )
  {
    *(_DWORD *)(*(_QWORD *)(a2 + 1648) + 20LL) = *(_DWORD *)(*(_QWORD *)(a2 + 1648) + 24LL);
    __dsb(0xFu);
  }
  *(_BYTE *)(a2 + 288) = 0;
  *(_DWORD *)(a2 + 396) = 0;
  return 0;
}

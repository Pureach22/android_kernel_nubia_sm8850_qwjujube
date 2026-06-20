__int64 __fastcall wcd9378_set_compander(__int64 a1, __int64 a2)
{
  bool v2; // w9
  __int64 v3; // x8

  v2 = *(_DWORD *)(a2 + 72) != 0;
  v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 152LL);
  if ( *(_DWORD *)(*(_QWORD *)(a1 + 120) + 20LL) )
  {
    *(_BYTE *)(v3 + 393) = v2;
    return 0;
  }
  else
  {
    *(_BYTE *)(v3 + 392) = v2;
    return 0;
  }
}

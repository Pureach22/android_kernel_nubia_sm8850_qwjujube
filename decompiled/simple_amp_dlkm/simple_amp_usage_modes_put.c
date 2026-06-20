__int64 __fastcall simple_amp_usage_modes_put(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 128) + 24LL) + 152LL);
  if ( !v2 )
    return 4294967274LL;
  *(_DWORD *)(v2 + 156) = *(_QWORD *)(a2 + 72);
  return 0;
}

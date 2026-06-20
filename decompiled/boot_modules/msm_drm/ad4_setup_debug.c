__int64 __fastcall ad4_setup_debug(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(a2 + 8);
  if ( *(_DWORD *)(v2 + 28) != 2 || (*(_BYTE *)(*(_QWORD *)(v2 + 32) + 384LL) & 1) == 0 )
  {
    sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 76));
    sde_reg_read(a1, (unsigned int)(*(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 72) + 48LL) + 344LL) + 80));
  }
  return 0;
}

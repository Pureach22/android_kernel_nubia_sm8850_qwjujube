__int64 __fastcall tpdm_dsb_msr_is_visible(__int64 a1, __int64 a2)
{
  if ( *(_DWORD *)(a2 + 36) >= *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL) + 56LL) )
    return 0;
  else
    return *(unsigned __int16 *)(a2 + 8);
}

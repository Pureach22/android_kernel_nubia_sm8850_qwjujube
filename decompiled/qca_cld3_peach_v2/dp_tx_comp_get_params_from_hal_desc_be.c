__int64 __fastcall dp_tx_comp_get_params_from_hal_desc_be(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 *v3; // x8
  __int64 v4; // x8

  v3 = (__int64 *)a2;
  if ( (*(_BYTE *)(a2 + 11) & 0x40) == 0 )
    v3 = (__int64 *)(*(_QWORD *)(*(_QWORD *)(a1 + 22608) + 24LL * (*(_DWORD *)(a2 + 4) >> 21))
                   + (((unsigned __int64)*(unsigned int *)(a2 + 4) >> 9) & 0xFF8));
  v4 = *v3;
  *a3 = v4;
  if ( v4 )
    *(_WORD *)(v4 + 50) = *(_WORD *)(a2 + 28) & 0x1FFF | (((*(_DWORD *)(a2 + 28) >> 13) & 1) << *(_DWORD *)(a1 + 13328));
  return 0;
}

__int64 __fastcall tpdm_cmb_is_visible(__int64 a1, __int64 a2)
{
  __int64 v2; // x8

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 96) + 152LL);
  if ( v2 && (*(_BYTE *)(v2 + 32) & 0x44) != 0 )
    return *(unsigned __int16 *)(a2 + 8);
  else
    return 0;
}

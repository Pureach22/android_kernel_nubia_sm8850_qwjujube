__int64 __fastcall sde_hw_intf_is_te_32bit_supported(__int64 a1)
{
  return (*(unsigned __int8 *)(*(_QWORD *)(a1 + 40) + 32LL) >> 4) & 1;
}

__int64 __fastcall scmi_clk_atomic_is_enabled(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x1
  _DWORD *v4; // x8
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a1 + 32);
  v3 = *(unsigned int *)(a1 - 16);
  v6[0] = 0;
  v4 = *(_DWORD **)(scmi_proto_clk_ops + 48);
  if ( *(v4 - 1) != -397315789 )
    __break(0x8228u);
  if ( ((unsigned int (__fastcall *)(__int64, __int64, _BYTE *, __int64))v4)(v2, v3, v6, 1) )
    dev_warn(*(_QWORD *)(a1 - 8), "Failed to get state for clock ID %d\n", *(_DWORD *)(a1 - 16));
  _ReadStatusReg(SP_EL0);
  return v6[0];
}

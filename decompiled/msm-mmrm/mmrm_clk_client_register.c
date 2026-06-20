__int64 __fastcall mmrm_clk_client_register(__int64 a1, __int64 a2)
{
  _DWORD **v2; // x8
  _DWORD *v3; // x23
  __int64 v4; // x20
  __int64 v5; // x21
  unsigned int v7; // w19
  __int64 result; // x0
  _BYTE v9[152]; // [xsp+0h] [xbp-A0h] BYREF
  __int64 v10; // [xsp+98h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && (v2 = *(_DWORD ***)(a1 + 152)) != nullptr && (v3 = *v2) != nullptr )
  {
    v4 = *(_QWORD *)(a2 + 168);
    v5 = *(_QWORD *)(a2 + 176);
    v7 = *(_DWORD *)(a2 + 160);
    memcpy(v9, (const void *)(a2 + 8), sizeof(v9));
    if ( *(v3 - 1) != 291947711 )
      __break(0x8237u);
    result = ((__int64 (__fastcall *)(__int64, _BYTE *, _QWORD, __int64, __int64))v3)(a1, v9, v7, v4, v5);
  }
  else
  {
    if ( (~msm_mmrm_debug & 0x10001) == 0 )
      printk(&unk_DCD6, "err ", "mmrm_clk_client_register");
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

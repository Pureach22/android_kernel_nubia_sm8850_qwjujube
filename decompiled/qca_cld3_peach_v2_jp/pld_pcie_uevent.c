__int64 __fastcall pld_pcie_uevent(__int64 a1, int a2)
{
  __int64 result; // x0
  int v5; // w8
  _DWORD *v6; // x8
  _QWORD v7[4]; // [xsp+0h] [xbp-20h] BYREF

  v7[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v7, 0, 24);
  result = pld_get_global_context();
  if ( result )
  {
    if ( a2 == 3 )
    {
      v5 = 2;
    }
    else
    {
      if ( a2 != 4 )
        goto LABEL_10;
      v5 = 0;
    }
    LODWORD(v7[0]) = v5;
    v6 = *(_DWORD **)(*(_QWORD *)result + 88LL);
    if ( v6 )
    {
      if ( *(v6 - 1) != -2054464844 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *))v6)(a1 + 200, v7);
    }
  }
LABEL_10:
  _ReadStatusReg(SP_EL0);
  return result;
}

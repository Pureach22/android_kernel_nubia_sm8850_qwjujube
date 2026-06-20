__int64 __fastcall reg_get_pdev_from_phy_id(__int64 a1, __int64 a2, __int64 a3, char a4, unsigned int *a5)
{
  _DWORD *v7; // x8
  __int64 v8; // x21
  unsigned int v9; // w2
  __int64 result; // x0
  _BYTE v11[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_DWORD **)(a3 + 136);
  v11[0] = 0;
  if ( v7 )
  {
    v8 = a1;
    if ( *(v7 - 1) != 13449260 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _BYTE *))v7)(a1, a2, v11);
    LOBYTE(a2) = v11[0];
    a1 = v8;
  }
  else
  {
    v11[0] = a2;
  }
  if ( (a4 & 1) != 0 )
    v9 = 22;
  else
    v9 = 21;
  *a5 = v9;
  result = wlan_objmgr_get_pdev_by_id(a1, a2, v9);
  _ReadStatusReg(SP_EL0);
  return result;
}

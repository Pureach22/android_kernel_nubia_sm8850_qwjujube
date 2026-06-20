__int64 __fastcall fake_soc_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v6; // w8
  __int64 v7; // x0
  int v9; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = 0;
  if ( (unsigned int)kstrtoint(a3, 0, &v9) )
  {
    a4 = -22;
  }
  else
  {
    v6 = *(unsigned __int8 *)(a1 + 616);
    *(_DWORD *)(a1 + 1032) = v9;
    if ( v6 == 1 )
    {
      v7 = *(_QWORD *)(a1 + 344);
      if ( v7 )
        power_supply_changed(v7);
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4;
}

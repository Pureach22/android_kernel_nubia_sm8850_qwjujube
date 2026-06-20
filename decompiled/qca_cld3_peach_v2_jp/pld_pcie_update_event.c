__int64 __fastcall pld_pcie_update_event(__int64 a1, __int64 a2)
{
  __int64 global_context; // x0
  void (__fastcall *v5)(__int64, __int64 *); // x8
  __int64 *v6; // x8
  __int64 v7; // x8
  int v8; // w10
  int v9; // w9
  __int64 v11; // [xsp+0h] [xbp-20h] BYREF
  __int64 v12; // [xsp+8h] [xbp-18h]
  __int64 v13; // [xsp+10h] [xbp-10h]
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  v13 = 0;
  v11 = 0;
  global_context = pld_get_global_context();
  LODWORD(v5) = -22;
  if ( !a2 || !global_context )
    goto LABEL_21;
  if ( *(_DWORD *)a2 != 6 )
  {
    if ( *(_DWORD *)a2 != 5 )
    {
LABEL_19:
      LODWORD(v5) = 0;
      goto LABEL_21;
    }
    v6 = *(__int64 **)(a2 + 8);
    if ( v6 )
    {
      LODWORD(v11) = 3;
      v12 = *v6;
      LOWORD(v13) = *((_WORD *)v6 + 4);
      goto LABEL_15;
    }
LABEL_20:
    LODWORD(v5) = -22;
    goto LABEL_21;
  }
  v7 = *(_QWORD *)(a2 + 8);
  if ( !v7 )
    goto LABEL_20;
  LODWORD(v11) = 4;
  if ( *(_DWORD *)v7 == 1 )
    v8 = 1;
  else
    v8 = 0xFFFF;
  if ( *(_DWORD *)v7 )
    v9 = v8;
  else
    v9 = 0;
  LODWORD(v12) = v9;
  v13 = *(_QWORD *)(v7 + 8);
LABEL_15:
  v5 = *(void (__fastcall **)(__int64, __int64 *))(*(_QWORD *)global_context + 88LL);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -2054464844 )
      __break(0x8228u);
    v5(a1 + 200, &v11);
    goto LABEL_19;
  }
LABEL_21:
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v5;
}

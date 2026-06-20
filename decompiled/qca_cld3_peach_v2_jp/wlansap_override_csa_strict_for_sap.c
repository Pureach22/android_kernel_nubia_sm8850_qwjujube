__int64 __fastcall wlansap_override_csa_strict_for_sap(__int64 a1, __int64 a2, unsigned int a3, char a4)
{
  __int64 v4; // x8
  __int64 v6; // x0
  char v9; // w20
  int v11; // [xsp+Ch] [xbp-14h] BYREF
  int v12; // [xsp+10h] [xbp-10h] BYREF
  int v13; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v14; // [xsp+18h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v13 = 7;
  if ( a1 )
  {
    v4 = *(_QWORD *)(a2 + 16);
    if ( v4 )
    {
      if ( *(_DWORD *)(v4 + 16) == 1 && *(_DWORD *)(a2 + 732) == 2 )
      {
        v6 = *(_QWORD *)(a1 + 21552);
        v9 = a4;
        v11 = 0;
        v12 = 0;
        if ( policy_mgr_is_force_scc(v6) )
        {
          if ( (unsigned __int8)policy_mgr_fetch_existing_con_info(
                                  *(_QWORD *)(a1 + 21552),
                                  *(_BYTE *)(a2 + 12),
                                  a3,
                                  &v13,
                                  &v12,
                                  &v11) == 0xFF
            || (a4 = v9, (v13 & 0xFFFFFFFD) != 0) )
          {
            a4 = 1;
          }
        }
        else
        {
          a4 = v9;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return a4 & 1;
}

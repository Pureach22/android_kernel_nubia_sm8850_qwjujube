__int64 __fastcall dp_soc_set_interrupt_mode(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x20
  __int64 v3; // x0
  char v4; // w8
  int v5; // [xsp+Ch] [xbp-14h] BYREF
  int v6; // [xsp+10h] [xbp-10h] BYREF
  int v7; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 40);
  *(_BYTE *)(result + 17840) = 0;
  if ( *(_BYTE *)(v1 + 545) != 1 )
  {
    v4 = 2;
    goto LABEL_5;
  }
  v2 = result;
  v3 = *(_QWORD *)(*(_QWORD *)(result + 24) + 40LL);
  v7 = 0;
  v5 = 0;
  v6 = 0;
  result = pld_get_user_msi_assignment(v3, (__int64)"DP", (__int64)&v5, (__int64)&v7, (__int64)&v6);
  if ( !(_DWORD)result )
  {
    v4 = 1;
    result = v2;
LABEL_5:
    *(_BYTE *)(result + 17840) = v4;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

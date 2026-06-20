__int64 __fastcall gsi_rndis_class_id_store(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x20
  _BYTE v6[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v7; // [xsp+8h] [xbp-8h]

  v7 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 176);
  v6[0] = 0;
  if ( (unsigned int)kstrtou8(a2, 0, v6) || (unsigned int)v6[0] - 1 > 8 )
    a3 = -22;
  else
    *(_DWORD *)(v4 + 280) = v6[0];
  _ReadStatusReg(SP_EL0);
  return a3;
}

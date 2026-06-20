__int64 __fastcall pld_pcie_wlan_enable(__int64 a1, int *a2, int a3)
{
  int v3; // w8
  __int64 v4; // x9
  __int64 v5; // x9
  unsigned int v6; // w8
  int v7; // w8
  __int64 v8; // x8
  int v9; // w9
  __int64 v10; // x10
  __int64 v11; // x2
  __int64 result; // x0
  _QWORD v13[4]; // [xsp+8h] [xbp-68h] BYREF
  __int64 v14; // [xsp+28h] [xbp-48h]
  __int64 v15; // [xsp+30h] [xbp-40h]
  __int64 v16; // [xsp+38h] [xbp-38h]
  __int64 v17; // [xsp+40h] [xbp-30h]
  __int64 v18; // [xsp+48h] [xbp-28h]
  __int64 v19; // [xsp+50h] [xbp-20h]
  __int64 v20; // [xsp+58h] [xbp-18h]
  __int64 v21; // [xsp+60h] [xbp-10h]
  __int64 v22; // [xsp+68h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a2;
  v4 = *((_QWORD *)a2 + 1);
  v14 = 0;
  v15 = 0;
  v17 = 0;
  v18 = 0;
  v13[0] = 0;
  v13[1] = v4;
  v5 = *((_QWORD *)a2 + 3);
  LODWORD(v13[0]) = v3;
  v6 = a2[4];
  v13[3] = v5;
  v13[2] = v6;
  v7 = a2[8];
  v20 = 0;
  v21 = 0;
  LODWORD(v14) = v7;
  v8 = *((_QWORD *)a2 + 5);
  v19 = 0;
  v15 = v8;
  v16 = 0;
  LODWORD(v16) = a2[12];
  v17 = *((_QWORD *)a2 + 7);
  LOBYTE(v18) = *((_BYTE *)a2 + 64);
  if ( (unsigned __int8)v18 == 1 )
  {
    v9 = a2[18];
    HIDWORD(v18) = a2[17];
    LODWORD(v19) = v9;
  }
  v10 = *((_QWORD *)a2 + 10);
  HIDWORD(v19) = a2[19];
  v20 = v10;
  if ( a3 == 1 )
    v11 = 1;
  else
    v11 = 2 * (unsigned int)(a3 == 2);
  result = cnss_wlan_enable(a1, v13, v11);
  _ReadStatusReg(SP_EL0);
  return result;
}

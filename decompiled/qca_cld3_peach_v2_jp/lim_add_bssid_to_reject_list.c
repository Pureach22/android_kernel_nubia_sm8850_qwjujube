__int64 __fastcall lim_add_bssid_to_reject_list(__int64 a1, __int64 a2, __int64 a3)
{
  __int16 v5; // w9
  char v6; // w10
  int v7; // w8
  int v8; // w8
  int v9; // w9
  __int64 v10; // x10
  int v11; // w9
  __int64 result; // x0
  __int64 v13; // [xsp+8h] [xbp-38h] BYREF
  __int64 v14; // [xsp+10h] [xbp-30h]
  __int64 v15; // [xsp+18h] [xbp-28h]
  __int64 v16; // [xsp+20h] [xbp-20h]
  __int64 v17; // [xsp+28h] [xbp-18h]
  __int64 v18; // [xsp+30h] [xbp-10h]
  __int64 v19; // [xsp+38h] [xbp-8h]

  v19 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v17 = 0;
  v18 = 0;
  v15 = 0;
  v16 = 0;
  v13 = 0;
  v14 = 0;
  qdf_mem_set(&v13, 0x30u, 0);
  v5 = *(_WORD *)(a3 + 20);
  v6 = *(_BYTE *)(a3 + 28);
  LODWORD(v13) = *(_DWORD *)(a3 + 16);
  v7 = *(_DWORD *)(a3 + 24);
  WORD2(v13) = v5;
  LODWORD(v14) = v7;
  v9 = *(_DWORD *)(a3 + 40);
  v8 = *(_DWORD *)(a3 + 44);
  BYTE4(v14) = v6;
  v10 = *(_QWORD *)(a3 + 56);
  HIDWORD(v17) = v9;
  LODWORD(v18) = v8;
  v11 = *(_DWORD *)(a3 + 48);
  v15 = v10;
  LODWORD(v17) = 4;
  LODWORD(v16) = v11;
  result = dlm_add_bssid_to_reject_list(a1, &v13);
  _ReadStatusReg(SP_EL0);
  return result;
}

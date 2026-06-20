__int64 __fastcall lim_add_bssid_to_reject_list(__int64 a1, unsigned int a2, __int64 a3)
{
  __int16 v6; // w9
  char v7; // w10
  int v8; // w8
  int v9; // w8
  int v10; // w9
  __int64 v11; // x10
  int v12; // w9
  __int64 result; // x0
  _QWORD v14[8]; // [xsp+0h] [xbp-70h] BYREF
  __int64 v15; // [xsp+40h] [xbp-30h]
  __int64 v16; // [xsp+48h] [xbp-28h]
  __int64 v17; // [xsp+50h] [xbp-20h]
  __int64 v18; // [xsp+58h] [xbp-18h]
  __int64 v19; // [xsp+60h] [xbp-10h]
  __int64 v20; // [xsp+68h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  v19 = 0;
  v16 = 0;
  v17 = 0;
  v15 = 0;
  memset(v14, 0, sizeof(v14));
  qdf_mem_set(v14, 0x68u, 0);
  v6 = *(_WORD *)(a3 + 20);
  v7 = *(_BYTE *)(a3 + 28);
  LODWORD(v14[0]) = *(_DWORD *)(a3 + 16);
  v8 = *(_DWORD *)(a3 + 24);
  WORD2(v14[0]) = v6;
  LODWORD(v15) = v8;
  v10 = *(_DWORD *)(a3 + 40);
  v9 = *(_DWORD *)(a3 + 44);
  BYTE4(v15) = v7;
  v11 = *(_QWORD *)(a3 + 56);
  HIDWORD(v18) = v10;
  LODWORD(v19) = v9;
  v12 = *(_DWORD *)(a3 + 48);
  v16 = v11;
  LODWORD(v18) = 4;
  LODWORD(v17) = v12;
  ((void (__fastcall *)(__int64, _QWORD, _QWORD *))dlm_update_mlo_reject_ap_info)(a1, a2, v14);
  result = dlm_add_bssid_to_reject_list(a1, v14);
  _ReadStatusReg(SP_EL0);
  return result;
}

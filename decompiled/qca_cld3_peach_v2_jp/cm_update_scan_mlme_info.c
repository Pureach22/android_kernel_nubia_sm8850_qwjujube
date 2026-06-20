__int64 __fastcall cm_update_scan_mlme_info(__int64 result, __int64 a2)
{
  int v2; // w9
  int v3; // w10
  int v4; // w9
  int v5; // w11
  int v6; // w10
  __int64 v7; // x19
  size_t v8; // x2
  _QWORD v9[2]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v10; // [xsp+10h] [xbp-50h]
  __int64 v11; // [xsp+18h] [xbp-48h]
  _DWORD v12[9]; // [xsp+2Ch] [xbp-34h] BYREF
  __int64 v13; // [xsp+50h] [xbp-10h]
  __int64 v14; // [xsp+58h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a2 + 8);
  v3 = *(unsigned __int16 *)(a2 + 12);
  v10 = 0;
  v11 = 0;
  v9[0] = 0;
  v9[1] = 0;
  v13 = 0;
  memset(&v12[1], 0, 32);
  if ( v2 | v3 )
  {
    v5 = *(_DWORD *)(a2 + 48);
    v4 = *(_DWORD *)(a2 + 52);
    v6 = *(_DWORD *)(a2 + 8);
    v7 = result;
    v8 = *(unsigned __int8 *)(a2 + 14);
    *(_WORD *)((char *)&v13 + 5) = *(_WORD *)(a2 + 12);
    *(_DWORD *)((char *)&v13 + 1) = v6;
    v12[0] = v5;
    LOBYTE(v12[1]) = v8;
    HIDWORD(v10) = 2 * (v4 == 0);
    qdf_mem_copy((char *)&v12[1] + 1, (const void *)(a2 + 15), v8);
    result = scm_scan_update_mlme_by_bssinfo(*(_QWORD *)(*(_QWORD *)v7 + 152LL), v12, v9);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

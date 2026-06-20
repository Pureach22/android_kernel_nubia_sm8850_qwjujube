__int64 __fastcall cm_update_scan_mlme_info(__int64 *a1, __int64 a2)
{
  int v4; // w8
  __int64 v5; // x21
  int v6; // w9
  int v7; // w8
  int v8; // w10
  size_t v9; // x2
  const void *v10; // x1
  bool v11; // zf
  __int16 v12; // w8
  int v13; // w9
  __int64 v14; // x1
  __int64 v15; // x9
  char v16; // w10
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x9
  __int64 result; // x0
  _QWORD v21[2]; // [xsp+8h] [xbp-88h] BYREF
  __int64 v22; // [xsp+18h] [xbp-78h]
  __int64 v23; // [xsp+20h] [xbp-70h]
  _QWORD v24[4]; // [xsp+30h] [xbp-60h] BYREF
  char v25; // [xsp+50h] [xbp-40h]
  _QWORD v26[7]; // [xsp+58h] [xbp-38h] BYREF

  v26[6] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a2 + 8;
  v4 = *(_DWORD *)(a2 + 8);
  v6 = *(unsigned __int16 *)(a2 + 12);
  v22 = 0;
  v23 = 0;
  v21[0] = 0;
  v21[1] = 0;
  memset(v26, 0, 44);
  if ( v4 | v6 )
  {
    v8 = *(_DWORD *)(a2 + 48);
    v7 = *(_DWORD *)(a2 + 52);
    v9 = *(unsigned __int8 *)(a2 + 14);
    v10 = (const void *)(a2 + 15);
    v11 = v7 == 0;
    v12 = *(_WORD *)(v5 + 4);
    *(_DWORD *)((char *)&v26[4] + 5) = *(_DWORD *)v5;
    v13 = v11;
    LODWORD(v26[0]) = v8;
    *(_WORD *)((char *)&v26[5] + 1) = v12;
    BYTE4(v26[0]) = v9;
    HIDWORD(v22) = 2 * v13;
    qdf_mem_copy((char *)v26 + 5, v10, v9);
    scm_scan_update_mlme_by_bssinfo(*(_QWORD *)(*a1 + 216), v26, v21);
    cm_update_link_channel_info(*a1, v5);
    v14 = HIDWORD(v22);
  }
  else
  {
    v14 = 0;
  }
  v15 = *(_QWORD *)(a2 + 38);
  v16 = *(_BYTE *)(a2 + 46);
  v17 = *a1;
  v24[2] = *(_QWORD *)(a2 + 30);
  v24[3] = v15;
  v18 = *(_QWORD *)(a2 + 22);
  v19 = *(_QWORD *)(a2 + 14);
  v25 = v16;
  v24[0] = v19;
  v24[1] = v18;
  result = cm_standby_link_update_mlme_by_bssid(v17, v14, v24);
  _ReadStatusReg(SP_EL0);
  return result;
}

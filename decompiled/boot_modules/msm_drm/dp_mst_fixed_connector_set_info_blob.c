__int64 __fastcall dp_mst_fixed_connector_set_info_blob(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x9
  __int64 v7; // x8
  _DWORD *v8; // x9
  __int64 v9; // x1
  _QWORD v11[2]; // [xsp+0h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a3 + 40);
  v5 = *(_QWORD *)(a1 + 2744);
  v11[0] = 0;
  if ( *(_QWORD *)(v4 + 1448) == v5 )
  {
    v6 = 1336;
  }
  else
  {
    if ( *(_QWORD *)(v4 + 2840) != v5 )
      goto LABEL_8;
    v6 = 2728;
  }
  v7 = v4 + v6;
  v8 = *(_DWORD **)(a3 + 328);
  v9 = *(unsigned int *)(v7 + 400);
  if ( *(v8 - 1) != -1699731847 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, __int64, _QWORD *))v8)(a3, v9, v11);
  ((void (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(a2, "display type", v11[0]);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return 0;
}

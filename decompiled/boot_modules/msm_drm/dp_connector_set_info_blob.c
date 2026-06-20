__int64 __fastcall dp_connector_set_info_blob(__int64 a1, __int64 a2, __int64 a3)
{
  _DWORD *v5; // x8
  _QWORD v7[2]; // [xsp+0h] [xbp-10h] BYREF

  v7[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = *(_DWORD **)(a3 + 320);
  v7[0] = 0;
  if ( *(v5 - 1) != 988268915 )
    __break(0x8228u);
  ((void (__fastcall *)(__int64, _QWORD *))v5)(a3, v7);
  ((void (__fastcall *)(__int64, const char *, _QWORD))sde_kms_info_add_keystr)(a2, "display type", v7[0]);
  if ( *(_BYTE *)(a3 + 34) == 1 && *(_BYTE *)(a3 + 73) == 1 )
    ((void (__fastcall *)(__int64, const char *, const char *))sde_kms_info_add_keystr)(
      a2,
      "ext bridge hpd support",
      "true");
  _ReadStatusReg(SP_EL0);
  return 0;
}

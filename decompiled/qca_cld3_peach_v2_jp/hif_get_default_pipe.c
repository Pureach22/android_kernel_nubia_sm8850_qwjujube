__int64 __fastcall hif_get_default_pipe(__int64 a1, _BYTE *a2, _BYTE *a3)
{
  __int64 result; // x0
  int v4; // [xsp+0h] [xbp-10h] BYREF
  int v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  result = hif_map_service_to_pipe(a1, 1u, a2, a3, &v5, &v4);
  _ReadStatusReg(SP_EL0);
  return result;
}

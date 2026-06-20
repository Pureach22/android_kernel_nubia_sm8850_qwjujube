__int64 __fastcall hdd_update_dynamic_tsf_sync(__int64 result)
{
  __int64 v1; // x19
  __int64 *v2; // x8
  __int64 v3; // x0
  _BYTE v4[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v5; // [xsp+8h] [xbp-8h]

  v1 = result;
  v5 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(__int64 **)(result + 24);
  if ( v2 )
  {
    v3 = *v2;
    v4[0] = 0;
    result = ucfg_fwol_get_tsf_sync_enable(v3, v4);
    LOBYTE(v2) = 0;
    if ( !(_DWORD)result )
      LOBYTE(v2) = v4[0];
  }
  *(_BYTE *)(v1 + 39344) = (unsigned __int8)v2 & 1;
  _ReadStatusReg(SP_EL0);
  return result;
}

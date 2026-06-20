__int64 stop_coalescing()
{
  _BYTE *v0; // x8
  __int64 result; // x0
  __int16 v2; // [xsp+4h] [xbp-Ch] BYREF
  char v3; // [xsp+6h] [xbp-Ah]
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = (_BYTE *)ipa3_ctx;
  if ( (*(_BYTE *)ipa3_ctx & 1) == 0 )
  {
    if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 && *(_DWORD *)(ipa3_ctx + 32240) >= 0x18u )
    {
      v3 = 0;
      v2 = 0;
      ipahal_read_reg_n_fields(163, 0, &v2);
      v3 = 1;
      result = ((__int64 (__fastcall *)(__int64, _QWORD, __int16 *))ipahal_write_reg_n_fields)(163, 0, &v2);
      v0 = (_BYTE *)ipa3_ctx;
    }
    *v0 = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

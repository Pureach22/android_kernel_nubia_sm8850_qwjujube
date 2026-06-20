__int64 __fastcall drm_dp_pcon_hdmi_frl_link_error_count(__int64 result, __int64 a2)
{
  const char **v3; // x20
  unsigned int v4; // w21
  int v5; // w8
  int v6; // w3
  const char *v7; // x8
  __int64 v8; // x0
  _BYTE v9[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v10; // [xsp+8h] [xbp-8h]

  v10 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( *(_BYTE *)(a2 + 346) )
  {
    v3 = (const char **)result;
    v4 = 0;
    v9[0] = 0;
    do
    {
      result = drm_dp_dpcd_read(v3, v4 + 12343, (__int64)v9, 1);
      if ( result < 0 )
        break;
      v5 = (v9[0] & 7) - 1;
      if ( (unsigned int)v5 > 3 )
      {
        v6 = 0;
        v7 = v3[157];
        if ( !v7 )
        {
LABEL_8:
          v8 = 0;
          goto LABEL_9;
        }
      }
      else
      {
        v6 = dword_1EE38[v5];
        v7 = v3[157];
        if ( !v7 )
          goto LABEL_8;
      }
      v8 = *((_QWORD *)v7 + 1);
LABEL_9:
      result = dev_err(v8, "[drm] *ERROR* %s: More than %d errors since the last read for lane %d", *v3, v6, v4++);
    }
    while ( v4 < *(unsigned __int8 *)(a2 + 346) );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

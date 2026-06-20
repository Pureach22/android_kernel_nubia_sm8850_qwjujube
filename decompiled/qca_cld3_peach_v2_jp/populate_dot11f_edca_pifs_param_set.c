__int64 __fastcall populate_dot11f_edca_pifs_param_set(__int64 a1, _BYTE *a2)
{
  __int64 v3; // x8
  int v4; // w22
  __int64 result; // x0
  size_t v6; // x2
  int v7; // [xsp+0h] [xbp-10h] BYREF
  char v8; // [xsp+4h] [xbp-Ch]
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *a2 = 1;
  a2[23] = 1;
  v3 = *(_QWORD *)(a1 + 8);
  v8 = 0;
  v7 = 0;
  v4 = *(_DWORD *)(v3 + 1028);
  result = wlan_mlme_set_edca_pifs_param((__int64)&v7, (unsigned __int8)v4);
  a2[24] = v4;
  if ( !(_BYTE)v4 )
  {
    v6 = 4;
    goto LABEL_5;
  }
  if ( (unsigned __int8)v4 == 1 )
  {
    v6 = 3;
LABEL_5:
    a2[25] = v6;
    result = (__int64)qdf_mem_copy(a2 + 26, (char *)&v7 + 1, v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall dot11f_pack_ie_channel_switch_wrapper(__int64 a1, _BYTE *a2, _BYTE *a3, unsigned int a4, int *a5)
{
  int v5; // w8
  int v6; // w23
  __int64 result; // x0
  char *v13; // x2
  _BYTE *v14; // x24
  unsigned int v15; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+8h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = (unsigned __int8)*a2;
  v6 = *a5;
  v15 = 0;
  if ( !v5 )
    goto LABEL_6;
  result = get_packed_size_core(a1, (__int64)a2, (int *)&v15, IES_ChannelSwitchWrapper);
  if ( (_DWORD)result )
    goto LABEL_7;
  if ( !*a2 )
  {
LABEL_6:
    result = 0;
    goto LABEL_7;
  }
  if ( v15 <= a4 )
  {
    *a3 = -60;
    v13 = a3 + 2;
    v14 = a3 + 1;
    *a5 += 2;
    result = pack_core(a1, (__int64)a2, v13, a4 - 2, a5, (__int64)&FFS_ChannelSwitchWrapper, IES_ChannelSwitchWrapper);
    if ( v14 )
      *v14 = *(_BYTE *)a5 - v6 - 2;
  }
  else
  {
    result = 268435461;
  }
LABEL_7:
  _ReadStatusReg(SP_EL0);
  return result;
}

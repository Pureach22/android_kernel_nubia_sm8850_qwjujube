__int64 __fastcall ufs_qcom_advertise_quirks(__int64 a1)
{
  _BYTE *v1; // x8
  __int64 result; // x0
  int v4; // w8

  if ( a1 )
  {
    v1 = *(_BYTE **)(a1 + 184);
    if ( v1[174] == 2 )
      *(_DWORD *)(a1 + 212) |= 0x20u;
    if ( (v1[360] & 1) != 0 || v1[3176] == 1 )
      *(_DWORD *)(a1 + 212) |= 0x800u;
    result = of_device_is_compatible(*(_QWORD *)(*(_QWORD *)(a1 + 64) + 744LL), "qcom,sm8550-ufshc");
    v4 = *(_DWORD *)(a1 + 212);
    if ( (_DWORD)result )
      v4 |= 0x2000000u;
    *(_DWORD *)(a1 + 212) = v4 | 0x400000;
  }
  else
  {
    __break(0x800u);
    return ufs_qcom_shared_ice_init(0);
  }
  return result;
}

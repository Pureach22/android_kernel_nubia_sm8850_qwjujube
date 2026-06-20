__int64 __fastcall extract_sw_cal_ver_ext2_tlv(__int64 a1, __int64 a2, _DWORD *a3)
{
  _DWORD *v3; // x8

  if ( !a2 )
    return 4;
  v3 = *(_DWORD **)(a2 + 176);
  if ( !v3 )
    return 4;
  *a3 = v3[1];
  a3[1] = v3[2];
  a3[2] = v3[3];
  return 0;
}

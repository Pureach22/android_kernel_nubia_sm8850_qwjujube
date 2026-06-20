__int64 __fastcall cnss_dev_specific_power_on(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  __int64 v8; // x20
  __int64 result; // x0
  __int64 v11; // x2
  __int64 v12; // x3
  __int64 v13; // x4
  __int64 v14; // x5
  __int64 v15; // x6
  __int64 v16; // x7

  if ( *(_DWORD *)(a1 + 7736) != 2 )
    return 0;
  v8 = a1 + 4096;
  if ( (*(_BYTE *)(a1 + 7880) & 1) != 0 )
    return 0;
  result = cnss_get_vreg_type((__int64 *)a1, 0, a3, a4, a5, a6, a7, a8);
  if ( !(_DWORD)result )
  {
    *(_BYTE *)(v8 + 2417) = 0;
    return cnss_power_on_device(a1, 0, v11, v12, v13, v14, v15, v16);
  }
  return result;
}

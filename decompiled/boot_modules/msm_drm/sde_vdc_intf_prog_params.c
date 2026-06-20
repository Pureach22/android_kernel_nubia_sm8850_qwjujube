__int64 __fastcall sde_vdc_intf_prog_params(__int64 result, int a2)
{
  int v2; // w9
  int v3; // w10
  int v4; // w9
  int v5; // w11
  int v6; // w12
  int v7; // w9
  int v8; // w9

  v2 = *(_DWORD *)(result + 476);
  v3 = (a2 + v2 - 1) / v2;
  v4 = v2 * (*(unsigned __int16 *)(result + 454) >> 4);
  v5 = *(_DWORD *)(result + 504);
  v6 = v4 + 7;
  v7 = v4 + 14;
  if ( v5 > v3 )
    v5 = 1;
  if ( v6 >= 0 )
    v7 = v6;
  v8 = v7 >> 3;
  *(_DWORD *)(result + 488) = v8;
  *(_DWORD *)(result + 492) = v8 * v5;
  *(_DWORD *)(result + 508) = v3 / v5;
  *(_DWORD *)(result + 500) = (v8 * v3 + 2) / 3;
  *(_DWORD *)(result + 496) = v8 * v3 % 3;
  return result;
}

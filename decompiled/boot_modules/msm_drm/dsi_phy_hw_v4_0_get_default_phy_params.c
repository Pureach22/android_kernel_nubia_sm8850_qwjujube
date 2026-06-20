__int64 __fastcall dsi_phy_hw_v4_0_get_default_phy_params(__int64 result, int a2)
{
  int v2; // w8
  int v3; // w9
  int v4; // w10

  if ( a2 == 1 )
  {
    v2 = 1;
    v3 = 80;
    v4 = 20;
  }
  else
  {
    v2 = 0;
    *(_QWORD *)(result + 24) = 0x1E00000002LL;
    *(_QWORD *)(result + 32) = 0xA00000032LL;
    v3 = 5;
    v4 = 1;
    *(_DWORD *)(result + 40) = 30;
  }
  *(_DWORD *)(result + 52) = v4;
  *(_DWORD *)(result + 56) = v3;
  *(_DWORD *)(result + 20) = 50;
  *(_DWORD *)(result + 44) = v2;
  *(_DWORD *)(result + 48) = 10;
  return result;
}

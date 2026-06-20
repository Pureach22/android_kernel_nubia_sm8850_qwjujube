__int64 __fastcall cam_vfe_bus_ver3_update_wm_ubwc_data(__int64 result, __int64 a2, _DWORD *a3, char a4)
{
  int v4; // w8
  int v5; // w8
  int v6; // w8
  int v7; // w8
  int v8; // w8
  int v9; // w8
  int v10; // w8
  int v11; // w8

  if ( !*(_DWORD *)(result + 140) )
  {
    v4 = a3[8];
    if ( *(_DWORD *)(result + 40) != v4 || (a4 & 1) == 0 )
    {
      *(_DWORD *)(result + 40) = v4;
      *(_BYTE *)a2 = 1;
    }
  }
  v5 = a3[1];
  if ( *(_DWORD *)(a2 + 8) != v5 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 8) = v5;
    *(_BYTE *)a2 = 1;
  }
  v6 = a3[5];
  if ( *(_DWORD *)(a2 + 12) != v6 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 12) = v6;
    *(_BYTE *)a2 = 1;
  }
  v7 = a3[11];
  if ( *(_DWORD *)(a2 + 20) != v7 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 20) = v7;
    *(_BYTE *)a2 = 1;
  }
  v8 = a3[13];
  if ( *(_DWORD *)(a2 + 24) != v8 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 24) = v8;
    *(_BYTE *)a2 = 1;
  }
  v9 = a3[14];
  if ( *(_DWORD *)(a2 + 28) != v9 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 28) = v9;
    *(_BYTE *)a2 = 1;
  }
  v10 = a3[15];
  if ( *(_DWORD *)(a2 + 32) != v10 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 32) = v10;
    *(_BYTE *)a2 = 1;
  }
  v11 = a3[16];
  if ( *(_DWORD *)(a2 + 36) != v11 || (a4 & 1) == 0 )
  {
    *(_DWORD *)(a2 + 36) = v11;
    *(_BYTE *)a2 = 1;
  }
  return result;
}

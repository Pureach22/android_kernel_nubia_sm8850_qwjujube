__int64 __fastcall csr_get_cfg_valid_channels(__int64 a1, __int64 a2, _DWORD *a3)
{
  __int64 v3; // x9
  int v5; // w8
  int v7; // w8
  unsigned __int8 v8; // w21
  __int64 v9; // x22
  __int64 v10; // x23
  __int64 v11; // x9

  v3 = *(_QWORD *)(a1 + 8);
  v5 = *(_DWORD *)(v3 + 6176);
  *a3 = v5;
  if ( v5 )
  {
    v7 = 0;
    v8 = 0;
    v9 = v3 + 5776;
    do
    {
      v10 = v7;
      if ( (wlan_reg_is_dsrc_freq() & 1) == 0 )
      {
        v11 = v8++;
        *(_DWORD *)(a2 + 4 * v11) = *(_DWORD *)(v9 + 4 * v10);
      }
      v7 = v10 + 1;
    }
    while ( (unsigned int)(v10 + 1) < *a3 );
    v5 = v8;
  }
  *a3 = v5;
  return 0;
}

__int64 __fastcall msm_vidc_update_meta_port_settings(__int64 a1)
{
  __int64 v1; // x20
  __int64 v3; // x8
  __int64 (*v4)(void); // x8
  int v5; // w0
  __int64 v6; // x8
  int v7; // w9
  __int64 v8; // x8
  __int64 v9; // x9
  int v10; // w10

  v1 = *(_QWORD *)(a1 + 320);
  if ( v1 && (v3 = *(_QWORD *)(v1 + 6560)) != 0 && (v4 = *(__int64 (**)(void))(v3 + 48)) != nullptr )
  {
    if ( *((_DWORD *)v4 - 1) != 1958436756 )
      __break(0x8228u);
    v5 = v4();
  }
  else
  {
    v5 = 0;
  }
  v6 = *(_QWORD *)(a1 + 2520);
  v7 = *(_DWORD *)(a1 + 2528);
  *(_DWORD *)(a1 + 812) = v5;
  *(_DWORD *)(a1 + 2652) = v5;
  *(_QWORD *)(a1 + 2640) = v6;
  *(_DWORD *)(a1 + 2648) = v7;
  if ( v1 )
  {
    v8 = *(_QWORD *)(v1 + 6560);
    if ( v8 )
    {
      v8 = *(_QWORD *)(v8 + 48);
      if ( v8 )
      {
        if ( *(_DWORD *)(v8 - 4) != 1958436756 )
          __break(0x8228u);
        LODWORD(v8) = ((__int64 (__fastcall *)(__int64, __int64))v8)(a1, 4);
      }
    }
  }
  else
  {
    LODWORD(v8) = 0;
  }
  v9 = *(_QWORD *)(a1 + 2560);
  v10 = *(_DWORD *)(a1 + 2568);
  *(_DWORD *)(a1 + 1020) = v8;
  *(_QWORD *)(a1 + 2680) = v9;
  *(_DWORD *)(a1 + 2688) = v10;
  *(_DWORD *)(a1 + 2692) = v8;
  return 0;
}

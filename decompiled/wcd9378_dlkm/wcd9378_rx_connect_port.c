__int64 __fastcall wcd9378_rx_connect_port(__int64 a1, unsigned __int8 a2, char a3)
{
  __int64 v3; // x0
  __int64 v4; // x8
  unsigned int v5; // w10
  unsigned int v6; // w9
  int v7; // w9
  __int64 v8; // x0
  _DWORD *v9; // x9
  __int64 result; // x0
  int v11; // [xsp+4h] [xbp-1Ch] BYREF
  _BYTE v12[4]; // [xsp+8h] [xbp-18h] BYREF
  _BYTE v13[4]; // [xsp+Ch] [xbp-14h] BYREF
  _BYTE v14[4]; // [xsp+10h] [xbp-10h] BYREF
  _BYTE v15[4]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 24);
  v4 = *(_QWORD *)(v3 + 152);
  if ( *(_DWORD *)(v4 + 1748) == a2 )
  {
    v5 = 0;
    v6 = 0;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1768) == a2 )
  {
    v5 = 0;
    v6 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1788) == a2 )
  {
    v5 = 0;
    v6 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1808) == a2 )
  {
    v5 = 0;
    v6 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1828) == a2 )
  {
    v5 = 0;
    v6 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1848) == a2 )
  {
    v5 = 0;
    v6 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1868) == a2 )
  {
    v5 = 0;
    v6 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1888) == a2 )
  {
    v5 = 0;
LABEL_17:
    v6 = 7;
    goto LABEL_135;
  }
  v7 = *(unsigned __int8 *)(v4 + 465);
  if ( !*(_BYTE *)(v4 + 465) )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 1908) == a2 )
  {
    v6 = 0;
    v5 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1928) == a2 )
  {
    v5 = 1;
    v6 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1948) == a2 )
  {
    v6 = 2;
    v5 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1968) == a2 )
  {
    v6 = 3;
    v5 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 1988) == a2 )
  {
    v6 = 4;
    v5 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2008) == a2 )
  {
    v6 = 5;
    v5 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2028) == a2 )
  {
    v6 = 6;
    v5 = 1;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2048) == a2 )
  {
    v6 = 7;
    v5 = 1;
    goto LABEL_135;
  }
  if ( v7 == 1 )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 2068) == a2 )
  {
    v6 = 0;
    v5 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2088) == a2 )
  {
    v6 = 1;
    v5 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2108) == a2 )
  {
    v5 = 2;
    v6 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2128) == a2 )
  {
    v6 = 3;
    v5 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2148) == a2 )
  {
    v6 = 4;
    v5 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2168) == a2 )
  {
    v6 = 5;
    v5 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2188) == a2 )
  {
    v6 = 6;
    v5 = 2;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2208) == a2 )
  {
    v6 = 7;
    v5 = 2;
    goto LABEL_135;
  }
  if ( v7 == 2 )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 2228) == a2 )
  {
    v6 = 0;
    v5 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2248) == a2 )
  {
    v6 = 1;
    v5 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2268) == a2 )
  {
    v6 = 2;
    v5 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2288) == a2 )
  {
    v5 = 3;
    v6 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2308) == a2 )
  {
    v6 = 4;
    v5 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2328) == a2 )
  {
    v6 = 5;
    v5 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2348) == a2 )
  {
    v6 = 6;
    v5 = 3;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2368) == a2 )
  {
    v6 = 7;
    v5 = 3;
    goto LABEL_135;
  }
  if ( v7 == 3 )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 2388) == a2 )
  {
    v6 = 0;
    v5 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2408) == a2 )
  {
    v6 = 1;
    v5 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2428) == a2 )
  {
    v6 = 2;
    v5 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2448) == a2 )
  {
    v6 = 3;
    v5 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2468) == a2 )
  {
    v5 = 4;
    v6 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2488) == a2 )
  {
    v6 = 5;
    v5 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2508) == a2 )
  {
    v6 = 6;
    v5 = 4;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2528) == a2 )
  {
    v6 = 7;
    v5 = 4;
    goto LABEL_135;
  }
  if ( v7 == 4 )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 2548) == a2 )
  {
    v6 = 0;
    v5 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2568) == a2 )
  {
    v6 = 1;
    v5 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2588) == a2 )
  {
    v6 = 2;
    v5 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2608) == a2 )
  {
    v6 = 3;
    v5 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2628) == a2 )
  {
    v6 = 4;
    v5 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2648) == a2 )
  {
    v5 = 5;
    v6 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2668) == a2 )
  {
    v6 = 6;
    v5 = 5;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2688) == a2 )
  {
    v6 = 7;
    v5 = 5;
    goto LABEL_135;
  }
  if ( v7 == 5 )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 2708) == a2 )
  {
    v6 = 0;
    v5 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2728) == a2 )
  {
    v6 = 1;
    v5 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2748) == a2 )
  {
    v6 = 2;
    v5 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2768) == a2 )
  {
    v6 = 3;
    v5 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2788) == a2 )
  {
    v6 = 4;
    v5 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2808) == a2 )
  {
    v6 = 5;
    v5 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2828) == a2 )
  {
    v5 = 6;
    v6 = 6;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2848) == a2 )
  {
    v6 = 7;
    v5 = 6;
    goto LABEL_135;
  }
  if ( v7 == 6 )
    goto LABEL_142;
  if ( *(_DWORD *)(v4 + 2868) == a2 )
  {
    v6 = 0;
    v5 = 7;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2888) == a2 )
  {
    v6 = 1;
    v5 = 7;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2908) == a2 )
  {
    v6 = 2;
    v5 = 7;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2928) == a2 )
  {
    v6 = 3;
    v5 = 7;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2948) == a2 )
  {
    v6 = 4;
    v5 = 7;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2968) == a2 )
  {
    v6 = 5;
    v5 = 7;
    goto LABEL_135;
  }
  if ( *(_DWORD *)(v4 + 2988) == a2 )
  {
    v6 = 6;
    v5 = 7;
LABEL_135:
    v15[0] = v5;
    v8 = *(_QWORD *)(v4 + 56);
    v9 = (_DWORD *)(v4 + 1748 + 160LL * v5 + 20LL * v6);
    v14[0] = v9[3];
    v13[0] = v9[2];
    v11 = v9[4];
    v12[0] = v9[1];
    if ( a3 )
      result = swr_connect_port(v8, v15, 1, v13, &v11, v14, v12);
    else
      result = swr_disconnect_port(v8, v15, 1, v13, v12);
    goto LABEL_138;
  }
  if ( *(_DWORD *)(v4 + 3008) == a2 )
  {
    v5 = 7;
    goto LABEL_17;
  }
  if ( v7 == 7 )
  {
LABEL_142:
    result = dev_err(v3, "%s Failed to find slave port for type %u\n", "wcd9378_set_port_params", a2);
LABEL_138:
    _ReadStatusReg(SP_EL0);
    return result;
  }
  __break(0x5512u);
  return wcd9378_init_reg(v3);
}

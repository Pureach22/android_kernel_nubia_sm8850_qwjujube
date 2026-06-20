__int64 __fastcall msm_vidc_get_recon_buf_count(__int64 a1)
{
  int v1; // w9
  int v2; // w10
  int v3; // w11
  unsigned __int64 v4; // x8
  int v5; // w14
  int v6; // w11
  int v7; // w12
  bool v8; // cf
  int v9; // w9
  int v10; // w13
  int v11; // w13
  bool v12; // zf
  int v13; // w8
  int v14; // w9
  int v15; // w8

  v1 = *(_DWORD *)(a1 + 312);
  v2 = *(_DWORD *)(a1 + 1832);
  v3 = *(_DWORD *)(a1 + 15272);
  v4 = 0x41uLL >> ((unsigned __int8)v1 - 2);
  if ( v2 == 3 )
    v5 = 0;
  else
    v5 = v3 + 1;
  v6 = v3 + 1;
  if ( (unsigned int)(v1 - 2) > 0x3E )
    LOBYTE(v4) = 0;
  if ( v1 == 1 )
    LOBYTE(v4) = 0;
  if ( *(_DWORD *)(a1 + 15944) )
    v7 = 2;
  else
    v7 = 1;
  v8 = v1 != 1 || (unsigned int)v5 >= 4;
  v9 = (v5 + 1) >> 1;
  v10 = !v8;
  v11 = v5 - v10;
  if ( (v4 & 1) != 0 )
    v11 = (v5 + 1) >> 1;
  if ( v2 != 2 )
    v9 = v11;
  if ( v5 < 2 )
    v9 = v7;
  if ( v2 != 3 )
    v6 = 0;
  v13 = (unsigned __int8)v4 & ((*(_QWORD *)(a1 + 15104) & 0xFFFFFFFELL) == 4);
  v12 = v13 == 0;
  v14 = v9 + *(_QWORD *)(a1 + 11744);
  v15 = v6 << v13;
  if ( !v12 )
    v14 = 3;
  if ( v6 <= 1 )
    v15 = v14;
  return (unsigned int)((v15 + 1) << (*(unsigned int *)(a1 + 35936) != 0));
}

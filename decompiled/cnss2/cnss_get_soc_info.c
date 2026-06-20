__int64 __fastcall cnss_get_soc_info(__int64 a1, unsigned __int64 a2)
{
  _QWORD *v2; // x8
  __int64 v3; // x20
  size_t v5; // x0
  unsigned __int64 v6; // x2
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x10
  __int64 v10; // x11
  __int64 v11; // x8
  __int64 v12; // x10
  __int64 v13; // x11
  __int64 v15; // x0
  unsigned __int64 *v16; // x10

  v2 = *(_QWORD **)(a1 + 152);
  if ( !v2 )
    return 4294967277LL;
  v3 = v2[1];
  if ( !v3 )
    return 4294967277LL;
  *(_QWORD *)a2 = v2[40];
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(*v2 + 1120LL);
  *(_DWORD *)(a2 + 16) = *(_DWORD *)(v3 + 1464);
  *(_DWORD *)(a2 + 20) = *(_DWORD *)(v3 + 1468);
  *(_DWORD *)(a2 + 24) = *(_DWORD *)(v3 + 1472);
  *(_DWORD *)(a2 + 28) = *(_DWORD *)(v3 + 1476);
  *(_DWORD *)(a2 + 32) = *(_DWORD *)(v3 + 1480);
  v5 = strnlen((const char *)(v3 + 1484), 0x21u);
  if ( v5 >= 0x22 )
  {
    _fortify_panic(2, 33, v5 + 1);
  }
  else
  {
    if ( v5 == 33 )
      v6 = 33;
    else
      v6 = v5 + 1;
    if ( v6 < 0x22 )
    {
      sized_strscpy(a2 + 36, v3 + 1484);
      v7 = *(_QWORD *)(v3 + 512);
      *(_QWORD *)(a2 + 72) = *(_QWORD *)(v3 + 504);
      *(_QWORD *)(a2 + 80) = v7;
      v8 = *(_QWORD *)(v3 + 1544);
      v9 = *(_QWORD *)(v3 + 1528);
      v10 = *(_QWORD *)(v3 + 1520);
      *(_QWORD *)(a2 + 104) = *(_QWORD *)(v3 + 1536);
      *(_QWORD *)(a2 + 112) = v8;
      *(_QWORD *)(a2 + 88) = v10;
      *(_QWORD *)(a2 + 96) = v9;
      v11 = *(_QWORD *)(v3 + 1576);
      v12 = *(_QWORD *)(v3 + 1560);
      v13 = *(_QWORD *)(v3 + 1552);
      *(_QWORD *)(a2 + 136) = *(_QWORD *)(v3 + 1568);
      *(_QWORD *)(a2 + 144) = v11;
      *(_QWORD *)(a2 + 120) = v13;
      *(_QWORD *)(a2 + 128) = v12;
      memcpy((void *)(a2 + 152), (const void *)(v3 + 1584), 0x81u);
      return 0;
    }
  }
  v15 = _fortify_panic(7, 33, v6);
  __stxr(a2, v16);
  return cnss_pci_get_user_msi_assignment(v15);
}

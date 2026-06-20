__int64 __fastcall cnss_pci_clear_dump_info(__int64 result)
{
  __int64 v1; // x24
  __int64 v2; // x8
  __int64 *v3; // x19
  __int64 v4; // x25
  __int64 v5; // x26
  unsigned int v6; // w20
  __int64 *v7; // x8
  __int64 v8; // x21
  __int64 v9; // x3
  __int64 v10; // x22
  __int64 v11; // x8
  __int64 v12; // x23
  __int64 v13; // x6
  __int64 v14; // x7
  unsigned int v15; // w20
  __int64 *v16; // x8
  __int64 v17; // x21
  __int64 v18; // x3
  __int64 v19; // x22
  __int64 v20; // x8
  __int64 v21; // x23
  __int64 v22; // x6
  __int64 v23; // x7
  unsigned int v24; // w20
  unsigned int i; // w25
  __int64 v26; // x3
  __int64 v27; // x21
  __int64 v28; // x22
  __int64 v29; // x8
  __int64 v30; // x23
  __int64 v31; // x6
  __int64 v32; // x7
  __int64 v33; // x4
  __int64 v34; // x0
  unsigned int v35; // w1
  __int64 v36; // x8
  int v37; // w9
  __int64 v38; // x3
  __int64 v39; // x8
  __int64 v40; // x23
  __int64 v41[2]; // [xsp+0h] [xbp-10h] BYREF

  v41[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v1 = *(_QWORD *)(result + 8);
  if ( *(_QWORD *)(v1 + 272) )
  {
    v2 = *(_QWORD *)(result + 344);
    v3 = (__int64 *)result;
    v5 = *(_QWORD *)(v2 + 152);
    v4 = *(_QWORD *)(v2 + 160);
    if ( *(_DWORD *)(v5 + 16) )
    {
      v6 = 0;
      do
      {
        v7 = (__int64 *)(*(_QWORD *)v5 + 32LL * (int)v6);
        v8 = *v7;
        v9 = v7[2];
        v10 = v7[3];
        v11 = *v3;
        v12 = v3[1];
        v41[0] = 0;
        cnss_va_to_pa(v11 + 200, v10, v8, v9, v41);
        result = cnss_minidump_remove_region(v12, 0, v6++, v8, v41[0], v10, v13, v14);
      }
      while ( v6 < *(_DWORD *)(v5 + 16) );
    }
    if ( *(_DWORD *)(v4 + 16) )
    {
      v15 = 0;
      do
      {
        v16 = (__int64 *)(*(_QWORD *)v4 + 32LL * (int)v15);
        v17 = *v16;
        v18 = v16[2];
        v19 = v16[3];
        v20 = *v3;
        v21 = v3[1];
        v41[0] = 0;
        cnss_va_to_pa(v20 + 200, v19, v17, v18, v41);
        result = cnss_minidump_remove_region(v21, 1u, v15++, v17, v41[0], v19, v22, v23);
      }
      while ( v15 < *(_DWORD *)(v4 + 16) );
    }
    if ( *(_DWORD *)(v1 + 1720) )
    {
      v24 = 0;
      for ( i = 0; i < *(_DWORD *)(v1 + 1720); ++i )
      {
        v36 = v1 + 1728 + 40LL * (int)i;
        v37 = *(_DWORD *)(v36 + 28);
        if ( v37 == 4 )
        {
          v27 = *(_QWORD *)(v36 + 8);
          v26 = *(_QWORD *)(v36 + 16);
          v28 = *(_QWORD *)v36;
          v29 = *v3;
          v30 = v3[1];
          v41[0] = 0;
          cnss_va_to_pa(v29 + 200, v28, v27, v26, v41);
          v33 = v41[0];
          v34 = v30;
          v35 = 3;
        }
        else
        {
          if ( v37 != 1 || (*(_BYTE *)(v36 + 32) & 0x40) == 0 )
            continue;
          v27 = *(_QWORD *)(v36 + 8);
          v38 = *(_QWORD *)(v36 + 16);
          v28 = *(_QWORD *)v36;
          v39 = *v3;
          v40 = v3[1];
          v41[0] = 0;
          cnss_va_to_pa(v39 + 200, v28, v27, v38, v41);
          v33 = v41[0];
          v34 = v40;
          v35 = 2;
        }
        result = cnss_minidump_remove_region(v34, v35, v24++, v27, v33, v28, v31, v32);
      }
    }
    *(_DWORD *)(v1 + 336) = 0;
    *(_BYTE *)(v1 + 280) = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

__int64 __fastcall handle_aer_irq(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 result; // x0
  __int64 v5; // x20
  int *v6; // x8
  int v7; // w26
  int v8; // w27
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x9
  __int64 v12; // x0
  int v13; // w8
  __int64 v14; // x0
  unsigned int v15; // w8
  _QWORD v16[6]; // [xsp+0h] [xbp-60h] BYREF
  __int64 v17; // [xsp+30h] [xbp-30h]
  __int64 v18; // [xsp+38h] [xbp-28h]
  __int64 v19; // [xsp+40h] [xbp-20h]
  __int64 v20; // [xsp+48h] [xbp-18h]
  __int64 v21; // [xsp+50h] [xbp-10h]
  __int64 v22; // [xsp+58h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a2 + 2004);
  if ( *(_DWORD *)(a2 + 2000) == v2 )
  {
    result = 0;
  }
  else
  {
    v5 = a2 + 2024;
    do
    {
      v6 = (int *)(v5 + 8LL * (*(_DWORD *)(a2 + 2008) & v2));
      v7 = *v6;
      v8 = v6[1];
      __dmb(0xAu);
      v20 = 0;
      v21 = 0;
      LODWORD(v6) = *(_DWORD *)(a2 + 2004);
      v18 = 0;
      v19 = 0;
      v17 = 0;
      memset(&v16[3], 0, 24);
      *(_DWORD *)(a2 + 2004) = (_DWORD)v6 + 1;
      v9 = *(_QWORD *)(a2 + 8);
      v16[1] = 0;
      v16[2] = 0;
      v10 = *(_QWORD *)(v9 + 80);
      v16[0] = a2;
      if ( v10 )
      {
        if ( (v7 & 1) != 0 )
          ++*(_QWORD *)(v10 + 584);
        if ( (v7 & 4) != 0 )
        {
          if ( (v7 & 0x40) != 0 )
            v11 = 592;
          else
            v11 = 600;
          ++*(_QWORD *)(v10 + v11);
        }
      }
      if ( (v7 & 1) != 0 )
      {
        v12 = *(_QWORD *)(a2 + 8);
        v13 = (v7 & 2) != 0 ? 8519680 : 0x20000;
        HIDWORD(v17) = v13 & 0xFFFF0000 | (unsigned __int16)v8;
        msm_aer_print_port_info(v12, v16);
        if ( (msm_find_source_device(*(_QWORD *)(a2 + 8), v16) & 1) != 0 )
          msm_aer_process_err_devices(v16);
      }
      if ( (v7 & 4) != 0 )
      {
        v14 = *(_QWORD *)(a2 + 8);
        v15 = (v7 << 10) & 0x10000 | HIWORD(v8) | HIDWORD(v17) & 0xFFFC0000 | 0x800000;
        if ( (v7 & 8) == 0 )
          v15 = (v7 << 10) & 0x10000 | HIWORD(v8) | HIDWORD(v17) & 0xFF7C0000;
        HIDWORD(v17) = v15;
        msm_aer_print_port_info(v14, v16);
        if ( (msm_find_source_device(*(_QWORD *)(a2 + 8), v16) & 1) != 0 )
          msm_aer_process_err_devices(v16);
      }
      v2 = *(_DWORD *)(a2 + 2004);
    }
    while ( *(_DWORD *)(a2 + 2000) != v2 );
    result = 1;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

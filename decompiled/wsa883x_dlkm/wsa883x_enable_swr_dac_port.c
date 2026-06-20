__int64 __fastcall wsa883x_enable_swr_dac_port(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x19
  __int64 result; // x0
  char v6; // w8
  char v7; // w10
  int v8; // w9
  int v9; // w8
  char v10; // w10
  int v11; // w10
  char v12; // w9
  char v13; // w11
  __int64 v14; // x2
  unsigned int v15; // w2
  __int64 v16; // x8
  __int64 v17; // x9
  _BYTE *v18; // x10
  _BYTE *v19; // x8
  unsigned __int64 v26; // x9
  unsigned __int64 v29; // x9
  unsigned __int64 v32; // x9
  unsigned __int64 v35; // x10
  unsigned __int64 v38; // x10
  __int64 v39; // [xsp+8h] [xbp-28h] BYREF
  __int64 v40; // [xsp+10h] [xbp-20h] BYREF
  int v41; // [xsp+18h] [xbp-18h]
  __int64 v42; // [xsp+1Ch] [xbp-14h]
  int v43; // [xsp+24h] [xbp-Ch]
  __int64 v44; // [xsp+28h] [xbp-8h]

  v44 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
  if ( v4 )
  {
    result = 0;
    v39 = 0;
    v40 = 0;
    v42 = 0;
    v43 = 0;
    if ( a3 > 3 )
    {
      if ( a3 == 4 )
      {
        v11 = *(unsigned __int8 *)(v4 + 32);
        v12 = *(_BYTE *)(v4 + 41);
        v13 = *(_BYTE *)(v4 + 49);
        BYTE4(v40) = *(_BYTE *)(v4 + 40);
        BYTE4(v39) = v12;
        LOBYTE(v39) = v13;
        if ( v11 == 1 && (*(_QWORD *)(v4 + 400) & 1) != 0 )
        {
          BYTE5(v40) = *(_BYTE *)(v4 + 52);
          BYTE5(v39) = *(_BYTE *)(v4 + 53);
          BYTE1(v39) = *(_BYTE *)(v4 + 61);
          _X8 = (unsigned __int64 *)(v4 + 400);
          __asm { PRFM            #0x11, [X8] }
          do
            v35 = __ldxr(_X8);
          while ( __stxr(v35 & 0xFFFFFFFFFFFFFFFELL, _X8) );
          v14 = 2;
        }
        else
        {
          v14 = 1;
        }
        if ( *(_BYTE *)(v4 + 33) == 1 && (*(_QWORD *)(v4 + 400) & 2) != 0 )
        {
          v17 = (unsigned int)v14;
          v18 = (_BYTE *)(((unsigned __int64)&v40 + 4) | (unsigned int)v14);
          v14 = (unsigned int)(v14 + 1);
          v19 = *(_BYTE **)(*(_QWORD *)(v3 - 184) + 152LL);
          *v18 = v19[76];
          *(_BYTE *)(((unsigned __int64)&v39 + 4) | v17) = v19[77];
          *(_BYTE *)((unsigned __int64)&v39 | v17) = v19[85];
          _X8 = (unsigned __int64 *)(v4 + 400);
          __asm { PRFM            #0x11, [X8] }
          do
            v38 = __ldxr(_X8);
          while ( __stxr(v38 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        }
        swr_disconnect_port(*(_QWORD *)(v4 + 16), (char *)&v40 + 4, v14, (char *)&v39 + 4, &v39);
        goto LABEL_28;
      }
      if ( a3 == 8 )
      {
        if ( (unsigned int)swr_set_device_group(*(_QWORD *)(v4 + 16), 0) )
          dev_err(*(_QWORD *)(v3 - 184), "%s: set num ch failed\n", "wsa883x_enable_swr_dac_port");
        swr_slvdev_datapath_control(*(_QWORD *)(v4 + 16), *(unsigned __int8 *)(*(_QWORD *)(v4 + 16) + 64LL), 0);
        goto LABEL_28;
      }
    }
    else
    {
      if ( a3 == 1 )
      {
        v6 = *(_BYTE *)(v4 + 40);
        v7 = *(_BYTE *)(v4 + 41);
        LOBYTE(v40) = *(_BYTE *)(v4 + 48);
        v8 = *(_DWORD *)(v4 + 92);
        BYTE4(v40) = v6;
        v9 = *(_DWORD *)(v4 + 44);
        BYTE4(v39) = v7;
        v10 = *(_BYTE *)(v4 + 49);
        v41 = v9;
        LOBYTE(v39) = v10;
        if ( v8 == 1 )
          v41 = 4800000;
        if ( *(_BYTE *)(v4 + 32) == 1 )
        {
          BYTE5(v40) = *(_BYTE *)(v4 + 52);
          BYTE1(v40) = *(_BYTE *)(v4 + 60);
          BYTE5(v39) = *(_BYTE *)(v4 + 53);
          LODWORD(v42) = *(_DWORD *)(v4 + 56);
          BYTE1(v39) = *(_BYTE *)(v4 + 61);
          _X8 = (unsigned __int64 *)(v4 + 400);
          __asm { PRFM            #0x11, [X8] }
          do
            v29 = __ldxr(_X8);
          while ( __stxr(v29 | 1, _X8) );
          v15 = 2;
        }
        else
        {
          v15 = 1;
        }
        if ( *(_BYTE *)(v4 + 33) == 1 )
        {
          v16 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
          *(_BYTE *)(((unsigned __int64)&v40 + 4) | v15) = *(_BYTE *)(v16 + 76);
          *(_BYTE *)((unsigned __int64)&v40 | v15) = *(_BYTE *)(v16 + 84);
          *(_BYTE *)(((unsigned __int64)&v39 + 4) | v15) = *(_BYTE *)(v16 + 77);
          *(&v41 + v15) = *(_DWORD *)(v16 + 80);
          *(_BYTE *)((unsigned __int64)&v39 | v15) = *(_BYTE *)(v16 + 85);
          _X8 = (unsigned __int64 *)(v4 + 400);
          __asm { PRFM            #0x11, [X8] }
          do
            v32 = __ldxr(_X8);
          while ( __stxr(v32 | 2, _X8) );
        }
        swr_connect_port(*(_QWORD *)(v4 + 16), (char *)&v40 + 4);
        goto LABEL_28;
      }
      if ( a3 == 2 )
      {
        _X8 = (unsigned __int64 *)(v4 + 376);
        __asm { PRFM            #0x11, [X8] }
        do
          v26 = __ldxr(_X8);
        while ( __stxr(v26 | 1, _X8) );
LABEL_28:
        result = 0;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

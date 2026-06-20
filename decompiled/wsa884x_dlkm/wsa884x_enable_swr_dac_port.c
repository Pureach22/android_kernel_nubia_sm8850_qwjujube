__int64 __fastcall wsa884x_enable_swr_dac_port(__int64 a1, __int64 a2, int a3)
{
  __int64 v3; // x20
  __int64 v4; // x8
  __int64 v5; // x19
  __int64 result; // x0
  char v7; // w8
  char v8; // w10
  int v9; // w9
  int v10; // w8
  char v11; // w10
  int v12; // w10
  char v13; // w9
  char v14; // w11
  __int64 v15; // x2
  unsigned int v16; // w2
  __int64 v17; // x9
  __int64 v18; // x8
  __int64 v19; // x8
  __int64 v20; // x8
  __int64 v21; // x9
  _BYTE *v22; // x10
  _BYTE *v23; // x8
  _BYTE *v24; // x8
  _BYTE *v25; // x8
  unsigned __int64 v32; // x9
  unsigned __int64 v35; // x9
  unsigned __int64 v38; // x9
  unsigned __int64 v41; // x9
  unsigned __int64 v44; // x9
  unsigned __int64 v47; // x10
  unsigned __int64 v50; // x10
  unsigned __int64 v53; // x10
  unsigned __int64 v56; // x10
  int v57; // [xsp+0h] [xbp-40h] BYREF
  __int16 v58; // [xsp+4h] [xbp-3Ch]
  int v59; // [xsp+8h] [xbp-38h] BYREF
  __int16 v60; // [xsp+Ch] [xbp-34h]
  char v61; // [xsp+10h] [xbp-30h] BYREF
  int v62; // [xsp+11h] [xbp-2Fh]
  char v63; // [xsp+15h] [xbp-2Bh]
  int v64; // [xsp+18h] [xbp-28h] BYREF
  __int16 v65; // [xsp+1Ch] [xbp-24h]
  int v66; // [xsp+20h] [xbp-20h]
  __int64 v67; // [xsp+24h] [xbp-1Ch]
  __int64 v68; // [xsp+2Ch] [xbp-14h]
  int v69; // [xsp+34h] [xbp-Ch]
  __int64 v70; // [xsp+38h] [xbp-8h]

  v70 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a1 + 40);
  v4 = *(_QWORD *)(v3 - 184);
  v69 = 0;
  v68 = 0;
  v5 = *(_QWORD *)(v4 + 152);
  v67 = 0;
  if ( v5 )
  {
    result = 0;
    v65 = 0;
    v64 = 0;
    v62 = 0;
    v63 = 0;
    v59 = 0;
    v60 = 0;
    v57 = 0;
    v58 = 0;
    if ( a3 > 3 )
    {
      if ( a3 == 4 )
      {
        v12 = *(unsigned __int8 *)(v5 + 32);
        v13 = *(_BYTE *)(v5 + 41);
        v14 = *(_BYTE *)(v5 + 49);
        LOBYTE(v64) = *(_BYTE *)(v5 + 40);
        LOBYTE(v59) = v13;
        LOBYTE(v57) = v14;
        if ( v12 == 1 && (*(_QWORD *)(v5 + 688) & 1) != 0 )
        {
          BYTE1(v64) = *(_BYTE *)(v5 + 52);
          BYTE1(v59) = *(_BYTE *)(v5 + 53);
          BYTE1(v57) = *(_BYTE *)(v5 + 61);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v47 = __ldxr(_X8);
          while ( __stxr(v47 & 0xFFFFFFFFFFFFFFFELL, _X8) );
          v15 = 2;
        }
        else
        {
          v15 = 1;
        }
        if ( *(_BYTE *)(v5 + 35) == 1 && (*(_QWORD *)(v5 + 688) & 4) != 0 )
        {
          v21 = (unsigned int)v15;
          v22 = (_BYTE *)((unsigned __int64)&v64 | (unsigned int)v15);
          v15 = (unsigned int)(v15 + 1);
          v23 = *(_BYTE **)(*(_QWORD *)(v3 - 184) + 152LL);
          *v22 = v23[76];
          *(_BYTE *)((unsigned __int64)&v59 | v21) = v23[77];
          *(_BYTE *)((unsigned __int64)&v57 | v21) = v23[85];
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v50 = __ldxr(_X8);
          while ( __stxr(v50 & 0xFFFFFFFFFFFFFFFBLL, _X8) );
        }
        if ( *(_BYTE *)(v5 + 33) == 1 && (*(_QWORD *)(v5 + 688) & 2) != 0 )
        {
          v24 = *(_BYTE **)(*(_QWORD *)(v3 - 184) + 152LL);
          *((_BYTE *)&v64 + (unsigned int)v15) = v24[88];
          *((_BYTE *)&v59 + (unsigned int)v15) = v24[89];
          *((_BYTE *)&v57 + (unsigned int)v15) = v24[97];
          v15 = (unsigned int)(v15 + 1);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v53 = __ldxr(_X8);
          while ( __stxr(v53 & 0xFFFFFFFFFFFFFFFDLL, _X8) );
        }
        if ( *(_BYTE *)(v5 + 34) == 1 && (*(_QWORD *)(v5 + 688) & 8) != 0 )
        {
          v25 = *(_BYTE **)(*(_QWORD *)(v3 - 184) + 152LL);
          *((_BYTE *)&v64 + (unsigned int)v15) = v25[100];
          *((_BYTE *)&v59 + (unsigned int)v15) = v25[101];
          *((_BYTE *)&v57 + (unsigned int)v15) = v25[109];
          v15 = (unsigned int)(v15 + 1);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v56 = __ldxr(_X8);
          while ( __stxr(v56 & 0xFFFFFFFFFFFFFFF7LL, _X8) );
        }
        swr_disconnect_port(*(_QWORD *)(v5 + 16), &v64, v15, &v59, &v57);
        goto LABEL_39;
      }
      if ( a3 == 8 )
      {
        if ( (unsigned int)swr_set_device_group(*(_QWORD *)(v5 + 16), 0)
          && (unsigned int)__ratelimit(&wsa884x_enable_swr_dac_port__rs, "wsa884x_enable_swr_dac_port") )
        {
          dev_err(*(_QWORD *)(v3 - 184), "%s: set num ch failed\n", "wsa884x_enable_swr_dac_port");
        }
        swr_slvdev_datapath_control(*(_QWORD *)(v5 + 16), *(unsigned __int8 *)(*(_QWORD *)(v5 + 16) + 64LL), 0);
        goto LABEL_39;
      }
    }
    else
    {
      if ( a3 == 1 )
      {
        v7 = *(_BYTE *)(v5 + 40);
        v8 = *(_BYTE *)(v5 + 41);
        v61 = *(_BYTE *)(v5 + 48);
        v9 = *(_DWORD *)(v5 + 116);
        LOBYTE(v64) = v7;
        v10 = *(_DWORD *)(v5 + 44);
        LOBYTE(v59) = v8;
        v11 = *(_BYTE *)(v5 + 49);
        v66 = v10;
        LOBYTE(v57) = v11;
        if ( v9 == 1 )
          v66 = 4800000;
        if ( *(_BYTE *)(v5 + 32) == 1 )
        {
          BYTE1(v64) = *(_BYTE *)(v5 + 52);
          LOBYTE(v62) = *(_BYTE *)(v5 + 60);
          BYTE1(v59) = *(_BYTE *)(v5 + 53);
          LODWORD(v67) = *(_DWORD *)(v5 + 56);
          BYTE1(v57) = *(_BYTE *)(v5 + 61);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v35 = __ldxr(_X8);
          while ( __stxr(v35 | 1, _X8) );
          v16 = 2;
        }
        else
        {
          v16 = 1;
        }
        if ( *(_BYTE *)(v5 + 35) == 1 )
        {
          v17 = v16;
          v18 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
          *(_BYTE *)((unsigned __int64)&v64 | v16) = *(_BYTE *)(v18 + 76);
          *(_BYTE *)((unsigned __int64)&v61 | v16) = *(_BYTE *)(v18 + 84);
          *(_BYTE *)((unsigned __int64)&v59 | v16) = *(_BYTE *)(v18 + 77);
          *(&v66 + v16++) = *(_DWORD *)(v18 + 80);
          *(_BYTE *)((unsigned __int64)&v57 | v17) = *(_BYTE *)(v18 + 85);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v38 = __ldxr(_X8);
          while ( __stxr(v38 | 4, _X8) );
        }
        if ( *(_BYTE *)(v5 + 33) == 1 )
        {
          v19 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
          *((_BYTE *)&v64 + v16) = *(_BYTE *)(v19 + 88);
          *(&v61 + v16) = *(_BYTE *)(v19 + 96);
          *((_BYTE *)&v59 + v16) = *(_BYTE *)(v19 + 89);
          *(&v66 + v16) = *(_DWORD *)(v19 + 92);
          *((_BYTE *)&v57 + v16++) = *(_BYTE *)(v19 + 97);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v41 = __ldxr(_X8);
          while ( __stxr(v41 | 2, _X8) );
        }
        if ( *(_BYTE *)(v5 + 34) == 1 )
        {
          v20 = *(_QWORD *)(*(_QWORD *)(v3 - 184) + 152LL);
          *((_BYTE *)&v64 + v16) = *(_BYTE *)(v20 + 100);
          *(&v61 + v16) = *(_BYTE *)(v20 + 108);
          *((_BYTE *)&v59 + v16) = *(_BYTE *)(v20 + 101);
          *(&v66 + v16) = *(_DWORD *)(v20 + 104);
          *((_BYTE *)&v57 + v16) = *(_BYTE *)(v20 + 109);
          _X8 = (unsigned __int64 *)(v5 + 688);
          __asm { PRFM            #0x11, [X8] }
          do
            v44 = __ldxr(_X8);
          while ( __stxr(v44 | 8, _X8) );
        }
        swr_connect_port(*(_QWORD *)(v5 + 16), &v64);
        goto LABEL_39;
      }
      if ( a3 == 2 )
      {
        _X8 = (unsigned __int64 *)(v5 + 680);
        __asm { PRFM            #0x11, [X8] }
        do
          v32 = __ldxr(_X8);
        while ( __stxr(v32 | 1, _X8) );
LABEL_39:
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

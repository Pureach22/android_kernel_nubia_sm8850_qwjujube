size_t __fastcall sde_evtlog_log(size_t result, char *s, int a3, int a4, int a5, int a6, int a7, int a8, char a9)
{
  size_t v10; // x23
  size_t v11; // x21
  size_t v13; // x22
  _QWORD *v14; // x24
  _QWORD *v15; // x25
  _QWORD *v16; // x26
  int v18; // w9
  int v19; // w8
  int v20; // w9
  int v21; // w25
  unsigned int v22; // w8
  size_t v23; // x24
  unsigned __int64 StatusReg; // x22
  unsigned int v25; // w12
  __int64 v26; // x8
  int v27; // w10
  char *v28; // x11
  size_t v29; // x10
  unsigned int v30; // w12
  char v31; // w13
  size_t v32; // x10
  char *v33; // x16
  char *v34; // x14
  int v35; // w11
  unsigned int v38; // w8
  unsigned int v39; // w8
  unsigned int v45; // w9
  char *v46; // [xsp+28h] [xbp-28h] BYREF
  char **v47; // [xsp+30h] [xbp-20h]
  __int64 v48; // [xsp+38h] [xbp-18h]
  __int64 v49; // [xsp+40h] [xbp-10h]
  __int64 v50; // [xsp+48h] [xbp-8h]

  v50 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( result )
  {
    if ( s )
    {
      v10 = result + 786432;
      v11 = result;
      if ( (*(_DWORD *)(result + 786452) & a4) != 0 )
      {
        v48 = 0;
        v49 = 0;
        v46 = nullptr;
        v47 = nullptr;
        result = strlen(s);
        v13 = result;
        v14 = (_QWORD *)(v10 + 48);
        v15 = *(_QWORD **)(v10 + 48);
        v16 = (_QWORD *)(v10 + 48);
        while ( 1 )
        {
          v16 = (_QWORD *)*v16;
          if ( v16 == v14 )
            break;
          result = strnstr(s, v16 + 2, v13);
          if ( result )
            goto LABEL_29;
        }
        if ( v15 != v14 )
          goto LABEL_28;
LABEL_29:
        _X9 = (unsigned int *)(v10 + 12);
        __asm { PRFM            #0x11, [X9] }
        do
        {
          v38 = __ldxr(_X9);
          v39 = v38 + 1;
        }
        while ( __stlxr(v39, _X9) );
        __dmb(0xBu);
        v18 = -v39;
        _NF = (-v39 & 0x80000000) != 0;
        v19 = v39 & 0x1FFF;
        v20 = v18 & 0x1FFF;
        if ( _NF )
          v21 = v19;
        else
          v21 = -v20;
        if ( v21 >= 0 )
          v22 = v21;
        else
          v22 = -v21;
        v23 = v11 + 96LL * v22;
        result = sched_clock();
        *(_QWORD *)v23 = result;
        *(_QWORD *)(v23 + 8) = s;
        StatusReg = _ReadStatusReg(SP_EL0);
        *(_DWORD *)(v23 + 16) = a3;
        *(_DWORD *)(v23 + 80) = 0;
        if ( ((v21 & 0x40000000) != 0) ^ __OFSUB__(v21, -v21) | (v21 == -v21) )
          v25 = -v21;
        else
          v25 = v21;
        v26 = 0;
        v27 = *(_DWORD *)(StatusReg + 1800);
        v28 = &a9;
        v46 = &a9;
        v47 = &v46;
        *(_DWORD *)(v23 + 84) = v27;
        v29 = v11 + 96LL * v25;
        v30 = -32;
        v31 = *(_DWORD *)(StatusReg + 40);
        v49 = 4294967264LL;
        *(_BYTE *)(v23 + 88) = v31;
        v32 = v29 + 20;
        while ( 1 )
        {
          if ( (v30 & 0x80000000) != 0 )
          {
            LODWORD(v49) = v30 + 8;
            if ( v30 <= 0xFFFFFFF8 )
            {
              v33 = (char *)&v46 + (int)v30;
              v34 = v28;
              v30 += 8;
              v28 = v33;
              goto LABEL_25;
            }
            v30 += 8;
          }
          v34 = v28 + 8;
          v46 = v28 + 8;
LABEL_25:
          v35 = *(_DWORD *)v28;
          if ( v35 != -1059143953 )
          {
            *(_DWORD *)(v32 + 4 * v26++) = v35;
            v28 = v34;
            if ( v26 != 15 )
              continue;
          }
          *(_DWORD *)(v23 + 80) = v26;
          _X8 = (unsigned int *)(v10 + 4);
          __asm { PRFM            #0x11, [X8] }
          do
            v45 = __ldxr(_X8);
          while ( __stlxr(v45 + 1, _X8) );
          __dmb(0xBu);
          break;
        }
      }
    }
  }
LABEL_28:
  _ReadStatusReg(SP_EL0);
  return result;
}

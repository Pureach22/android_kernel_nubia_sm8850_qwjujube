__int64 __fastcall sde_hw_ctl_get_staged_sspp(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 result; // x0
  int v6; // w23
  __int64 v7; // x1
  int v8; // w20
  _DWORD *v9; // x8
  __int64 i; // x12
  unsigned __int64 v13; // x15
  int v14; // w15
  __int64 v15; // x13
  __int64 v16; // x14
  int v17; // w15
  __int64 v18; // x14
  unsigned __int64 v24; // x14
  _DWORD v25[5]; // [xsp+4h] [xbp-1Ch]
  __int64 v26; // [xsp+18h] [xbp-8h]

  result = 0;
  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    if ( a2 <= 8 )
    {
      _X19 = a3;
      if ( a3 )
      {
        v6 = 4 * a2;
        if ( a2 == 6 )
          v7 = 36;
        else
          v7 = 4 * a2 - 4;
        v25[0] = sde_reg_read(a1, v7);
        v8 = sde_reg_read(a1, (unsigned int)(v6 + 60));
        v25[1] = v8;
        v25[2] = sde_reg_read(a1, (unsigned int)(v6 + 108));
        v25[3] = sde_reg_read(a1, (unsigned int)(v6 + 156));
        v25[4] = sde_reg_read(a1, (unsigned int)(v6 + 180));
        if ( (v25[0] & 0x1000000) != 0 )
          *(_BYTE *)(_X19 + 16) = 1;
        result = 0;
        v9 = &unk_28BC4C;
        for ( i = 1; i != 15; ++i )
        {
          v14 = *(v9 - 5);
          v15 = 1LL << i;
          if ( v14 )
          {
            v16 = (unsigned int)*(v9 - 7);
            if ( (unsigned int)v16 <= 4 && ((v25[v16] & (~(-1 << v14) << *(v9 - 6))) != 0 || (*(v9 - 4) & v8) != 0) )
            {
              __asm { PRFM            #0x11, [X19] }
              do
                v24 = __ldxr((unsigned __int64 *)_X19);
              while ( __stxr(v24 | v15, (unsigned __int64 *)_X19) );
              result = (unsigned int)(result + 1);
            }
          }
          v17 = *(v9 - 1);
          if ( v17 )
          {
            v18 = (unsigned int)*(v9 - 3);
            if ( (unsigned int)v18 <= 4 && ((v25[v18] & (~(-1 << v17) << *(v9 - 2))) != 0 || (*v9 & v8) != 0) )
            {
              _X14 = (unsigned __int64 *)(_X19 + 8);
              __asm { PRFM            #0x11, [X14] }
              do
                v13 = __ldxr(_X14);
              while ( __stxr(v13 | v15, _X14) );
              result = (unsigned int)(result + 1);
            }
          }
          v9 += 8;
        }
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

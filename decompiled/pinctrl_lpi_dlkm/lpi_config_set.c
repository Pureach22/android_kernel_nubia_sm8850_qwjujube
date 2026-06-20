__int64 __fastcall lpi_config_set(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x19
  int v9; // w26
  __int64 v10; // x25
  __int64 v11; // x28
  unsigned int v12; // w24
  __int64 v13; // x8
  __int64 v14; // x8
  int v15; // w9
  unsigned __int64 v16; // x10
  unsigned __int64 v17; // x9
  __int64 v18; // x8
  unsigned __int64 v19; // x10
  unsigned __int64 v20; // x9
  __int64 v21; // x8
  unsigned int v22; // w10
  __int64 v23; // x9
  __int64 v24; // x8
  unsigned int v25; // w10
  __int64 v26; // x9
  __int64 v27; // x8
  unsigned __int64 v34; // x10
  unsigned __int64 v37; // x10
  unsigned __int64 v40; // x10
  unsigned __int64 v43; // x10
  unsigned __int64 v46; // x10
  unsigned __int64 v49; // x10
  unsigned __int64 v52; // x10
  unsigned __int64 v55; // x10
  __int64 result; // x0
  int v57; // w9
  unsigned int v58; // w8
  _QWORD v59[2]; // [xsp+0h] [xbp-10h] BYREF

  v59[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v59[0] = 0;
  v4 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 16) + 8LL) + 24LL * a2 + 16);
  if ( a4 )
  {
    v9 = 0;
    v10 = *(_QWORD *)(*(_QWORD *)(a1 + 104) + 152LL);
    do
    {
      v11 = *(_QWORD *)(a3 + 8LL * v9);
      if ( (unsigned __int8)v11 > 8u )
      {
        v12 = (unsigned int)v11 >> 8;
        if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v9) > 0x11u )
        {
          if ( (unsigned __int8)v11 == 18 )
          {
            *(_BYTE *)(v4 + 12) = 1;
            *(_BYTE *)(v4 + 13) = (unsigned int)v11 > 0xFF;
          }
          else
          {
            if ( (unsigned __int8)v11 != 25 )
            {
LABEL_59:
              result = 4294967274LL;
              goto LABEL_69;
            }
            v13 = *(_QWORD *)(v4 + 32);
            if ( !v13 || *(_DWORD *)(v4 + 8) == -1 )
              break;
            if ( (unsigned int)v11 >= 0x400 )
            {
              if ( (unsigned int)__ratelimit(&lpi_config_set__rs, "lpi_config_set") )
                dev_err(
                  *(_QWORD *)(a1 + 104),
                  "%s: invalid slew rate %u for \t\t\t\t\tpin: %d\n",
                  "lpi_config_set",
                  v12,
                  a2);
              break;
            }
            *(_QWORD *)(v4 + 16) = v13;
            *(_DWORD *)v4 = 0;
            mutex_lock(v10 + 664);
            v14 = *(_QWORD *)(v4 + 40);
            if ( v14 )
            {
              v15 = *(_DWORD *)(v4 + 8);
              *(_QWORD *)(v4 + 16) = v14;
              if ( v15 != -1 )
              {
                v59[0] = (int)lpi_gpio_read((unsigned int *)v4, 0);
                v16 = *(unsigned int *)(v4 + 8);
                v17 = v16 >> 6;
                v18 = 1LL << v16;
                *(_DWORD *)v4 = v16;
                if ( (v11 & 0x100) != 0 )
                {
                  _X9 = &v59[v17];
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v37 = __ldxr(_X9);
                  while ( __stxr(v37 | v18, _X9) );
                }
                else
                {
                  _X9 = &v59[v17];
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v34 = __ldxr(_X9);
                  while ( __stxr(v34 & ~v18, _X9) );
                }
                v22 = *(_DWORD *)v4 + 1;
                v23 = v22 >> 6;
                v24 = 1LL << (*(_BYTE *)v4 + 1);
                *(_DWORD *)v4 = v22;
                if ( (unsigned int)v11 >= 0x200 )
                {
                  _X9 = &v59[v23];
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v43 = __ldxr(_X9);
                  while ( __stxr(v43 | v24, _X9) );
                }
                else
                {
                  _X9 = &v59[v23];
                  __asm { PRFM            #0x11, [X9] }
                  do
                    v40 = __ldxr(_X9);
                  while ( __stxr(v40 & ~v24, _X9) );
                }
                *(_DWORD *)v4 = 0;
                v9 = 2;
                v12 = v59[0];
              }
              lpi_gpio_write(v4, 0, v12);
              *(_QWORD *)(v4 + 16) = *(_QWORD *)(v4 + 32);
            }
            else
            {
              v59[0] = (int)lpi_gpio_read((unsigned int *)v4, 0);
              v19 = *(unsigned int *)(v4 + 8);
              v20 = v19 >> 6;
              v21 = 1LL << v19;
              *(_DWORD *)v4 = v19;
              if ( (v11 & 0x100) != 0 )
              {
                _X9 = &v59[v20];
                __asm { PRFM            #0x11, [X9] }
                do
                  v49 = __ldxr(_X9);
                while ( __stxr(v49 | v21, _X9) );
              }
              else
              {
                _X9 = &v59[v20];
                __asm { PRFM            #0x11, [X9] }
                do
                  v46 = __ldxr(_X9);
                while ( __stxr(v46 & ~v21, _X9) );
              }
              v25 = *(_DWORD *)v4 + 1;
              v26 = v25 >> 6;
              v27 = 1LL << (*(_BYTE *)v4 + 1);
              *(_DWORD *)v4 = v25;
              if ( (unsigned int)v11 >= 0x200 )
              {
                _X9 = &v59[v26];
                __asm { PRFM            #0x11, [X9] }
                do
                  v55 = __ldxr(_X9);
                while ( __stxr(v55 | v27, _X9) );
              }
              else
              {
                _X9 = &v59[v26];
                __asm { PRFM            #0x11, [X9] }
                do
                  v52 = __ldxr(_X9);
                while ( __stxr(v52 & ~v27, _X9) );
              }
              *(_DWORD *)v4 = 0;
              lpi_gpio_write(v4, 0, v59[0]);
              v9 = 2;
            }
            mutex_unlock(v10 + 664);
          }
        }
        else if ( (unsigned __int8)v11 == 9 )
        {
          *(_DWORD *)(v4 + 52) = v12;
        }
        else
        {
          if ( (unsigned __int8)v11 != 12 )
            goto LABEL_59;
          *(_BYTE *)(v4 + 12) = 0;
        }
      }
      else if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v9) > 2u )
      {
        if ( (unsigned __int8)v11 == 3 )
        {
          *(_DWORD *)(v4 + 48) = 1;
        }
        else
        {
          if ( (unsigned __int8)v11 != 5 )
            goto LABEL_59;
          *(_DWORD *)(v4 + 48) = 3;
        }
      }
      else if ( (unsigned __int8)*(_QWORD *)(a3 + 8LL * v9) )
      {
        if ( (unsigned __int8)v11 != 1 )
          goto LABEL_59;
        *(_DWORD *)(v4 + 48) = 0;
      }
      else
      {
        *(_DWORD *)(v4 + 48) = 2;
      }
      ++v9;
    }
    while ( v9 < a4 );
  }
  v57 = *(_DWORD *)(v4 + 4);
  *(_QWORD *)(v4 + 16) = *(_QWORD *)(v4 + 24);
  *(_DWORD *)v4 = v57;
  v59[0] = (int)lpi_gpio_read((unsigned int *)v4, 0) & 0xFFFFFFFFFFFFFC3CLL;
  v59[0] |= *(unsigned int *)(v4 + 48);
  v58 = *(_DWORD *)(v4 + 52);
  if ( v58 <= 2 )
    v58 = 2;
  if ( v58 >= 0x10 )
    v58 = 16;
  v59[0] |= ((32 * v58) & 0x3C0) - 64;
  if ( *(_BYTE *)(v4 + 12) == 1 )
    v59[0] |= (unsigned __int64)*(unsigned __int8 *)(v4 + 13) << 9;
  lpi_gpio_write(v4, 0, v59[0]);
  lpi_gpio_write(v4, 4u, 2 * *(unsigned __int8 *)(v4 + 12));
  result = 0;
LABEL_69:
  _ReadStatusReg(SP_EL0);
  return result;
}

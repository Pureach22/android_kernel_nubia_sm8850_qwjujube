__int64 __fastcall slim_stream_prepare(__int64 a1, unsigned int *a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x22
  int v7; // w0
  int v8; // w21
  __int64 v9; // x0
  unsigned int v10; // w8
  unsigned int v11; // w2
  int v12; // w10
  __int64 result; // x0
  int v14; // w9
  char v15; // w12
  char v16; // w11
  char v17; // w12
  int v18; // w13
  int v19; // w12
  bool v20; // zf
  _BOOL4 v21; // w10
  int v22; // w10
  int v23; // w9
  int v24; // w21
  int v25; // w8
  char v26; // w8
  int v27; // w23
  __int64 v28; // x8
  unsigned __int64 v29; // x9
  __int64 v30; // x8
  unsigned __int64 v31; // x24
  __int64 v32; // x9
  char v33; // w10
  __int64 v34; // x0
  unsigned int v35; // w19
  int v36; // [xsp+8h] [xbp-48h] BYREF
  __int16 v37; // [xsp+Ch] [xbp-44h]
  char v38; // [xsp+Eh] [xbp-42h]
  char v39; // [xsp+Fh] [xbp-41h]
  __int128 *v40; // [xsp+10h] [xbp-40h]
  __int64 v41; // [xsp+18h] [xbp-38h]
  __int128 v42; // [xsp+20h] [xbp-30h] BYREF
  _BYTE *v43; // [xsp+30h] [xbp-20h]
  __int64 v44; // [xsp+38h] [xbp-18h]
  _BYTE v45[4]; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v46; // [xsp+48h] [xbp-8h]

  v46 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 && a2 )
  {
    v4 = *(_QWORD *)(a1 + 40);
    v5 = *(_QWORD *)(a1 + 8);
    if ( v4 )
    {
      dev_err(v5, "Stream already Prepared\n");
      result = 4294967274LL;
    }
    else
    {
      v6 = *(_QWORD *)(v5 + 920);
      v7 = _sw_hweight32(a2[6]);
      v8 = v7;
      if ( is_mul_ok(v7, 0x24u) )
      {
        v9 = _kmalloc_noprof(36LL * v7, 3520);
        *(_QWORD *)(a1 + 40) = v9;
        if ( v9 )
        {
          *(_DWORD *)(a1 + 36) = v8;
          *(_DWORD *)(a1 + 24) = *a2;
          *(_DWORD *)(a1 + 28) = a2[1];
          v10 = a2[8];
          *(_DWORD *)(a1 + 16) = v10;
          v11 = *a2;
          if ( *a2 == 88200 || v11 == 44100 )
            v12 = v11 / 0x2B11;
          else
            v12 = (int)v11 / 4000;
          v14 = 0;
          v15 = 1;
          while ( 1 )
          {
            v16 = v15;
            if ( (v12 & 1) == 0 )
            {
              do
              {
                v17 = v12;
                v12 >>= 1;
                ++v14;
              }
              while ( (v17 & 2) == 0 );
            }
            v15 = 0;
            if ( v12 <= 3 )
              break;
            ++v12;
          }
          v18 = 1;
          v19 = 8;
          if ( v11 != 44100 && v11 != 88200 )
          {
            v20 = v12 == 1;
            v21 = v12 == 1;
            v18 = !v20;
            v19 = 16 * v21;
          }
          v22 = v18 + v14;
          v23 = (v18 + v14) | v19;
          if ( (v16 & 1) != 0 )
            v23 |= 0x80u;
          if ( v22 >= 8 )
            v24 = 0;
          else
            v24 = v23;
          if ( v24 < 0 )
          {
            v34 = *(_QWORD *)(a1 + 8);
            v35 = v23;
            dev_err(v34, "Cannot get presence rate for rate %d Hz\n", v11);
            result = v35;
          }
          else
          {
            if ( v11 % *(_DWORD *)(*(_QWORD *)(v6 + 72) + 924LL) )
            {
              if ( v10 )
                v25 = 3;
              else
                v25 = 2;
              *(_DWORD *)(a1 + 20) = v25;
            }
            else
            {
              *(_DWORD *)(a1 + 20) = 0;
            }
            v26 = 0;
            v27 = 0;
            *(_DWORD *)(a1 + 32) = *a2 / *(_DWORD *)(*(_QWORD *)(v6 + 72) + 924LL);
            do
            {
              v28 = -1LL << v26;
              if ( ((unsigned int)v28 & a2[6]) == 0 )
                break;
              v29 = __rbit64((unsigned int)v28 & a2[6]);
              v30 = *(_QWORD *)(a1 + 40) + 36LL * v27;
              v31 = __clz(v29);
              *(_DWORD *)(v30 + 8) = 0;
              *(_DWORD *)v30 = v31;
              *(_DWORD *)(v30 + 16) = v24;
              LODWORD(v29) = *(_DWORD *)(*((_QWORD *)a2 + 2) + 4LL * v27);
              *(_QWORD *)(v30 + 24) = 0;
              *(_DWORD *)(v30 + 32) = 1;
              *(_DWORD *)(v30 + 12) = v29;
              *(_DWORD *)(v30 + 4) = a2[8] != 0;
              v41 = 0;
              v42 = 0x20000u;
              v43 = v45;
              v44 = 0;
              v32 = *(_QWORD *)(a1 + 8);
              v33 = *(_BYTE *)(v32 + 932);
              *(_QWORD *)((char *)&v42 + 3) = 0;
              v36 = 1048582;
              v37 = 0;
              v38 = 0;
              v39 = v33;
              v40 = &v42;
              if ( !*(_DWORD *)(v30 + 4) )
                BYTE2(v36) = 17;
              v45[0] = *(_DWORD *)v30;
              v45[1] = *(_DWORD *)(v30 + 12);
              *(_DWORD *)(v30 + 32) = 2;
              *(_DWORD *)(v30 + 8) = 1;
              slim_do_transfer(*(_QWORD **)(v32 + 920), (unsigned __int8 *)&v36);
              ++v27;
              v26 = v31 + 1;
            }
            while ( v31 < 0x1F );
            result = 0;
          }
        }
        else
        {
          result = 4294967284LL;
        }
      }
      else
      {
        *(_QWORD *)(a1 + 40) = 0;
        result = 4294967284LL;
      }
    }
  }
  else
  {
    printk(&unk_89A4, "slim_stream_prepare");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

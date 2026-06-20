__int64 __fastcall qce_ccm_get_around_output(__int64 result, __int64 a2, int a3)
{
  unsigned int v3; // w9
  unsigned __int64 v4; // x8
  _DWORD *v5; // x10
  unsigned __int64 v6; // x11
  __int64 v7; // x13
  unsigned __int64 v8; // x9
  _DWORD *v9; // x8
  __int64 v10; // x19
  __int64 v11; // x20

  if ( a3 == 1 && *(_BYTE *)(result + 128) == 1 && (*(_BYTE *)(result + 129) & 1) == 0 )
  {
    v3 = *(_DWORD *)(result + 400);
    v4 = *(unsigned int *)(a2 + 80);
    if ( v3 )
    {
      v5 = (_DWORD *)(*(_QWORD *)(a2 + 72) + 8 * v4);
      v6 = *(_QWORD *)(result + 24) + *(unsigned int *)(a2 + 7280) - *(_QWORD *)(result + 16);
      while ( (_DWORD)v4 != 512 )
      {
        v4 = v6 >> 16;
        if ( v3 >= 0x7FC0 )
          v7 = 32704;
        else
          v7 = v3;
        v3 -= v7;
        *v5 = v6;
        v5[1] = v7 | v4 & 0xF0000;
        v5 += 2;
        v6 += v7;
        LODWORD(v4) = *(_DWORD *)(a2 + 80) + 1;
        *(_DWORD *)(a2 + 80) = v4;
        if ( !v3 )
          goto LABEL_11;
      }
      v10 = result;
      v11 = a2;
      printk(&unk_15B74, "_qce_sps_add_data", 512);
      LODWORD(v4) = *(_DWORD *)(v11 + 80);
      result = v10;
      a2 = v11;
      if ( (_DWORD)v4 == 512 )
        return printk(&unk_15B74, "_qce_sps_add_data", 512);
    }
    else
    {
LABEL_11:
      if ( (_DWORD)v4 == 512 )
        return printk(&unk_15B74, "_qce_sps_add_data", 512);
    }
    v8 = *(_QWORD *)(result + 24) + *(unsigned int *)(a2 + 7268) - *(_QWORD *)(result + 16);
    v9 = (_DWORD *)(*(_QWORD *)(a2 + 72) + 8LL * (unsigned int)v4);
    *v9 = v8;
    v9[1] = (v8 >> 16) & 0xF0000 | 0x80;
    ++*(_DWORD *)(a2 + 80);
  }
  return result;
}

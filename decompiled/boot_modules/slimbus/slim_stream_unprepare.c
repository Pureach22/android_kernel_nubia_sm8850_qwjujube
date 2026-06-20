__int64 __fastcall slim_stream_unprepare(__int64 a1)
{
  __int64 v2; // x0
  int v3; // w2
  __int64 v4; // x20
  __int64 v5; // x21
  __int64 v6; // x8
  __int64 v7; // x10
  char v8; // w9
  __int64 v9; // x9
  __int64 result; // x0
  int v11; // [xsp+8h] [xbp-48h] BYREF
  __int16 v12; // [xsp+Ch] [xbp-44h]
  char v13; // [xsp+Eh] [xbp-42h]
  char v14; // [xsp+Fh] [xbp-41h]
  __int128 *v15; // [xsp+10h] [xbp-40h]
  __int64 v16; // [xsp+18h] [xbp-38h]
  __int128 v17; // [xsp+20h] [xbp-30h] BYREF
  char *v18; // [xsp+30h] [xbp-20h]
  __int64 v19; // [xsp+38h] [xbp-18h]
  char v20; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v21; // [xsp+48h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 40);
    v3 = *(_DWORD *)(a1 + 36);
    if ( v2 && v3 )
    {
      if ( v3 >= 1 )
      {
        v4 = 0;
        v5 = 0;
        do
        {
          v6 = *(_QWORD *)(a1 + 8);
          v7 = *(_QWORD *)(a1 + 40);
          v16 = 0;
          v17 = 0x10000u;
          v8 = *(_BYTE *)(v6 + 932);
          *(_QWORD *)((char *)&v17 + 3) = 0;
          v18 = &v20;
          v19 = 0;
          v11 = 1310725;
          v12 = 0;
          v13 = 0;
          v14 = v8;
          v9 = v7 + v4;
          v15 = &v17;
          v20 = *(_DWORD *)(v7 + v4);
          *(_DWORD *)(v9 + 32) = 0;
          *(_DWORD *)(v9 + 8) = 0;
          slim_do_transfer(*(_QWORD **)(v6 + 920), (unsigned __int8 *)&v11);
          ++v5;
          v4 += 36;
        }
        while ( v5 < *(int *)(a1 + 36) );
        v2 = *(_QWORD *)(a1 + 40);
      }
      kfree(v2);
      result = 0;
      *(_QWORD *)(a1 + 40) = 0;
      *(_DWORD *)(a1 + 36) = 0;
    }
    else
    {
      printk(&unk_8819, "slim_stream_unprepare");
      result = 4294967274LL;
    }
  }
  else
  {
    printk(&unk_87EB, "slim_stream_unprepare");
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

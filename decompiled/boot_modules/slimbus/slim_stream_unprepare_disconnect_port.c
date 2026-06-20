__int64 __fastcall slim_stream_unprepare_disconnect_port(__int64 a1, char a2, char a3)
{
  int v4; // w2
  __int64 v6; // x21
  __int64 v7; // x22
  __int64 v8; // x8
  __int64 v9; // x10
  char v10; // w9
  __int64 v11; // x9
  __int64 result; // x0
  int v13; // [xsp+8h] [xbp-48h] BYREF
  __int16 v14; // [xsp+Ch] [xbp-44h]
  char v15; // [xsp+Eh] [xbp-42h]
  char v16; // [xsp+Fh] [xbp-41h]
  __int128 *v17; // [xsp+10h] [xbp-40h]
  __int64 v18; // [xsp+18h] [xbp-38h]
  __int128 v19; // [xsp+20h] [xbp-30h] BYREF
  char *v20; // [xsp+30h] [xbp-20h]
  __int64 v21; // [xsp+38h] [xbp-18h]
  char v22; // [xsp+44h] [xbp-Ch] BYREF
  __int64 v23; // [xsp+48h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    printk(&unk_87EB, "slim_stream_unprepare_disconnect_port");
    goto LABEL_13;
  }
  v4 = *(_DWORD *)(a1 + 36);
  if ( !*(_QWORD *)(a1 + 40) || !v4 )
  {
    printk(&unk_8819, "slim_stream_unprepare_disconnect_port");
LABEL_13:
    result = 4294967274LL;
    goto LABEL_14;
  }
  if ( (a2 & 1) != 0 && v4 >= 1 )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      v8 = *(_QWORD *)(a1 + 8);
      v9 = *(_QWORD *)(a1 + 40);
      v18 = 0;
      v19 = 0x10000u;
      v10 = *(_BYTE *)(v8 + 932);
      *(_QWORD *)((char *)&v19 + 3) = 0;
      v20 = &v22;
      v21 = 0;
      v13 = 1310725;
      v14 = 0;
      v15 = 0;
      v16 = v10;
      v11 = v9 + v6;
      v17 = &v19;
      v22 = *(_DWORD *)(v9 + v6);
      *(_DWORD *)(v11 + 32) = 0;
      *(_DWORD *)(v11 + 8) = 0;
      slim_do_transfer(*(_QWORD **)(v8 + 920), (unsigned __int8 *)&v13);
      ++v7;
      v6 += 36;
    }
    while ( v7 < *(int *)(a1 + 36) );
  }
  if ( (a3 & 1) != 0 )
  {
    kfree(*(_QWORD *)(a1 + 40));
    result = 0;
    *(_QWORD *)(a1 + 40) = 0;
    *(_DWORD *)(a1 + 36) = 0;
  }
  else
  {
    result = 0;
  }
LABEL_14:
  _ReadStatusReg(SP_EL0);
  return result;
}

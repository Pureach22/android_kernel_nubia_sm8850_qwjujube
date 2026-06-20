__int64 __fastcall rdbg_release(__int64 a1, __int64 a2)
{
  unsigned int v3; // w20
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x23
  int v7; // w8
  __int64 v9; // x8
  __int64 v10; // x20
  int v11; // w8

  if ( a1 && qword_108 )
  {
    v3 = *(_DWORD *)(a1 + 76) & 0xFFFFF;
    v4 = qword_108 + 456LL * v3;
    if ( *(_BYTE *)(v4 + 96) == 1 )
    {
      *(_BYTE *)(v4 + 96) = 0;
      complete(v4 + 8);
      v5 = qword_108;
      v6 = qword_108 + 456LL * v3;
      if ( *(_DWORD *)(v6 + 168) == -16711936 )
      {
        v7 = *(_DWORD *)(v6 + 192);
        if ( v7 == 2 )
        {
          **(_DWORD **)(v6 + 136) = 0;
        }
        else if ( v7 == 1 )
        {
          **(_DWORD **)(v6 + 128) = 0;
          kfree(*(_QWORD *)(v6 + 184));
          *(_QWORD *)(v6 + 184) = 0;
        }
        *(_DWORD *)(v6 + 168) = 0;
        v5 = qword_108;
      }
      v9 = v5 + 456LL * v3;
      if ( *(_DWORD *)(v9 + 248) == -16711936 )
      {
        v10 = v9 + 200;
        v11 = *(_DWORD *)(v9 + 272);
        if ( v11 == 2 )
        {
          **(_DWORD **)(v10 + 16) = 0;
        }
        else if ( v11 == 1 )
        {
          **(_DWORD **)(v10 + 8) = 0;
          kfree(*(_QWORD *)(v10 + 64));
          *(_QWORD *)(v10 + 64) = 0;
        }
        *(_DWORD *)(v10 + 48) = 0;
      }
    }
    *(_QWORD *)(a2 + 32) = 0;
    return 0;
  }
  else
  {
    printk(&unk_76C8);
    return 4294967277LL;
  }
}

__int64 __fastcall kgsl_destroy_anon(__int64 result)
{
  __int64 v1; // x8
  __int64 v2; // x19
  __int64 v3; // x20
  unsigned int v4; // w22
  __int64 v5; // x0
  unsigned __int64 v6; // x25
  unsigned __int64 v7; // x21
  __int64 v8; // x8
  unsigned __int64 v9; // x0
  unsigned int v16; // w8
  unsigned int v17; // w8

  if ( (*(_DWORD *)(result + 48) & 8) == 0 )
  {
    v1 = *(_QWORD *)(result + 56);
    v2 = result;
    if ( *(_DWORD *)(v1 + 8) )
    {
      v3 = *(_QWORD *)v1;
      v4 = 0;
      do
      {
        if ( *(_DWORD *)(v3 + 12) >= 0x1000u )
        {
          v6 = 0;
          v7 = *(_QWORD *)v3 & 0xFFFFFFFFFFFFFFFCLL;
          do
          {
            if ( (*(_BYTE *)(v2 + 75) & 1) == 0 )
              set_page_dirty_lock(v7);
            v8 = *(_QWORD *)(v7 + 8);
            v9 = v7;
            if ( (v8 & 1) != 0 )
              v9 = v8 - 1;
            _X9 = (unsigned int *)(v9 + 52);
            __asm { PRFM            #0x11, [X9] }
            do
            {
              v16 = __ldxr(_X9);
              v17 = v16 - 1;
            }
            while ( __stlxr(v17, _X9) );
            __dmb(0xBu);
            if ( !v17 )
              _folio_put();
            ++v6;
            v7 += 64LL;
          }
          while ( v6 < (unsigned __int64)*(unsigned int *)(v3 + 12) >> 12 );
        }
        ++v4;
        v5 = sg_next(v3);
        v1 = *(_QWORD *)(v2 + 56);
        v3 = v5;
      }
      while ( v4 < *(_DWORD *)(v1 + 8) );
    }
    sg_free_table(v1);
    result = kfree(*(_QWORD *)(v2 + 56));
    *(_QWORD *)(v2 + 56) = 0;
  }
  return result;
}

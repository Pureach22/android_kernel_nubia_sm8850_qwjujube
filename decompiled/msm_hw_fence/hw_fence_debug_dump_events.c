__int64 __fastcall hw_fence_debug_dump_events(
        __int64 result,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  __int64 v6; // x30
  __int64 v7; // x8
  unsigned int v9; // w20
  unsigned int v10; // w8
  __int64 *v11; // x11
  unsigned int v12; // w22
  __int64 v13; // x9
  unsigned __int64 v14; // x10
  unsigned __int64 v15; // x12
  __int64 v16; // x13
  __int64 v17; // t1
  bool v18; // cf
  unsigned int v19; // w21
  _QWORD *v20; // x1
  unsigned int i; // w21
  _QWORD v22[13]; // [xsp+8h] [xbp-78h] BYREF
  int v23; // [xsp+70h] [xbp-10h]
  __int64 v24; // [xsp+78h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a2 + 88);
  v23 = 0;
  memset(v22, 0, sizeof(v22));
  if ( v7 )
  {
    __dsb(0xFu);
    v9 = result;
    v10 = *(_DWORD *)(a2 + 96);
    if ( v10 )
    {
      v11 = *(__int64 **)(a2 + 88);
      v12 = 0;
      v13 = 0;
      v14 = 0;
      LODWORD(v15) = *(_DWORD *)(a2 + 96);
      do
      {
        v17 = *v11;
        v11 += 8;
        v16 = v17;
        v18 = v17 - 1 >= (unsigned __int64)(v13 - 1);
        if ( v17 - 1 >= (unsigned __int64)(v13 - 1) )
        {
          v15 = (unsigned int)v15;
        }
        else
        {
          v12 = v14;
          v15 = v10;
        }
        ++v14;
        if ( !v18 )
          v13 = v16;
      }
      while ( v14 < v15 );
      if ( v12 < v10 )
      {
        v19 = v12;
        do
        {
          v20 = (_QWORD *)(*(_QWORD *)(a2 + 88) + ((__int64)(int)v19 << 6));
          if ( !*v20 )
            break;
          result = dump_event(v9, v20, v22, v19++);
        }
        while ( v19 < *(_DWORD *)(a2 + 96) );
      }
    }
    else
    {
      v12 = 0;
    }
    if ( v12 )
    {
      for ( i = 0; i != v12; ++i )
        result = dump_event(v9, *(_QWORD *)(a2 + 88) + ((__int64)(int)i << 6), v22, i);
    }
  }
  else
  {
    result = printk(&unk_2A02D, "hw_fence_debug_dump_events", 677, v6, a5, a6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}

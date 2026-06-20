__int64 __fastcall snapshot_capture_mem_list(_QWORD *a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 (*v10)(void); // x8
  __int64 v11; // x20
  __int64 next; // x0
  int v13; // w21
  __int64 v14; // x20
  __int64 v15; // x8
  int v16; // w9
  int v18; // [xsp+0h] [xbp-10h] BYREF
  int v19; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v20; // [xsp+8h] [xbp-8h]

  v20 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v18 = 0;
  if ( a4 )
  {
    v19 = 0;
    raw_spin_lock(a4 + 32);
    idr_for_each(a4 + 40, count_mem_entries, &v18);
    if ( v18 )
    {
      if ( 20LL * v18 + 12 > a3 )
      {
        dev_err(*a1, "snapshot: Not enough memory for the mem list\n");
        v11 = 0;
      }
      else
      {
        *(_DWORD *)a2 = v18;
        v8 = *(_QWORD *)(a4 + 64);
        if ( v8 )
        {
          v9 = *(_QWORD *)(v8 + 96);
          if ( v9 && (v10 = *(__int64 (**)(void))(v9 + 48)) != nullptr )
          {
            if ( *((_DWORD *)v10 - 1) != 1831526433 )
              __break(0x8228u);
            v8 = v10();
          }
          else
          {
            v8 = 0;
          }
        }
        *(_QWORD *)(a2 + 4) = v8;
        v19 = 0;
        next = idr_get_next(a4 + 40, &v19);
        if ( next )
        {
          v13 = 0;
          v14 = a2 + 12;
          do
          {
            v15 = v14 + 20LL * v13++;
            *(_QWORD *)v15 = *(_QWORD *)(next + 32);
            *(_QWORD *)(v15 + 8) = *(_QWORD *)(next + 48);
            v16 = v19 + 1;
            *(_DWORD *)(v15 + 16) = *(unsigned __int8 *)(next + 81);
            v19 = v16;
            next = idr_get_next(a4 + 40, &v19);
          }
          while ( next );
        }
        v11 = 20 * v18 + 12;
      }
    }
    else
    {
      v11 = 0;
    }
    raw_spin_unlock(a4 + 32);
  }
  else
  {
    v11 = 0;
  }
  _ReadStatusReg(SP_EL0);
  return v11;
}
